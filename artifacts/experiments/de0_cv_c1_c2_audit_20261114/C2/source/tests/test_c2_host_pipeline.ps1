param(
  [Parameter(Mandatory=$true)][string]$FixtureDirectory,
  [Parameter(Mandatory=$true)][string]$OutputDirectory,
  [string]$Tclsh = 'C:\altera_lite\25.1std\quartus\bin64\tclsh.exe',
  [string]$Python = 'python'
)
$ErrorActionPreference = 'Stop'
if (Test-Path -LiteralPath $OutputDirectory) { throw 'Test output must be new.' }
$null = New-Item -ItemType Directory -Path $OutputDirectory
$root = Split-Path -Parent $PSScriptRoot
$entrypoint = Join-Path $root 'host/Invoke-C2J2JtagExperiment.ps1'
$mock = Join-Path $PSScriptRoot 'mock_c2_host_wire.tcl'
$fixture = Join-Path $FixtureDirectory 'single_frozen_2/mock_wire_fixture.txt'
foreach ($path in @($Tclsh, $fixture, $mock, $entrypoint)) {
  if (!(Test-Path -LiteralPath $path -PathType Leaf)) { throw "Missing fixture/tool: $path" }
}
# This sentinel is only hashed by the host wrapper. No programmer is invoked.
$sof = Join-Path $OutputDirectory 'MOCK_ONLY_NOT_A_BITSTREAM.sof'
[IO.File]::WriteAllText($sof, 'HOST PIPELINE TEST ONLY - NEVER PROGRAM')
$stub = Join-Path $OutputDirectory 'mock_stp.ps1'
$template = @'
if ($args.Count -ne 7 -or $args[0] -ne '-t') { throw 'Unexpected STP invocation.' }
& '__TCLSH__' '__MOCK__' $args[1] $args[2] $args[3] $args[4] $args[5] '__FIXTURE__' $args[6] normal
$global:LASTEXITCODE = $LASTEXITCODE
'@
$template = $template.Replace('__TCLSH__', $Tclsh.Replace("'", "''")).Replace('__MOCK__', $mock.Replace("'", "''")).Replace('__FIXTURE__', $fixture.Replace("'", "''"))
[IO.File]::WriteAllText($stub, $template)
$results = [Collections.Generic.List[object]]::new()
$successOut = Join-Path $OutputDirectory 'single'
& $entrypoint -SofPath $sof -ExperimentId HOST_PIPELINE_MOCK_SINGLE -OutputDirectory $successOut -CaseSequences 2 -Python $Python -QuartusStpTcl $stub
$manifest = Get-Content -LiteralPath (Join-Path $successOut 'run_manifest.json') -Raw | ConvertFrom-Json
$receipt = Get-Content -LiteralPath (Join-Path $successOut 'result_audit.json') -Raw | ConvertFrom-Json
if ($manifest.status -ne 'PASS_RUN_AND_ARTIFACT_AUDIT' -or $manifest.scope -ne 'subset' -or $manifest.expected_count -ne 1 -or $manifest.selected_sequences[0] -ne 2) { throw 'Pipeline selection/status mismatch.' }
if ($receipt.hardware_provenance_verified_by_this_checker -ne $false -or $manifest.board_programming_performed_by_this_script -ne $false) { throw 'Mock was misclassified as hardware proof.' }
foreach ($property in $manifest.output_sha256.PSObject.Properties) {
  $actual = (Get-FileHash -LiteralPath (Join-Path $successOut $property.Name) -Algorithm SHA256).Hash.ToLowerInvariant()
  if ($actual -ne $property.Value) { throw "Output hash mismatch: $($property.Name)" }
}
$results.Add(@{name='single_frozen_case_end_to_end';status='PASS';physical_jtag=$false})

$emptyStub = Join-Path $OutputDirectory 'mock_stp_empty.ps1'
[IO.File]::WriteAllText($emptyStub, '$global:LASTEXITCODE = 0')
$failureOut = Join-Path $OutputDirectory 'missing_artifacts'
$caught = $null
try {
  & $entrypoint -SofPath $sof -ExperimentId HOST_PIPELINE_MOCK_MISSING -OutputDirectory $failureOut -CaseSequences 2 -Python $Python -QuartusStpTcl $emptyStub
} catch { $caught = $_.Exception.Message }
if (!$caught -or $caught -notmatch 'Independent result audit failed') { throw "Expected independent audit failure, got: $caught" }
$manifest = Get-Content -LiteralPath (Join-Path $failureOut 'run_manifest.json') -Raw | ConvertFrom-Json
if ($manifest.status -ne 'FAIL' -or $manifest.quartus_stp_tcl_exit_code -ne 0 -or $manifest.result_audit_exit_code -ne 1) { throw 'Exit zero without artifacts was not rejected.' }
$results.Add(@{name='exit_zero_without_artifacts_rejected';status='PASS';physical_jtag=$false})
@{schema='c2-host-pipeline-test-v1';physical_jtag=$false;results=$results} | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $OutputDirectory 'summary.json') -Encoding utf8
Write-Output 'C2_HOST_PIPELINE_MOCK_PASS tests=2 physical_jtag=false'

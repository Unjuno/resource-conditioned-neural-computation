param(
  [Parameter(Mandatory=$true)][string]$SofPath,
  [Parameter(Mandatory=$true)][string]$ExperimentId,
  [Parameter(Mandatory=$true)][string]$OutputDirectory,
  [string]$CasesCsv = (Join-Path $PSScriptRoot 'c2_cases.csv'),
  [string]$ExpectedCasesSha256,
  [int[]]$CaseSequences,
  [string]$Python = 'python',
  [string]$QuartusStpTcl = 'C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe'
)
$ErrorActionPreference = 'Stop'
$selectedSequences = @(& (Join-Path $PSScriptRoot 'Resolve-C2Sequences.ps1') -SequenceIds $CaseSequences)
$sequenceArg = $selectedSequences -join ','
$scope = if ($sequenceArg -eq ((1..42) -join ',')) { 'all_frozen_42' } else { 'subset' }
if ($ExperimentId -notmatch '^[A-Za-z0-9_.-]+$') { throw 'ExperimentId must use only A-Z, a-z, 0-9, dot, underscore, and dash.' }
$sof = (Resolve-Path -LiteralPath $SofPath).Path
$cases = (Resolve-Path -LiteralPath $CasesCsv).Path
$stp = (Resolve-Path -LiteralPath $QuartusStpTcl).Path
if ([IO.Path]::GetExtension($sof) -ne '.sof') { throw 'Pass the SRAM configuration .sof artifact.' }
if (Test-Path -LiteralPath $OutputDirectory) { throw "Refusing to overwrite existing output directory: $OutputDirectory" }
$caseSha = & (Join-Path $PSScriptRoot 'Assert-C2FrozenCases.ps1') -CasesCsv $cases -ExpectedCasesSha256 $ExpectedCasesSha256
$caseRows = @(Import-Csv -LiteralPath $cases)
if ($caseRows.Count -ne 42) { throw "Expected 42 case rows, found $($caseRows.Count)." }
$buildIds = @($caseRows | ForEach-Object { $_.build_id.ToLowerInvariant() } | Sort-Object -Unique)
if ($buildIds.Count -ne 1 -or $buildIds[0] -notmatch '^[0-9a-f]{8}$') { throw 'Case table must have exactly one valid 32-bit build ID.' }
$expectedBuildId = $buildIds[0]
$caseAudit = Join-Path $PSScriptRoot '..\tools\audit_c2_case_payloads.py'
$caseManifest = Join-Path (Split-Path -Parent $cases) 'c2_case_manifest.json'
& $Python $caseAudit --csv $cases --manifest $caseManifest --build-id "0x$expectedBuildId"
if ($LASTEXITCODE -ne 0) { throw "C2 case payload audit failed with exit code $LASTEXITCODE." }
$sofSha = (Get-FileHash -LiteralPath $sof -Algorithm SHA256).Hash.ToLowerInvariant()
$null = New-Item -ItemType Directory -Path $OutputDirectory
$tcl = Join-Path $PSScriptRoot 'run_c2_jtag.tcl'
$runLog = Join-Path $OutputDirectory 'quartus_stp_tcl.log'
$repoRoot = $PSScriptRoot
for ($i = 0; $i -lt 5; $i++) { $repoRoot = Split-Path -Parent $repoRoot }
$repoRoot = [IO.Path]::GetFullPath($repoRoot).TrimEnd('\')
$asciiRepoAlias = 'C:\rtnn_c2_20261113'
$aliasItem = Get-Item -LiteralPath $asciiRepoAlias -ErrorAction Stop
if ($aliasItem.LinkType -ne 'Junction') { throw "Quartus path alias must be a directory junction: $asciiRepoAlias" }
$aliasTarget = (Resolve-Path -LiteralPath $aliasItem.Target).Path.TrimEnd('\')
if (-not [string]::Equals($aliasTarget, $repoRoot, [StringComparison]::OrdinalIgnoreCase)) {
  throw "Quartus path alias target mismatch: $asciiRepoAlias -> $aliasTarget; expected $repoRoot"
}
function Get-QuartusCliPath([string]$Path) {
  $fullPath = [IO.Path]::GetFullPath($Path)
  $relativePath = [IO.Path]::GetRelativePath($repoRoot, $fullPath)
  if (-not [IO.Path]::IsPathRooted($relativePath) -and $relativePath -ne '..' -and
      -not $relativePath.StartsWith('..\', [StringComparison]::Ordinal)) {
    return Join-Path $asciiRepoAlias $relativePath
  }
  if ($fullPath -match '[^\x00-\x7F]') {
    throw "Quartus Tcl cannot receive non-ASCII paths outside the repository: $fullPath"
  }
  return $fullPath
}
$tclCli = Get-QuartusCliPath $tcl
$casesCli = Get-QuartusCliPath $cases
$outputCli = Get-QuartusCliPath $OutputDirectory
foreach ($path in @($tclCli, $casesCli, $outputCli)) {
  if ($path -match '[^\x00-\x7F]') { throw "Quartus Tcl argument is not ASCII: $path" }
}
$command = @('-t', $tclCli, $casesCli, $outputCli, $sofSha, $ExperimentId, $sequenceArg)
$quartusProcessCwd = Split-Path -Parent $stp
Push-Location -LiteralPath $quartusProcessCwd
try {
  $lines = & $stp @command 2>&1
  $stpExit = $LASTEXITCODE
}
finally {
  Pop-Location
}
$lines | Out-File -LiteralPath $runLog -Encoding utf8
$auditExit = $null
$resultAudit = Join-Path $PSScriptRoot '..\tools\audit_c2_jtag_results.py'
if ($stpExit -eq 0) {
  & $Python $resultAudit --cases $cases --expected-cases-sha256 $caseSha `
    --results $OutputDirectory --sof-sha256 $sofSha --experiment-id $ExperimentId `
    --sequences $sequenceArg --out (Join-Path $OutputDirectory 'result_audit.json') `
    *> (Join-Path $OutputDirectory 'result_audit.log')
  $auditExit = $LASTEXITCODE
}
$files = @{}
foreach ($name in @('c2_jtag_results.csv','c2_jtag_results.json','c2_jtag_raw.log','quartus_stp_tcl.log','result_audit.json','result_audit.log')) {
  $path = Join-Path $OutputDirectory $name
  if (Test-Path -LiteralPath $path -PathType Leaf) {
    $files[$name] = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
  }
}
$manifest = [ordered]@{
  schema = 'rtnn-c2-jtag-run-manifest-v2'
  experiment_id = $ExperimentId
  status = if ($stpExit -eq 0 -and $auditExit -eq 0) { 'PASS_RUN_AND_ARTIFACT_AUDIT' } else { 'FAIL' }
  scope = $scope
  selected_sequences = $selectedSequences
  expected_count = $selectedSequences.Count
  quartus_stp_tcl_exit_code = $stpExit
  quartus_stp_tcl_path = $stp
  quartus_stp_tcl_sha256 = (Get-FileHash -LiteralPath $stp -Algorithm SHA256).Hash.ToLowerInvariant()
  command_arguments = $command
  cwd = (Get-Location).Path
  quartus_process_cwd = $quartusProcessCwd
  quartus_ascii_repo_alias = $asciiRepoAlias
  host_tcl_sha256 = (Get-FileHash -LiteralPath $tcl -Algorithm SHA256).Hash.ToLowerInvariant()
  result_audit_exit_code = $auditExit
  result_auditor_sha256 = (Get-FileHash -LiteralPath $resultAudit -Algorithm SHA256).Hash.ToLowerInvariant()
  cases_csv_sha256 = $caseSha
  sof_filename = [IO.Path]::GetFileName($sof)
  sof_sha256 = $sofSha
  expected_virtual_jtag_build_id = $expectedBuildId
  uart_used = $false
  flash_written = $false
  board_programming_performed_by_this_script = $false
  output_sha256 = $files
}
$manifestPath = Join-Path $OutputDirectory 'run_manifest.json'
$manifest | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath $manifestPath -Encoding utf8
if ($stpExit -ne 0) { throw "quartus_stp_tcl failed with exit code $stpExit; log: $runLog" }
if ($auditExit -ne 0) { throw "Independent result audit failed; see $OutputDirectory/result_audit.log" }
Write-Output "C2 JTAG run and result audit completed; scope=$scope selected_count=$($selectedSequences.Count); results=$OutputDirectory"

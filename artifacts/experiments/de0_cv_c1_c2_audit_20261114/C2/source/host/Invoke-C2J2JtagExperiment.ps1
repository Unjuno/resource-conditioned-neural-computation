[CmdletBinding()]
param(
  [Parameter(Mandatory=$true)][string]$SofPath,
  [Parameter(Mandatory=$true)][string]$ExperimentId,
  [Parameter(Mandatory=$true)][string]$OutputDirectory,
  [int[]]$CaseSequences,
  [string]$Python = 'python',
  [string]$QuartusStpTcl = 'C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe',
  [switch]$ValidateOnly
)

$ErrorActionPreference = 'Stop'
$selectedSequences = @(& (Join-Path $PSScriptRoot 'Resolve-C2Sequences.ps1') -SequenceIds $CaseSequences)
$casesCsv = Join-Path $PSScriptRoot '..\evidence\c2j2_candidate_20261112\host\c2_cases.csv'
$casesCsv = (Resolve-Path -LiteralPath $casesCsv).Path
$expectedSha256 = '52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d'
$actualSha256 = (Get-FileHash -LiteralPath $casesCsv -Algorithm SHA256).Hash.ToLowerInvariant()
if ($actualSha256 -ne $expectedSha256) {
  throw "Frozen C2J2 case table SHA-256 mismatch: expected $expectedSha256, got $actualSha256"
}

$rows = @(Import-Csv -LiteralPath $casesCsv)
if ($rows.Count -ne 42) { throw "C2J2 requires exactly 42 frozen cases; found $($rows.Count)." }
$buildIds = @($rows | ForEach-Object { $_.build_id.ToLowerInvariant() } | Sort-Object -Unique)
if ($buildIds.Count -ne 1 -or $buildIds[0] -ne '43324a32') {
  throw "C2J2 case table build ID mismatch: $($buildIds -join ',')"
}
$seqs = @($rows | ForEach-Object { [int]$_.seq } | Sort-Object -Unique)
if ($seqs.Count -ne 42 -or $seqs[0] -ne 1 -or $seqs[-1] -ne 42) {
  throw 'C2J2 case sequence must contain unique IDs 1 through 42.'
}

$caseAudit = Join-Path $PSScriptRoot '..\tools\audit_c2_case_payloads.py'
$caseManifest = Join-Path (Split-Path -Parent $casesCsv) 'c2_case_manifest.json'
& $Python $caseAudit --csv $casesCsv --manifest $caseManifest --build-id 0x43324a32
if ($LASTEXITCODE -ne 0) { throw "C2J2 payload audit failed with exit code $LASTEXITCODE." }

if ($ValidateOnly) {
  Write-Output "C2J2_ENTRYPOINT_VALIDATED cases=42 build_id=43324a32 cases_sha256=$actualSha256 hardware_access=none"
  Write-Output "C2J2_SELECTION_VALIDATED count=$($selectedSequences.Count) sequences=$($selectedSequences -join ',') hardware_access=none"
  return
}

$runner = Join-Path $PSScriptRoot 'Invoke-C2JtagExperiment.ps1'
& $runner -SofPath $SofPath -ExperimentId $ExperimentId -OutputDirectory $OutputDirectory `
  -CasesCsv $casesCsv -ExpectedCasesSha256 $expectedSha256 -CaseSequences $selectedSequences `
  -Python $Python -QuartusStpTcl $QuartusStpTcl

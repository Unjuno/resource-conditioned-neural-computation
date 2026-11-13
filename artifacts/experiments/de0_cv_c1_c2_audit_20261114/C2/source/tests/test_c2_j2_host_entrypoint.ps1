$ErrorActionPreference = 'Stop'
$script = Join-Path $PSScriptRoot '..\host\Invoke-C2J2JtagExperiment.ps1'
$output = @(& $script -SofPath 'not-used.sof' -ExperimentId 'C2J2_VALIDATE' `
  -OutputDirectory 'not-used' -ValidateOnly
)
if ($LASTEXITCODE -ne 0) { throw "ValidateOnly exit code was $LASTEXITCODE." }
if (($output -join "`n") -notmatch '(?m)^C2J2_ENTRYPOINT_VALIDATED cases=42 build_id=43324a32 cases_sha256=52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d hardware_access=none$') {
  throw "Unexpected ValidateOnly result: $output"
}
$assertScript = Join-Path $PSScriptRoot '..\host\Assert-C2FrozenCases.ps1'
$casesCsv = Join-Path $PSScriptRoot '..\evidence\c2j2_candidate_20261112\host\c2_cases.csv'
$goodSha = '52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d'
$actual = & $assertScript -CasesCsv $casesCsv -ExpectedCasesSha256 $goodSha
if ($actual -ne $goodSha) { throw "Expected C2J2 SHA $goodSha, got $actual." }
$wrongShaRejected = $false
try {
  & $assertScript -CasesCsv $casesCsv -ExpectedCasesSha256 ('0' * 64) | Out-Null
} catch {
  $wrongShaRejected = $_.Exception.Message -match 'SHA-256 mismatch'
}
if (-not $wrongShaRejected) { throw 'A deliberately wrong C2J2 case-table SHA was not rejected.' }
Write-Output $output
Write-Output 'C2J2_FROZEN_SHA_GUARD_PASS correct_sha_accepted wrong_sha_rejected'
$subset = @(& $script -SofPath 'not-used.sof' -ExperimentId 'C2J2_SUBSET_VALIDATE' `
  -OutputDirectory 'not-used' -CaseSequences 2,27,34 -ValidateOnly)
if (($subset -join "`n") -notmatch 'C2J2_SELECTION_VALIDATED count=3 sequences=2,27,34 hardware_access=none') {
  throw "Unexpected subset result: $subset"
}
foreach ($bad in @(@(2,2), @(43), @(0))) {
  $rejected = $false
  try {
    & $script -SofPath 'not-used.sof' -ExperimentId 'C2J2_BAD_SUBSET' `
      -OutputDirectory 'not-used' -CaseSequences $bad -ValidateOnly | Out-Null
  } catch {
    $rejected = $_.Exception.Message -match '(Duplicate CaseSequences|IDs 1 through 42)'
  }
  if (-not $rejected) { throw "Invalid selection accepted: $bad" }
}
Write-Output 'C2J2_SELECTION_GUARD_PASS subset_accepted duplicates_and_outside_ids_rejected'

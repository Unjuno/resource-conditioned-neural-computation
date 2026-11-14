$ErrorActionPreference = 'Stop'
$repoRoot = (Resolve-Path (Join-Path $PSScriptRoot '..\..\..\..\..\..')).Path

function Test-Manifest([string]$Label, [string]$Base, [string]$Manifest) {
  $manifestPath = Join-Path $Base $Manifest
  $matched = 0; $missing = 0; $mismatch = 0; $malformed = 0
  foreach ($line in Get-Content -LiteralPath $manifestPath) {
    if ($line -notmatch '^([0-9a-fA-F]{64})\s+(.+)$') { $malformed++; continue }
    $expected = $Matches[1].ToLowerInvariant()
    $relative = $Matches[2].TrimStart(' ', '*')
    $path = Join-Path $Base $relative
    if (-not (Test-Path -LiteralPath $path -PathType Leaf)) { $missing++; continue }
    $actual = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
    if ($actual -eq $expected) { $matched++ } else { $mismatch++ }
  }
  $status = if ($missing -eq 0 -and $mismatch -eq 0 -and $malformed -eq 0) { 'PASS' } else { 'FAIL' }
  [pscustomobject]@{ label=$Label; status=$status; matched=$matched; missing=$missing; mismatch=$mismatch; malformed=$malformed }
}

$c3 = Join-Path $repoRoot 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3'
$c2run = Join-Path $repoRoot 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/physical_empirical_42'
$dryrun = Join-Path $c3 'campaign/dry_runs/BEMPIRICAL_HOST_DRYRUN_20261114'
$results = @(
  (Test-Manifest 'C3 baseline evidence' $c3 'C3_SHA256SUMS.txt'),
  (Test-Manifest 'C2J2 42-case evidence' $c2run 'SHA256SUMS.txt'),
  (Test-Manifest 'B-EMPIRICAL 13-schedule dry-run' $dryrun 'SHA256SUMS.txt')
)
$results | Format-Table -AutoSize
if (($results | Where-Object status -ne 'PASS').Count -gt 0) { exit 1 }
exit 0

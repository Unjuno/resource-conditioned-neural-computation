param()
$ErrorActionPreference = 'Stop'
$manifest = Join-Path $PSScriptRoot 'SHA256SUMS_CURRENT_20261114.txt'
$evidenceRoot = Join-Path $PSScriptRoot '..\GATE_B_EXACT_REBUILD_20261114'
$matched = 0
$missing = 0
$mismatch = 0
$malformed = 0
foreach ($line in Get-Content -LiteralPath $manifest) {
    if ($line -notmatch '^([0-9a-fA-F]{64})  (.+)$') { $malformed++; continue }
    $expected = $Matches[1].ToLowerInvariant()
    $relative = $Matches[2]
    $path = Join-Path $evidenceRoot $relative
    if (-not (Test-Path -LiteralPath $path -PathType Leaf)) { $missing++; continue }
    $actual = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
    if ($actual -ne $expected) { $mismatch++ } else { $matched++ }
}
[pscustomobject]@{ matched=$matched; missing=$missing; mismatch=$mismatch; malformed=$malformed } | Format-List
if ($missing -or $mismatch -or $malformed) { exit 1 }
exit 0

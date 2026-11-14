param([Parameter(Mandatory=$true)][string]$C3Root)
$ErrorActionPreference = 'Stop'
$root = (Resolve-Path -LiteralPath $C3Root).Path
$manifestPath = Join-Path $root 'C3_SHA256SUMS.txt'
$lines = [System.IO.File]::ReadAllLines($manifestPath)
$count = 0
foreach ($line in $lines) {
    if ([string]::IsNullOrWhiteSpace($line)) { continue }
    if ($line -notmatch '^([0-9a-fA-F]{64})  (.+)$') { throw "Malformed manifest line $($count + 1)" }
    $expected = $Matches[1].ToLowerInvariant()
    $relative = $Matches[2].Replace('/', '\')
    $path = Join-Path $root $relative
    if (-not (Test-Path -LiteralPath $path -PathType Leaf)) { throw "Missing manifest file: $relative" }
    $actual = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
    if ($actual -cne $expected) { throw "SHA-256 mismatch: $relative" }
    $count++
}
if ($count -ne 827) { throw "Unexpected preservation manifest count: $count (expected 827)" }
"PASS_PRESERVED_MANIFEST entries=$count"

param(
  [Parameter(Mandatory=$true)][string]$CasesCsv,
  [string]$ExpectedCasesSha256
)
$ErrorActionPreference = 'Stop'

# Fingerprint of the 42 rows generated from the frozen C2 reference vectors.
$frozen = '7016910c20d47ce7c5487cfbec2490e2afcfb755d22f835b2038876e007ab2da'
$expected = if ($ExpectedCasesSha256) { $ExpectedCasesSha256.ToLowerInvariant() } else { $frozen }
if ($expected -notmatch '^[0-9a-f]{64}$') { throw 'ExpectedCasesSha256 must be 64 hexadecimal characters.' }
$path = (Resolve-Path -LiteralPath $CasesCsv).Path
$actual = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
if ($actual -ne $expected) {
  throw "Frozen C2 cases SHA-256 mismatch: expected $expected, got $actual"
}
Write-Output $actual

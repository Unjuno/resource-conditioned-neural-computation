param(
    [Parameter(Mandatory=$true)][string]$EvidenceRoot,
    [Parameter(Mandatory=$true)][ValidateSet('Write','Verify')][string]$Mode
)
$ErrorActionPreference = 'Stop'
$root = (Resolve-Path -LiteralPath $EvidenceRoot).Path
$manifestPath = Join-Path $root 'SHA256SUMS.txt'
$files = Get-ChildItem -LiteralPath $root -File -Recurse | Where-Object { $_.FullName -ne $manifestPath } | Sort-Object { $_.FullName.Substring($root.Length + 1).ToLowerInvariant() }
$expected = @()
foreach ($file in $files) {
    $rel = $file.FullName.Substring($root.Length + 1).Replace('\','/')
    $hash = (Get-FileHash -LiteralPath $file.FullName -Algorithm SHA256).Hash.ToLowerInvariant()
    $expected += "$hash  $rel"
}
if ($Mode -eq 'Write') {
    [System.IO.File]::WriteAllLines($manifestPath, $expected, [System.Text.UTF8Encoding]::new($false))
} else {
    $actual = [System.IO.File]::ReadAllLines($manifestPath)
    if ($actual.Count -ne $expected.Count) { throw "Manifest count mismatch: actual=$($actual.Count), expected=$($expected.Count)" }
    for ($i = 0; $i -lt $expected.Count; $i++) {
        if ($actual[$i] -cne $expected[$i]) { throw "Manifest mismatch at line $($i + 1): $($actual[$i]) != $($expected[$i])" }
    }
}
"mode=$Mode"
"files=$($expected.Count)"
"manifest_sha256=$((Get-FileHash -LiteralPath $manifestPath -Algorithm SHA256).Hash.ToLowerInvariant())"

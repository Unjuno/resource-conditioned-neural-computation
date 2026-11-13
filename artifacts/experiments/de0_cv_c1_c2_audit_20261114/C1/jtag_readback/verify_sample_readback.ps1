$ErrorActionPreference = 'Stop'
$bsdl = Join-Path $PSScriptRoot 'postconfig_bsdl_generation\5CEBA4F23C7_post.bsd'
$rawLog = Join-Path $PSScriptRoot 'sample_postconfig_leds.log'
$bsdlText = Get-Content -LiteralPath $bsdl -Raw
if ($bsdlText -notmatch 'supports boundary scan testing \(BST\) after device\s+--\s+configuration') { throw 'not post-configuration BSDL' }
if ($bsdlText -notmatch 'BOUNDARY_LENGTH[^\r\n]*is 864') { throw 'boundary length mismatch' }
$log = Get-Content -LiteralPath $rawLog -Raw
if ($log -notmatch 'IDCODE_BEFORE=02B050DD' -or $log -notmatch 'IDCODE_AFTER=02B050DD') { throw 'IDCODE bracketing mismatch' }
$m = [regex]::Match($log, 'SAMPLE_BSR_HEX=([0-9A-Fa-f]+)')
if (!$m.Success -or $m.Groups[1].Value.Length -ne 216) { throw 'sample length mismatch' }
$value = [bigint]::Parse(('0' + $m.Groups[1].Value), [Globalization.NumberStyles]::HexNumber)
$spec = @(@('LEDR3','IOY3',77,1), @('LEDR2','IOW2',68,0), @('LEDR1','IOAA1',71,0), @('LEDR0','IOAA2',74,0))
$observed = [System.Collections.Generic.List[string]]::new()
foreach ($row in $spec) {
  $name=$row[0]; $pin=$row[1]; $cell=[int]$row[2]; $want=[int]$row[3]
  $pattern='"' + $cell + '\s+\(BC_1,\s+' + $pin + ',\s+output3,'
  if ($bsdlText -notmatch $pattern) { throw "BSDL mapping mismatch for $name cell $cell pin $pin" }
  $bit=[int](($value -shr $cell) -band [bigint]1)
  if ($bit -ne $want) { throw "$name expected $want got $bit" }
  $observed.Add("${name} cell=$cell pin=$pin value=$bit")
}
$pattern=($spec | ForEach-Object { [int]($_[3]) }) -join ''
if ($pattern -ne '1000') { throw "LEDR pattern mismatch: $pattern" }
$observed.Add("LEDR3_to_LEDR0=$pattern PASS")
$observed | Set-Content -LiteralPath (Join-Path $PSScriptRoot 'sample_postconfig_leds_verification.log') -Encoding ascii
$observed | ForEach-Object { Write-Output $_ }

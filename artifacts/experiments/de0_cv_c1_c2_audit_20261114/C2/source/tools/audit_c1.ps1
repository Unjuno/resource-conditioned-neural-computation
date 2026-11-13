$ErrorActionPreference = 'Stop'
$repo = (Get-Location).Path
$base = Join-Path $repo 'de0cv_setup\stage3_experiments\ibex_csa_2026-11-03'
$c1 = Join-Path $base 'c1_autonomous_selftest_20261110\quartus_attempt3_timing_pass'
$pass7 = Join-Path $base 'vjtag_diagnostic_20261104\quartus_build\pass7_async_cdc_explicit_20261104'
$out = Join-Path $base 'c2_jtag_measurement_20261111\evidence\C1_READ_ONLY_AUDIT.txt'

function Verify-Manifest([string]$Root, [string]$Manifest) {
  $checked = 0
  foreach ($line in Get-Content -LiteralPath (Join-Path $Root $Manifest)) {
    if ($line -match '^([0-9a-fA-F]{64})\s+\*?(.+)$') {
      $expected = $Matches[1].ToLowerInvariant()
      $relative = $Matches[2]
      $file = Join-Path $Root $relative
      if (!(Test-Path -LiteralPath $file -PathType Leaf)) { throw "MISSING: $file" }
      $actual = (Get-FileHash -Algorithm SHA256 -LiteralPath $file).Hash.ToLowerInvariant()
      if ($actual -ne $expected) { throw "HASH_MISMATCH: $relative expected=$expected actual=$actual" }
      $checked++
    }
  }
  return $checked
}

$c1Count = Verify-Manifest $c1 'SHA256SUMS.txt'
$pass7Count = Verify-Manifest $pass7 'PASS7B_SHA256SUMS.txt'
$sof = (Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $c1 'rtnn_de0_cv.sof')).Hash.ToLowerInvariant()
$ibex = (Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $c1 'ibex_flat.v')).Hash.ToLowerInvariant()
$top = (Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $c1 'rtnn_c1_autonomous_selftest.sv')).Hash.ToLowerInvariant()
$p7sof = (Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $pass7 'rtnn_de0_cv.sof')).Hash.ToLowerInvariant()
$p7ibex = (Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $pass7 'ibex_flat.v')).Hash.ToLowerInvariant()
$lines = @(
  'C1_READ_ONLY_AUDIT=PASS',
  "C1_MANIFEST_CHECKED=$c1Count", "PASS7B_MANIFEST_CHECKED=$pass7Count",
  "C1_SOF_SHA256=$sof", "C1_IBEX_FLAT_SHA256=$ibex", "C1_TOP_SHA256=$top",
  "PASS7B_SOF_SHA256=$p7sof", "PASS7B_IBEX_FLAT_SHA256=$p7ibex",
  'C1_C1_TOP_SOURCE_HASH_EXPECTED=cde1fa56a3f147555f48bffdecb34138b068c69a642f2f551c634cb64d558d33',
  'C1_FIXED_IBEX_EXPECTED=8634e8a73623d74635f93daa1c1a34d30fb5d1dbb7aa30f66411b9cf58621b38',
  'PASS7B_JTAG_PHYSICAL_CASE_COUNT=20 (10 fixed + 10 adaptive, not the requested 42)',
  'PASS7B_FIRMWARE_CYCLE_SOURCE=Ibex mcycle delta returned in RTNR frame',
  'PASS7B_UART_PATH=internal UART TX/RX packet path; no external UART adapter',
  'PASS7B_FLASH=not written; SRAM SOF only per original log',
  'C1_SOURCE_OF_TRUTH=repository C1 attempt3 files; mismatching D scratch top was excluded'
)
Set-Content -LiteralPath $out -Value $lines -Encoding utf8
$lines

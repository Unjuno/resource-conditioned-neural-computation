$ErrorActionPreference = 'Stop'

$evidence = $PSScriptRoot
$c2 = Join-Path $evidence 'quartus_d101'
$research = Join-Path $evidence 'jtag_timing_research_20261113'
$failures = [System.Collections.Generic.List[string]]::new()
$checks = [ordered]@{}

function Check-Hash([string]$RelativePath, [string]$Expected) {
    $path = Join-Path $evidence $RelativePath
    if (-not (Test-Path -LiteralPath $path -PathType Leaf)) {
        $failures.Add("MISSING $RelativePath")
        return
    }
    $actual = (Get-FileHash -Algorithm SHA256 -LiteralPath $path).Hash.ToLowerInvariant()
    $ok = $actual -eq $Expected.ToLowerInvariant()
    $checks["sha256:$RelativePath"] = $ok
    if (-not $ok) { $failures.Add("HASH_MISMATCH $RelativePath expected=$Expected actual=$actual") }
}

Check-Hash 'quartus_d101\rtnn_c2.qsf' '9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e'
Check-Hash 'quartus_d101\rtnn_de0_cv_c2.sdc' '8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690'
Check-Hash 'quartus_d101\rtnn_c2_soc_flat.v' 'fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7'
Check-Hash 'quartus_d101\rtnn_c2.sof' '5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6'

$disposition = Get-Content -Raw -LiteralPath (Join-Path $c2 'd101_exact_disposition_audit.json') | ConvertFrom-Json
$requiredD101Checks = @(
    'assignment_count_801', 'assignment_targets_unique', 'assignment_entities_match_source_domains',
    'all_assignment_rule_D101', 'expected_target_set', 'drc_local_off_count_801',
    'drc_local_off_unique', 'drc_off_matches_qsf', 'global_D101_on', 'global_D102_on',
    'global_D103_on', 'zero_high_violations', 'zero_DRC_errors_and_warnings'
)
$allD101Flags = $true
foreach ($name in $requiredD101Checks) {
    if ($disposition.checks.$name -ne $true) { $allD101Flags = $false }
}
$checks['d101_exact_node_audit'] = [bool]$disposition.all_pass -and $allD101Flags -and
    $disposition.assignment_count -eq 801 -and
    $disposition.drc_local_off_count -eq 801 -and
    $disposition.request_node_count -eq 800 -and
    $disposition.response_node_count -eq 1
if (-not $checks['d101_exact_node_audit']) { $failures.Add('D101_AUDIT_NOT_PASS_OR_COUNTS_CHANGED') }

$paths = Get-Content -Raw -LiteralPath (Join-Path $c2 'c2_postfit_path_audit.json') | ConvertFrom-Json
$expectedCorners = @(0, 1, 2, 3)
$pathOk = $paths.corner_count -eq 4 -and $paths.errors.Count -eq 0 -and
    $paths.request.Count -eq 4 -and $paths.response.Count -eq 4 -and $paths.net_delay.Count -eq 4
foreach ($sequenceName in @('request', 'response', 'net_delay')) {
    $rows = @($paths.$sequenceName)
    $actualCorners = @($rows | ForEach-Object { [int]$_.corner } | Sort-Object -Unique)
    if (($actualCorners -join ',') -ne ($expectedCorners -join ',')) { $pathOk = $false }
}
foreach ($corner in $paths.net_delay) {
    if ($corner.groups.Count -ne 2) { $pathOk = $false; continue }
    $seenRequest = $false
    $seenResponse = $false
    foreach ($group in $corner.groups) {
        if ($group.from.Contains('req_hold_tck_q')) {
            $seenRequest = $true
            if ($group.bound_ns -ne 16.0) { $pathOk = $false }
        } elseif ($group.from.Contains('response_words_q')) {
            $seenResponse = $true
            if ($group.bound_ns -ne 24.0) { $pathOk = $false }
        } else { $pathOk = $false }
        if ($group.slack_ns -lt 0 -or $group.actual_ns -gt $group.bound_ns) { $pathOk = $false }
    }
    if (-not $seenRequest -or -not $seenResponse) { $pathOk = $false }
}
foreach ($corner in $paths.request) { if ($corner.path_count -ne 800 -or $corner.max_path_delay_ns -gt 16.0) { $pathOk = $false } }
foreach ($corner in $paths.response) { if ($corner.path_count -ne 384 -or $corner.max_path_delay_ns -gt 24.0) { $pathOk = $false } }
$checks['four_corner_cdc_net_delay_audit'] = $pathOk
if (-not $pathOk) { $failures.Add('FOUR_CORNER_CDC_NET_DELAY_AUDIT_FAILED_OR_COUNTS_CHANGED') }

$staText = Get-Content -Raw -LiteralPath (Join-Path $c2 'rtnn_c2.sta.rpt')
$effectiveClockGroupCut = $staText.Contains('set_clock_groups -asynchronous -group {altera_reserved_tck}')
$checks['effective_sld_hub_async_clock_group_detected'] = $effectiveClockGroupCut
if (-not $effectiveClockGroupCut) { $failures.Add('EXPECTED_SLD_HUB_ASYNC_CLOCK_GROUP_NOT_FOUND') }

$mtbfText = Select-String -Path (Join-Path $c2 'rtnn_c2.sta.rpt') -Pattern 'Number of Synchronizer Chains Found: 392','Fraction of Chains for which MTBFs Could Not be Calculated: 0.977' | ForEach-Object {$_.Line}
$checks['raw_mtbf_uncalculated_fraction_recorded'] = ($mtbfText.Count -ge 8)
if ($mtbfText.Count -lt 8) { $failures.Add("EXPECTED_RAW_MTBF_SUMMARY_NOT_FOUND count=$($mtbfText.Count)") }

$emptySkewReports = 0
for ($corner = 0; $corner -lt 4; $corner++) {
    $skewText = Get-Content -Raw -LiteralPath (Join-Path $c2 "c2_allcorners_maxskew_$corner.rpt")
    if ($skewText.Contains('Nothing to report.')) { $emptySkewReports++ }
}
$checks['four_corner_max_skew_reports_empty_not_pass'] = $emptySkewReports -eq 4
if ($emptySkewReports -ne 4) { $failures.Add("MAX_SKEW_EMPTY_REPORT_COUNT expected=4 actual=$emptySkewReports") }

$ucp = Get-Content -Raw -LiteralPath (Join-Path $c2 'c2_allcorners_ucp.rpt')
$ucpOk = $ucp.Contains('Unconstrained Input Ports       ; 2') -and
    $ucp.Contains('Unconstrained Output Ports      ; 4') -and
    $ucp.Contains('altera_reserved_tdi') -and
    $ucp.Contains('altera_reserved_tms') -and
    $ucp.Contains('altera_reserved_tdo')
$checks['unconstrained_external_paths_retained'] = $ucpOk
if (-not $ucpOk) { $failures.Add('EXPECTED_UNCONSTRAINED_PORTS_NOT_FOUND') }

$manifestPath = Join-Path $research 'jtag_interface_requirement_20261113\SHA256SUMS.txt'
$manifestHashExpected = 'f0b558dea10db382fa4728f55eb44fac469201041c04a7fe202633a49d1f400b'
$manifestHashActual = (Get-FileHash -Algorithm SHA256 -LiteralPath $manifestPath).Hash.ToLowerInvariant()
$checks['copied_inner_manifest_sha256'] = $manifestHashActual -eq $manifestHashExpected
if (-not $checks['copied_inner_manifest_sha256']) { $failures.Add("COPIED_MANIFEST_HASH_MISMATCH expected=$manifestHashExpected actual=$manifestHashActual") }

$verified = 0
foreach ($line in Get-Content -LiteralPath $manifestPath) {
    if ($line -notmatch '^([0-9a-fA-F]{64})\s+(.+)$') { $failures.Add("BAD_MANIFEST_LINE $line"); continue }
    $expected = $matches[1].ToLowerInvariant()
    $relative = $matches[2]
    $file = Join-Path (Split-Path $manifestPath -Parent) $relative
    if (-not (Test-Path -LiteralPath $file -PathType Leaf)) { $failures.Add("MANIFEST_MISSING $relative"); continue }
    $actual = (Get-FileHash -Algorithm SHA256 -LiteralPath $file).Hash.ToLowerInvariant()
    if ($actual -ne $expected) { $failures.Add("MANIFEST_MISMATCH $relative expected=$expected actual=$actual") }
    $verified++
}
$checks['copied_inner_manifest_entries'] = $verified -eq 63
if ($verified -ne 63) { $failures.Add("MANIFEST_ENTRY_COUNT expected=63 actual=$verified") }

function Verify-Manifest([string]$ManifestPath, [int]$ExpectedEntries, [string]$Label) {
    $count = 0
    foreach ($line in Get-Content -LiteralPath $ManifestPath) {
        if ($line -notmatch '^([0-9a-fA-F]{64})  (.+)$') { $failures.Add("$Label BAD_LINE $line"); continue }
        $expected = $matches[1].ToLowerInvariant()
        $relative = $matches[2]
        $file = Join-Path (Split-Path $ManifestPath -Parent) $relative
        if (-not (Test-Path -LiteralPath $file -PathType Leaf)) { $failures.Add("$Label MISSING $relative"); continue }
        $actual = (Get-FileHash -Algorithm SHA256 -LiteralPath $file).Hash.ToLowerInvariant()
        if ($actual -ne $expected) { $failures.Add("$Label HASH_MISMATCH $relative") }
        $count++
    }
    $ok = $count -eq $ExpectedEntries
    $checks["$Label`_entry_count"] = $ok
    if (-not $ok) { $failures.Add("$Label ENTRY_COUNT expected=$ExpectedEntries actual=$count") }
    return $count
}

$quartusManifestEntries = Verify-Manifest (Join-Path $c2 'SHA256SUMS.txt') 59 'quartus_d101_manifest'

$result = [ordered]@{
    audit = 'C3_GATE_B_EVIDENCE_RECHECK'
    repoEvidence = (Resolve-Path $evidence).Path
    quartusWasReexecuted = $false
    copiedJtagManifestEntriesChecked = $verified
    quartusManifestEntriesChecked = $quartusManifestEntries
    maxSkewInterpretation = 'NOT_EVALUATED: Quartus report says Nothing to report.'
    asyncClockGroupCutDetected = $effectiveClockGroupCut
    checks = $checks
    failures = @($failures)
    status = if ($failures.Count -eq 0) { 'PASS_SAVED_EVIDENCE_INTEGRITY_AND_INTERNAL_CDC_RECORDS' } else { 'FAIL' }
    gateBDecision = 'BLOCKED_BOARD_LEVEL_EXTERNAL_JTAG_TIMING'
}
$result | ConvertTo-Json -Depth 8
if ($failures.Count -gt 0) { exit 1 }

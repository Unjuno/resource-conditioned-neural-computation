param(
  [Parameter(Mandatory=$true)][string]$RunDirectory,
  [Parameter(Mandatory=$true)][int]$ExpectedRows,
  [Parameter(Mandatory=$true)][string]$ExpectedSofSha256,
  [Parameter(Mandatory=$true)][string]$ExpectedBuildId = '43334531',
  [Parameter(Mandatory=$true)][string]$ExpectedModelId = '52544e4e',
  [Parameter(Mandatory=$false)][string]$ExpectedSequenceCsv = '',
  [Parameter(Mandatory=$false)][string]$ExpectedScope = ''
)
$ErrorActionPreference = 'Stop'
$jsonPath = Join-Path $RunDirectory 'c2_jtag_results.json'
$csvPath = Join-Path $RunDirectory 'c2_jtag_results.csv'
$rawPath = Join-Path $RunDirectory 'c2_jtag_raw.log'
$j = Get-Content -LiteralPath $jsonPath -Raw | ConvertFrom-Json -ErrorAction Stop
$rows = @(Import-Csv -LiteralPath $csvPath)
$raw = Get-Content -LiteralPath $rawPath -Raw
$ids = @($rows | ForEach-Object { [int]$_.seq } | Sort-Object)
if ($ExpectedSequenceCsv -ne '') { $expectedIds = @($ExpectedSequenceCsv.Split(',') | ForEach-Object { [int]$_ }) } else { $expectedIds = @(1..$ExpectedRows) }
$bad = [ordered]@{
  json_status = ($j.status -ne 'PASS')
  json_count = ($j.count -ne $ExpectedRows -or $j.completed_count -ne $ExpectedRows -or $j.expected_count -ne $ExpectedRows -or @($j.cases).Count -ne $ExpectedRows)
  row_count = ($rows.Count -ne $ExpectedRows)
  sequence_order = (($ids -join ',') -ne ($expectedIds -join ','))
  selected_sequences = (($j.selected_sequences -join ',') -ne ($expectedIds -join ','))
  sof = ($j.sof_sha256 -ne $ExpectedSofSha256)
  build = ($j.build_id -ne $ExpectedBuildId -or $j.binding_id -ne $ExpectedBuildId)
  model_ids = @($rows | Where-Object { $_.response_model_id -ne $ExpectedModelId }).Count
  crc = @($rows | Where-Object { $_.response_crc_valid -ne '1' }).Count
  cycle_valid = @($rows | Where-Object {
    try { ([uint64]$_.cycles_end -le [uint64]$_.cycles_start) -or ([uint64]$_.cycles_end - [uint64]$_.cycles_start) -ne [uint64]$_.cycles } catch { $true }
  }).Count
  counter_status = @($rows | Where-Object { $_.counter_status -ne '0' -or $_.cycle_valid -ne '1' -or [uint64]$_.cycles -eq 0 }).Count
  prediction = @($rows | Where-Object { $_.prediction -ne $_.expected_prediction -or $_.response_label -ne $_.reference_label }).Count
  exits = @($rows | Where-Object { $_.admitted_exit -ne $_.expected_admitted -or $_.executed_exit -ne $_.expected_executed }).Count
  response_identity = @($rows | Where-Object {
    $_.seq -ne $_.response_seq -or $_.input_id -ne $_.response_input_id -or $_.mode -ne $_.response_mode -or
    $_.response_build_id -ne $ExpectedBuildId -or $_.response_binding_id -ne $ExpectedBuildId
  }).Count
  case_status = @($rows | Where-Object { $_.case_status -ne 'PASS' -or $_.error -ne '' }).Count
  scope = ($j.timing_classification -ne 'EMPIRICAL_ONLY' -or $j.wcet_or_hard_deadline_claimed -ne $false -or $j.uart -ne $false -or $j.flash_written -ne $false)
  result_scope = ($ExpectedScope -ne '' -and $j.scope -ne $ExpectedScope)
  cable = ($raw -notmatch 'hardware=USB-Blaster' -or $raw -notmatch 'device=.*5CE')
}
$cycles = @($rows | ForEach-Object { [uint64]$_.cycles } | Sort-Object)
$summary = [ordered]@{
  schema = 'rtnn-c3-v2-jtag-post-audit-v1'
  status = if ((@($bad.Values | Where-Object { $_ -is [bool] -and $_ }).Count -eq 0) -and (@($bad.Values | Where-Object { $_ -is [int] -and $_ -ne 0 }).Count -eq 0)) { 'PASS' } else { 'FAIL' }
  experiment_id = $j.experiment_id
  sof_sha256 = $j.sof_sha256
  build_id = $j.build_id
  response_count = $rows.Count
  unique_input_ids = @($rows | ForEach-Object { [int]$_.input_id } | Sort-Object -Unique)
  cycle_min = $cycles[0]
  cycle_median = ([double]$cycles[[math]::Floor(($cycles.Count-1)/2)] + [double]$cycles[[math]::Ceiling(($cycles.Count-1)/2)]) / 2.0
  cycle_max = $cycles[-1]
  bad = $bad
  raw_log_sha256 = (Get-FileHash -Algorithm SHA256 $rawPath).Hash.ToLower()
  results_csv_sha256 = (Get-FileHash -Algorithm SHA256 $csvPath).Hash.ToLower()
  results_json_sha256 = (Get-FileHash -Algorithm SHA256 $jsonPath).Hash.ToLower()
}
$summary | ConvertTo-Json -Depth 12
if ($summary.status -ne 'PASS') { exit 1 }

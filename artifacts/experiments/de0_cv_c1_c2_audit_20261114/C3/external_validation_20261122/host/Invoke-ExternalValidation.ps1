[CmdletBinding()]
param(
  [Parameter(Mandatory)][string]$CaseCsv,
  [Parameter(Mandatory)][string]$BindingJson,
  [Parameter(Mandatory)][string]$OutputDirectory,
  [string]$QuartusStpTcl='C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe',
  [switch]$ExecutePhysical
)
$ErrorActionPreference='Stop'
$root=Split-Path -Parent $PSScriptRoot
$case=(Resolve-Path -LiteralPath $CaseCsv).Path
$bindingPath=(Resolve-Path -LiteralPath $BindingJson).Path
$binding=Get-Content -LiteralPath $bindingPath -Raw | ConvertFrom-Json
if($binding.status -ne 'PHYSICAL_ELIGIBLE' -or $binding.classification -ne 'EMPIRICAL_ONLY'){throw 'Binding is not eligible for empirical physical pilot.'}
if($binding.external_jtag_timing -ne 'BLOCKED' -or $binding.build_id -ne '45585631' -or $binding.model_id -ne '52544e4e'){throw 'Binding identity/gate mismatch.'}
$caseSha=(Get-FileHash -LiteralPath $case -Algorithm SHA256).Hash.ToLowerInvariant()
if($caseSha -ne $binding.cases_csv_sha256){throw 'Case CSV SHA mismatch.'}
$rows=Import-Csv -LiteralPath $case
if($rows.Count -ne [int]$binding.case_count){throw 'Case count mismatch.'}
if(Test-Path -LiteralPath $OutputDirectory){throw 'Output directory exists; refusing overwrite.'}
if(-not $ExecutePhysical){
  [pscustomobject]@{status='PREFLIGHT_ONLY';case_count=$rows.Count;cases_csv_sha256=$caseSha;experiment_id=$binding.experiment_id;session_id=$binding.session_id;sof_sha256=$binding.sof_sha256;board=$binding.board;physical_jtag_started=$false} | ConvertTo-Json | Write-Output
  return
}
$tcl=Join-Path $PSScriptRoot 'run_external_validation.tcl'
if(-not(Test-Path -LiteralPath $QuartusStpTcl)){throw "Quartus STP Tcl not found: $QuartusStpTcl"}
$tclSha=(Get-FileHash -LiteralPath $tcl -Algorithm SHA256).Hash.ToLowerInvariant()
New-Item -ItemType Directory -Path (Split-Path -Parent $OutputDirectory) -Force | Out-Null
$log=Join-Path (Split-Path -Parent $OutputDirectory) ((Split-Path -Leaf $OutputDirectory)+'.launcher.log')
& $QuartusStpTcl -t $tcl $case $OutputDirectory $bindingPath *> $log
$exit=$LASTEXITCODE
if(Test-Path -LiteralPath $OutputDirectory){
  $statusFile=Join-Path $OutputDirectory 'run_status.json'
  if(Test-Path -LiteralPath $statusFile){
    $run=Get-Content -LiteralPath $statusFile -Raw | ConvertFrom-Json
    $run | Add-Member -NotePropertyName cases_csv_sha256 -NotePropertyValue $caseSha -Force
    $run | Add-Member -NotePropertyName binding_sha256 -NotePropertyValue ((Get-FileHash -LiteralPath $bindingPath -Algorithm SHA256).Hash.ToLowerInvariant()) -Force
    $run | Add-Member -NotePropertyName host_runner_sha256 -NotePropertyValue $tclSha -Force
    $run | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $statusFile -Encoding utf8
    Copy-Item -LiteralPath $case -Destination (Join-Path $OutputDirectory 'cases.csv')
    Copy-Item -LiteralPath $bindingPath -Destination (Join-Path $OutputDirectory 'binding.json')
    Copy-Item -LiteralPath $tcl -Destination (Join-Path $OutputDirectory 'run_external_validation.tcl')
    Copy-Item -LiteralPath $log -Destination (Join-Path $OutputDirectory 'launcher.log')
    $names=@('cases.csv','binding.json','run_external_validation.tcl','launcher.log','physical_results.csv','raw_jtag.log','run_status.json')
    $lines=foreach($name in $names){$path=Join-Path $OutputDirectory $name;if(Test-Path -LiteralPath $path){"$((Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant())  $name"}}
    Set-Content -LiteralPath (Join-Path $OutputDirectory 'SHA256SUMS.txt') -Value $lines -Encoding ascii
  }
}
if($exit -ne 0){throw "Physical runner exited $exit; retained output/log at $OutputDirectory and $log"}

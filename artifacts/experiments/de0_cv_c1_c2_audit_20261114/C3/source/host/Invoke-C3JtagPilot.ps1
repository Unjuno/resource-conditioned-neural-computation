[CmdletBinding()]
param(
  [Parameter(Mandatory=$true)][string]$SofPath,
  [Parameter(Mandatory=$true)][string]$ExperimentId,
  [Parameter(Mandatory=$true)][string]$OutputDirectory,
  [string]$Python='python',
  [string]$QuartusStpTcl='C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe',
  [string]$JtagConfig='C:\altera_lite\25.1std\quartus\bin64\jtagconfig.exe'
)
$ErrorActionPreference='Stop'
if($ExperimentId -notmatch '^[A-Za-z0-9_.-]+$'){throw 'ExperimentId contains unsupported characters.'}
$repoRoot=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..\..\..\..\..'))
$origin=(& git -C $repoRoot remote get-url origin).Trim()
$branch=(& git -C $repoRoot branch --show-current).Trim()
$head=(& git -C $repoRoot rev-parse HEAD).Trim()
if($origin -ne 'https://github.com/Unjuno/resource-conditioned-neural-computation.git'){throw "Wrong origin: $origin"}
if($branch -ne 'codex/stage-c3-jtag-pilot-20261114'){throw "Wrong work branch: $branch"}
$cases=Join-Path $repoRoot 'artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\pilot\c3_pilot_cases.csv'
$bindingPath=Join-Path $repoRoot 'artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\pilot\pilot_binding.json'
$binding=Get-Content -LiteralPath $bindingPath -Raw | ConvertFrom-Json
$caseSha=(Get-FileHash -LiteralPath $cases -Algorithm SHA256).Hash.ToLowerInvariant()
if($caseSha -ne $binding.pilot_case_csv_sha256){throw 'Pilot case CSV SHA mismatch.'}
$sof=(Resolve-Path -LiteralPath $SofPath).Path
$sofSha=(Get-FileHash -LiteralPath $sof -Algorithm SHA256).Hash.ToLowerInvariant()
if($sofSha -ne $binding.sof_sha256){throw "SOF mismatch: $sofSha"}
$elf=Join-Path $repoRoot 'artifacts\experiments\de0_cv_c1_c2_audit_20261114\C2\evidence\candidate_firmware_build\rtnn_c2_experiment.elf'
$firmwareManifest=Join-Path $repoRoot 'artifacts\experiments\de0_cv_c1_c2_audit_20261114\C2\evidence\candidate_firmware_build\c2_firmware_manifest.json'
$fw=Get-Content -LiteralPath $firmwareManifest -Raw | ConvertFrom-Json
if((Get-FileHash -LiteralPath $elf -Algorithm SHA256).Hash.ToLowerInvariant() -ne $fw.elf_sha256){throw 'Firmware ELF/manifest mismatch.'}
if($fw.build_id -ne $binding.build_id -or $fw.model_id -ne $binding.model_id){throw 'Firmware model/build mismatch.'}
$caseRows=@(Import-Csv -LiteralPath $cases)
if($caseRows.Count -ne 4 -or (($caseRows | ForEach-Object {[int]$_.seq}) -join ',') -ne '1,2,3,4'){throw 'Pilot must contain exactly sequences 1..4.'}
$builds=@($caseRows | ForEach-Object {$_.build_id.ToLowerInvariant()} | Sort-Object -Unique)
if($builds.Count -ne 1 -or $builds[0] -ne $binding.build_id){throw 'Pilot CSV build ID mismatch.'}
if(Test-Path -LiteralPath $OutputDirectory){throw "Refusing to overwrite output directory: $OutputDirectory"}
$null=New-Item -ItemType Directory -Path $OutputDirectory
$out=(Resolve-Path -LiteralPath $OutputDirectory).Path
$jtagPre=Join-Path $out 'jtag_preflight.log'
$jtagPost=Join-Path $out 'jtag_postflight.log'
$stpLog=Join-Path $out 'quartus_stp_tcl.log'
$manifestPath=Join-Path $out 'run_manifest.json'
$runStatus='FAIL_PRECHECK';$stpExit=$null;$auditExit=$null;$designHash='';$postDesignHash=''
try {
  $jtagLines=@(& $JtagConfig -n 2>&1);$jtagExit=$LASTEXITCODE
  $jtagLines | Out-File -LiteralPath $jtagPre -Encoding utf8
  $jtagText=$jtagLines -join "`n"
  if($jtagExit -ne 0 -or $jtagText -notmatch '02B050DD' -or $jtagText -notmatch 'Design hash\s+DF2731CF973C3275CFE6' -or $jtagText -notmatch 'Virtual JTAG #0'){
    throw 'Live JTAG identity differs from preserved C2J2 post-run fingerprint; no scan was issued.'
  }
  $designHash='DF2731CF973C3275CFE6'
  $alias='C:\rtnn_c3_pilot_20261114'
  $aliasItem=Get-Item -LiteralPath $alias -ErrorAction Stop
  if($aliasItem.LinkType -ne 'Junction'){throw "ASCII path alias is not a junction: $alias"}
  $aliasTarget=(Resolve-Path -LiteralPath ([string]$aliasItem.Target)).Path.TrimEnd('\')
  if(-not [string]::Equals($aliasTarget,$repoRoot.TrimEnd('\'),[StringComparison]::OrdinalIgnoreCase)){throw "Alias target mismatch: $aliasTarget"}
  $relTcl='artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\host\run_c3_jtag_pilot.tcl'
  $tcl=Join-Path $repoRoot $relTcl
  $tclCli=Join-Path $alias $relTcl
  $caseCli=Join-Path $alias ([IO.Path]::GetRelativePath($repoRoot,$cases))
  $outCli=Join-Path $alias ([IO.Path]::GetRelativePath($repoRoot,$out))
  foreach($p in @($tclCli,$caseCli,$outCli)){if($p -match '[^\x00-\x7F]'){throw "Non-ASCII Quartus Tcl path: $p"}}
  $stp=(Resolve-Path -LiteralPath $QuartusStpTcl).Path
  $quartusCwd=Split-Path -Parent $stp
  $stpArgs=@('-t',$tclCli,$caseCli,$outCli,$sofSha,$ExperimentId,'1,2,3,4')
  Push-Location -LiteralPath $quartusCwd
  try{$stpLines=@(& $stp @stpArgs 2>&1);$stpExit=$LASTEXITCODE}
  finally{Pop-Location}
  $stpLines | Out-File -LiteralPath $stpLog -Encoding utf8
  if($stpExit -ne 0){$runStatus='FAIL_JTAG_RUN'}else{
    $audit=Join-Path $PSScriptRoot 'audit_c3_pilot.py'
    $auditReceipt=Join-Path $out 'result_audit.json'
    $auditLog=Join-Path $out 'result_audit.log'
    & $Python $audit --cases $cases --binding $bindingPath --results $out --experiment-id $ExperimentId --sof-sha256 $sofSha --out $auditReceipt *> $auditLog
    $auditExit=$LASTEXITCODE
    $runStatus=if($auditExit -eq 0){'PASS_EMPIRICAL_PILOT'}else{'FAIL_ARTIFACT_AUDIT'}
  }
  $postLines=@(& $JtagConfig -n 2>&1);$postJtagExit=$LASTEXITCODE
  $postLines | Out-File -LiteralPath $jtagPost -Encoding utf8
  $postText=$postLines -join "`n"
  if($postJtagExit -ne 0 -or $postText -notmatch '02B050DD' -or $postText -notmatch 'Design hash\s+DF2731CF973C3275CFE6'){
    $runStatus='FAIL_POSTFLIGHT_IDENTITY'
  }else{$postDesignHash='DF2731CF973C3275CFE6'}
}
catch {
  $_ | Out-String | Set-Content -LiteralPath (Join-Path $out 'precheck_error.log') -Encoding utf8
  throw
}
$files=@{}
foreach($name in @('jtag_preflight.log','jtag_postflight.log','quartus_stp_tcl.log','c2_jtag_raw.log','c2_jtag_results.csv','c2_jtag_results.json','result_audit.json','result_audit.log','precheck_error.log')){
  $f=Join-Path $out $name;if(Test-Path -LiteralPath $f -PathType Leaf){$files[$name]=(Get-FileHash -LiteralPath $f -Algorithm SHA256).Hash.ToLowerInvariant()}
}
$run=[ordered]@{
  schema='rtnn-c3-jtag-pilot-run-v1';experiment_id=$ExperimentId;status=$runStatus
  repo_origin=$origin;branch=$branch;head=$head;cases_sha256=$caseSha
  binding_sha256=(Get-FileHash -LiteralPath $bindingPath -Algorithm SHA256).Hash.ToLowerInvariant()
  campaign_canonical_sha256=$binding.campaign_canonical_sha256;session_id=$binding.session_id
  selected_campaign_sequences=$binding.selected_frozen_schedule_sequences
  sof_sha256=$sofSha;firmware_elf_sha256=$fw.elf_sha256;model_id=$binding.model_id;build_id=$binding.build_id
  board_idcode='02B050DD';board_design_hash_pre=$designHash;board_design_hash_post=$postDesignHash
  quartus='Prime Lite 25.1std.0 Build 1129';quartus_stp_exit_code=$stpExit;result_audit_exit_code=$auditExit
  uart_used=$false;flash_written=$false;board_programming_performed_by_runner=$false
  measurement_scope=$binding.measurement_scope;timing_classification='EMPIRICAL_ONLY';wcet_or_hard_deadline_claimed=$false
  output_sha256=$files
}
$run | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $manifestPath -Encoding utf8
if($runStatus -ne 'PASS_EMPIRICAL_PILOT'){throw "Pilot ended with $runStatus; evidence: $out"}
Write-Output "C3_PILOT_PASS experiment_id=$ExperimentId results=$out"

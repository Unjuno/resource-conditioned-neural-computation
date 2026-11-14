[CmdletBinding()]
param(
  [Parameter(Mandatory=$true)][string]$CasesPath,
  [Parameter(Mandatory=$true)][string]$BindingPath,
  [Parameter(Mandatory=$true)][string]$SofPath,
  [Parameter(Mandatory=$true)][string]$ExperimentId,
  [Parameter(Mandatory=$true)][string]$OutputDirectory,
  [string]$Python='python',
  [string]$QuartusStpTcl='C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe',
  [string]$JtagConfig='C:\altera_lite\25.1std\quartus\bin64\jtagconfig.exe',
  [string]$BoardPowerSessionId='UNCONFIRMED',
  [switch]$ColdBootConfirmed,
  [ValidateRange(1,1000)][int]$ChunkSize=1000
)
$ErrorActionPreference='Stop'
if($ExperimentId -notmatch '^[A-Za-z0-9_.-]+$'){throw 'Invalid experiment ID.'}
$repoRoot=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..\..\..\..\..'))
$origin=(& git -C $repoRoot remote get-url origin).Trim();$branch=(& git -C $repoRoot branch --show-current).Trim();$head=(& git -C $repoRoot rev-parse HEAD).Trim()
if($origin -ne 'https://github.com/Unjuno/resource-conditioned-neural-computation.git'){throw "Wrong origin: $origin"}
if($branch -ne 'codex/stage-c3-jtag-pilot-20261114'){throw "Wrong work branch: $branch"}
$cases=(Resolve-Path -LiteralPath $CasesPath).Path;$bindingPath=(Resolve-Path -LiteralPath $BindingPath).Path;$sof=(Resolve-Path -LiteralPath $SofPath).Path
$binding=Get-Content -LiteralPath $bindingPath -Raw | ConvertFrom-Json
$caseSha=(Get-FileHash -LiteralPath $cases -Algorithm SHA256).Hash.ToLowerInvariant();if($caseSha -ne $binding.case_csv_sha256){throw 'Frozen case CSV SHA mismatch.'}
$sofSha=(Get-FileHash -LiteralPath $sof -Algorithm SHA256).Hash.ToLowerInvariant();if($sofSha -ne $binding.sof_sha256){throw 'SOF SHA mismatch.'}
$caseRows=@(Import-Csv -LiteralPath $cases);if($caseRows.Count -ne [int]$binding.record_count){throw 'Case count / binding mismatch.'}
if((Get-FileHash -LiteralPath $sof -Algorithm SHA256).Hash.ToLowerInvariant() -ne '5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6'){throw 'SOF is not the audited C2J2 physical image.'}
if(Test-Path -LiteralPath $OutputDirectory){throw "Refusing to overwrite output directory: $OutputDirectory"}
$null=New-Item -ItemType Directory -Path $OutputDirectory;$out=(Resolve-Path -LiteralPath $OutputDirectory).Path
$casesHashFile=Join-Path $out 'cases.sha256.txt';"$caseSha  $cases" | Set-Content -LiteralPath $casesHashFile -Encoding ascii
$pre=Join-Path $out 'jtag_preflight.log';$post=Join-Path $out 'jtag_postflight.log';$context=Join-Path $out 'execution_context.json';$auditOut=Join-Path $out 'result_audit.json';$auditLog=Join-Path $out 'result_audit.log';$chunkRoot=Join-Path $out 'chunk_jobs';$merged=Join-Path $out 'merged';$chunkIo=Join-Path $PSScriptRoot 'campaign_chunk_io.py'
$splitLines=@(& $Python $chunkIo split --cases $cases --out $chunkRoot --chunk-size $ChunkSize 2>&1);$splitExit=$LASTEXITCODE;$splitLines|Out-File -LiteralPath (Join-Path $out 'chunk_prepare.log') -Encoding utf8
if($splitExit -ne 0){throw "Could not split frozen case rows: exit=$splitExit"}
$chunkPlan=Get-Content -LiteralPath (Join-Path $chunkRoot 'chunks.json') -Raw | ConvertFrom-Json
$preLines=@(& $JtagConfig -n 2>&1);$preExit=$LASTEXITCODE;$preLines | Out-File -LiteralPath $pre -Encoding utf8;$preText=$preLines -join "`n"
if($preExit -ne 0 -or $preText -notmatch '02B050DD' -or $preText -notmatch 'Design hash\s+DF2731CF973C3275CFE6' -or $preText -notmatch 'Virtual JTAG #0'){throw 'Live board identity differs; JTAG measurements not started.'}
$alias='C:\rtnn_c3_pilot_20261114';$aliasItem=Get-Item -LiteralPath $alias -ErrorAction Stop
if($aliasItem.LinkType -ne 'Junction'){throw 'Expected ASCII junction missing.'}
$aliasTarget=(Resolve-Path -LiteralPath ([string]$aliasItem.Target)).Path.TrimEnd('\');if(-not [string]::Equals($aliasTarget,$repoRoot.TrimEnd('\'),[StringComparison]::OrdinalIgnoreCase)){throw "Junction target mismatch: $aliasTarget"}
$relTcl='artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\host\run_c3_jtag_pilot.tcl';$tclCli=Join-Path $alias $relTcl
$stp=(Resolve-Path -LiteralPath $QuartusStpTcl).Path;$cwd=Split-Path -Parent $stp
$tclSource=Join-Path $PSScriptRoot 'run_c3_jtag_pilot.tcl';$auditSource=Join-Path $PSScriptRoot 'audit_c3_campaign_session.py'
$toolHashes=[ordered]@{powershell_runner=(Get-FileHash -LiteralPath $PSCommandPath -Algorithm SHA256).Hash.ToLowerInvariant();quartus_tcl=(Get-FileHash -LiteralPath $tclSource -Algorithm SHA256).Hash.ToLowerInvariant();campaign_auditor=(Get-FileHash -LiteralPath $auditSource -Algorithm SHA256).Hash.ToLowerInvariant();chunk_io=(Get-FileHash -LiteralPath $chunkIo -Algorithm SHA256).Hash.ToLowerInvariant()}
$cmdline=[ordered]@{repo_root=$repoRoot;origin=$origin;branch=$branch;head=$head;working_directory=$cwd;quartus_stp_tcl=$stp;cases=$cases;cases_sha256=$caseSha;binding=$bindingPath;sof=$sof;sof_sha256=$sofSha;experiment_id=$ExperimentId;session_id=$binding.session_id;rows=$caseRows.Count;chunk_size=$ChunkSize;chunk_count=$chunkPlan.chunks.Count;board_power_session_id=$BoardPowerSessionId;cold_boot_confirmed=[bool]$ColdBootConfirmed;tool_source_sha256=$toolHashes;uart_used=$false;flash_written=$false;programmer_or_sof_download_invoked=$false;timing_classification='EMPIRICAL_ONLY';wcet_or_hard_deadline_claimed=$false;command_template=@('-t',$tclCli,'<chunk-cases.csv>','<chunk-results-dir>',$sofSha,$ExperimentId,'<chunk-sequences>')}
$cmdline | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $context -Encoding utf8
$stpExitCodes=@();$completedChunks=0
Push-Location -LiteralPath $cwd
try {
  foreach($job in $chunkPlan.chunks){
    $partCase=Join-Path $chunkRoot ([string]$job.case_file);$partResults=Join-Path $chunkRoot ([string]$job.result_dir)
    $partCaseCli=Join-Path $alias ([IO.Path]::GetRelativePath($repoRoot,$partCase));$partResultsCli=Join-Path $alias ([IO.Path]::GetRelativePath($repoRoot,$partResults));$seqs=[string]$job.sequences
    $partLog=Join-Path $partResults 'quartus_stp_tcl.log'
    $lines=@(& $stp -t $tclCli $partCaseCli $partResultsCli $sofSha $ExperimentId $seqs 2>&1);$rc=$LASTEXITCODE;$stpExitCodes+=@($rc);$lines|Out-File -LiteralPath $partLog -Encoding utf8
    if($rc -ne 0){break};$completedChunks++
  }
} finally {Pop-Location}
$stpExit=if($stpExitCodes.Count -eq $chunkPlan.chunks.Count -and @($stpExitCodes|Where-Object {$_ -ne 0}).Count -eq 0){0}else{1}
$mergeLines=@(& $Python $chunkIo aggregate --chunks $chunkRoot --out $merged 2>&1);$mergeExit=$LASTEXITCODE;$mergeLines|Out-File -LiteralPath (Join-Path $out 'chunk_aggregate.log') -Encoding utf8
$postLines=@(& $JtagConfig -n 2>&1);$postExit=$LASTEXITCODE;$postLines | Out-File -LiteralPath $post -Encoding utf8;$postText=$postLines -join "`n"
$postOk=($postExit -eq 0 -and $postText -match '02B050DD' -and $postText -match 'Design hash\s+DF2731CF973C3275CFE6')
$auditExit=-1
if($stpExit -eq 0 -and $mergeExit -eq 0 -and $postOk){
  $audit=Join-Path $PSScriptRoot 'audit_c3_campaign_session.py'
  & $Python $audit --cases $cases --binding $bindingPath --results $merged --experiment-id $ExperimentId --out $auditOut *> $auditLog
  $auditExit=$LASTEXITCODE
}else{
  $why=if($stpExit -ne 0){"NOT_RUN: one or more Quartus STP chunks failed; completed=$completedChunks/$($chunkPlan.chunks.Count)"}elseif($mergeExit -ne 0){"NOT_RUN: chunk aggregation exit=$mergeExit"}else{'NOT_RUN: postflight board identity mismatch'}
  @{status='NOT_RUN';reason=$why}|ConvertTo-Json|Set-Content -LiteralPath $auditOut -Encoding utf8
  $why|Set-Content -LiteralPath $auditLog -Encoding utf8
}
$status=if(-not $postOk){'FAIL_POSTFLIGHT_IDENTITY'}elseif($stpExit -ne 0){'FAIL_JTAG_RUN'}elseif($mergeExit -ne 0){'FAIL_CAMPAIGN_CHUNK_AGGREGATION'}elseif($auditExit -ne 0){'FAIL_EMPIRICAL_SESSION_AUDIT'}else{'PASS_EMPIRICAL_SESSION'}
$manifest=[ordered]@{schema='rtnn-c3-campaign-session-run-v1';experiment_id=$ExperimentId;status=$status;session_id=$binding.session_id;repo_origin=$origin;branch=$branch;head=$head;case_csv_sha256=$caseSha;binding_sha256=(Get-FileHash $bindingPath -Algorithm SHA256).Hash.ToLowerInvariant();schedule_sha256=$binding.schedule_canonical_sha256;campaign_canonical_sha256=$binding.campaign_canonical_sha256;sof_sha256=$sofSha;firmware_elf_sha256=$binding.firmware_elf_sha256;model_id=$binding.model_id;build_id=$binding.build_id;board_idcode='02B050DD';board_design_hash_pre='DF2731CF973C3275CFE6';board_design_hash_post=$(if($postOk){'DF2731CF973C3275CFE6'}else{''});board_power_session_id=$BoardPowerSessionId;cold_boot_confirmed=[bool]$ColdBootConfirmed;tool_source_sha256=$toolHashes;quartus_stp_exit_code=$stpExit;quartus_stp_chunk_exit_codes=$stpExitCodes;chunk_count=$chunkPlan.chunks.Count;completed_chunks=$completedChunks;chunk_aggregate_exit_code=$mergeExit;result_audit_exit_code=$auditExit;uart_used=$false;flash_written=$false;sof_programming_performed=$false;timing_classification='EMPIRICAL_ONLY';wcet_or_hard_deadline_claimed=$false;output_sha256=@{}}
Get-ChildItem -LiteralPath $out -Recurse -File | Where-Object {$_.Name -notin @('run_manifest.json','SHA256SUMS.txt')} | ForEach-Object {$rel=$_.FullName.Substring($out.TrimEnd('\').Length+1).Replace('\','/');$manifest.output_sha256[$rel]=(Get-FileHash $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant()}
$manifest | ConvertTo-Json -Depth 10 | Set-Content -LiteralPath (Join-Path $out 'run_manifest.json') -Encoding utf8
Get-ChildItem -LiteralPath $out -Recurse -File | Where-Object {$_.Name -ne 'SHA256SUMS.txt'} | ForEach-Object {$rel=$_.FullName.Substring($out.TrimEnd('\').Length+1).Replace('\','/');$hash=(Get-FileHash $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant();"$hash  $rel"} | Set-Content -LiteralPath (Join-Path $out 'SHA256SUMS.txt') -Encoding ascii
if($status -ne 'PASS_EMPIRICAL_SESSION'){throw "$status; evidence retained at $out"}
Write-Output "C3_EMPIRICAL_SESSION_PASS session=$($binding.session_id) rows=$($caseRows.Count) id=$ExperimentId results=$out"

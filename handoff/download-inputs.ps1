param(
 [string]$Destination = (Join-Path (Get-Location) 'inputs')
)
$ErrorActionPreference='Stop'
$base='https://raw.githubusercontent.com/Unjuno/resource-conditioned-neural-computation/handoff/de0cv-stage2-2026-11-03/handoff'
$items=@(
 @{ name='RTNN_DE0CV_RV32_stage2_2026-10-31.zip'; sha256='7f5c666514729b0d5f776904ec5662187271beb90f30d4c33231b7b92b4c5507' },
 @{ name='RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip'; sha256='c81f7bd81625247712fcea5d0a954dc3a7f24d2908e82e841de7eddfe908011e' },
 @{ name='RTNN_parallel_paper_eval_2026-11-02.zip'; sha256='02ad8a83daabcef44335d58513c2f4ae0aef622089eae62026df6b2406ede137' }
)
New-Item -ItemType Directory -Path $Destination -Force | Out-Null
foreach($i in $items){
 $dest=Join-Path $Destination $i.name
 if(Test-Path -LiteralPath $dest){
  $old=(Get-FileHash -LiteralPath $dest -Algorithm SHA256).Hash.ToLowerInvariant()
  if($old -eq $i.sha256){ Write-Host "Already verified: $($i.name)"; continue }
  throw "Existing file SHA mismatch, refusing overwrite: $dest"
 }
 $tmp=Join-Path $Destination ('.'+$i.name+'.download')
 if(Test-Path -LiteralPath $tmp){throw "Partial download exists; inspect before retry: $tmp"}
 try {
  Invoke-WebRequest -Uri ($base+'/'+$i.name) -OutFile $tmp
  $got=(Get-FileHash -LiteralPath $tmp -Algorithm SHA256).Hash.ToLowerInvariant()
  if($got -ne $i.sha256){throw "Download SHA mismatch: $($i.name) got $got"}
  Move-Item -LiteralPath $tmp -Destination $dest -ErrorAction Stop
  Write-Host "SHA256 OK: $($i.name)"
 } catch {Write-Error $_;throw}
}
Write-Host "Three verified RTNN inputs available at: $Destination"

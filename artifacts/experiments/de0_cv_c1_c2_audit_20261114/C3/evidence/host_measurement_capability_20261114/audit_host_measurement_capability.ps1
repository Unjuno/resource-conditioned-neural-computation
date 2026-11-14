$ErrorActionPreference = 'Stop'
$quartus = 'C:\altera_lite\25.1std\quartus\bin64'
Write-Output "cwd=$((Get-Location).Path)"
Write-Output "quartus_path=$quartus"
foreach ($exe in @('quartus_sh.exe','quartus_stp.exe','jtagconfig.exe')) {
    $path = Join-Path $quartus $exe
    Write-Output "$exe present=$(Test-Path -LiteralPath $path -PathType Leaf)"
}
Write-Output '--- Quartus version ---'
& (Join-Path $quartus 'quartus_sh.exe') --version
if ($LASTEXITCODE -ne 0) { throw "quartus_sh --version exit=$LASTEXITCODE" }
Write-Output '--- matching present USB / measurement devices (name/status/class only) ---'
$devicePattern = 'USB-Blaster|Blaster|Saleae|PicoScope|Analog Discovery|Digilent|Logic Analyzer|Oscilloscope|Keysight|Tektronix|Siglent'
$devices = @(Get-CimInstance Win32_PnPEntity | Where-Object { $_.Name -match $devicePattern } | Select-Object Name,Status,PNPClass)
if ($devices.Count) { $devices | Format-Table -AutoSize | Out-String | Write-Output } else { Write-Output '(no matching present device)' }
Write-Output '--- matching installed applications (display name/version only) ---'
$uninstallKeys = @(
    'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\*',
    'HKLM:\SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\Uninstall\*',
    'HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\*'
)
$appPattern = 'Saleae|PicoScope|WaveForms|Analog Discovery|Siglent|Tektronix|Keysight|Quartus|USB-Blaster'
$apps = @(Get-ItemProperty $uninstallKeys -ErrorAction SilentlyContinue | Where-Object { $_.DisplayName -match $appPattern } | Select-Object DisplayName,DisplayVersion | Sort-Object DisplayName)
if ($apps.Count) { $apps | Format-Table -AutoSize | Out-String | Write-Output } else { Write-Output '(no matching installed application)' }
Write-Output 'scope=read-only name-filtered host inventory; no JTAG scan, programming, settings change, or board I/O performed'

param(
  [string]$DownloadDirectory = 'D:\rtnn_quartus_lite_25_1_linux',
  [string]$ManifestPath = ''
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$officialSource = 'https://www.altera.com/downloads/fpga-development-tools/quartus-prime-lite-edition-design-software-version-25-1-linux'
$requiredFiles = @(
  [ordered]@{
    name = 'QuartusLiteSetup-25.1std.0.1129-linux.run'
    publishedSha1 = 'ce0773469eacab5b7035c175484625f4ec3737d1'
  },
  [ordered]@{
    name = 'cyclonev-25.1std.0.1129.qdz'
    publishedSha1 = 'a7225ec1bd36ccfd6826ea6273df5d21dd95633b'
  }
)

if (-not (Test-Path -LiteralPath $DownloadDirectory -PathType Container)) {
  throw "Download directory does not exist: $DownloadDirectory"
}

$verifiedFiles = @()
foreach ($required in $requiredFiles) {
  $path = Join-Path $DownloadDirectory $required.name
  if (-not (Test-Path -LiteralPath $path -PathType Leaf)) {
    throw "Required official Quartus payload is missing: $path"
  }

  $sha1 = (Get-FileHash -LiteralPath $path -Algorithm SHA1).Hash.ToLowerInvariant()
  if ($sha1 -ne $required.publishedSha1) {
    throw "Published SHA-1 mismatch for $($required.name): expected $($required.publishedSha1), got $sha1"
  }

  $sha256 = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
  $item = Get-Item -LiteralPath $path
  $verifiedFiles += [ordered]@{
    name = $required.name
    size_bytes = $item.Length
    official_sha1 = $sha1
    local_sha256 = $sha256
    status = 'PASS_OFFICIAL_SHA1'
  }
}

$manifest = [ordered]@{
  schema = 'rtnn-c2-quartus-linux-download-verification-v1'
  verified_at_utc = [DateTime]::UtcNow.ToString('yyyy-MM-ddTHH:mm:ssZ')
  official_source = $officialSource
  files = $verifiedFiles
  nonclaims = @(
    'download verification only; no installer was executed',
    'Quartus device support, synthesis, fitter, STA, or board programming not verified by this manifest'
  )
}

if ([string]::IsNullOrWhiteSpace($ManifestPath)) {
  $ManifestPath = Join-Path $DownloadDirectory 'quartus_linux_download_manifest.json'
}
if (Test-Path -LiteralPath $ManifestPath) {
  throw "Refusing to overwrite existing verification evidence: $ManifestPath"
}
$manifest | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $ManifestPath -Encoding utf8
Get-Content -LiteralPath $ManifestPath -Raw

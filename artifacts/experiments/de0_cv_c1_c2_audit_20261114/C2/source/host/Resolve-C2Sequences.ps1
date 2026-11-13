param([AllowNull()][AllowEmptyCollection()][int[]]$SequenceIds)
$ErrorActionPreference = 'Stop'
if ($null -eq $SequenceIds) { return (1..42) }
if ($SequenceIds.Count -eq 0) { throw 'CaseSequences must not be empty.' }
$seen = @{}
foreach ($id in $SequenceIds) {
  if ($id -lt 1 -or $id -gt 42) { throw 'CaseSequences must contain only IDs 1 through 42.' }
  if ($seen.ContainsKey($id)) { throw "Duplicate CaseSequences ID: $id" }
  $seen[$id] = $true
}
return $SequenceIds

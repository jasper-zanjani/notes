# Observations on the learning process

## Anki
Made good progress incorporating task-based learning by simplifying procedures into command sequences with no parameters or (at most) one or two. Used a spreadsheet to concatenate hand-entered text values in a cloze Anki flashcard.

#### Two tasks with related forms
```
* Get connection string of account
  constring=$(az storage account show-connection-string)

* Create file share with connection string
  az storage share create
    --connection-string $constring
```
Here, both instances of `storage` are tested at once.

#### Single task with different implementations
```
* Create an availability set (PowerShell) (3.1b.02)
New-AzAvailabilitySet
  -PlatformUpdateDomainCount
  -PlatformFaultDomainCount
  -Sku "{{c8::Aligned}}"

* Create an availability set (CLI) (3.1b.03)
az vm availability-set create
  --platform-update-domain-count
  --platform-fault-domain-count
```

#### Config object pattern
```
* Capture a managed VM image (3.1a.05)
$vm = Get-AzVM
$image = New-AzImageConfig -SourceVirtualMachineId $vm.Id
New-AzImage -Image $image
```

## Sources
  [AZ-103 Tasks](sources/az-103-tasks.md)
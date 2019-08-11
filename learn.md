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
{{c1::New-AzAvailabilitySet}}
  -{{c2::PlatformUpdateDomainCount}}
  -{{c3::PlatformFaultDomainCount}}
  -{{c4::Sku}} "{{c8::Aligned}}"

* Create an availability set (CLI) (3.1b.03)
az {{c5::vm availability-set create}}
  --{{c6::platform-update-domain-count}}
  --{{c7::platform-fault-domain-count}}
```
# Observations on the learning process

## Anki
Made good progress incorporating task-based learning by simplifying procedures into command sequences with no parameters or (at most) one or two. Used a spreadsheet to concatenate hand-entered text values in a cloze Anki flashcard.

#### Two tasks with related forms
```bash
* Get connection string of account
  constring=$(az storage account show-connection-string)

* Create file share with connection string
  az storage share create
    --connection-string $constring
```
Here, both instances of `storage` are tested at once.

#### Single task with different implementations
```powershell
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

## PowerShell
#### Get-Set pattern
```powershell
# Capture a managed VM image (3.1a.05)
$vm = Get-AzVM
$image = New-AzImageConfig -SourceVirtualMachineId $vm.Id
New-AzImage -Image $image
```
```powershell
$vnet2 = Get-AzVirtualNetwork -Name VNet2 -ResourceGroupName ExamRefRG
$vnet2.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.2.1.0/27
$vnet2 = Set-AzVirtualNetwork -VirtualNetwork $vnet2
```
```powershell
# Create a record set at the zone apex containing multiple records
$records = @()
$records += New-AzDnsRecordConfig -IPv4Address "1.2.3.4"
$records += New-AzDnsRecordConfig -IPv4Address "5.6.7.8"
New-AzDnsRecordSet -Name "@" -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords $records
```
## Sources
  [AZ-103 Tasks](sources/az-103-tasks.md)
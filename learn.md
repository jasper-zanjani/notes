# Observations on the learning process

#### Finding magic numbers
Before understanding the "lay of the land", or rather the best epistemology for a unit of information, you are first confronted with a list of information without context. This happened while studying for the Network+. On the topic of authentication, I learned a list of material, basically concepts associated with AAA. 
```markdown
- **Authentication** process of determining...
- **Authorization** identifying the resources...
- **Accounting** tracking methods used ...
- **Authentication, Authorization, Accounting, and Auditing (AAAA)** conceptual model...
- **Remote Authentication Dial-In User Service (RADIUS)** protocol that enables ...
- **Terminal Access Control Access Control System (TACACS)** security protocol designed ...
- **Kerberos** security system ...
  - **ticket** security tokens issued to clients ...
- **Local authentication subsystem (LASS)** authenticates users ...
```
But after further research, I found that once you understand the role of authentication, then really there are only three main systems that implement it (according to the material): **Kerberos**, **TACACS**, and **RADIUS**.\
Reducing a confusing mass of knowledge into a magic number (2, 3, 4, etc) helps in identifying interrelationships between concepts and entities

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
```powershell
$vm = Get-AzVM
$vm.HardwareProfile.VMSize = Standard_DS3_v2
Update-AzVM -VM $vm
```
```powershell
$rt = New-AzRouteTable
Add-AzRouteConfig -RouteTable $rt
Set-AzRouteTable -RouteTable $rt
```

#### Structure
Playing around with reference-style links and tooltips has me thinking that there really should be a more structured, flexible way of generating text reports from object-style hierarchical information. For example, whether a definition appears beside a word dictionary style or in a tooltip on hover is really an implementation detail. There should be an easy way of storing that data and specifying that presentation dynamically.

What I have settled on is a multilayered note-taking strategy. Every **lexeme** is defined first in a **slug** or one-line description that establishes its **epistemological** context as well as its **semantic** significance. A **stub** further elaborates the lexeme, especially insofar as it encapsulates further lexemes or can be analyzed into components.

These slugs and stubs can be presented in various ways. Most recently I have gotten into the habit of putting slugs into tooltips that appear when I hover over lexemes in my markdown notes. This is an especially elegant solution in tables, where I can provide a highly condensed and legible index of commands, each of which can be understood at a high level by hovering the mouse while still providing full details when clicked on. This is also an elegant solution in tables of contents, where I can use a tooltip to contain a synopsis of a chapter which still links to the full notes. It provides a way of rendering information of intermediary fidelity, between the mere title and fully developed notes.

## Sources
  [AZ-103 Tasks](sources/az-103-tasks.md)
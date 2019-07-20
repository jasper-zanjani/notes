# PowerShell commands for Azure

Command                           | Skill   | Task
:---                              | :---    | :---
**AzKeyVault**
`Add-AzKeyVaultKey`               | 2.1c.3  | **Store a software managed key in Azure Key Vault**
`New-AzKeyVault`                  | 2.1c.2  | **Create an Azure Key Vault**
`Set-AzKeyVaultSecret`            | 2.1c.6  | **Set secret value to be used in Azure Key Vault**
**AzResource**
`Get-AzResource`                  | 1.1b.3  | **Tag a resource group that has not already been tagged**
^                                 | 1.1b.4  | **Tag a resource group that already had been tagged**
^                                 |         | **Enable diagnostics log collection with a storage account**
`Set-AzResource`                  | 1.1b.3  | **Tag a resource group that has not already been tagged**
^                                 | 1.1b.4  | **Tag a resource group that already had been tagged**
**AzResourceGroup**
`Get-AzResourceGroup`             | 1.1b.4  | **Tag a resource group that already had been tagged**
^                                 | 1.2a.2  | **Enable diagnostics log collection with a storage account**
`New-AzResourceGroup`             |         | **Create a Resource Group**
^                                 |         | **Create a new Log Analytics workspace**
`Remove-AzResourceGroup`          | 1.3.1   | **Delete a resource group**
^                                 | 1.3.2   | **Delete a resource group without confirmation**
`Set-AzResourceGroup`             | 1.1b.4  | **Tag a resource group that already had been tagged**
**AzRoleAssignment**
`New-AzRoleAssignment`            | 1.4c.6  | **Grant a user RBAC rights**
^                                 | 1.4c.8  | **Grant a group RBAC rights**
`Remove-AzRoleAssignment`         | 1.4c.10 | **Remove RBAC assignments from a user**
^                                 | 1.4c.11 | **Remove RBAC assignments from a group**
**AzStorageAccount**
`New-AzStorageAccount`            | 2.1a.2  | **Create a storage account**
`Set-AzStorageAccount`            | 2.1a.4  | **Change storage account's access tier, without confirmation**
^                                 | 2.1f.1  | **Change replication mode of a storage account**
**AzStorageBlobSASToken**
`New-AzStorageBlobSASToken`       | 2.1d.1  | **Create a SAS token for a specific storage blob**
**AzStorageAccountKey**
`New-AzStorageAccountKey`         | 2.1c    | Regenerating access keys (notes only)
`Get-AzStorageAccountKey`         | 2.1c.4  | **Retrieve a storage account key**
^                                 | 2.3     | **Create an Azure File Share**
^                                 | 2.3     | **Connect to and mount an Azure File Share**
Uncategorized Command             | Skill   | Task
:---                              | :---    | :---
`Add-AzNetworkSecurityRuleConfig` |         | **Modify Network Security Group policies**
`Add-AzVMNetworkInterface`        | 2.1     | **Deploy a Windows Server Core VM**
`Connect-AzAccount`               |         | **Connect to Azure**
`ConvertTo-Json`                  | 1.4b.1  | **Retrieve the definition of a role**
`ConvertTo-SecureString`          | 2.1c.5  | **Convert storage account key to secure string**
`Enable-PSRemoting`               |         | **Connect to VM from a Windows machine**
`Enter-PSSession`                 |         | **Connect to VM from a Windows machine** 
`Get-AzADGroup`                   | 1.4c.8  | **Grant a group RBAC rights**
`Get-AzNetworkSecurityGroup`      |         | **Modify Network Security Group policies**
`Get-AzOperationalInsightsWorkspace` | 1.2a.4 | **Enable diagnostics log collection in a Log Analytics workspace**
`Get-AzProviderOperation`         | 1.4b.3  | **Retrieve operations that support `DataActions` and `NotDataActions`**
`Get-AzPublicIpAddress`           |         | **Display IP Address**
`Get-AzRoleDefinition`            | 1.4b.1  | **Retrieve the definition of a role**
^                                 | 1.4c.3  | **List roles available for assignment** 
`Get-AzServiceBusRule`            | 1.2a.3  | **Enable diagnostics log streaming to an Event Hub**
`Get-AzStorageBlobCopyState`      |         | **Use async blob copy service to copy a file**
`Get-AzStorageUsage`              | 1.1b.1  | **Configure resource quotas**
`Get-AzSubscription`              |         | **Display Azure subscription ID**
`Get-AzVMImage`                   |         | **Deploy a Windows Server Core VM**
^                                 |         | **Find a Marketplace image**
`Get-AzVMImageOffer`              |         | **Find a Marketplace image** 
`Get-AzVMImagePublisher`          |         | **Find a Marketplace image** 
`Get-AzVMImageSku`                |         | **Find a Marketplace image**
`Get-AzVMUsage`                   | 1.1b.1  | **Configure resource quotas**
`Install-Module`                  |         | **Install the Azure Resource Manager PowerShell module**
`Invoke-AzVMRunCommand`           |         | **Invoking a command on a VM**
`New-AzResourceGroupDeployment`   |         | **Create a new Log Analytics workspace**
`New-AzRoleAssignment`            | 1.4c.6  | **Grant a user RBAC rights**
^                                 | 1.4c.7  | **Grant a group RBAC rights**
`New-AzStorageAccountSASToken`    | 2.1d    | Mentioned only
`New-AzStorageBlobSASToken`       | 2.1d    | Mentioned only
`New-AzStorageContainer`          |         | **Create a storage container**
^                                 |         | **Use async blob copy service to copy a file**
`New-AzStorageContainerSASToken`  | 2.1d
`New-AzStorageContext`            |         | **Use async blob copy service to copy a file**
^                                 | 2.3     | **Create an Azure File Share**
`New-AzStorageFileSASToken`       | 2.1d    | Mentioned only
`New-AzStorageQueueSASToken`      | 2.1d    | Mentioned only
`New-AzStorageShareSASToken`      | 2.1d    | Mentioned only
`New-AzStorageTableSASToken`      | 2.1d    | Mentioned only
`New-AzStorageShare`              | 2.3     | **Create an Azure File Share**
`New-AzVM`                        |         | **Create a VM**
`New-AzVMConfig`                  |         | **Create a VM**
^                                 |         | **Deploy a Windows Server Core VM**
`New-NetFirewallRule`             |         | **Connect to VM from a Windows machine** 
`New-PSDrive`                     |         | **Connect to and mount an Azure File Share**
`Remove-AzRoleAssignment`         | 1.4c.10 | **Remove RBAC assignments from a user**
^                                 | 1.4c.11 | **Remove RBAC assignments from a group**
`Set-AzCurrentStorageAccount`     |         | **Create a storage container**
`Set-AzDiagnosticSetting`         |         | **Enable diagnostics log collection with a storage account**
^                                 |         | **Enable diagnostics log collection in a Log Analytics workspace**
`Set-AzNetworkSecurityGroup`      |         | **Modify Network Security Group policies**
`Set-AzDiagnosticSetting`         |         | **Enable all metrics and logs for a resource**
^                                 |         | **Disable all metrics and logs**
^                                 | 1.2a.2  | **Enable diagnostics log collection with a storage account**
^                                 | 1.2a.3  | **Enable diagnostics log streaming to an Event Hub**
^                                 | 1.2a.4  | **Enable diagnostics log collection in a Log Analytics workspace**
`Set-AzStorageBlobContent`        |         | **Create a storage blob**
`Start-AzStorageBlobCopy`         |         | **Use async blob copy service to copy a file**
`Set-AzVMOperatingSystem`         |         | **Deploy a Windows Server Core VM**
`Set-AzVMSourceImage`             |         | **Create a VM**
`Set-Item`                        |         | **Connect to VM from a Windows machine** 
`Start-AzVM`                      |         | **Start a VM**
`Start-AzStorageBlobCopy`         | 2.1f.2  | **Use async blob copy service to copy a file**
`Stop-AzVM`                       |         | **Shut down a VM**

#### Install the Azure Resource Manager PowerShell module
The older module __AzureRM__ has been replaced, largely, by __Az__. Commands to the older module are aliased to the new, but there are some commands which require the older module.
```powershell
Install-Module -Name Az -AllowClobber
Install-Module AzureRM
```

#### Connect to Azure 
`Connect-AzAccount` will produce an alphanumeric code that you must enter on [Microsoft's website](https://microsoft.com/devicelogin) to complete authentication.

```powershell
Connect-AzAccount
```

#### Create a Resource Group
`New-AzResourceGroup` has two required parameters
  - `-Name` which can be defined positionally at position __0__
  - `-Location`, the geographic area ("EastUS", "CentralUS", etc), defined positionally at position __1__

```powershell
New-AzResourceGroup RG WestUS
```

#### Deploy a Windows Server Core VM
```powershell
$vm = Get-AzVMImage `
-Location EastUS `
-Offer WindowsServer `
-PublisherName MicrosoftWindowsServer `
-Skus 2016-Datacenter-Server-Core `
-Version 2016.127.20190603
```

Sku: `2016-Datacenter-Server-Core`
Size: `Standard_B1ls`, 1 core, 512 MB RAM, 1 TB disk size
```powershell
$vm = New-AzVMConfig -VMName Spike -VMSize Standard_B1ls
$vm = Set-AzVMOperatingSystem $vm -Windows -ComputerName SpikeSpiegel -Crednetial $aztestadmin
$vm = Add-AzVMNetworkInterface
```

Set-AzVMOperatingSystem options:

Option                            | Position  | Description
:---                              | :---      | :---
`-VM`                             | 0 | Local virtual machine object on which to set OS properties
`-Linux`                          | 1 | Indicates that the OS is Linux
`-Windows`                        | 1 | Indicates OS type is Windows
`-ComputerName`                   | 2 | Name of the computer
`-Credential`                     | 3
`-CustomData`                     | 4 | Optional
`-DisablePasswordAuthentication`  | 5 | Optional
`-ProvisionVMAgent`               | 5 | Optional
`-EnableAutoUpdate`               | 6 | Optional
`-TimeZone`                       | 7 | Optional
`-WinRMHttp`                      | 8 | Optional: indicates that the system uses HTTP WinRM
`-WinRMHttps`                     | 9 | Indicates that the system uses HTTPS WinRM
`-WinRMCertificateUrl`            | 10 | Use of WinRM certificate, stored in a Key Vault

#### Create a VM
`New-AzVM`

Option                | Position  | Description
:---                  | :---      | :---
`-ResourceGroupName`  | 0         | Optional
`-Location`           | 1         | Optional
`-VM`                 | 2
`-Zone`               | 3         | Optional


```powershell
New-AzVM -ResourceGroupName "RG" -Name "VM" -Location "EastUS" -Size "Standard-B2s" -Credential (Get-Credential)
```

Or, taking advantage of positional parameters
```powershell
New-AzVM Greeks Socrates $vm
```

The `-Image` optional named parameter can be used to define other operating systems, and requires friendly image names. If a Linux image is provided, you should provide the `-Linux` switch parameter as well in order to specify a Linux-type disk file.
  - Win2016Datacenter (default)
  - Win2012R2Datacenter
  - Win2012Datacenter
  - Win2008R2SP1
  - UbuntuLTS
  - CentOS
  - CoreOS
  - Debian
  - openSUSE-Leap
  - RHEL
  - SLES

A custom image object can be built up and passed to `New-AzVM` through the `-VM` named parameter by using other commands:
```powershell
...
$vm = New-AzVMConfig -VMName $VMName -VMSize $VMSize
$vm = Set-AzVMOperatingSystem -VM $vm -Windows -ComputerName $ComputerName -Credential $Credential -Provision VMAgent -EnableAutoUpdate
$vm = Add-AzVMNetworkInterface -VM $vm -Id $NIC.Id
$vm = Set-AzVMSourceImage -VM $vm -PublisherName 'MicrosoftWindowsServer' -Offer 'WindowsServer' -Skus '2012-R2-Datacenter' -Version latest

New-AzVM -ResourceGroupName $ResourceGroupName -Location $LocationName -VM $vm
```

#### Find a Marketplace image
`Get-AzVMImagePublisher` produces the publisher, e.g. "MicrosoftWindowsServer"
  - `-Location`

`Get-AzVMImageOffer` produces the offer, e.g. "WindowsServer"
  - `-Location`
  - `-PublisherName`

`Get-AzVMImageSku` produces the sku, e.g.  "2016-Datacenter-Server-Core"
  - `-Location`
  - `-Offer`
  - `-PublisherName`

`Get-AzVMImage` requires the following named parameters:
  - `-Location` i.e. "EastUS"
  - `-PublisherName` cf. `Get-AzVMImagePublisher`
  - `-Offer` cf. `Get-AzVMImageOffer`
  - `-Skus` cf. `Get-AzVMImageSku`
  - `-Version` providing `*` will produce a list of available versions

#### Start a VM
`Start-AzVM` requires at minimum __2__ arguments:

Option              | Mandatory | Position
:---                | :--- | :---
`-Id`, `-ResourceGroupName` | ✔ | 0
`-Name`             | ✔ | 1

```powershell
Start-AzVM Greeks Socrates
```

#### Shut down a VM
```powershell
Stop-AzVM RG VM
```

#### Connect to VM from a Windows machine
1. WinRM access must be enabled on the target VM as well as the local machine.
```powershell
Enable-PSRemoting
```
Alternatively:
```cmd
winrm quickconfig
```

It can also be done through Azure, using `Invoke-AzVMRunCommand -CommandId EnableRemotePS`

2. __Modify Network Security Group policy__ (see below) to allow inbound connections to ports 5985 and 5986, which are used by WinRM.

3. Add the VM's public IP address &lt;$ipaddr&gt; to the trusted hosts of the local machine (must be run as administrator):
```powershell
Set-Item WSMan:\localhost\Client\TrustedHosts -Value ipaddr
```

4. Open the WinRM ports in the VM's firewall, if Windows Firewall is activated. The commands provided here can be run locally on the VM, or invoked through Azure:

```powershell
New-NetFirewallRule -DisplayName "WinRMHTTP" -Direction Inbound -LocalPort 5985 -Protocol TCP -Action Allow
New-NetFirewallRule -DisplayName "WinRMHTTPS" -Direction Inbound -LocalPort 5986 -Protocol TCP -Action Allow
```

Alternatively:

```cmd
netsh advfirewall firewall add rule name=WinRMHTTP dir=in action=allow protocol=TCP localport=5985
netsh advfirewall firewall add rule name=WinRMHTTPS dir=in action=allow protocol=TCP localport=5986
```

5.  Connect to the VM's public IP, passing along a previously-stored credential:
```powershell
$cred=Get-Credential
Enter-PSSession -ComputerName 123.47.78.90 -Credential $cred
```

Or, enter the credential dynamically
```powershell
etsn -ComputerName 123.45.67.89 -Credential (Get-Credential)
```

#### Connect to VM from a Mac or Linux machine
Using OpenSSH...

#### Display Azure subscription ID
```powershell
Get-AzSubscription | select -ExpandProperty Id
```

#### Invoking a command on a VM
`Invoke-AzVMRunCommand` requires only a single option: `-CommandId`. You can pass along a script containing predefined commands using the named parameter `-ScriptPath`, but the value for `-CommandId` must be `RunPowerShellScript`. Unlike `Invoke-Command, there is no way to define commands inline.
```powershell
Invoke-AzVMRunCommand -ResourceGroupName RG -VMName VM -CommandId 'RunPowerShellScript' -ScriptPath C:\injectedscript.ps1
```

#### Modify Network Security Group policies
Open inbound ports are most easily defined at the time of VM creation (`New-AzVM ... -OpenPorts 5985,5986 ...`).

From __Azure Portal__: Virtual machines > VM to be modified > (Settings) Networking > Network interface > Add inbound port rule button 

In PowerShell, an __inbound security rule__ can be created:
```powershell
Get-AzNetworkSecurityGroup -Name NSG -ResourceGroupName 4SysOps | 
Add-AzNetworkSecurityRuleConfig
  -Name AllowingWinRMHTTP -Description "To Enable PowerShell Remote Access"
  -Access Allow -Protocol Tcp -Direction Inbound -Priority 103 
  -SourceAddressPrefix Internet -SourcePortRange * 
  -DestinationAddressPrefix * -DestinationPortRange 5985 | 
Set-AzNetworkSecurityGroup
```

#### Display IP address
`Get-AzPublicIpAddress` takes the name of the resource (e.g. where &lt;VM&gt; is the name of the virtual machine, "VM-ip") and returns an object with a property `IpAddress`
```powershell
Get-AzPublicIpAddress Socrates-ip | select IpAddress
```

In order to use the output in an evaluated expression (like command substitution in bash), the property has to be expanded with the `-ExpandProperty` switch.
```powershell
Get-AzPublicIpAddress Socrates-ip | select -ExpandProperty IpAddress
```

#### Tag a resource group that already had been tagged (PowerShell)
```powershell
$tags = (Get-AzResourceGroup -Name hrgroup).Tags
$tags.Add("Owner","user@contoso.com")
Set-AzResourceGroup -Tag $tags -Name hrgroup
```

Using the `Add()` method
```powershell
$r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName hrgroup
$r.Tags.Add("Owner","user@contoso.com")
Set-AzResource -Tag $r.Tags -ResourceId $r.ResourceId -Force
```

#### Tag a resource-group that has not already been tagged (PowerShell)
```powershell
$r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName hrgroup
Set-AzResource -Tag @{ CostCode="1001"; Environment="Production" } -ResourceId
$r.ResourceId -Force
```

#### Enable diagnostics log collection with a storage account
```powershell
PS C:\> $resource = Get-AzResource `
>>   -Name <resourceName> `
>>   -ResourceGroupName <resourceGroupName>
PS C:\> $storage = Get-AzResource `
>>   -Name <resourceName> `
>>   -ResourceGroupName <resourceGroupName>
PS C:\> Set-AzDiagnosticSetting `
>>   -ResourceId $resource.ResourceId `
>>   -StorageAccountId $storage.ResourceId `
>>   -Enabled $true
```

#### Enable diagnostics log streaming to an Event Hub (PowerShell)
```powershell
PS C:\> $rule = Get-AzServiceBusRule -ResourceGroup <resourceGroupName> `
>> -Namespace <namespace> `
>> -Topic <topic> `
>> -Subscription <subscription> `
>> -Name <ruleName> 
PS C:\> Set-AzDiagnosticSetting `
>> -ResourceId $resource.ResourceId `
>> -ServiceBusRuleId $rule.Id `
>> -Enabled $true
```

#### Enable diagnostics logs collection in a Log Analytics workspace (PowerShell)
```powershell
PS C:\> $workspace = Get-AzOperationalInsightsWorkspace `
>> -Name <workspaceName> `
>> -ResourceGroupName <resourceGroupName> 
PS C:\> Set-AzDiagnosticSetting `
>> -ResourceId $resource.ResourceId `
>> -WorkspaceId $workspace.ResourceId `
>> -Enabled $true
```

#### Create a new Log Analytics workspace (PowerShell)
A new workspace can be configured through the Log Analytics blade, or through APIs using a Resource Manager template.
```powershell
PS C:\> $params = @{
>> workspaceName = "ExampleLA"
>> location = "eastus"
>> sku = "PerGB2018"
}
PS C:\> New-AzResourceGroup `
>> -Name ExamRefRG `
>> -Location "East US"
PS C:\> New-AzResourceGroupDeployment `
>> -ResourceGroupName ExamRefRG `
>> -TemplateFile 'azuredeploy.json' `
>> -TemplateParameterObject $params `
>> -Verbose
```

#### Delete a resource group
```powershell
PS C:\> Remove-AzResourceGroup -Name "hrgroup"
```

#### Delete a resource group without confirmation
```powershell
PS C:\> Remove-AzResourceGroup -Name "hrgroup" -Force
```

#### 2.1a.2: Create a storage account
> AZ-103: 2.1a.2 p. 107
```powershell
PS C:\> New-AzStorageAccount `
>> -ResourceGroupName RG
>> -Name mystorage112300
>> -SkuName Standard_LRS
>> -Location WestUS
>> -Kind StorageV2
>> -AccessTier Hot
```

#### 2.1a.4: Change storage account's access tier, without confirmation 
> AZ-103: 2.1a.4 p. 107
```powershell
PS C:\> Set-AzStorageAccount `
>> -ResourceGroupName RG `
>> -Name $accountName `
>> -AccessTier Cool `
>> -Force
```

#### Enable all metrics and logs for a resource
```powershell
PS C:\> Set-AzDiagnosticSetting `
>> -ResourceId <resourceId> `
>> -Enabled $True
```

#### Disable all metrics and logs
```powershell
PS C:\> Set-AzDiagnosticSetting `
>> -ResourceId <resourceId> `
>> -Enabled $False
```

#### Create an Azure Key Vault (PowerShell)
```powershell
PS C:\> New-AzKeyVault `
>>  -VaultName vaultName `
>>  -ResourceGroupNAme rgName `
>>  -Location EastUS 
```

#### Create a software managed key in Azure Key Vault (PowerShell)
```powershell
PS C:\> Add-AzKeyVaultKey `
>>  -VaultName vaultName `
>>  -Name keyName `
>>  -Destination 'Software'
```

#### Retrieve a storage account key (PowerShell)
```powershell
PS C:\> $storageKey = Get-AzStorageAccountKey `
>>  -ResourceGrouupName rgName `
>>  -Name storageAccount `
```

#### Convert storage account key to secure string
```powershell
PS C:\> $secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force
```

#### Set secret value to be used  (PowerShell)
```powershell
PS C:\> $secret = Set-AzKeyVaultSecret `
>>  -VaultName vaultName `
>>  -Name $secretName `
>>  -SecretValue $secretvalue
```

#### Create a SAS token for a specific storage blob
```powershell
PS C:\> New-AzStorageBlobSASToken `
>>  -Container $container `
>>  -Blob $blob `
>>  -Permission "rwd" `
>>  -StartTime $startTime `
>>  -ExpiryTime $startTime.AddHours(4) `
>>  -Context $context
```

#### Use async blob copy service to copy a file
```powershell
PS C:\> $blobCopyState = Start-AzStorageBlobCopy `
>>  -SrcBlob $blobName `
>>  -SrcContainer $srcContainer `
>>  -Context $srcContext `
>>  -DestContainer $destContainer `
>>  -DestBlob $vhdName
```

#### Create a storage container
`New-AzStorageContainer` require a storage context to be set, specifying the storage account anme and authentication credentials.

```powershell
PS C:\> $storageKey = Get-AzStorageAccountKey
>>  -Name $storageAccount `
>>  -ResourceGroupName $resourceGroup

PS C:\> $context = New-AzStorageContext `
>>  -StorageAccountName $storageAccount `
>>  -storageAccountKey $storageKey.Value[0]

PS C:\> Set-AzCurrentStorageAccount -Context $context

PS C:\> New-AzStorageContainer `
>>  -Name $container
>>  -Permission Off
```

#### Create a storage blob
```powershell
PS C:\> Set-AzStorageBlobContent `
>>  -File $localFile `
>>  -Container $container `
>>  -Blob $blobName
```

#### Create an Azure File Share
```powershell
PS C:\> $storageKey = Get-AzStorageAccountKey
>>  -ResourceGroupName $rgName
>>  -Name $storageAccount

PS C:\> $context = New-AzStorageContext
>>  -StorageAccountName $storageAccount
>>  -StorageAccountKey $storageKey.Value[0]

PS C:\> New-AzStorageShare
>>  -Name $shareName
>>  -Context $context
```

#### Connect to and mount an Azure File Share 
`New-PSDrive` maps the drive
```powershell
PS C:\> $storageKey = (Get-AzStorageAccountKey -ResourceGroupName $rgName -Name $storageNAme).Value[0]
PS C:\> $acctKey = ConvertTo-SecureString -String $storageKey -AsPlainText -Force
PS C:\> $credential = New-Object System.Management.Automation.PSCredential `
>>  -ArgumentList "Azure\$storageName", $acctKey
PS C:\> New-PSDrive `
>>  -Name "Z" `
>>  -PSProvider FileSystem `
>>  -Root "\\$storageName.file.core.windows.net\$shareName" 
>>  -Credential $credential
```

#### Retrieve the definition of a role (PowerShell)
> AZ-103: 1.4b.1 p. 88
```powershell
Get-AzRoleDefinition `
 -Name "Virtual Machine Contributor" |
ConvertTo-Json
```

#### Retrieve operations that support `DataActions` and `NotDataActions` (PowerShell)
> AZ-103: 1.4b.3 p.90
```powershell
Get-AzProviderOperation * | ? { $_.IsDataAction -eq $true }
```

#### List roles available for assignment (PowerShell)
> AZ-103: 1.4c.3 p. 96
```powershell
Get-AzRoleDefinition | Where-Object { $_.IsCustom -eq $true }
```

#### Grant a user RBAC rights (PowerShell)
> AZ-103: 1.4c.6 p. 96
```powershell
New-AzRoleAssignment `
 -SignInName cloudadmin@opsgility.onmicrosoft.com `
 -RoleDefinitionName "Virtual Machine Contributor" `
 -ResourceGroupName ExamRefRG
```

#### Grant a group RBAC rights (PowerShell)
> AZ-103: 1.4c.8 p. 97
```powershell
$group = Get-AzADGroup `
 -SearchString "Cloud Admins"
New-AzRoleAssignment `
 -ObjectId $group.Id `
 -RoleDefinitionName "Virtual Machine Contributor" `
 -ResourceGroupName ExamRefRG
```
#### 1.4c.10: Remove RBAC assignments from a user (PowerShell)
> AZ-103: 1.4c.10 p. 97
```powershell
Remove-AzRoleAssignment `
 -SignInName cloudadmin@opsgility.onmicrosoft.com
 -RoleDefinitionName "Virtual Machine Contributor" `
 -ResourceGroupName ExamRefRG
```
#### 1.4c.11: Remove RBAC assignments from a group (PowerShell)
> AZ-103: 1.4c.11 p. 97
```powershell
$group = Get-AzADGRoup -SearchString "Cloud Admins"
Remove-AzRoleAssignment `
 -ObjectId $group.Id `
 -RoleDefinitionName "Virtual Machine Contributor"
 -ResourceGroupName ExamRefRG
```

## Sources
  - "Enable-PSRemoting". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/enable-psremoting?view=powershell-6)
  - "Azure Az Module for Windows PowerShell, Core, and Cloud Shell Replaces Azure RM". [Petri](https://www.petri.com/azure-az-module-for-windows-powershell-core-and-cloud-shell-replaces-azurerm): 2019/01/23.
  - "Manage Azure IaaS virtual machines with Windows Admin Center". [Microsoft Docs](https://docs.microsoft.com/en-us/windows-server/manage/windows-admin-center/azure/manage-azure-vms): 2018/09/06.
  - "PowerShell Basics: Filtering Objects". [ITPro Today](https://www.itprotoday.com/powershell/powershell-basics-filtering-objects): 2013/07/25.
  - "Connect to Azure VM using PowerShell". [4sysops](https://4sysops.com/archives/connect-to-azure-vm-using-powershell/): 2018/10/11.
  - "About PSSessions". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_pssessions?view=powershell-6): 2019/07/02.
  - "Enable PowerShell Remoting". [4sysops](https://4sysops.com/wiki/enable-powershell-remoting/).
  - "Start-AzureRmVM". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/azurerm.compute/start-azurermvm?view=azurermps-6.13.0).
  - "Invoke-AzureRmVMRunCommand". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/AzureRm.Compute/Invoke-AzureRmVMRunCommand?view=azurermps-6.13.0).
  - "PowerShell Remoting over SSH". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/scripting/learn/remoting/ssh-remoting-in-powershell-core?view=powershell-6): 2018/08/13.
  - "Installation of OpenSSH for Windows Server 2019 and Windows 10". [Microsoft Docs](https://docs.microsoft.com/en-us/windows-server/administration/openssh/openssh_install_firstuse): 2019/01/06.
  - "New-AzVM". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/az.compute/new-azvm?view=azps-2.4.0).
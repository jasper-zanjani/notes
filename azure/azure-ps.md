# PowerShell commands for Azure
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
> `New-AzResourceGroup` required parameters: 
> 1. `Name` 
> 2. `Location`

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
Sku: `2016-Datacenter-Server-Core`\
Size: `Standard_B1ls` (1 core, 512 MB RAM, 1 TB disk size)
```powershell
$vm = New-AzVMConfig -VMName Spike -VMSize Standard_B1ls
$vm = Set-AzVMOperatingSystem $vm -Windows -ComputerName SpikeSpiegel -Crednetial $aztestadmin
$vm = Add-AzVMNetworkInterface
```
`Set-AzVMOperatingSystem` options:\
  1. `VM` Local virtual machine object on which to set OS properties
  2. `Linux` Indicates that the OS is Linux
  3. `Windows` Indicates OS type is Windows
  4. `ComputerName` Name of the computer
  5. `Credential`                     
  6. `CustomData` Optional
  7. `DisablePasswordAuthentication`  Optional
  8. `ProvisionVMAgent` Optional
  9. `EnableAutoUpdate` Optional
  10. `TimeZone` Optional
  11. `WinRMHttp` Optional: indicates that the system uses HTTP WinRM
  12. `WinRMHttps` Indicates that the system uses HTTPS WinRM
  13. `WinRMCertificateUrl` Use of WinRM certificate, stored in a Key Vault
<hr>

#### Create an Azure VM
`New-AzVM` options
  1. `ResourceGroupName` 
  2. `Location` 
  3. `VM` required
  4. `Zone`
  - `Image` optional named parameter can be used to define other operating systems, and requires friendly image names. Its default value is `Win2016Datacenter`. If a Linux image is provided, you should provide the `-Linux` switch parameter as well in order to specify a Linux-type disk file.
```powershell
New-AzVM -ResourceGroupName "RG" -Name "VM" -Location "EastUS" -Size "Standard-B2s" -Credential (Get-Credential)
New-AzVM Greeks Socrates $vm
```

#### Find a Marketplace image
`Get-AzVMImagePublisher` produces the publisher, e.g. "MicrosoftWindowsServer"
  - `Location` required
`Get-AzVMImageOffer` produces the offer, e.g. "WindowsServer"
  - `Location` required
  - `PublisherName` required (refer to `Get-AzVMImagePublisher`)
`Get-AzVMImageSku` produces the SKU, e.g.  "2016-Datacenter-Server-Core"
  - `Location` and `PublisherName` required
  - `Offer` required (refer to `Get-AzVMImageOffer`)
`Get-AzVMImage` requires the following named parameters:
  - `-Location`, `PublisherName`, and `-Offer` required
  - `-Skus` required (refer to `Get-AzVMImageSku`)
  - `-Version` providing `*` will produce a list of available versions

#### Start a VM
`Start-AzVM` required parameters:
  - `Id` or `-ResourceGroupName`
  - `Name`
```powershell
Start-AzVM Greeks Socrates
```

#### Shut down a VM
```powershell
Stop-AzVM Greeks Socrates
```

#### Connect to VM from a Windows machine
```powershell
# Azure can enable PowerShell on the target machine
Invoke-AzVMRunCommand -CommandId EnableRemotePS
```
```powershell
# WinRM can be enabled from a local command
Enable-PSRemoting
```
```cmd
@ Using the command-prompt
winrm quickconfig
```
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
Alternatively, using the command-prompt:
```cmd
netsh advfirewall firewall add rule name=WinRMHTTP dir=in action=allow protocol=TCP localport=5985
netsh advfirewall firewall add rule name=WinRMHTTPS dir=in action=allow protocol=TCP localport=5986
```
5.  Connect to the VM's public IP, passing along a previously-stored credential:
```powershell
$cred=Get-Credential
Enter-PSSession -ComputerName 123.47.78.90 -Credential $cred
# Alternatively...
etsn 123.45.67.89 -Credential (Get-Credential)
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
```powershell
# Open inbound ports are most easily defined at the time of VM creation 
New-AzVM ... -OpenPorts 5985,5986 ...
```
From __Azure Portal__: Virtual machines > VM to be modified > (Settings) Networking > Network interface > Add inbound port rule button \
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
## Sources
  - Michael Washam, Jonathan Tuliani, and Scott Hoag. _Exam Ref AZ-103 Microsoft Azure Administrator_. [AZ-103](../sources/az-103.md)
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
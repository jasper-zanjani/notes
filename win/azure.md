# Microsoft Azure

## Role assignments and classic administrators

Manage access to Azure resources using __role-based access control (RBAC)__. __Service Administrator__ and __Co-Administrator__ are legacy roles used with the classic deployment model.


## PowerShell

#### Install the Azure Resource Manager PowerShell module
The older module __AzureRM__ has been replaced, largely, by __Az__. Commands to the older module are aliased to the new, but there are some commands which require the older module.
```powershell
Install-Module -Name Az -AllowClobber
Install-Module AzureRM
```

#### Connect to Azure authenticated account
This command will produce an alphanumeric code that you must enter on [Microsoft's website](https://microsoft.com/devicelogin) to authenticate

```powershell
Connect-AzAccount
```

#### Create a Resource Group
`New-AzResourceGroup` has two required parameters
  - `-Name` which can be defined positionally at position __0__
  - `-Location`, the geographic area ("EastUS", "CentralUS", etc), defined positionally at position __1__

#### Create a VM
Where `$cred` was set with the username and password needed for the admin account:
```powershell
$cred = Get-Credential
```

```powershell
New-AzVM                                                              `
  -ResourceGroupName    "RG"                                          `
  -Name                 "VM"                                          `
  -Location             "EastUS"                                      `
  -VirtualNetworkName   "VN"                                          `
  -SubnetName           "SN"                                          `
  -SecurityGroupName    "SG"                                          `
  -PublicIpAddressName  "IP"                                          `
  -Credential           $cred
```

#### Connecting to a VM via PowerShell
1. WinRM access must be enabled on the target VM as well as the local machine.
```powershell
winrm quickconfig
```

2. Enable PowerShell remoting
```powershell
Enable-PSRemoting
```

An alternative command is:
```powershell
winrm quickconfig
```

3. Ensure WinRM is able to enter via ports 5985 and 5986 (rf. __Create an inbound security rule...__ below)

4. Add the VM's public IP address &lt;$ipaddr&gt; to the trusted hosts of the local machine (must be run as administrator):
```powershell
Set-Item WSMan:\localhost\Client\TrustedHosts -Value $ipaddr
```

5. Open the WinRM ports in the VM's firewall, if Windows Firewall is activated. The commands provided here can be run locally on the VM, or invoked through Azure:

```powershell
netsh advfirewall firewall add rule name=WinRMHTTP dir=in action=allow protocol=TCP localport=5985
netsh advfirewall firewall add rule name=WinRMHTTPS dir=in action=allow protocol=TCP localport=5986
```

6. Store the login credential in a variable. In Windows PowerShell this will bring up a dialog box in which you enter the username and password that will be passed to the VM. In PowerShell Core, the terminal itself will prompt for username and password.

```powershell
$cred = Get-Credential
```

7. Connect to the VM's public IP, passing along the credential

```powershell
Enter-PSSession -ComputerName 123.47.78.90 -Credential $cred
```


#### Create an inbound security rule, opening a port for inbound WinRM connections
An __inbound security rule__ can be created in the Cloud Shell using PowerShell:
```powershell
Get-AzNetworkSecurityGroup
  -Name NSG
  -ResourceGroupName 4SysOps
  | Add-AzNetworkSecurityRuleConfig
    -Name AllowingWinRMHTTP
    -Description "To Enable PowerShell Remote Access"
    -Access Allow 
    -Protocol Tcp 
    -Direction Inbound 
    -Priority 103 
    -SourceAddressPrefix Internet 
    -SourcePortRange * 
    -DestinationAddressPrefix * 
    -DestinationPortRange 5985 
    | Set-AzNetworkSecurityGroup
```

From __Azure Portal__:

Context                           | Action  | Effect
:---                              | :---    | :---
Azure Portal                      | Select __Virtual machines__ blade | Enter __Virtual machines__ page
Virtual machines page             | Select VM to be modified | Enter __Virtual machine__ page
Virtual machine page              | Select _Settings_ > __Networking__  | Open __Network Interface__ page
Network interface page            | Click __Add inbound port rule__ button | Open __Add inbound security rule__ modal dialog box
Add inbound security rule dialog  | Click __Basic__ button at top of dialog, switching to basic mode. Enter "5985" into __Port ranges__ field | 

Create another, similar rule for HTTPS traffic to port 5986

## Sources
  - "Enable-PSRemoting". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/enable-psremoting?view=powershell-6)
  - "Azure Az Module for Windows PowerShell, Core, and Cloud Shell Replaces Azure RM". [Petri](https://www.petri.com/azure-az-module-for-windows-powershell-core-and-cloud-shell-replaces-azurerm): 2019/01/23.
  - "Manage Azure IaaS virtual machines with Windows Admin Center". [Microsoft Docs](https://docs.microsoft.com/en-us/windows-server/manage/windows-admin-center/azure/manage-azure-vms): 2018/09/06.
  - "PowerShell Basics: Filtering Objects". [ITPro Today](https://www.itprotoday.com/powershell/powershell-basics-filtering-objects): 2013/07/25.
  - "PowerShell equivalents for common Linux/bash commands". [TheShellNut](https://mathieubuisson.github.io/powershell-linux-bash/): 2015/09/30.
  - "Connect to Azure VM using PowerShell". [4sysops](https://4sysops.com/archives/connect-to-azure-vm-using-powershell/): 2018/10/11.
  - "About PSSessions". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_pssessions?view=powershell-6): 2019/07/02.
  - "Enable PowerShell Remoting". [4sysops](https://4sysops.com/wiki/enable-powershell-remoting/).

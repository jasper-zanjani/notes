# Microsoft Azure
## Tasks
#### Create a virtual network with a subnet
```powershell
# Create a subnet first, to pass to the VNet upon creation
$subnet = New-AzVirtualNetworkSubnetConfig -Name "subnet1" -AddressPrefix "10.0.0.0/24"
$vnet = New-AzVirtualNetwork -Name "vnet" -ResourceGroupName "RG" -Location "East US" -AddressPrefix "10.0.0.0/16" -Subnet $subnet
```
#### Create an Azure VM
```powershell
New-AzVM -ResourceGroupName "RG" -Name "VM" -Location "EastUS" -Size "Standard-B2s" -Credential (Get-Credential)
New-AzVM Greeks Socrates $vm
```
#### Provision a Windows Server Core VM
```powershell
# Create a VNet with a subnet
$subnet = New-AzVirtualNetworkSubnetConfig -Name "subnet1" -AddressPrefix "10.0.0.0/24"
$vnet = New-AzVirtualNetwork -Name "vnet" -ResourceGroupName "RG" -Location "East US" -AddressPrefix "10.0.0.0/16" -Subnet $subnet

# Create a Public IP Address 
$ip = New-AzPublicIpAddress -Name "wscore-ip" -ResourceGroupName "RG" -Location "East US" -AllocationMethod Dynamic

# Create a Network Interface from the IP and VNet
$nic = New-AzNetworkInterface -Name "wscore-nic" -ResourceGroupName "RG" -Location "East US" -SubnetId $vnet.Subnets[0].Id -PublicIpAddressId $pip.Id
```
```powershell
# Provision the actual VM
$vm = New-AzVMConfig -VMName "Socrates" -VMSize "Standard_B1ls"       # 1 core, 512 MB RAM, 1 TB disk size
Set-AzVMOperatingSystem -VM $vm -Windows -ComputerName Socrates -Credential $aztestadmin
Set-AzVMSourceImage -PublisherName "MicrosoftWindowsServer" -Offer "WindowsServer" -Skus "2016-Datacenter-Server-Core" -Version 2016.127.20190603 -VM $vm
Set-AzVMOSDisk -CreatOption fromImage -VM $vm
Add-AzVMNetworkInterface -NetworkInterface $nic -VM $vm
New-AzVM -VM $vm -Location "East US" -ResourceGroupName "RG" -OpenPorts 5985,5986
```
#### Find a Marketplace image
```powershell
# Produce the publisher (e.g. "MicrosoftWindowsServer") from Location
Get-AzVMImagePublisher

# Produce the offer (e.g. "WindowsServer") from Location and PublisherName
Get-AzVMImageOffer

# Produce the Sku from Location and PublisherName and Offer
Get-AzVMImageSku 

# Requires PublisherName, Offer, Location, Skus, and Version (`-Version *` will produce a list of available version numbers)
Get-AzVMImage 
```
#### Start a VM
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
#### Invoking a command on a VM
`Invoke-AzVMRunCommand` requires only a single option: `-CommandId`. You can pass along a script containing predefined commands using the named parameter `-ScriptPath`, but the value for `-CommandId` must be `RunPowerShellScript`. Unlike `Invoke-Command, there is no way to define commands inline.
```powershell
Invoke-AzVMRunCommand -ResourceGroupName RG -VMName VM -CommandId 'RunPowerShellScript' -ScriptPath C:\injectedscript.ps1
```
#### Modify Network Security Group policies
```powershell
# Open inbound ports are most easily defined at the time of VM creation 
New-AzVM -VM $vm -Location "East US" -ResourceGroupName "RG" -OpenPorts 5985,5986
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
#### Ensure App Services, backup vault, and event hub have access to a storage account
```powershell
Get-AzVirtualNetwork -ResourceGroupName RG01 -Name VNET01 |
Set-AzVirtualNetworkSubnetConfig -NAme VSUBNET01 -AddressPrefix 10.0.0.0/24 -ServiceEndpoint Microsoft.Storage |
Set-AzVirtualNetwork

$subnet = Get-AzVirtualNetwork -ResourceGroupName RG01 -Name VNET01 |
Get-AzVirtualNetworkSubnetConfig -Name VSUBNET01
Add-AzStorageAccountNetworkRule -ResourceGroupName VNET01 -Name Storage01 -VirtualNetworkResourceId $subnet.Id
Update-AzStorageAccountNetworkRuleSet -ResourceGroupName RG01 -Name STORAGE01 -Bypass Azure.Services
```
#### Configure a VM for backup
```powershell
$t = Get-AzRecoveryServicesVault -Name t1
Set-AzRecoveryServicesBackupProperties -Vault $t -BackupStorageRedundancy GeoRedundant 
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
## Moving resources
- App Service SSL certificates need to be deleted from each App Service before moving it to a new resource group.
- VNet peering has to be disabled before moving a VNet, and a VNet can **only** be moved within the same subscription.
## Storage
#### CDN
There are 4 products available within Azure CDN:
  1. Azure CDN Standard from Microsoft, which does not offer dynamic site acceleration (DSA) (cf. Azure Front Door Service)
  2. Azure CDN Standard from Akamai
  3. Azure CDN Standard from Verizon
  4. Azure CDN Premium from Verizon, for which caching is configured using a rules engine.
#### Import/Export service
Import/Export service allows the physical shipment of disks to Azure for import.
1. Procure 2.5-inch SATA or 3.5-inch HDD disks.
2. Install **Azure Import/Export tool** on the disks. This requires a Windows computer with .NET Framework and BitLocker. There are two versions: Version 1 is recommended for **blob storage**, and Version 2 is recommended for **Files storage**.
3. Prepare drives using the tool. The first session requires several parameters, including **destination storage account key**, **BitLocker key**, and log directory.
4. Create an import job through Azure portal.. This requires a Windows computer with .NET Framework and BitLocker.
#### File Sync
Azure File Sync communicates over TCP 443 over SSL, and **not** IPSec.
**Cloud tiering** is an optional feature inw hich frequently accsesed files are cached locally while all other files are **tiered** to Azure Files based on policy.\
File Sync terminology:
  - **Storage Sync Service** top-level Azure resource for Azure File Sync
  - **Sync group** defines sync topology for a set of files
## Backup
Azure Backup can backup both Azure VMs and on-premises Windows machines

Types of backup agents that can be used with **Azure Backup**
  - Microsoft Azure Recovery Services (MARS) agent
  - DPM protection agent
  - VMSnapshot extension
## Web Apps
__Web Apps__ represent Azure's __PaaS__ product. It is part of the __App Service__ family, which include:
- Mobile Apps
- API Apps
- Logic Apps\
Each App Service resource is associated with a __service plan__, which defines the amount of resources available.\
Service plan tiers:
- **Free/Shared**: uses a shared infrastructure with minimal storage. No options for deploying different staged versions, routing of traffic, or backups
- **Basic**: Dedicated compute for app, including avaiilability of SSL and manual scaling of app instance number.
- **Standard**: Daily backups, automatic scaling of app instances, deployment slots, and user routing with Traffic Manager
- **Premium**: more frequent backups, increased storage, and greater number of deployment slots and instance scaling options.
## Role assignments and classic administrators
  __Service Administrator__ and __Co-Administrator__ are legacy roles used with the classic deployment model.
Azure methods of administering access to resources can be divided into two groups
  1. __Classic__ subscription administration roles 
    - Account Administrator
    - Service Administrator
    - Co-Administrator
  2. __Role-Based Access Controls (RBAC)__: There are more than __70__ built-in RBAC roles, allowing fine-grained access management, but __4__ of them are foundational:
    1. __Owner__ has full access to all resources and __can__ delegate access. Service Administrator and Co-Administrators are assigned this role at the subscription scope.
    2. __Contributor__ can create and manage all resources, but __cannot__ delegate access.
    3. __Reader__ can view resources.
    4. __User Access Administrator__ only manages user access to resources.\
Classic subscription administrators have full access to a subcription. They can access resources through Azure Portal, ARM APIs (PowerShell and CLI), and classic deployment model APIs. By default, the account that is used to sign up for a subscription is automatically set as both __Account Administrator__ and __Service Administrator__. There can only be one Account Administrator per account and only 1 Service Administrator per subscription. __Co-Administrators__ have the same access as Service Administrators, and there can be 200 of them per subscription, but cannot change the association of subscriptions to directories.\
Current assignments for classic admins can be seen in the __Properties blade__ of a subscription in Azure Portal. Co-Administrator assignments can be added by opening the __Access Control (IAM)__ blade of a subscription, then clicking the __Add co-administrator__ button.\
RBAC roles are supported only by Azure Portal and the ARM APIs. Access is applied to a __scope__, which includes subscriptions, resource groups, or resources. Azure Policy can be applied at various __scopes__. For example, a policy applied to a subscription is said to be at the "subscription scope". Policy can also be applied to Management Groups, which is an additional scope above subscription. In this way, several subscriptions can inherit a single policy through a Management Group.\
There is a built-in role named __Resource Policy Contributor__, which includes access to most Policy operations and should be considered privileged.\
RBAC roles can be used to grant rights to 2 types of principals:
  1. __User principal__: identity associated with a user or group of users.
  2. __Service principal__: identity associated with an application.\
RBAC roles can also be applied to a subscription through __Management Groups__, which represent the recommended practice for ensuring consistent application of tenant-wide security. Management groups form a hierarchy where each child inherits policy from its single parent while having additional controls. There is a single Management Group at the root of the hierarchy, associated with the Azure AD tenant (which is associated, in turn, with a subscription) that cannot be moved or deleted. 
## Logs
## Alerts
Alerts can have 3 states:
- **New** and not reviewed
- **Acknowledged** issue is being actioned by an admin
- **Closed** issue that generated the alerts has been resolved and the alert has been marked as closed
## VMs
VMs represent Azure's __IaaS__ product.
### Backups
Backups are integrated into Portal and clickable from the VM blade. You have to specify a **Recovery Services vault** and a **Backup policy**. The policy can specify frequency of backups, and other settings.\
Using Backup service costs $10 per VM plus the cost of used storage.\
Enable multi-factor authentication for the Recovery services vault by going to the vault in the Portal, then **Properties** > **Security settings: Update** > Choose **Yes** in the dropdown. An option to generate a security PIN will appear in this same blade.
### Operating system images
VM images are captured from an existing VM that has been prepared (or "generalized"). This removes unique settings (hostname, security IDs, personal information, user accounts, domain join information, etc) but not customizations (software installations, patches, additional files, folders).\
2 methods of generalizing a VM:
  1. **sysprep.exe**
  2. **Microsoft Azure Linux Agent (waagent)**\
2 types of VM image types
  1. **Managed** images (recommended), which remove the dependency of the VM to the image, at least within the same region. Copying a VM to another region still requires the managed image to be copied first.
  2. **Unmanaged** images, which required the VM to be created in the same storage account as that of the image. VM copies required the image to be copies first.
### Availability sets and zones
**Availability zones** protect from datacenter-level failures by providing physical and logical separation between VM instances. Zones have independent power sources, network, and cooling, and there are at least 3 zones in every region.\
**Availability sets** offer redundancy for VMs in the same application tier, ensuring at least one VM is available in the case of a host update or problem. Each VM is assigned a **fault domain** (representing separate physical racks in the datacenter) and an **update domain** (representing groups of VMs and underlying physical hardware that can be rebooted at the same time for host updates). Every availability set has up to 20 update domains and 3 fault domains available.\
A VM joined to an availability zone **may not** be also joined to an **availability set**.
### Scale sets
**VM scale sets (VMSS)** support the ability to dynamically add and remove instances. By default, a VMSS supports up to 100 instances or up to 1000 instances if deployed with the property `singlePlacementGroup` set to false (called a **large-scale set**). A **placement group** is a concept similar to an availability set in that it assigns fault and upgrade domains. By default, a scale set consists of only a single placement group, but disabling this setting allows the scale set to be composed of multiple placement groups. If a custom image is used instead of one in the gallery, the limit is actually 300 instances.
### Load balancers
Load balancers redistribute traffic from a frontend pool to a backend pool using rules. **Health probes** determine the health of the VMs in the backend pool: if they don't respond then new connections won't be sent. By default, Azure Load Balancer stores rules in a 5-tuple:
  1. Source IP address
  2. Source port
  3. Destination IP address
  4. Destination ports
  5. IP Protocol number\
Azure Load Balancers come in 2 pricing tiers:
  1. **Basic** which is free
  2. **Standard** which is charged based on the number of rules and the data that is processed.
### Dedicated hosts
A **host group** has to be created and placed in a resource group and associated with a location and availability zone and assigned a fault domain. A host then has to be created, a size specified, and associated with a host group. Any VM intended to run on the host has to be created in the same location and availability zone and associated with the host in the **Advanced** tab. [[8](#sources)]
## VNets
**Virtual Networks** (VNets) created through Portal require at least one subnet.
### Network security groups
NSGs are assicated with **network interfaces** and contain an arbitrary numberof **security rules**.\
**Service tags** represent a group of IP address prefixes managed by Microsoft available for use in NSG rules:
  - **`VirtualNetwork`**: all CIDR ranges defined for the virtual network, all connected on-premises address spaces, peered VNets or VNets connected to a VNET gateway
  - **`AzureLoadBalancer`**: Virtual IP address of the host where Azure's health probes originate
  - **`Internet`**: IP address space that is outside the virtual network
  - **`AzureCloud*`**: IP address space for Azure, including all datacenter public IP addresses
  - **`AzureTrafficManager*`**: IP address space for the Azure Traffic Manager probe IP addresses
  - **`Storage*`**:

Each rule has the following properties:
  - **Name**
  - **Priority**: number between 100 and 4096, lower numbers indicate a higher priority
  - **Source or destination**: IP address, CIDR block, service tag, or application security group
  - **Protocol**: `TCP`, `UDP`, `ICMP`, or `Any`
  - **Direction**: Inbound or outbound
  - **Port range**; 
  - **Action**: allow or deny
### Site to site VPN connections
Over IPSec
### Subnets
Subnet names are immutable and must be unique within each VNet, and their IP ranges must be described using CIDR notation. They can only be deleted if empty.\
Azure will reserve **5** IP addresses from each subnet IP range.
  - First and last IP addresses in each subnet are reserved for network identification and broadcast
  - An additional three addresses at the start (bottom) of the range are reserved. (This means the smallest possible subnet is `/29`, providing 3 addresses for use)
  - e.g. the first available IP address in range `192.168.1.0/24` is `192.168.1.4`
## Active Directory
In order to make sure AD users can change their password either locally or in the cloud, Azure AD has to be upgraded to **Premium**.
**Enterprise State Roaming** allows users to securely synchronize user settings and application settings to Azure.
## Azure blades
Blade                                   | Option                | Topics
:---                                    | :---                  | :---
Alerts                                  | New alert rule        | Create Alerts
                                        | Manage alert rules    | View existing alert rules
Import/Export Jobs                      |                       | Import and export data 
Log Analytics                           | Create                | Configure a new Log Analytics workspace
Metrics                                 | 
Monitor                                 | Alerts                | View alerts, Create Alerts, Manage Alert rules
                                        | Metrics               | View and create charts using metrics
Storage account                         | Firewalls and Virtual Networks |  Storage Firewall, allowing access to virtual networks
                                        | Access keys           | Access storage name and key
Subscription                            | Access Control (IAM)  | Assign subscription administrator permissions, including classic and RBAC roles
## Glossary
Term                                    | Definition  
:---                                    | :---        
append blob                             | blob type optimized for append operations, with no support for modification of existing blob contents, most commonly used for log files [[1](#sources): 130]
Archive                                 | blob storage access tier designed for long-term storage of infrequently-used data that can tolerate several hours of retrieval latency, remaining in the Archive tier for at least 180 days.
async blob copy service                 | server-side based service that can copy files you specify from a source location to a destination in an Azure Storage account [[1](#sources): 124]
availability set                        | feature that offers redundancy for VMs by assigning each instance a fault domain and update domain [[1](#sources): 193]
availability zone                       | feature that offers redundancy for VMs by providing physical and logical separation between VM instances, which will have independent power sources, network, and cooling. [[1](#sources): 191]
Azure Activity Log                      | subscription level log that captures events from operational data to service health events for a subscription [[1](#sources): 119]
Application Insights                    | service that can provide __application metrics__, if enabled and if the applications have been instrumented (now integrated into **Azure Monitor**) [[1](#sources): 44]
Azure Automation                        | allows you to build __runbooks__ that execute commands or scripts
Azure Backup                            | service that allows you to backup on-premises servers, cloud-based VMs, and virtualized workloads such as SQL Server and SharePoint to Microsoft Azure. [[1](#sources): 159]
Azure Backup Reports                    | provide data visualization from within Power BI from across Recovery Service vaults and Azure subscriptions to provide insight into backup activity [[1](#sources): 170]
Azure Backup Server                     | stand-alone service that is installed on a Windows Server operating system that stores backup data in a **Microsoft Azure Recovery Vault** [[1](#sources): 169, 271]
Azure Data Box                          | device that Microsoft will send to you that allows you to copy your data to it and then ship back to Microsoft for upload to Azure [[1](#sources): 129]
Azure Data Box Edge                     | edge device that can cache and process IoT data before uploading it to Azure [[F](#sources)]
Azure Dedicated Host                    | service that provides physical servers able to host Azure virtual machines dedicated to the customer [[8]]
Azure File Service                      | fully managed file share service that offers endpoints for __SMB__ (__CIFS__) protocol [[1](#sources): 147]
Azure File Sync                         | extends Azure File Service to allow on-premises file server to be extended to Azure [[1](#sources): 152]
Azure File Sync agent                   | software that needs to be deployed on every server to be added to an **Azure File Sync** group [[1](#sources): 152]
Azure Functions                         | 
Azure Import and Export service         | allows you to ship data into or out of an Azure Storage account by physically shipping disks to an Azure datacenter [[1](#sources): 129]
Azure Key Vault                         | helps safeguard cryptographic keys and secrets used by cloud applications and services [[1](#sources): 114]
Azure Log Analytics (OMS) agent)        | agent required to be installed on a machine for it to report telemetry to Azure Log Analytics (previously known as __Microsoft Monitoring Agent__, now integrated into **Azure Monitor**)
Azure Monitor                           | "single pane of glass" to manage __metrics__, __logs__, and **alerts** from multiple subscriptions
Azure Network Performance Monitor (NPM) | network monitorign solution that offers three main services and a dashboard giving an overview of network status [[1](#sources): 368]
Azure Policy                            | service that can create, assign, and manage policies to enforce governance.
Azure Resource Manager                  | service that manages and deploys resources in an Azure subscription, providing consistent capabilities and results across various such as the Portal, PowerShell, Azure CLI, REST APIs, and client SDKs ![Azure Resource Manager](https://docs.microsoft.com/en-us/azure/azure-resource-manager/media/resource-group-overview/consistent-management-layer.png)
Azure Storage Explorer                  | cross-platform application designed to help you quickly manage one or more Azure storage accounts that supports all storage services and CosmosDB and Azure Data Lake Storage services
BlobCache                               | multi-tier caching technology used on Azure VMs with SSDs; uses a combination of the RAM on the VM and local SSD [[1](#sources): 201]
blob storage                            | used for large-scale storage of arbitrary data objects, such as media files, log files, or other objects [[1](#sources): 129]
block blob                              | blob type optimized for efficient uploads and downloads for video, image, and other general-purpose storage [[1](#sources): 130]
bring your own key (BYOK)               | act of importing keys to Azure Key Vault [[1](#sources)]
Cloudyn                                 | service requiring separate registration that can track resource cost for Azure resources and resource usage for AWS and Azure. [[1](#sources): 60]
Connection Monitor                      | a **Network Watcher** feature that provides ongoing connection monitoring between a VM or App Gateway and another endpoint [[1](#sources): 385]
Connection Troubleshoot                 | a **Network Watcher** feature that allows you to test connectivity between a VM or App Gateway and another endpoint [[1](#sources): 384]
container                               | subdivision of a storage account, in which blobs are stored; similar in concept to a hard drive in that they provide a storage space in which blobs can be organized in a directory structure [[1](#sources): 129]
Cool                                    | blob storage access tier optimized for storing large amounts of data that is infrequently accessed and stored for at least 30 days
Dependency Agent                        | one of the two agents required by **Service Map** [[1](#sources): 349]
Desired State Configuration (DSC)       | a common Windows PowerShell extension for configuration management [[1](#sources): 259]
endpoint                                | file servers and paths within the file server you want the sync group to sync with each other [[1](#sources)]
Enterprise Agreement 
ExpressRoute Monitor                    | one of the three **Network Performance Monitor** services that monitors end-to-end connectivity between on-premises network and Azure over ExpressRoute connections [[1](#sources): 369]
forced tunneling                        | practice of overriding the default route sending 0.0.0.0/0-bound traffic to the Internet for the purpose of routing that traffic to an on-premises network security appliance [[1](#sources): 301]
Geographically-redundant storage (GRS)  | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies (typically within 15 minutes, but no SLA) to a second data center far away from the primary region
Hardware Security Modules (HSM)         | one of the ways keys in __Azure Key Vault__ can be protected [[1](#sources)]
Hot                                     | blob storage access tier optimized for the frequent access of objects in the storage account
IP Flow Verify                          | a **Network Watcher** tool that provides a quick and easy way to test if a given network flow will be allowed into or out of a VM [[1](#sources): 376]
key rolling                             | regenerate one access key by switching applications to a second one before regenerating the first [[1](#sources): 114]
Kusto                                   | query language comparable to SQL used by Log Analytics. Kusto queries use the pipe character to separate commands, always begin with a scope, are case-sensitive, and generate read-only requests so log entries are only deleted based on retention policy. [[1](#sources): 53]
large-scale set                         | a **scale set** spanning more than one **placement group** (allowing it to exceed 100 instances) [[1](#sources): 223]
Locally-redundant storage (LRS)         | Storage replication option that makes 3 local synchronous (within a single datacenter) copies 
Log Analytics                           | facilitates collection, correlation, search, and action on log and performance data, organized in __workspaces__ (now being called **Azure Monitor logs** [[1](#sources): 47-48]
Log Analytics workspace                 | where logs are collected and aggregated [[1](#sources): 48]
log                                     | numerical data or text [[1](#sources)]
Logic Apps
metrics                                 | numerical values output by resources and services within Azure [[1](#sources): 43]
Microsoft Azure Recovery Services (MARS) agent | stand-alone agent used to protect files and folders; one of the various backup agents that can be used with **Azure Backup** [[1](#sources): 162]
Microsoft Monitoring Agent (MMA)        | one of the two agents required by **Service Map** [[1](#sources): 349]
Network Security Group (NSG)            | allow you to control which network flows are permitted into and out of your virtual networks and virtual machines [[1](#sources): 338]
Network Topology                        | a **Network Watcher** view that provides a diagrammatic view of the resources in a virtual network as a quick and easy way to review network resources and manually check for misconfiguration [[1](#sources): 380]
Network Watcher                         | central hub for a wide range of network monitoring and diagnostic tools [[1](#sources): 375]
Next Hop                                | a **Network Watcher** view that provides a useful way to understand how a VM's outbound traffic is being directed [[1](#sources): 377]
Packet Captures                         | a **Network Watcher** tool that allows you to capture network packets entering or leaving VMs [[1](#sources): 378]
page blob                               | blob type optimized for random-access I/O, typically used to store VHD files when using unmanaged disks [[1](#sources): 130]
Performance Monitor                     | one of the three **Network Performance Monitor** services that monitors connectivity between various points in the network, both in Azure and on-premises; enables monitoring of packet loss and latency between endpoints [[1](#sources): 369]
placement group                         | construct containing a fault and upgrade domain, similar to **availability sets**, used in **scale sets** [[1](#sources): 222]
Read-access geographically redundant storage (RA-GRS) | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies to a second data center far away from the primary region, which has only read-only access
Recovery Services vault                 | the single resource that is provisioned for either **Azure Backup** or **Azure Site Recovery** [[1](#sources): 160]
Resource                                | single service instance, which can be a virtual machine, a virtual network, a storage account, or any other Azure service [[1](#sources): 62]
resource                                | manageable item that is available through Azure, including virtual machines, storage accounts, web apps, databases, and virtual networks [[1](#sources):|]
resource group                          | logical group of resources, container that holds related resources for an Azure solution [[1](#sources): 63, [D](#sources)]
Resource group template                 | JSON file that allows you to declaratively describe a set of resources [[1](#sources): 100]
resource provider                       | service that supplies Azure resources (e.g. `Microsoft.Compute`, `Microsoft.Insights`, `Microsoft.Storage`) [[1](#sources), [D](#sources)]
role                                    | definition of what action is allowed or denied to a **security principal** [[1](#sources): 85]
security principal                      | entities with access to Azure resources, i.e. users, groups, and service identities [[1](#sources): 85]
Service Connectivity Monitor            | one of the three **Network Performance Monitor** services that monitors outbound connectivity from nodes on the network to any external service with an open TCP port [[1](#sources): 369]
Service Map                             | Log Analytics solution that helps you document network flows from a running application and provides rich reporting of dependencies and network flows; installs two agents on each server: **Microsoft Monitoring Agent** and **Dependency Agent** [[1](#sources): 349]
Shared Access Signature (SAS) token     | query string parameter appended to the full URI of a storage resource [[1](#sources): 118]
soft delete                             | Storage account feature that allows you to save and recover data when blobs or blob snapshots are deleted even in the event of an overwrite [[1](#sources): 135]
VMSnapshot                              | extension automatically deployed by the Azure fabric controller to VMs while configuring backups through Azure Backup [[1](#sources): 270]
VMSnapshotLinux                         | extension automatically deployed by the Azure fabric controller to VMs while configuring backups through Azure Backup [[1](#sources): 270]
VPN Troubleshoot                        | a **Network Watcher** feature that provides automated diagnostics of Azure VPN gateways and connections [[1](#sources): 381]
Zone-redundant storage (ZRS)            | Storage replication option that makes 3 synchronous copies across multiple availability zones; available for general-purpose v2 storage accounts at **Standard** performance tier only.
## Sources
  1. Washam, Michael; Tuliani, Jonathan; Hoag, Scott. _Exam Ref AZ-103 Microsoft Azure Administrator_. [AZ-103](../sources/az-103.md)
  2. "Overview of alerts in Microsoft Azure". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-monitor/platform/alerts-overview). 2018/01/27
  3. "Azure Backup vs. Azure Site Recovery". [4sysops](https://4sysops.com/archives/azure-backup-vs-azure-site-recovery/): 2019/08/19.
  4. "Azure Resource Manager overview". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-resource-manager/resource-group-overview)
  5. "Azure Monitor terminology changes". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-monitor/terminology)
  6. "Azure Data Box Edge". [YouTube](https://youtu.be/5L8FcyQ1lCY).
  7. _Micorosft Azure Administrator - Exam Guide AZ-103_. Zaal, Sjoukje.
  8. "An introduction to Azure Dedicated Hosts". [YouTube](https://youtu.be/5qegfWl5woo): 2019/08/22.
  9. "Azure Backup". [YouTube](https://youtu.be/HJeCqbbT-5s): 2018/01/18.
  10. "Create, change, or delete a network security group". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/virtual-network/manage-network-security-group): 2018/04/04.
# Labs
[Install-WindowsFeature]: #install-windowsfeature '```&#10;Install-WindowsFeature&#10;```&#10;Installs one or more roles, role services, or features on either the local or a specified remote server that is running Windows Server 2012 R2.'
[Uninstall-AdcsCertificationAuthority]: #uninstall-adcscertificationauthority '```&#10;PS> Uninstall-AdcsCertificationAuthority&#10;```&#10;Uninstalls the CA role service and removes the configuration information.'
[Install-AdcsCertificationAuthority]: #install-adcscertificationauthority '```&#10;PS> Install-AdcsCertificationAuthority&#10;```&#10;Performs installation and configuration of the AD CS Certification Authority role service.'

[msdocs:Install-AdcsCertificationAuthority]: https://docs.microsoft.com/en-us/powershell/module/adcsdeployment/Install-AdcsCertificationAuthority "Install-AdcsCertificationAuthority documentation"
[msdocs:Install-AdcsEnrollmentWebService]: https://docs.microsoft.com/en-us/powershell/module/adcsdeployment/Install-AdcsEnrollmentWebService "Install-AdcsEnrollmentWebService documentation"
[msdocs:Install-WindowsFeature]: https://docs.microsoft.com/en-us/powershell/module/servermanager/Install-WindowsFeature "Install-WindowsFeature"


### Server Core
Configure VM
```powershell
Rename-VMSwitch Intel* External
New-VM PLABDMCORE02 1024 1 -SwitchName External -NewVHDPath 'D:\VHD\PLABDMCORE02\Virtual Hard Disks\PLABDMCORE02.vhdx' -NewVHDSize 127gb
Set-VMDvdDrive ... # Can't find way to pass through host drive Z:\ 
```
Add DVD drive Z: of host to VM's DVD drive (no Powershell equivalent found yet).
```powershell
Start-VM PLABDMCORE02
```
Install Windows, then continue configuring VM
```powershell
# PLABDMCORE02
Rename-Computer PLABDMCORE02
New-NetIpAddress 192.168.0.7 -PrefixLength 24 -InterfaceAlias Ethernet
Set-DnsClientServerAddress -InterfaceAlias Ethernet -ServerAddresses 192.168.0.1
Restart-Computer
```
Join computer to domain
```powershell
Add-Computer -DomainName practicelabs.com -DomainCredential practicelabs\administrator
Restart-Computer
```
Install packages remotely
```powershell
# PLABDC01
Enter-PSSession PLABDMCORE02
Add-WindowsFeature -Name dns,rsat-dns-server -IncludeManagementTools
```
Add PLABDMCORE02 as a DNS server while remotely connected to DC (no Powershell equivalent found yet).

Add a secondary lookup zone to PLABDMCORE02 (doesn't work; asks for Zonefile)
```powershell
Add-DnsServerSecondaryZone -Name practicelabs.com -MasterServers 192.168.0.1
```
### Nano Server
```powershell
# PLABDM01
Copy-Item Z:\NanoServer\NanoServerImageGenerator\*.ps* C:\nanoserver
Import-Module C:\nNanoserver\NanoServerImageGenerator.psm1
```
Create the VHD image
```powershell
New-NanoServerImage -Edition Standard -MediaPath z:\ -Basepath c:\nanoserver -Targetpath c:\nanoserver\PLABNANOSRV01.vhdx -DeploymentType Guest -ComputerName PLABNANOSRV01 -Storage -Package Microsoft-NanoServer-DNS-Package
Set-VMHardDiskDrive -VMName PLABNANOSRV01 -Path C:\nanoserver\PLABNANOSRV01.vhdx
```
### DISM
```powershell
# PLABSA01 
Set-Location C:\
mkdir updates,images,mount,drivers
Copy-Item \\plabdm01\Win10\sources\install.wim C:\updates
(Get-Item C:\updates\install.wim).IsReadOnly = $false
```
Move specified .msu installers to C:\updates and uncompress device driver to C:\drivers

Using Powershell:
```powershell
Mount-WindowsImage -Path C:\mount -ImagePath C:\images\install.wim -Index 1
Add-WindowsPackage -Path C:\mount -PackagePath C:\updates 
Add-WindowsDriver -Path C:\mount -Driver C:\drivers\display.driver\nv_dispi.inf
Save-WindowsImage -Path C:\mount 
Dismount-WindowsImage -Path C:\mount -Save
```
Using `dism.exe`:
```cmd
dism /mount-wim /wimfile:c:\images\install.wim /index:1 /mountdir:c:\mount
dism /image:c:\mount /add-package /packagepath:c:\updates
dism /image:c:\mount /add-driver /driver:c:\drivers\display.driver\nv_dispi.inf
dism /commit-wim /mountdir:c:\mount
dism /unmount-wim /commit /mountdir:c:\mount
```
### NLB lab
Configure a **Network Load Balancing** cluster. <sup>[Practice Lab][pl:70-740]</sup>

```powershell
# PLABDM01 and PLABSA01
Install-WindowsFeature web-server, web-webserver, web-mgmt-tools -IncludeManagementTools

# PLABDM01
New-NetIpAddress 192.168.0.20 -PrefixLength 24 -InterfaceAlias Ethernet1

# PLABSA01
New-NetIpAddress 192.168.0.40 -PrefixLength 24 -InterfaceAlias Ethernet1
Install-WindowsFeature -Name nlb -IncludeAllSubFeature -IncludeManagementTools
```
Using the **Network Load Balancing Manager**, create a new cluster named **PLAB-NLB1** specifying **multicast** operation mode at 192.168.0.25, and create an appropriate DNS record on **PLABDC01**.

Install NLB on **PLABDM01** and add it to the cluster through the NLB Manager.
Edit the image located at `C:\inetpub\wwwroot\iisstart.png` on either server.
Once saved, these edits will now be visible when that server's website is visited at its hostname.
Copy the contents of `C:\inetpub\wwwroot` to new directory `C:\nlbport` on **PLABDM01**.
Host that directory as a website on port 6789, opening the firewall appropriately.
```powershell
New-Website -Name nlbport -PhysicalPath "c:\nlbport" -Port 6789
New-NetFirewallRule -DisplayName NLBPort -Protocol TCP -LocalPort 6789
```
Returning to the NLB Manager, open Cluster Properties > Port Rules and remove the single defined port rule.
Add a new port rule that specifies port 80 for "multiple host" filtering mode, and another that specifies port 6789 for "single host" filtering mode.
Then from the host-specific port rule dialog box, select a handling priority of 10.
### iSCSI Storage
Network topology
```powershell
# PLABDC01
New-NetIpAddress 192.168.0.10 -PrefixLength 24 -InterfaceAlias Ethernet2

# PLABDM01
New-NetIpAddress 192.168.0.20 -PrefixLength 24 -InterfaceAlias Ethernet1
New-NetIpAddress 192.168.1.20 -PrefixLength 24 -InterfaceAlias Ethernet2
Set-DnsClientServerAddress -InterfaceAlias Ethernet1,Ethernet2 -ServerAddresses 192.168.0.1
```
iSCSI target
```powershell
# PLABDC01
Add-WindowsFeature fs-iscsitarget-server -IncludeManagementTools
New-iSCSIVirtualDisk -SizeBytes 5gb -Path 'C:\CorporateHD.vhdx'
New-iSCSIServerTarget -TargetName plabdc01 -InitiatorId @('ipaddress:192.168.0.20','ipaddress:192.168.1.20')
Add-iSCSIVirtualDiskTargetMapping -Path 'C:\CorporateHD.vhdx' -TargetName plabdc01
```
iSCSI initiator
```powershell
# PLABDM01
Start-Service msiscsi
Get-NetFirewallServiceFilter -Service msiscsi | Get-NetFirewallRule | Enable-NetFirewallRule
Connect-iSCSITarget -NodeAddress (Get-iSCSITarget).NodeAddress
```
Multipath
...
Finally, mount the drive
```powershell
New-Volume -DiskNumber 5 -FriendlyName iSCSI-Volume1 -FileSystem NTFS -DriveLetter R
```
### Data deduplication
```powershell
# PLABDM01
Add-WindowsFeature fs-data-deduplication -IncludeManagementTools
Get-DedupVolume
Get-DedupStatus
Enable-DedupVolume -Volume 'D:'
Set-DedupVolume -Volume 'D:' -ExcludeFolder 'D:\win81','D:\virtual machines' 
New-DedupSchedule $name -Days Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday -DurationHours 6 -Enabled $true -Type Optimization -Memory 50
Start-DedupJob D: -Type Optimization -Memory 50
```
### Failover cluster lab
Network topology
```powershell
# PLABDM01
New-NetIpAddress 192.168.0.20 -PrefixLength 24 -InterfaceAlias Ethernet1
New-NetIpAddress 192.168.0.21 -PrefixLength 24 -InterfaceAlias "vEthernet (Internal network 1)"
New-NetIpAddress 192.168.1.20 -PrefixLength 24 -InterfaceAlias Ethernet2
Set-DnsClientServerAddresses Ethernet1,Ethernet2 -ServerAddresses 192.168.0.1
Disable-NetAdapter "vEthernet (Internal network 1)"

# PLABSA01
New-NetIpAddress 192.168.0.40 -PrefixLength 24 -InterfaceAlias Ethernet1
New-NetIpAddress 192.168.0.41 -PrefixLength 24 -InterfaceAlias "vEthernet (Internal network 1)"
New-NetIpAddress 192.168.1.40 -PrefixLength 24 -InterfaceAlias Ethernet2
Set-DnsClientServerAddress Ethernet1,Ethernet2 -Serveraddresses 192.168.0.1
Disable-NetAdapter "vEthernet (Internal network 1)"
```
iSCSI target
```powershell
# PLABDC01
Add-WindowsFeature FS-iSCSITarget-Server -IncludeManagementTools
```
Then go into Server Manager > File and Storage Services > iSCSI and start the **New iSCSI Virtual Disk Wizard**.
Create a fixed 500 MB iSCSI virtual disk on C:\ named "QuorumHD" and assign it to the `PLABDC01` iSCSI target server.
Add `plabdm01.practicelabs.com` and `plabsa01.practicelabs.com` as initiators, and keep authentication disabled, and confirm the disk has been created.
Create another virtual disk, 30 GB dynamic on D:\ names "CSVHD", and assign it to the same `PLABDC01` iSCSI target server.
###### Configure iSCSI initiators to iSCSI Target Server
On **PLABDM01**, open Server Manager and click on Tools > **iSCSI Initiator** and connect to `plabdc01.practicelabs.com`.
Bring disks 5 and 6 online and initialize them with [MBR][MBR] partition style.
This can be done within `diskmgmt.msc`, where the shared volumes that have been created will appear beneath the local disks, or using PowerShell:
```powershell
# PLABDM01
New-Volume -DiskNumber 5 -DriveLetter Q -FileSystem NTFS -FriendlyName 'Quorum'
New-Volume -DiskNumber 6 -DriveLetter V -FileSystem NTFS -FriendlyName 'CSV'
```
Only bring the disks online on the other client
```powershell
# PLABSA01
Set-Disk -Number 4,5 -IsOffline $false
```
###### Install failover clusters
On both **PLABDM01** and **PLABSA01**:
```powershell
Install-WindowsFeature failover-clustering -IncludeManagementTools
```
Then validate the installation through the [**Failover Cluster Manager**](/img/image-m17-c-102.jpg) (cluadmin.msc).
Open the **Validate Configuration** wizard and enter `plabdm01.practicelabs.com` and `plabsa01.practicelabs.com` into the list of selected servers.

Open the **Create Cluster Wizard** and create cluster "PLHYPVCL01" using those same two nodes, choosing 192.168.**0**.25 and 192.168.**1**.25 for the administrative access points.

Open the [**Configure Cluster Quorum Wizard**](/img/image-m17-c-103.jpg) and configure a disk witness using the Quorum shared volume.

Open **Hyper-V Manager** (virtmgmt.msc) and move **PLABDC02** and **PLABWIN811** to `V:\PLABDC02` and `V:\PLABWIN811` respectively, specifying the VM's **storage**.
Confirm the move has taken place by inspecting each VM's hard drive in the settings.

Add the **Virtual Machine** role to the **Failover Cluster Manager**, and select **PLABDC02** and **PLABWIN811**.
This will create the "PLABWIN811" Role, which actually includes both selected VMs.
Open **PLABWIN811 Properties**, then the **Failover** tab, and select "Allow failback" specifying between 1 and 2 hours.

Open **Hyper-V Manager** and start **PLABDC02**.
Wait until it has booted completely, then return to **Failover Cluster Manager**, open Nodes, right-click on **PLABDM01** and then Stop Cluster Service.
This option forces a failover of the VM, which drains to **PLABSA01**.
This can be confirmed by returning to **PLABSA01** and opening **Hyper-V Manager**, where it is revealed that **PLABDC02** is running.
### Scale-Out Fileserver lab
Plan network topology
```powershell
# PLABDM01
New-NetIpAddress 192.168.0.20 -PrefixLength 24 -InterfaceAlias Ethernet1
New-NetIpAddress 192.168.1.20 -PrefixLength 24 -InterfaceAlias Ethernet2
Set-DnsClientServerAddress -InterfaceAlias Ethernet1,Ethernet2 -ServerAddresses 192.168.0.1
Disable-NetAdapter -InterfaceAlias 'vethernet (internal network 1)'
```
```powershell
# PLABSA01
New-NetIpAddress 192.168.0.40 -PrefixLength 24 -InterfaceAlias Ethernet1
New-NetIpAddress 192.168.1.40 -PrefixLength 24 -InterfaceAlias Ethernet2
Set-DnsClientServerAddress -InterfaceAlias Ethernet1,Ethernet2 -ServerAddresses 192.168.0.1
```
Configure iSCSI target
```powershell
# PLABDC01
Install-WindowsFeature fs-iscsitarget-server -IncludeManagementTools
New-IscsiVirtualDisk -Fixed -SizeBytes 500mb -Path 'C:\QuorumHD.vhdx'
New-IscsiVirtualDisk -SizeBytes 30gb -Path 'D:\CSVHD.vhdx'
New-IscsiServerTarget -TargetName PLABDC01 -InitiatorId @('iqn:iqn.1991-05.com.microsoft:plabsa01.practicelabs.com','iqn:iqn.1991-05.com.microsoft:plabdm01.practicelabs.com')
Add-IscsiVirtualDiskTargetMapping -Path 'C:\QuorumHD.vhdx' -TargetName plabdc01
Add-IscsiVirtualDiskTargetMapping -Path 'D:\CSVHD.vhdx' -TargetName plabdc01
```
Configure iSCSI initiator on both clients
```powershell
# PLABDM01 and PLABSA01
Start-Service msiscsi
Get-NetFirewallServiceFilter -Service msiscsi | Get-NetFirewallRule | Enable-NetFirewallRule
Connect-iSCSITarget -NodeAddress (Get-iSCSITarget).NodeAddress
```
Install Failover Clustering role on nodes of the cluster
```powershell
# PLABDM01 and PLABSA01
Install-WindowsFeature failover-clustering -IncludeManagementTools
```
Create a failover cluster through the GUI (the Powershell commands for cluster creation appear not to support adding multiple network networks)
```powershell
# PLABDM01
New-Cluster -Name PLABSCL01 -Node PLABDM01, PLABSA01 -StaticAddress 192.168.0.25 -IgnoreNetwork 192.168.1.0/24
Set-ClusterQuorum -DiskWitness 'Cluster Disk 1'
```
### Hyper-V storage lab
Create a VM with VHDX disks
```powershell
New-VM -Name PLABWIN102 -Generation 1 -MemoryStartupBytes 1536mb -SwitchName 'Private network 1' -NewVHDPath 'C:\Users\Public\Documents\Hyper-V\Virtual hard disks\PLABWIN102.vhdx' -NewVHDSizeBytes 127gb
Set-VMDvdDrive -VMName PLABWIN102 -Path C:\Users\Administrator.PRACTICELABS\Documents\Eval81.iso
New-VHD -Path 'D:\Virtual Machines\PLAB1.vhdx' -Dynamic -SizeBytes 127gb
Add-VMHardDiskDrive -VMName PLABWIN102 -ControllerType IDE -ControllerNumber 0 -Path 'D:\Virtual Machines\PLAB1.vhdx'
```
Add a differencing disk
```powershell
New-VHD -Path 'D:\Virtual Machines\PLAB2.vhdx' -Differencing -ParentPath 'C:\Users\Public\Documents\Hyper-V\Virtual hard disks\PLABWIN102.vhdx'
Add-VMHardDrive PLABWIN102 SCSI -Path 'D:\Virtual Machines\PLAB2.vhdx'
```
Add a passthrough disk
```powershell
Set-Disk -Number 1 -IsOffline $true
Add-VMHardDiskDrive PLABWIN102 IDE 1 -DiskNumber 1
```
Create a SAN
```powershell
New-VMSan -Name "PLABS-Fc"
Add-VMFibreChannelHBA -VMName PLABDC02 -SanName "PLABS-Fc"
```
### Hyper-V replica lab
Emphasizes [**`VMReplication`**](PowerShell#hyper-v) cmdlets.

```powershell
# PLABDM01
Enable-NetFirewallRule VIRT-HVRHTTPL-In-TCP-NoScope,VIRT-HVRHTTPSL-In-TCP-NoScope
```
Enable incoming replication on the receiving server
```powershell
#PLABSA01
Enable-NetFirewallRule VIRT-HVRHTTPL-In-TCP-NoScope,VIRT-HVRHTTPSL-In-TCP-NoScope
Set-Disk -Number 1,3,4 -IsOffline $false -IsReadOnly $false
New-Volume -DiskNumber 1 -FileSystem NTFS -FriendlyName VMReplica -DriveLetter E
Set-VmReplicationServer -ReplicationEnabled $true -AllowedAuthenticationType kerberos -ReplicationAllowedFromAnyServer $true -DefaultStorageLocation E:\VHD
```
Configure one VM and initiate initial replication
```powershell
# PLABDM01
Test-VMReplicationConnection PLABDC02 plabsa01.practicelabs.com 80 Kerberos
Enable-VMReplication PLABDC02 plabsa01.practicelabs.com 80 Kerberos
Start-VMInitialReplication PLABDC02
```
Repeat for another VM
```powershell
Enable-VMReplication PLABWIN811 plabsa01.practicelabs.com 80 Kerberos
Start-VMInitialReplication PLABWIN811
```
Initiate a planned failover
```powershell
Start-VMFailover PLABDC02
Start-VM PLABDC02
```
### WSUS lab
Almost totally GUI configuration of WSUS server after installation
```powershell
# PLABDM01
Add-WindowsFeature updateservices,updateservices-widdb,updateservices-services -IncludeManagementTools
mkdir C:\updates
'C:\Program Files\Update Services\Tools\wsusutil.exe' postinstall content_dir=C:\updates
```
### WSUS (Sec+)
```powershell
# PLABDM01
Set-Disk -Number 1 -IsOffline $false
Set-Disk -Number 1 -IsReadOnly $false
New-Volume -DiskNumber 1 -Filesystem NTFS - FriendlyName WSUS -DriveLetter E
Add-WindowsFeature updateservices,updateservices-widdb,updateservices-services -IncludeManagementTools
'C:\Program Files\Update Services\Tools\wsusutil.exe' postinstall content_dir=E:\updates
$wsus = Get-WsusServer
$config = $wsus.GetConfiguration()
```
Proxy
```powershell
$config.UseProxy = $true
$config.ProxyName = 'proxy'
$config.ProxyServerPort = 80
```
English language
```powershell
$config.AllUpdateLanguagesEnabled = $false
$config.SetEnabledUpdateLanguages('en')
$config.Save()
```
Upstream server is Microsoft Update
```powershell
Set-WsusServerSynchronization –SyncFromMU
```
Select products and classifications
```powershell
Get-WSUSProduct | Where-Object {$_.Product.Title -In ('Windows 10','Windows 8.1')} | Set-WSUSProduct
Get-WSUSClassification | Where-Object {$_.Classification.Title -eq 'Critical Updates'} | Set-WSUSClassification
```
Get WSUS Subscription and perform initial synchronization
```powershell
$sub = $wsus.GetSubscription()
$sub.StartSynchronization()
$sub.SynchronizeAutomatically = $false
```
### Storage replica lab
Actually from the [Practice test][mu:70-740].
```powershell
# On both origin and replica servers
Install-WindowsFeature storage-replica -Restart

Test-SRTopology
New-SRGroup -ComputerName server1
New-SRPartnership -SourceComputerName server1 -SourceRGName rg1 -SourceVolumeName D: -SourceLogVolumeName E: -DestinationComputerName server2 -DestinationRGName rg2 -DestinationVolumeName D: -DestinationLogVolumeName E:
```
### Certificates
- ADCSCertificationAuthority
[`Install`][Install-AdcsCertificationAuthority]<sup>[?][msdocs:Install-AdcsCertificationAuthority]</sup>
- ADCSWebEnrollment
[`Install`][Install-AdcsWebEnrollment]<sup>[?][msdocs:Install-AdcsWebEnrollment]</sup>
- WindowsFeature
[`Add`][Install-WindowsFeature]<sup>[?][msdocs:Install-WindowsFeature]</sup>

```powershell
Add-WindowsFeature -Name ADCS-Cert-Authority,ADCS-Web-Enrollment -IncludeManagementTools
Install-ADCSCertificationAuthority -CAType EnterpriseRootCA
Install-ADCSWebEnrollment
```
Make a duplicate of the "User" template named "SecureUser", with the following changes
- In the **Request Handling** tab, select "Prompt the user during enrollment"
- In the **Security** tab ensure that Authenticated Users has Autoenroll allowed
- In the **Superseded Templates** tab, select User
- In the **Subject Name** tab, clear checkboxes for "Include e-mail name in subject name" and "E-mail name"
```powershell
Add-CATemplate SecureUser
```
### Hyperconverged failover cluster
[MeasureUp][mu:70-740]
```powershell
New-Cluster -Name HC-CLU1 -Node node1, node2, node3, node4 -NoStorage
Enable-ClusterStorageSpacesDirect -CacheMode Disabled -AutoConfig:0 -SkipEligibilityChecks
New-StoragePool -StorageSubSystemFriendlyName *Cluster* -FriendlyName S2DPool -ProvisioningTyupeDefault Fixed -PhysicalDisk (Get-PhysicalDisk | Where-Object -Property CanPool -eq $true)
$pool = Get-StoragePool S2DPool
New-StorageTier -StoragePoolUniqueID ($pool).UniqueID -FriendlyName Performance -MediaType HDD -ResiliencySettingName Mirror
New-StorageTier -StoragePoolUniqueID ($pool).UniqueID -FriendlyName Capacity -MediaType HDD -ResiliencySettingName Parity
New-Volume -StoragePool $pool -FriendlyName SharedVol1 -FileSystem CSVFS_REFS -StorageTierFriendlyNames Performance, Capacity -StorageTierSizes 2gb, 10gb
```

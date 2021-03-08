## High availability

These high-availability options are mutually exclusive:

- **Availability zones** protect from datacenter-level failures by providing physical and logical separation between VM instances. Zones have independent power sources, network, and cooling, and there are at least 3 zones in every region.
- **Availability sets** offer redundancy for VMs in the same application tier, ensuring at least one VM is available in the case of a host update or problem. Each VM is assigned a **fault domain** (representing separate physical racks in the datacenter) and an **update domain** (representing groups of VMs and underlying physical hardware that can be rebooted at the same time for host updates). Availability sets have a maximum of 20 update domains and 3 fault domains. 

**VM scale sets (VMSS)** support the ability to dynamically add and remove instances. By default, a VMSS supports up to 100 instances or up to 1000 instances if deployed with the property `singlePlacementGroup` set to false (called a **large-scale set**). A **placement group** is a concept similar to an availability set in that it assigns fault and upgrade domains. By default, a scale set consists of only a single placement group, but disabling this setting allows the scale set to be composed of multiple placement groups. If a custom image is used instead of one in the gallery, the limit is actually 300 instances.

## Load balancers

Load balancers redistribute traffic from a frontend pool to a backend pool using rules. 
**Health probes** determine the health of the VMs in the backend pool: if they don't respond then new connections won't be sent. 
By default, Azure Load Balancer stores rules in a 5-tuple:

  1. Source IP address
  2. Source port
  3. Destination IP address
  4. Destination ports
  5. IP Protocol number

Azure Load Balancers come in 2 pricing tiers:

  1. **Basic** which is free
  2. **Standard** which is charged based on the number of rules and the data that is processed.

Both boot and **guest OS** diagnostics can be enabled [on](#enable-on-deployment) or [after](#enable-after-deployment) VM creation.

Azure VMs have built-in extensions that enable configuration management. 2 most common extensions for configuration management:

- Windows PowerShell **Desired State Configuration (DSC)** allows you to define the state of a VM using **PowerShell Desired State Configuration language** 

A VM may have more than one **Network Interface Card (NIC)**, but they must belong to the same region as the VM itself. All NICs on a VM must also be attached to the same VNet.

# Tasks

### Find Marketplace image

Produce the publisher (e.g. "MicrosoftWindowsServer") from Location
```powershell
Get-AzVMImagePublisher
```
Produce the offer (e.g. "WindowsServer") from Location and PublisherName
```powershell
Get-AzVMImageOffer
```
Produce the Sku from Location and PublisherName and Offer
```powershell
Get-AzVMImageSku 
```
Requires PublisherName, Offer, Location, Skus, and Version (`-Version *` will produce a list of available version numbers)
```powershell
Get-AzVMImage 
```

Deploy from image


=== "Azure PowerShell"

    Specify a managed image for use in a new virtual machine

    ```powershell
    $image = Get-AzImage -ImageName $imageName -ResourceGroupName $g
    $vmConfig = Set-AzVMSourceImage -VM $vmConfig -Id $image.Id
    ```

    Specify a legacy unmanaged image for use in a new virtual machine

    ```powershell
    $osDiskUri = "https://examrefstorage.blob.core.windows.net/vhd/os-disk"
    $imageUri = "https://examrefstorage.blob.core.windows.net/images/legacy-image.vhd"
    $vm = Set-AzVMOSDisk -VM $vm -Name $osDiskName -VhdUri $osDiskUri -CreateOption fromImage -SourceImageUri $imageUri -Windows
    ```
    

=== "Azure CLI"

    Specify a managed image for use in a new virtual machine

    ```sh
    az vm create -g $g -n $vmName --image $imageName
    ```

    Specify a legacy unmanaged image for use in a new virtual machine

    ```sh
    az vm create -g $g -n $vmName --image $osDiskUri --generate-ssh-keys
    ```
    

### Access


```powershell
Enable-PSRemoting
# If a network connection is Public, this command will not work
Enable-PSRemoting -SkipNetworkProfileCheck -Force
```
The remote computer must also have WinRM up and running. Azure can enable PowerShell on the target machine
```powershell
Invoke-AzVMRunCommand -AsJob -ResourceGroupName "RG" -VMName "Socrates" -CommandId EnableRemotePS
```
Using Azure Cloud PowerShell
```powershell
Enable-AzVMPSRemoting -Name Socrates -ResourceGroupName "RG"
```
Add the VM's public IP address `$IP` to the trusted hosts of the local workstation (must be run as administrator):
```powershell
Set-Item WSMan:\localhost\Client\TrustedHosts -Value $IP
```
Traffic to ports **5985** and **5986** must be allowed through [Windows firewall](#firewall) and, if the computer is an Azure VM, the Network Security Group.
```powershell
Enter-PSSession -ComputerName 123.47.78.90 -Credential $cred
etsn 123.45.67.89 -Credential (Get-Credential)
```

```powershell
Invoke-AzVMRunCommand -ResourceGroupName RG -VMName VM -CommandId 'RunPowerShellScript' -ScriptPath C:\injectedscript.ps1
```

Open firewall WinRM ports 5985 and 5986

=== "PowerShell"

    ```powershell
    New-NetFirewallRule -DisplayName "WinRMHTTP" -Direction Inbound -LocalPort 5985 -Protocol TCP -Action Allow
    New-NetFirewallRule -DisplayName "WinRMHTTPS" -Direction Inbound -LocalPort 5986 -Protocol TCP -Action Allow
    ```

=== "netsh"

    ```cmd
    netsh advfirewall firewall add rule name=WinRMHTTP dir=in action=allow protocol=TCP localport=5985
    netsh advfirewall firewall add rule name=WinRMHTTPS dir=in action=allow protocol=TCP localport=5986
    ```

### RDP

Saving the .rdp file for later use
```powershell
$g = "ExamRefRG"
$vmName = "ExamRefVM"
$Path = "C:\path\to\ExamRefVM.rdp"

Get-AzRemoteDesktopFile -ResourceGroupName $g -Name $vmName -LocalPath $path
```
### Backup
```powershell
$t = Get-AzRecoveryServicesVault -Name t1
Set-AzRecoveryServicesBackupProperties -Vault $t -BackupStorageRedundancy GeoRedundant 
```
### SSH
```powershell
$VirtualMachine = Get-AzVM -ResourceGroupName "ResourceGroup11" -Name "VirtualMachine07"
Add-AzVMSshPublicKey -VM $VirtualMachine -KeyData "MIIDszCCApugAwIBAgIJALBV9YJCF/tAMA0GCSq12Ib3DQEB21QUAMEUxCzAJBgNV" -Path "/home/admin/.ssh/authorized_keys"
```
Resize VM

=== "PowerShell"

    ```powershell
    $vm = Get-AzVM -ResourceGroupName $g -VMName $n
    $vm.HardwareProfile.VMSize = "Standard_DS2_V2"
    Update-AzVM -VM $vm -ResourceGroupName $g
    ```

=== "Azure CLI"

    ```sh
    az vm list-vm-resize-options --resource-group $g --name $vmName --output table
    az vm resize --resource-group $g --name $vmName --size Standard_DS3_v2
    ```

### Windows Server Core

=== "PowerShell"

    Simply:

    ```powershell
    New-AzVM -ResourceGroupName "RG" -Name "VM" -Location "EastUS" -Size "Standard-B2s" -Credential (Get-Credential)
    New-AzVM Greeks Socrates $vm
    ```

    The VM's NIC has to be linked to an **NSG**, a **Subnet**, and a **Public IP Address**.

    ```powershell
    # Create a VNet with a subnet
    $subnet = New-AzVirtualNetworkSubnetConfig -Name "subnet1" -AddressPrefix "10.0.0.0/24"
    $vnet = New-AzVirtualNetwork -Name "vnet" -ResourceGroupName "RG" -Location "East US" -AddressPrefix "10.0.0.0/16" -Subnet $subnet

    # Create a Network Interface from the IP and VNet
    $ip = New-AzPublicIpAddress -Name "wscore-ip" -ResourceGroupName "RG" -Location "East US" -AllocationMethod Dynamic
    $nic = New-AzNetworkInterface -Name "wscore-nic" -ResourceGroupName "RG" -Location "East US" -SubnetId $vnet.Subnets[0].Id -PublicIpAddressId $pip.Id -NetworkSecurityGroupId $nsg.Id
    ```

    ```powershell
    $vm = New-AzVMConfig -VMName "Socrates" -VMSize "Standard_B1s"
    Set-AzVMOperatingSystem -VM $vm -Windows -ComputerName Socrates -Credential $aztestadmin
    Set-AzVMSourceImage -VM $vm -PublisherName "MicrosoftWindowsServer" -Offer "WindowsServer" -Skus "2016-Datacenter-Server-Core" -Version 2016.127.20190603
    Set-AzVMOSDisk -VM $vm -CreateOption fromImage
    Add-AzVMNetworkInterface -VM $vm -NetworkInterface $nic

    # No `-Name`, since we set `-VMName` when initializing the PSVirtualMachine object with `New-AzVMConfig`
    New-AzVM -AsJob -VM $vm -Location "East US" -ResourceGroupName "RG" 
    ```

=== "Azure CLI"

    ```sh
    az vm create -n Socrates -g RG -l "East US" 
        --image "MicrosoftWindowsServer:WindowsServer:2016-Datacenter-Server-Core:2016.127.20190603" 
        --admin-username aztestadmin
        --admin-password $password
        --nics socrates-nic
    ```

Display status of VMs


=== "Azure CLI"

    ```sh
    az vm list --resource-group $RESOURCEGROUP --output table
    ```
    
Enable IIS using the **Custom Script Extension** to run a PowerShell script on the VM. 

=== "Azure CLI"

    ```sh
    az vm extension set --resource-group $RESOURCEGROUP --vm-name SimpleWinVM --name CustomScriptExtension --publisher Microsoft.Compute --version 1.9 --settings '{"fileUris":["https://raw.githubusercontent.com/MicrosoftDocs/mslearn-welcome-to-azure/master/configure-iis.ps1"]}' --protected-settings '{"commandToExecute": "powershell -ExecutionPolicy Unrestricted -File configure-iis.ps1"}'
    ```
    [Source](https://docs.microsoft.com/en-us/learn/modules/build-azure-vm-templates/5-add-a-resource?pivots=windows-cloud)
    

### Add NIC

=== "PowerShell"

    ```powershell
    Stop-AzVM -Name $vmName -ResourceGroupName $g
    Add-AzVMNetworkInterface -VM $vm -Id $nicId -Primary 
    Update-AzVm -ResourceGroupName $g -VM $vm
    ```

=== "Azure CLI"

    ```sh
    az network nic create --resource-group $g --name $nicName --vnet-name $ExamRefVNET --subnet $subnetName
    az vm nic add -g $g --vm-name $vmName --nics $nicName --primary-nic
    ```

Redeploy

=== "PowerShell"

    ```powershell
    Set-AzVM -Redeploy -ResourceGroupName ExamRefRG -Name ExamRefVM
    ```

=== "Azure CLI"

    ```sh
    az vm redeploy --resource-group ExamRefRG --name ExamRefVM
    ```

Create managed VM

=== "PowerShell"

    ```powershell
    Set-AzVM -ResourceGroupName  $g -Name $vmName -Generalized 
    $vm = Get-AzVM -ResourceGroupName $g -Name $vmName
    $image = New-AzImageConfig -Location $location -SourceVirtualMachineId $vm.ID 
    New-AzImage -Image $image -ImageName $imageName -ResourceGroupName $g
    ```

=== "Azure CLI"

    ```sh
    az vm deallocate --resource-group $g --name $vmName
    az vm generalize --resource-group $g --name $vmName
    az image create --resource-group $g --name $imageName --source $vmName 
    ```


### Create
```powershell
$subnets = @()
$subnet1Name = "Subnet1"
$subnet2Name = "Subnet2"
$subnet1AddressPrefix = "10.0.0.0/24"
$subnet2AddressPrefix = "10.0.1.0/24"
$vnetAddressSpace = "10.0.0.0/16"
$vnetName = "ExamRefVNET"

New-AzResourceGroup -Name $resourceGroupName -Location $location
```
Create a virtual network
```powershell
$subnets = @()
$subnets += New-AzVirtualNetworkSubnetConfig -Name $subnet1Name -AddressPrefix $subnet1AddressPrefix
$subnets += New-AzVirtualNetworkSubnetConfig -Name $subnet2Name -AddressPrefix $subnet2AddressPrefix
$vnet = New-AzVirtualNetwork -Name $vnetName -Location $location -AddressPrefix $vnetAddressSpace -Subnet $subnets
$pip = New-AzPublicIpAddress -Name $ipName -ResourceGroupName $g -Location $location -AllocationMethod Dynamic -DomainNameLabel $dnsName
$nsgRules = @()
$nsgRules += New-AzNetworkSecurityRuleConfig -Name "RDP" -Description "RemoteDesktop" -Protocol Tcp -SourcePortRange "*" -DestinationPortRange "3389" -SourceAddressPrefix "*" -DestinationAddressPrefix "*" -Access Allow -Priority 110 -Direction Inbound
$nsg = New-AzNetworkSecurityGroup -ResourceGroupName $resourceGroupName -Name "ExamREfNSG" -SecurityRules $nsgRules -Location $location
$nic = New-AzNetworkInterface -Name $nicNAme -ResourceGroupName $resourceGroupName -Location $location -SubnetId $vnet.Subnets[0].Id -PublicIpAddressId $pip.Id -NetworkSecurityGroupId $nsg.Id
Add-AzVMNetworkInterface -VM $vm -NetworkInterface $nic
$vm = New-AzVMConfig -VMName $vmName -VMSize $vmSize
Set-AzVMOperatingSystem -Windows -ComputerName $vmName -Credential $cred -ProvisionVMAgent -VM $vm
Set-AzVMSourceImage -PublisherName $pubName -Offer $offerName -Skus $skuName -Version "latest" -VM $vm
Set-AzVMOSDisk -CreateOption fromImage -VM $vm
New-AzVM -ResourceGroupName $resourceGroupName -Location $location -VM $vm
```

```sh
az group create --name $g --location $location
vmName="myUbuntuVM"
imageName="UbuntuLTS"
az vm create --resource-group $g --name $vmName --image $imageName --generate-ssh-keys
```
Create a virtual network
```sh
vnetName="ExamRefVNET"
vnetAddressPrefix="10.0.0.0/16"
az network vnet create --resource-group $g -n ExamRefVNET --address-prefixes $vnetAddressPrefix -l $location
dnsRecord="examrefdns123123"
ipName="ExamRefIP"
az network public-ip create -n $ipName -g $g --allocation-method Dynamic --dns-name $dnsRecord -l $location
nsgName="webnsg"
az network nsg create -n $nsgName -g $g -l $location
```
Create a NSG rules to allow inbound SSH and HTTP
```sh
az network nsg rule create -n SSH --nsg-name ... --priority 100 -g ... --access Allow --description "SSH Access" --direction Inbound --protocol Tcp --destination-address-prefix "*" --destination-port-range 22 --source-address-prefix "*" --source-port-range "*"
az network nsg rule create -n HTTP --nsg-name ... --priority 101 -g ... --access Allow --description "Web Access" --direction Inbound --protocol Tcp --destination-address-prefix "*" --destination-port-range 80 --source-address-prefix "*" --source-port-range "* 
```
```sh
# Create a network interface
nicname="WebVMNic1"
az network nic create -n $nicname -g $g --subnet $Subnet1Name --network-security-group $nsgName --vnet-name $vnetName --public-ip-address $ipName -l $location
```
```sh
# Retrieve a list of marketplace images
az vm image list --all
```
```sh
# Retrieve form factors available in each region
az vm list-sizes --location ...
```
```sh
# Create the VM
imageName="Canonical:UbuntuServer:16.04-LTS:latest"
vmSize="Standard_DS1_V2"
user=demouser
vmName="WebVM"
az vm create -n $vmName -g $g -l $location --size $vmSize --nics $nicname --image $imageName --generate-ssh-keys
```

## VHD

Add a new disk to a VM

=== "PowerShell"

    ```powershell
    $dataDiskName = "MyDataDisk"
    $location="WestUS"
    $diskConfig = New-AzDiskConfig -SkuName Premium_LRS -Location $location -CreateOption Empty -DiskSizeGB 128
    $dataDisk1 = New-AzDisk -DiskName $dataDiskName -Disk $diskConfig -ResourceGroupNAme ExamRefRG
    $vm = Get-AzVM -Name ExamRefVM -ResourceGroupName ExamRefRG
    $vm = Add-AzVMDataDisk -VM $vm -Name $dataDiskName -CreateOption Attach -ManagedDiskId $dataDisk1.Id -Lun 1
    
    Update-AzVM -VM $vm -ResourceGroupName ExamRefRG
    ```

=== "Azure CLI"

    ```sh
    az vm disk attach -g ExamRefRG --vm-name ExamRefVM --name myDataDisk --new --size-gb 128 --sku Premium_LRS
    ```

Modify host cache setting

=== "PowerShell"

    ```powershell
    $vm = Get-AzVM -ResourceGroupName $g -Name $vmName
    Set-AzVMDataDisk -VM $vm -Lun 0 -Caching ReadOnly
    Update-AzVM -ResourceGroupName $g -VM $vm
    ```

=== "Azure CLI"

    ```sh
    az vm disk attach --vm-name $vmName --resource-group $g --size-gb 128 --disk $diskName --caching ReadWrite -new
    az vm unmanaged-disk attach
    ```


## Diagnostics
### Enable on deployment

![](/img/az-vm-diag.jpg)
### Enable after deployment


:point_right: [`Set-AzVmDiagnosticsExtension`](https://docs.microsoft.com/en-us/powershell/module/az.compute/set-azvmdiagnosticsextension?view=azps-4.8.0)

Enable diagnostics using a storage account specified in a XML configuration file
```powershell
Set-AzVMDiagnosticsExtension -ResourceGroupName "ResourceGroup01" -VMName "VirtualMachine02" -DiagnosticsConfigurationPath "diagnostics_publicconfig.xml"
```
Providing storage account name absent in config, or overriding it if present
```powershell
Set-AzVMDiagnosticsExtension -ResourceGroupName "ResourceGroup1" -VMName "VirtualMachine2" -DiagnosticsConfigurationPath diagnostics_publicconfig.xml -StorageAccountName "MyStorageAccount"
```
Explicitly providing storage account name and key
```powershell
Set-AzVMDiagnosticsExtension -ResourceGroupName "ResourceGroup01" -VMName "VirtualMachine02" -DiagnosticsConfigurationPath "diagnostics_publicconfig.xml" -StorageAccountName "MyStorageAccount" -StorageAccountKey $storage_key
```

## ARM templates

Deploy a named ARM template

=== "PowerShell"

    ```powershell
    New-AzResourceGroupDeployment -Mode Complete -Name simpleVMDeployment -ResourceGroupName ExamRefRG
    ```

=== "Azure CLI"

    ```sh
    az group deployment create --name simpleVMDeployment --mode Complete --resource-group ExamRefRG
    ```
    
Export a resource group to an ARM template

=== "PowerShell"

    ```powershell
    Save-AzResourceGroupDeploymentTemplate -ResourceGroupName ExamRefRG -DeploymentName simpleVMDeployment
    ```
    
=== "Azure CLI"

    ```sh
    az group deployment export --name simpleVMDeployment --resource-group ExamRefRG
    ```

Create from existing resource group

```powershell
Export-AzResourceGroup -ResourceGroupName ExamRefRG
```

Pass a template file during deployment

```powershell
New-AzResourceGroupDeployment -Name MyDeployment -ResourceGroupName ExamRefRG -TemplateFile C:\MyTemplates\AppTemplate.json
```

```sh
az group export --name ExamRefRG
```


```sh
az group deployment create --name MyDeployment --resource-group ExamRefRG --template-file AppTemplate.json --parameters @dev-env.json
```

## View all available sizes in a location
Move a resource to another resource group or subscription (PowerShell)
```powershell
$resourceID = Get-AzResource -ResourceGroupName ExamRefRG | Format-Table -Property ResourceId

Move-AzResource -DestinationResourceGroupName ExamRefDestRG -ResourceId $resourceID
Move-AzResource -DestinationSubscriptionId $subscriptionID -DestinationResourceGroupName ExamRefDestRG -ResourceId $resourceID
```

Move a resource to another resource group or subscription (Azure CLI)
```sh
az resource list -g ExamRefRG
az resource move --destination-group ExamRefDestRG --ids $resourceID
az resource move --destination-group ExamrefDestRG --destination-subscription-id $subscriptionID --ids $resourceID
```

## DSC
### Package
Package a DSC script into a zip file
```powershell
Publish-AzVMDscConfiguration -ConfigurationPath .\ContosoWeb.ps1 -OutputArchivePath .\ContosoWeb.zip
```
### Apply
Publish a packaged DSC script to a storage account
```powershell
$g = "ExamRefRG"
$location =- "WestUS"
$vmName = "ExamRefVM"
$storageName = "dscstorageer1"
$configurationName = "Main"
$archiveBlob = "ContosoWeb.ps1.zip"
$configurationPath = ".\ContosoWeb.ps1"

Publish-AzVMDscConfiguration -ConfigurationPath $configurationPath -ResourceGroupName $g -StorageAccountName $storageName
Set-AzVmDscExtension -Version 2.76 -ResourceGroupName $g -VMName $vmName -ArchiveStorageAccountNAme $storageName -ArchiveBlobName $archiveBNlob -AutoUpdate:$false -ConfigurationName $configurationName
```

## VMSS
Create a VMSS with IIS installed from a custom script extension
```powershell
$g = "ExamRefRG"
$location = "WestUS"
$vmSize = "Standard_DS2_V2"
$capacity = 2

New-AzResourceGroup -Name $g -Location $location
$vmssConfig = New-AzVmssConfig -Location $location -SkuCapacity $capacity -SkuName $vmSize -UpgradePolicyMode Automatic
$publicIP = New-AzPublicIpAddress -ResourceGroupName $g -Location $locaiton -AllocationMethod Static -Name $publicIPName
$frontendIP = New-AzLoadBalancerFrontendIpConfig -Name "lbFrontEndPool" -PublicIpAddress $publicIP
$backendPool = New-AzLoadBalancerBackendAddressPoolConfig -Name "lbBackEndPool"
$lb = New-AzLoadBalancer -ResourceGroupName $g -Name "lbrule" -Location $location -FrontendIPConfiguration $frontendIP -BackendAddressPool $backendPool

Add-AzLoadBalancerProbeConfig -Name "lbrule" -LoadBalancer $lb -Protocol http -Port 80 -IntervalInSeconds 15 -ProbeCount 2 -RequestPath "/"
Set-AzLoadBalancer -LoadBalancer $lb
```
Reference a VM image from the gallery
```powershell
Set-AzVmssStorageProfile $vmssConfig -ImageReferencePublisher MicrosoftWindowsServer -ImageReferenceOffer WindowsServer -ImageReferenceSku 2016-Datacenter -ImageReferenceVersion latest -OsDiskCreateOption FromImage
```
Set up information for authenticating with the VM
```powershell
Set-AzVmssOsProfile $vmssConfig -AdminUsername "azureuser" -AdminPassword "P@ssword!" -ComputerNamePrefix "ssVM"
```
Create VNet resources
```powershell
$subnet = New-AzVirtualNetworkSubnetConfig -Name "web" -AddressPrefix 10.0.0.0/24
$vnet = New-AzVirtualNetwork -ResourceGroupName $g -Name $ssName -Location $location -AddressPrefix 10.0.0.0/16 -Subnet $subnet
$ipConfig = New-AzVmssIpConfig -Name "vmssIPConfig" -LoadBalancerBackendAddressPoolsId $lb.BackendAddressPools[0].Id -SubnetId $vnet.Subnets[0].Id
```
Attach the VNet to the config object
```powershell
Add-AzVmssNetworkInterfaceConfiguration -VirtualMachineScaleSet $vmssConfig -Name "network-config" -Primary $true -IPConfiguration $ipConfig 
```
Create the scale set with the config object
```powershell
New-AzVmss -ResourceGroupName $g -Name $scaleSetName -VirtualMachineScaleSet $vmssConfig
```
```sh
g="ExamRefRG"
ssName="erscaleset"
userName="azureuser"
password="P@ssword!"
vmPrefix="ssVM"
location="WestUS"

az group create --name $g --location $location
az vmss create --resource-group $g --name $ssName --image UbuntuLTS --authentication-type password --admin-username $userName --admin-password $password
```

## Custom script extension
Use the custom script extension to install packages and Windows features and roles to VMs
```powershell
# Deploy the Active Directory Domain Services role
Install-WindowsFeature -Name "AD-Domain-Services" -IncludeManagementTools -IncludeAllSubFeature
Install-ADDSForest -DomainName $domain -DomainMode Win2012 -ForestMode Win2012 -Force -SafeModeAdministratorPassword $smPassword
```
```powershell
# Use `Set-AzVMCustomScriptExtension` to run script on a VM
$vmName = "ExamRefVM"
$scriptName = "deploy-ad.ps1"
$domain = "contoso.com"
$extensionName = "installAD"
$location = "WestUS"
$scriptUri = "https://raw.githubusercontent.com/opsgility/lab-support-public/master/script-extensions/deploy-ad.ps1" 
$scriptArgument = "contoso.com $password"
Set-AzVMCustomScriptExtension -ResourceGroupName $g -VMName $vmName -FileUri $scriptUri -Argument "$domain $password" -Run $scriptName -Name $extensionName -Location $location
```
```sh
vmName="LinuxVM"
extensionName="InstallApache"
az vm extension set --resource-group $g --vm-name $vmName --name customScript --publisher Microsoft.Azure.Extensions --protected-settings ./cseconfig.json
```

Enable IIS using the **Custom Script Extension** to run a PowerShell script on the VM. <sup>[?](https://docs.microsoft.com/en-us/learn/modules/build-azure-vm-templates/5-add-a-resource?pivots=windows-cloud)</sup>
```sh
az vm extension set --resource-group $RESOURCEGROUP --vm-name SimpleWinVM --name CustomScriptExtension --publisher Microsoft.Compute --version 1.9 --settings '{"fileUris":["https://raw.githubusercontent.com/MicrosoftDocs/mslearn-welcome-to-azure/master/configure-iis.ps1"]}' --protected-settings '{"commandToExecute": "powershell -ExecutionPolicy Unrestricted -File configure-iis.ps1"}'
```

Create availability set


=== "Azure PowerShell"

    ```powershell
    New-AzavailabilitySet -ResourceGroupName $g -Name $n -Location $l -PlatformUpdateDomainCount 10 -PlatformFaultDomainCount 3 -Sku "Aligned"
    ```
    
=== "Azure CLI"

    ```sh
    az vm availability-set create -n $n -g $g --platform-fault-domain-count 3 --platform-update-domain-count 10
    ```
    

### Invoke a command on a VM
Run a shell script, `$script` can be supplied inline
```sh
az vm run-command invoke --command-id RunShellScript --scripts $script
```
Parameters can be passed to the script argument
```sh
az vm run-command invoke --command-id RunShellScript --scripts 'echo $1 $2' --parameters hello world
```
Run a PowerShell script
```sh
az vm run-command invoke --command-id RunPowerShellScript -n Socrates -g RG 
```
Run a script file
```sh
az vm run-command invoke --command-id RunPowerShellScript -n Socrates -g RG --scripts @script.ps1 --parameters 'arg1=somefoo' 'arg2=somebar'
```
Available values for **command-id** can be enumerated:
```sh
az vm run-command list
```
### Dedicated host
![](/img/az-host-group-1.jpg)
![](/img/az-host-group-2.jpg)

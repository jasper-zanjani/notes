## High availability

These high-availability options are mutually exclusive:

- **Availability zones** protect from datacenter-level failures by providing physical and logical separation between VM instances. Zones have independent power sources, network, and cooling, and there are at least 3 zones in every region.
- **Availability sets** offer redundancy for VMs in the same application tier, ensuring at least one VM is available in the case of a host update or problem. Each VM is assigned a **fault domain** (representing separate physical racks in the datacenter) and an **update domain** (representing groups of VMs and underlying physical hardware that can be rebooted at the same time for host updates). Availability sets have a maximum of 20 update domains and 3 fault domains. 

**VM scale sets (VMSS)** support the ability to dynamically add and remove instances. By default, a VMSS supports up to 100 instances or up to 1000 instances if deployed with the property `singlePlacementGroup` set to false (called a **large-scale set**). A **placement group** is a concept similar to an availability set in that it assigns fault and upgrade domains. By default, a scale set consists of only a single placement group, but disabling this setting allows the scale set to be composed of multiple placement groups. If a custom image is used instead of one in the gallery, the limit is actually 300 instances.

```sh title="Create availability set"
az vm availability-set create -n $n -g $g 
    --platform-fault-domain-count 3 
    --platform-update-domain-count 10
```
    


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


```sh title=
# Deploy VM from image
az vm create -g $rg  -n $vmName -l $vmLocation 
    --image $imageName

# Specify a legacy unmanaged image
az vm create -g $rg  -n $vmName -l $vmLocation 
    --image $osDiskUri 
    --generate-ssh-keys

# Windows Server Core
az vm create -g $rg  -n $vmName -l $vmLocation 
    --image "MicrosoftWindowsServer:WindowsServer:2016-Datacenter-Server-Core:2016.127.20190603" 
    --admin-username aztestadmin
    --admin-password $password
    --nics socrates-nic
```

```sh title="Display status of VMs"
az vm list -g $g -o table
```

```sh title="Invoke a command on a VM"
# Enumerate available values for command-id
az vm run-command list

az vm run-command invoke -g $g -n $n
    --command-id RunPowerShellScript 
    --scripts @script.ps1 
    --parameters 'arg1=somefoo' 'arg2=somebar'
```

```sh title="
# Resize VM
az vm list-vm-resize-options 
    -g $g -n $n 
    --output table

az vm resize -g $g -n $n 
    --size Standard_DS3_v2

# Create container registry
az acr create -g $g -n $n
    --sku Basic --admin-enabled true

# Add NIC
az network nic create -g $g -n $n 
    --vnet-name $ExamRefVNET 
    --subnet $subnetName

az vm nic add -g $g --vm-name $vmName --nics $nicName --primary-nic
```


```sh
az vm redeploy -g $g -n $n
```

```sh title="Create managed VM"
az vm deallocate -g $g --name $vmName
az vm generalize -g $g --name $vmName
az image create -g $g --name $imageName --source $vmName 
```

```sh title="Create scale set"
az vmss create -g $g -n $n 
    --image UbuntuLTS 
    --authentication-type password 
    --admin-username $userName 
    --admin-password $password
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

```powershell
# Create a virtual network
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

### Dedicated host

![](/img/az-host-group-1.jpg)
![](/img/az-host-group-2.jpg)

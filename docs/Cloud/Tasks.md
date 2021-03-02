# ✅ Tasks

#### Tags

List a resource's tags

=== "Azure PowerShell"

    ```powershell
    $r = Get-AzResource -Name $resourceName -ResourceGroup rg
    Get-AzTag -ResourceId $r.id
    ```

=== "Azure CLI"

    ```sh
    az resource show -n $resourceName -g $rgName --query tags
    ```

List a resource group's tags

=== "Azure PowerShell"

    ```powershell
    $rg = Get-AzResourceGroup -Name $rgName
    Get-AzTag -ResourceId $rg.ResourceId
    ```

=== "Azure CLI"

    ```sh
    az group show -n $rgName --query tags
    ```

List a subscription's tags

=== "Azure PowerShell"

    ```powershell
    $s = (Get-AzSubscription -SubscriptionName "Example Subscription").Id
    Get-AzTag -ResourceId "/subscriptions/$s"
    ```


#### Containers

Create container registry

=== "Azure PowerShell"

    ```powershell
    New-AzContainerRegistry -ResourceGroupName $rg -Name $registry -Sku "Basic" -EnableAdminUser
    ```

=== "Azure CLI"

    ```sh
    az acr create --name $registry --resource-group $rg --sku Basic --admin-enabled true
    ```


#### Web application

In Azure, multiple web applications are organized under an **App Service Plan** resource.
So if no such app service plan exists, it must be created.

=== "Azure PowerShell"

    ```powershell
    $p = New-AzAppServicePlan -Name $n -ResourceGroupName $g -Location $l -Tier "Basic" -NumberofWorkers 2 -WorkerSize "Small"
    New-AzWebApp -Name $n -Location $l -ResourceGroupName $g -AppServicePlan $p
    ```

=== "Azure CLI"

    ```sh
    az appservice plan create -g $g -n $p --is-linux
    az webapp create -n $n -g $g --plan $p
    ```

#### Load balancer

### To-do app using MongoDB

Create two VMs, **backend** and **frontend**, running on Ubuntu. Make sure ports 80 and 22 are open.

### Create a new Google Cloud Source Repository

These steps require:

  1. Cloud SDK and Git to be installed
  2. A GCP project with billing and the Cloud Source Repositories API enabled

```sh
#Create a new repository
gcloud source repos create hello-world

#Clone it locally
gcloud source repos clone hello-world

# Create scripts, then add, commit and push them as usual.
git commit -am "Initial"
git push origin master
```

### Create a VM

([src](https://www.youtube.com/watch?v=j274vq9a2Rs))
```sh
gcloud compute instances create instance-1 --zone-uscentral1-a
```


### Functions

Deploy [Deploy](https://cloud.google.com/functions/docs/quickstart)
```sh
gcloud functions deploy hello_get --runtime python37 --trigger-http
```
[Test](https://cloud.google.com/source-repositories/docs/creating-an-empty-repository)
```sh
gcloud functions describe hello_get
```

### Change storage class

`$STORAGE_CLASS` can be `multi_regional`, `regional`, `nearline`, or `coldline`
```sh
gsutil rewrite -s $STORAGE_CLASS gs://$PATH_TO_OBJECT
```

## Virtual networking

Create virtual network with a specific prefix and subnet

=== "Azure PowerShell"

    ```powershell
    $subnet = New-AzVirtualNetworkSubnetConfig -Name $subnetName -AddressPrefix "10.0.0.0/24"
    $vnet = New-AzVirtualNetwork -Name $vnetName -ResourceGroupName $rgName -Location $l 
        -AddressPrefix "10.0.0.0/16" 
        -Subnet $subnet
    ```
    
=== "Azure CLI"

    ```sh
    az network vnet create -g $rgName -n $vnetName  \
        --address-prefix 10.0.0.0/16                \
        --subnet-name $subnetName                   \
        --subnet-prefix 10.0.0.0/24
    ```


Create peering

=== "Azure PowerShell"

    ```powershell
    Add-AzVirtualNetworkPeering -Name 'VNet2-to-VNet1' -VirtualNetwork $vnet2 -RemoteVirtualNetworkId $vnet1.Id
    Add-AzVirtualNetworkPeering -Name 'VNet1-to-VNet2' -VirtualNetwork $vnet1 -RemoteVirtualNetworkId $vnet2.Id
    ```
    
=== "Azure CLI"

    ```sh
    az network vnet peering create --name 'VNet1-to-VNet2' --resource-group $rg --vnet-name VNet1 --allow-vnet-access --remote-vnet VNet2
    az network vnet peering create --name 'VNet2-to-VNet1' --resource-group $rg --vnet-name VNet2 --allow-vnet-access --remote-vnet VNet1
    ```
    
Check peering

=== "Azure PowerShell"

    ```powershell
    Get-AzVirtualNetworkPeering -ResourceGroupName $rg -VirtualNetworkName $vnetName
    ```
    
=== "Azure CLI"

    ```sh
    az network vnet peering list --resource-group $rg --vnet-name VNet1
    az network vnet peering list --resource-group $rg --vnet-name VNet2
    ```
    

User-defined routes

=== "Azure PowerShell"

    ```powershell
    # Create the route table resource
    $routeTable = New-AzRouteTable -Name $routeTableName -ResourceGroupName ExamRefRG
    
    # Add a route to route table object
    Add-AzRouteConfig 
        -RouteTable $routeTable 
        -Name $routeName 
        -AddressPrefix 10.3.0.0/16 
        -NextHopType VirtualAppliance 
        -NextHopIpAddress 10.2.20.4
    Set-AzRouteTable -RouteTable $routeTable
    
    # Associate route table with subnet
    Set-AzVirtualNetworkSubnetConfig -VirtualNetwork $vnet -Name Default -AddressPrefix $subnet.AddressPrefix 
        -RouteTable $routeTable
    
    # Commit changes
    Set-AzVirtualNetwork -VirtualNetwork $vnet
    
    # Get effective routes for a NIC
    Get-AzEffectiveRouteTable -NetworkInterfaceName $nicName -ResourceGroupName $rgName
    ```
    

=== "Azure CLI"

    ```sh
    # Create route table resource
    az network route-table create --name $routeTableName --resource-group $rgName 
    
    # Add route to route table
    az network route-table route create 
        --resource-group $rgName 
        --route-table-name $routeTableName 
        --name $routeName 
        --address-prefix 10.3.0.0/16 
        --next-hop-type VirtualAppliance 
        --next-hop-ip-address 10.2.20.4
    
    # Associate route table with subnet
    az network vnet subnet update --name defualt --vnet-name Vnet1 --resource-group $rgName 
        --route-table rt
    
    # Get effective routes for NIC
    az network nic show-effective-route-table --name $nicName --resource-group $rgName
    ```
    

Create NSG

=== "Azure PowerShell"

    ```powershell
    $nsgRules = @()
    $nsgRules += New-AzNetworkSecurityRuleConfig -Name "AllowingWinRMHTTP" -Description "To Enable PowerShell Remote Access" -Access Allow -Protocol Tcp -Direction Inbound -Priority 103 -SourceAddressPrefix Internet -SourcePortRange * -DestinationAddressPrefix * -DestinationPortRange 5985
    $nsgRules += New-AzNetworkSecurityRuleConfig -Name "AllowingWinRMHTTPS" -Description "To Enable PowerShell Remote Access" -Access Allow -Protocol Tcp -Direction Inbound -Priority 104 -SourceAddressPrefix Internet -SourcePortRange * -DestinationAddressPrefix * -DestinationPortRange 5986
    $nsg = New-AzNetworkSecurityGroup -Name "wscore-nsg" -ResourceGroupName "RG" -Location "East US" -SecurityRules $nsgRules
    ```
    
View rules

=== "Azure PowerShell"

    ```powershell
    Get-AzEffectiveNetworkSecurityGroup -NetworkInterfaceName $nicName -ResourceGroupName $rgName
    ```
    
=== "Azure CLI"

    ```sh
    az network nic list-effective-nsg --name $nicName --resource-group $rgName
    ```
    

Create Bastion

Connecting to a VM requires at least Reader role privileges on the VM, its NIC, and on the Bastion itself.

=== "Azure PowerShell"

    ```powershell
    New-AzBastion -ResourceGroupName $rgName -Name $n -PublicIpAddress $pip -VirtualNetwork $vnet
    ```
    
=== "Azure CLI"

    ```sh
    az network bastion create -g $rgName -n $n -l $l --public-ip-address $pip  --vnet-name $vnetName
    ```

Create virtual appliance

**IP forwarding** must be enabled on the VM's NIC, then applications installed on the VM can begin accepting packets destined for other IP addresses.

![](img/az-vm-nic.jpg)
![](img/az-vm-nic-ip.jpg)

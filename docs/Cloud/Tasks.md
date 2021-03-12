# Tasks

## 🛠&#xfe0f; Administration

Display subscription ID

=== "Azure PowerShell"

    ```powershell
    Get-AzSubscription
    ```
    
=== "Azure CLI"

    ```sh
    az account show
    ```

### 🖥&#xfe0f; CLI

Initialize CLI utility

=== "GCP gcloud"

    ```sh
    gcloud init
    ```

### 💰 Cost management

To view resource quotas for a subscription, go to the subscription in Azure Portal and open the **Usage + quotas** blade. From there you can select resources and then click the **Request Increase** button.

View current usage of vCPU quotas

=== "Azure PowerShell"

    ```powershell
    Get-AzVMUsage
    ```

View current usage of storage service

=== "Azure PowerShell"

    ```powershell
    Get-AzStorageUsage
    ```

Create a budget

To create a budget, open **Cost Management + Billing**, then **Subscriptions**, select a subscription, then click **Budgets**. 
Then click **+ Add**, which produces a Create budget blade. 
The created budget can be seen in the **Budgets** blade. 
PowerShell commands used with budgets:

- `Get-AzResourceGroup` retrieve Resource Group object
- `Set-AzResourceGroup` apply a tag to a resource group with **no preexisting tags**
- `.Tags` method that retrieves Tag collection from a resource group
- `.Add()` method used to add tags to a resource group that **already has** tags.



### Monitoring

VM extension

=== "Azure PowerShell"

    ```powershell
    Set-AzVMExtension -ResourceGroupName ExamRefRG -Location "West Europe" -VMName VM1 -Name networkWatcherAgent -Publisher Microsoft.Azure.NetworkWatcher -Type NetworkWatcherAgentWindows -TypeHandlerVersion 1.4
    ```
    
=== "Azure CLI"
    
    ```sh
    az vm extension set --vm-name VM1 --resource-group ExamRefRG --publisher Microsoft.Azure.NetworkWatcher --version 1.4 --name NetworkWatcherAgentWindows --extension-instance-name NetworkWatcherAgent
    ```

Start packet capture
    
=== "Azure PowerShell"

    ```powershell
    $nw = Get-AzResource | Where ResourceType -eq "Microsoft.Network/networkWatchers" -and Location -eq "WestEurope"
    $networkWatcher = Get-AzNetworkWatcher -Name $nw.Name -ResourceGroupName $nw.ResourceGroupName
    $storageAccount = Get-AzStorageAccount -Name examref-storage -ResourceGroupName ExamRefRG
    
    $filter1 = New-AzPacketCaptureFilterConfig -Protocol TCP -RemoteIPAddress "1.1.1.1-255.255.255.255" -LocalIPAddress "10.0.0.3" -LocalPort "1-65535" -RemotePort "20;80;443"
    $filter2 = New-AzPacketCaptureFilterConfig -Protocol UDP
    $vm = Get-AzVM ` -Name VM1 -ResourceGroupName ExamRefRG
    
    New-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -TargetVirtualMachineId $vm.Id -PacketCaptureName "PacketCaptureTest" -StorageAccountId $storageAccount.id -TimeLimitInSeconds 60 -Filter $filter1, $filter2
    ```
    

=== "Azure CLI"

    ```sh
    filter='[ { "protocol": "TCP", "remoteIPAddress": "1.1.1.1-255.255.255.255", "localIPAddress":"10.0.0.3", "remotePort":"20" } ]'
    az network watcher packet-capture create --name PacketCaptureTest2 --resource-group ExamRefRG --vm VM1 --time-limit 300 --storage-account examref-storage --filters $filter
    ```

Check status of packet capture

=== "Azure PowerShell"

    ```powershell
    Get-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -PacketCaptureName "PacketCaptureTest"
    ```
    
=== "Azure CLI"

    ```sh
    az network watcher packet-capture show-status --name PacketCaptureTest --location WestEurope
    ```
    
Stop packet capture

=== "Azure PowerShell"

    ```powershell
    Stop-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -PacketCaptureName "PacketCaptureTest"
    ```
    
=== "Azure CLI"

    ```sh
    az network watcher packet-capture stop --name PacketCaptureTest --location WestEurope
    ```


Use **IP Flow Verify** to test outbound connectivity from source VM and port to destination. If any configured filtering rules block traffic between the endpoints, it will return the name of the offending NSG.

=== "Azure PowerShell"

    ```powershell
    Test-AzNetworkWatcherIPFlow
    ```

=== "Azure CLI"

    ```sh
    az network watcher test-ip-flow
    ```

Next Hop

=== "Azure PowerShell"

    ```powershell
    Get-AzNetworkWatcherNextHop
    ```
    
=== "Azure CLI"

    ```sh
    az network watcher show-next-hop
    ```

Use Network Topology

=== "Azure PowerShell"

    ```powershell
    Get-AzNetworkWatcherTopology
    ```
    
=== "Azure CLI"

    ```sh
    az network watcher show-topology
    ```
    
Capture SFTP traffic

```powershell
$r = Get-AzResource | where ResourceType -eq "Microsoft.Network/networkWatchers" -and Location -eq "EastUS"
$nw = Get-AzNetworkWatcher -Name $r.Name -ResourceGroupName $r.ResourceGroupName
$s = Get-AzStorageAccount -ResourceGroupName "Diagnostics-RG" -Name "Diagnostics-Storage"
$filter = New-AzPacketCaptureFilterConfig -Protocol TCP -RemoteIPAddress "1.1.1.1-255.255.255.255" -LocalIPAddress "10.0.0.4" -LocalPort "1-65535" -RemotePort "22"

New-AzNetworkWatcherPacketCapture -NetworkWatcher $nw -TargetVirtualMachineId $vm.ID -PacketCaptureName "Capture SFTP traffic" -StorageAccountId $s.Id -TimeLimitInSeconds 60 -Filter $filter
```

### Policy

Assign a policy

=== "Azure PowerShell"

    ```powershell
    $scope = '/subscriptions/$subscriptionID'
    $policyparam = '{
      "tagName" : {
        "value": "Environment" },
      "tagValue": {
        "value" : "Production" } }'
    $assignment = New-AzPolicyAssignment -Name 'append-environment-tag' -DisplayName 'Append Environment Tag' -Scope $scope -PolicyDefinition $definition -PolicyParameter $policyparam
    ```

Remove policy assignment and definition

=== "Azure PowerShell"

    ```powershell
    Remove-AzPolicyAssignment -Id $assignment.ResourceId
    Remove-AzPolicyDefinition -Id $definition.ResourceId
    ```
    
Create a policy definition

=== "Azure Portal"

    (All Services) > Policy > Definitions: Both builtin and custom policies can be managed here.
    

=== "Azure PowerShell"

    ```powershell
    New-AzPolicyDefinition -Name 'appendEnvironmentTag' -DisplayName 'Append Environment Tag' -Policy 'AppendDefaultTag.json' -Parameter 'AppendDefaultTagParams.json'
    ```

=== "Azure CLI"

    ```sh
    az policy definition create --name 'allowedVMs' --description 'Only allow virtual machines in the defined SKUs' --mode ALL --rules '{...}' --params '{...}'
    ```
    
Apply policy to a scope

=== "Azure CLI"

    ```sh
    az policy assignment create --policy allowedVMs --name 'deny-non-compliant-vms' --scope '/subscriptions/<Subscription ID>' -p
    ```

Delete policy assignment

=== "Azure CLI"

    ```sh
    az policy assignment delete --name deny-non-compliant-vms
    ```


### Resources

Create resource group

=== "Azure PowerShell"

    ```powershell
    New-AzGroup -Location $location -Name $rgName
    ```

=== "Azure CLI"

    ```sh
    az group create -l $location -n $rgName 
    ```

Register resource provider in subscription
```sh
az provider register --namespace 'Microsoft.PolicyInsights'
```

Move resources

=== "Azure PowerShell"

    ```powershell
    $webapp = Get-AzResource -ResourceGroupName OldRG -ResourceName ExampleSite
    $plan = Get-AzResource -ResourceGroupName OldRG -ResourceName ExamplePlan

    Move-AzResource -DestinationResourceGroupName NewRG -ResourceId $webapp.ResourceId, $plan.ResourceId
    ```

=== "Azure CLI"

    ```sh
    webapp=$(az resource show -g OldRG -n ExampleSite --resource-type "Microsoft.Web/sites" --query id --output tsv)
    plan=$(az resource show -g OldRG -n ExamplePlan --resource-type "Microsoft.Web/serverfarms" --query id --output tsv)

    az resource move --destination-group newgroup --ids $webapp $plan
    ```

Create lock on a resource

=== "Azure PowerShell"

    ```powershell
    New-AzResourceLock 
        -LockName LockSite
        -LockLevel CanNotDelete 
        -ResourceGroupName $rg 
        -ResourceName $r 
        -ResourceType Microsoft.Web/sites 
    ```

=== "Azure CLI"

    ```sh
    az lock create 
        --name LockSite
        --lock-type CanNotDelete 
        --resource-group $rg 
        --resource-name $r 
        --resource-type Microsoft.Web/sites 
    ```

Create lock on a resource group

=== "Azure PowerShell"

    ```powershell
    New-AzResourceLock 
        -LockName LockGroup 
        -LockLevel CanNotDelete 
        -ResourceGroupName $rg
    ```

=== "Azure CLI"

    ```sh
    az lock create 
        --name LockGroup 
        --lock-type CanNotDelete 
        --resource-group $rg
    ```


Display resource lock

=== "Azure PowerShell"

    ```powershell
    Get-AzResourceLock -ResourceName $r -ResourceType Microsoft.Web/sites -ResourceGroupName $rg
    ```

=== "Azure CLI"

    ```sh
    az lock list --resource-group $rg --resource-name $r --namespace Microsoft.Web --resource-type sites --parent ""
    ```

Delete resource lock

=== "Azure PowerShell"

    ```powershell
    $lockId = (Get-AzResourceLock -ResourceGroupName $rg -ResourceName $r -ResourceType Microsoft.Web/sites).LockId

    Remove-AzResourceLock -LockId $lockId
    ```

=== "Azure CLI"

    ```sh
    lockid=$(az lock show --name LockSite --resource-group $rg --resource-type Microsoft.Web/sites --resource-name $r --output tsv --query id)
    az lock delete --ids $lockid
    ```

Sources

- [Manage Azure Resource Manager resource groups by using Azure PowerShell](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/manage-resource-groups-powershell)
- [Manage Azure Resource Manager resource groups by using Azure CLI](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/manage-resource-groups-cli)
- [Resource providers](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/azure-services-resource-providers)
- [Lock resources to prevent unexpected changes](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/lock-resources)
- AZ-103: [<code>1.3</code>](AZ-103#13-manage-resource-groups "Manage resource groups"), p. 76


### Tags

List all resources by tag

=== "Azure PowerShell"

    ```powershell
    (Get-AzResource -Tag @{ CostCode="1001"}).Name
    # List all resources by tag name, with no value
    (Get-AzResource -TagName CostCode).Name
    ```
    
=== "Azure CLI"

    ```sh
    az resource list --tag Dept=Finance
    ```

List resource groups by tag

=== "Azure PowerShell"

    ```powershell
    (Get-AzResourceGroup -Tag @{ CostCode="1001" }).ResourceGroupName
    ```
    
=== "Azure CLI"

    ```sh
    az group list --tag CostCode=1001
    ```

Enumerate a resource's tags

=== "Azure PowerShell"

    ```powershell
    $r = Get-AzResource -Name $resourceName -ResourceGroup rg
    Get-AzTag -ResourceId $r.id

    # Resource group
    $rg = Get-AzResourceGroup -Name $rgName
    Get-AzTag -ResourceId $rg.ResourceId

    # Subscription
    $s = (Get-AzSubscription -SubscriptionName "Example Subscription").Id
    Get-AzTag -ResourceId "/subscriptions/$s"
    ```


=== "Azure CLI"

    ```sh
    az resource show -n $resourceName -g $rgName --query tags

    # Resource group
    az group show -n $rgName --query tags
    ```

Tag resource

=== "Azure PowerShell"

    ```powershell
    $r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName rg
    $r.Tags.Add("Owner", "user@contoso.com")
    Set-AzResource -Tag $r.Tags -ResourceId $r.ResourceId -Force
    ```

    Resource group

    ```powershell
    $tags = @{"Dept"="Finance"; "Status"="Normal"}
    $rg = Get-AzResourceGroup -Name demoGroup
    New-AzTag -ResourceId $rg.ResourceId -tag $tags
    ```

    ```powershell
    $tags = (Get-AzResourceGroup -Name rg).Tags
    $tags.Add("Owner", "user@contoso.com")
    Set-AzResourceGroup -Tag $tags -Name rg
    ```

=== "Azure CLI"

    ```sh
    jsonrtag=$(az group show -n rg --query tags)
    rt=$(echo $jsonrtag | tr -d '"{},' | sed 's/: /=/g')
    az group update -n rg --tags $rt Owner=user@contoso.com
    ```



Remove specific tags

=== "Azure PowerShell"

    ```powershell
    $tags = @{"Project"="ECommerce"; "Team"="Web"}
    Update-AzTag -ResourceId $resource.id -Tag $tags -Operation Delete
    ```

Remove all tags

=== "Azure PowerShell"

    ```powershell
    $s = (Get-AzSubscription -SubscriptionName "Example Subscription").Id
    Remove-AzTag -ResourceId "/subscriptions/$s"
    
    # Alternatively
    Set-AzResourceGroup -Tag @{} -Name rg
    ```

Apply tags to resource, overwriting

=== "Azure PowerShell"

    ```powershell
    $tags = @{"Dept"="Finance"; "Status"="Normal"}
    New-AzTag -ResourceId $resource.id -Tag $tags
    ```
    ```powershell
    Set-AzResource -ResourceId $r.ResourceId -Tag @{ CostCode="1001"; Environment="Production" } -Force
    ```
    
=== "Azure CLI"

    ```sh
    az resource tag --tags 'Dept=IT' 'Environment=Test' -g $rgName -n examplevnet --resource-type "Microsoft.Network/virtualNetworks"
    ```
    
Apply tags to resource group

=== "Azure PowerShell"

    ```powershell
    Set-AzResourceGroup -Name rg -Tag @{CostCode=1001; Environment=Production}
    ```
    
=== "Azure CLI"

    ```sh
    az group update -n $rgName --tags 'Environment=Test' 'Dept=IT'

    # Alternatively
    az group update -n $rgName --set tags.Environment=Production tags.CostCode=1001
    ```


## Compute

### IaaS

Create a VM

([src](https://www.youtube.com/watch?v=j274vq9a2Rs))
```sh
gcloud compute instances create instance-1 --zone-uscentral1-a
```

### PaaS

Deploy app in current working directory.
```sh
gcloud app deploy
```
View the deployed app
```sh
gcloud app browse
```
app.yaml allows configuration of the app in several ways
```yaml
runtime: python37
```

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



### Containers

Create a new source repository

=== "GCP"

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

Create container registry

=== "Azure PowerShell"

    ```powershell
    New-AzContainerRegistry -ResourceGroupName $rg -Name $registry -Sku "Basic" -EnableAdminUser
    ```

=== "Azure CLI"

    ```sh
    az acr create --name $registry --resource-group $rg --sku Basic --admin-enabled true
    ```


### ⚓ Kubernetes

Create Kubernetes cluster

=== "Azure PowerShell"

    ```powershell
    New-AzAKS -ResourceGroupName $g -Name $n
        -NodeCount 2
        -NetworkPlugin azure
        -NodeVmSetType VirtualMachineScaleSets
        -WindowsProfileAdminUserName azureuser
        -WindowsProfileAdminUserPassword $Password
        -KubernetesVersion 1.16.7 
        # PowerShell does not offer an option to generate SSH keys for access to the cluster; `ssh-keygen` must be used.
    ```
    - 📄 [Create a Windows Server container on an AKS cluster](https://docs.microsoft.com/en-us/azure/aks/windows-container-powershell)

=== "Azure CLI"

    ```sh
    az aks create -g $g -n $n
        --node-count 2 
        --network-plugin azure 
        --vm-set-type VirtualMachineScaleSets 
        --windows-admin-username azureuser 
        --windows-admin-password $PASSWORD
        --generate-ssh-keys 
        --enable-addons monitoring 
    ```
    - 📄 [Create a Windows Server container on an AKS cluster](https://docs.microsoft.com/en-us/azure/aks/windows-container-cli) 

Add a pool of nodes

=== "Azure PowerShell"

    ```powershell
    New-AzAksNodePool -ResourceGroupName $rgName -Name npwin -ClusterName $clusterName 
        -OsType Windows 
        -KubernetesVersion 1.16.7
    ```

=== "Azure CLI"

    ```sh
    az aks nodepool add -g $g -n $n --cluster-name $clusterName
        --os-type Windows
        --node-count 1
    ```

Persistent volume claim

=== "Azure"

    ```yaml
    apiVersion: v1
    kind: PersistentVolumeClaim
    metadata:
        name: azure-managed-disk
    spec:
        accessModes:
        - ReadWriteOnce
        storageClassName: managed-premium
        resources:
            requests:
                storage: 5Gi
    ```
    - 📄 [Source](https://docs.microsoft.com/en-us/azure/aks/concepts-storage#storage-classes)

Provision Azure Disk

=== "Standard"

    ```yaml
    kind: StorageClass
    apiVersion: storage.k8s.io/v1
    metadata:
    name: managed-disk-forapp
    provisioner: kubernetes.io/azure-disk
    reclaimPolicy: Retain
    parameters:
    storageaccounttype: default
    kind: Managed
    ```

=== "Premium"

    ```yaml
    kind: StorageClass
    apiVersion: storage.k8s.io/v1
    metadata:
    name: managed-disk-forapp
    provisioner: kubernetes.io/azure-disk
    reclaimPolicy: Retain
    parameters:
    storageaccounttype: Premium_LRS
    kind: Managed
    ```



### Functions

[Deploy](https://cloud.google.com/functions/docs/quickstart)
```sh
gcloud functions deploy hello_get --runtime python37 --trigger-http
```
[Test](https://cloud.google.com/source-repositories/docs/creating-an-empty-repository)
```sh
gcloud functions describe hello_get
```

## Storage

Create storage account

=== "Azure Portal"
    
    Click **Create a resouce**, then **Storage**, then **Storage account**. Choose a **globally** unique name for the account, containing lower-case characters and digits only.

=== "Azure PowerShell"

    ```powershell
    New-AzStorageAccount -ResourceGroupName ExamRefRG -Name mystorage112300 -SkuName Standard_LRS -Location WestUS -Kind StorageV2 -AccessTier Hot
    ```

=== "Azure CLI"

    ```sh
    az storage account create --name $accountName --resource-group $resourceGroup -location $location --sku $sku
    ```

Change access tier of storage account

=== "Azure PowerShell

    ```powershell
    Set-AzStorageAccount -ResourceGroupName RG -Name $accountName -AccessTier Cool -Force
    ```

Change replication mode of storage account

```powershell
Set-AzStorageAccount -ResourceGroupName $resourceGroup -Name $accountName -SkuName $type
```

Renew storage account keys

=== "Azure 

    ```powershell
    New-AzStorageAccountKey
    ```

=== "Azure CLI"

    ```sh
    az storage account keys renew
    ```

Create Azure Key Vault

=== "Azure PowerShell"

    ```powershell
    New-AzKeyVault -VaultName $vaultName -ResourceGroupName $g -Location $location 
    $key = Add-AzKeyVaultKey -VaultName $vaultName -Name $keyName -Destination 'Software' 
    $storageKey = Get-AzStorageAccountKey -ResourceGroupName $g -Name $storageAccount 
    $secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force
    $secret = Set-AzKeyVaultSecret -VaultName $vaultName -Name $secretName -SecretValue  $secretvalue
    ```

=== "Azure CLI"

    ```sh
    az keyvault create --name $vaultName --resource-group $g --location $location
    az keyvault key create --vault-name "$vaultName" --name $keyName --protection "software"
    az keyvault secret set --vault-name "$vaultName" --name "$secretName" --value "$secretValue"
    ```

Create key in Azure Key Vault

=== "Azure PowerShell"

    ```powershell
    $key = Add-AzKeyVaultKey -VaultName $vaultName -Name $keyName -Destination 'Software'
    $storageKey = Get-AzStorageAccountKey -ResourceGroupName $g -Name $storageAccount 
    $secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force

    $secret = Set-AzKeyVaultSecret -VaultName $vaultName -Name $secretName -SecretValue $secretvalue
    ```

=== "Azure CLI"

    ```sh
    az keyvault key create --vault-name $vaultName --name $keyName --protection "software"
    az keyvault secret set --vault-name $vaultName --name $secretName --value $secretValue
    ```

Create Azure sync group

Specify name of sync group in dialog after creating an Azure File Sync


Change storage class

`$STORAGE_CLASS` can be `multi_regional`, `regional`, `nearline`, or `coldline`
```sh
gsutil rewrite -s $STORAGE_CLASS gs://$PATH_TO_OBJECT
```

### File shares


Deploy Azure File Sync

=== "Azure PowerShell"

    ```powershell
    # Create Storage Sync Service
    $storageSync = New-AzStorageSyncService -ResourceGroupName $g -Name $storageSyncName -Location $l

    # Create Azure File Share
    $storageKey = Get-AzStorageAccountKey -ResourceGroupName $g -Name $storageAccount 
    $context = New-AzStorageContext -StorageAccountName $storageAccount -StorageAccountKey $storageKey.Value[0]

    New-AzStorageShare -Name $shareName -Context $context
    ```

=== "Azure CLI"

    ```sh
    # Creating a Storage Sync Service resource is only possible in PowerShell or Portal
    constring=$(az storage account show-connection-string -n $storageAccountName)
    az storage share create --name $shareName --quota 2048 --connection-string $constring
    ```

Create sync group

=== "Azure PowerShell"

    ```powershell
    $syncgroup = New-AzStorageSyncGroup -Name $syncgroupname -ParentObject $storageSync
    ```

Create cloud endpoint

=== "Azure PowerShell"

    ```powershell
    New-AzStorageSyncCloudEndpoint -Name $shareName -ParentObject $syncgroup -StorageAccountResourceId $storageAccount.Id -AzureFileShareName $shareName
    ```

### Network access

Display the status of the default NetworkRule for a storage account

=== "Azure PowerShell"

    ```powershell
    Get-AzStorageAccountNetworkRuleSet -ResourceGroupName $rgName -AccountName $n | Select-Object DefaultAction
    ```

=== "Azure CLI"

    ```sh
    az storage account show -$rgName -n $n --query networkRuleSet.defaultAction
    ```
    

Set default rule

=== "Azure PowerShell"

    ```powershell
    Update-AzStorageAccountNetworkRuleSet -ResourceGroupName $g -Name $n -DefaultAction Deny
    Update-AzStorageAccountNetworkRuleSet -ResourceGroupName $g -Name $n -DefaultAction Allow
    ```

=== "Azure CLI"

    ```sh
    az storage account update -g $g -n $n --default-action Deny
    az storage account update -g $g -n $n --default-action Allow
    ```

## Networking

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
    az network vnet create -g $rgName -n $vnetName
        --address-prefix 10.0.0.0/16
        --subnet-name $subnetName
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

![](/img/az-vm-nic.jpg)
![](/img/az-vm-nic-ip.jpg)

### CDN

Create new profile

=== "Azure Portal"

    ![](/img/az-cdn-profile.jpg)

    1. Click **Create a resource** 
    2. Click **Web**
    3. Click **CDN**, opening the CDN profile blade
    4. Specify name for the profile, name of the resource group, region, and pricing tier.
    5. Click **Create**

    AZ-103: p. 140

Create endpoint

=== "Azure Portal"

    ![](/img/az-cdn-endpoint.jpg)

    Add an endpoint to a CDN profile (Portal)
    1. Open the CDN Profile
    2. Click **+ Endpoint** button
    3. Specify unique name, configuration for origin settings such as type, host header, and origin port for HTTP and HTTPS.
    4. Click **Add** button

    AZ-103: p. 141

Publish content in a CDN endpoint

=== "Azure Portal"

    1. Create a new CDN profile
    2. Add an endpoint to the profile



### DNS

Create DNS zone

=== "Azure PowerShell"

    ```powershell
    New-AzDnsZone -Name examref.com -ResourceGroupName ExamRefRG
    ```

=== "Azure CLI"

    ```sh
    az network dns zone create --name examref.com --resource-group ExamRefRG
    ```


Create empty A record

=== "Azure PowerShell"

    ```powershell
    New-AzDnsRecordSet -Name www -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords (New-AzDnsRecordConfig -IPv4Address "1.2.3.4")
    ```

=== "Azure CLI"

    ```sh
    az network dns record-set a create --name www --zone-name examref.com --resource-group ExamRefRG --ttl 3600
    ```

Create multiple records

=== "Azure PowerShell"

    ```powershell
    $records = @()
    $records += New-AzDnsRecordConfig -IPv4Address "1.2.3.4"
    $records += New-AzDnsRecordConfig -IPv4Address "5.6.7.8"
    New-AzDnsRecordSet -Name "@" -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords $records
    ```

=== "Azure CLI"

    ```sh
    az network dns record-set a add-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 1.2.3.4
    az network dns record-set a add-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 5.6.7.8
    ```

Remove record

=== "Azure PowerShell"

    ```powershell
    $recordset = Get-AzDnsRecordSet -Name www -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG
    Add-AzdnsRecordConfig -RecordSet $recordset -IPv4Address "5.6.7.8"
    Remove-AzDnsRecordConfig -RecordSet $recordset -IPv4Address "1.2.3.4"
    Set-AzDnsRecordSet -RecordSet $recordset
    ```

=== "Azure CLI"

    ```sh
    az network dns record-set a remove-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 1.2.3.4
    ```

Read records

=== "Azure PowerShell"

    ```powershell
    Get-AzDnsRecordSet -ZoneName examref.com -ResourceGroupName ExamRefRG
    ```

=== "Azure CLI"

    ```sh
    az network dns record-set list --zone-name examref.com --resource-group ExamRefRG -o table 
    ```

Create a virtual network with custom DNS settings

=== "Azure PowerShell"

    ```powershell
    New-AzVirtualNetwork -Name VNet1 -ResourceGroupName $rgName -Location $location 
        -AddressPrefix 10.1.0.0/16 -Subnet (New-AzVirtualNetworkSubnetConfig -Name Default -AddressPrefix 10.1.0.0/24)
        -DNSServer 10.0.0.4,10.0.0.5 
    ```

=== "Azure CLI"

    ```sh
    az network vnet create --name VNet1 --resource-group $rgName 
        --address-prefixes 10.0.0.0/16 
        --dns-servers 10.0.0.4 10.0.0.5
    ```



Modify the DNS server configuration of an existing VNET

=== "Azure PowerShell"

    ```powershell
    $vnet = Get-AzVirtualNetwork -Name $vnetName -ResourceGroupName $rgName
    $vnet.DhcpOptions.DnsServers.Clear()
    $vnet.DhcpOptions.DnsServers.Add("10.10.200.1")
    $vnet.DhcpOptions.DnsServers.Add("10.10.200.2")
    Set-AzVirtualNetwork -VirtualNetwork $vnet
    ```

=== "Azure CLI"

    ```sh
    az network vnet update --name $vnetName --resource-group $rgName 
        --dns-servers 10.10.200.1 10.10.200.2
    ```


Restart the VMs in the VNet to pick up the DNS change

=== "Azure PowerShell"

    ```powershell
    $vm = Get-AzVM -Name VNet1-VM -ResourceGroupName ExamRefRG
    Restart-AzVM -ID $vm.Id
    ```
    
Update the DNS settings on a NIC

```powershell
$nic = Get-AzNetworkInterface -Name VM1-NIC -ResourceGroupName ExamRefRG
$nic.DnsSettings.DnsServers.Clear()
$nic.DnsSettings.DnsServers.Add("8.8.8.8")
$nic.DnsSettings.DnsServers.Add("8.8.4.4")
```

Commit the DNS change, causing the VM to restart

```powershell
Set-AzNetworkInterface -NetworkInterface $nic
```



Remove custom DNS servers from a VNET

=== "Azure CLI"

    ```sh
    az network vnet update --name VNet1 --resource-group ExamRefRG --remove DHCPOptions.DNSServers
    ```

Set custom DNS servers on a NIC

=== "Azure CLI"

    ```sh
    az network nic update --name VM1-NIC --resource-group ExamRefRG --dns-servers 8.8.8.8 8.8.4.4
    ```
    


### Load balancing

Create public load balancer

Creating a load balancer in PowerShell requires defining objects which are all passed to `New-AzLoadBalancer` as objects:
- Frontend IP 
  - Public Ip Address resource (if public)
  - Private IP address specified as a string (if internal)
- Backend address pool
- Health probe
- Load balancing rule

By contrast, in Azure CLI, the load balancer can be defined first with `az network lb create` before adding a probe and rule, passing the name of the load balancer to `--lb-name`.

=== "Azure PowerShell"

    ```powershell
    $publicIP = New-AzPublicIpAddress -Name ExamRefLB-IP -ResourceGroupName $g -Location $location -AllocationMethod Static 
    $frontendIP = New-AzLoadBalancerFrontendIpConfig -Name frontend -PublicIpAddress $publicIP
    $beAddressPool = New-AzLoadBalancerBackendAddressPoolConfig -Name backend
    $healthProbe = New-AzLoadBalancerProbeConfig -Name -RequestPath '/' -Protocol http -Port 80

    $lbrule = New-AzLoadBalancerRuleConfig -Name -FrontendIpConfiguration $frontendIP -BackendAddressPool $beAddressPool -Probe $healthProbe -Protocol Tcp -FrontendPort 80 -BackendPort 80
    $lb = New-AzLoadBalancer -ResourceGroupName -Name -Location -FrontendIpConfiguration $frontendIP -LoadBalancingRule $lbrule -BackendAddressPool $beAddressPool -Probe $healthProbe
    ```

=== "Azure CLI"

    ```sh
    az network public-ip create --name ExamRefLB-IP --resource-group ExamRefRG --location --allocation-method Static
    az network lb create --name ExamRefLB --resource-group ExamRefRG --location --backend-pool-name backend --frontend-ip-name frontend --public-ip-address ExamRefLB-IP
    az network lb probe create --resource-group ExamRefRG --name HealthProbe --lb-name ExamRefLB --protocol http --port 80 --path / --interval 5 --threshold 

    az network lb rule create --name ExamRefRule --lb-name ExamRefLB --resource-group ExamRefRG --protocol Tcp --frontend-port 80 --backend-port 80 --frontend-ip-name ExamRefFrontEnd --backend-pool-name backend --probe-name HealthProbe
    ```


## IAM

Add guest user

=== "Azure Portal"

    ![](/img/az-ad.jpg)
    ![](/img/az-ad-guest.jpg)
    

=== "Azure PowerShell"

    ```powershell
    New-AzureADMSInvitation -InvitedUserEmailAddress someexternaluser@externaldomain.com -SendInvitationMessage $True -InviteRedirectUrl "http://myapps.onmicrosoft.com"
    ```

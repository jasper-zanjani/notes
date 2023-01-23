# Tasks

[**Cloud APIs** <sup>:material-google:</sup>](https://cloud.google.com/apis) are equivalent to Azure [**resource providers** <sup>:material-microsoft-azure:</sup>](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/azure-services-resource-providers).
Unlike Azure, which automatically registers resource providers on use, Cloud APIs must be enabled per project.

!!! gcp "GCP"
    ```sh
    gcloud services enable container.googleapis.com
    ```

!!! azure
    ```sh
    az provider register -n Microsoft.ContainerService
    ```


#### Display all available regions

!!! gcp "GCP"
    ```sh
    gcloud compute regions list
    ```

--8<-- "includes/Cloud/Tasks/CLI.md"

--8<-- "includes/Cloud/Tasks/K8s.md"

--8<-- "includes/Cloud/Tasks/Storage.md"

## 🛠&#xfe0f; Administration

Display subscription ID

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzSubscription
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az account show
    ```

### 🖥&#xfe0f; CLI

Initialize CLI utility

=== ":material-google::material-bash:"

    ```sh
    gcloud init
    ```

### IAM

Add guest user

    

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzureADMSInvitation 
        -InvitedUserEmailAddress $EMAIL 
        -SendInvitationMessage $True 
        -InviteRedirectUrl "http://myapps.onmicrosoft.com"
    ```

=== ":material-microsoft-azure::fontawesome-solid-desktop:"

    ![](/img/az-ad.jpg)
    ![](/img/az-ad-guest.jpg)

Assign a role

=== ":material-google::material-bash:"

    
    ```sh
    # At the organization level
    gcloud organizations add-iam-policy-binding 
        $ORG_ID
        --member="user:$EMAIL"
        --role="roles/compute.xpnAdmin"
    ```

    ```sh
    # At the folder level
    gcloud beta resource-manager-folders add-iam-policy-binding 
        $FOLDER_ID
        --member="user:$EMAIL"
        --role="roles/compute.xpnAdmin"
    ```

### 💰 Cost management

To view resource quotas for a subscription, go to the subscription in Azure Portal and open the **Usage + quotas** blade. From there you can select resources and then click the **Request Increase** button.

View current usage of vCPU quotas

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzVMUsage
    ```

View current usage of storage service

=== ":material-microsoft-azure::material-powershell:"

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

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Set-AzVMExtension -ResourceGroupName ExamRefRG -Location "West Europe" -VMName VM1 -Name networkWatcherAgent -Publisher Microsoft.Azure.NetworkWatcher -Type NetworkWatcherAgentWindows -TypeHandlerVersion 1.4
    ```
    
=== ":material-microsoft-azure::material-bash:"
    
    ```sh
    az vm extension set --vm-name VM1 --resource-group ExamRefRG --publisher Microsoft.Azure.NetworkWatcher --version 1.4 --name NetworkWatcherAgentWindows --extension-instance-name NetworkWatcherAgent
    ```

Start packet capture
    
=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $nw = Get-AzResource | Where ResourceType -eq "Microsoft.Network/networkWatchers" -and Location -eq "WestEurope"
    $networkWatcher = Get-AzNetworkWatcher -Name $nw.Name -ResourceGroupName $nw.ResourceGroupName
    $storageAccount = Get-AzStorageAccount -Name examref-storage -ResourceGroupName ExamRefRG
    
    $filter1 = New-AzPacketCaptureFilterConfig -Protocol TCP -RemoteIPAddress "1.1.1.1-255.255.255.255" -LocalIPAddress "10.0.0.3" -LocalPort "1-65535" -RemotePort "20;80;443"
    $filter2 = New-AzPacketCaptureFilterConfig -Protocol UDP
    $vm = Get-AzVM ` -Name VM1 -ResourceGroupName ExamRefRG
    
    New-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -TargetVirtualMachineId $vm.Id -PacketCaptureName "PacketCaptureTest" -StorageAccountId $storageAccount.id -TimeLimitInSeconds 60 -Filter $filter1, $filter2
    ```
    

=== ":material-microsoft-azure::material-bash:"

    ```sh
    filter='[ { "protocol": "TCP", "remoteIPAddress": "1.1.1.1-255.255.255.255", "localIPAddress":"10.0.0.3", "remotePort":"20" } ]'
    az network watcher packet-capture create --name PacketCaptureTest2 --resource-group ExamRefRG --vm VM1 --time-limit 300 --storage-account examref-storage --filters $filter
    ```

Check status of packet capture

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -PacketCaptureName "PacketCaptureTest"
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network watcher packet-capture show-status --name PacketCaptureTest --location WestEurope
    ```
    
Stop packet capture

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Stop-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -PacketCaptureName "PacketCaptureTest"
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network watcher packet-capture stop --name PacketCaptureTest --location WestEurope
    ```


Use **IP Flow Verify** to test outbound connectivity from source VM and port to destination. If any configured filtering rules block traffic between the endpoints, it will return the name of the offending NSG.

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Test-AzNetworkWatcherIPFlow
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network watcher test-ip-flow
    ```

Next Hop

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzNetworkWatcherNextHop
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network watcher show-next-hop
    ```

Use Network Topology

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzNetworkWatcherTopology
    ```
    
=== ":material-microsoft-azure::material-bash:"

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


### Resources

Create resource group

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzGroup -Location $location -Name $rgName
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az group create -l $location -n $rgName 
    ```

Register resource provider in subscription
```sh
az provider register --namespace 'Microsoft.PolicyInsights'
```

Move resources

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $webapp = Get-AzResource -ResourceGroupName OldRG -ResourceName ExampleSite
    $plan = Get-AzResource -ResourceGroupName OldRG -ResourceName ExamplePlan

    Move-AzResource -DestinationResourceGroupName NewRG -ResourceId $webapp.ResourceId, $plan.ResourceId
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    webapp=$(az resource show -g OldRG -n ExampleSite --resource-type "Microsoft.Web/sites" --query id --output tsv)
    plan=$(az resource show -g OldRG -n ExamplePlan --resource-type "Microsoft.Web/serverfarms" --query id --output tsv)

    az resource move --destination-group newgroup --ids $webapp $plan
    ```

Create lock on a resource

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzResourceLock 
        -LockName LockSite
        -LockLevel CanNotDelete 
        -ResourceGroupName $rg 
        -ResourceName $r 
        -ResourceType Microsoft.Web/sites 
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az lock create 
        --name LockSite
        --lock-type CanNotDelete 
        --resource-group $rg 
        --resource-name $r 
        --resource-type Microsoft.Web/sites 
    ```

Create lock on a resource group

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzResourceLock 
        -LockName LockGroup 
        -LockLevel CanNotDelete 
        -ResourceGroupName $rg
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az lock create 
        --name LockGroup 
        --lock-type CanNotDelete 
        --resource-group $rg
    ```


Display resource lock

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzResourceLock -ResourceName $r -ResourceType Microsoft.Web/sites -ResourceGroupName $rg
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az lock list --resource-group $rg --resource-name $r --namespace Microsoft.Web --resource-type sites --parent ""
    ```

Delete resource lock

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $lockId = (Get-AzResourceLock -ResourceGroupName $rg -ResourceName $r -ResourceType Microsoft.Web/sites).LockId

    Remove-AzResourceLock -LockId $lockId
    ```

=== ":material-microsoft-azure::material-bash:"

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

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    (Get-AzResource -Tag @{ CostCode="1001"}).Name
    # List all resources by tag name, with no value
    (Get-AzResource -TagName CostCode).Name
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az resource list --tag Dept=Finance
    ```

List resource groups by tag

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    (Get-AzResourceGroup -Tag @{ CostCode="1001" }).ResourceGroupName
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az group list --tag CostCode=1001
    ```

Enumerate a resource's tags

=== ":material-microsoft-azure::material-powershell:"

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


=== ":material-microsoft-azure::material-bash:"

    ```sh
    az resource show -n $resourceName -g $rgName --query tags

    # Resource group
    az group show -n $rgName --query tags
    ```

Tag resource

=== ":material-microsoft-azure::material-powershell:"

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

=== ":material-microsoft-azure::material-bash:"

    ```sh
    jsonrtag=$(az group show -n rg --query tags)
    rt=$(echo $jsonrtag | tr -d '"{},' | sed 's/: /=/g')
    az group update -n rg --tags $rt Owner=user@contoso.com
    ```



Remove specific tags

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $tags = @{"Project"="ECommerce"; "Team"="Web"}
    Update-AzTag -ResourceId $resource.id -Tag $tags -Operation Delete
    ```

Remove all tags

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $s = (Get-AzSubscription -SubscriptionName "Example Subscription").Id
    Remove-AzTag -ResourceId "/subscriptions/$s"
    
    # Alternatively
    Set-AzResourceGroup -Tag @{} -Name rg
    ```

Apply tags to resource, overwriting

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $tags = @{"Dept"="Finance"; "Status"="Normal"}
    New-AzTag -ResourceId $resource.id -Tag $tags
    ```
    ```powershell
    Set-AzResource -ResourceId $r.ResourceId -Tag @{ CostCode="1001"; Environment="Production" } -Force
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az resource tag --tags 'Dept=IT' 'Environment=Test' -g $rgName -n examplevnet --resource-type "Microsoft.Network/virtualNetworks"
    ```
    
Apply tags to resource group

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Set-AzResourceGroup -Name rg -Tag @{CostCode=1001; Environment=Production}
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az group update -n $rgName --tags 'Environment=Test' 'Dept=IT'

    # Alternatively
    az group update -n $rgName --set tags.Environment=Production tags.CostCode=1001
    ```


## Compute






### ⚓ Kubernetes

Create Kubernetes cluster

=== ":material-microsoft-azure::material-powershell:"

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
    - :material-file-document-multiple-outline: [Create a Windows Server container on an AKS cluster](https://docs.microsoft.com/en-us/azure/aks/windows-container-powershell)

=== ":material-microsoft-azure::material-bash:"

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
    - :material-file-document-multiple-outline: [Create a Windows Server container on an AKS cluster](https://docs.microsoft.com/en-us/azure/aks/windows-container-cli) 

Add a pool of nodes

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzAksNodePool -ResourceGroupName $rgName -Name npwin -ClusterName $clusterName 
        -OsType Windows 
        -KubernetesVersion 1.16.7
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az aks nodepool add -g $g -n $n --cluster-name $clusterName
        --os-type Windows
        --node-count 1
    ```

Persistent volume claim

=== ":material-microsoft-azure::material-code-json:"

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
    - :material-file-document-multiple-outline: [Source](https://docs.microsoft.com/en-us/azure/aks/concepts-storage#storage-classes)

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

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzStorageAccount -ResourceGroupName ExamRefRG -Name mystorage112300 -SkuName Standard_LRS -Location WestUS -Kind StorageV2 -AccessTier Hot
    ```

=== ":material-microsoft-azure::material-bash:"

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

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az storage account keys renew
    ```

Create Azure Key Vault

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzKeyVault -VaultName $vaultName -ResourceGroupName $g -Location $location 
    $key = Add-AzKeyVaultKey -VaultName $vaultName -Name $keyName -Destination 'Software' 
    $storageKey = Get-AzStorageAccountKey -ResourceGroupName $g -Name $storageAccount 
    $secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force
    $secret = Set-AzKeyVaultSecret -VaultName $vaultName -Name $secretName -SecretValue  $secretvalue
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az keyvault create --name $vaultName --resource-group $g --location $location
    az keyvault key create --vault-name "$vaultName" --name $keyName --protection "software"
    az keyvault secret set --vault-name "$vaultName" --name "$secretName" --value "$secretValue"
    ```

Create key in Azure Key Vault

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $key = Add-AzKeyVaultKey -VaultName $vaultName -Name $keyName -Destination 'Software'
    $storageKey = Get-AzStorageAccountKey -ResourceGroupName $g -Name $storageAccount 
    $secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force

    $secret = Set-AzKeyVaultSecret -VaultName $vaultName -Name $secretName -SecretValue $secretvalue
    ```

=== ":material-microsoft-azure::material-bash:"

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

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    # Create Storage Sync Service
    $storageSync = New-AzStorageSyncService -ResourceGroupName $g -Name $storageSyncName -Location $l

    # Create Azure File Share
    $storageKey = Get-AzStorageAccountKey -ResourceGroupName $g -Name $storageAccount 
    $context = New-AzStorageContext -StorageAccountName $storageAccount -StorageAccountKey $storageKey.Value[0]

    New-AzStorageShare -Name $shareName -Context $context
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    # Creating a Storage Sync Service resource is only possible in PowerShell or Portal
    constring=$(az storage account show-connection-string -n $storageAccountName)
    az storage share create --name $shareName --quota 2048 --connection-string $constring
    ```

Create sync group

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $syncgroup = New-AzStorageSyncGroup -Name $syncgroupname -ParentObject $storageSync
    ```

Create cloud endpoint

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzStorageSyncCloudEndpoint -Name $shareName -ParentObject $syncgroup -StorageAccountResourceId $storageAccount.Id -AzureFileShareName $shareName
    ```

### Network access

Display the status of the default NetworkRule for a storage account

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzStorageAccountNetworkRuleSet -ResourceGroupName $rgName -AccountName $n | Select-Object DefaultAction
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az storage account show -$rgName -n $n --query networkRuleSet.defaultAction
    ```
    

Set default rule

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Update-AzStorageAccountNetworkRuleSet -ResourceGroupName $g -Name $n -DefaultAction Deny
    Update-AzStorageAccountNetworkRuleSet -ResourceGroupName $g -Name $n -DefaultAction Allow
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az storage account update -g $g -n $n --default-action Deny
    az storage account update -g $g -n $n --default-action Allow
    ```

## Networking

Create virtual network with a specific prefix and subnet

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $subnet = New-AzVirtualNetworkSubnetConfig 
        -Name $subnetName 
        -AddressPrefix "10.0.0.0/24"
    $vnet = New-AzVirtualNetwork -Name $name -ResourceGroupName $rgName -Location $l 
        -AddressPrefix "10.0.0.0/16" 
        -Subnet $subnet
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network vnet create -g $rgName -n $name
        --address-prefix "10.0.0.0/16"
        --subnet-name $subnetName
        --subnet-prefix "10.0.0.0/24"
    ```

=== ":material-google::material-bash:"

    ```sh
    gcloud networks create $name --subnet-mode=custom
    gcloud beta compute networks subnets create $subnetName
        --network=$name
        --region=$l
        --range="10.0.0.0/16"
        --enable-private-ip-google-access
        --enable-flow-logs
    ```

Create peering

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Add-AzVirtualNetworkPeering 
        -Name 'peering1' 
        -VirtualNetwork $net1 
        -RemoteVirtualNetworkId $net2.Id
    
    Add-AzVirtualNetworkPeering 
        -Name 'peering2' 
        -VirtualNetwork $net2 
        -RemoteVirtualNetworkId $net1.Id
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network vnet peering create 
        -n 'peering1' 
        -g $g 
        --vnet-name net1 
        --allow-vnet-access 
        --remote-vnet net2
    
    az network vnet peering create 
        -n 'peering2' 
        -g $g 
        --vnet-name net2 
        --allow-vnet-access 
        --remote-vnet net1
    ```

=== ":material-google::material-bash:"

    ```sh
    gcloud compute networks peerings create "peering1"
        --network net1
        --peer-project $p
        --peer-network net2
        --auto-create-routes
    
    gcloud compute networks peerings create "peering2"
        --network net1
        --peer-project $p
        --peer-network net1
        --auto-create-routes
    ```

Check peering

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzVirtualNetworkPeering -ResourceGroupName $rg -VirtualNetworkName $vnetName
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network vnet peering list --resource-group $rg --vnet-name VNet1
    az network vnet peering list --resource-group $rg --vnet-name VNet2
    ```
    

User-defined routes

=== ":material-microsoft-azure::material-powershell:"

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
    

=== ":material-microsoft-azure::material-bash:"

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

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $nsgRules = @()
    $nsgRules += New-AzNetworkSecurityRuleConfig -Name "AllowingWinRMHTTP" -Description "To Enable PowerShell Remote Access" -Access Allow -Protocol Tcp -Direction Inbound -Priority 103 -SourceAddressPrefix Internet -SourcePortRange * -DestinationAddressPrefix * -DestinationPortRange 5985
    $nsgRules += New-AzNetworkSecurityRuleConfig -Name "AllowingWinRMHTTPS" -Description "To Enable PowerShell Remote Access" -Access Allow -Protocol Tcp -Direction Inbound -Priority 104 -SourceAddressPrefix Internet -SourcePortRange * -DestinationAddressPrefix * -DestinationPortRange 5986
    $nsg = New-AzNetworkSecurityGroup -Name "wscore-nsg" -ResourceGroupName "RG" -Location "East US" -SecurityRules $nsgRules
    ```
    
View rules

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzEffectiveNetworkSecurityGroup -NetworkInterfaceName $nicName -ResourceGroupName $rgName
    ```
    
=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network nic list-effective-nsg --name $nicName --resource-group $rgName
    ```
    

Create Bastion

Connecting to a VM requires at least Reader role privileges on the VM, its NIC, and on the Bastion itself.

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzBastion -ResourceGroupName $rgName -Name $n -PublicIpAddress $pip -VirtualNetwork $vnet
    ```
    
=== ":material-microsoft-azure::material-bash:"

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

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzDnsZone 
        -Name examref.com 
        -ResourceGroupName ExamRefRG
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network dns zone create 
        --name examref.com 
        --resource-group ExamRefRG
    ```


Create empty A record

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzDnsRecordSet -Name www -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords (New-AzDnsRecordConfig -IPv4Address "1.2.3.4")
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network dns record-set a create --name www --zone-name examref.com --resource-group ExamRefRG --ttl 3600
    ```

Create multiple records

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $records = @()
    $records += New-AzDnsRecordConfig -IPv4Address "1.2.3.4"
    $records += New-AzDnsRecordConfig -IPv4Address "5.6.7.8"
    New-AzDnsRecordSet -Name "@" -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords $records
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network dns record-set a add-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 1.2.3.4
    az network dns record-set a add-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 5.6.7.8
    ```

Remove record

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $recordset = Get-AzDnsRecordSet -Name www -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG
    Add-AzdnsRecordConfig -RecordSet $recordset -IPv4Address "5.6.7.8"
    Remove-AzDnsRecordConfig -RecordSet $recordset -IPv4Address "1.2.3.4"
    Set-AzDnsRecordSet -RecordSet $recordset
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network dns record-set a remove-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 1.2.3.4
    ```

Read records

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    Get-AzDnsRecordSet -ZoneName examref.com -ResourceGroupName ExamRefRG
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network dns record-set list --zone-name examref.com --resource-group ExamRefRG -o table 
    ```

Create a virtual network with custom DNS settings

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    New-AzVirtualNetwork -Name VNet1 -ResourceGroupName $rgName -Location $location 
        -AddressPrefix 10.1.0.0/16 -Subnet (New-AzVirtualNetworkSubnetConfig -Name Default -AddressPrefix 10.1.0.0/24)
        -DNSServer 10.0.0.4,10.0.0.5 
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network vnet create --name VNet1 --resource-group $rgName 
        --address-prefixes 10.0.0.0/16 
        --dns-servers 10.0.0.4 10.0.0.5
    ```



Modify the DNS server configuration of an existing VNET

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $vnet = Get-AzVirtualNetwork -Name $vnetName -ResourceGroupName $rgName
    $vnet.DhcpOptions.DnsServers.Clear()
    $vnet.DhcpOptions.DnsServers.Add("10.10.200.1")
    $vnet.DhcpOptions.DnsServers.Add("10.10.200.2")
    Set-AzVirtualNetwork -VirtualNetwork $vnet
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network vnet update --name $vnetName --resource-group $rgName 
        --dns-servers 10.10.200.1 10.10.200.2
    ```


Restart the VMs in the VNet to pick up the DNS change

=== ":material-microsoft-azure::material-powershell:"

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

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network vnet update --name VNet1 --resource-group ExamRefRG --remove DHCPOptions.DNSServers
    ```

Set custom DNS servers on a NIC

=== ":material-microsoft-azure::material-bash:"

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

=== ":material-microsoft-azure::material-powershell:"

    ```powershell
    $publicIP = New-AzPublicIpAddress -Name ExamRefLB-IP -ResourceGroupName $g -Location $location -AllocationMethod Static 
    $frontendIP = New-AzLoadBalancerFrontendIpConfig -Name frontend -PublicIpAddress $publicIP
    $beAddressPool = New-AzLoadBalancerBackendAddressPoolConfig -Name backend
    $healthProbe = New-AzLoadBalancerProbeConfig -Name -RequestPath '/' -Protocol http -Port 80

    $lbrule = New-AzLoadBalancerRuleConfig -Name -FrontendIpConfiguration $frontendIP -BackendAddressPool $beAddressPool -Probe $healthProbe -Protocol Tcp -FrontendPort 80 -BackendPort 80
    $lb = New-AzLoadBalancer -ResourceGroupName -Name -Location -FrontendIpConfiguration $frontendIP -LoadBalancingRule $lbrule -BackendAddressPool $beAddressPool -Probe $healthProbe
    ```

=== ":material-microsoft-azure::material-bash:"

    ```sh
    az network public-ip create --name ExamRefLB-IP --resource-group ExamRefRG --location --allocation-method Static
    az network lb create --name ExamRefLB --resource-group ExamRefRG --location --backend-pool-name backend --frontend-ip-name frontend --public-ip-address ExamRefLB-IP
    az network lb probe create --resource-group ExamRefRG --name HealthProbe --lb-name ExamRefLB --protocol http --port 80 --path / --interval 5 --threshold 

    az network lb rule create --name ExamRefRule --lb-name ExamRefLB --resource-group ExamRefRG --protocol Tcp --frontend-port 80 --backend-port 80 --frontend-ip-name ExamRefFrontEnd --backend-pool-name backend --probe-name HealthProbe
    ```

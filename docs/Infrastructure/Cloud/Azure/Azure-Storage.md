
### DNS


## Storage account access


### SAS token

SAS tokens are generated from a storage account key; if the key is invalidated then so are all SAS tokens generated from it. The user delegation SAS token itself is meant to be **appended** to the end of the blob's URI.<sup>[CloudSkills](https://portal.cloudskills.io/products/azure-administrator-az-104-exam-prep-course/categories/2692678/posts/8980118 "Manage storage accounts"): 40:00</sup>

# Tasks


### Add endpoints to Azure File Sync Group

1. Register a server to the sync group by installing **Azure File Sync agent** on each server. When installing, you sign in with your subscription's credentials, then register the server by providing the Subscription, Resource Group, and Storage Sync Service names.
2. Click **Add Server Endpoint**. This will display a dropdown of all servers with the agent installed and associated with the sync service.

```sh title="Upload blob"
az storage blob upload --container-name $containerName --account-name $accountName --account-key $accountKey --file $file --name $blobName
    
AzCopy copy localFilePath https://storageAccount.blob.core.windows.net/destinationContainer/path/to/blob?SASToken
```
    
```cmd
:: Download a blob from a container
AzCopy copy https://storageAccount.blob.core.windows.net/sourceContainer/path/to/blob?SASToken localFilePath

:: Copy a blob from one container to another
AzCopy /Source:https://sourceblob.blob.core.windows.net/sourcecontainer/ 
    /Dest:https://deststorage.blob.core.windows.net/destcontainer/ 
    /SourceKey:sourcekey /DestKey:destkey /Pattern:disk1.vhd
```
    

```powershell
$blobCopyState = Start-AzStorageBlobCopy -SrcBlob $blobName -SrcContainer $srcContainer -Context $srcContext -DestContainer $destContainer -DestBlob $vhdName -DestContext $destContext
$srcStorageKey = Get-AzStorageAccountKey -ResourceGroupName $sourceg -Name $srcStorageAccount
$destStorageKey = Get-AzStorageAccountKey -ResourceGroupName $destg -Name $destStorageAccount
$srcContext = New-AzStorageContext -StorageAccountName $srcStorageAccount -StorageAccountKey $srcStorageKey.Value[0]
$destContext = New-AzStorageContext -StorageAccountNAme $destStorageAccount -StorageAccountKey $destStorageKey.Value[0]

# Create new container in destination account
New-AzStorageContainer -Name $destContainer -Context $destContext

# Make the copy
$copiedBlob = Start-AzStorageBlobCopy -SrcBlob $blobName -SrcContainer $srcContainer -Context $srcContext -DestContainer $destContainer -DestBlob $blobName -DestContext $destContext
```
```sh
az storage blob copy start --account-name $destStorageAccount --account-key $destStorageKey --destination-blob $blobName --source-account-name $srcStorageAccount --source-container $srcContainer --source-blob $blobName --source-account-key $srcStorageKey
```

### Monitor progress of the async blob copy
```powershell
$copiedBlob | Get-AzStorageBlobCopyState
```
```sh
az storage blob show --account-name $destStorageAccount --account-key $destStorageKey --container-name $destContainer --name $blobName
```
### Create SAS token
```powershell
$storageKey = Get-AzStorageAccountKey -ResourceGroupName $g -Name $accountName
$context = New-AzStorageContext -StorageAccountName $accountName -StorageAccountKey $storageKey[0].Value
$startTime = Get-Date
$endTime = $startTime.AddHours(4)

New-AzStorageBlobSASToken -Container $container -Blob $blob -Permission "rwd" -StartTime $startTime -ExpiryTime $startTime.AddHours(4) -Context $context
```
```sh
az storage blob generate-sas --account-name "storageAccount" --account-key $storageAccountKey --container-name $container --name $blobName --permissions r --expiry "2019-05-31"
```

### Create container

```powershell
$storageKey = Get-AzStorageAccountKey -Name $storageAccount -ResourceGroupName $resourceGroup
$context = New-AzStorageContext -StorageAccountName $storageAccount -StorageAccountKey $storageKey.Value[0]
Set-AzCurrentStorageAccount -Context $context

New-AzStorageContainer -Name $container -Permission Off
```

Upload file as blob to new container

=== "Azure PowerShell"

    ```powershell
    Set-AzStorageBlobContent -File $localFile -Container $container -Blob $blobName
    ```
    
=== "Azure CLI"

    ```sh
    az storage container create --account-name $storageaccount --name $containername --public-access off
    ```
    

### Ensure App Services, backup vault, and event hub have access to a storage account

```powershell
Get-AzVirtualNetwork -ResourceGroupName RG01 -Name VNET01 |
Set-AzVirtualNetworkSubnetConfig -Name VSUBNET01 -AddressPrefix 10.0.0.0/24 -ServiceEndpoint Microsoft.Storage |
Set-AzVirtualNetwork

$subnet = Get-AzVirtualNetwork -ResourceGroupName RG01 -Name VNET01 |
Get-AzVirtualNetworkSubnetConfig -Name VSUBNET01
Add-AzStorageAccountNetworkRule -ResourceGroupName VNET01 -Name Storage01 -VirtualNetworkResourceId $subnet.Id
Update-AzStorageAccountNetworkRuleSet -ResourceGroupName RG01 -Name STORAGE01 -Bypass Azure.Services
```

### Troubleshoot Azure File Sync

Several procedures to be used when Azure File Sync is having issues

Collect logs to troubleshoot issues with Azure File Sync agent installation
```
StorageSyncAgent.msi /l*v AFSInstaller.log
```
Remove the server from registered sync group
Error message "This server is already registered during registration"
```powershell
Import-Module "C:\Program Files\Azure\StorageSyncAgent\StorageSync.Management.ServerCmdlets.dll"
Reset-StorageSyncServer
```

### Monitoring using Log Analytics
Access Activity Log data (Portal)
1. Find **Management + Governance** in **All Services**
2. Open **Activity Log**
3. Click Logs icon at top of Activity Log view to select an existing Log Analytics (OMS) workspace or create a new one

### Storage account endpoints

#### Virtual network service endpoint

Sources
- AZ-103 p. 112
- [Configure Azure Storage firewalls and virtual networks](https://docs.microsoft.com/en-us/azure/storage/common/storage-network-security)

![](/img/az-vnet-endpoint.jpg)

1. Specify `Microsoft.Storage` in the service endpoint settings of the VNet subnet
2. Configure which VNets can access a particular storage account

Display virtual network rules

=== "Azure PowerShell"

    ```powershell
    Get-AzStorageAccountNetworkRuleSet -ResourceGroupName $rgName -AccountName $n | Select-Object VirtualNetworkRules
    ```

=== "Azure CLI"

    ```sh
    az storage account network-rule list -g $rgName -n $n --query virtualNetworkRules
    ```

Enable service endpoint for Azure Storage on an existing virtual network and subnet.

=== "Azure PowerShell"

    ```powershell
    Get-AzVirtualNetwork -ResourceGroupName $rgName -Name $n | Set-AzVirtualNetworkSubnetConfig -Name "mysubnet" -AddressPrefix "10.0.0.0/24" -ServiceEndpoint "Microsoft.Storage" |   Set-AzVirtualNetwork
    ```

=== "Azure CLI"

    ```sh
    az network vnet subnet update -g $rgName --vnet-name $n --name "mysubnet" --service-endpoints "Microsoft.Storage"
    ```


Add network rule for VNet and subnet

=== "Azure PowerShell"

    ```powershell
    $subnet = Get-AzVirtualNetwork -ResourceGroupName $ng -Name $nn | Get-AzVirtualNetworkSubnetConfig -Name "mysubnet"
    
    Add-AzStorageAccountNetworkRule -ResourceGroupName $sg -Name $sn -VirtualNetworkResourceId $subnet.Id
    ```


=== "Azure CLI"

    ```sh
    subnetid=$(az network vnet subnet show -g $ng --vnet-name $nn -n "mysubnet" --query id --output tsv)
    az storage account network-rule add -g $sg -n $sn --subnet $subnetid
    ```
    
Remove network rule

    ```powershell
    $subnet = Get-AzVirtualNetwork -ResourceGroupName $ng -Name $nn | 
        Get-AzVirtualNetworkSubnetConfig -Name "mysubnet"

    Remove-AzStorageAccountNetworkRule -ResourceGroupName $sg -Name $sn -VirtualNetworkResourceId $subnet.Id
    ```

Bypass network rules to allow access for Azure services like Event Hub and Recovery Services Vault

=== "Azure PowerShell"

    ```powershell
    # Display exceptions for the storage account network rules
    Get-AzStorageAccountNetworkRuleSet -ResourceGroupName $g -Name $n | Select-Object Bypass
    # Configure exceptions to storage account network rules
    Update-AzStorageAccountNetworkRuleSet -ResourceGroupName $g -Name $n -Bypass AzureServices,Metrics,Logging
    ```

=== "Azure CLI"

    ```sh
    # Display exceptions for the storage account network rules
    az storage account show -g $g -n $n --query networkRuleSet.bypass
    # Configure exceptions to storage account network rules
    az storage account update -g $g -n $n --bypass Logging Metrics AzureServices
    ```


- [Configure Azure Storage firewalls and virtual networks](https://docs.microsoft.com/en-us/azure/storage/common/storage-network-security)
- AZ-103: p. 107, 114, 127
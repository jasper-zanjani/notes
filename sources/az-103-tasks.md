# Exam Ref AZ-103 Microsoft Azure Administrator, by Michael Washam, Jonathan Tuliani, and Scott Hoag
## Tasks
###  1       Manage Azure subscriptions and resource
#### 1.1a.1: Assign an RBAC role (Portal)
To assign an RBAC role to a subscription, open the __Subscription__, then the __Access Control (IAM)__ blades, then click __Add Role Assignment__. This will open a dialog box where you can select a __Role__ (e.g. Owner) then __Select__ a target principal.
#### 1.1b.1: Configure resource quotas
To view resource quotas for a subscription, go to the subscription in Azure Portal and open the __Usage + quotas__ blade. From there you can select resources and then click the __Request Increase__ button. PowerShell commands used with resource quotas:
```powershell
# View current usage of vCPU quotas
Get-AzVMUsage
```
```powershell
# View current usage of storage service
Get-AzStorageUsage
``` 
#### 1.1b.2 Configure cost center quotas
Budgets can be viewed and administered in the __Cost Management + Billing__ blade. Users must be at least Reader to a subscription to view, and Contributor to create and manage, budgets. Specialized roles that grant access to Cost Management include
  - __Cost Management contributor__
  - __Cost Management reader__ \
To create a budget, open __Cost Management + Billing__, then __Subscriptions__, select a subscription, then click __Budgets__. Then click __+ Add__, which produces a Create budget blade. The created budget can be seen in the __Budgets__ blade. PowerShell commands used with budgets:
  - `Get-AzResourceGroup` retrieve Resource Group object
  - `Set-AzResourceGroup` apply a tag to a resource group with __no preexisting tags__
  - `.Tags` method that retrieves Tag collection from a resource group
  - `.Add()` method used to add tags to a resource group that __already has__ tags.
#### 1.1b.3: Tag a resource group with no existing tags (PowerShell)
```powershell
Set-AzResourceGroup -Name hrgroup -Tag @{CostCode=1001; Environment=Production}
```
#### 1.1b.4: Tag a resource group with existing tags (PowerShell)
```powershell
$tags = (Get-AzResourceGroup -Name hrgroup).Tags
$tags.Add("Owner", "user@contoso.com")
Set-AzResourceGroup -Tag $tags -Name hrgroup
```
#### 1.1b.5: Tag a resource with no existing tags (PowerShell)
```powershell
$r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName hrgroup
Set-AzResource -Tag @{ CostCode="1001"; Environment="Production" } -ResourceId $r.ResourceId -Force
```
#### 1.1b.6: Tag a resource with existing tags (PowerShell)
```powershell
$r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName hrgroup
$r.Tags.Add("Owner", "user@contoso.com")
Set-AzResource -Tag $r.Tags -ResourceId $r.ResourceId -Force
```
#### 1.1b.7: Remove tags from a resource group (PowerShell)
```powershell
Set-AzResourceGroup -Tag @{} -Name hrgroup
```
#### 1.1b.8: Retrieve resource groups with a specific tag (PowerShell)
```powershell
(Get-AzResourceGroup -Tag @{ Owner="user@contoso.com" }).ResourceGroupName
```
#### 1.1b.9: Retrieve resources with a specific tag (PowerShell)
```powershell
(Get-AzResource -Tag @{ Owner="user@contoso.com"}).Name
```
#### 1.1b.10: Retrieve resources based on a tag name but no value (PowerShell)
```powershell
(Get-AzResource -TagName CostCode).Name
```
#### 1.1c.1: Create a policy definition (Portal)
Open __All Services__, then __Policy__, then the __Definitions__ blade. Both builtin and custom policies can be managed here.
#### 1.1c.2: Register resource provider in subscription (Azure CLI)
```sh
az provider register --namespace 'Microsoft.PolicyInsights'
```
#### 1.1c.3: Define a policy (Azure CLI)
```sh
az policy definition create --name 'allowedVMs' --description 'Only allow virtual machines in the defined SKUs' --mode ALL --rules '{...}' --params '{...}'
```
#### 1.1c.4: Apply policy to a scope (Azure CLI)
```sh
az policy assignment create --policy allowedVMs --name 'deny-non-compliant-vms' --scope '/subscriptions/<Subscription ID>' -p
```
#### 1.1c.5 Delete policy assignment (Azure CLI)
```sh
az policy assignment delete --name deny-non-compliant-vms
```
#### 1.2a.1 Enable diagnostics log collection with a storage account (Portal)
Browse to the resource itself. Alternatively, open __Azure Monitor__ and then the __Diagnostics Settings__ blade. From there you can view all eligible resouce types and view status of log collection. 
#### 1.2a.2 Enable diagnostics log collection with a storage account (PowerShell)
`Set-AzDiagnostic-Setting` requires resource ID of resource being enabled (can be found with `Get-AzResource`) and resource ID of storage account (passed to `StorageAccountId` parameter).
```powershell
$resource = Get-AzResource -Name $resourceName -ResourceGroupName $resourceGroupName
$storage = Get-AzResource -Name $resourceName -ResourceGroupName $resourceGroupName
Set-AzDiagnosticSetting -ResourceId $resource.ResourceId -StorageAccountId $storage.ResourceId -Enabled $true
```
#### 1.2a.3 Enable diagnostics log streaming to an Event Hub (PowerShell) 
```powershell
$rule = Get-AzServiceBusRule -ResourceGroup $resourceGroupName -Namespace $namespace -Topic $topic -Subscription $subscription -Name $ruleName
Set-AzDiagnosticSetting -ResourceId $resource.ResourceId -ServiceBusRuleId $rule.Id -Enabled $true
```
#### 1.2a.4 Enable diagnostics logs collection in a Log Analytics workspace (PowerShell)
```powershell
$workspace = Get-AzOperationalInsightsWorkspace -Name $workspaceName -ResourceGroupName $resourceGroupName
Set-AzDiagnosticSetting -ResourceId $resource.ResourceId -WorkspaceId $workspace.ResourceId -Enabled $true
```
#### 1.2a.5 Obtain resource ID (Azure CLI)
`az monitor diagnostic-settings create` to enable diagnostic logs. `az resource show` to obtain resource ID.
```sh
resourceId=$(az resource show -resource-group $resourceGroupName -name $resourceName --resource-type $resourceType --query id --output tsv)
```
#### 1.2a.6 Enable diagnostics log collection with a storage account (Azure CLI)
```sh
az monitor diagnostic-settings create --name $diagnosticName --storage-account $storageId --resource $resouceId --resource-group $resourceGroup \
  --logs '[ {
    "category": <categoryName>,
    "enabled": true,
    "retentionPolicy": {
      "days": <numberOfDays>,
      "enabled": true } } ] '
```
#### 1.2a.7 Enable diagnostics log streaming to an Event Hub (Azure CLI)
```sh
az monitor diagnostic-settings create --name $diagnosticName --event-hub $eventHubName --event-hub-rule $eventHubRuleId --resource $targetResourceId \
  --logs '[{
    "category": <categoryName>,
    "enabled": true }]'
```
#### 1.2a.8 Enable diagnostics logs collection in a Log Analytics workspace (Azure CLI)
```sh
az monitor diagnostic-settings create --name $diagnosticName --workspace $logAnalyticsName --resource $resourceId --resouce-group $resourceGroup \
  --logs '[{
    "category": <categoryName>,
    "enabled": true }]'
```
#### 1.2b.1 Create an alert rule (Portal)
1. **Alerts**
2. **New Alert Rule** button
#### 1.2g.1 Enable Cloudyn (Portal)
1. Open **Cost Management + Billing**
2. Open **Cost Management**
3. Click Cloudyn
4. Register with Cloudyn
#### 1.3.1 Delete a resource group (PowerShell)
```powershell
Remove-AzResourceGroup -Name $resourceGroup
```
#### 1.3.2 Delete a resource group without confirmation (PowerShell)
```powershell
Remove-AzResourceGroup -Name $resourceGroup -Force
```
#### 1.3.3 Delete a resource group (CLI)
```sh
az group delete --name $resourceGroup
```
#### 1.3.4 Delete a resource group without confirmation (CLI)
```sh
az group delete --name $resourceGroup --yes
```
#### 1.4b.1: Retrieve the definition of a role (PowerShell)
```powershell
Get-AzRoleDefinition -Name "Virtual Machine Contributor" | ConvertTo-Json
```
#### 1.4b.2: Retrieve the definition of a role (Azure CLI)
```sh
az role definition list -n "Virtual Machine Contributor"
```
#### 1.4b.3: Retrieve operations that support `DataActions` and `NotDataActions` (PowerShell)
```powershell
Get-AzProviderOperation * |? { $_.IsDataAction -eq $true }
```
#### 1.4c.1: Assign a role to a user (Portal)
1. Navigate to resource group
2. Open Access Control (IAM)
3. Open **Role Assignments** tab
4. Click **Add**
5. Select **Add Role Assignment**
#### 1.4c.2: Remove a role assignment (Portal)
1. Navigate to resource group
2. Open Access Control (IAM)
3. Open **Role Assignments** tab
4. Select one or more security principals and click **Remove**
#### 1.4c.3: List roles available for assignment (PowerShell)
```powershell
Get-AzRoleDefinition | Where-Object { $_.IsCustom -eq $true }
```
#### 1.4c.4: List custom roles available for assignment (Azure CLI)
```sh
az role definition list --custom-role-only -o table
```
#### 1.4c.5: View all role assignments in a subscription (Azure CLI)
```sh
az role assignment list --all
```
#### 1.4c.6: Grant a user RBAC rights (PowerShell)
```powershell
New-AzRoleAssignment -SignInName "cloudadmin@opsgility.onmicrosoft.com" -RoleDefinitionName "Virtual Machine Contributor" -ResourceGroupName ExamRefRG
```
#### 1.4c.7: Grant a user RBAC rights (Azure CLI)
```sh
az role assignment create --assignee "cloudadmin@opsgility.onmicrosoft.com" --role "Virtual Machine Contributor" --resource-group ExamRefRG
```
#### 1.4c.8: Grant a group RBAC rights (PowerShell)
```powershell
$group = Get-AzADGroup -SearchString "Cloud Admins"
New-AzRoleAssignment -ObjectId $group.Id -RoleDefinitionName "Virtual Machine Contributor" -ResourceGroupName ExamRefRG
```
#### 1.4c.9: Grant a group RBAC rights (Azure CLI)
```sh
groupid=$(az ad group list --query "[?displayName=='Cloud Admins'].objectId" -o tsv)
az role assignment create --role "Virtual Machine Contributor" --assignee-object-id $groupid --resource-group ExamRefRG
```
#### 1.4c.10: Remove RBAC assignments from a user (PowerShell)
```powershell
Remove-AzRoleAssignment -SignInName "cloudadmin@opsgility.onmicrosoft.com" -RoleDefinitionName "Virtual Machine Contributor" -ResourceGroupName ExamRefRG
```
#### 1.4c.11: Remove RBAC assignments from a group (PowerShell)
```powershell
$group = Get-AzADGRoup -SearchString "Cloud Admins"
Remove-AzRoleAssignment -ObjectId $group.Id -RoleDefinitionName "Virtual Machine Contributor" -ResourceGroupName ExamRefRG
```
#### 1.4c.12: Remove RBAC assignments from a user (Azure CLI)
```sh
az role assignment delete --role "Virtual Machine Contributor" --assignee "cloudadmin@opsgility.onmicrosoft.com" --resource-group ExamRefRG
```
#### 1.4c.13: Remove RBAC assignments from a group (Azure CLI)
```sh
groupid=$(az ad group list --query "[?displayName=='CloudAdmins'].objectId" -o tsv)
az role assignment delete --role "Virtual Machine Contributor" --assignee-object-id $groupid --resource-group ExamRefRG
```
###  2       Implement and manage storage
#### 2.1a.1: Create a storage account (Portal)
Click **Create a resouce**, then **Storage**, then **Storage account**. Choose a **globally** unique name for the account, containing lower-case characters and digits only.
#### 2.1a.2: Create a storage account (PowerShell)
```powershell
New-AzStorageAccount -ResourceGroupName ExamRefRG -Name mystorage112300 -SkuName Standard_LRS -Location WestUS -Kind StorageV2 -AccessTier Hot
```
#### 2.1a.3: Create a storage account (CLI)
```sh
az storage account create --name $accountName --resource-group $resourceGroup -location $location --sku $sku
```
#### 2.1a.4: Change storage account's access tier, without confirmation (PowerShell)
```powershell
Set-AzStorageAccount -ResourceGroupName RG -Name $accountName -AccessTier Cool -Force
```
#### 2.1b.1: Configure service endpoints (Portal)
1. Specify `Microsoft.Storage` in the service endpoint settings of the VNet subnet
2. Configure which VNets can access a particular storage account
#### 2.1c.1: Access storage account name and key (Portal)
1. Open storage account
2. Open **Access keys** blade
#### 2.1c.2: Create an Azure Key Vault (PowerShell)
```powershell
New-AzKeyVault -VaultName $vaultName -Name $keyName -ResourceGroupName $rgName -Location $location
```
#### 2.1c.3: Store a software managed key in Azure Key Vault (PowerShell)
```powershell
$key = Add-AzKeyVaultKey -VaultName $vaultName -Name $keyName -Destination 'Software'
```
#### 2.1c.4: Retrieve a storage account key (PowerShell)
```powershell
$storageKey = Get-AzStorageAccountKey -ResourceGroupName $rgName -Name $storageAccount 
```
#### 2.1c.5: Convert storage account key to secure string
```powershell
$secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force
```
#### 2.1c.6: Set secret value to be used in Azure Key Vault (PowerShell)
```powershell
$secret = Set-AzKeyVaultSecret -VaultName $vaultName -Name $secretName -SecretValue $secretvalue
```
#### 2.1c.7: Create an Azure Key Vault (Azure CLI)
```sh
az keyvault create --name $vaultName --resource-group $rgName --location $location
```
#### 2.1c.8: Store a software managed key in Azure Key Vault (Azure CLI)
```sh
az keyvault key create --vault-name $vaultName --name $keyName --protection "software"
```
#### 2.1c.9: Set secret value to be used in Azure Key Vault (Azure CLI)
```sh
az keyvault secret set --vault-name $vaultName --name $secretName --value $secretValue
```
#### 2.1d.1: Create a SAS token for a specific storage blob (PowerShell)
```powershell
$storageKey = Get-AzStorageAccountKey -ResourceGroupName $rgName -Name $accountName
$context = New-AzStorageContext -StorageAccountName $accountName -StorageAccountKey $storageKey[0].Value
$startTime = Get-Date
$endTime = $startTime.AddHours(4)

New-AzStorageBlobSASToken -Container $container -Blob $blob -Permission "rwd" -StartTime $startTime -ExpiryTime $startTime.AddHours(4) -Context $context
```
#### 2.1d.2: Create a SAS token for a specific storage blob (Azure CLI)
```sh
az storage blob generate-sas --account-name "storageAccount" --account-key $storageAccountKey --container-name $container --name $blobName --permissions r --expiry "2019-05-31"
```
#### 2.1e.1: Access Activity Log data (Portal)
1. Find **Management + Governance** in **All Services**
2. Open **Activity Log**
3. Click Logs icon at top of Activity Log view to select an existing Log Analytics (OMS) workspace or create a new one
#### 2.1f.1: Change replication mode of a storage account (PowerShell)
```powershell
Set-AzStorageAccount -ResourceGroupName $resourceGroup -Name $accountName -SkuName $type
```
#### 2.1f.2: Use async blob copy service to copy a file (PowerShell)
```powershell
$blobCopyState = Start-AzStorageBlobCopy -SrcBlob $blobName -SrcContainer $srcContainer -Context $srcContext -DestContainer $destContainer -DestBlob $vhdName -DestContext $destContext
```
```powershell
# Get storage account keys
$srcStorageKey = Get-AzStorageAccountKey -ResourceGroupName $sourceRGName -Name $srcStorageAccount
$destStorageKey = Get-AzStorageAccountKey -ResourceGroupName $destRGName -Name $destStorageAccount
```
```powershell
# Create storage account contexts
$srcContext = New-AzStorageContext -StorageAccountName $srcStorageAccount -StorageAccountKey $srcStorageKey.Value[0]
$destContext = New-AzStorageContext -StorageAccountNAme $destStorageAccount -StorageAccountKey $destStorageKey.Value[0]
```
```powershell
# Create new container in destination account
New-AzStorageContainer -Name $destContainer -Context $destContext
```
```powershell
# Make the copy
$copiedBlob = Start-AzStorageBlobCopy -SrcBlob $blobName -SrcContainer $srcContainer -Context $srcContext -DestContainer $destContainer -DestBlob $blobName -DestContext $destContext
```
#### 2.1f.3: Monitor progress of the async blob copy (PowerShell)
```powershell
$copiedBlob | Get-AzStorageBlobCopyState
```
#### 2.1f.4: Copy a blob from one storage account to another (Azure CLI)
```sh
az storage blob copy start --account-name $destStorageAccount --account-key $destStorageKey --destination-blob $blobName --source-account-name $srcStorageAccount --source-container $srcContainer --source-blob $blobName --source-account-key $srcStorageKey
```
#### 2.1f.5: Monitor progress of the async blob copy (Azure CLI)
```sh
az storage blob show --account-name $destStorageAccount --account-key $destStorageKey --container-name $destContainer --name $blobName
```
#### 2.1f.6: Use AzCopy to copy a blob
```cmd
AzCopy /Source:https://sourceblob.blob.core.windows.net/sourcecontainer/ /Dest:https://deststorage.blob.core.windows.net/destcontainer/ /SourceKey:sourcekey /DestKey:destkey /Pattern:disk1.vhd
```
#### 2.2a.1: Create a storage container (PowerShell)
```powershell
# Get account key
$storageKey = Get-AzStorageAccountKey -Name $storageAccount -ResourceGroupName $resourceGroup
```
```powershell
# Create and store the storage context
$context = New-AzStorageContext -StorageAccountName $storageAccount -StorageAccountKey $storageKey.Value[0]
Set-AzCurrentStorageAccount -Context $context
```
```powershell
# Create storage container
New-AzStorageContainer -Name $container -Permission Off
```
```powershell
# Create storage blob
Set-AzStorageBlobContent -File $localFile -Container $container -Blob $blobName
```
#### 2.2a.2: Create a storage container (Azure CLI)
`az storage container create` parameters:
  - `public-access` used to set permissions: values include 
    - `off` 
    - `blob`
    - `container`
```sh
az storage container create --account-name $storageaccount --name $containername --public-access off
```
#### 2.2a.3: Upload a file (Azure CLI)
`az storage blob upload` is used to upload a file
```sh
az storage blob upload --container-name $containerName --account-name $accountName --account-key $accountKey --file $file --name $blobName
```
#### 2.2a.4: Download a blob from a container (AzCopy)
```cmd
AzCopy copy https://storageAccount.blob.core.windows.net/sourceContainer/path/to/blob?SASToken localFilePath
```
#### 2.2a.5: Upload a blob to a container (AzCopy)
```cmd
AzCopy copy localFilePath https://storageAccount.blob.core.windows.net/destinationContainer/path/to/blob?SASToken
```
#### 2.2b.1: Export data (Portal)
1. From **All Services** open **Import/Export Jobs**
2. Open **Create Import/Export Job**
3. Select **Basics** tab
4. Choose **Export From Azure**, specifying job name and resource group to contain the job
5. Select **Job Details** tab
6. Select which storage account to export from and choose blobs to export.
7. Select **Return Shipping Info**
8. Specify carrier information and address for disks to be shipped to
9. Select **Summary** tab
10. Click OK
#### 2.2c.1: Import data
1. Install Azure Import/Export tool
2. Prepare drives and copy data to drives. Specify destination storage account key, BitLocker key (available from Portal), and log directory, among other parameters, in the first session
```cmd
WAImportExport.exe PrepImport \
  /j:JournalFile \
  /id:SessionId \
  /logdir:LogDirectory \
  /t:SourceDriveLetter \
  /srcdir/SourceFolder \
  /dstdir:DestinationPath
```
3. Create an import job through the Portal
#### 2.2c.2: Create an import job (Portal)
1. From **All Services** open **Import/Export Jobs**
2. Open **Create Import/Export Job**
3. Select **Basics** tab
4. Select **Import into Azure**, specifying job name and resource group to contain the job
5. Select **Job Details** tab
6. Choose journal file created with the Import/Export Tool
7. Select **Return Shipping Info**
8. Specify carrier information and return address
9. Select **Summary** tab
10. Click OK
11. Physically ship disks to Microsoft
#### 2.2e.1: Publish content in a CDN endpoint (Portal)
1. Create a new CDN profile
2. Add an endpoint to the profile
#### 2.2e.2: Create a new CDN profile (Portal)
1. Click **Create a resource** 
2. Click **Web**
3. Click **CDN**, opening the CDN profile blade
4. Specify name for the profile, name of the resource group, region, and pricing tier.
5. Click **Create**
#### 2.2e.3: Add an endpoint to a CDN profile (Portal)
1. Open the CDN Profile
2. Click **+ Endpoint** button
3. Specify unique name, configuration for origin settings such as type, host header, and origin port for HTTP and HTTPS.
4. Click **Add** button
#### 2.3a.1: Create an Azure File Share (Portal)
1. Open a standard Azure storage account (not premium)
2. **Files**
3. **+ File Share** button
#### 2.3a.2: Create an Azure File Share (PowerShell)
```powershell
# Get key of storage account
$storageKey = Get-AzStorageAccountKey -ResourceGroupName $rgName -Name $storageAccount 
# Get context from storage key
$context = New-AzStorageContext -StorageAccountName $storageAccount -StorageAccountKey $storageKey.Value[0]
# Create the file share with the context
New-AzStorageShare -Name $shareName -Context $context
```
#### 2.3a.3: Create an Azure File Share (CLI)
```powershell
# Get the connection string associated with the account
constring=$(az storage account show-connection-string -n $storageAccountName)
# Create the file share with the connection string
az storage share create --name $shareName --quota 2048 --connection-string $constring
```
#### 2.3a.4: Connect to and mount an Azure File Share (Windows File Explorer)
1. Right-click on **This PC**
2. Click **Map Network Drive** option
3. Specify drive letter to be used 
4. Specify folder: `\\<storageAccount>.files.core.windows.net\<shareName>`
5. Click **Finish**
6. In the dialog box that opens login with the username: `AZURE\<storageName>`
7. Password should be access key for the storage account
#### 2.3a.5: Connect to and mount an Azure File Share (net use command)
```cmd
net use x \\erstandard01.file.core.windows.net\logs /u:AZURE\erstandard01 <accessKey>
```
#### 2.3a.6: Connect to and mount an Azure File Share (PowerShell)
`New-PSDrive` maps the drive
```powershell
$storageKey = (Get-AzStorageAccountKey -ResourceGroupName $rgName -Name $storageNAme).Value[0]
$acctKey = ConvertTo-SecureString -String $storageKey -AsPlainText -Force
$credential = New-Object System.Management.Automation.PSCredential -ArgumentList "Azure\$storageName", $acctKey
New-PSDrive -Name "Z" -PSProvider FileSystem -Root "\\$storageName.file.core.windows.net\$shareName" -Credential $credential
```
#### 2.3a.7: Automatically reconnect after reboot in Windows
```
cmdkey /add:storageAccountName.file.core.windows.net /user:AZURE\storageAccountName /pass:storageAccountKey
```
#### 2.3a.8: Connect to and mount an Azure File Share (Linux)
Mounting to `/logs`
```sh
sudo mount -t cifs //$storageAccount.file.core.windows.net/logs /logs -o "vers=3.0,username=$storageAccount,password=$storageAccountKey,dir_mode=0777,file_mode=0777,sec=ntlmssp"
```
#### 2.3b.1: Create the Azure File Sync Service (Portal)
Create a resource **Storage** **Azure File Sync**
#### 2.3c.1: Create a sync group (Portal)
Specify name of sync group in dialog after creating an Azure File Sync (2.3b.1)
#### 2.3c.2: Add endpoints to Azure File Sync Group (Portal)
1. Register a server to the sync group by installing **Azure File Sync agent** on each server. When installing, you sign in with your subscription's credentials, then register the server by providing the Subscription, Resource Group, and Storage Sync Service names.
2. Click **Add Server Endpoint**. This will display a dropdown of all servers with the agent installed and associated with the sync service.
#### 2.3d.1: Collect logs to troubleshoot issues with Azure File Sync agent installation
```
StorageSyncAgent.msi /l*v AFSInstaller.log
```
#### 2.3d.2: Remove the server from registered sync group
Error message "This server is already registered during registration"
```powershell
Import-Module "C:\Program Files\Azure\StorageSyncAgent\StorageSync.Management.ServerCmdlets.dll"
Reset-StorageSyncServer
```
###  3       Deploy and manage virtual machines
#### 3.1a.1: Create an Azure VM (Portal)
...
#### 3.1a.2: Create an Azure VM (PowerShell)
```powershell
# Variables
$subnets = @()
$subnet1Name = "Subnet1"
$subnet2Name = "Subnet2"
$subnet1AddressPrefix = "10.0.0.0/24"
$subnet2AddressPrefix = "10.0.1.0/24"
$vnetAddressSpace = "10.0.0.0/16"
$vnetName = "ExamRefVNET"
```
```powershell
# Login to Azure account
Connect-AzAccount
```
```powershell
# Create a new resource group 
New-AzResourceGroup -Name $resourceGroupName -Location $location
```
```powershell
# Create a virtual network
$subnets = @()
$subnets += New-AzVirtualNetworkSubnetConfig -Name $subnet1Name -AddressPrefix $subnet1AddressPrefix
$subnets += New-AzVirtualNetworkSubnetConfig -Name $subnet2Name -AddressPrefix $subnet2AddressPrefix
$vnet = New-AzVirtualNetwork -Name $vnetName -Location $location -AddressPrefix $vnetAddressSpace -Subnet $subnets
```
```powershell
# Create a public IP address
$pip = New-AzPublicIpAddress -Name $ipName -ResourceGroupName $rgName -Location $location -AllocationMethod Dynamic -DomainNameLabel $dnsName
```
```powershell
# Add a rule to the network security group to allow RDP in
$nsgRules = @()
$nsgRules += New-AzNetworkSecurityRuleConfig -Name "RDP" -Description "RemoteDesktop" -Protocol Tcp -SourcePortRange "*" -DestinationPortRange "3389" -SourceAddressPrefix "*" -DestinationAddressPrefix "*" -Access Allow -Priority 110 -Direction Inbound
```
```powershell
# Apply the rules
$nsg = New-AzNetworkSecurityGroup -ResourceGroupName $resourceGroupName -Name "ExamREfNSG" -SecurityRules $nsgRules -Location $location
```
```powershell
# Create a virtual machine configuration object with the `New-AzVMConfig` cmdlet
$vm = New-AzVMConfig -VMName $vmName -VMSize $vmSize
```
```powershell
# Specify operating system and credentials
Set-AzVMOperatingSystem -Windows -ComputerName $vmName -Credential $cred -ProvisionVMAgent -VM $vm
```
```powershell
# Specify the operating system image using `Set-AzVMSourceImage`
Set-AzVMSourceImage -PublisherName $pubName -Offer $offerName -Skus $skuName -Version "latest" -VM $vm
Set-AzVMOSDisk -CreateOption fromImage -VM $vm
```
```powershell
# Create a network interface
$nic = New-AzNetworkInterface -Name $nicNAme -ResourceGroupName $resourceGroupName -Location $location -SubnetId $vnet.Subnets[0].Id -PublicIpAddressId $pip.Id -NetworkSecurityGroupId $nsg.Id
Add-AzVMNetworkInterface -VM $vm -NetworkInterface $nic
```
```powershell
# Provision the virtual machine with `New-AzVM`
New-AzVM -ResourceGroupName $resourceGroupName -Location $location -VM $vm
```
#### 3.1a.3: Create an Azure VM (Azure CLI)
```sh
# Login to Azure account
az login
```
```sh
# Create a new resource group 
az group create --name $rgName --location $location
```
```sh
# Identify available regions
az account list-locations
```
```sh
# Create a simple virtual machine
vmName="myUbuntuVM"
imageName="UbuntuLTS"
az vm create --resource-group $rgName --name $vmName --image $imageName --generate-ssh-keys
```
```sh
# Create a virtual network
vnetName="ExamRefVNET"
vnetAddressPrefix="10.0.0.0/16"
az network vnet create --resource-group $rgName -n ExamRefVNET --address-prefixes $vnetAddressPrefix -l $location
```
```sh
# Create a public IP address
dnsRecord="examrefdns123123"
ipName="ExamRefIP"
az network public-ip create -n $ipName -g $rgName --allocation-method Dynamic --dns-name $dnsRecord -l $location
```
```sh
# Create a network security group
nsgName="webnsg"
az network nsg create -n $nsgName -g $rgName -l $location
```
```sh
# Create a network security group rule to allow SSH in
az network nsg rule create -n SSH --nsg-name ... --priority 100 -g ... --access Allow --description "SSH Access" --direction Inbound --protocol Tcp --destination-address-prefix "*" --destination-port-range 22 --source-address-prefix "*" --source-port-range "*"
```
```sh
# Create a network security group rule to allow HTTP in
az network nsg rule create -n HTTP --nsg-name ... --priority 101 -g ... --access Allow --description "Web Access" --direction Inbound --protocol Tcp --destination-address-prefix "*" --destination-port-range 80 --source-address-prefix "*" --source-port-range "* 
```
```sh
# Create a network interface
nicname="WebVMNic1"
az network nic create -n $nicname -g $rgName --subnet $Subnet1Name --network-security-group $nsgName --vnet-name $vnetName --public-ip-address $ipName -l $location
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
az vm create -n $vmName -g $rgName -l $location --size $vmSize --nics $nicname --image $imageName --generate-ssh-keys
```
#### 3.1a.4: Capture a managed VM image (Portal)
#### 3.1a.5: Capture a managed VM image (PowerShell)
```powershell
# Variables
$rgName = "Contoso"
$vmName = "ImageVM"
$location = "WestUS"
$imageName = "WinVMImage"j
```
```powershell
# Set status of VM to "Generalized"
Set-AzVM -ResourceGroupName  $rgName -Name $vmName -Generalized 
```
```powershell
# Create a managed VM from a VM
$vm = Get-AzVM -ResourceGroupName $rgName -Name $vmName
$image = New-AzImageConfig -Location $location -SourceVirtualMachineId $vm.ID 
New-AzImage -Image $image -ImageName $imageName -ResourceGroupName $rgName
```
#### 3.1a.6: Capture a managed VM image (Azure CLI)
```sh
# Create a managed image
rgName="Contoso"
vmName="ImageVM"
imageName="LinuxImage"
```
```sh
# Deallocate the VM
az vm deallocate --resource-group $rgName --name $vmName
```
```sh
# Set the status of the VM to Generalized
az vm generalize --resource-group $rgName --name $vmName
az image create --resource-group $rgName --name $imageName --source $vmName 
```
#### 3.1a.7: Create a VM from an image
#### 3.1a.34: Specify a legacy unmanaged image for use in a new virtual machine (PowerShell)
```powershell
$osDiskUri = "https://examrefstorage.blob.core.windows.net/vhd/os-disk"
$imageUri = "https://examrefstorage.blob.core.windows.net/images/legacy-image.vhd"
$vm = Set-AzVMOSDisk -VM $vm -Name $osDiskName -VhdUri $osDiskUri -CreateOption fromImage -SourceImageUri $imageUri -Windows
```
#### 3.1a.35: Specify a legacy unmanaged image for use in a new virtual machine (Azure CLI)
```sh
az vm create --resource-group $rgName --name $vmName --image $osDiskUri --generate-ssh-keys
```
#### 3.1a.36: Specify a managed image for use in a new virtual machine (PowerShell)
```powershell
$image = Get-AzImage -ImageName $imageName -ResourceGroupName $rgName
$vmConfig = Set-AzVMSourceImage -VM $vmConfig -Id $image.Id
```
#### 3.1a.37: Specify a managed image for use in a new virtual machine (Azure CLI)
```sh
az vm create -g $rgName -n $vmName --image $imageName
```
#### 3.1b.01: Create an availability set (Portal)
#### 3.1b.02: Create an availability set (PowerShell)
```powershell
# Variables
$rgName = "ExamRefRG"
$avSetName = "WebAVSet"
$location = "West US"
```
```powershell
# Create an availability set
New-AzavailabilitySet -ResourceGroupName $rgName -Name $avSetName -Location $location -PlatformUpdateDomainCount 10 -PlatformFaultDomainCount 3 -Sku "Aligned"
```
#### 3.1b.03: Create an availability set (CLI)
```sh
# Variables
rgName="ExamRefRG"
avSetName="WebAVSet"
location="WestUS"
```
```sh
# Create an availability set
az vm availability-set create --name $avSetName --resource-group $rgName --platform-fault-domain-count 3 --platform-update-domain-count 10
```
#### 3.1c.01: Resizing a VM (PowerShell)
```powershell
# Variables
$rgName = "ExamRefRG"
$vmName = "Web1"
$size = "Standard_DS2_V2"
```
```powershell
# View available sizes
Get-AzVMSize -Location $location
```
```powershell
# Change VM to the new size
$vm = Get-AzVM -ResourceGroupName $rgName -VMName $vmNAme
$vm.HardwareProfile.VMSize = "Standard_DS2_V2"
Update-AzVM -VM $vm -ResourceGroupName $rgName
```
#### 3.1c.02: Resizing a VM (Azure CLI)
```sh
az vm list-vm-resize-options --resource-group $rgName --name $vmName --output table
az vm resize --resource-group $rgName --name $vmName --size Standard_DS3_v2
```
#### 3.1e.01: Modify host cache setting on a virtual HD (Portal)
#### 3.1e.02: Modify host cache setting on a virtual HD (PowerShell)
```powershell
$vm = Get-AzVM -ResourceGroupName $rgName -Name $vmName
Set-AzVMDataDisk -VM $vm -Lun 0 -Caching ReadOnly
Update-AzVM -ResourceGroupName $rgName -VM $vm
```
#### 3.1e.03: Modify host cache setting on a managed virtual HD (Azure CLI)
Variables
```sh
rgName="StorageRG"
vmName="StandardVM"
diskName="ManagedDisk"
```
Attach a managed disk
```sh
az vm disk attach --vm-name $vmName --resource-group $rgName --size-gb 128 --disk $diskName --caching ReadWrite -new
```
#### 3.1e.04: Modify host cache setting on a unmanaged virtual HD (Azure CLI)
```sh
az vm unmanaged-disk attach
```
#### 3.1e.05: Create a new storage pool using all available disks (PowerShell)
#### 3.1f.01: Connecting to a Windows VM with remote desktop
```powershell
# Variables
$rgName = "ExamRefRG"
$vmName = "ExamRefVM"
$Path = "C:\path\to\ExamRefVM.rdp"
```
```powershell
# Use `Launch` param to retrieve .rdp file and immediately open it with a Remote Desktop client
Get-AzRemoteDesktopFile -ResourceGroupName $rgName -Name $vmName -Launch
```
```powershell
# Specify `LocalPath` param to save the .rdp file for later use
Get-AzRemoteDesktopFile -ResourceGroupName $rgName -Name $vmName -LocalPath $path
```
#### 3.1f.02: Connecting to a Linux virtual machine using SSH
#### 3.1g.01: Enabling and configuring diagnostics (Windows)
#### 3.1g.02: Enabling and configuring diagnostics (Linux)
#### 3.1h.01: Creating a virtual machine scale set (Portal)
#### 3.1h.02: Creating a virtual machine scale set (PowerShell)
```powershell
# Variables
$rgName = "ExamRefRG"
$location = "WestUS"
$vmSize = "Standard_DS2_V2"
$capacity = 2
```
```powershell
# Create a VMSS with IIS installed from a custom script extension
New-AzResourceGroup -Name $rgName -Location $location
```
```powershell
# Create a config object
$vmssConfig = New-AzVmssConfig -Location $location -SkuCapacity $capacity -SkuName $vmSize -UpgradePolicyMode Automatic
```
```powershell
# Create a public IP address
$publicIP = New-AzPublicIpAddress -ResourceGroupName $rgNAme -Location $locaiton -AllocationMethod Static -Name $publicIPName
```
```powershell
# Create a frontend and backend IP pool
$frontendIP = New-AzLoadBalancerFrontendIpConfig -Name "lbFrontEndPool" -PublicIpAddress $publicIP
$backendPool = New-AzLoadBalancerBackendAddressPoolConfig -Name "lbBackEndPool"
```
```powershell
# Create the load balancer
$lb = New-AzLoadBalancer -ResourceGroupName $rgName -Name "lbrule" -Location $location -FrontendIPConfiguration $frontendIP -BackendAddressPool $backendPool
```
```powershell
# Create a load balancer rule to distribute traffic on port 80
Add-AzLoadBalancerProbeConfig -Name "lbrule" -LoadBalancer $lb -Protocol http -Port 80 -IntervalInSeconds 15 -ProbeCount 2 -RequestPath "/"
Set-AzLoadBalancer -LoadBalancer $lb
```
```powershell
# Reference a VM image from the gallery
Set-AzVmssStorageProfile $vmssConfig -ImageReferencePublisher MicrosoftWindowsServer -ImageReferenceOffer WindowsServer -ImageReferenceSku 2016-Datacenter -ImageReferenceVersion latest -OsDiskCreateOption FromImage
```
```powershell
# Set up information for authenticating with the VM
Set-AzVmssOsProfile $vmssConfig -AdminUsername "azureuser" -AdminPassword "P@ssword!" -ComputerNamePrefix "ssVM"
```
```powershell
# Create VNet resources
$subnet = New-AzVirtualNetworkSubnetConfig -Name "web" -AddressPrefix 10.0.0.0/24
$vnet = New-AzVirtualNetwork -ResourceGroupName $rgName -Name $ssName -Location $location -AddressPrefix 10.0.0.0/16 -Subnet $subnet
$ipConfig = New-AzVmssIpConfig -Name "vmssIPConfig" -LoadBalancerBackendAddressPoolsId $lb.BackendAddressPools[0].Id -SubnetId $vnet.Subnets[0].Id
```
```powershell
# Attach the VNet to the config object
Add-AzVmssNetworkInterfaceConfiguration -VirtualMachineScaleSet $vmssConfig -Name "network-config" -Primary $true -IPConfiguration $ipConfig 
```
```powershell
# Create the scale set with the config object
New-AzVmss -ResourceGroupName $rgName -Name $scaleSetName -VirtualMachineScaleSet $vmssConfig
```
#### 3.1h.03: Creating a virtual machine scale set (CLI)
```sh
# Variables
rgName="ExamRefRG"
ssName="erscaleset"
userName="azureuser"
password="P@ssword!"
vmPrefix="ssVM"
location="WestUS"
```
```powershell
# Create a VM Scale Set with load balancer, virtual network, and a public IP address
az group create --name $rgName --location $location
az vmss create --resource-group $rgName --name $ssName --image UbuntuLTS --authentication-type password --admin-username $userName --admin-password $password
```
#### 3.2c.01: Deploy a template that creates a VM (Portal)
#### 3.2c.02: Deploy a template that creates a VM (PowerShell)
```powershell
# Variables
$rgName = "ExamRefRG"
$location = "WestUs"
$deploymentName = "simpleVMDeployment"
$templateUri = "https://raw.githubusercontent.com/Azure/azure-quickstart-templates/master/101-vm-simple-windows/azuredeploy.json"
```
```powershell
# Create a resource group
New-AzResourceGroup -Name $rgName -Location $location
# Deploy template from GitHub
New-AzResourceGroupDeployment -Name $deploymentName -ResourceGroupName $rgName -TemplateUri $templateUri
```
#### 3.2c.03: Deploy a template that creates a VM (Azure CLI)
```sh
# Variables
rgName="ExamRefRG"
location="WestUS"
deploymentName="simpleVMDeployment"
templateUri = "https://raw.githubusercontent.com/Azure/azure-quickstart-templates/master/101-vm-simple-windows/azuredeploy.json"
```
```sh
# Create a resource group
az group create --name $rgNAme --location $location
```
```sh
# Deploy template from GitHub
az group deployment create --name $deploymentName --resource-group $rgName --template-uri $templateUri
```
#### 3.2d.01: Deploy a template in Complete mode
```powershell
New-AzResourceGroupDeployment -Mode Complete -Name simpleVMDeployment -ResourceGroupName ExamRefRG
```
```sh
az group deployment create --name simpleVMDeployment --mode Complete --resource-group ExamRefRG
```
#### 3.2e.01: Export deployment template (Portal)
#### 3.2e.02: Access template that represents current state of resource group
#### 3.2e.03: Export templates
```powershell
Save-AzResourceGroupDeploymentTemplate -ResourceGroupName ExamRefRG -DeploymentName simpleVMDeployment
```
```sh
az group deployment export --name simpleVMDeployment --resource-group ExamRefRG
```
#### 3.2e.04: Export all resources in a resource group as a template
```powershell
Export-AzResourceGroup -ResourceGroupName ExamRefRG
```
```sh
az group export --name ExamRefRG
```
#### 3.2e.05: Pass a template file during deployment
#### 3.3a.01: Add a data disk to an existing VM (Portal)
#### 3.3a.02: Attach a new managed disk to an existing VM
```powershell
# Variables
$dataDiskName = "MyDataDisk"
$location="WestUS"
```
```powershell
# Create the disk configuration
$diskConfig = New-AzDiskConfig -SkuName Premium_LRS -Location $location -CreateOption Empty -DiskSizeGB 128
```
```powershell
# Create the disk
$dataDisk1 = New-AzDisk -DiskName $dataDiskName -Disk $diskConfig -ResourceGroupNAme ExamRefRG
```
```powershell
# Retrieve the current VM
$vm = Get-AzVM -Name ExamRefVM -ResourceGroupName ExamRefRG
```
```powershell
# Attach the disk
$vm = Add-AzVMDataDisk -VM $vm -Name $dataDiskName -CreateOption Attach -ManagedDiskId $dataDisk1.Id -Lun 1
```
```powershell
# Update the VM
Update-AzVM -VM $vm -ResourceGroupName ExamRefRG
```
```sh
az vm disk attach -g ExamRefRG --vm-name ExamRefVM --name myDataDisk --new --size-gb 128 --sku Premium_LRS
``` 
#### 3.3b.01: Add a new network interface to an existing VM
#### 3.3b.02: Attach a new network interface to an existing VM
```powershell
# Variables
$vnetNAme = "ExamRefVNET"
$subnetName = "Subnet-1"
$rgName = "ExamRefRG"
$vmName = "ExamRefVM"
$nicName = "newnic"
```
```powershell
# Deallocate the VM
Stop-AzVM -Name $vmName -ResourceGroupName $rgName
```
```powershell
# Retrieve the VM configuration
$vm = Get-AzVm -Name ExamRefVM -ResourceGroupName $rgName
```
```powershell
# Get info for the backend subnet
$myVnet = Get-AzVirtualNetwork -ResourceGroupName $rgName -Name $vnetName
$backend = $myVnet.Subnets |? { $_.Name -eq $subnetName }
```
```powershell
# Create a virtual NIC
$newNic = New-AzNetworkInterface -ResourceGroupName $rgName -Name $nicName -Location $location -SubnetId $newNic.Id
```
```powershell
# Get the ID of the new virtual NIC and add to VM
$nicId = (Get-AzNetworkInterface -ResourceGroupName $rgName -Name $nicName).Id
Add-AzVMNetworkInterface -VM $vm -Id $nicId -Primary | Update-AzVm -ResourceGroupName $rgName
```
```sh
# Variables
vnetName="ExamRefVNET"
subnetName="Subnet-1"
rgName="ExamRefRG"
vmName="ExamRefVM"
nicName="newnic"
```
```sh
az network nic create --resource-group $rgName --name $nicName --vnet-name $ExamRefVNET --subnet $subnetName
az vm nic add -g $rgName --vm-name $vmName --nics $nicName --primary-nic
```
#### 3.3c.01: View all available sizes in a location
#### 3.3c.02: Change VM to a new size
#### 3.3d.01: Move a VM to another resource group or subscription (Portal)
#### 3.3d.02: Move a resource to another resource group or subscription (PowerShell)
```powershell
# Use `Get-AzResource` to identify the resource ID value
$resourceID = Get-AzResource -ResourceGroupName ExamRefRG | Format-Table -Property ResourceId
```
```powershell
# Specify the destination resource group and the resource ID to move
Move-AzResource -DestinationResourceGroupName ExamRefDestRG -ResourceId $resourceID
```
```powershell
# To move to a different subscription, use the `-DestinationSubscriptionId` param
Move-AzResource -DestinationSubscriptionId $subscriptionID -DestinationResourceGroupName ExamRefDestRG -ResourceId $resourceID
```
#### 3.3d.03: Move a resource to another resource group or subscription (Azure CLI)
```sh
# List resource IDs
az resource list -g ExamRefRG
```
```sh
# Move to a different resource group
az resource move --destination-group ExamRefDestRG --ids $resourceID
```
```sh
# Use the `--subscription-id` parameter to move to a different subscription
az resource move --destination-group ExamrefDestRG --destination-subscription-id $subscriptionID --ids $resourceID
```
#### 3.3e.01: Redeploy a VM
#### 3.3f.01: Package a DSC script into a zip file
```powershell
Publish-AzVMDscConfiguration -ConfigurationPath .\ContosoWeb.ps1 -OutputArchivePath .\ContosoWeb.zip
```
#### 3.3f.02: Apply the PowerShell Desired State Configuration extension
#### 3.3f.03: Publish a packaged DSC script to a storage account
```powershell
# Variables
$rgName = "ExamRefRG"
$location =- "WestUS"
$vmName = "ExamRefVM"
$storageName = "dscstorageer1"
$configurationName = "Main"
$archiveBlob = "ContosoWeb.ps1.zip"
$configurationPath = ".\ContosoWeb.ps1"
```
```powershell
# Publish the configuration script into Azure storage
Publish-AzVMDscConfiguration -ConfigurationPath $configurationPath -ResourceGroupName $rgName -StorageAccountName $storageName
```
```powershell
# Set the VM to run the DSC configuration
Set-AzVmDscExtension -Version 2.76 -ResourceGroupName $rgName -VMName $vmName -ArchiveStorageAccountNAme $storageName -ArchiveBlobName $archiveBNlob -AutoUpdate:$false -ConfigurationName $configurationName
```
#### 3.3f.04: Use the custom script extension
```powershell
# Deploy the Active Directory Domain Services role
Install-WindowsFeature -Name "AD-Domain-Services" -IncludeManagementTools -IncludeAllSubFeature
Install-ADDSForest -DomainName $domain -DomainMode Win2012 -ForestMode Win2012 -Force -SafeModeAdministratorPassword $smPassword
```
```powershell
# Use `Set-AzVMCustomScriptExtension` to run script on a VM
$rgName = "ExamRefRG"
$vmName = "ExamRefVM"
$scriptName = "deploy-ad.ps1"
$domain = "contoso.com"
$extensionName = "installAD"
$location = "WestUS"
$scriptUri = "https://raw.githubusercontent.com/opsgility/lab-support-public/master/script-extensions/deploy-ad.ps1" 
$scriptArgument = "contoso.com $password"
Set-AzVMCustomScriptExtension -ResourceGroupName $rgName -VMName $vmName -FileUri $scriptUri -Argument "$domain $password" -Run $scriptName -Name $extensionName -Location $location
```
```sh
rgName="ExamRefRG"
vmName="LinuxVM"
extensionName="InstallApache"
az vm extension set --resource-group $rgName --vm-name $vmName --name customScript --publisher Microsoft.Azure.Extensions --protected-settings ./cseconfig.json
```
#### 3.4a.01: Backup a VM with Azure Backup
#### 3.4d.01: Restore an Azure Backup recovery point as a new VM
#### 3.4d.02: Restore access to files in Azure Backup
###  4       Configure and manage virtual networks
#### 4.1d.01: Configure user-defined routes (Portal)
First, create the route table resource, then add routes 
#### 4.1d.02: Configure user-defined routes (PowerShell)
Create the route table resource
```powershell
$rt = New-AzRouteTable -Name RouteTable1 -ResourceGroupName ExamRefRG
```
Add a route to route table
```powershell
Add-AzRouteConfig -RouteTable $rt -Name Route1 -AddressPrefix 10.3.0.0/16 -NextHopType VirtualAppliance -NextHopIpAddress 10.2.20.4
Set-AzRouteTable -RouteTable $rt
```
Find the VNet and subnet
```powershell
$vnet = Get-AzVirtualNetwork -Name VNet1 -ResourceGroupNAme ExamRefRG 
$subnet = $vnet.Subnets | where {$_.Name -eq "Default"}
```
Update the subnet to specify the route table
```powershell
Set-AzVirtualNetworkSubnetConfig -VirtualNetwork $vnet -Name Default -AddressPrefix $subnet.AddressPrefix -RouteTable $rt
```
Commit the VNet back to Azure
```powershell
Set-AzVirtualNetwork -VirtualNetwork $vnet
```
Get effective routes for a NIC
```powershell
Get-AzEffectiveRouteTable -NetworkInterfaceName VNet1-VM -ResourceGroupName ExamRefRG
```
#### 4.1d.03: Configure user-defined routes (Azure CLI)
```sh
# Create route table
az network route-table create --name RouteTable1 --resource-group ExamRefRG 
```
```sh
# Add route to route table
az network route-table route create --name Route1 --route-table-name RouteTable1 --resource-group ExamRefRG --address-prefix 10.3.0.0/16 --next-hop-type VirtualAppliance --next-hop-ip-address 10.2.20.4
```
```sh
# Associate route table with subnet
az network vnet subnet update --name defualt --vnet-name Vnet1 --resource-group ExamRefRG --route-table RouteTable1
```
```sh
# Get effective routes for NIC
az network nic show-effective-route-table --name VM1-NIC --resource-group ExamRefRG
```
#### 4.2a.01: Creating a VNet peering (Portal)
#### 4.2a.02: Creating a VNet peering (PowerShell)
```powershell
$vnet1 = Get-AzVirtualNetwork -ResourceGroupName ExamRefRG -Name VNet1
$vnet2 = Get-AzVirtualNetwork -ResourceGroupName ExamRefRG -Name VNet2
```
```powershell
# Peer Vnet1 to VNet2 (and vice versa)
Add-AzVirtualNetworkPeering -Name 'VNet2-to-VNet1' -VirtualNetwork $vnet2 -RemoteVirtualNetworkId $vnet1.Id
Add-AzVirtualNetworkPeering -Name 'VNet1-to-VNet2' -VirtualNetwork $vnet1 -RemoteVirtualNetworkId $vnet2.Id
```
```powershell
# Check the peering status
Get-AzVirtualNetworkPeering -ResourceGroupName ExamRefRG -VirtualNetworkName VNet1 |
Format-Table VirtualNetworkName, PeeringState
```
#### 4.2a.03: Creating a VNet peering (Azure CLI)
```sh
# Peer VNet1 to VNet2
az network vnet peering create --name VNet1-to-VNet2 --resource-group ExamRefRG --vnet-name VNet1 --allow-vnet-access --remote-vnet VNet2
```
```sh
# Peer VNet2 to VNet1
az network vnet peering create --name VNet2-to-VNet1 --resource-group ExamRefRG --vnet-name VNet2 --allow-vnet-access --remote-vnet VNet1
```
```sh
# Check the peering status
az network vnet peering list --resource-group ExamRefRG --vnet-name VNet1 -o table
az network vnet peering list --resource-group ExamRefRG --vnet-name VNet2 -o table
```
#### 4.2b.01: Creating a VPN gateway and VNet-to-VNet connection (Portal)
#### 4.2b.02: Creating a VPN gateway and VNet-to-VNet connection (PowerShell)
```powershell
# Create gateway subnets in VNet2 and VNet3
$vnet2 = Get-AzVirtualNetwork -Name VNet2 -ResourceGroupName ExamRefRG
$vnet2.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.2.1.0/27
$vnet2 = Set-AzVirtualNetwork -VirtualNetwork $vnet2
$vnet3 = Get-AzVirtualNetwork -Name VNet3 -ResourceGroupName ExamRefRG
$vnet3.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.3.1.0/27
$vnet3 = Set-AzVirtualNetwork -VirtualNetwork $vnet3
```
```powershell
# Create VPN gateway in VNet2
$gwpip2 = New-AzPublicIpAddress -Name VNet2-GW-IP -ResourceGroupName ExamRefRG -Location $vnet2.Location -AllocationMethod Dynamic
$gwsubnet2 = Get-AzVirtualNetworkSubnetConfig -Name 'GatewaySubnet' -VirtualNetwork $vnet2
$gwipconf2 = New-AzVirtualNetworkGatewayIpConfig -Name GwIPConf2 -Subnet $gwsubnet2 -PublicIpAddress $gwpip2
$vnet2gw = New-AzVirtualNetworkGateway -Name VNet2-GW -ResourceGroupNAme ExamRefR -Location $vnet2.Location -IpConfigurations $gwipconf2 -GatewayType Vpn -VpnType RouteBased -GatewaySku VpnGw1
```
```powershell
# Create VPN gateway in VNet3
$gwpip3 = New-AzPublicIpAddress -Name VNet3-GW-IP -ResourceGroupName ExamRefR -Location $vnet3.Location -AllocationMethod Dynamic
$gwsubnet3 = Get-AzVirtualNetworkSubnetConfig -Name 'GatewaySubnet' -VirtualNetwork $vnet3
$gwipconf3 = New-AzVirtualNetworkGatewayIpConfig -Name GwIPConf3 -Subnet $gwsubnet3 -PublicIpAddress $gwpip3
$vnet3gw = New-AzVirtualNetworkGateway -Name VNet3-GW -ResourceGroupNAme ExamRefRG -Location $vnet3.Location -IpConfigurations $gwipconf3 -GatewayType Vpn -VpnType RouteBased -GatewaySku VpnGw1
```
```powershell
# Create connections
New-AzVirtualNetworkGatewayConnection -Name VNet2-to-VNet3 -ResourceGroupName ExamRefRG -Location $vnet2.Location -VirtualNetworkGateway1 $vnet2gw -VirtualNetworkGateway2 $vnet3gw -ConnectionType VNet2VNet -SharedKey "secretkey123"
New-AzVirtualNetworkGatewayConnection -Name VNet3-to-VNet2 -ResourceGroupName ExamRefRG -Location $vnet3.Location -VirtualNetworkGateway1 $vnet3gw -VirtualNetworkGateway2 $vnet2gw -ConnectionType VNet2VNet -SharedKey "secretkey123"
```
#### 4.2b.03: Creating a VPN gateway and VNet-to-VNet connection (Azure CLI)
```sh
# Create gateway subnets in VNet2 and VNet3
az network vnet subnet create --name GatewaySubnet --vnet-name VNet2 --resource-group ExamRefRG --address-prefixes 10.2.1.0/27
az network vnet subnet create --name GatewaySubnet --vnet-name VNet3 --resource-group ExamRefRG --address-prefixes 10.3.1.0/27
```
```sh
# Create public IP addresses for use by VPN gateways
az network public-ip create --name VNet2-GW-IP --resource-group ExamRefRG --location NorthEurope
az network public-ip create --name VNet3-GW-IP --resource-group ExamRefRG --location WestEurope
```
```sh
# Create VPN gateways in VNet2 and VNet 3
az network vnet-gateway create --name VNet2-GW --resource-group ExamRefRG --gateway-type vpn --sku VpnGw1 --vpn-type RouteBased --vnet VNet2 --public-ip-addresses VNet2-GW-IP --location NorthEurope
az network vnet-gateway create --name VNet3-GW --resource-group ExamRefRG --gateway-type vpn --sku VpnGw1 --vpn-type RouteBased --vnet VNet3 --public-ip-addresses VNet3-GW-IP --location WestEurope
```
```sh
# :Create connections between VPN gateways
az network vpn-connection create --name VNet2-to-VNet3 --resource-group ExamRefRG --vnet-gateway1 VNet2-GW --vnet-gateway2 VNet3-GW --shared-key secretkey123 --location NorthEurope
az network vpn-connection create --name VNet3-to-VNet2 --resource-group ExamRefRG --vnet-gateway1 VNet3-GW --vnet-gateway2 VNet2-GW --shared-key secretkey123 --location WestEurope
```
#### 4.3a.01: Creating DNS zones and DNS records (Portal)
#### 4.3a.02: Creating DNS zones and DNS records (PowerShell)
```powershell
# Create a DNS zone
New-AzDnsZone -Name examref.com -ResourceGroupName ExamRefRG
```
```powershell
# Create a record set containing a single record
New-AzDnsRecordSet -Name www -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords (New-AzDnsRecordConfig -IPv4Address "1.2.3.4")
```
```powershell
# Create a record set at the zone apex containing multiple records
$records = @()
$records += New-AzDnsRecordConfig -IPv4Address "1.2.3.4"
$records += New-AzDnsRecordConfig -IPv4Address "5.6.7.8"
New-AzDnsRecordSet -Name "@" -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords $records
```
```powershell
# Add a new record to and remove an existing record from an existing record set
$recordset = Get-AzDnsRecordSet -Name www -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG
Add-AzdnsRecordConfig -RecordSet $recordset -IPv4Address "5.6.7.8"
Remove-AzDnsRecordConfig -RecordSet $recordset -IPv4Address "1.2.3.4"
Set-AzDnsRecordSet -RecordSet $recordset
```
```powershell
# View records
Get-AzDnsRecordSet -ZoneName examref.com -ResourceGroupName ExamRefRG
```
#### 4.3a.03: Creating DNS zones and DNS records (Azure CLI)
```sh
# Create a DNS zone
az network dns zone create --name examref.com --resource-group ExamRefRG
```
```sh
# Create an empty record set of type A
az network dns record-set a create --name www --zone-name examref.com --resource-group ExamRefRG --ttl 3600
```
```sh
# Add A records to the above record set
az network dns record-set a add-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 1.2.3.4
az network dns record-set a add-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 5.6.7.8
```
```sh
# Remove an A record from the record set
az network dns record-set a remove-record --record-set-name www --zone-name examref.com --resource-group ExamRefRG --ipv4-address 1.2.3.4
```
```sh
# View records
az network dns record-set list --zone-name examref.com --resource-group ExamRefRG -o table 
```
#### 4.3b.01: Configure custom DNS settings (Portal)
#### 4.3b.02: Configure custom DNS settings (PowerShell)
```powershell
# Create a virtual network with custom DNS settings
New-AzVirtualNetwork -Name VNet1 -ResourceGroupName ExamRefRG -Location "North Europe" -AddressPrefix 10.1.0.0/16 -DNSServer 10.0.0.4,10.0.0.5 -Subnet (New-AzVirtualNetworkSubnetConfig -Name Default -AddressPrefix 10.1.0.0/24)
```
```powershell
# Modify the DNS server configuration of an existing VNET
$vnet = Get-AzVirtualNetwork -Name VNet1 -ResourceGroupName ExamRefRG
$vnet.DhcpOptions.DnsServers.Clear()
$vnet.DhcpOptions.DnsServers.Add("10.10.200.1")
$vnet.DhcpOptions.DnsServers.Add("10.10.200.2")
Set-AzVirtualNetwork -VirtualNetwork $vnet
```
```powershell
# Restart the VMs in the VNet to pick up the DNS change
$vm = Get-AzVM -Name VNet1-VM -ResourceGroupName ExamRefRG
Restart-AzVM -ID $vm.Id
```
```powershell
# Update the DNS settings on a NIC
$nic = Get-AzNetworkInterface -Name VM1-NIC -ResourceGroupName ExamRefRG
$nic.DnsSettings.DnsServers.Clear()
$nic.DnsSettings.DnsServers.Add("8.8.8.8")
$nic.DnsSettings.DnsServers.Add("8.8.4.4")
```
```powershell
# Commit the DNS change, causing the VM to restart
Set-AzNetworkInterface -NetworkInterface $nic
```
#### 4.3b.03: Configure custom DNS settings (Azure CLI)
```sh
# Create a virtual network with custom DNS settings
az network vnet create --name VNet1 --resource-group ExamRefRG --address-prefixes 10.0.0.0/16 --dns-servers 8.8.8.8 8.8.4.4
```
```sh
# Set custom DNS servers on a VNet
az network vnet update --name VNet1 --resource-group ExamRefRG --dns-servers 10.0.0.254
```
```sh
# Remove custom DNS servers from a VNET
az network vnet update --name VNet1 --resource-group ExamRefRG --remove DHCPOptions.DNSServers
```
```sh
# Set custom DNS servers on a NIC
az network nic update --name VM1-NIC --resource-group ExamRefRG --dns-servers 8.8.8.8 8.8.4.4
```
#### 4.3c.01: Create private DNS zones
#### 4.4c.01: Implement Service Map (Portal)
#### 4.4c.02: Install Dependency Agent
#### 4.4c.03: Register a resource provider (PowerShell)
```powershell
Register-AzResourceProvider -ProviderNamespace Microsoft.Insights
```
#### 4.4c.04: Register a resource provider (Azure CLI)
```sh
az provider register --namespace Microsoft.Insights
```
#### 4.4d.01: View effective security rules (Portal)
#### 4.4d.02: View effective security rules (PowerShell)
```powershell
Get-AzEffectiveNetworkSecurityGroup -NetworkInterfaceName examref-vm1638 -ResourceGroupName ExamRefRG
```
#### 4.4d.03: View effective security rules (Azure CLI)
```sh
az network nic list-effective-nsg --name examref-vm1638 --resource-group ExamRefRG
```
#### 4.5a.01: Create an Azure load balancer (Portal)
#### 4.5a.02: Create an Azure load balancer (PowerShell)
```powershell
# Variables
$rgName = "ExamRefRG"
$location = "West Europe"
```
```powershell
# Create Public IP
$publicIP = New-AzPublicIpAddress -Name ExamRefLB-IP -ResourceGroupName $rgNAme -Location $location -AllocationMethod Static 
```
```powershell
# Create frontend IP configuration
$frontendIP = New-AzLoadBalancerFrontendIpConfig -Name ExamRefFrontEnd -PublicIpAddress $publicIP
```
```powershell
# Create backend pool
$beAddressPool = New-AzLoadBalancerBackendAddressPoolConfig -Name ExamRefBackEndPool
```
```powershell
# Create HTTP Probe
$healthProbe = New-AzLoadBalancerProbeConfig -Name -RequestPath '/' -Protocol http -Port 80
```
```powershell
# Create load balancer rule
$lbrule = New-AzLoadBalancerRuleConfig -Name -FrontendIpConfiguration $frontendIP -BackendAddressPool $beAddressPool -Probe $healthProbe -Protocol Tcp -FrontendPort 80 -BackendPort 80
```
```powershell
# Create load balancer
$lb = New-AzLoadBalancer -ResourceGroupName -Name -Location -FrontendIpConfiguration $frontendIP -LoadBalancingRule $lbrule -BackendAddressPool $beAddressPool -Probe $healthProbe
```
#### 4.5a.03: Create an Azure load balancer (Azure CLI)
```sh
#Create Public IP
az network public-ip create --name ExamRefLB-IP --resource-group ExamRefRG --location --allocation-method Static
```
```sh
# Create load balancer
az network lb create --name ExamRefLB --resource-group ExamRefRG --location --backend-pool-name ExamRefBackEndPool --frontend-ip-name ExamRefFrontEnd --public-ip-address ExamRefLB-IP
```
```sh
# Create HTTP Probe
az network lb probe create --resource-group ExamRefRG --name HealthProbe --lb-name ExamRefLB --protocol http --port 80 --path / --interval 5 --threshold 
```
```sh
# Create load balancer rule
az network lb rule create --name ExamRefRule --lb-name ExamRefLB --resource-group ExamRefRG --protocol Tcp --frontend-port 80 --backend-port 80 --frontend-ip-name ExamRefFrontEnd --backend-pool-name ExamRefBackEndPool --probe-name HealthProbe
```
#### 4.5a.04: Add VMs to the backend pool of a load balancer (PowerShell)
The process in PowerShell is actually to add a reference to the backend pool to the NIC of each VM.
```powershell
# Variables
$rgName = "ExamRefRG"
```
```powershell
# Get the NIC based on VM ID
$vml = Get-AzVM -Name VM1 -ResourceGroupName $rgName
$vmlnic = Get-AzNetworkInterface -ResourceGroupName $rgName | where {$_.VirtualMachine.Id -eq $vml.Id}
```
```powershell
# Get the load balancer and backend pool
$lb = Get-AzLoadBalancer -Name ExamRefLB -ResourceGroupName $rgName
$beAddressPool = Get-AzLoadBalancerBackendAddressPoolConfig -Name ExamRefBackEndPool -LoadBalancer $lb
```
```powershell
# All IP configuration settings of the NIC have to be reapplied, there is no support for incremental changes
$ipconfig = Get-AzNetworkInterfaceIpConfig -Name ipconfig1 -NetworkInterface vm1nic
Set-AzNetworkInterfaceIpConfig -Name ipconfig1 -NetworkInterface $vm1nic -SubnetId $ipconfig.Subnet.Id -LoadBalancerBackendAddressPoolId $beAddressPool.Id
```
```powershell
# Commit the change
Set-AzNetworkInterface -NetworkInterface $vm1nic
```
#### 4.5a.05: Add VMs to the backend pool of a load balancer (Azure CLI)
Azure CLI supports incremental update of the NIC, which makes this command simpler than its PowerShell equivalent.
```sh
az network nic ip-config address-pool add --resource-group ExamRefRG --address-pool ExamRefBackEndPool --lb-name ExamRefLB --nic-name vm1-nic --ip-config-name ipconfig1
```
#### 4.5b.01: Enable basic-tier load-balancer logs
#### 4.6a.01: Install Network Performance Monitor (Portal)
#### 4.6a.02: Install Network Performance Monitor on a VM (Portal)
#### 4.6a.03: Connect on-premises server to Log Analytics
#### 4.6a.04: Configure Performance Monitor
#### 4.6a.05: Configure Service Connectivity Monitor
#### 4.6a.06: Configure ExpressRoute Monitor
#### 4.6c.01: Install Network Watcher VM extension (PowerShell)
```powershell
Set-AzVMExtension ` -ResourceGroupName ExamRefRG -Location "West Europe" -VMName VM1 -Name networkWatcherAgent -Publisher Microsoft.Azure.NetworkWatcher -Type NetworkWatcherAgentWindows -TypeHandlerVersion 1.4
```
#### 4.6c.02: Install Network Watcher VM extension (Azure CLI)
```sh
az vm extension set --vm-name VM1 --resource-group ExamRefRG --publisher Microsoft.Azure.NetworkWatcher --version 1.4 --name NetworkWatcherAgentWindows --extension-instance-name NetworkWatcherAgent
```
#### 4.6c.03: Use IP Flow Verify (Portal)
#### 4.6c.04: Use IP Flow Verify (PowerShell)
```powershell
Test-AzNetworkWatcherIPFlow
```
#### 4.6c.05: Use IP Flow Verify (Azure CLI)
```sh
az network watcher test-ip-flow
```
#### 4.6c.06: Use Next Hop (Portal)
#### 4.6c.07: Use Next Hop (PowerShell)
```powershell
Get-AzNetworkWatcherNextHop
```
#### 4.6c.08: Use Next Hop (Azure CLI)
```sh
az network watcher show-next-hop
```
#### 4.6c.09: Use Packet Capture (Portal)
#### 4.6c.10: Use Packet Capture (PowerShell)
```powershell
# Get the Network Watcher resource
$nw = Get-AzResource | Where ResourceType -eq "Microsoft.Network/networkWatchers" -and Location -eq "WestEurope"
$networkWatcher = Get-AzNetworkWatcher -Name $nw.Name -ResourceGroupName $nw.ResourceGroupName
```
```powershell
# Get the storage account to store the capture in
$storageAccount = Get-AzStorageAccount -Name examref-storage -ResourceGroupName ExamRefRG
```
```powershell
# Set up filters
$filter1 = New-AzPacketCaptureFilterConfig -Protocol TCP -RemoteIPAddress "1.1.1.1-255.255.255.255" -LocalIPAddress "10.0.0.3" -LocalPort "1-65535" -RemotePort "20;80;443"
$filter2 = New-AzPacketCaptureFilterConfig -Protocol UDP
```
```powershell
# Get the VM
$vm = Get-AzVM ` -Name VM1 -ResourceGroupName ExamRefRG
```
```powershell
# Start the packet capture
New-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -TargetVirtualMachineId $vm.Id -PacketCaptureName "PacketCaptureTest" -StorageAccountId $storageAccount.id -TimeLimitInSeconds 60 -Filter $filter1, $filter2
```
```powershell
# Check packet capture status
Get-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -PacketCaptureName "PacketCaptureTest"
```
```powershell
# Stop packet capture
Stop-AzNetworkWatcherPacketCapture -NetworkWatcher $networkWatcher -PacketCaptureName "PacketCaptureTest"
```
#### 4.6c.11: Use Packet Capture (Azure CLI)
```sh
# Start packet capture
az network watcher packet-capture create --name PacketCaptureTest2 --resource-group ExamRefRG --vm VM1 --time-limit 300 --storage-account examref-storage `
  --filters '[ { 
    "protocol": "TCP", 
    "remoteIPAddress": "1.1.1.1-255.255.255.255",
    "localIPAddress":"10.0.0.3", 
    "remotePort":"20" } ]'
```
```sh
# Get packet capture status
az network watcher packet-capture show-status --name PacketCaptureTest --location WestEurope
```
```sh
# Stop packet capture
az network watcher packet-capture stop --name PacketCaptureTest --location WestEurope
```
#### 4.6c.12: Use Network Topology (Portal)
#### 4.6c.13: Use Network Topology (PowerShell)
```powershell
Get-AzNetworkWatcherTopology
```
#### 4.6c.14: Use Network Topology (Azure CLI)
```sh
az network watcher show-topology
```
#### 4.6d.01: Use VPN Troubleshoot (Portal)
#### 4.6d.02: Use VPN Troubleshoot (PowerShell)
```powershell
# Get the Network Watcher resource
$nw = Get-AzResource | Where ResourceType -eq Microsoft.Network/networkWatchers -and Location -eq WestEurope
$networkWatcher = Get-AzNetworkWatcher -Name $nw.Name -ResourceGroupName $nw.ResourceGroupName
```
```powershell
# Create a storage account and container for logs
$sa = New-AzStorageAccount -Name examrefstorage -SKU Standard_LRS -ResourceGroupName ExamRefRG -Location WestEurope
Set-AzCurrentStorageAccount -ResourceGroupName $sa.ResourceGroupName -Name $sa.StorageAccountName
$sc = New-AzureStorageContainer -Name logs
```
```powershell
# Get the connection to troubleshoot
$connection = Get-AzVirtualNetworkGatewayConnection -Name Vnet1-to-Vnet2 -ResourceGroupName ExamRefRG
```
```powershell
# Start VPN Troubleshoot
Start-AzNetworkWatcherResourceTroubleshooting -NetworkWatcher $networkWatcher -TargetResourceId $connection.Id -StorageId $sa.Id -StoragePath "$($sa.PrimaryEndpoints.Blob)$($sc.name)"
```
#### 4.6d.03: Use VPN Troubleshoot (Azure CLI)
```sh
# Crate a storage account and container for logs
az storage account create --name examrefstorage --location westeurope --resource-group ExamRefRG --sku Standard_LRS
az storage account keys list --resource-group ExamRefRG --account-name examrefstorage
az storage container create --account-name examrefstorage --account-key {storageAccountKey} --name logs
```
```sh
# Start VPN Troubleshoot
az network watcher troubleshooting start --resource-group ExamRefRG --resource Vnet1-to-Vnet2 --resource-type vpnConnection --storage-account examrefstorage --storage-path https://examrefstorage.blob.core.windows.net/logs --output json
```
#### 4.6e.01: Use Connection Troubleshoot (Portal)
#### 4.6e.02: Use Connection Troubleshoot (PowerShell)
#### 4.6e.03: Use Connection Troubleshoot (Azure CLI)
#### 4.6e.04: Use Connection Monitor (Portal)
#### 4.7a.01: Create a VPN Gateway (Portal)
#### 4.7a.02: Create a VPN Gateway (PowerShell)
```powershell
$rg = ExamRefRG
```
```powershell
# Create gateway subnet in VNet1
# Gateway subnets are normal subnets with the name "GatewaySubnet"
$vnet1 = Get-AzVirtualNetwork -Name VNet1 -ResourceGroupName $rg
$vnet1.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.1.1.0/27
$vnet1 = Set-AzVirtualNetwork -VirtualNetwork $vnet1
```
```powershell
# Create VPN gateway in VNet1
$gwpip = New-AzPublicIpAddress -Name VNet1-GW-IP -ResourceGroupName $rg -Location 'North Europe' -AllocationMethod Dynamic
$gwsubnet = Get-AzVirtualNetworkSubnetConfig -Name 'GatewaySubnet' -VirtualNetwork $vnet1
$gwipconf = New-AzVirtualNetworkGatewayIpConfig -Name GwIPConf -Subnet $gwsubnet -PublicIpAddress $gwpip
$vnet1gw = New-AzVirtualNetworkGateway -Name VNet1-GW -ResourceGroupName $rg -Location 'North Europe' -IpConfigurations $gwipconf -GatewayType Vpn -VpnType RouteBased -GatewaySku VpnGw1
```
#### 4.7a.03: Create a VPN Gateway (Azure CLI)
```sh
# Create gateway subnets in VNet2 and VNet3
az network vnet subnet create --name GatewaySubnet --vnet-name VNet1 --resource-group ExamRefRG --address-prefixes 10.1.1.0/27
```
```sh
# Create public IP addresses for use by VPN gateway
az network public-ip create --name VNet1-GW-IP --resource-group ExamRefRG --location NorthEurope
```
```sh
# Create VPN gateway in VNet1
az network vnet-gateway create --name VNet1-GW --resource-group ExamRefRG --gateway-type vpn --sku VpnGw1 --vpn-type RouteBased --vnet VNet1 --public-ip-addresses VNet1-GW-IP --location NorthEurope
```
#### 4.7b.01: Create a site-to-site VPN (Portal)
#### 4.7b.02: Create a site-to-site VPN (PowerShell)
```powershell
# Create local network gateway
$localnw = New-AzLocalNetworkGateway -Name LocalNetGW -ResourceGroupName ExamRefRG -Location "West Europe" -GatewayIpAddress "53.50.123.195" -AddressPrefix "10.5.0.0/16" 
```
```powershell
# Get VPN gateway
$gateway = Get-AzVirtualNetworkGateway -Name VPNGW1 -ResourceGroupName ExamRefRG
```
```powershell
# Create the connection
$conn = New-AzVirtualNetworkGatewayConnection -Name OnPremConnection -ResourceGroupName ExamRefRG -Location 'West Europe' -VirtualNetworkGateway1 $gateway -LocalNetworkGateway2 $localnw -ConnectionType IPsec -SharedKey "abc123"
```
#### 4.7b.03: Create a site-to-site VPN (Azure CLI)
```sh
# Create Local Network Gateway
az network local-gateway create --gateway-ip-address 53.50.123.195 --name LocalNetGW --resource-group ExamRefRG --local-address-prefixes 10.5.0.0/16
```
```sh
# Create VPN connection
az network vpn-connection create --name OnPremConnection --resource-group ExamRefRG --vnet-gateway1 VPNGW1 --location WestEurope --shared-key abc123 --local-gateway2 LocalNetGW
```
#### 4.7c.01: Creating an ExpressRoute circuit
###  5        Manage identities

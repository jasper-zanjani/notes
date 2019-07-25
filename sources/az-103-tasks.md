# Exam Ref AZ-103 Microsoft Azure Administrator, by Michael Washam, Jonathan Tuliani, and Scott Hoag
## Tasks 
#### 1.1a.1: Assign an RBAC role (Portal)
To assign an RBAC role to a subscription, open the __Subscription__, then the __Access Control (IAM)__ blades, then click __Add Role Assignment__. This will open a dialog box where you can select a __Role__ (e.g. Owner) then __Select__ a target principal.
#### 1.1b.1: Configure resource quotas
To view resource quotas for a subscription, go to the subscription in Azure Portal and open the __Usage + quotas__ blade. From there you can select resources and then click the __Request Increase__ button. PowerShell commands used with resource quotas:
  - `Get-AzVMUsage`: view current usage of vCPU quotas
  - `Get-AzStorageUsage`: view current usage of storage service
#### 1.1b.2 Configure cost center quotas
Budgets can be viewed and administered in the __Cost Management + Billing__ blade. Users must be at least Reader to a subscription to view, and Contributor to create and manage, budgets. Specialized roles that grant access to Cost Management include
  - __Cost Management contributor__
  - __Cost Management reader__
To create a budget, open __Cost Management + Billing__, then __Subscriptions__, select a subscription, then click __Budgets__. Then click __+ Add__, which produces a Create budget blade. The created budget can be seen in the __Budgets__ blade. PowerShell commands used with budgets:
  - `Get-AzResourceGroup` retrieve Resource Group object
  - `Set-AzResourceGroup` apply a tag to a resource group with __no preexisting tags__
  - `.Tags` method that retrieves Tag collection from a resource group
  - `.Add()` method used to add tags to a resource group that __already has__ tags.
#### 1.1b.3: Tag a resource group with no existing tags (PowerShell)
```powershell
Set-AzResourceGroup `
  -Name hrgroup
  -Tag @{CostCode=1001; Environment=Production}
```
#### 1.1b.4: Tag a resource group with existing tags (PowerShell)
```powershell
$tags = (Get-AzResourceGroup -Name hrgroup).Tags
$tags.Add("Owner", "user@contoso.com")
Set-AzResourceGroup `
  -Tag $tags
  -Name hrgroup
```
#### 1.1b.5: Tag a resource with no existing tags (PowerShell)
```powershell
$r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName hrgroup
Set-AzResource -Tag @{ CostCode="1001"; Environment="Production" } -ResourceId
$r.ResourceId -Force
```
#### 1.1b.6: Tag a resource with existing tags (PowerShell)
```powershell
$r = Get-AzResource `
  -ResourceName hrvm1 `
  -ResourceGroupName hrgroup
$r.Tags.Add("Owner", "user@contoso.com")
Set-AzResource `
  -Tag $r.Tags `
  -ResourceId $r.ResourceId `
  -Force
```
#### 1.1b.7: Remove tags from a resource (PowerShell)
```powershell
Set-AzResourceGroup `
  -Tag @{} `
  -Name hrgroup
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
```bash
az provider register \
  --namespace 'Microsoft.PolicyInsights'
```
#### 1.1c.3: Define a policy (Azure CLI)
```bash
az policy definition create \
  --name 'allowedVMs' \
  --description 'Only allow virtual machines in the defined SKUs' 
  --mode ALL \
  --rules '{...}' \
  --params '{...}'
```
#### 1.1c.4: Apply policy to a scope (Azure CLI)
```bash
$ az policy assignment create \
> --policy allowedVMs \
> --name 'deny-non-compliant-vms' \
> --scope '/subscriptions/<Subscription ID>' -p
```
#### 1.1c.5 Delete policy assignment (Azure CLI)
```bash
$ az policy assignment delete \
> --name deny-non-compliant-vms
```
#### 1.2a.1 Enable diagnostics log collection with a storage account (Portal)
Browse to the resource itself. Alternatively, open __Azure Monitor__ and then the __Diagnostics Settings__ blade. From there you can view all eligible resouce types and view status of log collection. 
#### 1.2a.2 Enable diagnostics log collection with a storage account (PowerShell)
`Set-AzDiagnostic-Setting` requires resource ID of resource being enabled (can be found with `Get-AzResource`) and resource ID of storage account (passed to `StorageAccountId` parameter).

```powershell
$resource = Get-AzResource `
  -Name <resourceName> `
  -ResourceGroupName <resourceGroupName>
$storage = Get-AzResource `
  -Name <resourceName> `
  -ResourceGroupName <resourceGroupName>

Set-AzDiagnosticSetting `
  -ResourceId $resource.ResourceId `
  -StorageAccountId $storage.ResourceId `
  -Enabled $true
```
#### 1.2a.3 Enable diagnostics log streaming to an Event Hub (PowerShell) 
```powershell
$rule = Get-AzServiceBusRule `
  -ResourceGroup <resourceGroupName> `
  -Namespace <namespace> `
  -Topic <topic> `
  -Subscription <subscription> `
  -Name <ruleName> 
Set-AzDiagnosticSetting `
  -ResourceId $resource.ResourceId `
  -ServiceBusRuleId $rule.Id `
  -Enabled $true
```
#### 1.2a.4 Enable diagnostics logs collection in a Log Analytics workspace (PowerShell)
```powershell
$workspace = Get-AzOperationalInsightsWorkspace `
  -Name <workspaceName> `
  -ResourceGroupName <resourceGroupName> 
Set-AzDiagnosticSetting `
  -ResourceId $resource.ResourceId `
  -WorkspaceId $workspace.ResourceId `
  -Enabled $true
```
#### 1.2a.5 Enable diagnostic logs (Azure CLI)
`az monitor diagnostic-settings create` to enable diagnostic logs. `az resource show` to obtain resource ID.

```bash
resourceId=$(az resource show -resource-group resourceGroupName -name resourceName --resource-type resourceType --query id --output tsv)
```
#### 1.2a.6 Enable diagnostics log collection with a storage account (Azure CLI)
```bash
az monitor diagnostic-settings create \
  --name <diagnosticName> \
  --storage-account <storageId> \
  --resource <resouceId> \
  --resouce-group <resourceGroup> \
  --logs '[ {
  "category": <categoryName>,
  "enabled": true,
  "retentionPolicy": {
    "days": <numberOfDays>,
    "enabled": true } } ] '
```
#### 1.2a.7 Enable diagnostics log streaming to an Event Hub (Azure CLI)
```bash
az monitor diagnostic-settings create \
  --name <diagnosticName> \
  --event-hub-rule <eventHubRuleId> \
  --resource <targetResourceId> \
  --logs '[{
    "category": <categoryName>,
    "enabled": true }]'
```
#### 1.2a.8 Enable diagnostics logs collection in a Log Analytics workspace (Azure CLI)
```bash
az monitor diagnostic-settings create \
  --name <diagnosticName> \
  --workspace <logAnalyticsName> \
  --resource <resourceId> \
  --resouce-group <logAnalysticsWorkspaceResourceGroup> \
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
Remove-AzResourceGroup `
  -Name "hrgroup"
```
#### 1.3.2 Delete a resource group without confirmation (PowerShell)
```powershell
Remove-AzResourceGroup 
  -Name "hrgroup" 
  -Force
```
#### 1.3.3 Delete a resource group (CLI)
```bash
az group delete 
  --name hrgroup
```
#### 1.3.4 Delete a resource group without confirmation (CLI)
```bash
az group delete 
  --name hrgroup 
  --yes
```
#### 1.4b.1: Retrieve the definition of a role (PowerShell)
```powershell
Get-AzRoleDefinition `
  -Name "Virtual Machine Contributor" |
ConvertTo-Json
```
#### 1.4b.2: Retrieve the definition of a role (Azure CLI)
```bash
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
```bash
az role definition list --custom-role-only -o table
```
#### 1.4c.5: View all role assignments in a subscription (Azure CLI)
```bash
az role assignment list --all
```
#### 1.4c.6: Grant a user RBAC rights (PowerShell)
```powershell
New-AzRoleAssignment `
  -SignInName cloudadmin@opsgility.onmicrosoft.com `
  -RoleDefinitionName "Virtual Machine Contributor" `
  -ResourceGroupName ExamRefRG
```
#### 1.4c.7: Grant a user RBAC rights (Azure CLI)
```bash
az role assignment create \
  --assignee cloudadmin@opsgility.onmicrosoft.com
  --role "Virtual Machine Contributor" \
  --resource-group ExamRefRG
```
#### 1.4c.8: Grant a group RBAC rights (PowerShell)
```powershell
$group = Get-AzADGroup `
  -SearchString "Cloud Admins"
New-AzRoleAssignment `
  -ObjectId $group.Id `
  -RoleDefinitionName "Virtual Machine Contributor" `
  -ResourceGroupName ExamRefRG
```
#### 1.4c.9: Grant a group RBAC rights (Azure CLI)
```bash
groupid=$(az ad group list --query "[?displayName=='Cloud Admins'].objectId" -o tsv)
az role assignment create \
 --role "Virtual Machine Contributor" \
 --assignee-object-id $groupid \
 --resource-group ExamRefRG
```
#### 1.4c.10: Remove RBAC assignments from a user (PowerShell)
```powershell
Remove-AzRoleAssignment `
  -SignInName cloudadmin@opsgility.onmicrosoft.com
  -RoleDefinitionName "Virtual Machine Contributor" `
  -ResourceGroupName ExamRefRG
```
#### 1.4c.11: Remove RBAC assignments from a group (PowerShell)
```powershell
$group = Get-AzADGRoup -SearchString "Cloud Admins"
Remove-AzRoleAssignment `
  -ObjectId $group.Id `
  -RoleDefinitionName "Virtual Machine Contributor"
  -ResourceGroupName ExamRefRG
```
#### 1.4c.12: Remove RBAC assignments from a user (Azure CLI)
```bash
az role assignment delete \
  --role "Virtual Machine Contributor" \
  --assignee cloudadmin@opsgility.onmicrosoft.com \
  --resource-group ExamRefRG
```
#### 1.4c.13: Remove RBAC assignments from a group (Azure CLI)
```bash
groupid=$(az ad group list --query "[?displayName=='CloudAdmins'].objectId" -o tsv)
az role assignment delete \
  --role "Virtual Machine Contributor" \
  --assignee-object-id $groupid \
  --resource-group ExamRefRG
```
#### 2.1a.1: Create a storage account (Portal)
Click **Create a resouce**, then **Storage**, then **Storage account**. Choose a **globally** unique name for the account, containing lower-case characters and digits only.
#### 2.1a.2: Create a storage account (PowerShell)
```powershell
New-AzStorageAccount `
  -ResourceGroupName RG
  -Name mystorage112300
  -SkuName Standard_LRS
  -Location WestUS
  -Kind StorageV2
  -AccessTier Hot
```
#### 2.1a.3: Create a storage account (CLI)
```bash
az storage account create \
  --name $accountName \
  --resource-group $resourceGroup \
  --location $location \
  --sku $sku
```
#### 2.1a.4: Change storage account's access tier, without confirmation (PowerShell)
```powershell
Set-AzStorageAccount `
  -ResourceGroupName RG `
  -Name $accountName `
  -AccessTier Cool `
  -Force
```
#### 2.1b.1: Configure service endpoints (Portal)
1. Specify `Microsoft.Storage` in the service endpoint settings of the VNet subnet
2. Configure which VNets can access a particular storage account
#### 2.1c.1: Access storage account name and key (Portal)
1. Open storage account
2. Open **Access keys** blade
#### 2.1c.2: Create an Azure Key Vault (PowerShell)
```powershell
New-AzKeyVault `
  -VaultName vaultName `
  -ResourceGroupNAme rgName `
  -Location EastUS 
```
#### 2.1c.3: Store a software managed key in Azure Key Vault (PowerShell)
```powershell
Add-AzKeyVaultKey `
  -VaultName vaultName `
  -Name keyName `
  -Destination 'Software'
```
#### 2.1c.4: Retrieve a storage account key (PowerShell)
```powershell
$storageKey = Get-AzStorageAccountKey `
  -ResourceGrouupName rgName `
  -Name storageAccount `
```
#### 2.1c.5: Convert storage account key to secure string
```powershell
$secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force
```
#### 2.1c.6: Set secret value to be used in Azure Key Vault (PowerShell)
```powershell
$secret = Set-AzKeyVaultSecret `
  -VaultName vaultName `
  -Name $secretName `
  -SecretValue $secretvalue
```
#### 2.1c.7: Create an Azure Key Vault (Azure CLI)
```bash
az keyvault create \
  --name $vaultName \
  --resource-group $rgName \
  --location $location
```
#### 2.1c.8: Store a software managed key in Azure Key Vault (Azure CLI)
```bash
az keyvault key create \
  --vault-name $vaultName \
  --name $keyName \
  --protection "software"
```
#### 2.1c.9: Set secret value to be used in Azure Key Vault (Azure CLI)
```bash
az keyvault secret set \
  --vault-name $vaultName \
  --name $secretName \
  --value $secretValue
```
#### 2.1d.1: Create a SAS token for a specific storage blob (PowerShell)
```powershell
New-AzStorageBlobSASToken `
  -Container $container `
  -Blob $blob `
  -Permission "rwd" `
  -StartTime $startTime `
  -ExpiryTime $startTime.AddHours(4) `
  -Context $context
```
#### 2.1d.2: Create a SAS token for a specific storage blob (Azure CLI)
```bash
az storage blob generate-sas \
  --account-name "storageAccount" \
  --account-key $storageAccountKey \
  --container-name $container \
  --name $blobName \
  --permissions r \
  --expiry "2019-05-31"
```
#### 2.1e.1: Access Activity Log data (Portal)
1. Find **Management + Governance** in **All Services**
2. Open **Activity Log**
3. Click Logs icon at top of Activity Log view to select an existing Log Analytics (OMS) workspace or create a new one
#### 2.1f.1: Change replication mode of a storage account
```powershell
Set-AzStorageAccount `
  -ResourceGroupName $resourceGroup `
  -Name $accountName `
  -SkuName $type
```
#### 2.1f.2: Use async blob copy service to copy a file
```powershell
$blobCopyState = Start-AzStorageBlobCopy `
  -SrcBlob $blobName `
  -SrcContainer $srcContainer `
  -Context $srcContext `
  -DestContainer $destContainer `
  -DestBlob $vhdName
  -DestContext $destContext
```
#### 2.1f.2: Copy a blob from one storage account to another (PowerShell)
```powershell
$srcStorageKey = Get-AzStorageAccountKey `
 -ResourceGroupName $sourceRGName `
 -Name $srcStorageAccount

$destStorageKey = Get-AzStorageAccountKey `
 -ResourceGroupName $destRGName `
 -Name $destStorageAccount

$srcContext = New-AzStorageContext `
 -StorageAccountName $srcStorageAccount `
 -StorageAccountKey $srcStorageKey.Value[0]

$destContext = New-AzStorageContext `
 -StorageAccountNAme $destStorageAccount `
 -StorageAccountKey $destStorageKey.Value[0]

New-AzStorageContainer `
 -Name $destContainer `
 -Context $destContext

$copiedBlob = Start-AzStorageBlobCopy `
 -SrcBlob $blobName `
 -SrcContainer $srcContainer `
 -Context $srcContext `
 -DestContainer $destContainer `
 -DestBlob $blobName `
 -DestContext $destContext
```
#### 2.1f.3: Monitor progress of the async blob copy (PowerShell)
```powershell
PS C:\> $copiedBlob | Get-AzStorageBlobCopyState
```
#### 2.1f.4: Copy a blob from one storage account to another (Azure CLI)
```bash
az storage blob copy start \
 --account-name $destStorageAccount \
 --account-key $destStorageKey \
 --destination-blob $blobName \
 --source-account-name $srcStorageAccount \
 --source-container $srcContainer \
 --source-blob $blobName \
 --source-account-key $srcStorageKey
```
#### 2.1f.5: Monitor progress of the async blob copy (Azure CLI)
```bash
az storage blob show \
 --account-name $destStorageAccount \
 --account-key $destStorageKey \
 --container-name $destContainer \
 --name $blobName
```
#### 2.1f.6: Use AzCopy to copy a blob
```cmd
AzCopy \
 /Source:https://sourceblob.blob.core.windows.net/sourcecontainer/ \
 /Dest:https://deststorage.blob.core.windows.net/destcontainer/ \
 /SourceKey:sourcekey \
 /DestKey:destkey \
 /Pattern:disk1.vhd
```
#### 2.2a.1: Create a storage container (PowerShell)
Command                     | Effect
:---                        | :---
`New-AzStorageContainer`    | Create a container
`Set-AzStorageBlobContent`  | Create a blob within an existing container

```powershell
$storageKey = Get-AzStorageAccountKey `
  -Name $storageAccount `
  -ResourceGroupName $resourceGroup

$context = New-AzStorageContext `
  -StorageAccountName $storageAccount `
  -StorageAccountKey $storageKey.Value[0]

Set-AzCurrentStorageAccount `
  -Context $context

New-AzStorageContainer `
  -Name $container `
  -Permission Off

Set-AzStorageBlobContent `
  -File $localFile `
  -Container $container `
  -Blob $blobName
```
#### 2.2a.2: Create a storage container (Azure CLI)
`az storage container create` is used to create a storage account container; the parameter `public-access` is used to set permissions, and supported values include `off`, `blob`, and `container`
```bash
az storage container create \
  --account-name $storageaccount \
  --name $containername
  --public-access off
```
#### 2.2a.3: Upload a file (Azure CLI)
`az storage blob upload` is used to upload a file
```bash
az storage blob upload \
  --container-name $containerName \
  --account-name $accountName \
  --account-key $accountKey \
  --file $file \
  --name $blobName
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
PS C:\> $storageKey = Get-AzStorageAccountKey
>>  -ResourceGroupName $rgName
>>  -Name $storageAccount

PS C:\> $context = New-AzStorageContext
>>  -StorageAccountName $storageAccount
>>  -StorageAccountKey $storageKey.Value[0]

PS C:\> New-AzStorageShare
>>  -Name $shareName
>>  -Context $context
```
#### 2.3a.3: Create an Azure File Share (CLI)
```powershell
$ constring=$(az storage account show-connection-string -n $storageAccountName)

$ az storage share create \
>  --name $shareName \
>  --quota 2048 \
>  --connection-string $constring
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
$credential = New-Object System.Management.Automation.PSCredential `
  -ArgumentList "Azure\$storageName", $acctKey

New-PSDrive `
  -Name "Z" `
  -PSProvider FileSystem `
  -Root "\\$storageName.file.core.windows.net\$shareName" 
  -Credential $credential
```
#### 2.3a.7: Automatically reconnect after reboot in Windows
```
cmdkey \
  /add:storageAccountName.file.core.windows.net \
  /user:AZURE\storageAccountName \
  /pass:storageAccountKey
```
#### 2.3a.8: Connect to and mount an Azure File Share (Linux)
Mounting to `/logs`
```bash
sudo mount \
-t cifs //$storageAccount.file.core.windows.net/logs /logs \
-o vers=3.0,username=$storageAccount,password=$storageAccountKey,dir_mode=0777,file_mode=0777,sec=ntlmssp
```
#### 2.3b.1: Create the Azure File Sync Service (Portal)
Create a resource > **Storage** > **Azure File Sync**
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
#### 3.1a.1: Create an Azure VM (Portal)
...
#### 3.1a.2: Create an Azure VM (PowerShell)

Subtask sequence:
  - Login to Azure account
  - Create a new resource group
  - Create a public IP address
  - Add a rule to the network security group to allow RDP in
  - Apply the rules


Command sequence:
  - `Connect-AzAccount`
  - `New-AzResourceGroup`
  - `New-AzVirtualNetworkSubnetConfig`
  - `New-AzVirtualNetwork`
  - `New-AzPublicIpAddress`
  - `New-AzNetworkSecurityRuleConfig`
  - `New-AzNetworkSecurityGroup`
  - `New-AzVMConfig`
  - `Set-AzVMOperatingSystem`
  - `Set-AzVMSourceImage`
  - `Set-AzVMOSDisk`
  - `New-AzNetworkInterface`
  - `Add-AzVMNetworkInterface`
  - `New-AzVM`

```powershell
# Login to Azure account
Connect-AzAccount
# Create a new resource group 
New-AzResourceGroup ` 
  -Name $resourceGroupName `
  -Location $location

# Create a virtual network
$subnets = @()
$subnets += New-AzVirtualNetworkSubnetConfig `
  -Name $subnet1Name `
  -AddressPrefix $subnet1AddressPrefix
$subnets += New-AzVirtualNetworkSubnetConfig `
  -Name $subnet2Name `
  -AddressPrefix $subnet2AddressPrefix
$vnet = New-AzVirtualNetwork `
  -Name $vnetNAme `
  -Location $location `
  -AddressPrefix $vnetAddressSpace `
  -Subnet $subnets

# Create a public IP address
$pip = New-AzPublicIpAddress `
  -Name $ipName `
  -ResourceGroupName $rgNAme `
  -Location $location `
  -AllocationMethod Dynamic `
  -DomainNameLabel $dnsName

# Add a rule to the network security group to allow RDP in
$nsgRules = @()
$nsgRules += New-AzNetworkSecurityRuleConfig `
  -Name "RDP" `
  -Description "RemoteDesktop" `
  -Protocol Tcp `
  -SourcePortRange "*" `
  -DestinationPortRange "3389" `
  -SourceAddressPrefix "*" `
  -DestinationAddressPrefix "*" `
  -Access Allow `
  -Priority 110 `
  -Direction Inbound

# Apply the rules
$nsg = New-AzNetworkSecurityGroup `
  -ResourceGroupName $resourceGroupName `
  -Name "ExamREfNSG" `
  -SecurityRules $nsgRules `
  -Location $location

# Create a virtual machine configuration object with the `New-AzVMConfig` cmdlet
$vm = New-AzVMConfig
  -VMName $vmName `
  -VMSize $vmSize

# Specify operating system and credentials
Set-AzVMOperatingSystem `
  -Windows `
  -ComputerName $vmName `
  -Credential $cred `
  -ProvisionVMAgent `
  -VM $vm

# Specify the operating system image using `Set-AzVMSourceImage`
Set-AzVMSourceImage `
  -PublisherName $pubName `
  -Offer $offerName `
  -Skus $skuName `
  -Version "latest" `
  -VM $vm

Set-AzVMOSDisk `
  -CreateOption fromImage `
  -VM $vm

# Create the network interface for the VM
$nic = New-AzNetworkInterface `
  -Name $nicNAme `
  -ResourceGroupName $resourceGroupName `
  -Location $location `
  -SubnetId $vnet.Subnets[0].Id `
  -PublicIpAddressId $pip.Id `
  -NetworkSecurityGroupId $nsg.Id

Add-AzVMNetworkInterface `
  -VM $vm `
  -NetworkInterface $nic

# Provision the virtual machine with `New-AzVM`
New-AzVM `
  -ResourceGroupName $resourceGroupName `
  -Location $location
  -VM $vm
```

`New-AzVM` option     | Position  | Description
:---                  | :---      | :---
`-ResourceGroupName`  | 0         | Optional
`-Location`           | 1         | Optional
`-VM`                 | 2
`-Zone`               | 3         | Optional


```powershell
New-AzVM -ResourceGroupName "RG" -Name "VM" -Location "EastUS" -Size "Standard-B2s" -Credential (Get-Credential)
New-AzVM Greeks Socrates $vm
```

The `-Image` optional named parameter can be used to define other operating systems, and requires friendly image names. If a Linux image is provided, you should provide the `-Linux` switch parameter as well in order to specify a Linux-type disk file.
  - Win2016Datacenter (default)
  - Win2012R2Datacenter
  - Win2012Datacenter
  - Win2008R2SP1
  - UbuntuLTS
  - CentOS
  - CoreOS
  - Debian
  - openSUSE-Leap
  - RHEL
  - SLES

A custom image object can be built up and passed to `New-AzVM` through the `-VM` named parameter by using other commands:
```powershell
...
$vm = New-AzVMConfig -VMName $VMName -VMSize $VMSize
$vm = Set-AzVMOperatingSystem -VM $vm -Windows -ComputerName $ComputerName -Credential $Credential -Provision VMAgent -EnableAutoUpdate
$vm = Add-AzVMNetworkInterface -VM $vm -Id $NIC.Id
$vm = Set-AzVMSourceImage -VM $vm -PublisherName 'MicrosoftWindowsServer' -Offer 'WindowsServer' -Skus '2012-R2-Datacenter' -Version latest

New-AzVM -ResourceGroupName $ResourceGroupName -Location $LocationName -VM $vm
```
#### 3.1a.4: Capture a managed VM image (Portal)
#### 3.1a.5: Capture a managed VM image (PowerShell)
#### 3.1a.6: Capture a managed VM image (Azure CLI)
#### 3.1a.7: Create a VM from an image
#### 3.1a.04: Capture a managed VM image
#### 3.1a.05: Capture a managed VM image
#### 3.1a.06: Capture a managed VM image
#### 3.1a.07: Creating a VM from an image
#### 3.1a.08: Login to Azure (PowerShell)
#### 3.1a.09: Create a new resource group (PowerShell)
#### 3.1a.10: Create a virtual network (PowerShell)
#### 3.1a.11: Create a public IP address resource (PowerShell)
#### 3.1a.12: Add a rule to a network security group (PowerShell)
#### 3.1a.13: Create a network security group (PowerShell)
#### 3.1a.14: Specify size and availability of a virtual machine (PowerShell)
#### 3.1a.15: Set operating system and credentials of a virtual machine (PowerShell)
#### 3.1a.16: Specify an operating system image for a virtual machine (PowerShell)
#### 3.1a.17: Create a network interface for a virtual machine (PowerShell)
#### 3.1a.18: Login to Azure (Azure CLI)
#### 3.1a.19: Create a new resource group (Azure CLI)
#### 3.1a.20: Identify regions available to resources and resource groups (Azure CLI)
#### 3.1a.21: Create a simple virtual machine
#### 3.1a.22: Create a virtual network (Azure CLI)
#### 3.1a.23: Add subnets to a virtual network (Azure CLI)
#### 3.1a.24: Create a public IP address resource (Azure CLI)
#### 3.1a.25: Create a network security group (Azure CLI)
#### 3.1a.26: Add rules to a network security group (Azure CLI)
#### 3.1a.27: Create a network security group rule to allow incoming SSH connections (Azure CLI)
#### 3.1a.28: Create a network security group rule to allow incoming HTTP connections (Azure CLI)
#### 3.1a.29: Create a network interface for a virtual machine (Azure CLI)
#### 3.1a.30: Retrieve a list of marketplace images (Azure CLI)
#### 3.1a.32: Retrieve available VM sizes (Azure CLI)
#### 3.1a.33: Create a virtual machine (Azure CLI)
#### 3.1a.34: Specify a legacy unmanaged image for use in a new virtual machine (PowerShell)
#### 3.1a.35: Specify a legacy unmanaged image for use in a new virtual machine (Azure CLI)
#### 3.1a.36: Specify a managed image for use in a new virtual machine (PowerShell)
#### 3.1a.37: Specify a managed image for use in a new virtual machine (Azure CLI)
#### 3.1b.01: Create an availability set (Portal)
#### 3.1b.02: Create an availability set (PowerShell)
```powershell
New-AzavailabilitySet `
  -ResourceGroupName `
  -Location
  -PlatformUpdateDomainCount 10 `
  -PlatformFaultDomainCount 3 `
  -Sku "Aligned"
```
#### 3.1b.03: Create an availability set (CLI)
#### 3.1c.01: Resizing a VM (PowerShell)
#### 3.1c.02: Resizing a VM (Azure CLI)
#### 3.1e.01: Modify host cache setting on a virtual HD (Portal)
#### 3.1e.02: Modify host cache setting on a virtual HD (PowerShell)
#### 3.1e.03: Modify host cache setting on a managed virtual HD (Azure CLI)
#### 3.1e.04: Modify host cache setting on a unmanaged virtual HD (Azure CLI)
#### 3.1e.05: Create a new storage pool using all available disks (PowerShell)
#### 3.1f.01: Connecting to a Windows VM with remote desktop
#### 3.1f.02: Connecting to a Linux virtual machine using SSH
#### 3.1g.01: Enabling and configuring diagnostics (Windows)
#### 3.1g.02: Enabling and configuring diagnostics (Linux)
#### 3.1h.01: Creating a virtual machine scale set (Portal)
#### 3.1h.02: Creating a virtual machine scale set (PowerShell)
#### 3.1h.03: Creating a virtual machine scale set (CLI)
#### 3.2c.01: Deploy a template that creates a VM (Portal)
#### 3.2c.02: Deploy a template that creates a VM (PowerShell)
#### 3.2d.01: Deploy a template in Complete mode
#### 3.2e.01: Export deployment template (Portal)
#### 3.2e.02: Access template that represents current state of resource group
#### 3.2e.03: Export templates
#### 3.2e.04: Export all resources in a resource group as a template
#### 3.2e.05: Pass a template file during deployment
#### 3.3a.01: Add a data disk to an existing VM (Portal)
#### 3.3a.02: Attach a new managed disk to an existing VM
#### 3.3b.01: Add a new network interface to an existing VM
#### 3.3b.02: Attach a new network interface to an existing VM
#### 3.3c.01: View all available sizes in a location
#### 3.3c.02: Change VM to a new size
#### 3.3d.01: Move a VM to another resource group or subscription (Portal)
#### 3.3d.02: Move a resource to another resource group or subscription (PowerShell)
#### 3.3d.03: Move a resource to another resource group or subscription (Azure CLI)
#### 3.3e.01: Redeploy a VM
#### 3.3f.01: Package a DSC script into a zip file
#### 3.3f.02: Apply the PowerShell Desired State Configuration extension
#### 3.3f.03: Publish a packaged DSC script to a storage account
#### 3.3f.04: Use the custom script extension
#### 3.4a.01: Backup a VM with Azure Backup
#### 3.4d.01: Restore an Azure Backup recovery point as a new VM
#### 3.4d.02: Restore access to files in Azure Backup
#### 4.1d.01: Configure user-defined routes (Portal)
#### 4.1d.02: Configure user-defined routes (PowerShell)
#### 4.1d.03: Configure user-defined routes (Azure CLI)
#### 4.2a.01: Creating a VNet peering (Portal)
#### 4.2a.02: Creating a VNet peering (PowerShell)
#### 4.2a.03: Creating a VNet peering (Azure CLI)
#### 4.2b.01: Creating a VPN gateway and VNet-to-VNet connection (Portal)
#### 4.2b.02: Creating a VPN gateway and VNet-to-VNet connection (PowerShell)
#### 4.2b.03: Creating a VPN gateway and VNet-to-VNet connection (Azure CLI)
#### 4.3a.01: Creating DNS zones and DNS records (Portal)
#### 4.3a.02: Creating DNS zones and DNS records (PowerShell)
#### 4.3a.03: Creating DNS zones and DNS records (Azure CLI)
#### 4.3b.01: Configure custom DNS settings (Portal)
#### 4.3b.02: Configure custom DNS settings (PowerShell)
#### 4.3b.03: Configure custom DNS settings (Azure CLI)
#### 4.3c.01: Create private DNS zones
#### 4.4c.01: Implement Service Map (Portal)
#### 4.4c.02: Install Dependency Agent
#### 4.4c.03: Register a resource provider (PowerShell)
#### 4.4c.04: Register a resource provider (Azure CLI)
#### 4.4d.01: View effective security rules (Portal)
#### 4.4d.02: View effective security rules (PowerShell)
#### 4.4d.03: View effective security rules (Azure CLI)
#### 4.5a.01: Create an Azure load balancer (Portal)
#### 4.5a.02: Create an Azure load balancer (PowerShell)
#### 4.5a.03: Create an Azure load balancer (Azure CLI)
#### 4.5b.01: Enable basic-tier load-balancer logs
#### 4.6a.01: Install Network Performance Monitor (Portal)
#### 4.6a.02: Install Network Performance Monitor on a VM (Portal)
#### 4.6a.03: Connect on-premises server to Log Analytics
#### 4.6a.04: Configure Performance Monitor
#### 4.6a.05: Configure Service Connectivity Monitor
#### 4.6a.06: Configure ExpressRoute Monitor
#### 4.6c.01: Install Network Watcher VM extension (PowerShell)
#### 4.6c.02: Install Network Watcher VM extension (Azure CLI)
#### 4.6c.03: Use IP Flow Verify (Portal)
#### 4.6c.04: Use IP Flow Verify (PowerShell)
#### 4.6c.05: Use IP Flow Verify (Azure CLI)
#### 4.6c.06: Use Next Hop (Portal)
#### 4.6c.07: Use Next Hop (PowerShell)
#### 4.6c.08: Use Next Hop (Azure CLI)
#### 4.6c.09: Use Packet Capture (Portal)
#### 4.6c.10: Use Packet Capture (PowerShell)
#### 4.6c.11: Use Packet Capture (Azure CLI)
#### 4.6c.12: Use Network Topology (Portal)
#### 4.6c.13: Use Network Topology (PowerShell)
#### 4.6c.14: Use Network Topology (Azure CLI)
#### 4.6d.01: Use VPN Troubleshoot (Portal)
#### 4.6d.02: Use VPN Troubleshoot (PowerShell)
#### 4.6d.03: Use VPN Troubleshoot (Azure CLI)
#### 4.6e.01: Use Connection Troubleshoot (Portal)
#### 4.6e.02: Use Connection Troubleshoot (PowerShell)
#### 4.6e.03: Use Connection Troubleshoot (Azure CLI)
#### 4.6e.04: Use Connection Monitor (Portal)
#### 4.7a.01: Create a VPN Gateway (Portal)
#### 4.7a.02: Create a VPN Gateway (PowerShell)
#### 4.7a.03: Create a VPN Gateway (Azure CLI)
#### 4.7b.01: Create a site-to-site VPN (Portal)
#### 4.7b.02: Create a site-to-site VPN (PowerShell)
#### 4.7b.03: Create a site-to-site VPN (Azure CLI)
#### 4.7c.01: Creating an ExpressRoute circuit
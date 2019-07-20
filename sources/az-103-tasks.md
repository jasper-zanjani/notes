# Exam Ref AZ-103 Microsoft Azure Administrator, by Michael Washam, Jonathan Tuliani, and Scott Hoag
## Tasks 
#### 1.1a.1 Assign an RBAC role (Portal)
> AZ-103: 1.1a.1 (p. 4)

To assign an RBAC role to a subscription, open the __Subscription__, then the __Access Control (IAM)__ blades, then click __Add Role Assignment__. This will open a dialog box where you can select a __Role__ (e.g. Owner) then __Select__ a target principal.
#### 1.1b.1 Configure resource quotas
> AZ-103: 1.1b.1 (p. 9)
> - [x] Indexed\
> - [x] Anki?

To view resource quotas for a subscription, go to the subscription in Azure Portal and open the __Usage + quotas__ blade. From there you can select resources and then click the __Request Increase__ button. PowerShell commands used with resource quotas:
  - `Get-AzVMUsage`: view current usage of vCPU quotas
  - `Get-AzStorageUsage`: view current usage of storage service
#### 1.1b.2 Configure cost center quotas
> AZ-103: 1.1b.2 (p. 10)

Budgets can be viewed and administered in the __Cost Management + Billing__ blade. Users must be at least Reader to a subscription to view, and Contributor to create and manage, budgets. Specialized roles that grant access to Cost Management include
  - __Cost Management contributor__
  - __Cost Management reader__
To create a budget, open __Cost Management + Billing__, then __Subscriptions__, select a subscription, then click __Budgets__. Then click __+ Add__, which produces a Create budget blade. The created budget can be seen in the __Budgets__ blade. PowerShell commands used with budgets:
  - `Get-AzResourceGroup` retrieve Resource Group object
  - `Set-AzResourceGroup` apply a tag to a resource group with __no preexisting tags__
  - `.Tags` method that retrieves Tag collection from a resource group
  - `.Add()` method used to add tags to a resource group that __already has__ tags.
#### 1.1b.3 Tag a resource group that has not already been tagged (PowerShell)
> AZ-103: 1.1b.3 (p. 14)
> - [x] Indexed?
> - [x] Anki?

```powershell
$r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName hrgroup
Set-AzResource -Tag @{ CostCode="1001"; Environment="Production" } -ResourceId
$r.ResourceId -Force
```
#### 1.1b.4 Tag a resource group that already had been tagged (PowerShell)
> AZ-103: 1.1b.4 (p. 14)
> - [x] Indexed?
> - [x] Anki?

```powershell
$tags = (Get-AzResourceGroup -Name hrgroup).Tags
$tags.Add("Owner","user@contoso.com")
Set-AzResourceGroup -Tag $tags -Name hrgroup
```
Using the `Add()` method
```powershell
$r = Get-AzResource -ResourceName hrvm1 -ResourceGroupName hrgroup
$r.Tags.Add("Owner","user@contoso.com")
Set-AzResource -Tag $r.Tags -ResourceId $r.ResourceId -Force
```
#### 1.1c.1 Create a policy definition (Portal)
> AZ-103: 1.1c.1 (p. 16)

Open __All Services__, then __Policy__, then the __Definitions__ blade. Both builtin and custom policies can be managed here.
#### 1.1c.1 Register resource provider in subscription (Azure CLI)
> AZ-103: 1.1c.2 (p. 21)

Az CLI can be used to register the `Microsoft.PolicyInsights` resource provider is registered in the target subscription, a prerequisite for policy creation:
```bash
az provider register \
  --namespace 'Microsoft.PolicyInsights'
```
#### 1.1c.2 Define a policy (Azure CLI)
> AZ-103: 1.1c.3 (p. 21)

```bash
az policy definition create \
  --name 'allowedVMs' \
  --description 'Only allow virtual machines in the defined SKUs' 
  --mode ALL \
  --rules '{...}' \
  --params '{...}'
```
#### 1.1c.3 Apply policy to a scope (Azure CLI)
> AZ-103: 1.1c.3 (p. 21)

```bash
$ az policy assignment create \
> --policy allowedVMs \
> --name 'deny-non-compliant-vms' \
> --scope '/subscriptions/<Subscription ID>' -p
```
#### 1.1c.4 Delete policy assignment (Azure CLI)
> AZ-103: 1.1c.4 (p. 22)

```bash
$ az policy assignment delete \
> --name deny-non-compliant-vms
```
#### 1.2a.1 Enable diagnostics log collection with a storage account (Portal)
> AZ-103: 1.2a.1 (p. 27)

Browse to the resource itself. Alternatively, open __Azure Monitor__ and then the __Diagnostics Settings__ blade. From there you can view all eligible resouce types and view status of log collection. 
#### 1.2a.2 Enable diagnostics log collection with a storage account (PowerShell)
> AZ-103: 1.2a.2 (p. 29)
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 1.2a.3 (p. 30)
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 1.2a.4 (p. 30)
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 1.2a.6 (p. 29-30)

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
> AZ-103: 1.2a.7 (p. 30)

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
> AZ-103: 1.2a.8 (p. 30)

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
> AZ-103: 1.3.1 (p. 84)

```powershell
Remove-AzResourceGroup `
  -Name "hrgroup"
```
#### 1.3.2 Delete a resource group without confirmation (PowerShell)
> AZ-103: 1.3.2 (p. 84)

```powershell
Remove-AzResourceGroup 
  -Name "hrgroup" 
  -Force
```
#### 1.3.3 Delete a resource group (CLI)
> AZ-103: 1.3.3 (p. 84)

```bash
az group delete 
  --name hrgroup
```
#### 1.3.4 Delete a resource group without confirmation (CLI)
> AZ-103: 1.3.4 (p. 84)

```bash
az group delete 
  --name hrgroup 
  --yes
```
#### 1.4b.1: Retrieve the definition of a role (PowerShell)
> AZ-103: 1.4b.1 p. 88
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 1.4b.3 p. 90
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 1.4c.3 p. 96

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
> AZ-103: 1.4c.6 p. 96
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 1.4c.8 p. 97
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 1.4c.10 p. 97\
> Azure CLI equivalent: 1.4c.12
> - [x] Indexed?
> - [ ] Anki?

```powershell
Remove-AzRoleAssignment `
  -SignInName cloudadmin@opsgility.onmicrosoft.com
  -RoleDefinitionName "Virtual Machine Contributor" `
  -ResourceGroupName ExamRefRG
```
#### 1.4c.11: Remove RBAC assignments from a group (PowerShell)
> AZ-103: 1.4c.11 p. 97\
> Azure CLI equivalent: 1.4c.13

```powershell
$group = Get-AzADGRoup -SearchString "Cloud Admins"
Remove-AzRoleAssignment `
  -ObjectId $group.Id `
  -RoleDefinitionName "Virtual Machine Contributor"
  -ResourceGroupName ExamRefRG
```
#### 1.4c.12: Remove RBAC assignments from a user (Azure CLI)
> PowerShell equivalent: 1.4c.10

```bash
az role assignment delete \
  --role "Virtual Machine Contributor" \
  --assignee cloudadmin@opsgility.onmicrosoft.com \
  --resource-group ExamRefRG
```
#### 1.4c.13: Remove RBAC assignments from a group (Azure CLI)
> PowerShell equivalent: 1.4c.11

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
> AZ-103: 2.1a.2 p. 107
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 2.1a.4 p. 107
> - [x] Indexed?
> - [ ] Anki?

```powershell
Set-AzStorageAccount `
  -ResourceGroupName RG `
  -Name $accountName `
  -AccessTier Cool `
  -Force
```
#### 2.1b.1: Configure service endpoints (Portal)
> AZ-103: 2.1b.1 p. 112

1. Specify `Microsoft.Storage` in the service endpoint settings of the VNet subnet
2. Configure which VNets can access a particular storage account
#### 2.1c.1: Access storage account name and key (Portal)
1. Open storage account
2. Open **Access keys** blade
#### 2.1c.2: Create an Azure Key Vault (PowerShell)
> AZ-103: 2.1c.2 p. 115\
> Azure CLI equivalent: 2.1c.7
> - [x] Indexed?
> - [ ] Anki?

```powershell
New-AzKeyVault `
  -VaultName vaultName `
  -ResourceGroupNAme rgName `
  -Location EastUS 
```
#### 2.1c.3: Store a software managed key in Azure Key Vault (PowerShell)
> AZ-103: 2.1c.3 p. 115\
> Azure CLI equivalent: 2.1c.8
> - [x] Indexed?
> - [ ] Anki?

```powershell
Add-AzKeyVaultKey `
  -VaultName vaultName `
  -Name keyName `
  -Destination 'Software'
```
#### 2.1c.4: Retrieve a storage account key (PowerShell)
> AZ-103: 2.1c.4 p. 115
> - [x] Indexed?
> - [ ] Anki?

```powershell
$storageKey = Get-AzStorageAccountKey `
  -ResourceGrouupName rgName `
  -Name storageAccount `
```
#### 2.1c.5: Convert storage account key to secure string
> AZ-103: 2.1c.5 p. 115
> - [x] Indexed?
> - [ ] Anki?

```powershell
$secretvalue = ConvertTo-SecureString $storageKey[0].Value -AsPlainText -Force
```
#### 2.1c.6: Set secret value to be used in Azure Key Vault (PowerShell)
> AZ-103: 2.1c.6 p. 115\
> Azure CLI equivalent: 2.1c.9
> - [x] Indexed?
> - [ ] Anki?

```powershell
$secret = Set-AzKeyVaultSecret `
  -VaultName vaultName `
  -Name $secretName `
  -SecretValue $secretvalue
```
#### 2.1c.7: Create an Azure Key Vault (Azure CLI)
> AZ-103: 2.1c.7 p. 115\
> PowerShell equivalent: 2.1c.2
> - [ ] Indexed?
> - [ ] Anki?

```bash
az keyvault create \
  --name $vaultName \
  --resource-group $rgName \
  --location $location
```
#### 2.1c.8: Store a software managed key in Azure Key Vault (Azure CLI)
> AZ-103: 2.1c.8 p. 115\
> PowerShell equivalent: 2.1c.3
> - [ ] Indexed?
> - [ ] Anki?

```bash
az keyvault key create \
  --vault-name $vaultName \
  --name $keyName \
  --protection "software"
```
#### 2.1c.9: Set secret value to be used in Azure Key Vault (Azure CLI)
> AZ-103: 2.1c.9 p. 115\
> PowerShell equivalent: 2.1c.6
> - [ ] Indexed?
> - [ ] Anki?

```bash
az keyvault secret set \
  --vault-name $vaultName \
  --name $secretName \
  --value $secretValue
```
#### 2.1d.1: Create a SAS token for a specific storage blob (PowerShell)
> AZ-103: 2.1d.1 p. 117\
> Azure CLI equivalent: 2.1d.2
> - [x] Indexed?
> - [ ] Anki?

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
> AZ-103: 2.1d.2 p.117\
> PowerShell equivalent: 2.1d.1
> - [ ] Indexed?
> - [ ] Anki?

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
> AZ-103: 2.1f.1 p. 123
> - [x] Indexed?
> - [ ] Anki?

```powershell
Set-AzStorageAccount `
  -ResourceGroupName $resourceGroup `
  -Name $accountName `
  -SkuName $type
```
#### 2.1f.2: Use async blob copy service to copy a file
> AZ-103: 2.1f.2 p. 12
> - [x] Indexed?
> - [ ] Anki?

```powershell
$blobCopyState = Start-AzStorageBlobCopy `
  -SrcBlob $blobName `
  -SrcContainer $srcContainer `
  -Context $srcContext `
  -DestContainer $destContainer `
  -DestBlob $vhdName
  -DestContext $destContext
```
#### 2.2a.1 Create a storage container (PowerShell) 
> AZ-103: 2.2a.1 (p. 132)

`New-AzStorageContainer` require a storage context to be set, specifying the storage account anme and authentication credentials.

```powershell
$storageKey = Get-AzStorageAccountKey
  -Name $storageAccount `
  -ResourceGroupName $resourceGroup
$context = New-AzStorageContext `
  -StorageAccountName $storageAccount `
  -storageAccountKey $storageKey.Value[0]
Set-AzCurrentStorageAccount -Context $context
New-AzStorageContainer `
  -Name $container
  -Permission Off
```
#### 2.1f.2: Copy a blob from one storage account to another (PowerShell)
> AZ-103: 2.1f.2 p. 124-125
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
> AZ-103: 2.1f.3 p. 126\
> Azure CLI equivalent: 2.1f.5
```powershell
PS C:\> $copiedBlob | Get-AzStorageBlobCopyState
```
#### 2.1f.4: Copy a blob from one storage account to another (Azure CLI)
> PowerShell equivalent: 2.1f.2
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
> PowerShell equivalent: 2.1f.3
```bash
az storage blob show \
 --account-name $destStorageAccount \
 --account-key $destStorageKey \
 --container-name $destContainer \
 --name $blobName
```
#### 2.1f.6: Use AzCopy to copy a blob
> AZ-103: 2.1f.6 p. 127
```cmd
AzCopy \
 /Source:https://sourceblob.blob.core.windows.net/sourcecontainer/ \
 /Dest:https://deststorage.blob.core.windows.net/destcontainer/ \
 /SourceKey:sourcekey \
 /DestKey:destkey \
 /Pattern:disk1.vhd
```
#### 2.2a.1: Create a storage container (PowerShell)
> AZ-103: 2.2a.1 p. 132\
> Azure CLI equivalent: 2.2a.2
> - [ ] Indexed?
> - [ ] Anki?

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
> AZ-103: 2.2a.2 p. 133\
> PowerShell equivalent: 2.2a.1
> - [ ] Indexed?
> - [ ] Anki?

`az storage container create` is used to create a storage account container; the parameter `public-access` is used to set permissions, and supported values include `off`, `blob`, and `container`
```bash
az storage container create \
  --account-name $storageaccount \
  --name $containername
  --public-access off
```
#### 2.2a.3: Upload a file (Azure CLI)
> AZ-103: 2.2a.2 p. 133
> - [ ] Indexed?
> - [ ] Anki?

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
> AZ-103: 2.2b.1: p. 135
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
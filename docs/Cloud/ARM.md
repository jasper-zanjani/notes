

![](/img/arm.png)

**Azure Resource Manager (ARM)** is the interface for managing and organizing cloud resources. <sup>[?](https://docs.microsoft.com/en-us/learn/modules/build-azure-vm-templates/2-define-templates)</sup> 

An ARM **template** is a JSON file that precisely defines all ARM [resources](Resources) in a deployment. An ARM template can be deployed into a [resource group](Resources#resource-groups) as a single operation.

ARM templates are typically adapted from existing **Azure Quickstart** templates, which are contributed by the community and hosted on a [gallery](https://azure.microsoft.com/resources/templates). The **Azure Resource Manager Visualizer** assists users in seeing what the template will do before actually deploying.

The **Custom Script Extension** is a way to run scripts on Azure VMs and represents one of the ways to automate configuration of new deployments. <sup>[?](https://docs.microsoft.com/en-us/learn/modules/build-azure-vm-templates/5-add-a-resource?pivots=windows-cloud)</sup>

If you explort a deployment to a template, only the resources deployed in that deployment will be templatized. In the case of a complex deployment that had several phases, the ultimate result of the deployment can be obtained by exporting the template from the resource group.

## Structure

A template **must** have at least the following sections.

- `$schema`
- `contentVersion`
- [`resources`](#resources "Contains definitions of the deployment's resources")

A template may have the following optional sections

- [`parameters`](#parameters)
- [`variables`](#variables "Make templates easier to maintain")
- [`functions`](#functions)
- [`outputs`](#outputs)

```json
{
  "$schema": "http://schema.management.azure.com/schemas/2015-01-01/deploymentTemplate.json#",
  "contentVersion": "",
  "parameters": {  },
  "variables": {  },
  "functions": [  ],
  "resources": [  ],
  "outputs": {  }
}
```


### Resources

Create a public IP address.

```json
{ "type": "Microsoft.Network/publicIPAddresses",
  "apiVersion": "2018-08-01",
  "name": "[variables('publicIPAddressName')]",
  "location": "[parameters('location')]",
  "properties": {
    "publicIPAllocationMethod": "Dynamic",
    "dnsSettings": {
      "domainNameLabel": "[parameters('dnsLabelPrefix')]" } } }
```

Create a storage account
```json
{ "type": "Microsoft.Storage/storageAccounts",
  "apiVersion": "2019-06-01",
  "name": "[variables('storageAccountName')]",
  "location": "[parameters('location')]",
  "sku": {
    "name": "[parameters('storageAccountType')]"
  },
  "kind": "StorageV2",
  "properties": {} }
```

Create a Azure Data Explorer cluster
```json

```
### Parameters
```json
"adminUsername": {
  "type": "string",
  "metadata": {
    "description": "Username for the Virtual Machine." }},
"adminPassword": {
  "type": "securestring",
  "metadata": {
    "description": "Password for the Virtual Machine." }}
```

[Simple storage account](https://github.com/Azure/azure-quickstart-templates/blob/master/101-storage-account-create/azuredeploy.json#L27)
```json
{ "storageAccountType": {
    "type": "string",
    "defaultValue": "Standard_LRS",
    "allowedValues": [
      "Standard_LRS",
      "Standard_GRS",
      "Standard_ZRS",
      "Premium_LRS" ],
    "metadata": {
      "description": "Storage Account type" }},
  "location": {
    "type": "string",
    "defaultValue": "[resourceGroup().location]",
    "metadata": {
      "description": "Location for all resources." }}}
```
### Variables
```json
{ "nicName": "myVMNic",
  "addressPrefix": "10.0.0.0/16",
  "subnetName": "Subnet",
  "subnetPrefix": "10.0.0.0/24",
  "publicIPAddressName": "myPublicIP",
  "virtualNetworkName": "MyVNET" }
```
[Simple storage account](https://github.com/Azure/azure-quickstart-templates/blob/master/101-storage-account-create/azuredeploy.json#L27)
```json
{ "storageAccountName": "[concat('store', uniquestring(resourceGroup().id))]" },
```
### Functions
Create a globally unique name, useful for some resources that require it. `concat` is a built-in function.
```json
[ 
  { "namespace": "contoso",
    "members": {
      "uniqueName": {
        "parameters": [
          {
            "name": "namePrefix",
            "type": "string"
          }
        ],
        "output": {
          "type": "string",
          "value": "[concat(toLower(parameters('namePrefix')), uniqueString(resourceGroup().id))]" }}}}
]
```
### Outputs
```json
"outputs": {
  "hostname": {
    "type": "string",
    "value": "[reference(variables('publicIPAddressName')).dnsSettings.fqdn]"
  }
}
```
[Standard storage account](https://github.com/Azure/azure-quickstart-templates/tree/master/101-storage-account-create)
```json
{
  "$schema": "http://schema.management.azure.com/schemas/2015-01-01/deploymentTemplate.json#",
  "contentVersion": "",
  "parameters": {  },
  "variables": {  },
  "functions": [  ],
  "resources": [  ],
  "outputs": {
    "storageAccountName": {
      "type": "string",
      "value": "[variables('storageAccountName')]"
    }
  }
}
```
# Tasks
:point_right: [Deploy a VM quickstart template](https://docs.microsoft.com/en-us/learn/modules/build-azure-vm-templates/4-deploy-a-vm-quickstart-template?pivots=windows-cloud)
## Create a resource group

Create a resource group 
```sh
RESOURCEGROUP=learn-quickstart-vm-rg
LOCATION=eastus
az group create --name $RESOURCEGROUP --location $LOCATION
```
Create template parameters
## Validate template

```sh
USERNAME=azureuser
PASSWORD=$(openssl rand -base64 32)
DNS_LABEL_PREFIX=mydeployment-$RANDOM
```
```sh
az deployment group validate --resource-group $RESOURCEGROUP --template-uri "https://raw.githubusercontent.com/Azure/azure-quickstart-templates/master/101-vm-simple-windows/azuredeploy.json" --parameters adminUsername=$USERNAME --parameters adminPassword=$PASSWORD --parameters dnsLabelPrefix=$DNS_LABEL_PREFIX
```
## Deploy template

```sh
USERNAME=azureuser
PASSWORD=$(openssl rand -base64 32)
DNS_LABEL_PREFIX=mydeployment-$RANDOM
```
```sh
az deployment group create --name MyDeployment --resource-group $RESOURCEGROUP --template-uri "https://raw.githubusercontent.com/Azure/azure-quickstart-templates/master/101-vm-simple-windows/azuredeploy.json" --parameters adminUsername=$USERNAME --parameters adminPassword=$PASSWORD --parameters dnsLabelPrefix=$DNS_LABEL_PREFIX
```
Verify deployment
```sh
az deployment group show --name MyDeployment --resource-group $RESOURCEGROUP
```

## ARM
[?](https://docs.microsoft.com/en-us/learn/modules/build-azure-vm-templates/5-add-a-resource?pivots=windows-cloud)
```json
{
  "name": "[concat(variables('vmName'), '/', 'ConfigureIIS')]",
  "type": "Microsoft.Compute/virtualMachines/extensions",
  "apiVersion": "2018-06-01",
  "location": "[parameters('location')]",
  "properties": {
    "publisher": "Microsoft.Compute",
    "type": "CustomScriptExtension",
    "typeHandlerVersion": "1.9",
    "autoUpgradeMinorVersion": true,
    "settings": {
      "fileUris": [
        "https://raw.githubusercontent.com/MicrosoftDocs/mslearn-welcome-to-azure/master/configure-iis.ps1"
      ]
    },
    "protectedSettings": {
      "commandToExecute": "powershell -ExecutionPolicy Unrestricted -File configure-iis.ps1"
    }
  },
  "dependsOn": [
    "[resourceId('Microsoft.Compute/virtualMachines/', variables('vmName'))]"
  ]
}
```
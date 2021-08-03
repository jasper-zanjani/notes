

Pricing tiers:
- **Free/Shared**: uses a shared infrastructure with minimal storage. No options for deploying different staged versions, routing of traffic, or backups
- **Basic**: Dedicated compute for app, including avaiilability of SSL and manual scaling of app instance number.
- **Standard**: Daily backups, automatic scaling of app instances, deployment slots, and user routing with Traffic Manager
- **Premium**: more frequent backups, increased storage, and greater number of deployment slots and instance scaling options.




# Tasks
### List available runtimes

```sh
az webapp list-runtimes --linux
```

### Deploy image from [ACR](Azure-Container-Registry)
Sources
```sh
az webapp create --name $n --resource-group $g --plan $p --deployment-container-image-name $registry.azurecr.io/$image:latest
az webapp config appsettings set -n $n -g $g --settings "WEBSITES_PORT=8000"

# Service principal ID
$p = az webapp identity assign -n $n -g $g --query principalId -o tsv
$s = az account show --query id --output tsv

# Grant web app permission to access the container registry
az role assignment create --assignee $p --scope /subscriptions/$s/resourceGroups/$g/provides/Microsoft.ContainerRegistry/registries/$registry

# Deploy image (note that `$registry` is specified twice in this command)
az webapp config container set -n $n -g $g --docker-custom-image-name $registry.azurecr.io/$image:latest --docker-registry-server-url https://$registry.azurecr.io

# Restart web app after making changes
az webapp restart -n $n -g $g
```
### Deploy from GitHub
```sh
#!/bin/bash

# Replace the following URL with a public GitHub repo URL
gitrepo=https://github.com/Azure-Samples/php-docs-hello-world
webappname=mywebapp$RANDOM

# Create a resource group.
az group create --location westeurope --name myResourceGroup

# Create an App Service plan in `FREE` tier.
az appservice plan create --name $webappname --resource-group myResourceGroup --sku FREE

# Create a web app.
az webapp create --name $webappname --resource-group myResourceGroup --plan $webappname

# Deploy code from a public GitHub repository. 
az webapp deployment source config --name $webappname --resource-group myResourceGroup \
--repo-url $gitrepo --branch master --manual-integration

# Copy the result of the following command into a browser to see the web app.
echo http://$webappname.azurewebsites.net
```
```powershell
$gitrepo="<replace-with-URL-of-your-own-GitHub-repo>"
$gittoken="<replace-with-a-GitHub-access-token>"
$webappname="mywebapp$(Get-Random)"
$location="West Europe"

# Create a resource group.
New-AzResourceGroup -Name myResourceGroup -Location $location

# Create an App Service plan in Free tier.
New-AzAppServicePlan -Name $webappname -Location $location `
-ResourceGroupName myResourceGroup -Tier Free

# Create a web app.
New-AzWebApp -Name $webappname -Location $location -AppServicePlan $webappname `
-ResourceGroupName myResourceGroup

# SET GitHub
$PropertiesObject = @{
    token = $gittoken;
}
Set-AzResource -PropertyObject $PropertiesObject `
-ResourceId /providers/Microsoft.Web/sourcecontrols/GitHub -ApiVersion 2015-08-01 -Force

# Configure GitHub deployment from your GitHub repo and deploy once.
$PropertiesObject = @{
    repoUrl = "$gitrepo";
    branch = "master";
}
Set-AzResource -PropertyObject $PropertiesObject -ResourceGroupName myResourceGroup `
-ResourceType Microsoft.Web/sites/sourcecontrols -ResourceName $webappname/web `
-ApiVersion 2015-08-01 -Force
```


### Create Front Door

Add the `front-door` extension if using Azure CLI
```sh
az extension add --name front-door
```
Create web apps in two different regions.
```powershell
$webapp1 = New-AzWebApp -Name "WebAppContoso-$(Get-Random)" -Location centralus -ResourceGroupName myResourceGroupFD -AppServicePlan myAppServicePlanCentralUS
$webapp2 = New-AzWebApp -Name "WebAppContoso-$(Get-Random)" -Location southcentralus -ResourceGroupName myResourceGroupFD -AppServicePlan myAppServicePlanSouthCentralUS
```
```sh
az appservice plan create --name myAppServicePlanCentralUS --resource-group myRGFDCentral
az webapp create --name WebAppContoso1 --resource-group myRGFDCentral --plan myAppServicePlanCentralUS 

az appservice plan create --name myAppServicePlanSouthCentralUS -resource-groupg myRGFDSouthCentral
az webapp create --name WebAppContoso2 --resource-group myRGFDSouthCentral --plan myAppServicePlanSouthCentralUS
```
Create a frontend object
![](/img/az-front-door-frontend.png)

```powershell
# Create a unique name
$fdname = "contoso-frontend-$(Get-Random)"

#Create the frontend object
$FrontendEndObject = New-AzFrontDoorFrontendEndpointObject `
-Name "frontendEndpoint1" `
-HostName $fdname".azurefd.net"
```
Create the backend pool
![](/img/az-front-door-backend.png)
```powershell
# Create backend objects that points to the hostname of the web apps
$backendObject1 = New-AzFrontDoorBackendObject `
-Address $webapp1.DefaultHostName
$backendObject2 = New-AzFrontDoorBackendObject `
-Address $webapp2.DefaultHostName

# Create a health probe object
$HealthProbeObject = New-AzFrontDoorHealthProbeSettingObject `
-Name "HealthProbeSetting"

# Create the load balancing setting object
$LoadBalancingSettingObject = New-AzFrontDoorLoadBalancingSettingObject `
-Name "Loadbalancingsetting" `
-SampleSize "4" `
-SuccessfulSamplesRequired "2" `
-AdditionalLatencyInMilliseconds "0"

# Create a backend pool using the backend objects, health probe, and load balancing settings
$BackendPoolObject = New-AzFrontDoorBackendPoolObject `
-Name "myBackendPool" `
-FrontDoorName $fdname `
-ResourceGroupName myResourceGroupFD `
-Backend $backendObject1,$backendObject2 `
-HealthProbeSettingsName "HealthProbeSetting" `
-LoadBalancingSettingsName "Loadbalancingsetting"

New-AzFrontDoor `
-Name $fdname `
-ResourceGroupName myResourceGroupFD `
-RoutingRule $RoutingRuleObject `
-BackendPool $BackendPoolObject `
-FrontendEndpoint $FrontendEndObject `
-LoadBalancingSetting $LoadBalancingSettingObject `
-HealthProbeSetting $HealthProbeObject
```
```sh
az network front-door create \
--resource-group myRGFDCentral \
--name contoso-frontend \
--accepted-protocols http https \
--backend-address webappcontoso1.azurewebsites.net webappcontoso2.azurewebsites.net
```




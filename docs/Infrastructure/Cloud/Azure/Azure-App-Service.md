Web applications must be organized under an **App Service Plan** resource.
App service plans have various pricing tiers:

- **Free/Shared**: uses a shared infrastructure with minimal storage. No options for deploying different staged versions, routing of traffic, or backups
- **Basic**: Dedicated compute for app, including avaiilability of SSL and manual scaling of app instance number.
- **Standard**: Daily backups, automatic scaling of app instances, deployment slots, and user routing with Traffic Manager
- **Premium**: more frequent backups, increased storage, and greater number of deployment slots and instance scaling options.

```sh
az appservice plan create -g $g -n $p
    --is-linux

az webapp list-runtimes --linux

az webapp create -n $n -g $g 
    --plan $p
```

```sh title="Deploy from GitHub"
az appservice plan create -g $rg -n $p
    --sku FREE

az webapp create -g $rg -n $webappname 
    --plan $p

az webapp deployment source config -g $rg -n $webappname 
    --repo-url $gitrepo 
    --branch master 
    --manual-integration

# Web app will be available at http://$webappname.azurewebsites.net
```


```sh title="Deploy image from Azure Container Registry"
az webapp create -g $g -n $n
    --plan $p 
    --deployment-container-image-name $registry.azurecr.io/$image:latest

az webapp config appsettings set -g $g -n $n 
    --settings "WEBSITES_PORT=8000"

# Service principal ID
$p = az webapp identity assign -g $g -n $n -o tsv
    --query principalId 

$s = az account show -o tsv
    --query id 

# Grant web app permission to access the container registry
az role assignment create 
    --assignee $p 
    --scope /subscriptions/$s/resourceGroups/$g/provides/Microsoft.ContainerRegistry/registries/$registry

# Deploy image
az webapp config container set -g $g -n $n 
    --docker-custom-image-name $registry.azurecr.io/$image:latest 
    --docker-registry-server-url https://$registry.azurecr.io

az webapp restart -n $n -g $g
```

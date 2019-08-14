# Azure CLI

## Extensions
### Azure DevOps CLI
Command groups:
  - `pipelines`
  - `boards`
  - `repos`
  - `artifacts`
Command subgroups:
  - `admin` administrative operations
  - `extension` manage extensions
  - `project` manage team projects
  - `security`
  - `service-endpoint`
  - `team`
  - `user`
  - `wiki`

#### Install DevOps CLI
```sh
az extension add --name azure-devops
```
#### Display help for Azure Devops extension
```sh
az devops -h
```
#### Display help for a command group
```sh
az pipelines --help
```
#### Create a pipeline interactively
This command will produce interactive prompts to fill in parameters.
```sh
az pipelines create --name "Express.CI"
```
## Sources
  A. "Working with Azure DevOps using the Azure DevOps CLI". [YouTube](https://www.youtube.com/watch?time_continue=7&v=DiztcJOZvZo)
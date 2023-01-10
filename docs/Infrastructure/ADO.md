# Azure DevOps

## Azure CLI

There is an [Azure DevOps extension](https://learn.microsoft.com/en-us/azure/devops/cli/?view=azure-devops) for the Azure CLI.

```sh
# Installation and configuring defaults
az extension add --name azure-devops
az devops configure --defaults organization=$ORG
az devops configure --defaults project=$PROJECT

# Display users
az devops user list --organization $ORG

# Display a single user
az devops user show --organization $ORG --user $USER

# The extension must be updated separately from the core Azure CLI
az upgrade
az extension update --name azure-devops 
```


## Pipelines

Pipelines are used to automate the building of source code, including executing associated tasks like unit tests and packaging.
A pipeline is started by a **trigger** and made up of one or more **stages**, each of which can have one or more **jobs**.
Every execution of a pipeline, or a **run**, produces an **artifact**.

The simplest possible pipeline is a YAML file with a single line defining a trigger. 
Creating a new repo with a single YAML file with the following content will allow a Pipeline to then be created, but not run.
```yaml
trigger: none # (1)
```

1. A [push trigger](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/trigger?view=azure-pipelines#trigger-none) specifies which branches cause a continuous integration build to run. [**trigger: none**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/trigger?view=azure-pipelines#trigger-none) disables CI triggers.


Pipelines has some functionality with the [Azure DevOps extension to Azure CLI](#azure-cli).
```sh
az pipelines runs list --query '[*].result' # (1)
az pipelines run --id 1 --parameters "name=Dgiapusccu pool=Work" # (2)
az pipelines delete --id 1
```

1. Like other JSON output from the Azure CLI, JMESPATH queries can be passed to the **--query** option to filter results.
2. The **--parameters** options appears to be relatively new and buggy. The help indicates that multiple space-delimited key-value pairs should be able to be passed, however this appears not to be the case.

#### Agent

An [**agent**](https://learn.microsoft.com/en-us/azure/devops/pipelines/agents/agents?view=azure-devops&tabs=browser) represents compute infrastructure with installed agent software. Agents can be Microsoft-hosted (i.e. Azure VMs created specifically for the job and discarded after use) or self-hosted.
Agents are organized into **pools**; an agent instance can only belong to a single pool, **unless** more than one agent is installed.

The agent software package contains several shell scripts that provide various ways of running and managing the agent.

- **config.sh** must be run to configure the agent after installation by providing the server URL and PAT token.
- **run.sh** allows manual, interactive execution of the agent software
- **svc.sh** allows management of the agent software as a SystemD service. The service itself is named according to the pattern **vsts.agent.[ORGANIZATION].[AGENTPOOL].[AGENTNAME].service**.

??? info "Self-hosted agent setup"

    Because the agent software itself is based on .NET Core 3.1, some operating systems such as Ubuntu 22.04 are not compatible.
    Some like CentOS 9 have an unsupported version of OpenSSL installed, which results in the configuration script producing a libssl error.
    CentOS 9 provides OpenSSL 1.1.1k libraries in a separate package:
    ```sh
    dnf install compat-openssl11
    ```

    Also note it appears that the **git** utility needs to be installed, at least on Red Hat derivatives like CentOS, although it doesn't appear to be explicitly installed by the installdependencies.sh script.
    This may be because git is assumed to exist on Ubuntu.

### Tasks

This pipeline will place a short message in the user directory of the service account running the self-hosted agent.

```yaml title="Hello, World!"
trigger: none
jobs:
- job: HelloWorld
  pool: Hyper-V
  displayName: Hello, World!
  timeoutInMinutes: 0
  steps:
  - checkout: self  
  - bash: |
      echo "Hello, World!" > ~/hello
```

This example can be developed further to provide the ability to choose between agent pools.
Note the mustache syntax used for interpolating this parameter value into the value of **jobs.job.pool**.

```yaml hl_lines="3-8 11"
trigger: none
parameters:
- name: pool
  displayName: Agent pool
  default: Home
  values:
  - Home
  - Work
jobs:
- job: HelloWorld
  pool: ${{ parameters.pool }}
  displayName: Hello, World!
  steps:
  - checkout: self  
  - bash: |
      echo "Hello, World!" > ~/hello
```

A textbox can be created by defining a parameter of **type: string**.

```yaml hl_lines="9-12 20"
trigger: none
parameters:
- name: pool
  displayName: Agent pool
  default: Home
  values:
  - Home
  - Work
- name: name
  displayName: Name to be greeted
  type: string
  default: World
jobs:
- job: HelloWorld
  pool: ${{ parameters.pool }}
  displayName: Hello, World!
  steps:
  - checkout: self  
  - bash: |
      echo "Hello, ${{ parameters.name  }}!" > ~/hello
```

#### extends

```yaml title="hw-extends.yml"

```

## Wiki

ADO offers the opportunity to create wikis for repos ("codewiki") or projects ("projectwiki").
These can also be done through the [CLI](https://learn.microsoft.com/en-us/azure/devops/project/wiki/manage-wikis?view=azure-devops#create-a-wiki-page).

```sh title="ADO wikis"
az devops wiki list
```
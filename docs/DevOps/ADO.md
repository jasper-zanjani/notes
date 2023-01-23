# Azure DevOps

TODO:

- [Resources](https://learn.microsoft.com/en-us/azure/devops/pipelines/process/resources?view=azure-devops&tabs=schema) represent sources of pipelines, builds, repositories, **containers**, packages, and webhooks.
    - What is the significance of the containers?
- templates?

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

ADO offers the opportunity to create wikis for repos ("codewiki") or projects ("projectwiki").
These can also be done through the [CLI](https://learn.microsoft.com/en-us/azure/devops/project/wiki/manage-wikis?view=azure-devops#create-a-wiki-page).

```sh title="ADO wikis"
az devops wiki list
```

## Pipelines

Pipelines are used to automate the building of source code, including executing associated tasks like unit tests and packaging.
Every execution of a pipeline, or a **run**, produces an **artifact**.

A pipeline is started by a **trigger** and made up of one or more **stages**, each of which can have one or more **jobs**, which can further contain a number of **steps**.

The simplest possible pipeline is a YAML file with a single line defining a trigger. 
Creating a new repo with a single YAML file with the following content will allow a Pipeline to then be created, but not run.

```yaml
trigger: none # (1)
```

1. A [push trigger](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/trigger?view=azure-pipelines#trigger-none) specifies which branches cause a continuous integration build to run. [**trigger: none**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/trigger?view=azure-pipelines#trigger-none) disables CI triggers.

Simple pipelines can [omit](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/pipeline?view=azure-pipelines) the stages and [**jobs**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/jobs?view=azure-pipelines) container and directly specify the steps keyword.
In this case the pipeline is said to have a single implicit stage, as well as a single implicit job.
This single-stage, single-job pipeline will place a short message in the user directory of the service account running the self-hosted agent.

```yaml
trigger: none
pool: Hyper-V # (1)
steps:
- checkout: self  
- bash: echo "Hello, World!" > ~/hello
```

1. Without the [pool](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/pool?view=azure-pipelines) property, ADO will allocate a VM from the cloud.

Here the stages and jobs lists are made explicit. 

```yaml title="Hello, World!"
trigger: none
pool: Hyper-V
stages:
- stage: HelloWorld # (1)
  displayName: Hello, World! stage
  jobs:
  - job: HelloWorld # (1)
    displayName: Hello, World! job
    steps:
    - checkout: self  
    - bash: echo "Hello, World!" > ~/hello
```

1. Values for **stages.stage** and **jobs.job** must be an alphanumeric string with no spaces.
Both also expose an optional **displayName** property that appears in the web interface.

Pipelines has some functionality with the [Azure DevOps extension to Azure CLI](#azure-cli).

```sh
az pipelines runs list --query '[*].result' # (1)
az pipelines run --id 1 --parameters "name=Dgiapusccu pool=Work" # (2)
az pipelines delete --id 1
```

1. Like other JSON output from the Azure CLI, JMESPATH queries can be passed to the **--query** option to filter results.
2. The **--parameters** options appears to be relatively new and buggy. The help indicates that multiple space-delimited key-value pairs should be able to be passed, however this appears not to be the case.

Scheduled triggers can be defined with the  [**schedules**](https://learn.microsoft.com/en-us/azure/devops/pipelines/process/scheduled-triggers) key.

```yaml
trigger: none
schedules:
- cron: "0 3 * * *"
  displayName: Daily 3 AM scan
  branches:
    include:
    - main
  always: true # (1)
```

1. [**always**](https://learn.microsoft.com/en-us/azure/devops/pipelines/process/scheduled-triggers#running-even-when-there-are-no-code-changes) ensures that the pipeline runs even when there are no code changes.

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

#### Secure files

[Secure files](https://learn.microsoft.com/en-us/azure/devops/pipelines/library/secure-files?view=azure-devops) are one of two types of files that can be made available via the [Library](https://learn.microsoft.com/en-us/azure/devops/pipelines/library/?view=azure-devops).
Secure files provide a way to store files that can be shared across pipelines, especially security-related items like signatures and keys.

```yaml title="Consume secure file" hl_lines="1-5"
- task: DownloadSecureFile@1
  name: caCertificate
  displayName: 'Download CA certificate'
  inputs:
    secureFile: 'myCACertificate.pem'

- script: |
    echo Installing $(caCertificate.secureFilePath) to the trusted CA directory...
    sudo chown root:root $(caCertificate.secureFilePath)
    sudo chmod a+r $(caCertificate.secureFilePath)
    sudo ln -s -t /etc/ssl/certs/ $(caCertificate.secureFilePath)
```

## Tasks


### MOTD

**/etc/motd** contains a message that is displayed to users who login for the first time in that day. 
It is similar to a Hello, World! and can be developed from this example pipeline.

```yaml title="Hello, World!"
trigger: none
pool: Hyper-V
jobs:
- job: HelloWorld # (1)
  displayName: Hello, World! job
  steps:
  - checkout: self  
  - bash: echo "Hello, World!" > ~/hello
```

This example can be developed further to provide the ability to choose between agent pools.
Note the `${{ ... }}` syntax used for referencing the parameter value in [**jobs.job.pool**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/jobs-job?view=azure-pipelines).

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
  pool: ${{ parameters.pool }} # (1)
  displayName: Hello, World! job
  steps:
  - checkout: self  
  - bash: echo "Hello, World!" > ~/hello
```

1. It is also possible to specify the agent pool at [**stages.stage**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/stages-stage?view=azure-pipelines):
```yaml hl_lines="5"
# ...
stages:
- stage: HelloWorldStage
  displayName: Hello, World! stage
  pool: ${{ parameters.pool }}
  jobs:
  # ...
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
  displayName: Hello, World! job
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self  
  - bash: echo "Hello, ${{ parameters.name  }}!" > ~/hello
```

#### Ansible

If the ADO agent is also an Ansible control host, with properly defined sudo permissions, it can be used to set the motd on a managed host.

```yaml hl_lines="20"
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
- job: HelloWorldJob
  displayName: Hello, World! job
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self
  - bash: |
      ansible all -m copy -a 'dest=/etc/motd content="Hello, ${{ parameters.name }}!"'
```

#### extends

The [**extends**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/pipeline?view=azure-pipelines#pipeline-extends) keyword can be used to remove complexity from a pipeline.
Parameters defined in the parent must be passed to the child explicitly, and they must be defined again within the child to make them available to any template experssions.

```yaml title="pipeline.yml" hl_lines="13-17"
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
extends:
  template: jobs.yml
  parameters:
    pool: ${{ parameters.pool }}
    name: ${{ parameters.name }}
```

```yaml title="jobs.yml" hl_lines="1-3"
parameters: # (1)
- name: pool
- name: name
jobs:
- job: HelloWorldJob
  displayName: Hello, World! job
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self
  - bash: |
      ansible all -m copy -a 'dest=/etc/motd content="Hello, ${{ parameters.name }}!"'
```

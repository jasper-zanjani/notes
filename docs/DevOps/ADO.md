# Azure Devops

#### Agent

An [**agent**](https://learn.microsoft.com/en-us/azure/devops/pipelines/agents/agents?view=azure-devops&tabs=browser) represents compute infrastructure with installed agent software. Agents can be Microsoft-hosted (i.e. Azure VMs created specifically for the job and discarded after use) or self-hosted.
Agents are organized into **pools**; an agent instance can only belong to a single pool, **unless** more than one agent is installed.

The agent software package contains several shell scripts that provide various ways of running and managing the agent.

- **config.sh** must be run to configure the agent after installation by providing the server URL and PAT token.
- **run.sh** allows manual, interactive execution of the agent software
- **svc.sh** allows management of the agent software as a SystemD service. The service itself is named according to the pattern **vsts.agent.[ORGANIZATION].[AGENTPOOL].[AGENTNAME].service**.

??? info "Self-hosted agent setup"

    Because the agent software itself is based on .NET Core 3.1, some operating systems (such as Ubuntu 22.04) are not compatible.
    Some like CentOS 9 have an unsupported version of OpenSSL installed, which results in the configuration script producing a libssl error.
    CentOS 9 provides OpenSSL 1.1.1k libraries in a separate package:

    ```sh
    dnf install compat-openssl11
    ```

    Also note it appears that the **git** utility needs to be installed on Red Hat derivatives like CentOS, although it doesn't appear to be explicitly installed by the installdependencies.sh script.
    This may be because git is assumed to exist on Ubuntu.

    The agent software package must be downloaded from ADO, and a personal access token must be created with the [**Agent Pools (read, manage)** scope](https://learn.microsoft.com/en-us/azure/devops/pipelines/agents/v2-linux?view=azure-devops#authenticate-with-a-personal-access-token-pat).

    ```sh
    wget "https://vstsagentpackage.azureedge.net/agent/3.218.0/vsts-agent-linux-x64-3.218.0.tar.gz"
    mkdir agent; cd agent
    tar xfz "vsts-agent-linux-x64-3.218.0.tar.gz"
    ./config.sh
    sudo ./svc.sh install
    sudo ./svc.sh run
    ```

#### Azure CLI

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

# Upgrade Azure CLI
az upgrade # (1)!
```

1. 
```sh
# The extension used to need to be updated separately from the core Azure CLI
az extension list-versions --name azure-devops
az extension update --name azure-devops 
```

ADO offers the opportunity to create wikis for repos ("codewiki") or projects ("projectwiki").
These can also be done through the [CLI](https://learn.microsoft.com/en-us/azure/devops/project/wiki/manage-wikis?view=azure-devops#create-a-wiki-page).

```sh title="ADO wikis"
az devops wiki list
```

A separate command group for Azure Pipelines is installed with the azure-devops extension, with limited functionality.

```sh
az pipelines runs list --query '[*].result' # (1)
az pipelines run --id 1 --parameters "name=Dgiapusccu pool=Work" # (2)
az pipelines delete --id 1
```

1. Like other JSON output from the Azure CLI, JMESPATH queries can be passed to the **--query** option to filter results.
2. The **--parameters** options appears to be relatively new and buggy. The help indicates that multiple space-delimited key-value pairs should be able to be passed, however this appears not to be the case.

#### Force push

Git force-push is specifically disabled for the main branch by default.
This setting can only be changed by [setting branch permissions](https://learn.microsoft.com/en-us/azure/devops/repos/git/branch-permissions?view=azure-devops) that take effect for the main branch across the entire organization.
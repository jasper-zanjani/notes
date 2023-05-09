# Automation using Azure DevOps and Ansible

<!-- TODO:

- [Resources](https://learn.microsoft.com/en-us/azure/devops/pipelines/process/resources?view=azure-devops&tabs=schema) represent sources of pipelines, builds, repositories, **containers**, packages, and webhooks.
    - What is the significance of the containers?
- templates? -->


**Azure Pipelines** are used to automate the building of source code, including executing associated tasks like unit tests and packaging.
Every execution of a pipeline, or a **run**, produces an **artifact**.

Pipelines makes use of several [concepts](https://learn.microsoft.com/en-us/azure/devops/pipelines/get-started/key-pipelines-concepts?view=azure-devops).

- A pipeline is started by a **trigger** 
- A pipeline is made up of one or more **stages**, each of which can have one or more **jobs**
- Each **job** runs on an [**agent**](ADO/#agent) and can be made of one or more **steps** or **tasks** which are run sequentially.
- A [**task**](https://learn.microsoft.com/en-us/azure/devops/pipelines/tasks/reference/?view=azure-pipelines&viewFallbackFrom=azure-devops) refers to a predefined action

The simplest possible pipeline is a YAML file with a single line defining a trigger. 
Creating a new repo with a single YAML file with only the [**trigger**](#trigger) keyword defined will allow a Pipeline to then be created.
But attempting to run it will produce an error reading "The pipeline must contain at least one stage with no dependencies."

```yaml title="pipeline.yml"
trigger: none
```



Simple pipelines can [omit](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/pipeline?view=azure-pipelines) the stages and [**jobs**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/jobs?view=azure-pipelines) container and directly specify the steps keyword.
In this case the pipeline is said to have a single **implicit** stage, as well as a single **implicit** job.

This single-stage, single-job pipeline will place a short message in the user directory of the service account of a self-hosted agent.

```yaml
trigger: none
pool: Hyper-V # (1)!
steps:
- checkout: self  
- bash: | # (2)!
    echo "Hello, World!" > ~/hello
```

1. Without the [pool](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/pool?view=azure-pipelines) property, ADO will allocate a VM from the cloud.
2. The pipe symbol here represents the [**block style indicator**](https://yaml-multiline.info/), one of many formats supported by YAML for multiline strings.

Here the stages and jobs lists are made explicit. 

```yaml
trigger: none
pool: Hyper-V
stages:
- stage: helloWorldStage # (1)
  jobs:
  - job: helloWorldJob
    steps:
    - checkout: self  
    - bash: |
        echo "Hello, World!" > ~/hello
```

1. Values for **stages.stage** and **jobs.job** must be an alphanumeric string with no spaces.
Both also expose an optional **displayName** property that appears in the web interface.

This example can be developed further to provide the ability to choose between agent pools using [**templates**](https://learn.microsoft.com/en-us/azure/devops/pipelines/process/templates?view=azure-devops), which define reusable content such as parameters.

[**Parameters**](https://learn.microsoft.com/en-us/azure/devops/pipelines/process/templates?view=azure-devops#parameters) must contain a name and data type, for example this string.
Parameters are references using the **${{ ... }}** syntax. 

```yaml hl_lines="3-5 10"
trigger: none
parameters:
- name: name
  type: string
  default: World
jobs:
- job: helloWorldJob
  steps:
  - checkout: self  
  - bash: echo "Hello, ${{ parameters.name  }}!" > ~/hello
```

Enums, rendered as dropdowns, are defined using a list of values placed under the **values** key.

```yaml hl_lines="3-7 13"
trigger: none
parameters:
- name: pool
  default: Home
  values:
  - Home
  - Work
- name: name
  type: string
  default: World
jobs:
- job: helloWorld
  pool: ${{ parameters.pool }} # (1)!
  steps:
  - checkout: self  
  - bash: |
      echo "Hello, ${{ parameters.name }}!" > ~/hello
```

1. It is also possible to specify the agent pool at [**stages.stage**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/stages-stage?view=azure-pipelines):
```yaml hl_lines="5"
stages:
- stage: helloWorldStage
  pool: ${{ parameters.pool }}
  jobs:
# ...
```

**/etc/motd** contains a message that is displayed to users who login for the first time in that day. 
If the ADO agent is also an **Ansible** control host, with properly defined sudo permissions, it can be used to set the motd on a managed host.

Ensure that the control node has [privilege escalation enabled](Ansible/#setup).

```yaml hl_lines="17"
trigger: none
parameters:
- name: pool
  default: Home
  values:
  - Home
  - Work
- name: name
  type: string
  default: World
jobs:
- job: helloWorldJob
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self
  - bash: |
      ansible all -m copy -a 'dest=/etc/motd content="Hello, ${{ parameters.name }}!"'
```

Instead of running an Ansible ad-hoc command, we can create a [**role**](Ansible/#role), which groups content in a way that allows Ansible content to be shared.

Here, the pipeline executes the motd-role role which is specified in the requirements file and defined in a separate repo.
The pipeline parameter is passed to the playbook via the [**--extra-vars**](Ansible/#extra-vars) option.

```yaml hl_lines="14-16"
trigger: none
parameters:
- name: pool
  default: Home
  values:
  - Home
  - Work
jobs:
- job: HelloWorldJob
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self
  - bash: |
      ansible-galaxy role install -r ansible/requirements.yml -p ansible/roles -f 
      ansible-playbook ansible/playbook.yml \
        --extra-vars "greet_name=${{parameters.name}}"
# (1)!
```

1. 
```yaml title="ansible/playbook.yml"
- name: Running motd role
  hosts: all
  roles:
  - role: 'motd-role'
```
```yaml title="ansible/requirements.yml"
roles:
- src: git+https://jasperzanjani@dev.azure.com/jasperzanjani/NewDevOpsProject/_git/motd-role
```


The [**extends**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/pipeline?view=azure-pipelines#pipeline-extends) keyword can be used to remove complexity from a pipeline.
Parameters defined in the parent must be passed to the child explicitly, and they must be defined again within the child to make them available to any template experssions.
This makes it possible to abstract the frontend of parameter definitions from the backend of build logic.

```yaml title="pipeline.yml" hl_lines="11-15"
trigger: none
parameters:
- name: pool
  default: Home
  values:
  - Home
  - Work
- name: name
  type: string
  default: World
extends:
  template: jobs.yml
  parameters:
    pool: ${{ parameters.pool }}
    name: ${{ parameters.name }}
```

```yaml title="jobs.yml" hl_lines="1-3"
parameters:
- name: pool
- name: name
jobs:
- job: helloWorldJob
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self
  - bash: |
      ansible-galaxy role install -r ansible/requirements.yml -p ansible/roles -f 
      ansible-playbook ansible/playbook.yml \
        --extra-vars "greet_name=${{parameters.name}}"
```

[**Secure files**](https://learn.microsoft.com/en-us/azure/devops/pipelines/library/secure-files?view=azure-devops) are one of two types of files that can be made available via the [**Library**](https://learn.microsoft.com/en-us/azure/devops/pipelines/library/?view=azure-devops).
Secure files provide a way to store files that can be shared across pipelines, especially security-related items like signatures and keys.

In order to consume a secure file in a pipeline, the [**DownloadSecureFile** task](https://learn.microsoft.com/en-us/azure/devops/pipelines/tasks/reference/download-secure-file-v1?view=azure-pipelines) task is used.
Here it is used to make a private SSH key available on the agent.

```yaml
- task: DownloadSecureFile@1
  name: sshkey
  inputs:
    secureFile: ansible@hyperv-ubuntu2004
```

The secure file can then be used in the following line to make the key available to Ansible.
Note that the template syntax **$( ... )** differs from the template syntax used for pipelines parameters.


```yaml hl_lines="2"
- bash: |
    eval $(ssh-agent); ssh-add <(cat "$(sshkey.secureFilePath)")
    ansible-galaxy role install -r ansible/requirements.yml -p ansible/roles -f 
    ansible-playbook ansible/playbook.yml \
      --extra-vars "greet_name=${{parameters.name}}"
    pkill ssh-agent 
# (1)!
```

1. Repeated runs of the pipeline will continue to start new instances of ssh-agent, so an additional line killing the process at the end of the pipline is good form.



An Ansible vault password file can be placed in Pipelines as a secure file. 
This file is downloaded to the agent using the [**DownloadSecureFile** task](https://learn.microsoft.com/en-us/azure/devops/pipelines/tasks/reference/download-secure-file-v1?view=azure-pipelines) and can be used in downstream tasks, such as the argument to the **--vault-password-file** option, using the [**secureFilePath**](https://learn.microsoft.com/en-us/azure/devops/pipelines/tasks/reference/download-secure-file-v1?view=azure-pipelines#output-variables) output variable.


```yaml title="pipeline.yaml" hl_lines="14-17 27"
trigger: none
parameters:
- name: pool
  displayName: Agent pool
  default: Home
  values:
  - Home
  - Work
jobs:
- task: DownloadSecureFile@1
  name: sshkey
  inputs:
    secureFile: ansible@hyperv-ubuntu2004
- task: DownloadSecureFile@1
  name: vaultpw
  inputs:
    secureFile: vault-pw
- job: HelloWorldJob
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self
  - bash: |
      eval $(ssh-agent); ssh-add <(cat "$(sshkey.secureFilePath)")
      ansible-galaxy role install -r ansible/requirements.yml -p ansible/roles
      ansible-playbook ansible/playbook.yml \
        --extra-vars "greet_name=${{parameters.name}}" \
        --vault-password-file=$(vaultpw.secureFilePath)  
      pkill ssh-agent 
# (1)!
```

1. 
The [magic variable](https://docs.ansible.com/ansible/latest/reference_appendices/special_variables.html#magic-variables) **role\_path** points to the path of the currently running role.
```yaml title="roles/motd-role/tasks/main.yml" hl_lines="3-4"
---
# tasks file for motd
- include_vars:
   file: "{{ role_path }}/defaults/main.yml" # (1)
- copy:
    dest: /etc/motd
    content: Hello, {{ greet_name }}!
  notify: Confirm motd
```
Here, the encrypted value for the **greet\_name** variable is encrypted inline in an otherwise unencrypted vars file.
```yaml title="roles/motd-role/defaults/main.yml"
---
# defaults file for motd
greet_name: !vault |
  $ANSIBLE_VAULT;1.1;AES256
  32306266363035376539336165613665393533653331363063303630353737633965646634356233
  3761346166386235336362623435653264336435623261610a313864346535343534616530313461
  61656438633862333038376239343132616537623664633536306264653636333835633735353531
  6331623962383261340a666330666438613764636162353831356432623461386437313963663333
  3137
```

#### trigger

A [push trigger](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/trigger?view=azure-pipelines#trigger-none) specifies which branches cause a continuous integration build to run. [**trigger: none**](https://learn.microsoft.com/en-us/azure/devops/pipelines/yaml-schema/trigger?view=azure-pipelines#trigger-none) disables CI triggers.

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
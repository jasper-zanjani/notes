### Incorporating Ansible and Azure DevOps Pipelines

Here, the pipeline executes the motd-role role which is defined in another repo.

```yaml title="pipeline.yml"
trigger: none
parameters:
- name: pool
  displayName: Agent pool
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
      ansible-playbook ansible/playbook.yml
```

```yaml title="ansible/playbook.yml"
- name: Running motd role
  hosts: all
  roles:
  - role: 'motd-role'
```

```yaml title="ansible/requirements.yml"
roles:
- src: git+https://jasperzanjani@dev.azure.com/jasperzanjani/NewDevOpsProject/_git/motd-role # (1)
```

1. Additional parameters are available, but default values are probably good in most cases:
```yaml
  scm: git
  version: master
```

#### Secure variables

An Ansible vault password file can be placed in Pipelines as a secure file. 
This file is downloaded to the agent using the [**DownloadSecureFile** task](https://learn.microsoft.com/en-us/azure/devops/pipelines/tasks/reference/download-secure-file-v1?view=azure-pipelines) and can be used in downstream tasks, such as the argument to the **--vault-password-file** option, using the [**secureFilePath**](https://learn.microsoft.com/en-us/azure/devops/pipelines/tasks/reference/download-secure-file-v1?view=azure-pipelines#output-variables) output variable.


```yaml title="pipeline.yaml" hl_lines="15-18 21"
trigger: none
parameters:
- name: pool
  displayName: Agent pool
  default: Home
  values:
  - Home
  - Work
jobs:
- job: HelloWorldJob
  pool: ${{ parameters.pool }}
  steps:
  - checkout: self
  - task: DownloadSecureFile@1
    name: vaultpw
    inputs:
      secureFile: vault-pw
  - bash: |
      ansible-galaxy role install -r ansible/requirements.yml -p ansible/roles
      ansible-playbook ansible/playbook.yml  --vault-password-file=$(vaultpw.secureFilePath)  
```

Here, the encrypted value for the **greet\_name** variable is encrypted inline in an otherwise unencrypted vars file.

```yaml title="defaults/main.yml"
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

A separate encrypted file or directory can be provided, but it must be manually included.

```yaml title="tasks/main.yml" hl_lines="3-4"
---
# tasks file for motd
- include_vars:
   file: "{{ role_path }}/defaults/main.yml" # (1)
- copy:
    dest: /etc/motd
    content: Hello, {{ greet_name }}!
  notify: Confirm motd
```

1. **role\_path** is a [magic variable](https://docs.ansible.com/ansible/latest/reference_appendices/special_variables.html#magic-variables) that points to the path of the currently running role.
### Incorporating Ansible and Azure DevOps Pipelines

Here, the pipeline executes the motd-role role which is defined in another repo.

- pipeline.yml
- ansible
    - [playbook.yml](#ansible-playbookyml)
    - [requirements.yml](#ansible-requirementsyml)

```yaml title="pipeline.yml"
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
      ansible-galaxy role install -r ansible/requirements.yml -p ansible/roles -f
      ansible-playbook ansible/playbook.yml
```

```yaml title="ansible/playbook.yml"
- name: Running motd role
  hosts: all
  roles:
  - role: 'motd-role'
```
{: #ansible-playbookyml }

```yaml title="ansible/requirements.yml"
roles:
- src: git+https://jasperzanjani@dev.azure.com/jasperzanjani/NewDevOpsProject/_git/motd-role
  version: master
```
{: #ansible-requirementsyml }

#### Secure variables


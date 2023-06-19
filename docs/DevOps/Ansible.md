# Ansible

??? info "Projects for learning"

    There are [several areas][https://opensource.com/article/19/8/ops-tasks-ansible] where Ansible can be used in personal projects for learning purposes. 

    1. Use the [`users`](#users) module to manage users, assign groups, and define custom aliases in the `profile` property.
    2. Put a time limit on the availability of the `sudo` command
    3. Use Ansible Tower to produce a GUI interface to restart certain services.
    4. Use Ansible Tower to look for files larger than a particular size in a directory.
    5. Debug a system performance problem. 

Ansible is an automation tool used for configuration management using human-readable YAML templates. 
Ansible is distinguished for being **agentless**, meaning no special software is required on the nodes it manages.

Ansible can be used in one of two ways:

- Running **ad hoc commands**{: #ad-hoc}, executed in realtime by an administrator working at the terminal using the [**ansible**](#ansible) command
- Running **playbooks**, YAML documents that represent a sequence of scripted actions which apply changes uniformly over a set of hosts, using the [**ansible-playbook** ](#ansible-playbook) command. 

A **playbook**{: #playbook } is a YAML document that represents a sequence of scripted actions called **tasks**{: #task } which apply changes uniformly over a set of hosts.
Any ad hoc command can be rewritten as a playbook, but some modules can only be used effectively as playbooks.

```yaml title="playbooks/motd.yml"
- hosts: all
  tasks:
  - copy:
    dest: /etc/motd
    content: "Hello, World!"
```

Ansible host management relies on an [**inventory**](https://docs.ansible.com/ansible/latest/getting_started/get_started_inventory.html#building-an-inventory){: #inventory } file containing a list of IP addresses or hostnames organized in groups.
Inventories can be INI or YAML format.
Inventories are conventionally organized as a file named **hosts** at the root of a project directory, although a system hosts file can be defined at **/etc/ansible/hosts**.

#### Variables

[**Variables**](https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_variables.html) can be defined under **vars** (as properties), and they are [referenced](https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_variables.html#referencing-simple-variables) using Jinja2-style double braces: `{{ }}`. 
YAML syntax requires a value starting with double braces to be quoted.

```yaml hl_lines="2-3" title="playbooks/motd.yml"
- hosts: all
  vars:
    name: World
  tasks:
  - command: echo "Hello, {{ name }}!"
```

Variables can also be defined in **variables files**, YAML-format dictionaries conventionally placed in the **vars** directory, and referenced using the **vars\_files** property.
The path for vars files appears to be interpreted relative to the location of the playbook.

```yaml hl_lines="2-3" title="playbooks/motd.yml"
- hosts: all
  vars_files:
  - vars/name.yml
  tasks:
  - copy:
    dest: /etc/motd
    content: Hello, {{ greet_name }}!
```
```yaml title="playbooks/vars/name.yml"
greet_name: World
```

Variables can also be defined at runtime using the [**--extra-vars**/**-e**](https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_variables.html#defining-variables-at-runtime){: #extra-vars} option.
Variables can be passed as space-delimited or JSON format.

```sh
ansible-playbook release.yml -e "version=1.23.45 other_variable=foo"
```

Variables cane be [encrypted inline](https://docs.ansible.com/ansible/2.9/user_guide/playbooks_vault.html#single-encrypted-variable) in an otherwise cleartext vars file.

#### Jinja2

Various effects are possible using Jinja2 templates:

Jinja2 **control structures** support control flow features like loops and conditionals inside **`{% ... %}`** blocks.

```yaml hl_lines="3"
- name: Find any YUM/DNF variables
  find:
    paths: "/etc/{% 'dnf' if ansible_distribution_major_version == '8' else 'yum' %}/vars"
  register: _repository_vars_files
```

[Filters](https://jinja.palletsprojects.com/en/latest/templates/#filters) follow a pipe in the template.

```yaml title="Capitalize a value"
line: " {{ hypervisor | upper }}
```

Ansible provides [additional filters](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/index.html#filter-plugins).
Here both the [basename](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/basename_filter.html#ansible-collections-ansible-builtin-basename-filter), [b64decode](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/b64decode_filter.html#ansible-collections-ansible-builtin-b64decode-filter), and [combine](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/combine_filter.html#ansible-collections-ansible-builtin-combine-filter) Ansible filters are used as well as [trim](https://jinja.palletsprojects.com/en/latest/templates/#jinja-filters.trim) which is native to Jinja2.
```yaml hl_lines="2"
- set_fact:
    repository_vars: "{{ (repository_vars | default({})) | combine({ (_file.source | basename): _file.content | b64decode | trim }) }}"
  loop: "{{ _repository_vars_slurped_files.results }}"
  loop_control:
    loop_var: _file
```

#### Roles

Ansible **roles**{: #role } group content in a way that allows it to be shared.
They typically correspond to the service offered (web servers or databases, etc).

Roles have a highly standardized directory structure.

- **defaults**: default values for variables with low perecedence that **can** be overriden by inventory variables
- **files**: static files referenced by role tasks
- **handlers**: handler definitions
- **meta**: metadata about the role, such as author, license, platforms, dependencies, etc
- **tasks**: task definitions
- **vars**: role variables with high precedence that **cannot** be overriden by inventory variables

A skeleton directory can be created with [ansible-galaxy](#ansible-galaxy). 

```sh
ansible-galaxy init $ROLENAME
```

Roles can be called in a playbook under the **roles** property.
The value of the role is interpreted as a path, appended to the project directory or various other potential locations. Because roles are meant to be reused by many playbooks, a central location is recommended:

- ~/.ansible/roles
- /etc/ansible/roles
- /usr/share/ansible/roles


```yaml title="playbooks/motd.yml"
- hosts: all
  roles:
  - role: roles/motd
    vars:
      greet_name: Dgiapusccu # (1)
```

1. Without providing an overriding variable value:
```yaml
- hosts: all
  roles: 
  - roles/motd
```


```yaml title="motd role"
# motd/tasks/main.yml
- copy:
    content: Hello, {{ greet_name }}!
    dest: /etc/motd

# motd/defaults/main.yml
greet_name: World # (1)
```

1. Role variables defined in **vars** have a high precedence and cannot be overriden.
Only values defined in **defaults** can be overriden.

It appears that variables with values defined in the main.yml file located **vars** or **defaults** are automatically picked up.
But if variables are defined in additional files they must be explicitly imported.

```yaml title="motd/tasks/main.yml"
- include_vars:
    file: "{{ role_path }}/defaults/secure.yml"
- copy:
    content: Hello, {{ greet_name }}!
    dest: /etc/motd
```

Normally, tasks in a role execute **before** the other tasks of a playbook. **pre\_tasks** and **post\_tasks** can be defined as well. 


Roles can have dependencies on other dependencies, as defined in the **meta** directory.

```yaml
dependencies:
- { role: apache, port: 80 }
- { role: mariadb, dbname: addresses, admin_user: bob }
```

#### Collections

Ansible [**collections**](https://www.youtube.com/watch?v=WOcqhk7TdYc) comprise a standardized format for **Ansible content** distribution, allowing it to be delivered asynchronously and on-demand separately from Ansible Automation Platform releases.
Ansible content can include playbooks, modules, roles, documentation, tests, plugins.
Ansible collections are delivered using **Ansible Galaxy** and each collection needs a galaxy.yml file that describes the collection.

Collections can be installed from a YAML-format requirements file:
```sh
ansible-galaxy collection install -r ansible/requirements.yml
```

```yaml title="ansible/requirements.yml"
roles:
- src: git@ssh.dev.azure.com:v3/PODS-LLC/SWE/devops_inventory_role
  version: master # (2)
  scm: git
  name: inventory # (1)
```

1. This apparently determines how the directory is renamed.
2. Branch name

#### Handlers

**Handlers** are tasks that are executed when notified by a task. They are only run once, and only if the notifying task has made a change to the system. 


Here, **Enable Apache** will be called if **Install Apache** makes a change. 
If apache2 is already installed, the handler is not called. 

```yaml
- hosts: webservers
  become: yes
  tasks:
  - name: Install Apache
    apt: name=apache2 update_cache=yes state=latest
    notify: enable apaches

  handlers:
  - name: Enable Apache
    service: name=apache2 enabled=yes state=started
```


```yaml
- hosts: all
  vars:
    package_name: apache2
  tasks:
  - name: this installs a package
    apt: "name={{ package_name }} update_cache=yes state=latest"
    notify: enable apache
  handlers:
  - name: enable apache
    service: "name={{ package_name }} enabled=yes state=started" 
```

**Conditional logic** is [implemented][https://www.linuxjournal.com/content/ansible-part-iii-playbooks] on each task by defining a value for the **when** statement:

```yaml hl_lines="7"
- hosts: all
  vars:
    startme: true
  tasks:
  - command: echo Hello, World!
    when: startme
```

#### Vault

**Ansible Vault** is a place to safely keep passwords.
There are two types of vaulted content:

- **Vaulted files**, where the full file, which can contain Ansible variables or other content, is encrypted
- **Single encrypted variables**, where only specific variables within a normal "variable file" are encrypted.

```sh title="Run a playbook providing a vault password file"
ansible-playbook --vault-password-file $pwfile playbooks/motd.yml
```

## Tasks

#### Setup
:   
    The Ansible **control node** needs to be configured to elevate privileges.
    This is done by modifying **ansible.cfg** in the relevant project directory or the system config at **/etc/ansible/ansible.cfg**

    ```ini title="ansible.cfg"
    [privilege_escalation]
    become=yes
    ```

    An Ansible service account is created on each **managed node**.
    ```sh
    useradd ansible -s /usr/bin/bash -mG wheel # sudo
    passwd ansible
    su - ansible
    ssh-keygen -A
    ```

    Now the service account is given the ability to sudo any command without a password.

    ```sh title="/etc/sudoers.d/ansible"
    ansible ALL=(ALL) NOPASSWD: ALL
    # (1)!
    ```

    1. Without this line, plays will fail with the message "Missing sudo password" 
    ``` hl_lines="4"
    PLAY [Running motd role] *******************************************************

    TASK [Gathering Facts] *********************************************************
    fatal: [hyperv-centos9]: FAILED! => {"msg": "Missing sudo password"}

    PLAY RECAP *********************************************************************
    hyperv-centos9             : ok=0    changed=0    unreachable=0    failed=1    skipped=0    rescued=0    ignored=0   
    ```

    The system inventory is an INI-format config located at **etc/ansible/hosts** and defines the clients which are to be controlled by the server.

    The group name **all** is implicitly defined, and the following command will display all defined hosts.

    ```sh title="Display all available hosts"
    ansible all --list-hosts
    ```

#### Apache
:   

    ```yaml
    --8<-- "includes/Ansible/tasks/apache.yaml"
    ```

    ```yaml title="Using vars" hl_lines="3-4"
    --8<-- "includes/Ansible/tasks/apache-vars.yaml"
    ```
    {: #httpd-vars }

#### Files
:   

    ```yaml title="Create file"
    - copy:
        dest: /etc/motd
        content: "Hello, World!\n" # (1)
    ```

    1. Alma Linux 9 additionally requires the **libselinux-python** package to handle SELinux contexts. It is incorrectly identified as "libselinux-python" in the Ansible error message.

    ```yaml title="Delete file"
    - file:
        path: /etc/motd
        state: absent
    ```

    ```yaml title="Create directory"
    - file:
        path: /home/ansible/.vim/autoload
        state: directory
        mode: 0755
    ```

#### User creation
:   

    ```yaml
    --8<-- "includes/Ansible/tasks/user.yml"
    ```

    More secure is using a separate vaulted variables file to keep the credential secure.

    ```yaml title="playbooks/user.yml"
    --8<-- "includes/Ansible/tasks/user-vault.yml"
    ```
    ```yaml title="playbooks/vars/user.yml"
    username: newuser
    password: password
    ```
    ```sh title="Run playbook providing a password file"
    ansible-playbook --vault-password-file vault-pw playbooks/user.yml
    ```

## Commands

#### ansible
:   
    --8<-- "includes/Ansible/Commands/ansible.md"

#### ansible-config
:   
    --8<-- "includes/Ansible/Commands/ansible-config.md"

#### ansible-doc
:   
    --8<-- "includes/Ansible/Commands/ansible-doc.md"

#### ansible-galaxy
:   
    --8<-- "includes/Ansible/Commands/ansible-galaxy.md"

#### ansible-playbook
:   
    --8<-- "includes/Ansible/Commands/ansible-playbook.md"

#### ansible-vault
:   
    --8<-- "includes/Ansible/Commands/ansible-vault.md"

## Modules

### Miscellaneous
:   
    --8<-- "includes/Ansible/Modules/archive.md"

    --8<-- "includes/Ansible/Modules/cli_config.md"

    --8<-- "includes/Ansible/Modules/command.md"

    --8<-- "includes/Ansible/Modules/copy.md"

    --8<-- "includes/Ansible/Modules/debug.md"

    --8<-- "includes/Ansible/Modules/file.md"

    --8<-- "includes/Ansible/Modules/firewalld.md"

    --8<-- "includes/Ansible/Modules/git.md"

    --8<-- "includes/Ansible/Modules/group.md"

    --8<-- "includes/Ansible/Modules/ini_file.md"

    --8<-- "includes/Ansible/Modules/lineinfile.md"

    --8<-- "includes/Ansible/Modules/redhat_subscription.md"

    --8<-- "includes/Ansible/Modules/replace.md"

    --8<-- "includes/Ansible/Modules/service.md"

    --8<-- "includes/Ansible/Modules/setup.md"

    --8<-- "includes/Ansible/Modules/systemd.md"

    --8<-- "includes/Ansible/Modules/template.md"

    --8<-- "includes/Ansible/Modules/user.md"

### Package management

#### apt
:   
    --8<-- "includes/Ansible/Modules/apt.md"

#### package
:   
    --8<-- "includes/Ansible/Modules/package.md"

#### snap
:   
    --8<-- "includes/Ansible/Modules/snap.md"

#### yum
:   
    --8<-- "includes/Ansible/Modules/yum.md"

#### yum_repository
:   
    --8<-- "includes/Ansible/Modules/yum_repository.md"

## Glossary

- [**Ad Hoc**](#ad-hoc): type of command run in realtime by an administrator working at the terminal
- **Ansible Galaxy**: online portal where a gallery of roles made by the Ansible community can be found
- **Ansible Tower**: web-based RESTful API endpoint that provides the officially supported GUI frontend to Ansible configuration management, available in two versions: standard ($13,000/yr) and premium ($17,500/yr)
- **Ansible Vault**: place to keep encrypted passwords
- **AWX**: Open-source project upon which Ansible Tower was built
- **Fact**: System property gathered by Ansible when it executes a playbook on a node
- [**Inventory**](#inventory): INI-format file containing a list of servers or nodes that you are managing and configuring
- [**Module**](#modules): standalone scripts that enable a particular task across many OSes, services, applications, etc. 
Predefined modules are available in the **module library**, and new ones can be defined via Python or JSON.
- **Play**: script or instruction that defines the task to be carried out in a server
- [**Playbook**](#playbook):   
- **Role**: organize components of playbooks, allowing them to be reused
- [**Task**](#task): A single scripted action in a playbook, equivalent to an ad hoc command
- [**Vault**](#vault): feature of Ansible that allows you to keep sensitive data such as passwords or keys protected at rest, rather than as plaintext in playbooks or roles.

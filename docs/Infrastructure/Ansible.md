# Ansible

Ansible is an automation tool used for configuration management using human-readable YAML templates. Ansible is distinguished for being **agentless**, meaning no special software is required on the nodes it manages.

Ansible host management relies on an .ini-format **inventory** file containing a list of IP addresses or hostnames organized in groups.



Ansible **roles** group content in a way that allows it to be shared.
Roles also have a highly standardized directory structure.
Folders named handlers, tasks, etc. contain those items.
A skeleton directory can be created with [ansible-galaxy](#ansible-galaxy), although they can also be formed manaully of course. 

Roles can then be called in a playbook:

=== "Default values"

    ```yaml
    - name: Play to create shared folder
      hosts: ftpservers

      roles:
      - vsftpd_server
    ```

=== "Overridden values"

    ```yaml
    - name: Play to create shared folder
      hosts: ftpservers

      roles:
      - role: vsftpd_server
        vars:
          ftp_config_src: vsftpd_special.conf.j2
    ```

??? info "Projects for learning"

    There are [several areas][https://opensource.com/article/19/8/ops-tasks-ansible] where Ansible can be used in personal projects for learning purposes. 

    1. Use the [`users`](#users) module to manage users, assign groups, and define custom aliases in the `profile` property.
    2. Put a time limit on the availability of the `sudo` command
    3. Use Ansible Tower to produce a GUI interface to restart certain services.
    4. Use Ansible Tower to look for files larger than a particular size in a directory.
    5. Debug a system performance problem. 
:   - Standalone script that enables a particular task regardless of OS, service or application
    - Discrete unit of code used in playbooks for executing commands


**Variable substitution** is done by specifying the name of the placeholder variable and its value under `vars` as a sibling to `tasks` and `handlers` 

```yaml
---
- hosts: webservers
  become: yes
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

**Conditional logic** is [implemented][https://www.linuxjournal.com/content/ansible-part-iii-playbooks] with each task by defining a condition as the value for a property `when` :
```yaml
---
- hosts: webservers
  become: yes
  tasks:
    - name: install apache this way
      apt: name=apache2 update_cache=yes state=latest
      notify: start apache2
      when: ansible_os_family == "Debian"

    - name: install apache that way
      yum: name=httpd state=latest
      notify: start httpd
      when: ansible_os_family == "RedHat"

  handlers:
    - name: start apache2
      service: name=apache2 enabled=yes state=started

    - name: start httpd
      service: name=httpd enabled=yes state=started
```




Ansible configuration can be done through many files.

- **ansible.cfg** defines how privileges are escalated, and they are commonly placed in project directories.
- **/etc/ansible/hosts** defines the clients which are to be controlled by the server

## Tasks

```yaml title="Hello, World!"
---
- name: Hello, World! playbook
  hosts: all
  tasks:
  - name: Hello, World! play
    command: echo Hello, World!
... # (1)
```

1.     
```sh title="Ad-hoc"
ansible all -m command -a "echo Hello, World!"
```

??? info ":material-tools: Configuration"

    ```ini title="ansible.cfg"
    [privilege_escalation]
    become=yes
    become_method=sudo
    become_user=root
    become_ask_pass=no
    remote_user=ansible

    [defaults]
    interpreter_python=auto_silent
    deprecation_warnings=False
    ```

    ```sh title="Display non-default settings"
    ansible-config dump --only-changed
    ```


??? info ":material-file: Files"

    === ":material-plus: Create file"

        ```yaml
        ---
        - name: Create file
          hosts: all
          tasks:
          - name: Create file
            copy:
              dest: /etc/motd
              content: "Hello, World!\n" # (1)
        ...
        ```

        1. Alma Linux 9 requires an additional package to be installed to handle SELinux contexts:
        ```sh
        # This package is incorrectly identified as "libselinux-python" in the Ansible error displayed on the controller host
        dnf install python3-libselinux
        ```

    === ":material-trash-can: Delete file"

        ```yaml
        ---
        - name: Delete file
          hosts: all
          tasks:
          - name: Delete file
            file:
              path: /etc/motd
              state: absent
        ...
        ```

## Commands

All CLI tools use the same set of [**modules**](#modules), which expose the same API.

--8<-- "includes/Ansible/modules.md"

--8<-- "includes/Ansible/ansible.md"

--8<-- "includes/Ansible/ansible-config.md"

--8<-- "includes/Ansible/ansible-doc.md"

--8<-- "includes/Ansible/ansible-galaxy.md"

--8<-- "includes/Ansible/ansible-playbook.md"

## Modules

--8<-- "includes/Ansible/Modules/archive.md"

--8<-- "includes/Ansible/Modules/cli_config.md"

--8<-- "includes/Ansible/Modules/command.md"

--8<-- "includes/Ansible/Modules/copy.md"

--8<-- "includes/Ansible/Modules/debug.md"

--8<-- "includes/Ansible/Modules/file.md"

--8<-- "includes/Ansible/Modules/git.md"

--8<-- "includes/Ansible/Modules/template.md"

## Glossary

Ad Hoc
:   
    Type of command run in realtime by an administrator working at the terminal'

Ansible Galaxy
:   Online portal where a gallery of roles made by the Ansible community can be found

Ansible Tower
:   Web-based RESTful API endpoint that provides the officially supported GUI frontend to Ansible configuration management. 
    A commercial product that is available in two versions: 
    
    - **Standard**: $13,000/yr
    - **Premium**: $17,500/yr

Ansible Vault
:   Place to keep encrypted passwords

AWX
:   Open-source project upon which Ansible Tower was built

Fact
:   System property gathered by Ansible when it executes a playbook on a node

#### Handler
:   
    **Handlers** are tasks that are executed when notified by a task. They are only run once, and only if the notifying task has made a change to the system. 


    Here, **Enable Apache** will be called if **Install Apache** makes a change. 
    If apache2 is already installed, the handler is not called. 

    ```yaml
    ---
    - hosts: webservers
        become: yes
        tasks:
            - name: Install Apache
                apt: name=apache2 update_cache=yes state=latest
                notify: enable apache

        handlers:
            - name: Enable Apache
                service: name=apache2 enabled=yes state=started
    ```


Inventory
:   Text file containing a list of servers or nodes that you are managing and configuring

#### Module
:   
    **Modules** are standalone scripts that enable a particular task across many OSes, services, applications, etc. 
    Predefined modules are available in the **module library**, and new ones can be defined via Python or JSON.

Play
:   Script or instruction that defines the task to be carried out in a server

#### Playbook
:   
    Ansible can be used in one of two ways:

    - Running **ad hoc** commands, executed in realtime by an administrator working at the terminal using the [**ansible**](#ansible) command
    - Running **playbooks**, YAML documents that represent a sequence of scripted actions which apply changes uniformly over a set of hosts, using the [**ansible-playbook** ](#ansible-playbook) command. 

    A **playbook** is a YAML document that represents a sequence of scripted actions called **tasks** which apply changes uniformly over a set of hosts.

    Any ad hoc command can be rewritten as a playbook, but some modules can only be used effectively as playbooks.

    Playbooks can be written in **two** styles:

    - Using "`k=v`" syntax, where keys and values are defined inline
    - Using proper YAML syntax

    === "k=v"

        ```yaml
        tasks:
        - name: Install htop
            dnf: name=htop state=latest
        ```

    === "YAML"

        ```yaml
        tasks:
        - name: Install htop
            dnf:
            name: htop
            state: latest
        ```

Role
:   Organize components of playbooks, allowing them to be reused'

Task
:   A single scripted action in a playbook, equivalent to an ad hoc command

Vault
:   Feature of Ansible that allows you to keep sensitive data such as passwords or keys protected at rest, rather than as plaintext in playbooks or roles

    Two types of vaulted content:
    
    - **Vaulted files**, where the full file, which can contain Ansible variables or other content, is encrypted
    - **Single encrypted variables**, where only specific variables within a normal "variable file" are encrypted.

## Tasks

#### Setup

An Ansible service is account is created on each node and given the ability to sudo any command without a password.
```sh
useradd ansible
passwd ansible
```
```sh title="/etc/sudoers.d/ansible"
ansible ALL=(ALL) NOPASSWD: ALL
```
```sh
su - ansible
ssh-keygen
```
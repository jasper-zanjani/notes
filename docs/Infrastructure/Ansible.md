# Ansible

Ansible is an automation tool used for configuration management using human-readable YAML templates. Ansible is distinguished for being **agentless**, meaning no special software is required on the nodes it manages.

Ansible **playbooks** represent a sequence of scripted actions which apply changes uniformly over a set of hosts.
**Modules** are standalone scripts that enable a particular task across many OSes, services, applications, etc. 
Predefined modules are available in the **module library**, and new ones can be defined via Python or JSON.

Ansible host management relies on a `.ini` file containing a list of IP addresses or hostnames organized in groups.

There are [several areas][https://opensource.com/article/19/8/ops-tasks-ansible] where Ansible can be used in personal projects for learning purposes. 

1. Use the [`users`](#users) module to manage users, assign groups, and define custom aliases in the `profile` property.
2. Put a time limit on the availability of the `sudo` command
3. Use Ansible Tower to produce a GUI interface to restart certain services.
4. Use Ansible Tower to look for files larger than a particular size in a directory.
5. Debug a system performance problem. 


Ansible can be used in one of two ways:

- Running **ad hoc** commands, that is commands executed in realtime by an administrator working at the terminal, using the [ `ansible` ](#ansible) command.
- Running **playbooks**, YAML documents containing **tasks** each of which are equivalent to a single ad hoc command, using the [ `ansible-playbook` ](#ansible-playbook) command. Any ad hoc command can be rewritten as a playbook, but some modules can only be used effectively as playbooks.

Playbooks, in turn, can be written in **two** styles:

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

**Variable substitution** is done by specifying the name of the placeholder variable and its value under `vars` as a sibling to `tasks` and `handlers` <sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]</sup>
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

**Handlers** are tasks that are executed when notified by a task. They are only run once, and only if the notifying task has made a change to the system. 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]</sup>

Here, `enable apache` will be called if `this installs a package` makes a change. If apache2 is already installed, the handler is not called. 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]</sup>

```yaml
---
- hosts: webservers
  become: yes
  tasks:
    - name: this installs a package
      apt: name=apache2 update_cache=yes state=latest
      notify: enable apache

  handlers:
    - name: enable apache
      service: name=apache2 enabled=yes state=started
```



## Config

- **ansible.cfg** defines how privileges are escalated, and they are commonly placed in project directories.
- **/etc/ansible/hosts** defines the clients which are to be controlled by the server


## Syntax


All CLI tools use the same set of **modules**, which expose the same API.

--8<-- "includes/Ansible/modules.md"

--8<-- "includes/Ansible/ansible.md"

--8<-- "includes/Ansible/ansible-config.md"

--8<-- "includes/Ansible/ansible-doc.md"

--8<-- "includes/Ansible/ansible-galaxy.md"

--8<-- "includes/Ansible/ansible-playbook.md"

## Glossary

--8<-- "includes/Ansible/defs.md"

## Tasks

#### Setup

Create Ansible service account
```sh
useradd ansible
passwd ansible
```
Grant service account superuser permissions
```sh
# /etc/sudoers.d/ansible
ansible ALL=(ALL) NOPASSWD: ALL
```
Generate SSH keys
```sh
su - ansible
ssh-keygen
```
[https://youtu.be/wZ_mh4-4HPY]: https://youtu.be/wZ_mh4-4HPY "Red Hat Ansible Tower Demo"
[https://4sysops.com/archives/ansible-tower-vs-ansible-awx-for-automation/]: https://4sysops.com/archives/ansible-tower-vs-ansible-awx-for-automation/ "Ansible Tower vs. Ansible AWX"
[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"
[https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin]: https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin "Ansible: the automation framework that thinks like a sysadmin"
[https://www.linuxjournal.com/content/ansible-making-things-happen]: https://www.linuxjournal.com/content/ansible-making-things-happen "Ansible: Making things happen"
[https://www.linuxjournal.com/content/ansible-part-iii-playbooks]: https://www.linuxjournal.com/content/ansible-part-iii-playbooks "Ansible, Part III: Playbooks"
[https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]: https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together "Ansible, Part IV: Putting it all together"
[https://opensource.com/article/19/8/ops-tasks-ansible]: https://opensource.com/article/19/8/ops-tasks-ansible "5 ops tasks to do with Ansible"
[https://www.tecmint.com/understand-core-components-of-ansible/]: https://www.tecmint.com/understand-core-components-of-ansible/ '"Understand Core Components of Ansible - Part 1" _TecMint_'
[https://www.digitalocean.com/community/cheatsheets/how-to-use-ansible-cheat-sheet-guide]: https://www.digitalocean.com/community/cheatsheets/how-to-use-ansible-cheat-sheet-guide 'Erika Heidi". How to Use Ansible: A Reference Guide". Digital Ocean: 06/05/2019.'
[My playbook]: https://github.com/jasper-zanjani/ansible/tree/master/playbooks/packages.yaml "The packages I install"

[/etc/ansible/hosts]: #etcansiblehosts '/etc/ansible/hosts&#10;Ansible hosts file, defining the clients which are to be controlled by the server'

[Ad Hoc]:                     # 'Ad Hoc&#10;Type of command run in realtime by an administrator working at the terminal'
[Ansible Galaxy]:             # 'Ansible Galaxy&#10;Online portal where a gallery of roles made by the Ansible community can be found&#10;"Ansible, Part IV: Putting it all together". _Linux Journal_: 2018/03/02.'
[Ansible Tower]:              # 'Ansible Tower&#10;Web-based RESTful API endpoint that provides the officially supported GUI frontend to Ansible configuration management. It is a commercial product that is available in two versions: **Standard** ($13,000/yr) and **Premium** ($17,500/yr)&#10;"Ansible Tower vs. Ansible AWX". 4sysops.com: 2019/08/13.&#10;---&#10;Presents a dashboard that depicts success and failure of Ansible playbook runs. Tower implements RBAC, supporting large teams.&#10;"Red Hat Ansible Tower Demo". YouTube: 2018/09/09.'
[Ansible Vault]:              # 'Ansible Vault&#10;Place to keep encrypted passwords&#10;"Ansible: the automation framework that thinks like a sysadmin" _Linux Journal_: 2018/01/05.'
[AWX]:                        # 'AWX&#10;Open-source project upon which Ansible Tower was built&#10;"Ansible Tower vs. Ansible AWX". 4sysops.com: 2019/08/13.'
[EPEL]:                       # 'Extra Packages For Enterprise Linux (EPEL)&#10;Red Hat repository that must be added before installing Ansible in Red Hat/CentOS using yum'
[Fact]: # 'Fact&#10;System property gathered by Ansible when it executes a playbook on a node&#10;"Understand Core Components of Ansible - Part 1" _TecMint_'
[Handler]:                    # 'Handler&#10;Tasks executed when notified by a task&#10;"Ansible, Part III: Playbooks". _Linux Journal_: 2018/02/19.'
[Inventory]:                  # 'Inventory&#10;Text file containing a list of servers or nodes that you are managing and configuring&#10;"Understand Core Components of Ansible - Part 1" _TecMint_'
[Module]:                     # 'Module&#10;Standalone script that enables a particular task regardless of OS, service or application&#10;---&#10;Discrete unit of code used in playbooks for executing commands&#10;"Understand Core Components of Ansible - Part 1" _TecMint_'
[Module Library]:             # 'Module Library&#10;Where predefined modules can be found'
[Play]: # 'Play&#10;Script or instruction that defines the task to be carried out in a server&#10;"Understand Core Components of Ansible - Part 1" _TecMint_'
[Playbook]:                   # 'Playbook&#10;YAML document that represents a sequence of scripted actions which apply changes uniformly over a set of hosts'
[Role]:                       #roles 'Role&#10;Organize components of playbooks, allowing them to be reused'
[Task]:                       # 'Task&#10;A single scripted action in a playbook, equivalent to an ad hoc command'
[Vault]: # 'Vault&#10;Feature of Ansible that allows you to keep sensitive data such as passwords or keys protected at rest, rather than as plaintext in playbooks or roles&#10;Two types of vaulted content:&#10;  - Vaulted files, where the full file, which can contain Ansible variables or other content, is encrypted.&#10;  - Single encrypted variables, where only specific variables within a normal "variable file" are encrypted.&#10;"Using Vault in playbooks". Ansible documentation. '

# Ansible
Ansible is an automation tool used for configuration management using human-readable YAML templates. Ansible is distinguished for being **agentless**, meaning no special software is required on the nodes it manages.

Ansible [**playbooks**][Playbook] represent a sequence of scripted actions which apply changes uniformly over a set of hosts.  [**Modules**](#modules) are standalone scripts that enable a particular task across many OSes, services, applications, etc. Predefined modules are available in the **module library**, and new ones can be defined via Python or JSON.

Ansible host management relies on a `.ini` file containing a list of IP addresses or hostnames organized in groups.

There are several areas where Ansible can be used in personal projects for learning purposes. [<sup>ref</sup>][https://opensource.com/article/19/8/ops-tasks-ansible]
1. Use the [`users`](#users) module to manage users, assign groups, and define custom aliases in the `profile` property.
2. Put a time limit on the availability of the `sudo` command
3. Use Ansible Tower to produce a GUI interface to restart certain services.
4. Use Ansible Tower to look for files larger than a particular size in a directory.
5. Debug a system performance problem. 

#### Concepts
[Ad hoc command][Ad Hoc] 
[Ansible Galaxy][Ansible Galaxy] 
[Ansible Tower][Ansible Tower] 
[Ansible Vault][Ansible Vault] 
[AWX][AWX] 
[EPEL][EPEL] 
[Fact][Fact] 
[Handler][Handler] 
[Inventory][Inventory]
[Module][Module] 
[Module Library][Module Library] 
[Play][Play] 
[Playbook][Playbook] 
[Role][Role] 
[Task][Task]
[Vault][Vault]

#### Commands
[`ansible`](#ansible-command) 
[`ansible-galaxy`](#ansible-galaxy) 
[`ansible-inventory`](#ansible-inventory) 
[`ansible-playbook`](#ansible-playbook)

#### Modules
[`apt`](#package-management) 
[`archive`](#archive-module) 
[`cli_config`](#cli_config) 
[`command`](#command-module) 
[`copy`](#copy-module) 
[`debug`](#debug-module) 
[`dnf`](#package-management) 
[`file`](#file-module) 
[`git`](#git-module) 
[`lineinfile`](#lineinfile-module) 
[`package`](#package-management) 
[`ping`](#ping-module) 
[`raw`](#raw-module) 
[`service`](#service-module) 
[`setup`](#setup-module) 
[`shell`](#shell-module) 
[`template`](#template-module)

#### Roles
A playbook may also contain [**roles**][Role], which organize the components of playbooks and allow them to be reused. By creating a system of subfolders within a folder named `roles` (either in the current working directory or in **/etc/ansible/roles/**, complicated playbooks can be broken up into multiple files. Folders with names like `tasks`, `handlers`, `vars`, etc must each contain `main.yml`. Then the role can be specified by folder name.

Define the "webserver" role with a tree of subdirectories and files:
```
roles/
  webserver/
    tasks/
      main.yml
    handlers/
      main.yml
    vars/
      main.yml
    templates/
      index.html.j2
      httpd.conf.j2
    files/
      ntp.conf
```
The role can be specified in a very simple playbook:
```yaml
---
- hosts: cadlab
  roles:
    - webserver
```

## Configs
`/etc/ansible/ansible.cfg` is the default, system-wide config which takes lower precedence than, and is overridden by, more specific configs.
The user specific `~/.ansible.cfg` or project-specific `ansible.cfg` take precedence.

[`/etc/ansible/hosts`][/etc/ansible/hosts] 
[`/etc/ansible/roles`](#roles)

###### /etc/sudoers.d/user
Privilege escalation needs a sudo configuration, and a suitable sudoers file for the ansible user on Ansible-managed hosts could look like the following
```
user ALL=(ALL) NOPASSWD: ALL
```
###### /etc/ansible/hosts
Individual hosts can be listed in **groups** (bracketed sections). Plain-text passwords would also be stored here. [[4](#sources)]\
Typical appearance:
```ini
[webservers]
blogserver ansible_host=192.168.1.5
wikiserver ansible_host=192.168.1.10

[dbservers]
mysql_1 ansible_host=192.168.1.22
pgsql_1 ansible_host=192.168.1.23
```

## Syntax
Ansible can be used in one of two ways:
1. Running **ad hoc** commands, that is commands executed in realtime by an administrator working at the terminal, using the [ `ansible` ](#ansible) command.
2. Running **playbooks**, YAML documents containing **tasks** each of which are equivalent to a single ad hoc command, using the [ `ansible-playbook` ](#ansible-playbook) command. Any ad hoc command can be rewritten as a playbook, but some modules can only be used effectively as playbooks.

Playbooks, in turn, can be written in **two** styles:
1. Using "`k=v`" syntax, where keys and values are defined inline
```yaml
tasks:
  - name: Install htop
    dnf: name=htop state=latest
```
2. Using proper YAML syntax
```yaml
tasks:
  - name: Install htop
    dnf:
      name: htop
      state: latest
```

## Commands
###### `ansible` command
[ansible -&#97;]:  #ansible  '```&#10;$ ansible -&#97;&#10;```&#10;Specify arguments to module'
[ansible -&#98;]:  #ansible  '```&#10;$ ansible -&#98;&#10;```&#10;Elevate privileges by becoming the root user'
[ansible -&#109;]: #ansible '```&#10;$ ansible -&#109; $MODULE&#10;```&#10;Specify module to be executed'
[ansible -&#105;]: #ansible '```&#10;$ ansible -&#105;&#10;$ ansible --inventory&#10;```&#10;Specify inventory host path or comma separated host list'
[ansible -&#75;]:  #ansible '```&#10;$ ansible -K&#10;$ ansible --ask-become-pass&#10;```&#10;Ask for privilege escalation password.&#10;"Understanding privilege escalation: become". Ansible documentation.'
[ansible --list-hosts]: #ansible '```&#10;$ ansible --list-hosts&#10;```&#10;Display a list of matching hosts'
[ansible -&#117;]: #ansible '```&#10;$ ansible -&#117;&#10;$ ansible --user&#10;```&#10;Specify a remote user'
[ansible -&#111;]: #ansible '```&#10;$ ansible -&#111;&#10;$ ansible --one-line&#10;```&#10;Condense output'

<code>&nbsp;</code>   [`a`][ansible -&#97;] [`b`][ansible -&#98;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`i`][ansible -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`m`][ansible -&#109;] <code>&nbsp;</code> [`o`][ansible -&#111;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`u`][ansible -&#117;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`K`][ansible -&#75;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

[`list-hosts`][ansible --list-hosts]


The `ansible` command is only used for running **ad hoc** commands,  Modules are called as arguments passed to the `-m` option. 
```sh
ansible $CLIENT [-b] -m $MODULE -a $ARGUMENTS
```
Test network connectivity using the [`ping`](#ping-module) module [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin]
```sh
ansible all -m ping 
```
Install `htop` on the localhost
```sh
ansible localhost -b -m package -a "name=htop"
```
Use `--ask-become-pass` to interactively prompt for `sudo` password [<sup>ref</sup>][https://www.digitalocean.com/community/cheatsheets/how-to-use-ansible-cheat-sheet-guide]
```sh
ansible localhosst -b -m dnf -a "name=vim-enhanced state=latest' --ask-become-pass
```
List hosts in project-local inventory file
```sh
ansible all -i inventory --list-hosts
```
###### `ansible-galaxy`
Search for roles [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]
```sh
ansible-galaxy search $ROLE
```
Install `$ROLE` made  available in **Ansible Galaxy** by `$USER` into the [ system-wide ](#configuration) roles folder [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]
```sh
sudo ansible-galaxy install $USER.$ROLE
```
Create a skeleton structure in which you can define a new role [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]
```sh
ansible-galaxy init roles/$ROLE
```
Log in [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]
```sh
ansible-galaxy login
```
Upload a role [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iv-putting-it-all-together]
```sh
ansible-galaxy import $USERNAME $REPONAME
ansible-galaxy import --no-wait $USERNAME $REPONAME # send job to background
```
###### `ansible-inventory`
###### `ansible-playbook`
Playbooks are executed with the `ansible-playbook` command
```sh
ansible-playbook -i $CLIENT $PLAYBOOK
```
## Playbooks
```yaml
---
- hosts: webservers
  become: yes
  tasks:
    - name: this installs a package
      apt: name=apache2 update_cache=yes state=latest

    - name: this restarts the apache service
      service: name=apache2 enabled=yes state=restarted
```

#### Handlers
**Handlers** are tasks that are executed when notified by a task. They are only run once, and only if the notifying task has made a change to the system. [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]

Here, `enable apache` will be called if `this installs a package` makes a change. If apache2 is already installed, the handler is not called. [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]
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

#### Variable substitution
Variable substitution is done by specifying the name of the placeholder variable and its value under `vars` as a sibling to `tasks` and `handlers` [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]
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
#### Conditional logic
Conditional logic is implemented with each task by defining a condition as the value for a property `when` [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]
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
## Modules
#### `archive` module
Compress files <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```yaml
- name: Compress directory /path/to/foo/ into /path/to/foo.tgz
  archive:
    path: /path/to/foo
    dest: /path/to/foo.tgz
```
```yaml
- name: Create a bz2 archive of multiple files, rooted at /path
  archive:
    path:
    - /path/to/foo
    - /path/wong/foo
    dest: /path/file.tar.bz2
    format: bz2
```
#### `cli_config`
Platform-agnostic way of pushing text-based configurations to network devices over the **network_cli_connection** plugin <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```yaml
# Set hostname for a switch and exit with a commit message
- name: commit with comment
  cli_config:
    config: set system host-name foo
    commit_comment: this is a test
```
```yaml
# Back up a config to a different destination file
- name: configurable backup path
  cli_config:
    config: "{{ lookup('template', 'basic/config.j2') }}"
    backup: yes
    backup_options:
      filename: backup.cfg
      dir_path: /home/user
```
#### `command` module
Safest module to execute remote commands on client machine, requires Python. When Ansible execute commands using the Command module, they are not processed through the user's shell (meaning environment variables like [ `$HOME` ](../lx/commands/bash.md) and output redirection are not available).

Takes command name followed by a list of space-delimited arguments. <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```sh
ansible all -i inventory -m command -a 'cat /etc/motd' -u ansible
```
```yaml
- name: return motd to registered var
  command: cat /etc/motd
  register: mymotd
```
```yaml
- name: Change the working directory to somedir/ and run the command as db_owner if /path/to/database does not exist.
  command: /usr/bin/make_database.sh db_user db_name
  become: yes
  become_user: db_owner
  args:
    chdir: somedir/
    creates: /path/to/database
```
#### `copy` module
Copy files from the server to nodes (cf. [`file`](#file-module)).
Useful when updating configuration files.

Place a text message into a file through an ad-hoc command
```sh
ansible all -i inventory -m copy -a 'content="Managed by Ansible\n" dest=/etc/motd' -b -u ansible
```

Copy `updated.conf` from the control node to each client. <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```sh
ansible $CLIENT -b -m copy -a "src=./updated.conf dest=/etc/ntp.conf owner=root group=root mode=0644 backup=yes"
```
```yaml
- name: Copy a new "ntp.conf file into place, backing up the original if it differs from the copied version
  copy:
    src: /mine/ntp.conf
    dest: /etc/ntp.conf
    owner: root
    group: root
    mode: '0644'
    backup: yes
```
```yaml
- name: Copy file with owner and permission, using symbolic representation
  copy:
    src: /srv/myfiles/foo.conf
    dest: /etc/foo.conf
    owner: foo
    group: foo
    mode: u=rw,g=r,o=r
```
#### `debug` module
```yaml
- name: Display all variables/facts known for a host
  debug:
    var: hostvars[inventory_hostname]
    verbosity: 4
```
Display content of copy module only when verbosity of 2 is specified (i.e. `ansible-playbook demo.yaml -vv`) [<sup>ref</sup>][https://opensource.com/article/19/9/must-know-ansible-modules]
```yaml
- name: Write some content in a file /tmp/foo.txt
  copy:
    dest: /tmp/foo.txt
    content: |
     Good Morning!
      Awesome sunshine today.
    register: display_file_content
- name: Debug display_file_content
    debug:
      var: display_file_content
      verbosity: 2
```
[[3](#sources)]
#### `file` module
Used for doing file manipulation on the remote system itself. [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-making-things-happen]
#### `state` directive
The `state` directive can take one of several values, and indicates to Ansible what should actually be done to the target file:
`state` value | Effect
:---          | :---
`absent`      | delete file or directory recursively
`directory`   | create directory
`hard`        | create hardlink
`link`        | create symlink
`touch`       | create empty file

Change a file's attributes [<sup>ref</sup>][https://opensource.com/article/19/9/must-know-ansible-modules]
```yaml
- name: Change file ownership, group and permissions
  file:
    path: /etc/foo.conf
    owner: foo
    group: foo
    mode: '0644'
```
Create a symlink 
Ad hoc [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-making-things-happen]
```sh
ansible $CLIENT -b -m file -a "src=/etc/ntp.conf dest=/home/user/ntp.conf owner=user group=user state=link
```
Create a folder using an ad hoc command [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-making-things-happen]
```sh
ansible $CLIENT -b -m file -a "path=/etc/newfolder state=directory mode=0755"
```
Create a folder using a playbook <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```yaml
- name: Create a directory if it does not exist
  file:
    path: /etc/foo
    state: directory
    mode: '0755'
```
#### `git` module
Manage git checkouts of repos <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```yaml
# Create git archive from repo
- git:
    repo: https://github.com/ansible/ansible-examples.git
    dest: /src/ansible-examples
    archive: /tmp/ansible-examples.zip
```
```yaml
- git:
    repo: https://github.com/ansible/ansible-examples.git
    dest: /src/ansible-examples
    separate_git_dir: /src/ansible-examples.git
```
#### `lineinfile` module
Manages lines in a text file, mostly used to ensure a particular line is present or changed in a config. <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```yaml
- name: Ensure SELinux is set to enforcing mode
  lineinfile:
    path: /etc/selinux/config
    regexp: '^SELINUX='
    line: SELINUX=enforcing
```
```yaml
- name: Add a line to a file if the file does not exist, without passing regexp
  lineinfile:
    path: /etc/resolv.conf
    line: 192.168.1.99 foo.lab.net foo
    create: yes
```
#### `raw` module
Similar to [ `shell` ](#shell-module) module, but the user's default shell is used, Ansible doesn't do any error checking, and `STDERR`, `STDOUT`, and `Return Code` are all returned
#### `service` module
Starts a package after installing it. [<sup>ref</sup>][https://opensource.com/article/19/9/must-know-ansible-modules]
```yaml
- name: Start service foo, based on running process /usr/bin/foo
  service:
    name: foo
    pattern: /usr/bin/foo
    state: started
```
```yaml
- name: Restart network service for interface eth0
  service:
    name: network
    state: restarted
    args: eth0
```
#### `shell` module
The Shell module uses /bin/sh in the remote user's environment (cf. [`raw`](#raw-module) module). [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin]

Test authentication by displaying results of [`uptime`](lx/commands.md#uptime) command for each host in the `webservers` group. [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin]
```sh
ansible -m shell -a 'uptime' webservers
```
#### `setup` module
Display [facts][Fact.] Usable almost exclusively in playbooks, although some ad hocs are available.

Display all available information about the system [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-making-things-happen]
```sh
ansible $CLIENT -b -m setup
```
Filter results to `ansible_os_family`, which indicates if the OS is Debian or Red Hat [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-making-things-happen] [<sup>ref</sup>][https://www.tecmint.com/understand-core-components-of-ansible/]
```sh
ansible $CLIENT -b -m setup -a "filter=*family*"
```
#### `snap` module
Install VS Code [<sup>ref</sup>][My playbook]
```yaml
- name: Install VS Code
  snap:
    name: code
    state: present
    classic: yes   
```
#### `template` module
Works similar to mail merge in a word processor. Ansible uses the Jinja2 templating language, which has a syntax similar to Ansible variable substitution. [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]

This example creates a HTML document on each client that is customized using Ansible variables. [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]
```yaml
---
- hosts: webservers
  become: yes

  tasks:
   - name: install apache2
     apt: name=apache2 state=latest update_cache=yes
     when: ansible_os_family == "Debian"

   - name: install httpd
     yum: name=httpd state=latest
     when: ansible_os_family == "RedHat"

   - name: start apache2
     service: name=apache2 state=started enable=yes
     when: ansible_os_family == "Debian"

   - name: start httpd
     service: name=httpd state=started enable=yes
     when: ansible_os_family == "RedHat

   - name: install index
     template:
       src: index.html.j2
       dest: /var/www/html/index.html
```
Jinja template file [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-part-iii-playbooks]
```j2
<html><center>
<h1>This computer is running {{ ansible_os_family }},
and its hostname is:</h1>
<h3>{{ ansible_hostname }}</h3>
{# this is a comment, which won't be copied to the index.html file #}
</center></html>
```
### Package management
There is a specific module for most popular package managers, such as `dnf` and `apt`, but the `package` is generic and will install packages regardless of distribution.\
Install Apache2 using the `apt` module in an ad hoc command [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-making-things-happen]
```sh
ansible $CLIENT -b -m apt -a "update_cache=yes name=apache2 state=latest"
```
Install Apache and MariaDB <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```yaml
- name: install the latest version of Apache and MariaDB
  dnf:
    name:
     - httpd
      - mariadb-server
    state: latest
```
Install PostgreSQL and NGINX <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
```yaml
- name: Install a list of packages
  yum:
    name:
     - nginx
      - postgresql
      - postgresql-server
    state: present
```
## Tasks
Install htop on local computer
```sh
ansible localhost -m package 'name=htop state=present' -b
```
Simple ad-hoc installation to `all` group defined in local inventory file
```sh
ansible all -i inventory -m apt -a 'name=htop state=present' -b -u ansible
```

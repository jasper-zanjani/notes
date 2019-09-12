# Ansible
Ansible is an automation tool used for configuration management using human-readable YAML templates. Ansible is distinguished for being **agentless**, meaning no special software is required on the nodes it manages.
Ansible **playbooks** represent a sequence of scripted actions which apply changes uniformly over a set of hosts.  **Modules** are standalone scripts that enable a particular task across many OSes, services, applications, etc. Predefined modules are available in the **module library**, and new ones can be defined via Python or JSON.\
Ansible host management relies on a `.ini` file containing a list of IP addresses or hostnames organized in groups.
#### /etc/ansible/ansible.cfg
Config for Ansible
#### Package management module
There is a module for most popular package managers, such as `dnf` and `apt`.\
```yaml
# Install Apache and MariaDB
- name: install the latest version of Apache and MariaDB
  dnf:
    name:
     - httpd
      - mariadb-server
    state: latest
```
```yaml
# Install PostgreSQL and NGINX
- name: Install a list of packages
  yum:
    name:
     - nginx
      - postgresql
      - postgresql-server
    state: present
```
[[3](#sources)]
#### Service module
Starts a package after installing it.\
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
[[3](#sources)]
#### Copy module
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
[[3](#sources)]
#### Debug module
```yaml
- name: Display all variables/facts known for a host
  debug:
    var: hostvars[inventory_hostname]
    verbosity: 4
```
Display content of copy module only when verbosity of 2 is specified (i.e. `ansible-playbook demo.yaml -vv`)
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
#### File module
```yaml
- name: Change file ownership, group and permissions
  file:
    path: /etc/foo.conf
    owner: foo
    group: foo
    mode: '0644'
```
```yaml
- name: Create a directory if it does not exist
  file:
    path: /etc/foo
    state: directory
    mode: '0755'
```
[[3](#sources)]
#### Lineinfile module
Manages lines in a text file, mostly used to ensure a particular line is present or changed in a config.
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
[[3](#sources)]
#### Git module
Manage git checkouts of repos
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
[[3](#sources)]
#### CLI_command
Platform-agnostic way of pushing text-based configurations to network devices over the **network_cli_connection** plugin
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
[[3](#sources)]
#### Archive module
Compress files
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
[[3](#sources)]
#### Command module
Takes command name followed by a list of space-delimited arguments
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
[[3](#sources)]
#### Ad hoc commands
The `ansible` command is only used for running **ad hoc** commands, that is commands executed in realtime by an administrator working at the terminal. Modules are called as arguments passed to the `-m` option:\
```sh
ansible all -m ping 
```
#### Executing a playbook
Playbooks are executed with the `ansible-playbook` command
```sh
ansible-playbook -i production site.yml
```
#### Ansible Tower
**Ansible Tower** is a web-based RESTful API endpoint that provides the officially supported GUI frontend to Ansible configuration management. It is a commercial product that is available in two versions: **Standard** ($13,000/yr) and **Premium** ($17,500/yr) [[2](#sources)]\
On login, Tower presents a dashboard that depicts success and failure of Ansible playbook runs. Tower implements RBAC, supporting large teams. [[1](#sources)]\
#### AWX
**AWX** is the open-source project upon which Ansible Tower was built.
## Sources
  1. "Red Hat Ansible Tower Demo". [Web](https://youtu.be/wZ_mh4-4HPY): 2018/09/09.
  2. "Ansible Tower vs. Ansible AWX". [Web](https://4sysops.com/archives/ansible-tower-vs-ansible-awx-for-automation/): 2019/08/13.
  3. "10 Ansible modules you need to know". [Web](https://opensource.com/article/19/9/must-know-ansible-modules): 2019/09/11.

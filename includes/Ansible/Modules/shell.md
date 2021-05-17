[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"
[https://www.linuxjournal.com/content/ansible-making-things-happen]: https://www.linuxjournal.com/content/ansible-making-things-happen "Ansible: Making things happen"
[https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin]: https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin "Ansible: the automation framework that thinks like a sysadmin"
[https://www.tecmint.com/understand-core-components-of-ansible/]: https://www.tecmint.com/understand-core-components-of-ansible/ '"Understand Core Components of Ansible - Part 1" _TecMint_'
[My playbook]: https://github.com/jasper-zanjani/ansible/tree/master/playbooks/packages.yaml "The packages I install"

The Shell module uses /bin/sh in the remote user's environment (cf. [`raw`](#raw-module) module). 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin]</sup>

Test authentication by displaying results of [`uptime`](lx/commands.md#uptime) command for each host in the `webservers` group.
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-automation-framework-thinks-sysadmin]</sup>
```sh
ansible -m shell -a 'uptime' webservers
```
#### `setup`
Display [facts][Fact.] Usable almost exclusively in playbooks, although some ad hocs are available.

Display all available information about the system 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-making-things-happen]</sup>
```sh
ansible $CLIENT -b -m setup
```
Filter results to `ansible_os_family`, which indicates if the OS is Debian or Red Hat 
<sup>[?][https://www.linuxjournal.com/content/ansible-making-things-happen] 
[?][https://www.tecmint.com/understand-core-components-of-ansible/]</sup>

```sh
ansible $CLIENT -b -m setup -a "filter=*family*"
```
#### `snap`
Install VS Code [<sup>ref</sup>][My playbook]
```yaml
- name: Install VS Code
  snap:
    name: code
    state: present
    classic: yes   
```

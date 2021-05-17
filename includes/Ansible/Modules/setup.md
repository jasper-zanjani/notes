Display [facts][Fact.] Usable almost exclusively in playbooks, although some ad hocs are available.

Display all available information about the system 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-making-things-happen]</sup>
```sh
ansible $CLIENT -b -m setup
```
Filter results to `ansible_os_family`, which indicates if the OS is Debian or Red Hat [<sup>ref</sup>][https://www.linuxjournal.com/content/ansible-making-things-happen] 
<sup>[tecmint.com][https://www.tecmint.com/understand-core-components-of-ansible/]</sup>

```sh
ansible $CLIENT -b -m setup -a "filter=*family*"
```

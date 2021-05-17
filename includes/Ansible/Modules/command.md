[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"

Safest module to execute remote commands on client machine, requires Python. When Ansible execute commands using the Command module, they are not processed through the user's shell (meaning environment variables like [ `$HOME` ](https://github.com/jasper-zanjani/notes/blob/primary/lx/README.md#bash) and output redirection are not available).

Takes command name followed by a list of space-delimited arguments. 
<sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>

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


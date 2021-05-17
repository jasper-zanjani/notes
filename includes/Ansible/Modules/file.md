[https://www.linuxjournal.com/content/ansible-making-things-happen]: https://www.linuxjournal.com/content/ansible-making-things-happen "Ansible: Making things happen"
[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"

Used for doing file manipulation on the remote system itself. 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-making-things-happen]</sup>

#### `state` directive
The `state` directive can take one of several values, and indicates to Ansible what should actually be done to the target file:
`state` value | Effect
:---          | :---
`absent`      | delete file or directory recursively
`directory`   | create directory
`hard`        | create hardlink
`link`        | create symlink
`touch`       | create empty file

Change a file's attributes 
<sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>

```yaml
- name: Change file ownership, group and permissions
  file:
    path: /etc/foo.conf
    owner: foo
    group: foo
    mode: '0644'
```
Create a symlink 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-making-things-happen]</sup>
```sh
ansible $CLIENT -b -m file -a "src=/etc/ntp.conf dest=/home/user/ntp.conf owner=user group=user state=link
```
Create a folder using an ad hoc command 
<sup>[linuxjournal.com][https://www.linuxjournal.com/content/ansible-making-things-happen]</sup>

```sh
ansible $CLIENT -b -m file -a "path=/etc/newfolder state=directory mode=0755"
```
Create a folder using a playbook 
<sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>

```yaml
- name: Create a directory if it does not exist
  file:
    path: /etc/foo
    state: directory
    mode: '0755'
```

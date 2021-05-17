[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"

Manages lines in a text file, mostly used to ensure a particular line is present or changed in a config. 
<sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>

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

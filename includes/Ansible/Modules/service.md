[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"

Starts a package after installing it. 
<sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>

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

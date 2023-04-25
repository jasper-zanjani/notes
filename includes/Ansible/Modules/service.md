```yaml title="service"
- name: Start service foo, based on running process /usr/bin/foo
  service:
    name: foo
    pattern: /usr/bin/foo
    state: started
- name: Restart network service for interface eth0
  service:
    name: network
    state: restarted
    args: eth0
```

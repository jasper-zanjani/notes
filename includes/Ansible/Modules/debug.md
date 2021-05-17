[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"

```yaml
- name: Display all variables/facts known for a host
  debug:
    var: hostvars[inventory_hostname]
    verbosity: 4
```
Display content of copy module only when verbosity of 2 is specified (i.e. `ansible-playbook demo.yaml -vv`) 
<sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
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


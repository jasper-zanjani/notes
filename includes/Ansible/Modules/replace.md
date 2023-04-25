```yaml title="replace"
- name: Comment out a line in a config
  ansible.builtin.replace:
    path: /etc/motd
    regexp: '^Hello, (.*)'
    replace: '# Hello, \1'
```
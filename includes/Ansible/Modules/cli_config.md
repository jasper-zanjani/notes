[https://opensource.com/article/19/9/must-know-ansible-modules]: https://opensource.com/article/19/9/must-know-ansible-modules "10 Ansible modules you need to know"

Platform-agnostic way of pushing text-based configurations to network devices over the **network_cli_connection** plugin <sup>[opensource.com][https://opensource.com/article/19/9/must-know-ansible-modules]</sup>
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


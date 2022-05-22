#### cli\_config
:   
    Set hostname for a switch and exit with a commit message
    ```yaml
    - name: commit with comment
      cli_config:
        config: set system host-name foo
        commit_comment: this is a test
    ```

    Back up a config to a different destination file
    ```yaml
    - name: configurable backup path
      cli_config:
        config: "{{ lookup('template', 'basic/config.j2') }}"
        backup: yes
        backup_options:
          filename: backup.cfg
          dir_path: /home/user
    ```

    Platform-agnostic way of [pushing text-based configurations](https://opensource.com/article/19/9/must-know-ansible-modules) to network devices over the **network_cli_connection** plugin.
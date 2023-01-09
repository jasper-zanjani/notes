# Ansible

The architecture of an environment managed by Ansible features several concepts:

- **Controller host** which contains playbooks which are executed
- **Managed hosts** which are controlled using SSH


## Tasks

```yaml title="Hello, World!"
---
- name: Hello, World! playbook
  hosts: all
  tasks:
  - name: Hello, World! play
    command: echo Hello, World!
... # (1)
```

1.     
```sh title="Ad-hoc"
ansible all -m command -a "echo Hello, World!"
```

#### Configuration
:   

    ```ini title="ansible.cfg"
    [privilege_escalation]
    become=yes
    become_method=sudo
    become_user=root
    become_ask_pass=no
    remote_user=ansible

    [defaults]
    interpreter_python=auto_silent
    deprecation_warnings=False
    ```

    ```sh title="Display non-default settings"
    ansible-config dump --only-changed
    ```


#### Documentation
:   
    ```sh title="ansible-doc"
    # List currently installed modules
    ansible-doc -l

    # Get module-specific information
    ansible-doc $MODULE

    # Get example code
    ansible-doc -s $MODULE
    ```

    ```sh title="Verify YAML syntax"
    ansible-playbook --syntax-check $FILE
    ```

#### Files
:   

    ```yaml title="Create file"
    ---
    - name: Create file
      hosts: all
      tasks:
      - name: Create file
        copy:
          dest: /etc/motd
          content: "Hello, World!\n" # (1)
    ...
    ```

    1. Alma Linux 9 requires an additional package to be installed to handle SELinux contexts:
    ```sh
    # This package is incorrectly identified as "libselinux-python" in the Ansible error displayed on the controller host
    dnf install python3-libselinux
    ```

    ```yaml title="Delete file"
    ---
    - name: Delete file
      hosts: all
      tasks:
      - name: Delete file
        file:
          path: /etc/motd
          state: absent
    ...
    ```
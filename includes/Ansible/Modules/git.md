#### git
:   
    Manage git checkouts of repos 

    Create git archive from repo
    ```yaml
    - git:
        repo: https://github.com/ansible/ansible-examples.git
        dest: /src/ansible-examples
        archive: /tmp/ansible-examples.zip
    ```
    
    ```yaml
    - git:
        repo: https://github.com/ansible/ansible-examples.git
        dest: /src/ansible-examples
        separate_git_dir: /src/ansible-examples.git
    ```



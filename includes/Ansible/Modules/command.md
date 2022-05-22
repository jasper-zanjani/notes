#### command
:   
    Safest module to execute a command and arguments on client machine, requires Python. 
    When Ansible execute commands using the Command module, they are not processed through the user's shell (meaning environment variables like $HOME and output redirection are not available).

    Takes command name followed by a list of space-delimited arguments. 

    ```sh
    ansible all -i inventory -m command -a 'cat /etc/motd' -u ansible
    ```
    ```yaml
    - name: return motd to registered var
      command: cat /etc/motd
      register: mymotd
    ```
    ```yaml
    - name: Change the working directory to somedir/ and run the command as db_owner if /path/to/database does not exist.
      command: /usr/bin/make_database.sh db_user db_name
      become: yes
      become_user: db_owner
      args:
        chdir: somedir/
        creates: /path/to/database
    ```

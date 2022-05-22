#### file
:   
    Used for doing file manipulation on the remote system itself. 

    The **state directive** can take one of several values, and indicates to Ansible what should actually be done to the target file:

    - **absent** delete file or directory recursively
    - **directory** create directory                    
    - **hard** create hardlink                     
    - **link** create symlink                      
    - **touch** create empty file                   

    Change a file's attributes 
    ```yaml
    - name: Change file ownership, group and permissions
      file:
        path: /etc/foo.conf
        owner: foo
        group: foo
        mode: '0644'
    ```

    Create a symlink 
    ```sh
    ansible $CLIENT -b -m file -a "src=/etc/ntp.conf dest=/home/user/ntp.conf owner=user group=user state=link
    ```

    Create a folder using an ad hoc command 
    ```sh
    ansible $CLIENT -b -m file -a "path=/etc/newfolder state=directory mode=0755"
    ```

    Create a folder using a playbook 
    ```yaml
    - name: Create a directory if it does not exist
      file:
        path: /etc/foo
        state: directory
        mode: '0755'
    ```

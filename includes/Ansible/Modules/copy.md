#### copy
:   
    Copy files from the server to nodes (cf. [`file`](#file-module)).
    Useful when updating configuration files.

    Place a text message into a file through an ad-hoc command
    ```sh
    ansible all -i inventory -m copy -a 'content="Managed by Ansible\n" dest=/etc/motd' -b -u ansible
    ```
    Copy `updated.conf` from the control node to each client. 

    ```sh
    ansible $CLIENT -b -m copy -a "src=./updated.conf dest=/etc/ntp.conf owner=root group=root mode=0644 backup=yes"
    ```
    ```yaml
    - name: Copy a new "ntp.conf file into place, backing up the original if it differs from the copied version
      copy:
        src: /mine/ntp.conf
        dest: /etc/ntp.conf
        owner: root
        group: root
        mode: '0644'
        backup: yes
    ```
    ```yaml
    - name: Copy file with owner and permission, using symbolic representation
      copy:
        src: /srv/myfiles/foo.conf
        dest: /etc/foo.conf
        owner: foo
        group: foo
        mode: u=rw,g=r,o=r
    ```

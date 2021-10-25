#### Samba
:   
    Configure Samba 
    ```sh
    mkdir /samba                   # Create a directory for the share
    chmod -R 0777 /samba
    chown -R nobody:nobody /samba  # Remove ownership
    ```
    Open firewall rule
    ```sh
    firewall-cmd --permanent --add-service=samba
    firewall-cmd --reload
    firewall-cmd --list-services # verify
    ```

    Configure the main Samba config file at **/etc/samba/smb.conf**
    ```ini
    [samba-share]
        comment = Samba on Ubuntu
        path = /samba
        read only = no
        browsable = yes
    ```

    Verify configuration
    ```sh
    testparm
    ```

    Allow SELinux to work with Samba
    ```sh
    setsebool -P samba_export_all_ro on
    ```

    Set up a Samba account for `$USER`
    ```sh
    smbpasswd -a $USER
    ```

    Restart Samba service
    ```sh
    systemctl restart smbd
    ```


    Access samba share at `$SHARE` at server `$HOST` using user credential `$USER`
    ```sh
    smbclient //$HOST/$USER -U $USER
    ```

    This will display the Samba CLI
    ```
    smb: \>
    ```

    On TrueNAS, the option to "Allow Guest Access" should be turned on, unless password-based authentication for specific users is desired.
    Also, the directory must have write permissions enabled to allow uploading.
    ```sh
    chmod o+w
    ```
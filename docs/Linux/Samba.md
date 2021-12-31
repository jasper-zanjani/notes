#### Samba

Configure Samba 
```sh
mkdir /samba                   # Create a directory for the share
chmod -R 0777 /samba           # If the folder being shared on the host does not have write permissions, clients will be able to connect but not to create new files.
chown -R nobody:nobody /samba  # Remove ownership
```
Open firewall rule
```sh
firewall-cmd --permanent --add-service=samba
firewall-cmd --reload
firewall-cmd --list-services # verify
```

Configure the main Samba config file at **/etc/samba/smb.conf**. The name in brackets becomes the name of the share.
```ini
[samba]
    comment = Samba on Ubuntu
    path = /samba
    guest ok = yes
    read only = no # equivalent to `writeable = yes`
    browsable = yes
```

If only certain users are to be granted access:
```ini
[samba]
    guest ok = no
    valid users = mohsen
```

This user must already be a valid user in the host OS as well as in the Samba system
```sh
useradd mohsen
smbpasswd -a mohsen
```

Verify configuration
```sh
testparm
```

Set SELinux context of share directory
```sh
semanage fcontext -a -t samba_share_t '/samba(/.*)?'
restorecon -vvFR /samba
```

<!--
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
-->

Browse all available shares. If guest access is enabled then a blank username and password can be provided.
```sh
smbclient -L $HOST
```

Access share "samba" at server `$HOST` using user credential `$USER`
```sh
smbclient //$HOST/samba -U $USER
```

This will display the Samba CLI
```
smb: \>
```

Because Windows requires a credential to be sent, a user credential must be added to the Samba application, even one with an empty password.

```sh
smbpasswd -a nobody
```
The username logged into by the Windows user then becomes the Linux owner of any files created, if the permissions to do so are set.
The domain used for logging in (set by the **`workgroup`** directive and set to "SAMBA" in default configs) does not appear to be important.

So long as the parent directory is `o+w` clients are able to create files (which are owned by their credential) and delete **any** files, but not subdirectories **unless** they are owned by that account.
Permissions of subdirectories take precedence over the parent, such that a subdirectory may be written to even though the root directory of a share may not.


On TrueNAS, the option to "Allow Guest Access" should be turned on, unless password-based authentication for specific users is desired.
Also, the directory must have write permissions enabled to allow uploading.

Bizarrely, the ability to navigate into subdirectories appears to depend on the owner execute bit.
This may have something to do with anonymous guest access.
```sh
chmod o+x
```

Permanently mounting a Samba share in /etc/fstab
```
//nas/Videos /home/jasper/Videos cifs guest,uid=1000,iocharset=utf8 0 0
```
Then mount the fstab file
```sh
mount -a
```

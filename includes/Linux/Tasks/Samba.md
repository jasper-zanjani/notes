# Samba

Configure Samba 
```sh
mkdir /samba                   # Create a directory for the share
chmod -R 0777 /samba
chown -R nobody:nobody /samba  # Remove ownership, not necessary
```

Open firewall rule (not strictly necessary)
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
    read only = no
    browsable = yes
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

<!-- Allow SELinux to work with Samba
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
``` -->

Browse all available shares
```sh
smbclient -L $HOST
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
Bizarrely, the ability to navigate into subdirectories appears to depend on the owner execute bit.
This may have something to do with anonymous guest access.
```sh
chmod u+x
```

Permanently mounting a Samba share in /etc/fstab
```
//nas/Videos /home/jasper/Videos cifs guest,uid=1000,iocharset=utf8 0 0
```
Then mount the fstab file
```sh
mount -a
```

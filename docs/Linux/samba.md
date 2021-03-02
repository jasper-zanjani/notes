# Samba

### /etc/samba/smb.conf

Configure Samba [ref](https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/ "vitux.com: \"How to Install and Configure Samba on Ubuntu\"")
```ini
[samba-share]
comment = Samba on Ubuntu
path = /samba
read only = no
browsable = yes
```
Configure anonymous unsecured file sharing on a shared directory [[41](#sources)]
```ini
[global]
workgroup = WORKGROUP
netbios name = rhel
security = user
...
[Anonymous]
comment = Anonymous File Server Share
path = /srv/samba/anonymous
browsable =yes
writable = yes
guest ok = yes
read only = no
force user = nobody
```

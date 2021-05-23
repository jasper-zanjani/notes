#### Install Samba
Install and configure Samba server [src][https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/]

Install `samba`
```sh
sudo apt install samba
```
Verify the samba service `smbd` is running
```sh
sudo systemctl status smbd
```
Configure Samba 
```sh
sudo mkdir /samba                   # Create a directory for the share
sudo chmod -R 0777 /samba
sudo chown -R nobody:nobody /samba  # Remove ownership
```
Open firewall rule
```sh
sudo firewall-cmd --permanent --add-service=samba
sudo firewall-cmd --reload
```
Configure Samba config file at [/etc/samba/smb.conf][/etc/samba/smb.conf]
```conf
[samba-share]
comment = Samba on Ubuntu
path = /samba
read only = no
browsable = yes
```
Set up a Samba account for `$USER`
```sh
sudo smbpasswd -a $USER
```
Restart Samba service [vitux.com][https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/] [tecmint.com](https://www.tecmint.com/install-samba-on-rhel-8-for-file-sharing-on-windows/ "Install Samba4 on RHEL 8 for File Sharing on Windows")
```sh
sudo systemctl restart smbd.service
```
Install and configure Samba as a client
```sh
sudo apt install smbclient 
```
Access samba share at `$SHARE` at server `$HOST` using user credential `$USER`
```sh
sudo smbclient //$HOST/$USER -U $USER
```
This will display the Samba CLI
```
smb: \>
```
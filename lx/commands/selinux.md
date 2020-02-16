# SELinux commands
&nbsp;  | Commands
---     | ---
&nbsp;  | `restorecon` `semanage` `sestatus` `setenforce`

Display SELinux contexts for processes
```sh
ps auxZ
```
Display SELinux context for files
```sh
ls -Z
```

### `restorecon`
Restore security context default in the policy
```sh
restorecon -Rv website
```
### `sestatus`
Display status of SELinux
```sh
sestatus
```
### `setenforce`
Change SELinux mode
```sh
setenforce enforcing
setenforce 1
setenforce permissive
setenforce 0
setenforce disabled
```
### `semanage`
Amend policy to add a file context
```sh
semanage fcontext -a -t httpd_sys_content_t website
```
Add a port context
```sh
semanage port -a -t http_port_t -p tcp 8080
```
Display all ports with attached types
```sh
semanage port -l
```

[sestatus]:                                          #sestatus                                '```&#10;sestatus&#10;```&#10;Display status of SELinux&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[setenforce]:                                        #setenforce                              '```&#10;setenforce&#10;```&#10;Change SELinux mode&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[semanage]:                                          #semanage                                '```&#10;$ semanage&#10;```&#10;Edit security contexts for files and ports'
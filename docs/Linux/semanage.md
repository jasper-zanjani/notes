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
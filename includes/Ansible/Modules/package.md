[https://www.linuxjournal.com/content/ansible-making-things-happen]: https://www.linuxjournal.com/content/ansible-making-things-happen "Ansible: Making things happen"

There is a specific module for most popular package managers, such as `dnf` and `apt`, but the `package` is generic and will install packages regardless of distribution.

Install Apache2 using the `apt` module in an ad hoc command 

```sh
ansible $CLIENT -b -m apt -a "update_cache=yes name=apache2 state=latest"
```
Install Apache and MariaDB 
```yaml
- name: install the latest version of Apache and MariaDB
  dnf:
    name:
     - httpd
      - mariadb-server
    state: latest
```
Install PostgreSQL and NGINX 
```yaml
- name: Install a list of packages
  yum:
    name:
     - nginx
      - postgresql
      - postgresql-server
    state: present
```


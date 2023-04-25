```yaml title="package"
- name: Install Apache and MariaDB
  dnf:
    name:
    - httpd
    - mariadb-server
    state: latest
- name: Install PostgreSQL and NGINX
  yum:
    name:
    - nginx
    - postgresql
    - postgresql-server
    state: present
```
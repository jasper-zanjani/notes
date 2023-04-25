```yaml title="file"
- name: Change file ownership, group and permissions
  file:
    path: /etc/foo.conf
    owner: foo
    group: foo
    mode: '0644'
- name: Create a directory if it does not exist
  file:
    path: /etc/foo
    state: directory
    mode: '0755'
```
```sh title="file"
# Create a symlink
ansible $CLIENT -b -m file -a "src=/etc/ntp.conf dest=/home/user/ntp.conf owner=user group=user state=link"

# Create a folder using an ad hoc command
ansible $CLIENT -b -m file -a "path=/etc/newfolder state=directory mode=0755"
```

  

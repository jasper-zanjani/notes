```sh title="setup"
# Display all available information about a system
ansible $CLIENT -b -m setup

# Filter results to ansible_os_family, which indicates if the OS is Debian or Red Hat
ansible $CLIENT -b -m setup -a "filter=*family*"
```

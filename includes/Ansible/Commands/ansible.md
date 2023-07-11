Used to run **ad-hoc commands** from the command-line.

```sh title="Ad-hoc commands"
ansible all -m shell -a env
ansible all -a env # (1)
```

1. The **command** module is default and does not have to be made explicit


```sh title="Delineate hosts"
ansible all --list-hosts

# Display specific groups from a provided inventory
ansible --list-hosts rhel7:rhel8 -i pods/inventory_role/pd/hosts
```
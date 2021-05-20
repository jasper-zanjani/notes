Playbooks are executed with the `ansible-playbook` command
```sh
ansible-playbook -i $CLIENT $PLAYBOOK
```

Check if a playbook has valid syntax
```sh
ansible-playbook --syntax-check $PLAYBOOK
```
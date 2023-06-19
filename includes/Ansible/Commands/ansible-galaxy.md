```sh
# Log in
ansible-galaxy login

# Search for roles
ansible-galaxy search $ROLE

# Install a public role (to ~/.ansible/roles by default)
ansible-galaxy install $USER.$ROLE

# Initiate the skeleton structure of a role
ansible-galaxy init $ROLENAME

# Upload a role
ansible-galaxy import $USERNAME $REPONAME
ansible-galaxy import --no-wait $USERNAME $REPONAME # send job to background
```

A [requirements file](https://galaxy.ansible.com/docs/using/installing.html#installing-multiple-roles-from-a-file) can also be used.
```sh
ansible-galaxy role install -r requirements.yml
```
```yaml title="requirements.yml"
roles:
- src: git+https://jasperzanjani@dev.azure.com/jasperzanjani/NewDevOpsProject/_git/motd-role # (1)
  version: master
```

1. By default, ansible-galaxy will expect a tarball, unless `git+` is prepended to the URL.

As long as a public key is [registered](https://learn.microsoft.com/en-us/azure/devops/repos/git/use-ssh-keys-to-authenticate?view=azure-devops) with Azure DevOps (and an outbound SSH connection isn't blocked by the firewall), the requirements file can use an SSH connection.
```yaml
roles:
- src: git@ssh.dev.azure.com:v3/jasperzanjani/NewDevOpsProject/motd-role
  version: master
```

Variables in 
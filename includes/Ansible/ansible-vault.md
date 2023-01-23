```sh
# Create an encrypted file, providing password interactively
ansible-vault create $file

# Use a cleartext password file
ansible-vault view --vault-password-file=vault-pw $file

# Encrypt/decrypt a file in-place, overwriting original file
ansible-vault encrypt $file
ansible-vault decrypt $file

ansible-vault edit secret.yml
```
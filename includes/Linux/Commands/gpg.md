Decrypt file
```sh
gpg file.txt
```
Export GPG public key
```sh
gpg --export --output ~/jdoe.pub
```
Import another person's public key
```sh
gpg --import jdoe.pub
```
List available GPG keys
```sh
gpg --list-key
```
Encrypt a file
```sh
gpg --encrypt -r jdoe@dplaptop.lab.itpro.tv ./file.txt
```
Sign {file} without encrypting it (produces file.asc)
```sh
gpg --clearsign file
```
Generate a key
```sh
gpg --generate-key
gpg --gen-key
```
Import another person's public key
```sh
gpg --import ~/jdoe.pub
```
Send keys to {keyserver}
```sh
gpg --send-keys keyIDs --keyserver keyserver
```
### `sudo`
`sudo` is installed by default on most distros, but it can be installed. [[52](sources.md)]\
In order to use `sudo`, users have to be added to special groups that vary based on distribution. The group `wheel` grants access to `sudo` on Red Hat derivatives, while there is a group named `sudo` on Debian, Ubuntu, and derivatives to do the same thing.\
Using `sudo` with output redirection will cause an error if the effective user doesn't have write permissions. 
- Invoke a new shell as root by using `sudo sh -c`
- Pipe output to `sudo tee` command

Prevent sudo from prompting for credentials or for any other reason
```sh
sudo --noprompt
```

### `su`
Obtain the normal login environment
```sh
su -
```
Execute a single command with a non-interactive session
```sh
su -c cmd
```
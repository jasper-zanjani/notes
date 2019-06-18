# Sudo
`sudo` is installed by default on most distros, but it can be installed.

## Usage
In order to use `sudo`, users have to be added to special groups that vary based on distribution. The group `wheel` grants access to `sudo` on Red Hat derivatives, while there is a group named `sudo` on Debian, Ubuntu, and derivatives to do the same thing.

### sudoers file

Syntax  | Effect
:---    | :---
`linuxize ALL=/bin/mkdir` | allow sudo access to user <linuxize> only for command /bin/mkdir
`linuxize ALL=(ALL) NOPASSWD: ALL` | allow user <linusize> to run sudo commands without authenticating himself
`Defaults timestamp_timeout=10` | change timeout to 10 minutes
`Defaults:linuxize timestamp_timeout=10` | change timeout to 10 minutes only for user <linuxize>

### Redirecting
Using `sudo` with output redirection will cause an error if the effective user doesn't have write permissions. 
  - Invoke a new shell as root by using `sudo sh -c`
  - Pipe output to `sudo tee` command

## Sources
  - [linuxize.com](https://linuxize.com/post/sudo-command-in-linux/)

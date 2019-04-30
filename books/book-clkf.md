# Command-Line Kung-Fu, by Jason Cannon

#### Run the last command as root
`sudo !!` `su -c "!!"`

#### Repeat the last command that started with a given string
`!<string>`

#### Reuse the second word (first argument) from the previous command
`!^`

#### Reuse the last word (last argument) from the previous command
`!$`

#### Reuse the nth word from a previous command
`!!:n`
: n is 0-indexed, so `!!:0` would refer to the command itself, etc

#### Repeat the previous command while substituting a string
`^<string1>^<string2>^`
: replace only the first occurrence of {string1}; trailing `^` is optional

`^<string1>^<string2>^:&`
: replace all occurrences; trailing `^` is required

#### Reference a word of the current command and reuse it
`!#:n`
: zero-based word reference {n} (0 is the command, etc)

#### Save a copy of your command line session
`script`

#### Find out which commands you use most often
`history | awk '{print $2' | sort | uniq -c | sort -rn | head`

#### Clear your shell history
`history -c`

#### Strip out comments and blank lines
`grep -E -v "^#|^$" file`

#### Use vim to edit files over the network
`vim scp://user@host/path/file`

#### Display output in a table
`| command -t`
: space-delimited text is put into columns

#### Grab the last word on a line of output
`awk '{print $NF}' file`

#### View colorized output with less
`| less -R`
: force `less` to preserve the raw string codes of input

#### Preserve color when piping to grep
`| grep --color=never`
: prevent `grep` from recolorizing input

#### Append text to a file using sudo
`| sudo tee`

#### Change the case of a string
`tr [:upper:] [:lower:]`

#### Display your command search path in a human readable format
`echo $PATH | tr ':' '\n'`

#### Create a text file from the command line without using an editor
`cat > file`
: will prompt for input from STDIN, until <^d> to signal EOF

#### Display a block of text between two strings
`awk '/start/,/stop/' file`

#### Delete a block of text between two strings
`sed '/start/,/stop/d' file`

#### Fix common typos with aliases
`alias grpe='grep'`

#### Sort the body of output while leaving the header on the first line intact
```bash
body() {
  IFS=read -r header
  printf "%s\n" "$header"
  "$@"
```
: insert this into .bash_profile

#### Remove a character or set of characters from a string or line of output
`tr -d "text"`

#### Count the number of occurrences of a string
`| uniq -c | sort -nr`

#### Serve files in the current directory via a web interface
`python -m SimpleHTTPServer 8080`
`python3 -m http.server`
: using port 80 requires sudo, since it is a privileged port

#### Mount a directory from a remote server on your local host via SSH
`sshfs remotehost:/directory mountpoint`
`fusermount -u mountpoint`

#### Get your public IP from the command line using curl
`curl ifconfig.me`

#### SSH into a remote system without a password
`ssh-keygen`
`ssh-copy-id remotehost`
`ssh remotehost`
: contents of the public key need to be in `~/.ssh/authorized_keys` on the remote host

#### Show open network connections
`sudo lsof -Pni`
: `lsof` can be used to display open files, open network ports, and network connections; `-P` prevents the conversion of port numbers to port names; `-i` displays network connections; `-n` prevents the conversion of IP addresses to hostnames

#### Compare the differences between a remote and local file
`ssh remotehost cat /path/to/remotefile | dif /path/to/localfile`
: cat a file over SSH and pipe the output into a diff or sdiff command

#### Send email from the command-line
`mail recipient@domain.com`
: send email interactively

`echo 'message' | mail -s 'subject' recipient@domain.com`
: send message via pipe 

#### Send an email attachment from the command-line
`mail -a /path/to/attachment`
: send email interactively

`echo 'message' | mail -s 'subject' -a /path/to/attachment`
: send message via pipe

#### Create an SSH tunnel to access remote resources
you can tunnel into a server to access a website which your local machine may not
`ssh -N -L localport:host:remoteport remotehost`
: `-L` creates the SSH tunnel; first port is the port that will be opened on the local machine; 

#### Find out which programs are listening on which ports
`sudo netstat -nutlp`
: `-n` show numerical addresses instead of determining symbolic names; `-u` include UDP protocol; `-t` include TCP protocol; `-l` show only listening sockets; `-p` show PID and program name

#### Use a different SSH key for a given remote host
modify the `~/.ssh/config` file
```config
Host remote-host
IdentityFile ~/.ssh/id_rsa-remote-host
```

`ssh -i ~/.ssh/id_rsa-db1 db1.example.com`
: use different SSH keys for different hosts by specifying the `-i` option

#### Avoid having to type your username when connecting via SSH
modify the `~/.ssh/config` file
```config
Host remote-host
User username
```
: avoid having to type {username@} when connecting to {remote-host}
#### Simplify multi-hop SSH connections and transparently proxy SSH
modify the `~/.ssh/config` file
```config
Host jumphost.example.com
  ProxyCommand none
Host *.example.com
  ProxyCommand ssh -W %h:%p jumphost.example.com
```
: configure SSH to automatically use a gateway server when accessing a host and proxy a ssh connection to server1 from through {jumphost}

#### Disconnect from a remote session and reconnect at a later time, picking up where you left off
start a screen session before launching a long-running process on a remote host, but after connecting via SSH. By detaching the session and then reattaching later, you can review output using vim keybindings

#### Configure SSH to append domain names to host names based on a pattern
modify the `~/.ssh/config` file
```config
host-prefix* !*.domain.com
  HostName %h.domain.com
```

#### Run a command immune to hangups, allowing the job to run after you disconnect
`nohup command &`

#### Encrypt your web browsing data with an SSH SOCKS proxy
i`ssh -D PORT remote-host`

#### Download a webpage, HTTP data, or use a web API from the command-line
`curl -o file.html http://website/webpage`
`wget http://website/webpage`

#### Use vim to edit files over the network
`vim scp://remotehost//path/to/file`
`vim scp://remote-user@remote-host//path/to/file`


#### Use a `for` loop at the command-line
```bash
for VAR in LIST
do
  cmds
done
```

#### Command substitution
`VAR=$(command)`

#### Store command-line output as a variable to use later
```bash
for VAR in LIST
do
  FOO=$(command)
  BAR=$(command)
  echo "$FOO BAR"
done
```

#### Read in input one line at a time
```bash
while read LINE
do
  cmd
done < file.txt
```

```bash
command | while read LINE
do
  cmd
done
```

#### Accept user input and store it in a variable
```bash
read VAR
read -n 1 VAR
read -p "Prompt text: " VAR
```
: `-n 1` will accept only the first letter of the written word

#### Sum all the numbers in a given column of a text
`awk '{sum += $1} END {print sum}' file`
: add up all first records to {sum}, then print that number out at the end

#### Automatically answer yes to any command
`yes | cmd`
: print out "y" until process is killed

## System administration

#### Display mounted file systems in a tabular format
`mount | column -t`
: by default, mount displays all mounted filesystems

#### Kill all processes for a given user or program
`pkill -9 cmd`
`pkill -9 -u user cmd`
: kill several processes with a single command

#### Repeat a command until it succeeds
```bash
while true
do
  cmd && break
done
```

#### Find who is using the most disk space
`sudo du -s /home | sort -n`

#### Find the files that are using the most disk space
`find / -type f -exec wc -c {} \; | sort -n`

#### List processes, sorted by memory usage
`ps aux | sort -nk 4`
: processes consuming the most memory will be at the bottom

`ps aux | sort -nk 4 | tail -5`
: five worst offenders

#### List processes, sorted by CPU usage
`ps aux | sort -nk 3`
: processes consuming the most CPU will be at the bottom

#### Quickly tell if you are on a 32- or 64-bit system
`getconf LONG_BIT`
: return '32' or '64'

#### Generate a random password
`openssl rand -base64 48 | cut -c1-PASSWORD-LENGTH`
: use `openssl` to generate a random password

`gpw () { openssl rand -base64 48 | cut -c1-${1};}`

## Files and directories

#### Quickly make a backup of a file
`cp file{,.bak}`
: brace expansion allows creation of multiple command-line args from a single one (equivalent to `cp file file.bak`)
`mkdir -p ~/my-app/{bin,lib,log}`
: `-p` argument creates parent directories if they don't exist

#### Quickly change a file's extension
`mv file{.old,.new}`
: using brace expansion

#### Create backups of files by date with ease
`alias d='date +%F'`
: using format "YYYY-MM-DD"
`cp file{,.$(d)}`
: append date to end of filename of copy using new alias

#### Overwrite the contents of a file
`cmd > file`

#### Empty a file that is being written to
`> file`
`cat /dev/null > file`
: if a process has a file open it will continue to write to the file if you try to delete it naively. This way the file is truncated and applications can continue writing to it.

#### Append a string to a file
`cmd >> file`

#### Follow a file as it grows
`tail -f file`
: view tail of file in realtime

#### Watch multiple log files at the same time
`multitail files`
: not available on BSD

#### Delete empty directories
`find . -type d -empty -delete`
: `-type d` finds directories

#### Print a list of files that contain a given string
`grep -rl string a`
: `-r` recursive; `-l` list files that match

#### An easy-to-read recursive file listing
`find . -type f -ls`

#### View files and directories in a tree format
`tree`
`tree -d`
: `-d` see only directories

`tree -L n`
: `-L` limit depth to {n}

#### Replace a string in multiple files
`find /path -type f -exec sed -i.bak`
: 

#### Extract the nth line from a file
`awk 'NR==N'`

#### Convert text files from Windows format to Linux format and vice-versa
`dos2unix` | `unix2dos` 

#### Change to the previous working directory
`cd -`

#### Reset your terminal emulator display
`reset`

#### Search Wikipedia from the Command-line
`dig +short txt <string>.wp.dg.cx`
`host -t txt <string>.wp.dg.cx`
: DNS returns Wikipedia article summaries as TXT records

#### Make non-interactive shell sessions behave the same as interactive sessions
`if [ -f ~/.bashrc ]; then source ~/.bashrc; fi`
: make .bash_profile point to .bashrc so that non-interactive sessions (like SSH) behave the same as interactive sessions (login)

#### Make your computer talk to you
`espeak -f file`
`echo text | espeak`
: text-to-speech (not available on BSD)

#### Display the current date and time in a different time zone
`TZ=<TIMEZONE> date`
`TZ=MST date`
TZ environment variable specifies timezone

#### Display a calendar at the command-line
`cal`
`cal MM YYYY`
`cal YYYY`

#### Extract a tar archive to a different directory
`tar archive -C /path/to/directory`
`tar xf archive -C /path/to/directory`

#### Transform the directory structure of a tar file when extarcting it
`tar xf archive --strip-components=n`
: where {n} is a number that represents the level of the top directory from which to extract

#### Use a spreadsheet from the command-line
`sc`
: not available on BSD

#### Rudimentary command-line stopwatch
`time read`
: will stop when you press enter, displaying how much time elapsed

#### Repeat a command at regular intervals and watch its changing output
`watch cmd -n n`
: execute {cmd} at periods of {n} seconds, watching its output

#### Execute a command at a given time
`echo "cmd" | at time`
`at -f file time`

#### Share your screen session with another user
`screen -x user/session`

#### Execute an unaliased version of an aliased command
`\cmd`
: if {cmd} is a command as well as an alias, use the backslash to run it as the original command

#### Save the output of a command as an image
`cmd | convert label:@- image.png`
: `convert` command from ImageMagick software suite

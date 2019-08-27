# Command-Line Kung-Fu, by Jason Cannon
#### Run the last command as root
```sh
sudo !!` `su -c "!!"
```
#### Repeat the last command that started with a given string
```sh
!<string>
```
#### Reuse the second word (first argument) from the previous command
```sh
!^
```
#### Reuse the last word (last argument) from the previous command
```sh
!$
```
#### n-th word of previous command
`n` is 0-indexed, so `!!:0` would refer to the command itself, etc
```sh
!!:n
```
#### n-th word of current command
`n` is 0-indexed, so `!#:0` would be the command itself, etc
```sh
!#:n
```
#### Replace only the first occurrence of a string
Trailing `^` is optional, but the string must be placed within angle brackets
```sh
^<string1>^<string2>^
```
#### Replace all occurrences of a string
Trailing `^` is required
```sh
^<string1>^<string2>^:&
```
#### Save a copy of your command line session
```sh
script
```
#### Find out which commands you use most often
```sh
history | awk '{print $2' | sort | uniq -c | sort -rn | head
```
#### Clear your shell history
```sh
history -c
```
#### Strip out comments and blank lines
```sh
grep -E -v "^#|^$" file
```
#### Use vim to edit files over the network
```sh
vim scp://user@host/path/file
```
#### Display output in a table
Pipe output of another command into `column -t`; space-delimited text is put into columns
```sh
command | column -t
```
#### Grab the last word on a line of output
```sh
awk '{print $NF}' file
```
#### View colorized output with less
Force `less` to preserve the raw string codes of input
```sh
cmd | less -R
```
#### Preserve color when piping to grep
Prevent `grep` from recolorizing input
```sh
cmd | grep --color=never
```
#### Append text to a file using sudo
```sh
cmd | sudo tee
```
#### Change the case of a string
```sh
tr [:upper:] [:lower:]
```
#### Display your command search path in a human readable format
```sh
echo $PATH | tr ':' '\n'
```
#### Create a text file from the command line without using an editor
Will prompt for input from STDIN, until <^d> to signal EOF
```sh
cat > file
```
#### Display a block of text between two strings
```sh
awk '/start/,/stop/' file
```
#### Delete a block of text between two strings
```sh
sed '/start/,/stop/d' file
```
#### Fix common typos with aliases
```sh
alias grpe='grep'
```
#### Sort the body of output while leaving the header on the first line intact
Insert this into **.bash_profile**
```bash
body() {
  IFS=read -r header
  printf "%s\n" "$header"
  "$@"
```
#### Remove a character or set of characters from a string or line of output
```sh
tr -d "text"
```
#### Count the number of occurrences of a string
```sh
| uniq -c | sort -nr
```
#### Serve files in the current directory via a web interface
Using port 80 requires sudo, since it is a privileged port
```sh
python -m SimpleHTTPServer 8080
```
```sh
python3 -m http.server
```
#### Mount a directory from a remote server on your local host via SSH
```sh
sshfs remotehost:/directory mountpoint
```
```sh
fusermount -u mountpoint
```
#### Get your public IP from the command line using curl
```sh
curl ifconfig.me
```
#### SSH into a remote system without a password
Contents of the public key need to be in `~/.ssh/authorized_keys` on the remote host
```sh
ssh-keygen
ssh-copy-id remotehost
ssh remotehost
```
#### Show open network connections
`lsof` can be used to display open files, open network ports, and network connections; `-P` prevents the conversion of port numbers to port names; `-i` displays network connections; `-n` prevents the conversion of IP addresses to hostnames
```sh
sudo lsof -Pni
```
#### Compare the differences between a remote and local file
`cat` a file over SSH and pipe the output into a diff or sdiff command
```sh
ssh remotehost cat /path/to/remotefile | diff /path/to/localfile
```
#### Send email from the command-line
Send email interactively
```sh
mail recipient@domain.com
```
Send message via pipe 
```sh
echo 'message' | mail -s 'subject' recipient@domain.com
```
#### Send an email attachment from the command-line
Send email interactively
```sh
mail -a /path/to/attachment
```
Send message via pipe
```sh
echo 'message' | mail -s 'subject' -a /path/to/attachment
```
#### Create an SSH tunnel to access remote resources
you can tunnel into a server to access a website which your local machine may not; `-L` creates the SSH tunnel; first port is the port that will be opened on the local machine; 
```sh
ssh -N -L localport:host:remoteport remotehost
```
#### Find out which programs are listening on which ports
`-n` show numerical addresses instead of determining symbolic names; `-u` include UDP protocol; `-t` include TCP protocol; `-l` show only listening sockets; `-p` show PID and program name
```sh
sudo netstat -nutlp
```
#### Use a different SSH key for a given remote host
Modify the `~/.ssh/config` file
```config
Host remote-host
IdentityFile ~/.ssh/id_rsa-remote-host
```
Use different SSH keys for different hosts by specifying the `-i` option
```sh
ssh -i ~/.ssh/id_rsa-db1 db1.example.com
```
#### Avoid having to type your username when connecting via SSH
Modify the `~/.ssh/config` file to avoid having to type {username@} when connecting to {remote-host}
```config
Host remote-host
User username
```
#### Simplify multi-hop SSH connections and transparently proxy SSH
modify the `~/.ssh/config` file
```config
Host jumphost.example.com
  ProxyCommand none
Host *.example.com
  ProxyCommand ssh -W %h:%p jumphost.example.com
```
Configure SSH to automatically use a gateway server when accessing a host and proxy a ssh connection to server1 from through {jumphost}
#### Disconnect from a remote session and reconnect at a later time, picking up where you left off
Start a screen session before launching a long-running process on a remote host, but after connecting via SSH. By detaching the session and then reattaching later, you can review output using vim keybindings
#### Configure SSH to append domain names to host names based on a pattern
modify the `~/.ssh/config` file
```config
host-prefix* !*.domain.com
  HostName %h.domain.com
```
#### Run a command immune to hangups, allowing the job to run after you disconnect
```sh
nohup command &
```
#### Encrypt your web browsing data with an SSH SOCKS proxy
```sh
ssh -D PORT remote-host
```
#### Download a webpage, HTTP data, or use a web API from the command-line
```sh
curl -o file.html http://website/webpage
wget http://website/webpage
```
#### Use vim to edit files over the network
```sh
vim scp://remotehost//path/to/file
vim scp://remote-user@remote-host//path/to/file
```
#### Use a `for` loop at the command-line
```bash
for VAR in LIST
do
  cmds
done
```
#### Command substitution
```sh
VAR=$(command)
```
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
`read -n 1` will accept only the first letter of the written word
```bash
read VAR
read -n 1 VAR
read -p "Prompt text: " VAR
```
#### Sum all the numbers in a given column of a text
Add up all first records to {sum}, then print that number out at the end
```sh
awk '{sum += $1} END {print sum}' file
```
#### Automatically answer yes to any command
Print out "y" until process is killed
```sh
yes | cmd
```
#### Display mounted file systems in a tabular format
By default, `mount` displays all mounted filesystems
```sh
mount | column -t
```
#### Kill all processes for a given user or program
Kill several processes with a single command
```sh
pkill -9 cmd
pkill -9 -u user cmd
```
#### Repeat a command until it succeeds
```bash
while true
do
  cmd && break
done
```
#### Find who is using the most disk space
```sh
sudo du -s /home | sort -n
``` 
#### Find the files that are using the most disk space
```sh
find / -type f -exec wc -c {} \; | sort -n
```
#### List processes, sorted by memory usage
```sh
ps aux | sort -nk 4 # Processes consuming the most memory will be at the bottom
ps aux | sort -nk 4 | tail -5 # Five worst offenders
```
#### List processes, sorted by CPU usage
Processes consuming the most CPU will be at the bottom
```sh
ps aux | sort -nk 3
```
#### Quickly tell if you are on a 32- or 64-bit system
Returns '32' or '64'
```sh
getconf LONG_BIT
```
#### Generate a random password
Use `openssl` to generate a random password
```sh
openssl rand -base64 48 | cut -c1-$LENGTH
```
```sh
# .bashrc
gpw () { 
  openssl rand -base64 48 | cut -c1-${1}
}
```
#### Quickly make a backup of a file using brace expansion
Brace expansion allows creation of multiple command-line args from a single one 
```sh
cp file{,.bak} # equivalent to `cp file file.bak`
```
#### Quickly create multiple directories using brace expansion
`mkdir -p` creates parent directories if they don't exist
```sh
mkdir -p ~/my-app/{bin,lib,log}
```
#### Quickly change a file's extension using brace expansion
```sh
mv file{.old,.new}
```
#### Create backups of files by date with ease using brace expansion
```sh
alias d='date +%F'  # Using format "YYYY-MM-DD"
cp file{,.$(d)}     # Append date to end of filename of copy using new alias
cmd > file          # Overwrite the contents of a file
``` 
#### Empty a file that is being written to
If a process has a file open it will continue to write to the file if you try to delete it naively. This way the file is truncated and applications can continue writing to it.
```sh
> file
cat /dev/null > file
```
`cmd >> file`
#### View tail of file in realtime
```sh
tail -f file
```
#### Watch multiple log files at the same time
`multitail` is not available on BSD
```sh
multitail files
``` 
`find . -type d -empty -delete` : `-type d` fine empty directories and delete them
#### Find files in a directory containing {string}
`-r` recursive; `-l` list files that match
```sh
grep -rl string a
```
#### Display a recursive file listing
```sh
find . -type f -ls
```
`-d` see only directories
```sh
tree -d
```
`-L` limit depth to {n}
```sh
tree -L n
```
#### Replace a string in multiple files
```sh
find /path -type f -exec sed -i.bak
```
#### Extract the nth line from a file 
```sh
awk 'NR==N'
```
#### Convert text files from Windows format to Linux format and vice-versa
```sh
dos2unix
unix2dos
```
#### Change to the previous working directory
```sh
cd -
```
#### Reset your terminal emulator display
```sh
reset
```
#### Search Wikipedia from the Command-line
DNS returns Wikipedia article summaries as TXT records
```sh
dig +short txt <string>.wp.dg.cx
host -t txt <string>.wp.dg.cx
```
#### Make non-interactive shell sessions behave the same as interactive sessions
Make **.bash_profile** point to **.bashrc** so that non-interactive sessions (like SSH) behave the same as interactive sessions (login)
```sh
if [ -f ~/.bashrc ]; then source ~/.bashrc; fi
```
#### Text to speech
Not available on BSD
```sh
espeak -f file
echo text | espeak
```
#### Display the current date and time in a different time zone
`TZ` environment variable specifies timezone
```sh
TZ=<TIMEZONE> date
TZ=MST date
```
#### Display a calendar at the command-line
```sh
cal
cal MM YYYY
cal YYYY
```
#### Extract a tar archive to a different directory
```sh
tar archive -C /path/to/directory
tar xf archive -C /path/to/directory
```
#### Transform the directory structure of a tar file when extarcting it
Where {n} is a number that represents the level of the top directory from which to extract
```sh
tar xf archive --strip-components=n
```
#### Use a spreadsheet from the command-line
Not available on BSD
```sh
sc
```
#### Stopwatch
Will stop when you press enter, displaying how much time elapsed
```sh
time read
```
#### Repeat a command at regular intervals and watch its changing output
Execute {cmd} at periods of {n} seconds, watching its output
```sh
watch cmd -n n
```
#### Execute a command at a given time
```sh
echo "cmd" | at time
```
```sh
at -f file time
```
#### Share your screen session with another user
```sh
screen -x user/session
```
#### Execute an unaliased version of an aliased command
If {cmd} is a command as well as an alias, use the backslash to run it as the original command
```
\cmd
```
#### Save the output of a command as an image
`convert` command is from ImageMagick software suite
```
cmd | convert label:@- image.png
```
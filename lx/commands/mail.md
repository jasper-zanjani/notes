\#  | Commands sorted alphabetically
:---| :---
M   | `mailmerge` `mailq` `mailstats` `msmtp`
P   | `postfix` `postqueue` `postsuper`
Q   | `qmail`
S   | `sendmail` `ssmtp`

### `mail`
**Mail User Agent (MUA)** which accepts interactive input using the `&` prompt
Check email of `$USER`
```sh
mail -u $USER
```
Send email to `$USER`
```sh
mail $USER
```
Send email from the command-line
Send email interactively
```sh
mail $ADDRESS
```
Send message via pipe 
```sh
echo 'message' | mail -s 'subject' recipient@domain.com
```
Send an email attachment from the command-line
```sh
mail -a /path/to/attachment
```
Send message via pipe
```sh
echo 'message' | mail -s 'subject' -a /path/to/attachment
```

### `mailmerge`
Mailmerge is a command-line Python program that provides a powerful way to send many customized emails by using Jinja2 templating. It is available from Fedora's repositories through `dnf` and is also available from PyPI. [[ref](https://opensource.com/article/19/8/sending-custom-emails-python "opensource.com - Sending custom emails with Python")]

Configuration file            | Description
:---                          | :---
$HOME/mailmerge_server.conf   | SMTP host configuration details
$HOME/mailmerge_database.csv  | custom data for each email, including email addresses of recipients. The email address to be used as test recipient (i.e. the user) is the first entry by convention.
$HOME/mailmerge_template.txt  | email's text with placeholder fields that will be replaced using data from mailmerge_database.csv

Review message to be sent to first recipient
This will display the message addressed to the first address specified in the recipient database in the terminal
```sh
mailmerge
```
Review every message to be sent
```sh
mailmerge --no-limit
```
Send test message to first recipient
```sh
mailmerge --no-dry-run
```
Send all emails
```sh
mailmerge --no-dry-run --no-limit
```

### `mailq`
Display the current mail queue on a Postfix server

### `mailstats`
Gather and display statistics about mail processed on a server running [ `sendmail` ](#sendmail)

### `msmtp`
[^][51]

~/.msmtprc

### `postqueue`
Cause mail queue to be processed on a Postfix server
```sh
postqueue -f
```
### `postsuper`
Delete all of the messages from the queue on a postfix server
```sh
postsuper -d
```

### `postfix`
Designed to replace Sendmail. 
- multiple processes with no particular parent/child relationship
Receives mail by two methods:
1. Local mail (sendmail)
2. Internet mail (SMTP)
Before mail is queued for delivery, it goes through a cleanup daemon, which can be configured to do header and body inspection using regex
`Qmgr` is the heart of postfix mail delivery; it maintains an active queue, which attempts delivery. It delivers mail using three methods:
1. Local inboxes
2. Internet (SMTP)
3. Piped to programs

### `qmail`
Mail Transfer Agent (MTA) designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". Its various modular subcomponents run independently and are mutually untrustful. It uses SMTP to exchange messages with other MTAs. It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. Deprecated and removed from Arch repos in 2005. [[27](sources.md)]

### `sendmail`
Mail daemon once the de facto standard for accepting and redirecting mail on Linux distributions, long ago fallen into disuse. It was infamous for its difficulty to set up, with roots in ARPANET itself. [^][Eckert]

### `ssmtp`
Installable client program [[25](sources.md)]

Configuration file                            | Description
:---                                          | :---
[/etc/ssmtp/ssmtp.conf](configs.md#etcssmtpssmtpconf) | Configuration file

Send {msg} to {recipient} from {user} at {host} using password {pw}
```sh
ssmtp -au recipient -ap pw user@host < msg
```
### `pine`
"Program for Internet news and email", a popular [MUA](# "\"mail user agent\", program that allows a user to view mail, such as mutt, pine, printmail, elm, mail, Thunderbird, Evolution, and Eudora") during the 1990s which has since been superceded by Alpine.

[pine]: ../lx/commands/mail.md#pine "\"Program for Internet news and email\", popular MUA during the 1990s which has since been replaced by Alpine."
[Eckert]: # "Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012."
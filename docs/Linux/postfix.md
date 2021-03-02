# postfix

Designed to replace Sendmail. 

- multiple processes with no particular parent/child relationship

Receives mail by two methods:

1. Local mail (sendmail)
2. Internet mail (SMTP)

Before mail is queued for delivery, it goes through a cleanup daemon, which can be configured to do header and body inspection using regex
`Qmgr` is the heart of postfix mail delivery; it maintains an active queue, which attempts delivery. 
It delivers mail using three methods:

1. Local inboxes
2. Internet (SMTP)
3. Piped to programs

### /etc/postfix/main.cf

Set e-mail domain name [Eckert][Eckert]
```cfg
mydomain = sample.com
```
Set local access to domain name [Eckert][Eckert]
```cfg
myorigin = $mydomain
```
Configure postfix to listen for email on all interfaces [Eckert][Eckert]
```cfg
inet_interfaces = all
```
Configure destination domain for email [Eckert][Eckert]
```cfg
mydestination = $myhostname, localhost.$mydomain, localhost, $mydomain
```
Trust email from computers on the local network [Eckert][Eckert]
```cfg
mynetworks_style = class
```

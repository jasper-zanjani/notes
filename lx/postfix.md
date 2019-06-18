### postfix

multiple processes with no particular parent/child relationship

Receives mail by two methods:
  1. Local mail (sendmail)
  2. Internet mail (SMTP)


Before mail is queued for delivery, it goes through a cleanup daemon, which can be configured to do header and body inspection using regex
`Qmgr` is the heart of postfix mail delivery; it maintains an active queue, which attempts delivery. 

It delivers mail using three methods:
  1. Local inboxes
  2. Internet (SMTP)
  3. Piped to programs

### Sources
  - "Linux Mail Server Postfix Architecture" [YouTube](https://youtu.be/qhA8HuJBa64)

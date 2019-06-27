# Linux Email utilities and services

File | Description
:--- | :---
/etc/aliases | forwarding to more than one address requires entries here
$HOME/.forward | forwarding to only one address

Command     | Effect
:---        | :---
`mailq`     | prints summary of mail messages queued for future delivery
`mail`      | Mail User Agent (MUA) which accepts interactive input using the `&` prompt
`postfix`   | Designed to replace Sendmail. 
`qmail`     | Mail Transfer Agent (MTA) designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". Its various modular subcomponents run independently and are mutually untrustful. It uses SMTP to exchange messages with other MTAs. It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. Deprecated and removed from Arch repos in 2005.
`Sendmail`  | Mail daemon once the de facto standard for accepting and redirecting mail on Linux distributions, long ago fallen into disuse. It was infamous for its difficulty to set up, with roots in ARPANET itself.

## postfix
- multiple processes with no particular parent/child relationship
Receives mail by two methods:
  1. Local mail (sendmail)
  2. Internet mail (SMTP)
Before mail is queued for delivery, it goes through a cleanup daemon, which can be configured to do header and body inspection using regex
`Qmgr` is the heart of postfix mail delivery; it maintains an active queue, which attempts delivery. It delivers mail using three methods:
  1. Local inboxes
  2. Internet (SMTP)
  3. Piped to programs

## SSMTP
Installable client program

Syntax | Effect or description
:---   | :---
`ssmtp -au recipient -ap pw user@host < msg` | send {msg} to {recipient} from {user} at {host} using password {pw}

#### Configuration
File | Description
:--- | :---
/etc/ssmtp/ssmtp.conf | Configuration file

```ini
mailhub=smtp.gmail.com:587
UseTLS=YES
UseSTARTTLS=YES
```

## Sources
  - "Linux Mail Server Postfix Architecture" [YouTube](https://youtu.be/qhA8HuJBa64)
  - "Qmail deprecation" [archlinux.org](https://www.archlinux.org/news/qmail-deprecation/)
  - "Send Emails From Linux Terminal Using SSMTP". [linuxhandbook.com](https://linuxhandbook.com/linux-send-email-ssmtp/)

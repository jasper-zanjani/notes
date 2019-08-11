# Mailmerge
Mailmerge is a command-line Python program that provides a powerful way to send many customized emails by using Jinja2 templating. It is available from Fedora's repositories through `dnf` and is also available from PyPI.
## Configuration files
  - **mailmerge_server.conf**: SMTP host configuration details
  - **mailmerge_database.csv**: custom data for each email, including email addresses of recipients. The email address to be used as test recipient (i.e. the user) is the first entry by convention.
  - **mailmerge_template.txt**: email's text with placeholder fields that will be replaced using data from mailmerge_database.csv
## Command-line usage
#### Review message to be sent to first recipient
This will display the message addressed to the first address specified in the recipient database in the terminal
```sh
mailmerge
```
#### Review every message to be sent
```sh
mailmerge --no-limit
```
#### Send test message to first recipient
```sh
mailmerge --no-dry-run
```
#### Send all emails
```sh
mailmerge --no-dry-run --no-limit
```
## Sources
  - "Sending custom emails with Python". [Pocket](https://app.getpocket.com/read/2685164877) from[opensource.com](https://opensource.com/article/19/8/sending-custom-emails-python)
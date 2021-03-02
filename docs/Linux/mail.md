### mail
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
# CLI conventions for shell scripts

## Validating arguments
`if [ $# != 2 ]; then echo "Usage: manuf.sh field file"; exit 1; fi`
: (PGL:548)
`[ -z "$1" ] && echo "Give either a pdf file or a DOI as an argument && exit`
: [Luke Smith](https://youtu.be/ksAfmJfdub0) 

## Looping based on user input
```bash
read -p "Backup another server? (y/n)" -n 1
["$BACKUP_AGAIN"="y"] || break
```
: placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate (CLKF)

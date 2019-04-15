# CLI conventions for shell scripts

## Validating arguments
`if [ $# != 2 ]; then echo "Usage: manuf.sh field file"; exit 1; fi`
: (PGL:548)
`[ -z "$1" ] && echo "Give either a pdf file or a DOI as an argument && exit`
: [Luke Smith](https://youtu.be/ksAfmJfdub0) 

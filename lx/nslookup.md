### nslookup

Syntax | Effect
:--- | :---
`nslookup url` | get IP address of a website
`nslookup -type=ns url` | get only nameservers
`nslookup -type=mx url` | get only MX records
`nslookup -type=soa url` | get Start of Authority (SOA) record
`nslookup -type=any url` | display all available records
`nslookup ipaddress` | perform reverse DNS lookup on <ipaddress>
`nslookup -port=portno url` | specify port <portno> in the lookup

### Sources
  - "nslookup Command: 7 Practical Examples" [linuxhandbook.com](https://linuxhandbook.com/nslookup-command/)

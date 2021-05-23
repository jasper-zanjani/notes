Perform a DNS lookup in an interactive shell with cleaner output than **dig**. Enter a domain name and you get output in two sections. 
Retrieve IP address of {host}
```sh
nslookup host
```
Get IP address of a website
```
nslookup url
```
Get only nameservers
```
nslookup -type=ns url
```
Get only MX records
```
nslookup -type=mx url
```
Get Start of Authority (SOA) record
```
nslookup -type=soa url
```
Display all available records
```
nslookup -type=any url
```
Perform reverse DNS lookup on {ipaddress}
```
nslookup ipaddress
```
Specify port {portno} in the lookup
```
nslookup -port=portno url
```
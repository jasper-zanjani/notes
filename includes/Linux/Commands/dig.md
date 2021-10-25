#### dig
:   
    DNS lookup tool that returns the text of the actual response from the DNS server, useful when troubleshooting a DNS issue (cf. `nslookup`)

    Nameserver
    ```
    dig example.com NS
    ```
    Mail server
    ```
    dig example.com MX
    ```
    Perform a reverse DNS lookup on an IP address
    ```sh
    dig -x 8.8.8.8
    ```
    Specify an alternate DNS server to query
    ```sh
    dig @8.8.8.8 example.com
    ```
    Find authoritative nameservers for the zone and display SOA records
    ```sh
    dig +nsearch example.com
    ```
    Lookup the IP associated with a domain name
    ```sh
    dig +short example.com
    ```
    Lookup the mail server IP associated with a domain name
    ```sh
    dig +short example.com MX example.com MX
    ```
    Perform iterative queries and display the entire trace path to resolve a domain name
    ```sh
    dig +trace example.com
    ```
    Get all types of records for a given domain name
    ```sh
    dig example.com ANY
    ```
    Display Start of Authority information for a domain
    ```sh
    dig example.com soa
    ```
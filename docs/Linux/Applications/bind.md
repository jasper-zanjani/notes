# BIND

```sh
apt install bind9 bind9-utils bind9-dnsutils -y
```

Set BIND to IPv4 mode in the service parameters file:

``` ini title="/etc/default/bind9"
OPTIONS="-4 -u bind"
```

BIND configs have a unique syntax that make heavy use of the semicolon.
The main config is at **/etc/named.conf** on Arch and RHEL systems and at **/etc/bind/named.conf** on Ubuntu.

A **DNS zone** is a database with resource records for a specific sub-tree in the domain space.

A DNS zone requires a [**start of authority (SOA)** record](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/9/html/managing_networking_infrastructure_services/assembly_setting-up-and-configuring-a-bind-dns-server_networking-infrastructure-services).
For readability, admins typically break the record apart into lines with comments describing each field following a semicolon.

``` title="Representative SOA record"
@ IN SOA ns1.example.com. hostmaster.example.com. (
                          2022070601 ; serial number
                          1d         ; refresh period
                          3h         ; retry period
                          3d         ; expire time
                          3h )       ; minimum TTL
```

Allow recursive queries from trusted clients

``` title="/etc/bind/named.conf.options"
acl "trusted" {
    10.128.10.11;    # ns1 - can be set to localhost
    10.128.20.12;    # ns2
    10.128.100.101;  # host1
    10.128.200.102;  # host2
};
```

Allow recursion

``` title="/etc/bind/named.conf.options" hl_lines="4-8"
options {
    directory "/var/cache/bind";
    
    recursion yes;
    allow-recursion {trusted; };
    listen-on { 0.0.0.0; };
    allow-transfer { none; };
    forwarders { 192.168.1.1; };
};
```

Now **zone files** can be specified in **named.conf.local**. An additional zone and zone file must be specified for every private subnet.

``` title="/etc/bind/named.conf.local"
zone "mydns" {
        type master;
        file "/etc/bind/zones/db.mydns";
}
```

The actual zone files can be copied from **/etc/bind/db.local** and edited manually.

``` title="/etc/bind/zones/db.mydns"

```
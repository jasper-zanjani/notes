<!--
On the first ban, f2b creates a new chain named **f2b-name** where "name" is the name of the jail, as defined in the config.

```ini title="/etc/fail2ban/action.d/iptables.conf"
actionstart = <iptables> -N f2b-<name>
```

This chain becomes the target of banned IPs, which are somehow added (although I don't know how).
-->


Fail2ban is an intrusion prevention framework written in Python and that runs as a service.
It can be installed from most distributions' repos.

The **jail** is a key concept in f2b that couples **filters** and **actions** definitions.


Fail2ban is configured through .ini-format configs found in **/etc/fail2ban**.
It is recommended not to edit the default configs ending in .config but rather to create a custom config called **jail.local** which will be automatically loaded by the service.

```ini title="Example jail"
[sshd]
enabled=true
port=ssh
filter=sshd
logpath=/var/log/auth.log
maxretry=0
findtime=300
bantime=3600
```

Failed logins can be checked by running **lastb**, and connections are also logged to SystemD.
```sh
journalctl -ru sshd
```

```sh
# Display banned IPs
fail2ban-client banned

# Manually ban an IP
fail2ban-client set sshd banip $IPADDRESS

# Manually unban an IP
fail2ban-client unban $IPADDRESS
```

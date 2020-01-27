# Hands-On Powershell for Active Directory

#### DC configuration
```powershell
New-NetIPAddress 10.0.0.1 -InterfaceAlias "Ethernet" -PrefixLength 24
Set-DnsClientServerAddress -InterfaceAlias "Ethernet" -ServerAddresses 127.0.0.1
Rename-Computer DC
Restart-Computer
```
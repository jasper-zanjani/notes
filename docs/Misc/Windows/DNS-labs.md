## Configuring DNS servers
| Hostname | IP Address  |
| :---     | :---        |
| PLABDC01 | 192.168.0.1 |
| PLABDM01 | 192.168.0.2 |
| PLABSA01 | 192.168.0.4 |

1. Create a Domain Forest
  - Create a [new domain and forest](#new-ad-forest) on PLABSA01 named "PRACTICEIT.CO.UK".
  - Configure PLABDC01 to [forward](#forwarding) for the new domain, and PLABSA01 to forward for the old one.
  - [Create a new DNS zone](#create-new-zone)
2. Set up alternate DNS server
3. Configure DNS forwarders

#### New AD forest
Create a [new domain and forest](#new-ad-forest) on PLABSA01 named "PRACTICEIT.CO.UK"
```powershell
# PLABSA01
Add-WindowsFeature dns, ad-domain-services -IncludeManagementTools
$pw = ConvertTo-SecureString -Force -AsPlainText 'Passw0rd'
Install-ADDSForest -DomainName PRACTICEIT.CO.UK -SafeModeAdministratorPassword $pw
```
#### Forwarding
Forward DNS queries for the new domain to PLABSA01
```powershell
# PLABDC01
# Equivalent to `netsh interface ipv4 add dns Ethernet 192.168.0.4 index=2`
Set-DNSClientServerAddress -InterfaceAlias Ethernet -ServerAddresses ('192.168.0.1','192.168.0.4') 
Add-DnsServerConditionalForwarderZone -Name 'practiceit.co.uk' -MasterServers '192.168.0.4'
Add-DnsServerForwarder -IpAddress '192.168.0.4'
Test-NetConnection plabsa01.practiceit.co.uk
```
Forward DNS queries for the old domain to PLABDC01
```powershell
# PLABSA01
# Equivalent to `netsh interface ipv4 add dns Ethernet 192.168.0.1 index=2`
Set-DnsClientServerAddress -InterfaceIndex 13 -ServerAddresses ('127.0.0.1','192.168.0.1') 
Add-DnsServerConditionalForwarderZone -Name 'practicelabs.com' -MasterServers '192.168.0.1'
Test-NetConnection plabdc01.practicelabs.com
```
#### Create new zone
```powershell
# PLABDM01
Add-WindowsFeature dns -IncludeManagementTools
Add-DnsServerPrimaryZone -ZoneFile 'apac.practicelabs.com.dns' -ZoneName 'apac.practicelabs.com' -DynamicUpdate NonsecureAndSecure
```
Delegate to the new zone
```powershell
# PLABDC01
Add-DnsServerZoneDelegation -Name 'practicelabs.com' -ChildZoneName 'apac' -NameServer 'plabdm01.practicelabs.com' -IPAddress '192.168.0.2'
Add-DnsServerPrimaryZone -ZoneName PLTEST.com -ReplicationScope Domain
Add-DnsServerResourceRecordA -Name www -ZoneName pltest.com -IPv4Address 192.168.0.1

# Copying PowerShell commands from a script
Add-DnsServerClientSubnet -Name EMEA -IPv4Subnet '192.168.0.0/24'
Add-DnsServerClientSubnet -Name APAC -IPv4Subnet '192.168.1.0/24'
Add-DnsServerZoneScope -ZoneName "PLTEST.com" -Name "EMEAZoneScope"
Add-DnsServerZoneScope -ZoneName "PLTEST.com" -Name "APACZoneScope"
Add-DnsServerResourceRecord -A -Name www -ZoneName 'PLTEST.com' -IPv4Address '192.168.1.1' -ZoneScope APACZoneScope
Add-DnsServerResourceRecord -A -Name www -ZoneName 'PLTEST.com' -IPv4Address '192.168.0.1' -ZoneScope EMEAZoneScope
Add-DnsServerQueryResolutionPolicy -Name EMEAPolicy -Action ALLOW -ClientSubnet 'eq,EMEA' -ZoneScope 'EMEAZoneScope,1' -ZoneName 'PLTEST.com'
Add-DnsServerQueryResolutionPolicy -Name APACPolicy -Action ALLOW -ClientSubnet 'eq,APAC' -ZoneScope 'APACZoneScope,1' -ZoneName 'PLTEST.com'

# PLABWIN10
ipconfig /flushdns
nslookup www.pltest.com

# PLABDC01
Add-DnsServerQueryResolutionPolicy -Name Blocklist -Action IGNORE -Fqdn 'eq,*.pltest.com' -PassThru

# PLABWIN10
# Now the query does not work
nslookup www.pltest.com

# PLABDC01
Remove-DnsServerQueryResolutionPolicy -Name Blocklist -Confirm
```
#### Configuration
Configure DNS socket pool
```cmd
::PLABDC01
dnscmd /info /socketpoolsize
dnscmd /config /socketpoolsize 3500
net stop dns
net start dns
dnscmd /info /socketpoolsize
```
Manage DNS cache locking
```cmd
dnscmd /info /cachelockingpercent
dnscmd /config /cachelockingpercent 90
dnscmd /info /cachelockingpercent
net stop dns
net start dns
dnscmd /info /cachelockingpercent
```
Create a GlobalNames zone
```powershell
Set-DnsServerGlobalNameZone -AlwaysQueryServer $true
Add-DnsServerPrimaryZone -Name GlobalNames -ReplicationScope Forest
dnscmd . /config /enableglobalnamessupport 1
```
Create a resource record in the GlobalNames zone
```powershell
Add-DnsServerResourceRecordA -Name PLABDC01 -ZoneName GlobalNames -IPv4Address 192.168.0.1
```
Enable response rate limiting
```powershell
Get-DNSServerResponseRateLimiting
Set-DNSServerResponseRateLimiting -Mode Enable -Confirm
Get-DNSServerResponseRateLimiting # confirming
Add-DNSServerResponseRateLimitingExceptionList -Name Whitelist1 -Fqdn 'eq, *.practicelabs.com'
Set-DNSServerResponseRateLimiting -Mode Enable -Confirm
```
Manage DNS logging
```powershell
Add-WindowsFeature dns -IncludeManagementTools -ComputerName PLABDM01
Set-DnsServerDiagnostics -LogFilePath C:\dnslog.txt
# Some additional settings appear necessary in order to begin logging
```
Enable zone transfers
```powershell
Set-DnsServerPrimaryZone -SecureSecondaries TransferAnyServer
```
Create a secondary DNS zone
```powershell
# PLABDM01
Add-DnsServerSecondaryZone -ComputerNAme PLABDM01 -MasterServers 192.168.0.1 -ZoneName practicelabs.com -ZoneFile practicelabs.com.dns
```
Check DNS logs at text file and event viewer.
#### Manage DNS zones and resource records
Convert AD-integrated zone to file-based zone
```powershell
Get-DNSServerZone -ZoneName practicelabs.com | ConvertTo-DnsServerPrimaryZone -ZoneFile practicelabs.com.dns
```
Manually add an A record
```powershell
Add-Content -Path C:\Windows\System32\dns\practicelabs.com.dns -Value "PLABSVR   1200   A  192.168.0.105"
```
Re-integrate zone to AD
```powershell
ConvertTo-DnsServerPrimaryZone -ZoneName practicelabs.com -ReplicationScope Domain
```
Promote a new DC
```powershell
# PLABDM01
Add-WindowsFeature dns,ad-domain-services -IncludeManagementTools
Install-ADDSDomainController -Domain practicelabs.com
```
Create a secondary zone
```powershell
# PLABSA01
Add-WindowsFeature dns -IncludeManagementTools
Add-DnsServerSecondaryZone -ZoneName practicelabs.com -ZoneFile "practicelabs.com.dns" -MasterServers 192.168.0.1
```
Enable zone transfer from master
```powershell
# PLABDC01
Set-DnsServerPrimaryZone -Name practicelabs.com -SecureSecondaries TransferAnyServer
```
Manually initiate a zone transfer if needed
```powershell
# PLABSA01
Start-DnsServerZoneTransfer -ZoneName practicelabs.com
```
Remove secondary zone
```powershell
# PLABSA01
Remove-DnsServerZone -ZoneName practicelabs.com
Add-DnsServerStubZone -ZoneName practicelabs.com -ZoneFile practicelabs.com.dns -MasterServers 192.168.0.1
```
Create new resource records
```powershell
# PLABDC01
Add-DnsServerResourceRecord -A -Name plabsa05 -IPv4Address 192.168.0.50 -ZoneName practicelabs.com
Add-DnsServerResourceRecord -CName -Name plabdmsrv01 -ZoneName practicelabs.com -HostNameAlias plabdm01.practicelabs.com
Add-DnsServerResourceRecord -MX -Name "." -ZoneName practicelabs.com -MailExchange mobilemail.practicelabs.com -Preference 10
Add-DnsServerResourceRecord -A -Name mobilemail -IPv4Address 192.168.0.21 -ZoneName practicelabs.com
```

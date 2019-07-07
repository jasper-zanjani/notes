## Network-related cmdlets in PowerShell

## Firewall
Windows Firewall can be manipulated with `Get-NetFirewallRule` and `Set-NetFirewallRule`

#### Display all firewall rules
```powershell
Get-NetFirewallRule
```

#### Display active firewall rules for inbound connections
```powershell
Get-NetFirewallRule -Enabled True -Direction Inbound
```

#### Set a new firewall rule for incoming WinRM connections
```powershell
New-NetFirewallRule -DisplayName "WinRMHTTP" -Direction Inbound -LocalPort 5985 -Protocol TCP -Action Allow
```

#### Display programs associated with firewall rules
```powershell
Get-NetFirewallRule | %{$_.Name; $_ | Get-NetFirewallApplicationFilter}
```

#### Set firewall rule for COM+ Network Access (DCOM-In)
```powershell
Set-NetFirewallRule -name COMPlusNetworkAccess-DCOM-In -Enabled True
```

#### Set firewall rule for Remote Event Log Management (NP-In)
```powershell
Set-NetFirewallRule -name RemoteEventLogSvc-In-TCP -Enabled True
```

#### Set firewall rule for Remote Event Log Management (RPC)
```powershell
Set-NetFirewallRule -name RemoteEventLogSvc-NP-In-TCP -Enabled True
```

#### Set firewall rule for Remote Event Log Management (RPC-EPMAP)
```powershell
Set-NetFirewallRule -name RemoteEventLogSvc-RPCSS-TCP -Enabled True
```

#### List all WinRM listeners  
```powershell
winrm enumerate winrm/config/listener
```

#### Display WinRM configuration
```powershell
winrm get winrm/config
```

#### Install Remote Server Adminstration Tools for PowerShell
```powershell
Install-WindowsFeature -Name RSAT-ADDS -IncludeAllSubFeature
```


## Web requests 
`Invoke-WebRequest` is the main command used in the following tasks.

#### Download a file over HTTP/HTTPS
```powershell
Invoke-WebRequest -Uri http://example.com/path/to/file -OutFile \\path\to\local\file
```

#### Resume a partial download
```powershell
Invoke-WebRequest -Uri http://example.com/path/to/file -Resume -Outfile \\path\to\local\file
```

#### Transfer a file over FTP/SFTP
```powershell
Invoke-WebRequest ftp://ftp.example.com/file -Outfile C:\path\to\file -Credential ftpuseraccount
```

#### Resolve shortened URLs
```powershell
$Uri = 'short-url/extension' 
$Web = Invoke-WebRequest -Uri 
$Uri -UseBasicParsing  $Web.BaseResponse.ResponseUri.AbsoluteUri
```

#### Scrape links from a website
```powershell
(Invoke-WebRequest -Uri "https://techrepublic.com").Links.Href
```

#### Request data from a website impersonating a browser
```powershell
Invoke-WebRequest -Uri http://microsoft.com -UserAgent ([Microsoft.PowerShell.Commands.PSUserAgent]::Chrome)
```

## Sources
  - "Managing the Windows Firewall with PowerShell". [4sysops](https://4sysops.com/archives/managing-the-windows-firewall-with-powershell/): 2018/05/14.
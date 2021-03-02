```powershell
# PLABDC01
Set-DHCPServerv4Scope -ScopeId '192.168.0.0' -Type Both -State Active
wdsutil.exe /initialize-server /remInst:"D:\RemoteInstall"
wdsutil.exe /enable-server
wdsutil.exe /start-server
```
Import install and boot images
```powershell
New-WDSInstallImageGroup -Name Win10-DVDImage
Get-WindowsImage -ImagePath \\plabdm01\win10\sources\install.wim
Import-WDSInstallImage -Path \\plabdm01\win10\sources\install.wim -ImageGroup Win10-DVDImage -ImageName 'Windows 10 Enterprise'
Import-WdsBootImage -Path \\plabdm01\win10\sources\boot.wim -NewImageName 'Microsoft Windows Setup (x64)' -NewDescription 'Microsoft Windows Setup (x64)'
```
Configure server to accept clients
```cmd
::wdsutil.exe /start-transportserver
wdsutil.exe /set-server /answerclients:all
wdsutil.exe /set-server /authorize:yes
wdsutil.exe /set-server /NewMachineNamingPolicy:PLABSA%#03
```
Configure VM to boot from PXE
```powershell
# PLABDM01
Rename-VMSwitch Intel* External
Add-VMNetworkAdapter -IsLegacy $true -VMName PLABSA02 -SwitchName External
Remove-VMAssignableDevice -VMName PLABSA02
Start-VM PLABSA02
# While connected to VM, when prompted to "press F12 for network service boot", press F12.
```

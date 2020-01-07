# Introduction to Microsoft Windows Server 2016
Prepare `$VMName` to turn on nested virtualization [10]
```powershell
Set-VMProcessor -VMName $VMName -ExposeVirtualizationExtensions $true
```
Turn on MAC spoofing on the host Hyper-V switch [10]
```powershell
Get-VMNetworkAdapter -VMName VMName | Set-VMNetworkAdapter -MacAddressSpoofing On
```
Turn on NAT on the nested Hyper-V VM
```powershell
New-VMSwitch -name VMNAT -SwitchType Internal
New-NetNAT -Name LocalNAT -InternalIPInterfaceAddressPrefix "192.168.100.0/24"
```
Assign an IP address to the new internal adapter
```powershell
Get-NetAdapter "vEthernet (VMNat)" | New-NetIPAddress -IPAddress 192.168.100.1 -AddressFamily IPv4 -PrefixLength 24
```
Assign an IP address and gateway for each nested guest VM
```powershell
Get-NetAdapter "Ethernet" | New-NetIPAddress -IPAddress 192.168.100.2 -DefaultGateway 192.168.100.1 -AddressFamily IPv4 -PrefixLength 24
```
Enable secure boot on Generation 2 Linux VMs [11]
```powershell
Set-VMFirmware vmname -SecureBootTemplate MicrosoftUEFICertificateAuthority
```
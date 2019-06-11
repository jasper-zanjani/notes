# Introduction to Microsoft Windows Server 2016

## Introduction

Term                            | Definition                              | Source
---                             | ---                                     | ---
Storage-Area Network (SAN)      | 
Network-Attached Storage (NAS)  |
Storage Spaces Direct           | Windows Server 2016 feature that allows servers with internal drives to build highly available and scalable software-defined storage  | IMWS: 54


## Software-defined datacenter

PowerShell Syntax                                                                                     | Effect  | Source
---                                                                                                   | ---     | ---
`Set-VMProcessor -VMName VMName -ExposeVirtualizationExtensions $true`                                | prepare <VMName> to turn on nested virtualization | IMWS: 10
`Get-VMNetworkAdapter -VMName VMName \| Set-VMNetworkAdapter -MacAddressSpoofing On`                  | turn on MAC spoofing on the host Hyper-V switch | IMWS: 10
`New-VMSwitch -name VMNAT -SwitchType Internal`, `New-NetNAT -Name LocalNAT -InternalIPInterfaceAddressPrefix "192.168.100.0/24"` | turn on NAT on the nested Hyper-V VM
`Get-NetAdapter "vEthernet (VMNat)" \| New-NetIPAddress -IPAddress 192.168.100.1 -AddressFamily IPv4 -PrefixLength 24` | assign an IP address to the new internal adapter
`get-netadapter "Ethernet" \| New-NetIPAddress -IPAddress 192.168.100.2 -DefaultGateway 192.168.100.1 -AddressFamily IPv4 -PrefixLength 24` | assign an IP address and gateway for each nested guest VM
`Set-VMFirmware vmname -SecureBootTemplate MicrosoftUEFICertificateAuthority`                         | enable secure boot on Generation 2 Linux VMs | IMWS: 11

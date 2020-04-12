[Zacker]: 70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."

# DSC
**Desired State Configuration (DSC)** Windows PowerShell feature that uses script files stored on a central server to apply, monitor, and maintain a specific configuration [[^][Zacker] 26]
- **Configuration scripts** scripts that are **idempotent** and contain **node blocks** specifying the names of target computers and **resource blocks** specifying property settings to be applied.
- **Resources** building blocks that specify settings or components and the values that the configuration script should assign to them
- **Local Configuration Manager (LCM)** engine running on the client system that receives configurations from the DSC server and applies them to the target computer <sup>[Zacker][Zacker]: 26</sup>

**Management Object Format (MOF)** file created for each computer specified in the `Node` block of a DSC script, as well as the associated file format <sup>[Zacker][Zacker]: 27</sup>

Refresh modes <sup>[Zacker][Zacker]: 27</sup>
- **Pull architecture** client computers' LCM creates a scheduled task to retrieve MOF file from a **Pull Server**, a SMB or IIS server with an Odata interface, set up with its own DSC configuration <sup>[Zacker][Zacker]: 27</sup>
- **Push architecture** configured on the server using the [`Start-DscConfiguration`](#start-dscconfiguration) cmdlet <sup>[Zacker][Zacker]: 27</sup>

Sample DSC configuration <sup>[Zacker][Zacker]: 27-8</sup>
```powershell
Configuration DnsClient                         # Specifying the name of the configuration
{
  Import-DscResource -ModuleName "xNetworking"  # Load specified module
  Node ("ServerA","ServerB")                    # Specify target configures
  {
    xDnsServerAddress DnsServer                 # Specify resource in the module to be configured
    {
      Address=10.0.0.1                          # DNS server address
      AddressFamily="Ipv4"                      # IP version of DNS server address
      InterfaceAlias="Ethernet"                 # Network adapter to be configured
}}}
```

Syntax           | Effect
:---             | :---
`Configuration`  | precedes title of script, at top (e.g. `Configuration ContosoSimple`)
`Ensure`         | property within `WindowsFeature` that can be set to `Present` or `Absent` (e.g. `Ensure = "Present"`)
`WindowsFeature` | declares code block representing a DSC resource to be installed (e.g. `WindowsFeature IIS`)

[ConfigurationRepositoryWeb]: #configurationrepositoryweb '```&#10;ConfigurationRepositoryWeb&#10;```&#10;Specify an HTTP pull service for configurations.'
[ConfigurationRepositoryShare]: #configurationrepositoryshare '```&#10;ConfigurationRepositoryShare&#10;```&#10;Specify an SMB share for configurations.'
[ResourceRepositoryWeb]: #resourcerepositoryweb '```&#10;ResourceRepositoryWeb&#10;```&#10;Specify an HTTP pull service for modules.'
[ResourceRepositoryShare]: #resourcerepositoryshare '```&#10;ResourceRepositoryShare&#10;```&#10;Specify an SMB share for modules.'
[ReportServerWeb]: #reportserverweb '```&#10;ReportServerWeb&#10;```&#10;Specify an HTTP pull service to which reports are sent.'
[PartialConfiguration]: #partialconfiguration '```&#10;PartialConfiguration&#10;```&#10;Provide data to enable partial configurations.'

## Tasks
###### Install Telnet client
```powershell
Configuration InstallTelnetLocal { 
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  Node localhost {
    WindowsOptionalFeature InstallTelnet {
      Name = "Telnet-Client"
      Ensure = "Present"
}}}
```
###### Install WSL
```powershell
Configuration InstallWSLLocal { 
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  Node localhost   {
    WindowsOptionalFeature InstallWSL     {
      Name = "Microsoft-Windows-Subsystem-Linux"
      Ensure = "Present" 
}}}
```
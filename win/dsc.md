[Zacker]: 70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."

# DSC
**Desired State Configuration (DSC)** Windows PowerShell feature that uses script files stored on a central server to apply, monitor, and maintain a specific configuration [[^][Zacker] 26]
- **Configuration scripts** scripts that are **idempotent** and contain **node blocks** specifying the names of target computers and **resource blocks** specifying property settings to be applied.
- **Resources** building blocks that specify settings or components and the values that the configuration script should assign to them
- **Local Configuration Manager (LCM)** engine running on the client system that receives configurations from the DSC server and applies them to the target computer <sup>[Zacker][Zacker]: 26</sup>

**Management Object Format (MOF)** file created for each computer specified in the <code>Node</code> block of a DSC script, as well as the associated file format <sup>[Zacker][Zacker]: 27</sup>

Deployment of DSC configurations <sup>[Zacker][Zacker]: 27</sup>
- **Pull architecture** client computers' LCM creates a scheduled task to retrieve MOF file from a **Pull Server**, a SMB or IIS server with an Odata interface, set up with its own DSC configuration <sup>[Zacker][Zacker]: 27</sup>
- **Push architecture** configured on the server using the [`Start-DscConfiguration`](#start-dscconfiguration) cmdlet <sup>[Zacker][Zacker]: 27</sup>

Sample DSC configuration <sup>[Zacker][Zacker]: 27-8</sup>
- `Configuration` specifies name of the configuration
- `Import-DscResource` loads specified module
- `Node` specifies target configures
- `xDnsServerAddress` specifies resource in the module to be configured, i.e. `DnsServer`
- `Address` specifies DNS server address
- `AddressFamily` specifies IP version of the DNS address
- `InterfaceAlias` specifies network adapter to be configured

```powershell
Configuration DnsClient
{
  Import-DscResource -ModuleName "xNetworking"
  Node ("ServerA","ServerB")
  {
    xDnsServerAddress DnsServer
    {
      Address=10.0.0.1
      AddressFamily="Ipv4"
      InterfaceAlias="Ethernet"
}}}
```

Syntax           | Effect
:---             | :---
`Configuration`  | precedes title of script, at top (e.g. `Configuration ContosoSimple`)
`Ensure`         | property within `WindowsFeature` that can be set to `Present` or `Absent` (e.g. `Ensure = "Present"`)
`WindowsFeature` | declares code block representing a DSC resource to be installed (e.g. `WindowsFeature IIS`)

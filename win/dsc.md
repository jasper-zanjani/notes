[Zacker]: 70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."

# DSC
[DSC]: # 'Desired State Configuration (DSC)&#10;Windows PowerShell feature that uses script files stored on a central server to apply, monitor, and maintain a specific configuration&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 26'
[LCM]: # 'Local Configuration Manager (LCM)&#10;engine running on the client system that receives configurations from the DSC server and applies them to the target computer&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 26'

[LCM][LCM] has to be [configured](#set-lcm-to-push-mode "Set LCM to push mode") to accept Configurations of either refresh mode.





[ConfigurationRepositoryWeb]: #configurationrepositoryweb '```&#10;ConfigurationRepositoryWeb&#10;```&#10;Specify an HTTP pull service for configurations.'
[ConfigurationRepositoryShare]: #configurationrepositoryshare '```&#10;ConfigurationRepositoryShare&#10;```&#10;Specify an SMB share for configurations.'
[ResourceRepositoryWeb]: #resourcerepositoryweb '```&#10;ResourceRepositoryWeb&#10;```&#10;Specify an HTTP pull service for modules.'
[ResourceRepositoryShare]: #resourcerepositoryshare '```&#10;ResourceRepositoryShare&#10;```&#10;Specify an SMB share for modules.'
[ReportServerWeb]: #reportserverweb '```&#10;ReportServerWeb&#10;```&#10;Specify an HTTP pull service to which reports are sent.'
[PartialConfiguration]: #partialconfiguration '```&#10;PartialConfiguration&#10;```&#10;Provide data to enable partial configurations.'

## Tasks
###### Set LCM to push mode
```powershell
[DSCLocalConfigurationManager()]
Configuration LCMConfig {
  Node localhost {
    Settings {
      RefreshMode = 'Push'
}}}
```

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
# VMware

**vSphere** is a suite of core infrastructure solutions for managing and monitoring a virtual infrastructure. The term was coined in 2009 with the release of VMware Virtual Infrastructure 4.

**VMware vCenter Server** server is the management layer of multiple ESXi hosts, allowing clusters to be created and enabling features like vSphere HA and vSphere DRS. It comes as either a Windows application or a virtual appliance running on a stripped-down version of SUSE Linux.

vCenter includes the **Platform Services Controller (PSC)** which consolidates several previously separate components, such as the SSO, Inventory Service, and Certificate Management.
This can be installed on the same host as vCenter, or separately as either a Windows application or Linux appliance.




#### Processes

    - **hostd** ESXi host agent
    - **vpxa** vCenter agent

## PowerCLI

```powershell title="Setup"
Install-Module -Name VMware.PowerCLI # (1)
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser # (2)
Set-PowerCLIConfiguration -InvalidCertificateAction Fail -Scope AllUsers
```

1. If the Hyper-V module is installed, the **-AllowClobber** option must be provided.
2. Allow local scripts to be run, but not those downloaded from the web or email.


``` powershell title="Decommission servers"
Connect-VIServer -Server $viserver # (1)

$servers = Import-CSV $args[0]

foreach ($server in $servers) {
    $VM = Get-VM -Name $server.Name
    Stop-VM $VM -Confirm -ErrorAction SilentlyContinue
    New-TagAssignment -Entity $VM -Tag (Get-Tag -Name TPA_Decomm) # (3)
    Set-NetworkAdapter -NetworkAdapter (Get-NetworkAdapter -VM $VM) -StartConnected $false -Confirm
    Move-VM -VM $VM -Destination DECOMMISSION # (2)
}
```

1. [**Connect-VIServer**](https://developer.vmware.com/docs/powercli/latest/vmware.vimautomation.core/commands/connect-viserver/#Default) establishes a connection to a vCenter Server system, checking certificates according to the policy set by [**Set-PowerCLIConfiguration**](https://developer.vmware.com/docs/powercli/latest/vmware.vimautomation.core/commands/set-powercliconfiguration/#Default). 
The connection can be destroyed with [**Disconnect-VIServer**](https://developer.vmware.com/docs/powercli/latest/vmware.vimautomation.core/commands/disconnect-viserver/#Default)
2. If the destination folder is under a parent, then apparently the best that can be done is to retrieve the Folder object first, specifying the parent folder to **-Location**:
```powershell
Move-VM -VM $VM -Destination (Get-Folder Linux -Location PROD)
```
3. 
``` powershell title="Remove tag assignment"
Remove-TagAssignment (Get-TagAssignment -Entity $VM -Tag (Get-Tag -Name TPA_Decomm))
```
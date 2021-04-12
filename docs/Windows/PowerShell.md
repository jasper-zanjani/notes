# 🐚 PowerShell

## Control flow

=== "if"

    ```powershell
    if ($condition) 
    {
        # ...
    }
    ```

=== "switch"

    ```powershell
    switch ($reference) 
    {
        $value1 { ... }
        $value2 { ... }
    }
    ```

=== "while"

    ```powershell
    $Values = while ($true) 
    {
        (++$Tick)
        if ($Tick -gt 2) 
        { 
            break 
        } 
    } # => @(1,2,3)
    ```

=== "do while"

    ```powershell
    $Values = do 
    { 
        'Hello, world!' 
    } while ($false) # => @('Hello, world!')
    ```

Loops are implemented with `ForEach-Object`.

```powershell
1..5 | ForEach-Object {$_ + 2} # => @(3,4,5,6,7)
```

When values are stored in a variable at the end of a pipeline, it will create an array. `while` and `do while` loops are available, as well as `until` and `do until` loops which operate so long as their condition is **false**.

## Variables

Variables are accessed by prefixing the identifier with `$`.

- [**Automatic variables**][Automatic variable] (`PSVersionTable`, `$IsLinux`, etc) are PowerShell-specific.
- Windows environment variables are actually accessed through the **`Env`** virtual drive the syntax `$Env:VARIABLE`.

- [`APPDATA`][APPDATA]
- [`LOCALAPPDATA`][LOCALAPPDATA] 
- [`USERNAME`][USERNAME] 
- [`USERPROFILE`][USERPROFILE] 
- [`WINDIR`][WINDIR]

### Typing

Variables can be typed by preceding their identifier with the datatype in brackets
```powershell
[double]$Price
[int]$Quantity
[string]$Description
```

Compatible data can be **cast** or converted by simply specifying the type in an assignment, but when the data cannot be converted the interpreter will throw an error.

```powershell
$Number = [int]'04'
$FailedCast = [int]'Hello'
```

Filtering results can be done with 5 commands:

- `Where-Object` (aliased to `where` and `?`): the most commonly used such command
- `Select-Object` (aliased to `sc`ed to specify specific columns of information to be displayed
- `Select-String` (aliased to `sls`)
- `ForEach-Object` (aliased to `foreach` and `%`) There are two different ways to construct a `ForEach-Object` statement:
    1. **Script block**, within which the variable `$_` represents the current object
    2. **Operation statement**, more naturalistic, where you specify a property value or call a method.


### Hashtable


Build a **hash table** using literals or the `Add` method

=== "Literal"

    ```powershell
    $fruit = @{
        Apple = 'red'
        Orange = 'orange'
        Eggplant = 'purple'
    }
    ```

=== "Literal (inline)"

    ```powershell
    $fruit = @{ Apple = 'red'; Orange = 'orange'; Eggplant = 'purple' }
    ```

=== "Add"

    ```powershell
    $fruit = @{}
    $fruit.Add('Apple','red')
    $fruit.Add('Orange','orange')
    $fruit.Add('Kiwi','green')
    ```

Hashtable methods

=== "Add"

    ```powershell
    $fruit = @{}
    $fruit.Add('Apple','red')
    $fruit.Add('Orange','orange')
    $fruit.Add('Kiwi','green')
    ```

=== "Clone"

    ```powershell
    # Deep copy or "clone" of a hashtable.
    $fruitclone = $fruit.Clone()
    ```

=== "Keys"

    ```powershell
    $fruit.Keys # => @('Apple','Orange','Kiwi')
    ```

=== "Values"

    ```powershell
    $fruit.Values # => @('red','orange','green')
    ```

=== "Count"

    ```powershell
    $fruit.Count
    ```

=== "Remove"

    ```powershell
    $fruit.Remove('One')
    ```

Unlike Python, a hash table can be made ordered, changing its data type:

```powershell
$fruit = [ordered]@{ Apple = 'red'; Orange = 'orange'; Eggplant = 'purple' }
$fruit.GetType().Name # => OrderedDictionary
```


## Documentation

Single-line comments are preceded by `#` and block quotes are enclosed between `<#` and `#>`.
Such a block comment will be parsed by PowerShell when running `Get-Help`.

```powershell
<#
.SYNOPSIS
This script coordinates the process of creating new employees

.DESCRIPTION
This script creates new users in Active Directory...

.PARAMETER UserName
The official logon name for the user...

.PARAMETER HomeServer
The server name where the user's home folder will live...
#>

<#
.EXAMPLE
New-CorpEmployee -UserName John-Doe -HomeServer HOMESERVER1
This example creates a single new employee...
#>
```

## Functions

Functions are declared with the `function` keyword and the body in braces, following this syntax:

```powershell
function Verb-Noun
{
    # ...
}
```

**Positional parameters** can be referenced using the `$args` array, which contains all arguments passed to the function on invocation.

**Named parameters** can be declared in one of two ways. 

- Within the function body using the `param` keyword, followed by the name of the variable representing the parameter's value, enclosed in `$(...)`:
- Directly after the function name in parentheses, with each parameter separated by a comma.

The name of the variable becomes the named parameter used when invoking the function.
Default values for parameters can be specified by placing them within the parentheses.

Parameters can be made mandatory by preceding the parameter name with `[Parameter(Mandatory=$true)]`. 
Parameters can be static typed by preceding the parameter identifier with the data type in brackets.

=== "Positional parameter"

    ```powershell
    function Get-LargeFiles 
    {
        Get-ChildItem C:\Users\Michael\Documents |
            where {$_.Length -gt $args[0] and !$_PSIscontainer} |
            Sort-Object Length -Descending
    }
    ```

=== "Named parameter"

    ```powershell
    function Get-LargeFiles($Size) 
    {
        # param ($Size)
        Get-ChildItem C:\Users\Michael\Documents |
            where {$_.Length -gt $Size -and !$_.PSIsContainer} |
            Sort-Object Length -Descending
    }
    ```

=== "Using param"

    ```powershell
    function Get-LargeFiles 
    {
        param ($Size)
        Get-ChildItem C:\Users\Michael\Documents |
            where {$_.Length -gt $Size -and !$_.PSIsContainer} |
            Sort-Object Length -Descending
    }
    ```

=== "Default value"

    ```powershell
    function Get-LargeFiles 
    {
        param ($Size=2000)
        Get-ChildItem C:\Users\Michael\Documents |
            where {$_.Length -gt $Size -and !$_.PSIsContainer} |
            Sort-Object Length -Descending
    }
    ```

=== "Typed"

    ```powershell
    function Get-LargeFiles 
    {
        param ([int]$Size=2000)
        Get-ChildItem C:\Users\Michael\Documents |
            where {$_.Length -gt $Size -and !$_.PSIsContainer} |
            Sort-Object Length -Descending
    }
    ```

=== "Invocation"

    ```powershell
    Get-LargeFiles -Size 2000
    ```

**Switch parameters** are typed as a **`switch`** data type.
Boolean values can be explicitly set upon invocation using this syntax:

=== "Switch-Item"

    ```powershell
    function Switch-Item 
    {
        param ([switch]$on)
        if ($on) { "Switch on" }
        else { "Switch off" }
    }
    ```

=== "Invocation"

    ```powershell
    Switch-Item             # => Switch off
    Switch-Item -On         # => Switch on
    Switch-Item -On:$false  # => Switch off
    ```

Attach common parameters to a custom function by placing the `[CmdletBinding()]` within the body of a function. 
This allows use of options like `-Verbose` or `-Debug` with custom functions.
Now, using `Write-Verbose` and `Write-Debug` within the function body serve the dual purpose of outputting additional information at the time of execution, when needed, as well as documentation.


## Remote administration

Powershell [remoting][remoting] can be done [**explicitly**][explicit remoting] or [**implicitly**][implicit remoting].
Remoting relies on [WinRM][WinRM], which is Microsoft's implementation of WSMAN.

- Explicit remoting is also 1-to-1 remoting, where an interactive Powershell prompt is brought up on a remote computer.
- One-to-many or fan-out remoting is possible with implicit remoting, where a command is transmitted to many computers.

## Testing

[**Pester**](https://pester.dev/docs/quick-start) tests are organized in a hierarchy of blocks and run with [`Invoke-Pester`](https://www.red-gate.com/simple-talk/sysadmin/powershell/introduction-to-testing-your-powershell-code-with-pester/):

```powershell
Describe
{
  Context # optional
  {
    It
    {
      Should # assertion statements accept a value passed in via pipe and **must** be called within a `Describe` block
    }
  }
}
```

```powershell
New-Fixture deploy Foo

function Foo 
{
  # ...
}

Describe 'Foo' 
{
    $true | Should -Be $true 
}
```

The block in braces is actually an argument pass to the `-Fixture` parameter.

```powershell
Describe "Best airports in the USA" -Fixture 
{
    It -Name "RDU is one of the best airports" -Test 
    {
        $Output = Get-Airport -City "Raleigh"
        $Output | Should -BeOfType System.Collections.Hashtable
    }
}
```

## Tasks

Display computer name

=== "Cmdlet"

    ```powershell
    Get-ComputerInfo -Property CsName
    ```

=== "Alias"

    ```powershell
    gin.CsName
    ```

=== "$Env"

    ```powershell
    $Env:computername
    ```

=== "Command prompt"

    ```
    hostname
    ```

Generate a random password 20 characters long ([src](https://adamtheautomator.com/powershell-random-password/))

```powershell
Add-Type -AssemblyName 'System.Web'
[System.Web.Security.Membership]::GeneratePassword(20, 3)
```

Store credential

=== "Interactive"

    ```powershell
    $cred = Get-Credential
    ```

=== "Cmdlet"

    ```powershell
    $pw = ConvertTo-SecureString "Password" -AsPlainText -Force
    $cred = New-Object System.Management.Automation.PSCredential ("FullerP", $pw)
    ```

Create a new file in the current working directory named `filename`

```powershell
New-Item -ItemType File -Name filename
```

Append `content` to `file`

```powershell
Add-Content C:\path\to\file $content
```


#### New domain controller
[Jones][Jones]
```powershell
Install-WindowsFeature AD-Domain-Services,DHCP -IncludeManagementTools
Install-ADDSForest -DomainName corp.packtlab.com
Add-DhcpServerv4Scope -Name "PacktLabNet" -StartRange 10.0.0.50 -EndRange 10.0.0.100 -SubnetMask 255.255.255.0
Set-DhcpServerv4OptionValue -DnsDomain corp.packtlab.com
Add-DhcpServerInDC -DnsName dc.corp.packtlab.com
New-AdUser -SamAccountName SysAdmin -AccountPassword (Read-Host "Set user password" -AsSecureString) -Name "SysAdmin" -Enabled $true -PasswordNeverExpires $true -ChangePasswordAtLogon $false
Add-ADPrincipalGroupMembership -Identity "CN=SysAdmin,CN=Users,DC=corp,DC=packtlab,DC=com","CN=Domain Admins,CN=Users,DC=corp,DC=packtlab,DC=com"
Get-ADPrincipalGroupMembership sysadmin
```

#### Text-to-speech
Initialize text-to-speech object [scriptinglibrary.com](https://www.scriptinglibrary.com/languages/powershell/powershell-text-to-speech/ "Powershell: Text To Speech in 3 lines of code")
```powershell
Add-Type –AssemblyName System.Speech
$tts = New-Object –TypeName System.Speech.Synthesis.SpeechSynthesizer
$tts.Speak('Hello, World!')
```
List available voices
```powershell
Foreach ($voice in $SpeechSynthesizer.GetInstalledVoices()){
    $Voice.VoiceInfo | Select-Object Gender, Name, Culture, Description
}
```
Change voice
```powershell
$tts.SelectVoice("Microsoft Zira Desktop")
$tts.Speak('Hello, World!')
```
Set output to WAV file [thinkpowershell.com](https://thinkpowershell.com/create-cortana-audio-files-from-text-using-powershell/ "Create Cortana Audio Files From Text Using PowerShell")
```powershell
$WavFileOut = Join-Path -Path $env:USERPROFILE -ChildPath "Desktop\thinkpowershell-demo.wav"
$SpeechSynthesizer.SetOutputToWaveFile($WavFileOut)
```
#### VHDX file
[VHDX]: # 'VHDX&#10;Newer hard disk image format and file name extension.&#10;VHDX image files can be as large as 64 TB, and they also support 4 KB logical sector sizes to provide compatibility with 4 KB native drives. VHDX files can be read only by servers running Windows Server 2012 or later or workstations running Windows 8 or later.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 88'

Create a new 256 GB dynamic [VHDX][VHDX] file, mount it, initialize it, and create and format the partition [Zacker][Zacker]: 91
```powershell
New-VHD -Path C:\Data\disk1.vhdx -SizeBytes 256GB -Dynamic | 
Mount-VHD -Passthru |
Initialize-Disk -PassThru |
New-Partition -DriveLetter X -UseMaximumSize | 
Format-Volume -Filesystem ntfs -FileSystemLabel data1 -Confirm:$False -Force
```
#### Restart Wi-Fi adapter
```powershell
$adaptor = Get-WmiObject -Class Win32_NetworkAdapter | Where-Object {$_.Name -like "*Wireless*"}
$adaptor.Disable()
$adaptor.Enable()
```
#### Add a member to a group
```powershell
Add-ADGroupMember -Identity $group -Members $user1,$user2
```
#### Add a new local admin
```powershell
nlu ansible
Add-LocalGroupMember Administrators ansible
```
#### Configure secure remoting using a self-signed certificate
#### Create a virtual switch with SET enabled
[SET]: # 'Switch Embedded Teaming (SET)&#10;Hyper-V-only variation of NIC teaming that is implemented wholly within a virtual switch&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'

Create a virtual switch with [SET][SET] enabled. [Zacker][Zacker]: 254
```powershell
New-VMSwitch -Name SETSwitch -NetAdapterName "nic1","nic2" -EnableEmbeddedTeaming $true
```
Add new virtual network adapters to VMs
```powershell
Add-VMNetworkAdapter -VMName server1 -SwitchName setswitch -Name set1
```
Enable RDMA with [`Get-`][Get-NetAdapterRdma] and [`Enable-NetAdapterRdma`][Enable-NetAdapterRdma].
#### Implement nested virtualization
Both the physical host and the nested virtual host must be running Windows Server 2016, but before installing Hyper-V on the nested host, the following configurations must be made. [Zacker][Zacker]: 181

Provide nested host's processor with access to virtualization technology on the physical host
```powershell
Set-VMProcessor -VMName server1 -ExposeVirtualizationExtensions $true
```
Disable dynamic memory
```powershell
Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false
```
Configure 2 virtual processors
```powershell
Set-VMProcessor -VMName SVR01 -Count 2
```
Turn on MAC address spoofing
```powershell
Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On
```
#### Enable CredSSP
On the remote (managed) server [Zacker][Zacker]: 176
```powershell
Enable-PSRemoting
Enable-WSManCredSSP
```
Add the fully-qualified domain name of the Hyper-V server to be managed to the local system's WSMan trusted hosts list
```powershell
Set-Item WSMan:\localhost\client\trustedhosts -Value "hypervserver.domain.com"
```
Enable the use of CredSSP on the client 
```powershell
Enable-WSManCredSSP -Role client -DelegateComputer "hypervserver.domain.com"
```
#### Configure Server Core
Manually configure network interface, if a DHCP server is unavailable [Zacker][Zacker]: 19
```powershell
New-NetIPAddress 10.0.0.3 -InterfaceAlias "Ethernet' -PrefixLength 24
```
Configure the DNS server addresses for the adapter
```powershell
Set-DnsClientServerAddress -InterfaceIndex 6 -ServerAddresses ("192.168.0.1","192.168.0.2")
```
Rename the computer and join it to a domain
```powershell
Add-Computer -DomainName adatum.com -NewName Server8 -Credential adatum\administrator
```
#### Update Server Core image
```powershell
Mount-WindowsImage -ImagePath .\CoreServer.vhdx -Path .\MountDir -Index 1
Add-WindowsPackage -Path .\MountDir -PackagePath C:\ServicingPackages_cabs
Dismount-WindowsImage -Path .\MountDir -Save
```
#### Implement DDA
[DDA]: # 'Discrete Device Assignment (DDA)&#10;Hyper-V feature that enables passthrough of any PCI Express device, including GPUs or network adapters&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 212'

[Discrete Device Assignment (DDA)][DDA] begins with finding the Instance ID of the device needed to be passed through. [Zacker][Zacker]: 212
```powershell
Get-PnpDevice -PresentOnly
Disable-PnpDevice -InstanceId                 # Remove host-installed drivers
Get-PnpDeviceProperty                         # Provide `InstanceId` and `KeyName` values in order to get value for `LocationPath` parameter in next command
Dismount-VmHostAssignableDevice -LocationPath # Remove the device from host control
Add-VMAssignableDevice -VM -LocationPath      # Attach the device to a guest
```
#### Configure live migration
Live migration is possible between Hyper-V hosts that are not clustered, but they must be within the same (or trusted) domains. [Zacker][Zacker]: 306
```powershell
Enable-VMMigration
Set-VMMigrationNetwork 192.168.4.0
Set-VMHost -VirtualMachineMigrationAuthenticationType Kerberos
Set-VMHost -VirtualMachineMigrationPerformanceOption smbtransport
```
#### Configure S2D cluster
```powershell
New-Cluster -Name cluster1 -node server1,server2,server3,server4 -NoStorage
Enable-ClusterStorageSpacesDirect
```
#### Install Docker Enterprise
[Zacker][Zacker]: 266
```powershell
Install-Module -Name dockermsftprovider -repository psgallery -force
Install-Package -Name docker -ProviderName dockermsftprovider
```
#### Handle XML files
Find a sample XML file [here](https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ms762271(v=vs.85) "books.xml")

Assign the output of [`gc`][Get-Content] to a variable
```powershell
[xml]$xdoc = gc $xmlfile
```
The XML tree can be viewed in VS Code using the **XML Tools** extension.
The object itself can be treated as a first-class Powershell object using dot notation. [red-gate.com](https://www.red-gate.com/simple-talk/sysadmin/powershell/powershell-data-basics-xml/ "Powershell Data Basics: XML")
```powershell
$xdoc.catalog.book | Format-Table -Autosize
```
Arrays of elements can be accessed by their index
```powershell
$xdoc.catalog.book[0]
```
Nodes in the XML object can also be navigated using **XPath** notation with the `SelectNodes` and `SelectSingleNode` methods.
```powershell
$xdoc.SelectNodes('//author')
This produces the same output as the command above (in XPath nodes are 1-indexed).
```powershell
$xdoc.SelectSingleNode('//book[1]')
```
[`Select-Xml`][Select-Xml] wraps the returned XML node with additional metadata, including the pattern searched.
However, it can accept piped input.
```powershell
(Select-Xml -Xml $xdoc -Xpath '//book[1]').Node
($xml | Select-Xml -Xpath '//book[1]').Node
```
#### Update Server Core images
[MeasureUp Lab][pl:70-740]
```powershell
Mount-WindowsImage -ImagePath .\CoreServer.vhdx -Path .\MountDir -Index 1
Add-WindowsPackage -Path .\MountDir PackagePath C:\ServicingPackages_cabs
Dismount-WindowsImage -Path .\MountDir -Save
```
#### Pass-through disk
[Zacker][Zacker]: 226
```powershell
Set-Disk -Number 2 -IsOffline $true
Add-VMHardDiskDrive -VMName server1 -ControllerType scsi -DiskNumber 2
```
#### Site-aware failover cluster
Configure failover clusters for two offices [Zacker][Zacker]: 366
```powershell
New-ClusterFaultDomain -Name ny -Type site -Description "Primary" -Location "New York, NY"
New-ClusterFaultDomain -Name sf -Type site -Description "Secondary" -Location "San Francisco, CA"
Set-ClusterFaultDomain -Name node1 -Parent ny
Set-ClusterFaultDomain -Name node2 -Parent ny
Set-ClusterFaultDomain -Name node3 -Parent sf
Set-ClusterFaultDomain -Name node4 -Parent sf
```
#### Filter AD account information
```powershell
Get-aduser -filter {(SamAccountName -like "*CA0*")} -properties Displayname, SaMaccountName, Enabled, EmailAddress, proxyaddresses | 
Where {($_.EmailAddress -notlike "*@*")} | 
Where {($_.Enabled -eq $True)} | 
Select Displayname, SaMaccountName, Enabled, EmailAddress, @{L=’ProxyAddress_1'; E={$_.proxyaddresses[0]}}, @{L=’ProxyAddress_2'; E={$_.ProxyAddresses[1]}} | 
Export-csv .\usersnoemail2.csv -notypeinformation
```
#### Create VM with installation media
[Practice Lab][pl:70-740]
```powershell
New-VM PLABWIN102 1536mb 1 -SwitchName 'Private network 1' -NewVHDPath 'C:\Users\Public\Documents\Hyper-V\Virtual hard disks\PLABWIN102.vhdx' -NewVHDSizeBytes 127gb
Set-VMDvdDrive -VMName PLABWIN102 -Path C:\Users\Administrator.PRACTICELABS\Documents\Eval81.iso
```
#### Registry

Description | Affected key
---         | ---
Fix Windows Search bar [docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-keys?view=powershell-7) | HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search
Remove 3D Objects [howtogeek.com](https://www.howtogeek.com/331361/how-to-remove-the-3d-objects-folder-from-this-pc-on-windows-10/ "How to Remove “3D Objects” From This PC on Windows 10") | HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace
Display seconds in system clock [howtogeek.com](https://www.howtogeek.com/325096/how-to-make-windows-10s-taskbar-clock-display-seconds/ "How to Make Windows 10’s Taskbar Clock Display Seconds") | HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced
Disable Aero Shake [howtogeek.com](https://www.howtogeek.com/howto/windows-7/disable-aero-shake-in-windows-7/ "How to Stop Aero Shake from Minimizing Your Windows") | HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced

Remove **3D Objects** from **This PC** [howtogeek.com](https://www.howtogeek.com/331361/how-to-remove-the-3d-objects-folder-from-this-pc-on-windows-10/ "How to Remove “3D Objects” From This PC on Windows 10")
```powershell
Remove-Item 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace\{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}'
```
Add seconds to clock [howtogeek.com](https://www.howtogeek.com/325096/how-to-make-windows-10s-taskbar-clock-display-seconds/ "How to Make Windows 10’s Taskbar Clock Display Seconds")
```powershell
New-Item -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced -Name ShowSecondsInSystemClock -Value 1
Restart-Computer
```
```powershell
New-Item -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search -Name BingSearchEnabled -Value 0
New-Item -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search -Name CortanaConsent -Value 0
```
Safely combine related registry modifications using [`Start-Transaction`][Start-Transaction] and [`Complete-Transaction`][Complete-Transaction] [Holmes][Holmes]: 604
```powershell
Start-Transaction
New-Item TempKey -UseTransaction
Complete-Transaction
```
Remove User UAC for local users. [ref](https://www.wintips.org/fix-mmc-exe-this-app-has-been-blocked-for-your-protection/)
```powershell
Set-ItemProperty -Path HKLM:\Software\Microsoft\Windows\CurrentVersion\Policies\System -Name EnableLUA -Value 0
```
#### WinForms
[Pastebin](https://pastebin.com/v3KMc2ni)
```powershell
# Load required assemblies
[void] [System.Reflection.Assembly]::LoadWithPartialName("System.Windows.Forms")

# Drawing form and controls
$Form_HelloWorld = New-Object System.Windows.Forms.Form
  $Form_HelloWorld.Text = "Hello World"
  $Form_HelloWorld.Size = New-Object System.Drawing.Size(272,160)
  $Form_HelloWorld.FormBorderStyle = "FixedDialog"
  $Form_HelloWorld.TopMost = $true
  $Form_HelloWorld.MaximizeBox = $false
  $Form_HelloWorld.MinimizeBox = $false
  $Form_HelloWorld.ControlBox = $true
  $Form_HelloWorld.StartPosition = "CenterScreen"
  $Form_HelloWorld.Font = "Segoe UI"

# adding a label to my form
$label_HelloWorld = New-Object System.Windows.Forms.Label
  $label_HelloWorld.Location = New-Object System.Drawing.Size(8,8)
  $label_HelloWorld.Size = New-Object System.Drawing.Size(240,32)
  $label_HelloWorld.TextAlign = "MiddleCenter"
  $label_HelloWorld.Text = "Hello World"
  $Form_HelloWorld.Controls.Add($label_HelloWorld)

# add a button
$button_ClickMe = New-Object System.Windows.Forms.Button
  $button_ClickMe.Location = New-Object System.Drawing.Size(8,80)
  $button_ClickMe.Size = New-Object System.Drawing.Size(240,32)
  $button_ClickMe.TextAlign = "MiddleCenter"
  $button_ClickMe.Text = "Click Me!"
  $button_ClickMe.Add_Click({
    $button_ClickMe.Text = "You did click me!"
    Start-Process calc.exe
  })
  $Form_HelloWorld.Controls.Add($button_ClickMe)

# show form
$Form_HelloWorld.Add_Shown({$Form_HelloWorld.Activate()})
[void] $Form_HelloWorld.ShowDialog()
```
#### Modules
Create a new module by placing a .psm1 file in a directory of the same name
```
.\Starship\Starship.psm1
```
Functions defined within the module can be loaded with [`Import-Module`][Import-Module] (execution policy must allow this).
```powershell
ipmo .\Starship
```
To import classes, a different syntax must be used [source](https://info.sapien.com/index.php/scripting/scripting-classes/import-powershell-classes-from-modules)
```powershell
Using module .\Starship
```
#### Sample enumeration
[PowerShellMagazine](https://www.powershellmagazine.com/2013/01/18/pstip-get-a-random-item-from-an-enumeration/)
```powershell
Add-Type -AssemblyName System.Drawing
$count = [Enum]::GetValues([System.Drawing.KnownColor]).Count
[System.Drawing.KnownColor](Get-Random -Minimum 1 -Maximum $count)
```
#### Migrate a VM
```powershell
Enable-VMMigration
Set-VMMigrationNetwork 192.168.10.1
Set-VMHost -VirtualMachineMigrationAuthenticationType Kerberos
Set-VMHost -VirtualMachineMigrationPerformanceOption SMBTransport
```
#### Storage Spaces Direct
[MeasureUp][mu:70-740]
```powershell
New-Cluster -Name HC-CLU1 -Node node1, node2, node3, node4 -NoStorage
Enable-ClusterStorageSpacesDirect -CacheMode Disabled -AutoConfig:0 -SkipEligibilityChecks
New-StoragePool -StorageSubSystemFriendlyName *Cluster* -FriendlyName S2DPool -ProvisioningTypeDefault Fixed -PhysicalDisk (Get-PhysicalDisk | Where-Object -Property CanPool -eq $true)
$pool = Get-StoragePool S2DPool
New-StorageTier -StoragePoolUniqueID ($pool).UniqueID -FriendlyName Performance -MediaType HDD -ResiliencySettingName Mirror
New-StorageTier -StoragePoolUniqueID ($pool).UniqueID -FriendlyName Capacity -MediaType HDD -ResiliencySettingName Parity
```
The next step would be the creation of a new volume
```powershell
New-Volume -StoragePool $pool -FriendlyName SharedVol1 -FileSystem CSVFS_REFS -StorageTiersFriendlyNames Performance, Capacity -StorageTierSizes 2GB, 10GB
```
#### Scheduled task
Automatically run SSH server in WSL on system start
```powershell
$action = New-ScheduledTaskAction -Execute C:\WINDOWS\System32\bash.exe -Argument '-c sudo service ssh start'
$trigger = New-ScheduledTaskTrigger -AtLogon

Register-ScheduledTask -TaskName 'SSH server' -Trigger $trigger -Action $action
```
#### Network connection alert
Play a tone when network connection has been (re)-established.
```powershell
while ($true) {
  if ((Test-NetConnection 8.8.8.8 -WarningAction SilentlyContinue).PingSucceeded -eq $true) {
    [System.Console]::Beep(1000,100)
    break
  }
}
```
```powershell
while (Test-NetConnection 8.8.8.8 -WarningAction SilentlyContinue).PingSucceeded -eq $false)
{
  continue
}
```




[Automatic variable]: #automatic-variables 'Automatic variable&#10;Variables that store state information for PowerShell and are created and maintained by Powershell.'
[USERPROFILE]: #variables '```&#10;[PS] Write-Host $Env:USERPROFILE&#10;```&#10;Location of profile directory of current user (i.e. "C:\Users\jsmith")'
[USERNAME]: #variables '```&#10;[PS] Write-Host $Env:USERNAME&#10;```&#10;Name of current user (i.e. "jsmith").'
[APPDATA]: #variables '```&#10;[PS] Write-Host $Env:APPDATA&#10;```&#10;The file-system directory that serves as a common repository for application-specific data (i.e. "C:\Users\jsmith\AppData\Roaming").'
[LOCALAPPDATA]: #variables '```&#10;[PS] Write-Host $Env:LOCALAPPDATA&#10;```&#10;The file-system directory that serves as a data repository for local, non-roaming applications (i.e. "C:\Users\jsmith\AppData\Local").'
[WINDIR]: #variables '```&#10;[PS] Write-Host $Env:WINDIR&#10;```&#10;Windows folder in the system drive'

[endpoint]: # 'endpoint&#10;a particular configuration item in WinRM, representing a specific application for which WinRM can receive traffic'
[explicit remoting]: # 'explicit remoting&#10;opening a temporary or persistent Powershell session to a remote system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 176'
[external virtual switch]: # 'external virtual switch&#10;bound to networking protocol stack in the host operating system and connected to a physical network interface adapter on the host, allowing VMs to access the network to which the physical adapter is connected&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[implicit remoting]: # 'implicit remoting&#10;running a cmdlet specifying the `ComputerName` parameter, which directs its function to the remote system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 177'
[internal virtual switch]: # 'internal virtual switch&#10;Bound to a separate instance of the networking protocol stack in the host operating system, independent from the physical network interface adapter and its connected network, it allows VMs to access the virtual network, including the host operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[listener]: # 'listener&#10;configuration item in WinRM representing the ability of the service to accept incoming network traffic, associated with a TCP port number'
[NuGet]: # 'NuGet&#10;.NET package manager'
[private virtual switch]: # 'private virtual switch&#10;Exists only in the Hyper-V server and is accessible only to the VMs running on it, and is inaccessible to the host operating system itself.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[remoting]: # 'remoting&#10;term applied to the use of WinRM in Powershell over port 5985 (or 5986 for HTTPS)'
[WinRM]: # 'Windows Remote Management (WinRM)&#10;Microsoft implementation of the WSMAN protocol, which handles communications and authentication for connections for many applications.&#10;Unlike MMCs, which are based on DCOM (legacy technology), WinRM is considered firewall-friendly and is the preferred option'
# Learning

#### Retrieval

**Retrieval-based learning** refers to the coupling of two ideas:

- **Retrieval processes**, those involved in using available cues to actively reconstruct knowledge, are most important in learning
- **Active retrieval** is most important for producing learning.

Retrieval-based learning characterizes knowledge as something that is reconstructed at the time of recall. 
Knowledge reconstruction is affected by the presence or absence of **retrieval cues**.
This is contrasted with the traditional analogy of knowledge as static storage.

Retrieval-based learning is an outgrowth of recent cognitive science research that shows that the act of measuring knowledge - by recall, answering questions, or solving novel problems - actually aids learning. 
The **testing effect** refers to the observation that the act of taking a test, by itself and without any feedback or further study, results in improved learning. ([src][Karpicke 2017])

**Retrieval effort** is a key concept in retrieval-based learning, which refers to the observation that activities that are difficult and require effort can be good for learning.
In other words, the effort involved in retrieval is the key to learning.

Learning activites that engage retrieval processes include group discussions, reciprocal teaching, and questioning techniques. ([src][Karpicke 2012])

**Free recall** refers to a specific task provided to subjects whereby the experimenter presents a list of items to be remembered and the subject is free to recall them in any order.

#### Paying forward

What's the best way to organize information for newcomers?

That is to say, what is the best way to organize notes on the **sources** of information that I stumble across, rather than merely the information itself?
The information itself is practical, but the context of what type of material assisted me in learning it should also be preserved, somehow.

For example, for someone new to [vim](https://github.com/jasper-zanjani/notes/tree/master/text/vim.md), Chris Toomey's [talk](https://youtu.be/wlR5gYd6um0 "Mastering the Vim Language") on YouTube might be a very good tool for learners who prefer to see lectures by impassioned and articulate people.
Someone who is more mechanically inclined might benefit more from [`pacvim`](https://github.com/jmoon018/PacVim "GitHub - jmoon018/PacVim"), or other hands-on activities.
Maybe a combination of both?

Some segments of PluralSight videos on esoteric technical topics appear to cover basic material concisely and effectively, in a way that made me wish I had access to those segments when I was learning it before.
Gathering this type of information could be useful, not to me, but to others.

How do I organize my thoughts and observations on the value of **sources** without doubling my effort?

#### Command-line syntax
After several weeks of refining my note-taking technique with regard to syntax, I believe I have settled on an improved workflow.

For all command-line syntax:
1. Note the command itself within "Commands" spreadsheet (separate from "Terms", which is for vocabulary)
2. If any options are encountered, document them in `Options`
3. If commands form command groups (like `apt`, `docker`, `git`, `netsh`, etc), those command groups need to be broken out separately ("Group-style commands")
4. If a command launches its own REPL (`bluetoothctl`, `diskpart`, `fdisk`...) those are broken out as well

#### Finding magic numbers
Before understanding the "lay of the land", or rather the best epistemology for a unit of information, you are first confronted with a list of information without context. This happened while studying for the Network+. On the topic of authentication, I learned a list of material, basically concepts associated with AAA. 

- **Authentication** process of determining...
- **Authorization** identifying the resources...
- **Accounting** tracking methods used ...
- **Authentication, Authorization, Accounting, and Auditing (AAAA)** conceptual model...
- **Remote Authentication Dial-In User Service (RADIUS)** protocol that enables ...
- **Terminal Access Control Access Control System (TACACS)** security protocol designed ...
- **Kerberos** security system ...
  - **ticket** security tokens issued to clients ...
- **Local authentication subsystem (LASS)** authenticates users ...

But after further research, I found that once you understand the role of authentication, then really there are only three main systems that implement it (according to the material): **Kerberos**, **TACACS**, and **RADIUS**.

Reducing a confusing mass of knowledge into a magic number (2, 3, 4, etc) helps in identifying interrelationships between concepts and entities

## Anki

Made good progress incorporating task-based learning by simplifying procedures into command sequences with no parameters or (at most) one or two.

**Cloze** notes with input comprise a low-level way of practicing the skill.
The best strategy to pursue is to identify common patterns, and make the most common elements of those patterns into cloze cards.

Basic templates:

=== "DSC"

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
            }
        }
    }
    ```

=== "C#"

    ```csharp
    namespace HelloWorld
    {
        class Program
        {
            static void Main(string[] args)
            {
            Console.WriteLine("Hello world!");
            }
        }
    }
    ```

Two tasks with related forms

```powershell
# Get connection string of account
constring=$(az storage account show-connection-string)

# Create file share with connection string
az storage share create --connection-string $constring
```

Single task with different implementations (see [tasks associated with cloud providers](/Cloud/Tasks))


Creating an availability set

=== "Azure Powershell"

    ```powershell
    New-AzAvailabilitySet
        -PlatformUpdateDomainCount
        -PlatformFaultDomainCount
        -Sku "{{c8::Aligned}}"
    ```

=== "Azure CLI"

    ```sh
    az vm availability-set create
        --platform-update-domain-count
        --platform-fault-domain-count
    ```

`Get`-`Set` pattern in PowerShell

=== "Capture a managed VM image"

    ```powershell
    $vm = Get-AzVM
    $image = New-AzImageConfig -SourceVirtualMachineId $vm.Id
    New-AzImage -Image $image
    ```

=== "Create a subnet"

    ```powershell
    $vnet2 = Get-AzVirtualNetwork -Name VNet2 -ResourceGroupName ExamRefRG
    $vnet2.Subnets += New-AzVirtualNetworkSubnetConfig -Name GatewaySubnet -AddressPrefix 10.2.1.0/27
    $vnet2 = Set-AzVirtualNetwork -VirtualNetwork $vnet2
    ```

=== "Create DNS record set"

    ```powershell
    $records = @()
    $records += New-AzDnsRecordConfig -IPv4Address "1.2.3.4"
    $records += New-AzDnsRecordConfig -IPv4Address "5.6.7.8"
    New-AzDnsRecordSet -Name "@" -RecordType A -ZoneName examref.com -ResourceGroupName ExamRefRG -Ttl 3600 -DnsRecords $records
    ```

=== "Change VM size"

    ```powershell
    $vm = Get-AzVM
    $vm.HardwareProfile.VMSize = Standard_DS3_v2
    Update-AzVM -VM $vm
    ```

=== "Add a route to a routing table"

    ```powershell
    $rt = New-AzRouteTable
    Add-AzRouteConfig -RouteTable $rt
    Set-AzRouteTable -RouteTable $rt
    ```

#### Structure

Playing around with reference-style links and tooltips has me thinking that there really should be a more structured, flexible way of generating text reports from object-style hierarchical information. For example, whether a definition appears beside a word dictionary style or in a tooltip on hover is really an implementation detail. There should be an easy way of storing that data and specifying that presentation dynamically.

What I have settled on is a multilayered note-taking strategy. Every **lexeme** is defined first in a **slug** or one-line description that establishes its **epistemological** context as well as its **semantic** significance. A **stub** further elaborates the lexeme, especially insofar as it encapsulates further lexemes or can be analyzed into components.

These slugs and stubs can be presented in various ways. Most recently I have gotten into the habit of putting slugs into tooltips that appear when I hover over lexemes in my markdown notes. This is an especially elegant solution in tables, where I can provide a highly condensed and legible index of commands, each of which can be understood at a high level by hovering the mouse while still providing full details when clicked on. This is also an elegant solution in tables of contents, where I can use a tooltip to contain a synopsis of a chapter which still links to the full notes. It provides a way of rendering information of intermediary fidelity, between the mere title and fully developed notes.


[Karpicke 2012]: http://learninglab.psych.purdue.edu/downloads/2012_Karpicke_CDPS.pdf "Karpicke, Jeffrey D. _Retrieval-Based Learning: Active Retrieval Promotes Meaningful Learning_. 2012."
[Karpicke 2017]: http://learninglab.psych.purdue.edu/downloads/inpress_Karpicke_Retrieval_Based_Learning_Review.pdf "Karpicke, Jeffrey D. _Retrieval-Based Learning: A Decade of Progress_. 2017"
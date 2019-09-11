# Notes and research
## Processing workflows
#### Cookbooks
**Cookbooks** are collections of tasks with representative implementations (e.g. Azure commands and procedures for [AZ-103](az-103.md))
1. **Number** tasks for easy reference, indexing, and linking in markdown
2. **Catalog** tasks and desciptions in a spreadsheet
3. **Copy** catalog with task and description to markdown. This will serve as both an index of tasks as well as the skeleton for the content. Use multiple cursors to introduce `####` heading syntax before the task identifier, followed by a carriage return before the one-line description of the task. This will ensure that the task is easily found by identifier. These should be collected in a single-cell table, producing a "cloud" of tasks."
4. **Fill** markdown with syntax, producing a true reference of the source's syntax
5. **Map** each form-based feature (e.g. commands) to tasks in a spreadsheet (Command | Task). Once organized by command, the resulting associations can form another table of content which associates form features to tasks. These should be placed in another single-cell cloud where each token is followed by links to the tasks in which it appears. The tokens should be organized, either by command group or roughly by domain.
6. **Index** form-based features at the top of the markdown as a concordance.
## Automation
### Ansible
Ansible is an automation tool used for configuration management.
Ansible **playbooks** represent a sequence of scripted actions which apply changes uniformly over a set of hosts.  **Modules** enable a particular task across many OSes, services, applications, etc. Predefined modules are available in the **module library**, and new ones can be defined via Python or JSON.\
Ansible host management relies on a `.ini` file containing a list of IP addresses or hostnames organized in groups.
#### Ad hoc commands
The `ansible` command is only used for running **ad hoc** commands, that is commands executed in realtime by an administrator working at the terminal. Modules are called as arguments passed to the `-m` option:\
```sh
ansible all -m ping 
```
#### Executing a playbook
Playbooks are executed with the `ansible-playbook` command
```sh
ansible-playbook -i production site.yml
```
#### Ansible Tower
**Ansible Tower** is a web-based RESTful API endpoint that provides the officially supported GUI frontend to Ansible configuration management. It is a commercial product that is available in two versions: **Standard** ($13,000/yr) and **Premium** ($17,500/yr) [[7](#sources)]\
On login, Tower presents a dashboard that depicts success and failure of Ansible playbook runs. Tower implements RBAC, supporting large teams. [[4](#sources)]\
#### AWX
**AWX** is the open-source project upon which Ansible Tower was built.
### Puppet
### Chef
## BitTorrent
Bram Cohen invented BitTorrent protocol in 2001 and wrote the first client in Python. It is a peer-to-peer file sharing protocol where those who share a file are called **seeders** and those who download are called **peers**. All seeders and peers related to a particular torrent comprise the **swarm**. The **tracker server** or **tracker** serves as a repository for information about peers associated with the same file. Files are downloaded in hashed pieces from multiple seeders to distribute the burden of seeding a file.\
A **Torrent Descriptor** file is a hashmap file
Torrent Descriptor property | Description
:---                        | :---
Announce                    | URL of the tracker
Info                        | dictionary whose keys depend on whether one or more files are being shared, including:<br/>Files: list of dictionaries, only exists when multiple files are being shared, each dictionary has two keys and corresponds to a file<br/>Length: size of the file in bytes<br/>Path: list of strings corresponding to subdirectory names, the last of which is the actual filename
length                      | size of the file in bytes (when one file is being shared
name                        | suggested file or directory name
Pieces length               | number of bytes per piece; must be a power of 2 and at least 16KiB
Pieces                      | list of SHA-1 160-bit hashes calculated on various parts of data

```json
{
  "Announce": "url of tracker",
  "Info": {
  "Files": [{ 
    "Length": 16, 
    "path": "/folder/to/path" }, 
    { "length": 193, 
    "path": "/another/folder" }] 
  },
  "length": 192, 
  "name":" Ubuntu.iso", 
  "Pieces length": 262144, 
  "Pieces": [AAF4C61DDCC5E8A2DABEDE0F3B482CD9AEA9434D, CFEA2496442C091FDDD1BA215D62A69EC34E94D0]
}
```

[[6](#sources)]
## Blockchain
Blockchain is a database technology that uses hashes to ensure reliability and security of data stored across a network of computers, popularized by BitCoin. Records, containing information, are validated and then added to **Blocks**, or hashed containers, which are then concatenated in a **chain** by associating each block with the hash of both of its neighbors. [[3](#sources)]
## Bootloaders
bootloader: software located in the first sector (Master Boot Record) of a HDD, which is read by the BIOS
- implementing interruptions requires knowledge of Assembler
- expertise in low-level programming in C
- Java and C# produce intermediate code, which must be executed by a special virtual machine
- mixed-code technique requires at least two compilers (one for Assembler and C, another as a linker to join the *.obj files to create a single executable file)
## Bots
### Discord
Main procedure:
  1. Create the bot user on Discord and register it with a guild.
  2. Write code that uses Discord’s APIs and implements your bot’s behaviors.
#### Create a Discord connection
A `Client` is an object that represents a connection to Discord, handling events, tracking state, and interacting with Discord APIs.
```py
# bot.py
import os, discord
from dotenv import load_dotenv # Install via `pip install -U python-dotenv`

load_dotenv()
token = os.getenv('DISCORD_TOKEN')

client = discord.Client()

@client.event
async def on_ready():
  print(f'{client.user} has connected to Discord!')

client.run(token)
```
#### Store token in `.env` file
`.env` should be placed in the same directory as `bot.py`
```
# .env
DISCORD_TOKEN={your-bot-token}
``` 
### Twitch
  - Nightbot
  - [Mee6](https://mee6.xyz/)
### Ruby bot programming
Ruby library "socket" allows integration with [Twitch's IRC API](https://twitchapps.com/tmi), which provides an oauth token which can be stored as password. Command `write_to_system` appears to be  what is needed to concatenate IRC commands `PASS #{@password`, `NICK #{@nickname}`, `USER #{@nickname} 0 * #{@nickname}`, and `JOIN #@{channel}`

From the REPL, you instantiate an instance of the class after running the script, which will allow passing messages to the chat room by using an instance method
```rb
bot = TwitchBot.new
bot.write_to_chat "Hello world"
```
## DevOps
> DevOps is a way to deliver software with shared pain and responsibility.

Traditionally, developers had incentives that were not aligned with those of operations who were to use the software. DevOps attempts to fuse development and operations, with the goal of aligning development with revenue generation.\
> Now, being a DevOps Engineer is something like "Systems Engineer 2.0".

There is an agreed-upon set of tools and concepts that most companies use with regard to DevOps. The end-goal is __endo-to-end process automation__, a digital pipeline that moves bits around in assembly line-like fashion.[[5](#sources)]
### Foundational layer
Three technologies that individually take a lifetime to master. Learning these skills will be an eternal commitment.
  - Linux
  - Python
    - Golang
  - AWS
    - Google Cloud

### Real-world skills
  - Configure
    - Terraform
      - Ansible
  - Version
    - Git and GitHub
      - GitLab
  - Package
    - Docker
      - Lambda
  - Deploy
    - Jenkins
      - CodeDeploy
  - Run
    - ECS
      - Kubernetes
  - Monitor
    - ELK Stack
      - Prometheus

## VMware
Hypervisor, similar to Hyper-V, but provided at a cost, with a robust command-line interface via PowerShell.[[6](#sources)]


## Sources
  1. "Custom bot using Ruby". [YouTube](https://www.youtube.com/watch?v=rVVhkX1uTRQ).
  2. "How to make a Discord bot in Python". [Real Python](https://realpython.com/how-to-make-a-discord-bot-python/): 2019/08/19.
  3. "Blockchain explained". [Reuters](https://graphics.reuters.com/TECHNOLOGY-BLOCKCHAIN/010070P11GN/index.html?source=post_page---------------------------).
  4. "Red Hat Ansible Tower Demo". [YouTube](https://youtu.be/wZ_mh4-4HPY): 2018/09/09.
  5. "How to become a DevOps engineer in six months or less". [medium.com](https://medium.com/@devfire/how-to-become-a-devops-engineer-in-six-months-or-less-366097df7737)
  6. "VMware PowerCLI 101". [BrianBunke.com](https://www.brianbunke.com/blog/2019/09/03/powercli-101/): 2019/09/03.
  7. "Ansible Tower vs. Ansible AWX". [4sysops](https://4sysops.com/archives/ansible-tower-vs-ansible-awx-for-automation/): 2019/08/13.
  8. "How Does BitTorrent Work? a Plain English Guide". [dev.to](https://app.getpocket.com/read/2717933967)

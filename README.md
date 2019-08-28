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
### Puppet
### Chef
## Blockchain
Blockchain is a database technology that uses hashes to ensure reliability and security of data stored across a network of computers, popularized by BitCoin. Records, containing information, are validated and then added to **Blocks**, or hashed containers, which are then concatenated in a **chain** by associating each block with the hash of both of its neighbors.
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
> DevOps is a way to deliver software with shared pain and responsibility.\ 
Traditionally, developers had incentives that were not aligned with those of operations who were to use the software. DevOps attempts to fuse development and operations, with the goal of aligning development with revenue generation.\
> Now, being a DevOps Engineer is something lik "Systems Engineer 2.0".\
There is an agreed-upon set of tools and concepts that most companies use with regard to DevOps. The end-goal is __endo-to-end process automation__, a digital pipeline that moves bits around in assembly line-like fashion.
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

## Sources
  - [medium.com](https://medium.com/@devfire/how-to-become-a-devops-engineer-in-six-months-or-less-366097df7737)
  1. "Custom bot using Ruby". [YouTube](https://www.youtube.com/watch?v=rVVhkX1uTRQ).
  2. "How to make a Discord bot in Python". [Real Python](https://realpython.com/how-to-make-a-discord-bot-python/): 2019/08/19.
  - "Blockchain explained". [Reuters](https://graphics.reuters.com/TECHNOLOGY-BLOCKCHAIN/010070P11GN/index.html?source=post_page---------------------------).
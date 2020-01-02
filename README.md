## Processing cookbooks
**Cookbooks** are collections of tasks with representative implementations (e.g. Azure commands and procedures for [AZ-103](az-103.md))
1. **Number** tasks for easy reference, indexing, and linking in markdown
2. **Catalog** tasks and desciptions in a spreadsheet
3. **Copy** catalog with task and description to markdown. This will serve as both an index of tasks as well as the skeleton for the content. Use multiple cursors to introduce `####` heading syntax before the task identifier, followed by a carriage return before the one-line description of the task. This will ensure that the task is easily found by identifier. These should be collected in a single-cell table, producing a "cloud" of tasks."
4. **Fill** markdown with syntax, producing a true reference of the source's syntax
5. **Map** each form-based feature (e.g. commands) to tasks in a spreadsheet (Command | Task). Once organized by command, the resulting associations can form another table of content which associates form features to tasks. These should be placed in another single-cell cloud where each token is followed by links to the tasks in which it appears. The tokens should be organized, either by command group or roughly by domain.
6. **Index** form-based features at the top of the markdown as a concordance.

## Bootloaders
**bootloader**: software located in the first sector (Master Boot Record) of a HDD, which is read by the BIOS
- implementing interruptions requires knowledge of Assembler
- expertise in low-level programming in C
- Java and C# produce intermediate code, which must be executed by a special virtual machine
- mixed-code technique requires at least two compilers (one for Assembler and C, another as a linker to join the *.obj files to create a single executable file)

## Bots
#### Discord
1. Create the bot user on Discord and register it with a guild.
2. Write code that uses Discord’s APIs and implements your bot’s behaviors.

Create a Discord connection [^][2]
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
Store token in `.env` file
`.env` should be placed in the same directory as `bot.py`
```
# .env
DISCORD_TOKEN={your-bot-token}
``` 
#### Twitch
- Nightbot
- [Mee6](https://mee6.xyz/)

#### Ruby bot programming
Ruby library "socket" allows integration with [Twitch's IRC API](https://twitchapps.com/tmi), which provides an oauth token which can be stored as password. Command `write_to_system` appears to be  what is needed to concatenate IRC commands `PASS #{@password`, `NICK #{@nickname}`, `USER #{@nickname} 0 * #{@nickname}`, and `JOIN #@{channel}`\
From the REPL, you instantiate an instance of the class after running the script, which will allow passing messages to the chat room by using an instance method [^][1]
```rb
bot = TwitchBot.new
bot.write_to_chat "Hello world"
```

## VMware
Hypervisor, similar to Hyper-V, but provided at a cost, with a robust command-line interface via PowerShell. [^][3]

---

[1]: https://www.youtube.com/watch?v=rVVhkX1uTRQ "Custom bot using Ruby"
[2]: https://realpython.com/how-to-make-a-discord-bot-python/ "How to make a Discord bot in Python"
[3]: https://www.brianbunke.com/blog/2019/09/03/powercli-101/ "VMware PowerCLI 101"
[5]: sources/README.md/#new-stack-makers "Storage in a DevOps World"

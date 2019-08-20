# Bots
## Discord
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
## Twitch
  - Nightbot
  - [Mee6](https://mee6.xyz/)
## Ruby bot programming
Ruby library "socket" allows integration with [Twitch's IRC API](https://twitchapps.com/tmi), which provides an oauth token which can be stored as password. Command `write_to_system` appears to be  what is needed to concatenate IRC commands `PASS #{@password`, `NICK #{@nickname}`, `USER #{@nickname} 0 * #{@nickname}`, and `JOIN #@{channel}`

From the REPL, you instantiate an instance of the class after running the script, which will allow passing messages to the chat room by using an instance method
```rb
bot = TwitchBot.new
bot.write_to_chat "Hello world"
```
## Sources
  1. "Custom bot using Ruby". [YouTube](https://www.youtube.com/watch?v=rVVhkX1uTRQ).
  2. "How to make a Discord bot in Python". [Real Python](https://realpython.com/how-to-make-a-discord-bot-python/): 2019/08/19.
# Discord
- [Discord](#discord)
    - [Discord UI](#discord-ui)
    - [Creating a new Discord](#creating-a-new-discord)
    - [Creating a bot](#creating-a-bot)
    - [Set-up](#set-up)
    - [Visual Studio Code](#visual-studio-code)
    - [First bot](#first-bot)
    - [Environment variable](#environment-variable)
      - [TextChannel hello-world](#textchannel-hello-world)
      - [DM hello-world](#dm-hello-world)
      - [Enriched hello-world](#enriched-hello-world)
    - [Cogs](#cogs)
      - [Call-out to click video](#call-out-to-click-video)
    - [Inspection of `ctx` object](#inspection-of-ctx-object)
    - [Events](#events)
    - [Reaction role](#reaction-role)
      - [`on_raw_reaction_add`](#on_raw_reaction_add)
      - [`discord.utils.get`](#discordutilsget)
      - [Adding role](#adding-role)
  - [API](#api)

If you're watching this video, odds are you need no introduction to Discord. Discord is an instant 
messaging application with support for images and file sharing, custom emoji, and granular role-
based access control. Just a few years ago, Discord might have been considered just one of many 
messaging platforms, vying for the spotlight alongside Telegram, Viber, WhatsApp, Slack, and 
Microsoft Teams. But today, Discord is the de facto communications platform for tech geeks, 
YouTubers, and especially PC gamers and Twitch streamers. With Discord it is ridiculously easy to 
start a free online community, populated with channels for text and voice communication, and you 
can even host video streams. Most interesting of all, Discord exposes an API that is supported by 
libraries that support the development of bots in a 
[**ton** of languages](https://discord.com/developers/docs/topics/community-resources).

Today I'm going to take you from zero to hero in one of these libraries, **Discord.py**!
Let's get started!

### Discord UI
I just created a fresh Discord account. All you need to provide is an email address for verification.
The Discord logo at the top opens our private messages. We don't have any at the moment. We can 
discover other public servers using the compass icon. We can also create our own server by clicking 
on the plus button. As you can see I haven't joined any Discord servers, which would appear between 
the compass and the plus icons.

But let's change that right now and join the [Discord.py](https://discord.gg/r3sSKJJ) server. This 
is a Discord server run by the developers and maintainers of the discord.py library. I can find an 
invite link from their GitHub page. I scroll to the bottom, click on the link and confirm that I 
want to join the server. As you can see, the icon now appears on the left sidebar. Within a typical 
Discord server, you usually find many TextChannels for chat, and a few VoiceChannels for audio 
communication. These are found on the left sidebar, to the right of the list of joined servers.
On the right sidebar you can find a list of all server members, organized by role.

### Creating a new Discord
Let's create our own Discord by clicking on the plus icon.

### Creating a bot
Let's open up a web browser and navigate to https://discordapp.com/developers

- token is a **secret**
- permissions

### Set-up
Before we start coding, we're going to install a virtual environment.
A virtual environment acts as a secondary installation of Python where we will install **dependencies**.
It is considered a best practice to install packages like discord.py in virtual environments so that 
you don't clutter up your system installation of Python with a bunch of packages of various versions
that could cause you confusion down the road.
How you do this is up to you, but I like to organize all my virtual environments into a single folder
that I can then reference from multiple projects that are stored elsewhere.
I start PowerShell and navigate to the correct folder.
I create the virtual environment by invoking Python with `-m` followed by "venv", then the name of the
virtual environment I want to create.
```sh
python -m venv discord
```
Now that it's created, before I activate it I inspect where the python command points to.
```powershell
Get-Command python | select Source
```
This is the system installation of Python.
I invoke the Activate script, which tells the system I want to use the virtual environment that
was just created and changes the appearance of the prompt.
```powershell
.\discord\Scripts\Activate.ps1
```
Now I inspect how the system will interpret the `python` command and confirm that it does indeed
point to the virtual environment.
```powershell
Get-Command python | select Source
```
Now when I run Python, I'll be running the Python that was installed to this directory because I
activated the virtual environment.
The same goes for `pip`, which is Python's package manager.
```powershell
gcm pip | select Source
```
I install the discord.py package into the virtual environment.
```sh
pip install discord.py
```
I can confirm the package was installed by running
```sh
pip list
```
I can leave the virtual environment by typing
```sh
deactivate
```
Now I have returned to the system installation of Python. If I check installed packages
```sh
pip list
```
We see that discord.py was installed only to the virtual environment, leaving our system installation
clean.

### Visual Studio Code
Now we are ready to start up our editor.
For this video I'm going to use Visual Studio Code, which is available free of charge for multiple
platforms, including Windows 10.
I have the Python extension installed, and you should too if you're thinking of developing in Python.
I start a new project folder to contain our work, and start a new Python script.
```py
import discord
```
As we can see, attempting to import the discord.py package produces an error.
That is because VS Code is still using the default system installation of Python.
We already confirmed that we installed the discord.py package only to the virtual environment and
not to the system installation. How do we tell VS Code to use the virtual environment?

We can select the virtual environment's interpreter by clicking here.
Once we select the correct interpreter, which is found in the same directory as the `activate` script,
the error is resolved, and we're ready to hit the ground running.

### First bot
There are several ways of using the API exposed by the discord.py package. We will stick to the 
easiest one by instantiating a `Bot` object. If you've never used a Discord bot, they typically 
appear as another user, and their functionality is accessed by typing a keyword preceded by a 
special character within a channel or DM, like `!help`.
`command_prefix` indicates what these specials characters will be. You can specify
more than one prefix by specifying a list of strings. Today, we will keep things simple and stick to
a period. Finally, we invoke the `run` method of the newly instantiated `Bot` object and pass it the 
token.
```py
from discord.ext.commands import Bot

bot = Bot(command_prefix='.')

bot.run(token)
```
Let's run the script as-is. We don't get any feedback in the terminal, but if we check the Discord, 
we see our bot is now online. We haven't defined any functionality for it yet, but we can type `.help`
and we receive a help message. This is because the help message is automatically implemented for any 
bot. Congratulations! You've created a completely useless Discord bot, hopefully the first of many!

### Environment variable
If you're starting out learning coding, then it's important to learn good habits from the jump.
And one of the most important habits is keeping **secrets** like a token out of your code. 
In the previous example, I placed the literal token within my code, a practice known as **hardcoding**.
This is a security issue, because anyone who sees this token will be able to use it and abuse it as
they please. 
Don't worry about my token here -- by the time you see this video it will have been changed long ago.

One day you might decide to share your code, because you need help with it or want to 
show off your achievement by uploading it to a public repository like GitHub. Unfortunately, hard-coded
secrets left within code remains one of the biggest sources of data leaks, and even big companies
and experienced developers are guilty of this rookie mistake. So how do we protect our secret token?

One of the best ways of protecting secrets is by placing them in **environment variables**.
Environment variables are values stored in memory and which can be accessed from Python.
Let's open up the integrated terminal by hitting <kbd>Ctrl</kbd><kbd>&grave;</kbd>, which is the
key directly to the left of the number 1 on US keyboards. 

As we can see, because we selected the virtual environment
as our interpreter, the integrated terminal comes up with the virtual environment already loaded.

Keep in mind in this video I'm using a Windows environment, so if you're using a Mac OS X or Linux
computer, the terminal will look different.

In PowerShell, environment variables can be viewed as a PowerShell drive, meaning it is treated
like a virtual filesystem
```powershell
Set-Location Env:\
Get-ChildItem 
```
Our system already has many environment variables set up. 
These environment variables provide information to programs on certain important locations.
For example, `SystemRoot` points to the directory where our installation of Windows is located.
My system has Windows installed to "C:\WINOWS", and if you're running Windows yours probably does too.
In PowerShell we can access the value of environment variable like so
```powershell
$Env:SystemRoot
```
Because it's a location on the drive, we can navigate directly there by accessing the environment variable as an argument to another command.
```powershell
Set-Location $Env:SystemRoot
Get-Location
```
Let's start the Python interpreter and see how we can access environment variables within Python.
```sh
python
```
Now we import the `os` module, which is part of the **Standard Library**. The Standard Library is
a collection of modules that are provided by default with every installation of Python.
```py
import os
```
We can access environment variables by calling `os.getenv()`. Let's use this command to inspect the
Windows installation directory.
```py
os.getenv('SystemRoot')
```

Now let's find out how to temporarily declare an environment variable and access it from the
script.
First we create a new file named ".env".
We open it up and we create a value
```
TOKEN=...
```
Let's install a new module
```sh
pip install dotenv
```
Now we place an import statement at the top of our Python script. And we can call a function 
```py
import dotenv

dotenv.load_dotenv()
```
When the script is run, this function call will load the ".env" file and add the TOKEN value to the
environment. Its value will be available as an environment variable.

Let's try it out:
```py
import os, dotenv

dotenv.load_dotenv()
token = os.getenv('TOKEN')
print(token)
```
As we can see we successfully loaded the .env file, then accessed its value as an environment variable.
However, once the script has completed execution and we exit the interpreter, the TOKEN variable is no
longer available
```powershell
$Env:TOKEN
```
This is how we can protect secrets at the measly cost of nothing more than 2 additional lines of code.
This has the added benefit that we will be able to use the same .env file for any additional Python
scripts we compose in this directory.

Let's compose 
```py
# import discord
import os, dotenv
from discord.ext.commands import Bot

dotenv.load_dotenv()
token=os.getenv('TOKEN')

client= Bot(command_prefix='.')

# ...

client.run(token)
```
#### TextChannel hello-world
These expressions preceded by the `@` sign are called **decorators**.
A deeper discussion of what decorators do is outside the scope of this video, but it's enough to
say that they add functionality to any functions they decorate.
And in discord.py in particular, they will tie together all the code you write.
`ctx.send` equivalent to `print`
```py
@client.command()
async def hello(ctx):
  await ctx.send(f'Hello world!')
```

#### DM hello-world
```py
@client.command()
async def hello(ctx):
  user = ctx.author
  await user.send('Hey handsome')
```

#### Enriched hello-world
**Embed**: enriched message
- URLs are automatically put into links
```py
@client.command()
async def hello(ctx):
  user = ctx.message.author.name
  emoji = random.choice([':grin:', ':smiling_face_with_3_hearts:', ':smirk:'])
  embed=discord.Embed(
    title=f"Hello {user}!", 
    description=f"Thank you for the attention {emoji}",
    color=discord.Color.teal())
  await ctx.send(embed=embed)
```
### Cogs
When you're developing something from scratch or learning something new, your code can get messy 
very quickly.
It's always a good idea to keep your code as tidy and clean as possible. 
You can definitely do this using the standard Python imports and modules.
This shouldn't be much of an issue since we're defining procedural functions which have nothing 
to do with one another logically.
The discord.py library offers a way to do that in what are called "Cogs", which not only organize
and modularize your code but offer a way to group your commands into command groups. 

```py
from discord.ext import commands
import dotenv
import os

dotenv.load_dotenv()
token = os.getenv('TOKEN')

client = commands.Bot(command_prefix='.')

client.load_extension('cogs.Example')

if __name__ == "__main__":
  client.run(token)
```
The way the cog file itself is designated by using the directory name and filename separated by period is the same convention used in [ **Django** ](django.md).
```py
from discord.ext import commands

class Example(commands.Cog):
  def __init__(self, client):
    self.client = client

  @commands.command()
  async def ping(self, ctx):
    await ctx.send('pong')
```

#### Call-out to click video
If the use of these command decorators strikes you as bizarre and you feel that it would help you
to see them being used in a different context, another video I recently made should help you out.
In it, I go over the `Click` package, which allows you to create command-line utilities in Python 
using decorators that look and act a whole lot like these ones.

### Inspection of `ctx` object
Listing channels on a Discord server
```py
@commands.command()
async def channels(self, ctx):
  channels = [c.name for c in ctx.guild.channels if type(c) is discord.TextChannel]
```
Snitch command
```py
@commands.command()
async def dmowner(self, ctx):
  user_id = ctx.guild.owner_id
  user = self.client.get_user(user_id)
  print(user_id)
  await user.send(f'This guy {ctx.author.name} is creeping me out... Betta handle dat!')
```

### Events
Event handler functions conventionally have names beginning with "on", i.e. `on_load`
- `@commands.Cog.listener()` vs. `@client.event` vs. `on_ready(self)` (class-based)

```py
@client.event
async def on_ready():
  print(f"Logged in as {client.user.name}")
```
```py
@commands.Cog.listener()
async def on_ready(self):
  print(f"Logged in as {self.client.user.name}")
```
### Reaction role
So we've established a broad-based understanding of the features exposed in the discord.py API:
- **commands** defined using the `command()` decorator
- **event handlers** that use the `event` decorator and which override the API's built-in events 
- **`Context`**  objects that are passed to commands upon invocation from the message window. Context objects, in turn, expose a
  - `send` method that we can use to send messages back to the `TextChannel` where the command originated
  - Using the `author` attribute of a Context object, we can send direct messages.
- `Embed` objects for richer message content
- **Cogs** to organize and modularize commands
- Most importantly, we learned about the **`Bot`** object itself, which accepts the token we get from the Discord developer portal, and how to keep that token secure.

Let's implement a practical project that will allow us to bring these lessons home. One of the most common features that Discord guild maintainers want to implement is a bot that will automatically assign roles to members based on an emoji reaction, or a "reaction role". In Discord these are often used to force members to indicate agreement to a code of conduct or to assign fun roles based on the individual's personal interests.

---

- First we need to adjust the permissions of the bot by assigning it the "Manage roles" permission. We can do this through the developer portal, but it's easier to do it in the Discord server itself
  - We right-click on our Discord server** and open **server settings
  - Let's go to the Roles section and click on Chatty Cathy
  - We scroll down until we find the Manage Roles permission
  - We grant Chatty Cathy the permission to manage roles
- We also need to actually create a role that Chatty Cathy will assign to a user. We can also do this in server settings.
- We also need to make sure the bot's role is placed physically above that of the role to be assigned.
- Discord roles are arranged like a totem pole in this way, such that roles can only be assigned by higher roles.
- Finally we can write some code.

#### `on_raw_reaction_add`
:red_circle: :point_right:

Let's go back to Visual Studio Code where we will create a new event handler in main.py for the **ON RAW REACTION ADD** event. This event, unlike the `on_ready` event **will** be passed a **PAYLOAD** argument..
```py
@bot.event
async def on_raw_reaction_add(payload):
  pass
```
:point_left:

The **Payload** argument is similar in concept to a Context object. It is not as rich in information. A payload does expose a few useful properties that we will need if we want to implement the functionality of a reaction role.

Where a Context object exposes a **Guild** object, a Payload object exposes only a **guild_id**.
Where a Context object exposes a **Channel** object, a Payload object exposes only a **channel_id**.
Where a Context object exposes a **Message** object, a Payload object exposes only a **message_id**.
This means that we have to implement additional query logic in order to retrieve these objects from the ID numbers alone.

[Context](https://discordpy.readthedocs.io/en/latest/ext/commands/api.html?highlight=context#discord.ext.commands.Context) | [RawReactionActionEvent](https://discordpy.readthedocs.io/en/latest/api.html?highlight=on_raw_reaction_add#discord.RawReactionActionEvent)
:---    | :---
**Guild** | `guild_id`
**Channel** | `channel_id`
**Message** | `message_id`

:point_right:


```py
@client.event
async def on_raw_reaction_add(payload):
  print("Message ID:",payload.message_id)
  print("Channel ID:", payload.channel_id)
  print('Guild ID:',payload.guild_id)
  print('Emoji:', payload.emoji.name)
```
Let's run it in the integrated terminal and see how it responds. After a moment, the `on_ready` event handlers fire, and the bot is running. Let's open Discord, react to a message, then examine the output in the terminal. The event handler worked!

Now let's see what the significance of this output is. Let's open Discord again, copy the message URL, and compare it to the output in the terminal. As we can see,
- The **first number** indicates the Discord server, or Guild as it is referred to in the Discord API
- The **second number** indicates the channel ID
- The **third number** indicates the message ID

Now let's create a new channel. This is where new Discord server members will have to go to be granted the **Turtles** role.
```
Respond with :thumbs_up:
```
And let's give it a reaction. As we can see, the event handler will be triggered when members perform emoji reactions to any message in any `TextChannel` on our Discord server.

Now we're ready to complete the implementation of the role reaction

#### `discord.utils.get`
:red_circle:

In order to retrieve the object from the object id, we're going to use the **`discord.utils.get`** function. [`discord.utils.get`](https://discordpy.readthedocs.io/en/latest/api.html?highlight=utils#discord.utils.get) takes the sequence to be queried first, and we can pass the guild_id into the id keyword argument.
```py
guild = discord.utils.get(client.guilds, id=payload.guild_id)
```
Now that we have a guild object, we can use this same `get` function to get the role that we want to assign.
```py
role = discord.utils.get(guild.roles, name='Turtles')
```
Now we can retrieve the member object for the user that actually provided the emoji reaction
```py
member = discord.utils.get(guild.members, id=payload.user_id)
```
Finally, a method exposed by the member object allows us to add the role.
```py
await member.add_roles(role)
```
Let's fire up our bot in the integrated terminal. The `on_ready` events fired, and we're up and running. Let's switch over to Discord. We can see that my username in Discord is not green. I do have a crown, because I am the Guild owner, but I do not have the Turtles role yet. 

I put a thumbs up on the message, and I can see that now my name is green. Our reaction role bot worked!

For some objects, in particular `Guild`, the Client object exposes a specific method:
```py
guild = client.get_guild(payload.guild_id)
```
[`discord.utils.find`](https://discordpy.readthedocs.io/en/latest/api.html?highlight=utils#discord.utils.find) uses a syntax similar to the Python builtin `filter` function, where a **lambda** function is defined, then the sequence of items across which it will be executed.

So for example, let's start a Python interpreter in the terminal. Let's make a list of numbers from 0 through 9.
```py
l = range(10)
```
We can use the filter command to find only even numbers:
```py
list(filter(lambda x: x % 2 == 0, l)) # [0,2,4,6,8]
```
What we're doing here is that we're iterating over this sequence of elements and executing this lambda function by passing each element through this expression. If the expression returns true, then that element makes it through. If the expression evaluates as false, that value is filtered.

`discord.utils.find` uses an identical syntax, but instead of returning multiple values, it returns only one. So we can use it to retrieve the guild object from the guild_id
```py
guild = discord.utils.find(lambda g : g.id == payload.guild_id, client.guilds)
```
A deeper discussion of lambdas is outside the scope of this video, and because the syntax can be confusing to someone who's not familiar with the topic, I'm actually going to comment out this line.

#### Adding role

`Member.add_roles` method takes a role object
```py
@client.event
async def on_raw_reaction_add(payload):
  if payload.message_id == 751854496748929065 and payload.emoji.name == u"\U0001F44D":
    guild = get(client.guilds, id=payload.guild_id)
```
## API
- Context
  - Guild
  - Message
    - Author
  - 
- Client
  - guilds
- Guild
  - **channels**
  - **roles**
  - **members**
  - `id`
- Payload
  - **Member**
  - **Emoji**
  - `message_id`
  - `channel_id`
  - `guild_id`

# discord.py

```sh
pip install discord.py
client = discord.Client()
```
`Client` objects expose a decorator that is used for event handlers, functions named after various events:
- `on_ready`
- `on_member_join`
- `on_error`
- `on_message`
```py
@client.event
async def on_ready():
  print(f'{client.user} has connected to Discord!')
```
Another decorator is exposed for in-chat commands ([`commands.Bot`](#discordextcommandsbot) has to be instantiated first.)
```py
@bot.command(name='roll_dice', help='Simulates rolling dice.')
async def roll(ctx, number_of_dice: int, number_of_sides: int):
  dice = [
    str(random.choice(range(1, number_of_sides + 1)))
    for _ in range(number_of_dice)
  ]
  await ctx.send(', '.join(dice))
```
```py
client.run(token)
```

```py
bot = comands.Bot(command_prefix='!')
```
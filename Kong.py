import discord
from discord.ext import commands

token = "**"

intents = discord.Intents.default()
intents.message_content = True

bot = commands.Bot(command_prefix = ".", intents = intents)

@bot.event
async def on_ready():
    print("Login to: ", bot.user.name)
    print("connection was succesful")
    await bot.change_presence(status = discord.Status.online, activity = None)

@bot.command()
async def join(ctx):
    try:
        global vc
        vc = await ctx.message.author.voice.channel.connect()
        await ctx.send(embed = discord.Embed(title = "Kong", description = "Join to channel..", color = 0x000000))
    except:
        try:
            await vc.move_to(ctx.message.author.voice.channel)
        except:
            await ctx.send(embed = discord.Embed(title = "Kong", description = "You don't join some channel", color = 0x000000))


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
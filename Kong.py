import discord
from discord.ext import commands

token = "MTAxNTEyNTIxNTkyNTI1NjE5Mg.GWtwvk.1Xi6LS7geiURCpPrN2oufzFqOFNvB9jzuwPKjY"

intents = discord.Intents.default()
intents.message_content = True

bot = commands.Bot(command_prefix = ".", intents = intents)

@bot.event
async def on_ready():
    print("Login to: ", bot.user.name)
    print("connection was succesful")
    await bot.change_presence(status = discord.Status.online, activity = None)
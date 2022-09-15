import discord
from discord.ext import commands
from youtube_dl import YoutubeDL
import time
import asyncio
import bs4
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from discord.utils import get_slots
from discord import FFmpegPCMAudio

token = ""

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

@bot.command()
async def leave(ctx):
    try:
        await vc.disconnect()
    except:
        await ctx.send(embed = discord.Embed(title = "Kong", description = "I didn't join anywhere channel", color = 0x000000))

@bot.command()
async def say(ctx, *, text):
   await ctx.send(embed = discord.Embed(title = "Say", description = text, color = 0xffffff))

@bot.command()
async def URLplay(ctx, *, url):
    YDL_OPTIONS = {'format': 'bestaudio','noplaylist':'True'}
    FFMPEG_OPTIONS = {'before_options': '-reconnect 1 -reconnect_streamed 1 -reconnect_delay_max 5', 'options': '-vn'}

    if not vc.is_playing():
        with YoutubeDL(YDL_OPTIONS) as ydl:
            info = ydl.extract_info(url, download=False)
        URL = info['formats'][0]['url']
        vc.play(FFmpegPCMAudio(URL, **FFMPEG_OPTIONS))
        await ctx.send(embed = discord.Embed(title= "Play Music", description = "Now played Music: " + url, color = 0x00ff00))
    else:
        await ctx.send("Music has been played now!")

@bot.command()
async def play(ctx, *, msg):
    if not vc.is_playing():
        global entireText
        YDL_OPTIONS = {'format': 'bestaudio', 'noplaylist':'True'}
        FFMPEG_OPTIONS = {'before_options': '-reconnect 1 -reconnect_streamed 1 -reconnect_delay_max 5', 'options': '-vn'}
            
        chromedriver_dir = r"C:\code\py\Kong\chromedriver.exe"
        driver = webdriver.Chrome(chromedriver_dir)
        driver.get("https://www.youtube.com/results?search_query="+msg+"+lyrics")
        source = driver.page_source
        bs = bs4.BeautifulSoup(source, 'lxml')
        entire = bs.find_all('a', {'id': 'video-title'})
        entireNum = entire[0]
        entireText = entireNum.text.strip()
        musicurl = entireNum.get('href')
        url = 'https://www.youtube.com'+ musicurl 

        with YoutubeDL(YDL_OPTIONS) as ydl:
            info = ydl.extract_info(url, download=False)
        URL = info['formats'][0]['url']
        await ctx.send(embed = discord.Embed(title= "Play Music", description = "Now played Music: " + entireText, color = 0x00ff00))
        vc.play(FFmpegPCMAudio(URL, **FFMPEG_OPTIONS))
    else:
        await ctx.send(embed = discord.Embed(title = "Music", description = "Can't play the Music: Just played Music now :!", color = 0xff0000))

bot.run(token)
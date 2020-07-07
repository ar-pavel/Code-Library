
import requests
from bs4 import BeautifulSoup

page = requests.get('https://www.thedailystar.net/')

daily_star = BeautifulSoup(page.text,'lxml')

headlines = daily_star.find_all('h5')

for headline in headlines:
	if len(headline.text)>17:	#This condition will help to skip redundant lines
		print(headline.text, end = "\n\n")

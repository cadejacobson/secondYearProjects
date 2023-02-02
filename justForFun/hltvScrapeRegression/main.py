from selenium import webdriver
from bs4 import BeautifulSoup
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt

def getPlayerInfo():
    driver = webdriver.Chrome("/usr/lib/chromium-browser/chromedriver")
    names = []
    rounds = []
    kdDiff = []
    kds = []
    ratings = []
    driver.get("https://www.hltv.org/stats/players")

    content = driver.page_source
    soup = BeautifulSoup(content, features="html.parser")

    i = 1

    for a in soup.findAll('td', attrs={'class': 'playerCol'}):
        oneName = a
        names.append(oneName.text)

    for a in soup.findAll('td', attrs={'class': 'kdDiffCol'}):
        oneKD = a
        kdDiff.append(oneKD.text)

    for a in soup.findAll('td', attrs={'class': 'statsDetail'}):
        if i % 3 == 0:
            oneKD = a
            kds.append(oneKD.text)
        i += 1

    for a in soup.findAll('td', attrs={'class': 'ratingCol ratingPositive'}):
        oneRating = a
        ratings.append(oneRating.text)

    for a in soup.findAll('td', attrs={'class': 'ratingCol ratingNeutral'}):
        oneRating = a
        ratings.append(oneRating.text)

    for a in soup.findAll('td', attrs={'class': 'ratingCol ratingNegative'}):
        oneRating = a
        ratings.append(oneRating.text)

    for a in soup.findAll('td', attrs={'class': 'statsDetail gtSmartphone-only'}):
        oneRound = a
        rounds.append(oneRound.text)

    df = pd.DataFrame({'Name': names, 'Rating': ratings, 'Rounds': rounds, 'KD Diff': kdDiff, 'K/D': kds})
    df.to_csv('players.csv', index=False, encoding='utf-8')

    reducedKds = []
    reducedRatings= []
    for i in range(kds.__len__()):
        reducedKds.append(float(kds[i]))
        reducedRatings.append(float(ratings[i]))

    p = np.poly1d(np.polyfit(reducedKds, reducedRatings,1))
    x_line = np.linspace(np.amin(reducedKds), np.amax(reducedKds), 200)
    plt.scatter(reducedKds, reducedRatings)
    plt.xlabel("Career Kill/Death Ratio")
    plt.ylabel("Average Rating (1.0)")
    plt.plot(x_line, p(x_line))
    plt.show()
    print(p)


getPlayerInfo()
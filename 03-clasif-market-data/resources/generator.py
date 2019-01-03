from numpy import random as nprandom
import random
import time
import datetime

loops = 1000

actives = ["GOOGLE", "APPLE", "TROLLOFONICA", "SAN@ANDER", "PIP0CONTGO_", "MAPFRE", "TOLAILOLAI", "ALIBABA", "AMAZON", "ALGO", "OTRO ALGO"]

price_mean = {}

default_data = open("/media/sampru/Datuak/eskola/prog-altas-prest/uc3m_prog_alt_prest/03-clasif-market-data/resources/default_data.txt", "w+")

for a in actives :
    price_mean[a] = random.randint(20, 100)

for i in range(0, loops) :
    active = actives[random.randint(0, len(actives) - 1)]
    price = nprandom.normal(price_mean[active], 5)
    timestamp = datetime.datetime.fromtimestamp(random.uniform(time.time(), time.time() + 10800)).strftime('%Y-%m-%d %H:%M:%S.%f')
    default_data.write(timestamp + ' "' + active + '" %.2f\n' % price)

default_data.close()

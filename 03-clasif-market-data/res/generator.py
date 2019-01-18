from numpy import random as nprandom
import random
import time
import datetime

loops = 1000000

actives = ["ACCIONA", "ACERINOX", "ACS", "AENA", "AMADEUS", "ARCELORMIT.", "BA.SABADELL", "BA.SANTANDER", "BANKIA",
           "BANKINTER", "BBVA", "CAIXABANK", "CELLNEX", "CIE AUTOMOT.", "ENAGAS", "ENCE", "ENDESA", "FERROVIAL",
           "GRIFOLS CL.A", "IAG", "IBERDROLA", "INDITEX", "INDRA A", "INM.COLONIAL", "MAPFRE", "MEDIASET",
           "MELIA HOTELS", "MERLIN", "NATURGY", "R.E.C.", "REPSOL", "SIEMENS GAME", "TEC.REUNIDAS", "TELEFONICA",
           "VISCOFAN"]

price_mean = {"ACCIONA":79.68, "ACERINOX":9.49, "ACS":35.32, "AENA":142.90, "AMADEUS":65.00, "ARCELORMIT.":20.02,
              "BA.SABADELL":1.06, "BA.SANTANDER":4.35, "BANKIA":2.59, "BANKINTER":7.11, "BBVA":5.20, "CAIXABANK":3.30,
              "CELLNEX":24.19, "CIE AUTOMOT.":24.30, "ENAGAS":25.02, "ENCE":6.47, "ENDESA":21.14, "FERROVIAL":19.36,
              "GRIFOLS CL.A":24.44, "IAG":7.02, "IBERDROLA":7.06, "INDITEX":23.83, "INDRA A":8.78, "INM.COLONIAL":8.92,
              "MAPFRE":2.46, "MEDIASET":5.75, "MELIA HOTELS":8.79, "MERLIN":11.51, "NATURGY":23.40, "R.E.C.":19.66,
              "REPSOL":15.00, "SIEMENS GAME":11.52, "TEC.REUNIDAS":22.22, "TELEFONICA":7.68, "VISCOFAN":47.52}

default_data = open("default_data.txt", "w+")

for i in range(0, loops) :
    active = actives[random.randint(0, len(actives) - 1)]
    price = nprandom.normal(price_mean[active], price_mean[active]/10)
    timestamp = datetime.datetime.fromtimestamp(random.uniform(time.time(), time.time() + 10800)).strftime('%d-%m-%Y %H:%M:%S.%f')
    default_data.write(timestamp + ' "' + active + '" %.2f\n' % price)

default_data.close()

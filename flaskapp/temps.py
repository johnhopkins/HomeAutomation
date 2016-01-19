from pymongo import MongoClient
import datetime
from datetime import timedelta, date
connection = MongoClient('localhost', 27017)
db = connection.homeautomation

start = datetime.datetime.now()
start = start.replace(hour=3,  minute=0, second=0, microsecond=0)
#start = datetime.datetime.now() - timedelta(hours=12)
end = datetime.datetime.now()

cursor = db.temperatures.find({'_id': {'$ne': 'current_temp'}, 'datetime':{'$gte': start}})

temperature = []; time = []

for record in cursor:
    temperature.append(record['temp'])
    time.append(record['datetime'])

import matplotlib as mpl
mpl.use('Agg')
import matplotlib.pyplot as plt

plt.figure(1)
plt.plot(time, temperature)
plt.xticks(fontsize=8,rotation=45)
plt.subplots_adjust(bottom=0.15)
plt.xlabel('Time')
plt.ylabel('Temp Celsius')
plt.title('Room Temperature')
plt.savefig('/var/www/johnhopkins.co.uk/flaskapp/static/temps.png')

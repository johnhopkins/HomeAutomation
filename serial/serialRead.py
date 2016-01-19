import serial, datetime
from pymongo import MongoClient

SERIALPORT = "/dev/tty.usbmodemFA1311"
BAUDRATE = 9600

ser = serial.Serial(SERIALPORT, BAUDRATE)
db = MongoClient('192.168.0.3')['homeautomation']['temperatures']

while True:
    data_raw = float(ser.readline().strip())
    db.update({'_id':'current_temp'},{'datetime':datetime.datetime.now(),'room':'attic','temp':data_raw}, upsert=True)
    db.insert({'datetime':datetime.datetime.now(),'room':'attic','temp':data_raw})

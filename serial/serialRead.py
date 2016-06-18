import serial, datetime
#from pymongo import MongoClient

''' To find the serial port you require type ls /dev/tty.* into your terminal 
	which will give you a list of all serial ports in use'''

SERIALPORT = "/dev/tty.SLAB_USBtoUART"
BAUDRATE = 9600

'''Instansiate a serial object and set it up with the required params.'''

ser = serial.Serial(SERIALPORT, BAUDRATE)

'''Create a mongodb connection object for storing data into the database'''

#db = MongoClient('192.168.0.3')['homeautomation']['temperatures']

''' Following loop reads serial port for incoming temperature data.
	Then updates the current temperature and inserts
	the data into our mongo database along with date and time  '''

while True:
    data_raw = float(ser.readline().strip())
#    db.update({'_id':'current_temp'},{'datetime':datetime.datetime.now(),'room':'attic','temp':data_raw}, upsert=True)
#    db.insert({'datetime':datetime.datetime.now(),'room':'attic','temp':data_raw})

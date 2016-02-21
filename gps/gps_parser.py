# Pruebas para parsear los mensajes del GPS
# Toma los datos literales via serial desde Arduino y los parsea en ordenador


import serial
import pynmea2

# TODO_p: buscar como detectar automáticamente el puerto con el que se comunica
# 115200 es el baud rate desde el que Arduino envia los datos que toma del GPS (9600 baduinos default)
serialPort = serial.Serial("/dev/cu.usbmodem1411", 115200, timeout=0.5)

while True:
    sentence = serialPort.readline()
    
    if sentence.find('GGA') > 0:
        data = pynmea2.parse(sentence)
        print "{time}: {lat},{lon}".format(time=data.timestamp,lat=data.latitude,lon=data.longitude)


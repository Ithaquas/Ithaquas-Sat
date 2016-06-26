/*
 * Ahorro en memoria frente al parseo onboard
*/

#include <SoftwareSerial.h>

#define RXPin 2
#define TXPin 3 // No se usa, posibilidad de eliminarlo usando
                // http://gammon.com.au/Arduino/SendOnlySoftwareSerial.zip
#define GPSBaud 9600 // default en el GPS
#define ConsoleBaud 115200 // Comunica al ordenador

// The serial connection to the GPS device
SoftwareSerial GPS_Serial(RXPin, TXPin); // Usando ambos pines

void setup()
{
  // Tenemos dos "canales" para los datos, Serial copia y envia
  // los datos que recibe de GPS_Serial
  Serial.begin(ConsoleBaud);
  GPS_Serial.begin(GPSBaud);
}

void loop()
{
  if (GPS_Serial.available() > 0) // As each character arrives...
  {
    Serial.write(GPS_Serial.read()); // ... write it to the console.
  }
}

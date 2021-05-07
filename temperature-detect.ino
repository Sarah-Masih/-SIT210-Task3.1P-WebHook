#include <Grove_Temperature_And_Humidity_Sensor.h>
//including library that is being used for DHT 11 Sensor
//the signal pin is connected to Pin D8 of particle argon
#define DHTPIN D8
DHT dht(DHTPIN);
int currentTemp=0;

void setup() 
{
    dht.begin();

  Particle.variable("temp", currentTemp);
}

void loop() {
    
     currentTemp=(int)dht.getTempFarenheit();
     Particle.publish("Temp",String(currentTemp), PRIVATE);
     delay(10000);
}


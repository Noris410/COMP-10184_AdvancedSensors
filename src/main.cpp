//I Noris Singa, 000812720 certify that this material is my original work. No other person's work has been 
//used without due acknowledgement. I have not made my work available to anyone else.

// 1-Wire sensor communication libary 
#include <OneWire.h> 
// DS18B20 sensor library 
#include <DallasTemperature.h> 
#include <Arduino.h>
 
// Pin that the  DS18B20 is connected to 
const int oneWireBus = D3;      
 
// Setup a oneWire instance to communicate with any OneWire devices 
OneWire oneWire(oneWireBus); 
 
// Pass our oneWire reference to Dallas Temperature sensor  
DallasTemperature DS18B20(&oneWire); 

DeviceAddress sensorAddress;
int numberOfDevices;

void printAddress(DeviceAddress d) {
  for (uint8_t i = 0; i < 8; i++) {
    if (d[i] < 16) Serial.print("0");
      Serial.print(d[i], HEX);
  }
}





void setup() {
  // put your setup code here, to run once:
   // configure the USB serial monitor 
  Serial.begin(115200); 
  Serial.println("\nTemperature Application ");
  DS18B20.begin();

  if(!DS18B20.getAddress(sensorAddress, 0)){
    Serial.println("No DS18B20 temperature sensors are installed!");

  }else{
    Serial.print("Found DS18B20 sensor with address: ");
    printAddress(sensorAddress);
    Serial.println();
  }

 
}

void loop(){
  // put your main code here, to run repeatedly:
  float fTemp; 
 
  // ask DS18B20 for the current temperature 
  DS18B20.requestTemperatures(); 
 
  // fetch the temperature.  We only have 1 sensor, so the index is 0. 
  fTemp = DS18B20.getTempCByIndex(0); 
 
  // print the temp to the USB serial monitor 
  Serial.println("Current temperature is: " + String(fTemp) + " \xC2\xB0""C"); 
 
  // wait 2s (2000ms) before doing this again 

  delay(2000); 
}


    





  

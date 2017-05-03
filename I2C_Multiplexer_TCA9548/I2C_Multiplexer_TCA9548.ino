#include "Wire.h"
extern "C" {
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}
#include "Adafruit_Si7021.h"

#define TCAADDR 0x70
Adafruit_Si7021 sensor[8]; // I2C

boolean portarray[8] = {true, true, true, true, true, true, true, true}; //To check the availability of the devices. Default is true for all ports 
float temperature[8]; //Stores 8 maximum possible values of Temperature
float humidity [8];//Stores 8 maximum possible values of Humidity
uint8_t j;
void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission(); 
}

void setup(void)
{
    while (!Serial);
    Wire.begin();
    Serial.begin(9600);
    Serial.println("\nTCA9548A Scanner ready!");
   
    for (uint8_t t=0; t<8; t++) { //Selecting the port
      tcaselect(t);
      Serial.print("TCA Port #"); Serial.println(t);

      for (uint8_t addr = 0; addr<=127; addr++) {// Since 7 bit address search for all addresses
        if (addr == TCAADDR) continue;
     
        uint8_t data;
        if (! twi_writeTo(addr, &data, 0, 1, 1)) {
           Serial.print("Found I2C 0x");  Serial.println(addr, HEX);
        }
      }
    }
    Serial.println("\ndone");
    delay(2000);

    Serial.println("Si7021 Multiplexer Initialization"); 
    Serial.println("");
    for (uint8_t port = 0; port<=7; port++) {
      tcaselect(port);
      if(!sensor[port].begin()){
        Serial.print("No Si7021 detected at port ");
        Serial.println(port);
        portarray[port] = false;
      }
    }
}

void loop(void)
{
  for (j = 0; j<=8; j++) {//For all the 8 ports
    if (portarray[j]) {
      tcaselect(j);   // Selects only the ports which are available
      temperature[j] = sensor[j].readTemperature();
      humidity[j] = sensor[j].readHumidity();   
      Serial.print("Port "); Serial.print(j);
      Serial.print(" Temperature = ");
      Serial.print(temperature[j]);
      Serial.println(" C");
      Serial.print("Port "); Serial.print(j);
      Serial.print(" Humidity = ");
      Serial.print(humidity[j]);
      Serial.println(" %");
      Serial.print("Port "); Serial.print(j);
      Serial.println("");
      delay(1000);
    }
  }
}


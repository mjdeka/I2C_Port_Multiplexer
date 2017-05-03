# I2C_Port_Multiplexer with Arduino.
I2C Port Multiplexing using the Adafruit's TCA9548A IC, and the temperature sensor Si7021.

--------------------------------------------------------------------------------
This project includes two modules:
1. Product Name: TCA9548A
   Product Type: I2C Port Multiplexer
   Product Link: https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout/overview
   I2C Address: 0x70

2. Product Name: Si7021
   Product Type: High Precision Temperature and Humidity Sensor suited for Heating Ventilation and Air Conditioning Systems.
   Product Link: https://www.sparkfun.com/products/13763
   I2C Address: 0x40
--------------------------------------------------------------------------------
Using sensors with non programmable I2C address is difficult if more number of sensors are to be installed with a same module.
The TCA9548A module is a solution for such problems if we have to hook up similar I2C devices with a micro-controller.
However there are solutions and libraries available for other modules of Adafruit like BME280 and BMP085 sensors.
Was facing difficulties while hooking up the Si7021 modules with the TCA9548A.
While trying to find some solutions for this problem, I found a code provided by Victor Armani (https://forums.adafruit.com/viewtopic.php?f=25&t=110426) in the link https://forums.adafruit.com/viewtopic.php?f=25&t=110426 for a similar solution for BME280.
I have made a few modifications with this code and used the library for Si7021 sensor module given in: https://github.com/adafruit/Adafruit_Si7021.
The code works fine with 3 modules of Si7021 tested in different SCL and SDA ports of the I2C multiplexer module.
--------------------------------------------------------------------------------

Mentor Credits:
1. Harsh Joshi
   https://github.com/Joshi-Harsh
2. Farogh Iftekhar

--------------------------------------------------------------------------------
Company Credits:
Smart Joules Pvt. Ltd.
http://www.smartjoules.co.in/
--------------------------------------------------------------------------------

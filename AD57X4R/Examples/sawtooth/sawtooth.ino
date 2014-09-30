#include "Arduino.h"
#include "SPI.h"
#include "AD57X4R.h"
#include "Streaming.h"

#define LOOP_DELAY 10
#define DAC_CS 49

const int value_inc = 100;

AD57X4R dac = AD57X4R(DAC_CS);
int power_control_register;
unsigned int value = 0;

void setup()
{
  // Setup serial communications
  Serial.begin(115200);

  // Initialize DAC
  dac.init(AD57X4R::AD5724R, AD57X4R::UNIPOLAR_5V, AD57X4R::ALL);

  // Check to make sure power_control_register set properly
  power_control_register = dac.readPowerControlRegister();
  Serial << "power_control_register =  " << _BIN(power_control_register) << endl;
}


void loop()
{
  value += value_inc;
  if (value > dac.getMaxDacValue())
  {
    value = 0;
  }
  Serial << "value = " << _DEC(value) << endl;
  dac.analogWrite(AD57X4R::ALL,value);
  delay(LOOP_DELAY);
}

/* This example shows how to use continuous mode to take
  range measurements with the VL53L0X. It is based on
  vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

  The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
 

  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
  Test();
}

float TestArray[200];

void Test()
{
  int x;
  for (x = 0; x < 200; x++){
    TestArray[x] = sensor.readRangeContinuousMillimeters();
    
  }
  for (x = 0; x < 200; x++)
  {
    Serial.println(TestArray[x]);
  }
  
}

void loop()
{
  
}

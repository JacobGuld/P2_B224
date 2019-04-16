/* This example shows how to use continuous mode to take
  range measurements with the VL53L0X. It is based on
  vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

  The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
const int antaltests = 50;

float TestArray[antaltests];

void Test(){
  int x;

  int sum;
  int gennemsnit;
  for (x = 0; x < antaltests; x++){
    TestArray[x] = sensor.readRangeContinuousMillimeters();
    
  }
  sum=TestArray[0];
  for(x = 0; x<antaltests-1; x++){
    sum=sum+TestArray[x+1];
  }
  gennemsnit = sum / antaltests;
  
  for (x = 0; x < antaltests; x++)
  {
    Serial.println(TestArray[x]);
  }
    Serial.print("WOW! gennemsnittet blev ");
    Serial.print (gennemsnit);
    Serial.println ("!");
  
}
void angiv_vaerdier(){
    int u=999;
    int b=0;
    for (int i=0; i < antaltests; i++){
    if(TestArray[i]<u){
    u=TestArray[i];
    }
    else if (TestArray[i]>u){
    }
    else if (TestArray[i]==u){
    }
    }
    for (int i=0; i < antaltests; i++){
    if(TestArray[i]>b){
    b=TestArray[i];
    }
    else if (TestArray[i]<b){
    }
    else if (TestArray[i]==b){
    }
    }
    Serial.print ("Det mindste tal er "); 
    Serial.print(u);
    Serial.print(", og det største tal er ");
    Serial.print(b) ;
    Serial.print(".");
}


void setup()
{
  Serial.begin(115200);
  Wire.begin();
 

  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
  Test();
  angiv_vaerdier();
}



void loop()
{
  
}

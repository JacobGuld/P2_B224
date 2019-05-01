#include <VL53L0X.h>
#include <Wire.h>
const int HBroPin1 = 3; //Defines the HBridges first pin
const int HBroPin2 = 4; //Defines the HBridgdes second pin
const int PWMoutput = 5; //Defines the PWMoutput  button pin
const int YButton = 11; //Defines the yellow button pin
const int BButton = 13; //Defines the blue button pin
int Speed = 100; //Between 0 and 255
int Distance; // Variable to store the measured distance
VL53L0X sensor; //defines the sensor name as sensor

double oenskede_afstand=420, measured_value=Distance, integral = 0, error, derivative, previous_error = 0; 
double dt=1;
double Kp=5;
double Ki=3;
double Kd=3;




void setup() { // defines input, output and sensor
  Serial.begin(115200);
  pinMode(HBroPin1, OUTPUT);
  pinMode(HBroPin2, OUTPUT);
  pinMode(PWMoutput, OUTPUT);
  pinMode(YButton, INPUT_PULLUP);
  pinMode(BButton, INPUT_PULLUP);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

void loop() {
  SystemDrive();
}

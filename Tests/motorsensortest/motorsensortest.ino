#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

const int p1 = 3;
const int p2 = 4;
const int PWMoutput = 5;
int dutyCycle = 100;
int RunTime = 0;
int Afstand;

void setup() {
  Serial.begin(115200);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(PWMoutput, OUTPUT);

  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}


void loop() {
  digitalWrite(p2, LOW);
  digitalWrite(p1, HIGH);
  Afstand = sensor.readRangeContinuousMillimeters();
  if (Afstand > 100) {
    dutyCycle = 100;
    analogWrite(PWMoutput, dutyCycle);
    delay(10);
  }
  else if (Afstand < 100) {
    dutyCycle = -100;
    analogWrite(PWMoutput, dutyCycle);
    delay(10);
  }
  else {
    dutyCycle = 0;
    analogWrite(PWMoutput, dutyCycle);
    delay(10);
  }

}

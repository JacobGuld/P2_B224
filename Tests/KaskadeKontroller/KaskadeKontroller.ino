#include <VL53L0X.h>
#include <Wire.h>
const int YButton = 11; //Defines the yellow button pin
const int xshut = 12;//Defines the blue button pin
const int HBroPin1 =  3;
const int HBroPin2 = 4;
const int PWMoutput = 6 ;
const int kpin = 2; 
unsigned long lastTime;
bool compute = true;
volatile int count; 

VL53L0X sensor; //defines the sensor name as sensor


void initializePWM() {
  cli();
  // sets TCCR5A register to fast PWM mode 9bit (WGM0 and WGM1, still needs to set WGMS in register B)and enables all coms
  TCCR4A = 0b10101010;
  // set TCCR5B for no prescaling, sets last WGM for pwm mode 9 bit.
  TCCR4B = 0b00001010;
  OCR4A = 0;
  OCR4B = 0;
  OCR4C = 0;
  sei();
  // formula for calculating PWM frequenzy can be found on page 160 sometihin in the atmega2560 datasheet, it's set for 32kHz
}





//float arr[5];

double photoGate(){
  double speed; 
  static long last; 
  static long time; 
  const int d = 35; 
  
  if (count > 1 ) {
    speed = 6321.0000/(micros()-time);
    time = micros();
    last = millis();
    count = 0;
  }
  
  else if (millis() > d + last) {
    last = millis();
    speed = 0;
    time = micros();
    count = 0;
  }
  return speed; 
}

class motor {
  public:
    motor() {

    }
    void goForwards() {
      digitalWrite(HBroPin2, LOW);
      digitalWrite(HBroPin1, HIGH);
    }
    void goBackwards() {
      digitalWrite(HBroPin2, HIGH);
      digitalWrite(HBroPin1, LOW);
    }

      void setPWM(int val) {
       //analogWrite(PWMoutput, val); 
          cli();
         OCR4A = val;//OCR4A is connectet to pin 6, we dont wan't doubles as dutycyles...
 
  sei();
      }
    
};


class pid {
  public:
    pid(double setdt, int setsign, int setCap) {
      sign = setsign; 
      dt = setdt;  
      invDt = 1/dt; 
      cap = setCap; 
      
      dev = new double[length];
      for (int i = 0; i < length ; i++) {
        dev[i] = 0;
      }

    }

    double getDev() {
      double result = 0;
      for (int i = 0; i < length; i++) {
        result += dev[i];
      }
      result = result / length;
      return result;
    }

    void addDev(double val) {
      static int pos;
      dev[pos] = val;
      pos ++;
      if (pos == (length - 1)) {
        pos = 0;
      }
    }
    void zeroI() {
      integral = 0;
    }

    double compute(double dist, double Kp, double Ki, double Kd, double target) {
      if (sign == 1){
      error = dist - target;
      }
      else if (sign == 0){
      error = target - dist;
      }
      integral = integral + (error * dt);
      if (integral > cap) {
        integral = cap;
      }
      if (integral < -cap) {
        integral = -cap;
      }

      addDev(derivative =(error - previous_error) * invDt);

      speed = (Kp * error)  + (Ki * integral) + (Kd * getDev());// signal til motor
      previous_error = error;
      
          if ( speed > 0.1) {
            speed = speed;
          }
          else if (speed < -0.1) {
            speed = speed ;
          }
     

      return speed;
    }


  private:

    double integral = 0, error, derivative, previous_error = 0;
    double target;
    double dt;
    double invDt;
    int sign; 
    int cap; 
    double speed;
    double *dev;
    int length = 2;

};




void setup() { // defines input, output and sensor
  Serial.begin(115200);
  initializePWM();
  pinMode(PWMoutput, OUTPUT);
  pinMode(xshut, INPUT_PULLUP);
  digitalWrite(xshut, HIGH);
  pinMode(HBroPin1, OUTPUT);
  pinMode(HBroPin2, OUTPUT);

  pinMode(PWMoutput, OUTPUT);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(40);
  sensor.startContinuous();

  attachInterrupt(digitalPinToInterrupt(kpin), counts, CHANGE);
  delay(1000);
}

void counts() {
  count ++ ;
}


void loop() {
  double distance;
  pid pid1(0.04, 1, 1.5);
  pid pid2(0.04, 0 , 3);
  motor motor1;
  bool go = true; 
  
  while (true) {
    double speed;
    if (compute == true) {
      distance = sensor.readRangeContinuousMillimeters();
      Serial.println(distance); 
      speed = count*0.0475; 
      count = 0; 
      distance = distance / 1000.00;
      
      if (distance > 3) {
        distance = 0.42;
        pid1.zeroI();
      }

      //Serial.println(distance);
      compute = false;
    }

    if ( (millis() - lastTime) > 40) {
        double pidVal; 

      
        pidVal = pid1.compute(distance, 40 , 12 , 24, 0.42); 
        if(pidVal > 0.1){
          pidVal = pidVal +1; 
        }
        else if (pidVal < -0.1){
          pidVal = pidVal -1; 
        }
        if (speed > 1.6){
          pidVal = 0; 
        }
        
      
       
       
      //Serial.println(pidVal);

      if (pidVal >= 0 ) {
        int PWM = 34 * pidVal;
        if (PWM > 511) {
          PWM = 511;

        }
        motor1.goForwards();
        motor1.setPWM(PWM);                  
       
        //Serial.println(PWM);
      }
      else if (pidVal < 0) {
        pidVal = abs(pidVal);
        int PWM = 34 * pidVal;
        if (PWM > 511) {
          PWM = 511;

        }
        motor1.goBackwards();
        motor1.setPWM(PWM);
        
        //Serial.println(PWM);
      }
      lastTime = millis();
      compute = true;
    }

  }
}

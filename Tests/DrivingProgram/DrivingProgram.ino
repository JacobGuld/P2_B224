const int HBroPin1=3;
const int HBroPin2=4;
const int PWMoutput=5;
const int YButton=11;
int Speed=100; //Between 0 and 255
int RunTime = 0;

void setup() {
Serial.begin(115200);
pinMode(HBroPin1,OUTPUT);
pinMode(HBroPin2,OUTPUT);
pinMode(PWMoutput,OUTPUT); 
pinMode(YButton, INPUT_PULLUP);

}

void Drive() {
  digitalWrite(HBroPin2,LOW);
  digitalWrite(HBroPin1,HIGH);
  analogWrite(PWMoutput,Speed);
}

void Brake() {
  digitalWrite(HBroPin2,HIGH);
  RunTime=0;
  
}

void loop() {
if (digitalRead(YButton) == LOW) {
  Drive();
  
  }
  Brake();
}
}
 
  

  

  
  

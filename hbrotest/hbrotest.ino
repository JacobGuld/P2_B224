const int p1=3;
const int p2=4;
const int PWMoutput=5;
int dutyCycle=100;
int RunTime = 0;


void setup() {
Serial.begin(115200);
pinMode(p1,OUTPUT);
pinMode(p2,OUTPUT);
pinMode(PWMoutput,OUTPUT); 
}


void loop() {
  digitalWrite(p2,LOW);
  digitalWrite(p1,HIGH);
  analogWrite(PWMoutput,dutyCycle);
  Runtime++;
  
  }
  
  

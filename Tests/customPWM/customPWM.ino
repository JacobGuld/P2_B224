
const int motor1pwm = 6;
const int in1 = 2;
const int in2 = 3;

const int kpin = 18;
volatile unsigned int count;
int d = 10;
long time = 0;
long speed = 0;
long last = 0;

void initializePWM(){
  cli();
  // sets TCCR5A register to fast PWM mode 9bit (WGM0 and WGM1, still needs to set WGMS in register B)and enables all coms
  TCCR4A = 0b10101010;
  // set TCCR5B for no prescaling, sets last WGM for pwm mode 10 bit.
  TCCR4B = 0b00001010;
  OCR4A = 0;
  OCR4B = 0;
  OCR4C = 0;
  sei();
  // formula for calculating PWM frequenzy can be found on page 160 sometihin in the atmega2560 datasheet, it's set for 32kHz
}
//sets the duty cycle of the PWM
void setPWM(int pwm1, int pwm2){
  cli();
  OCR4A = round(pwm1);//OCR4A is connectet to pin 6, we dont wan't doubles as dutycyles...
  OCR4B = round(pwm2);//OCR4B is connectet to pin 7
  // if we want to use OCR4C it's pin 8
  sei();
}//set the pwm mode for 512bit 32kHz

void setup() {
  // put your setup code here, to run once:

  initializePWM();
  setPWM(128, 255); 
  pinMode(motor1pwm, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT); 

  pinMode(kpin, INPUT);
attachInterrupt(digitalPinToInterrupt(kpin), counts, CHANGE);
Serial.begin(115200); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH); 

  
  if(count > 1 ){
     speed = micros()-time;
     time = micros();
     last = millis();
     Serial.println(speed);
     count = 0;
  }
  else if (millis() > d + last){
    last = millis();
    speed = 0;
    Serial.println(speed);
    time = micros();
    count = 0;
  }
 
}



void counts(){
  count ++ ;

}



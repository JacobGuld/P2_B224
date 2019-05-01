void Drive() { // Function to setup the HBridge, making it able to drive
  digitalWrite(HBroPin2, LOW);
  digitalWrite(HBroPin1, HIGH);
  analogWrite(PWMoutput, Speed);
}

void STOP() { //Function sets the speed to 0
  Speed = 0;
  Drive();
}

void SystemDrive() { //Main function to drive
  if (digitalRead(YButton) == LOW) { //Checks if Yellow button is press
    delay(100);
    while (digitalRead(BButton) != LOW) { //While Blue button is not pressed
      Distance = sensor.readRangeContinuousMillimeters(); //gets the distance and store in Distance
      if (Distance > 50) { // if distance > the wished value, then drive forward
        Speed = 50;
        Drive();
        delay(10);
      }
      else if (Distance <= 50) {// if distance is under or equal to the wished value, then drive set the speed to 0
        Speed = 0;
        Drive();
        delay(10);
      }
    }
    STOP(); //stop when blue is pressed
  }
}

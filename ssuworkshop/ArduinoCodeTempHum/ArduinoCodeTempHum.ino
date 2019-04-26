#include <dht.h>
dht DHT;
#define DHT11_PIN 7 

/*Code designed by Sujay Alaspure in SA Lab */

const int sensor=A5; // Assigning analog pin A5 to variable 'sensor'
float tempc; //variable to store temperature in degree Celsius
float vout; //temporary variable to hold sensor reading

void setup() {

pinMode(sensor,INPUT); // Configuring sensor pin as input
Serial.begin(9600);

}

void loop() {

int chk = DHT.read11(DHT11_PIN); 
vout=analogRead(sensor); //Reading the value from sensor
//vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
Serial.print("<T");Serial.print(tempc);Serial.print(">");
Serial.print("<H");Serial.print(DHT.humidity, 1);Serial.print(">");
//Serial.println();
delay(500); //Delay of 1 second for ease of viewing 
}

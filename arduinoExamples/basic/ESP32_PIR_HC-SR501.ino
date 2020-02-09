/**
 * Sensor PIR HC-SR501
 * 
 *  Author: Mael T.
 *  Date: 18/01/2020
 *  
 *  PINOUT
 *  ======
 *  GND:GND
 *  Vcc:+5v
 *  OUT:D4
 */

const int ledPin = 2;                // choose the pin for the LED
int inputPin = 4;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(115200);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  
  if (val == HIGH)  // check if the input is HIGH
  {            
    digitalWrite(ledPin, HIGH);  // turn LED ON
  
    if (pirState == LOW) 
  {
      Serial.println("Motion detected!"); // print on output change
      pirState = HIGH;
    }
  } 
  else 
  {
    digitalWrite(ledPin, LOW); // turn LED OFF
  
    if (pirState == HIGH)
  {
      Serial.println("Motion ended!");  // print on output change
      pirState = LOW;
    }
  }
}

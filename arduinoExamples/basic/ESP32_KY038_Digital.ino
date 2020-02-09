/**
 * Sound sensor DIGITAL
 * 
 *  Author: Mael T.
 *  Date: 18/01/2020
 *   
 *  PINOUT
 *  =====
 *  G: GND
 *  +: 5v
 *  A0:- 
 *  D0: D4 as digital input
 */
 
const int pinLED = 2; 
const int pinMicrophone = 4;
bool state;
 
void setup()
{
  pinMode(pinLED, OUTPUT);
  pinMode(pinMicrophone, INPUT_PULLUP);
  Serial.begin(115200);

}
 
void loop()
{
  bool soundDetected = digitalRead(pinMicrophone);
  Serial.println(soundDetected);
  if (soundDetected == true)
  {
    state = ! state;    
    digitalWrite(pinLED , state);
    delay (1000);
  }
  delay(100);
}

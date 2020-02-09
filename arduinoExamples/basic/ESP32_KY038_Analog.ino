/**
 * Sound sensor ANALOG
 *  
 *  Author: Mael T.
 *  Date: 18/01/2020
 *  
 *  PINOUT
 *  =====
 *  G: GND
 *  +: 5v
 *  A0:D4 as analog input
 *  D0: -
 */
const int pinMicrophone = 4;
 
void setup()
{
  Serial.begin(115200);
}
 
void loop()
{
  int soundDetected = analogRead(pinMicrophone);
  Serial.println(soundDetected);
  delay(500);
}

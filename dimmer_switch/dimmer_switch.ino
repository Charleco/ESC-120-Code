/*
  SparkFun Inventor’s Kit
  Circuit 1C-Photoresistor

  Use a photoresistor to monitor how bright a room is, and turn an LED on when it gets dark.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

            
int threshold = 750;               
int lightLevel = 0;

// Photoresistor pin
int lightPin = 0;
// LED pin
int ledPin = 9;
void setup() {
pinMode(ledPin, OUTPUT);
}
void loop() {
lightLevel = analogRead(A0);
lightLevel = map(lightLevel, 0, 1023, 0, 255);

lightLevel = constrain(lightLevel, 0, 255);
analogWrite(9, lightLevel);

}

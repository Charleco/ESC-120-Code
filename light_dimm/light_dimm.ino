
int lightPin = 0;
int ledPin = 9;
void setup() {
pinMode(ledPin, OUTPUT);
}
void loop() {
lightLevel = analogRead(A0);
if (lightLevel > 300 ) {
  digitalWrite(ledPin, LOW);
} else {
  digitalWrite(ledPin, HIGH);
}
}

int red = 10;
int yellow = 9;
int green = 8;
int button = 12;


void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(button, INPUT);
  digitalWrite(green, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  changeLights();
  delay(15000);
}
digitalWrite();




int xpin = 23;
int value = 0;
int ledpin = 39;
void setup() 
{
  Serial.begin(9600);
  pinMode(40, OUTPUT);
  pinMode(xpin, INPUT_PULLUP);
}

void loop() 
{
  
  value = analogRead(xpin);
  Serial.println(value);
  value = map(value, 0, 4096, 250, 1500);
  tone(40, value, 60);

  
}

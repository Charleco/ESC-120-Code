
//notes
#define note_a 440
#define note_cH 150
#define note_ff 349
// stick x pin
int stickx = 2;
// stick x position
int stickxpos = 0;
void beep(int note, int duration)
{
  tone(40, note, duration/2);
  delay(duration/2);
  noTone(40);
  delay(duration/2 + 20);  
}
void setup() 
{
//buzzer pin output
pinMode(40,OUTPUT);
//joystick input
pinMode(2, INPUT_PULLUP); 
//print to monitor to see variable value
Serial.begin(9600);

}

void loop() 
{
Serial.println(stickxpos);
//read x pos
stickxpos = analogRead(stickx);
// change input
stickxpos = map(stickxpos, 0, 4096, 120, 1500);
tone(40, stickxpos, 60);
delay(1);

}

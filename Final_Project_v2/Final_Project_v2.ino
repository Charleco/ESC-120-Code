#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif

#include "SPI.h"
#include "Screen_HX8353E.h"
Screen_HX8353E myScreen;

//joystick x position and pin
int stickx = 2;
int stickxpos = 0;
//joystick y position and pin
int sticky = 26;
int stickypos = 0;
// draw button
int button = 32;
// cursor size button and state
int cursor = 0;
 int cursor_button = 33;
//gyro pin
int gyro = 23;

void setup() {
  
  Serial.begin(9600);
  myScreen.begin();

  analogReadResolution(12);
  
  pinMode(button, INPUT_PULLUP);
  pinMode(stickx, INPUT_PULLUP);
  pinMode(sticky, INPUT_PULLUP);
  myScreen.setPenSolid(true);
  myScreen.dRectangle(0,0,128,128,myScreen.calculateColour(102,255,102));
}

void loop() {

  stickxpos = map(analogRead(stickx), 0, 4096, 0, 128);
  stickypos = map(analogRead(sticky), 0, 4096, 128, 0);

  if(stickxpos < 1) stickxpos=1;
  if(stickxpos > 126) stickxpos=126;
  if(stickypos < 1) stickypos = 1;
  if(stickypos > 126) stickypos = 126;

  //change cursor size
  if(!digitalRead(cursor_button))
  {
    cursor = cursor + 1;
    delay(100);
    if(cursor >= 3)
    {
      cursor = 0;
    }
  }
  Serial.println(cursor);
  //if button is pressed draw at point
  if(!digitalRead(button))
  {
   if (cursor == 0)
    {
    myScreen.dRectangle(stickxpos-1, stickypos-1, 2, 2, blackColour);      
    }
   if (cursor == 1)
   {
    myScreen.dRectangle(stickxpos-1, stickypos-1, 6, 6, blackColour);    
   }
   if (cursor == 2)
   {
    myScreen.dRectangle(stickxpos-1, stickypos-1, 15, 15, blackColour);    
   }

  }

  int gyrox= analogRead(gyro);

  if((gyrox<1300) || (gyrox>2800))
  {
    myScreen.dRectangle(0,0,128,128,myScreen.calculateColour(102,255,102));
  }
    
}

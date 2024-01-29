#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif


#include <SPI.h>

#include <LCD_screen.h>
#include <LCD_screen_font.h>
#include <LCD_utilities.h>
#include <Screen_HX8353E.h>
#include <Terminal12e.h>
#include <Terminal6e.h>
#include <Terminal8e.h>
Screen_HX8353E myScreen;


int sticky = 26;
int stickystate = 0;
int count = 0;
int buttonOne = 33;
int buttonOneState = 0;
int buttonTwo = 32;
int buttonTwoState = 0;
void setup() {
    Serial.begin(9600);
    delay(100);
    
    
    myScreen.begin();
    String s = myScreen.WhoAmI();
    myScreen.setOrientation(0);


    pinMode(26, INPUT_PULLUP);      
    pinMode(33, INPUT_PULLUP);
}

void loop() {
  myScreen.dRectangle(32, 32, 64, 64, whiteColour); 
  myScreen.setFontSize(8);
  myScreen.gText(56, 60, String(count), whiteColour, blackColour, 2, 2);
  buttonOneState = digitalRead(buttonOne);
  buttonTwoState = digitalRead(buttonTwo); 
  stickystate = analogRead(sticky);
  stickystate = map(stickystate, 0 ,4096, 0, 100);
  Serial.println(stickystate);
  if(count > 98)
  {
    delay(100);
    count = 0;
  }
  if(count < -98)
  {
    count = 0;
  }
  if (stickystate < 12)
  {
    count = count - 1;
    
  }
  if (stickystate > 12)
  {
    count = count + 1;
    
  }
  if(buttonOneState == LOW)
  {
    count = count + 1;
    delay(100);
  }
  if(buttonTwoState == LOW)
  {
    count = count - 1;
    delay(100);
  }
  
}

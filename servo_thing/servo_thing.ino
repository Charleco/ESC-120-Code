#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif
#include <Servo.h>

#include <SPI.h>

#include <LCD_screen.h>
#include <LCD_screen_font.h>
#include <LCD_utilities.h>
#include <Screen_HX8353E.h>
#include <Terminal12e.h>
#include <Terminal6e.h>
#include <Terminal8e.h>
Screen_HX8353E myScreen;

int stick_x = 2;
int stick_x_state = 0;
int servo_pos = 0;
Servo myservo; 
void setup() {
    analogReadResolution(12); 
    myservo.attach(19);
    myScreen.begin();
    String s = myScreen.WhoAmI();
    myScreen.setOrientation(0);

    pinMode(stick_x, INPUT_PULLUP);


}

void loop() {
  
  myScreen.dRectangle(32, 32, 64, 64, whiteColour); 
  myScreen.setFontSize(8);
  
  
  
  stick_x_state = analogRead(stick_x);
  servo_pos = map(stick_x_state, 0 ,4096,20, 160);
  if(servo_pos < 100)
  {
  myScreen.gText(56, 60, 0 + i32toa(servo_pos % 100) , whiteColour, blackColour, 2, 2);
  }
  else
  {
    myScreen.gText(56, 60, i32toa(servo_pos) , whiteColour, blackColour, 2, 2);
  }
delay(100);
  myservo.write(servo_pos);
  

}

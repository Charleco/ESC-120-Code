#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif

#include "SPI.h"
#include "Screen_HX8353E.h"
Screen_HX8353E myScreen;


int stickx = 2;
int stickxpos = 0;

int sticky = 26;
int stickypos = 0;
int button = 32;

int gyro = 23;

int grid [16][16];

void setup() {
  
  Serial.begin(9600);
  myScreen.begin();

  analogReadResolution(12);
  
  
  pinMode(button, INPUT_PULLUP);
  pinMode(stickx, INPUT_PULLUP);
  pinMode(sticky, INPUT_PULLUP);
  myScreen.setPenSolid(true);
  myScreen.dRectangle(0,0,128,128,whiteColour);
  myScreen.setPenSolid(false);
}

void loop() {
  //system largely uses drawing system from JoystickDrawColor
  stickxpos = map(analogRead(stickx), 0, 4096, 0, 128);
  stickypos = map(analogRead(sticky), 0, 4096, 128, 0);

  if(stickxpos < 1) stickxpos=1;
  if(stickxpos > 126) stickxpos=126;
  if(stickypos < 1) stickypos = 1;
  if(stickypos > 126) stickypos = 126;

  //draw backround
  myScreen.setPenSolid(true);
  

  //if button is pressed draw at point
  
  if(!digitalRead(button)){
    myScreen.dRectangle(stickxpos-1, stickypos-1, 8, 8, redColour);
  }

  int gyrox= analogRead(gyro);
  Serial.println(gyrox);
  if((gyrox<1300) || (gyrox>2800))
  {
    myScreen.setPenSolid(true);
    myScreen.dRectangle(0,0,128,128,whiteColour);
    myScreen.setPenSolid(false);
  }
  
  
  delay(100);
  
}

// Simple example application that shows how to read four Arduino
// digital pins and map them to the USB Joystick library.
//
// Ground digital pins 9, 10, 11, and 12 to press the joystick 
// buttons 0, 1, 2, and 3.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2015-11-20
//--------------------------------------------------------------------

#include <Joystick.h>
//#include <RotaryEncoder.h>

Joystick_ Joystick;

int buttonPin1 = 1;
int ledPin1 = A0;

int buttonPin2 = 2;
int ledPin2 = A1;

int buttonPin3 = 3;
int ledPin3 = A2;

int buttonPin4 = 4;
int ledPin4 = 11;

int buttonPin5 = 5;
int ledPin5 = A4;

int buttonPin6 = 6;
int ledPin6 = A5;

int buttonPin7 = 7;
int ledPin7 = 0;

int buttonPin8 = 8;
int ledPin8 = 12;

//int buttonPin9 = 10;

//int rotIntPin0 = 9;
//int rotIntPin1 = 13;

//Define Encoders
// RotaryEncoder encoder(rotIntPin0,rotIntPin1);


void setup() {
  // Initialize Button Pins
  pinMode(1,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
 // pinMode(9,INPUT_PULLUP);
 // pinMode(10,INPUT_PULLUP);
 // pinMode(13,INPUT_PULLUP);
  pinMode(0, OUTPUT);
  pinMode(A0, OUTPUT);  
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(12, OUTPUT);  

  // Initialize Joystick Library
  Joystick.begin();
 // attachInterrupt(digitalPinToInterrupt(rotIntPin0), getTick1, CHANGE);
 // attachInterrupt(digitalPinToInterrupt(rotIntPin1), getTick1, CHANGE);
}

//void getTick1(){
//  encoder.tick();    
//}


// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 1;
int toggleState = false;

// Last state of the button
int lastButtonState[8] = {0,0,0,0,0,0,0,0};

void loop() {

   // static int pos = 0;  
   // static int pos2 = 0;  
    
   //int newPos = encoder.getPosition();
   
  // Read pin values
  for (int index = 0; index < 8; index++)
   
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
   
  {
   if (digitalRead(buttonPin1) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin1, toggleState);
        }
    while (digitalRead(buttonPin1) == false);
    //delay(50);

    if (digitalRead(buttonPin2) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin2, toggleState);
        }
    while (digitalRead(buttonPin2) == false);
    //delay(50);

    if (digitalRead(buttonPin3) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin3, toggleState);
        }
    while (digitalRead(buttonPin3) == false);
    //delay(50);

    if (digitalRead(buttonPin4) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin4, toggleState);
        }
    while (digitalRead(buttonPin4) == false);
    //delay(50);
    
    if (digitalRead(buttonPin5) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin5, toggleState);
        }
    while (digitalRead(buttonPin5) == false);
    //delay(50);

    if (digitalRead(buttonPin6) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin6, toggleState);
        }
    while (digitalRead(buttonPin6) == false);
    //delay(50);

    if (digitalRead(buttonPin7) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin7, toggleState);
        }
    while (digitalRead(buttonPin7) == false);
    //delay(50);

    if (digitalRead(buttonPin8) == false) {
        toggleState = !toggleState;
        digitalWrite(ledPin8, toggleState);
        }
    while (digitalRead(buttonPin8) == false);
    //delay(50);
    
  }
  delay(50);
}

#include <Servo.h>
Servo servoOpenClose; //Declare Open+Close servo
Servo servoUpDown;    //Declare Up+Down servo
int val = 0;      //read value
int ledPin = 13;  //LED connected to D13

//Counters
int closeCount = 0;
int closeState = 0;
int closeLastState = 0;

int openCount = 0;
int openState = 0;
int openLastState = 0;

int upCount = 0;
int upState = 0;
int upLastState = 0;

int downCount = 0;
int downState = 0;
int downLastState = 0;

//Input pins
int closePin = 7; //close input
int openPin = 6;  //open input
int upPin = 4;    //up input
int downPin = 5;  //down input

//Outuput pins
//int openclose = 10; //Open+Close output
//int updown = 11;    //Up+Down output
void setup() {
  pinMode(closePin, INPUT); //D7 input
  pinMode(openPin, INPUT);  //D6 input
  pinMode(upPin, INPUT);    //D4 input
  pinMode(downPin, INPUT);  //D5 input
  
  //pinMode(openclose, OUTPUT);  //D10 output
  //pinMode(updown, OUTPUT);  //D11 output
  pinMode(ledPin, OUTPUT);  //D13 output

  servoOpenClose.attach(10);  //Attach to pin 10
  servoUpDown.attach(11);     //Attach to pin 11

}

void loop() {
  /*
  //Turn LED on when "shut/close" is on
  val = digitalRead(closePin);  //val = close status
  digitalWrite(ledPin, val);
  */
  /*--------Edge Detection--------*/
  //close
  closeState = digitalRead(closePin);
  if (closeState != closeLastState){
    if (closeState == HIGH){
      //if switch on
      servoOpenClose.write(0);
    }
    else if (closeState == LOW){
      //if switch off
      //digitalWrite(ledPin, LOW);
    }
    delay(10);
  }
  closeLastState = closeState;  //Save current as last
 
  //open
  openState = digitalRead(openPin);
  if (openState != openLastState){
    if (openState == HIGH){
      //if switch on
      servoOpenClose.write(180);
    }
    else if (openState == LOW){
      //if switch off
      //digitalWrite(ledPin, LOW);
    }
    delay(10);
  }
  openLastState = openState;  //Save current as last

  //up
  upState = digitalRead(upPin);
  if (upState != upLastState){
    if (upState == HIGH){
      //if switch on
      //digitalWrite(ledPin, HIGH);
    }
    else if (upState == LOW){
      //if switch off
      //digitalWrite(ledPin, LOW);
    }
    delay(10);
  }
  upLastState = upState;  //Save current as last

  //down
  downState = digitalRead(downPin);
  if (downState != downLastState){
    if (downState == HIGH){
      //if switch on
      //digitalWrite(ledPin, HIGH);
    }
    else if (downState == LOW){
      //if switch off
      //digitalWrite(ledPin, LOW);
    }
    delay(10);
  }
  downLastState = downState;  //Save current as last

}

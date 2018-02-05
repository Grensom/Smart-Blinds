
#include <Servo.h>

Servo hi1; //360
Servo hi2; //180

Servo goup;
Servo godown;

int pos = 0;
int val = 0;
int val2 = 0;
int up = 580; //pot read for up
int down = 640; //pot read for down
int count = 0; //start up blink count

void setup() {
  goup.attach(11);
  godown.attach(6);
  goup.write(0);
  godown.write(180);
  
  Serial.begin(9600);
  hi2.attach(10); //open, close
  pinMode(12, OUTPUT); //Red LED
  pinMode(13, OUTPUT); //Green LED
  //delay 10 second to allow the ESP8266 to boot up
  for(count = 0; count < 12; count++){
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
  }
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}

// Comment out the operation(function) that is not required

void loop() {
  //servo180();
  //servo360();
  //cont_rot();
  //windowsup_down();
  //capstone_test();
  finalCAP();
}

void finalCAP(){
  int val0 = analogRead(0); //up
  int val1 = analogRead(1); //down
  int val2 = analogRead(2); //open
  int val3 = analogRead(3); //close
  if (val0 > 600){
    digitalWrite(12, HIGH); //turn on Red LED (operating)
    blindsup();
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH); //turn on Green LED ( finished operating)
    delay(2000);
    digitalWrite(13, LOW);
  }
  else if (val1 > 600){
    digitalWrite(12, HIGH); //turn on Red LED
    blindsdown();
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
  }
  else if (val2 > 600){
    digitalWrite(12, HIGH); //turn on Red LED
    blindsopen();
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
  }
  else if (val3 > 600){
    digitalWrite(12, HIGH); //turn on Red LED
    blindsclose();
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
  }
}

void blindsup(){
  hi1.attach(9);
  pos = analogRead(4);
  while(pos < up){
    hi1.write(0); //9
    pos = analogRead(4);
    Serial.println(pos);
  }
  hi1.write(90);
  hi1.detach();
}
void blindsdown(){
  hi1.attach(9);
  pos = analogRead(4);
  while(pos > down){
    hi1.write(180);
    pos = analogRead(4);
    Serial.println(pos);
  }  
  hi1.write(90);
  hi1.detach();
}
void blindsopen(){
    hi2.write(90); //10
    delay(1000);
}
void blindsclose(){
    hi2.write(180);
    delay(1000);
}

//////////////////////////////////////////// EXTRA MODULES //////////////////////////////////////////////////////////////////////////////

void servo180() {
  for (val = 0; val < 180; val++) {
    hi1.write(val);
    delay(15);
  }
  delay(2000);
  for (val = 180; val > 0; val--) {
    hi1.write(val);
    delay(15);
  }
  delay(4000);
}

void servo360() {
  hi1.write(0);
  delay(2000);
  hi1.write (90);
  delay(2000);
  hi1.write(180);
  delay(2000);
  hi1.write(90);
  delay(4000);
}

void cont_rot() {
  // comment out one for direction

  hi1.write(0); //DOWN 9
  hi2.write(180); //UP 10
  //hi2.write(0); //DOWN 10
  //hi1.write(180); //UP 9
}

void windowsup_down() {
  pos = analogRead(0);
  if (pos >= up) {
    while (pos > down) {
      hi1.write(180);
    }
  }
  if (pos <= 0) {
    while (pos < up) {
      hi1.write(0);
    }
  }
}

void capstone_test(){
  val = analogRead(1); //up
  val2 = analogRead(2); //down
  if(val > 600){
    pos = analogRead(0);
    if(pos <= down){  //if down go up
      while (pos < up) {
      hi1.write(0);
      }
    }
  }
  if(val2 > 600){
    pos = analogRead(0);
    if(pos >= up){  //if up go down
      while (pos > down) {
      hi1.write(180);
      }
    }
  }
}

void testup(){
    hi1.attach(9);
    hi1.write(0);
    delay(2000);
    hi1.write(90);
    hi1.detach();
}

void testdown(){
    hi1.attach(9);
    hi1.write(180);
    delay(2000);
    hi1.write(90);
    hi1.detach();
}


#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(11, OUTPUT); 
  //LED-Red
  pinMode(10, OUTPUT); 
  //LED-Green
}

void loop() {
  val = analogRead(potpin);            
  // Potentiometer 0-1023
  val = map(val, 0, 1023, 15, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(5);
  if(val <= 20){
    digitalWrite(10, LOW);   
    //LED-G-off
    digitalWrite(11, HIGH);   
    //LED-R-on
  }
  if(val>= 160){
    digitalWrite(11, LOW);   
    //Vice Versa
    digitalWrite(10, HIGH);  
    //Vice Versa
  }
}

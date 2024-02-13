/*
This code is used to control the gripper of GOFA robot
The target arduino board is the Nano v3
Author: edwinDOS
*/

// Incluímos la librería para poder controlar el servo
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int ledPin = 13;  // LED connected to digital pin 13
int inPin = 4;    // robot output 1 connected to digital pin D4 (pin 7)
//int inPin2 = 5;    // robot output 2 connected to digital pin D5 (pin 8)
int closeDI1 = 0;      // variable to store the read value

void setup() {
  
  myservo.attach(8); // Iniciamos el servo para que empiece a trabajar con el pin D8 como salida PWM
  pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(inPin, INPUT_PULLUP);    // sets the digital pin D4 as input
  //pinMode(inPin2, INPUT_PULLUP);    // sets the digital pin D5 as input
  // initialize serial communication:
  //Serial.begin(9600); // Uncomment to debug by console
}

void loop() {

  closeDI1 = digitalRead(inPin);   // read the input from the robot via DI1 signal
  digitalWrite(ledPin, closeDI1);  // sets the LED to the DI1's value
  //Serial.print(closeDI1);

  if (closeDI1 == HIGH){
    myservo.write(0); // move the servo to close position
  } 
  else {
    myservo.write(100); // move the servo to open position
  }

}

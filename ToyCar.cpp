#include <IRremote.h>
#include <DIYables_IRcontroller.h>
#include <HCSR04.h>    debug tc  


//HCSR04 hc(9, 8); //initialisation class HCSR04 (trig pin , echo pin)   debug tc

int irPin = 9;            //Arduino pin connected to IR receiver
IRrecv irRecive(irPin);
decode_results results;

//left motor
int in1 = 6;
int in2 = 5;
int enA = 7;

//right motor
int in3 = 4;
int in4 = 3;
int enB = 2;

  //analogWrite(leftMotorSpeedPin, i);
  //analogWrite(rightMotorSpeedPin, i);

void setup() {
  Serial.begin(9600);      
  irRecive.enableIRIn();   //debug tc

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(enA, HIGH);  //for full speed
  digitalWrite(enB, HIGH);  //for full speed
  
  goForward();   //debug tc erase later
  stop();
  goBackward();  
  goForward();

}

//for testing
void loop() {
  // Move forward for 1.5 seconds at full speed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);  // Full speed
  analogWrite(enB, 255);
  delay(1500);

  // Stop for 0.5 seconds
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  delay(500);

  // Move backward for 1.5 seconds at full speed
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);  // Full speed
  analogWrite(enB, 255);
  delay(1500);

  // Stop for 0.5 seconds
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  delay(500);
}

//testing forward/backward
void continueForwardOrBackward() {
  if (direction == 1) {
    goForward();
  } else if (direction == 2) {
    goBackward();
  } else {
    stop();
  }
}



/*  
////for testing motors and pins//////

void setup(){
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH); //move forward for 1.5 seconds
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 100);
  digitalWrite(enB, 100);
  delay(500);


  digitalWrite(in1, LOW); //stop for 0.5 seconds
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enB, 0);
  delay(500);

  digitalWrite(in1, LOW); //Move backwards for 1.5 seconds
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 100);
  digitalWrite(enB, 100);
  delay(1500);

  digitalWrite(in1, LOW); //stop for 0.5 seconds
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enB, 0);
  delay(500);

 return 0;

  }


void loop(){

  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH); //move forward for 1.5 seconds
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 100);
  digitalWrite(enB, 100);
  delay(500);


  digitalWrite(in1, LOW); //stop for 0.5 seconds
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enB, 0);
  delay(500);

  digitalWrite(in1, LOW); //Move backwards for 1.5 seconds
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 100);
  digitalWrite(enB, 100);
  delay(1500);

  digitalWrite(in1, LOW); //stop for 0.5 seconds
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enB, 0);
  delay(500);

 return 0;

}
//////testing over//////
*/

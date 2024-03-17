#include <IRremote.h>
//#include <HCSR04.h>    debug tc

//HCSR04 hc(9, 8); //initialisation class HCSR04 (trig pin , echo pin)   debug tc

int irPin = 7;
IRrecv irRecive(irPin);
decode_results results;

// left motor
int leftMotorSpeedPin = 3;
int leftMotorForwardPin = 4;
int leftMotorBackwardPin = 5;

// right motor
int rightMotorSpeedPin = 11;
int rightMotorForwardPin = 12;   //purple problem tc
int rightMotorBackwardPin = 13;

int direction = 0; //0 = stop, 1 = forward, 2 = bakward


void setup() {
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorBackwardPin, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);
  pinMode(rightMotorBackwardPin, OUTPUT);

  digitalWrite(leftMotorSpeedPin, HIGH);
  digitalWrite(rightMotorSpeedPin, HIGH);

  //analogWrite(leftMotorSpeedPin, i);
  //analogWrite(rightMotorSpeedPin, i);

  Serial.begin(9600);      
  //irRecive.enableIRIn();   //debug tc

  //goForward();   //debug tc erase later
  stop();
  goBackward();  
  //goForward();
}

void loop() {

  //Serial.println(hc.dist()); // return curent distance in serial   debug tc
  delay(60);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.

} //end of loop

void goForward() {
  Serial.println("goForward() function called");
  digitalWrite(leftMotorForwardPin, HIGH);   
  digitalWrite(leftMotorBackwardPin, LOW);    
  digitalWrite(rightMotorForwardPin, HIGH);     
  digitalWrite(rightMotorBackwardPin, LOW);    
  direction = 1;
}

void goBackward() {
  Serial.println("goBackward() function called");
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
  direction = 2;
}

void goRight() {
  Serial.println("goRight() function called");
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
}

void goLeft() {
  Serial.println("goLeft() function called");
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
}

void stop() {
  Serial.println("stop() function called");
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
  direction = 0;
}

void continueForwardOrBackward() {
  if (direction == 1) {
    goForward();
  } else if (direction == 2) {
    goBackward();
  } else {
    stop();
  }
}
/////////

#include <IRremote.h>
#include <HCSR04.h>    debug tc  


HCSR04 hc(9, 8); //initialisation class HCSR04 (trig pin , echo pin)   debug tc


/*
int in1 = 2;
int in2 = 4;
int enA = 3;

int in3 = 5;
int in4 = 7;
int enB = 6;
*/

/*

//IRrecv irRecive(irPin);
decode_results results;

// left motor
int leftMotorSpeedPin = 3;
int leftMotorForwardPin = 4;
int leftMotorBackwardPin = 2;

// right motor
int rightMotorSpeedPin = 6;
int rightMotorForwardPin = 7;   //purple problem tc
int rightMotorBackwardPin = 5;

int direction = 1; //0 = stop, 1 = forward, 2 = bakward



void setup() {
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorBackwardPin, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);
  pinMode(rightMotorBackwardPin, OUTPUT);

  digitalWrite(leftMotorSpeedPin, HIGH);
  digitalWrite(rightMotorSpeedPin, HIGH);

  //analogWrite(leftMotorSpeedPin, i);
  //analogWrite(rightMotorSpeedPin, i);

  Serial.begin(9600);      
  //irRecive.enableIRIn();   //debug tc

  goForward();   //debug tc erase later
  stop();
  goBackward();  
  goForward();
  


}

void loop() {

  Serial.println(hc.dist()); // return curent distance in serial    debug tc
  delay(5);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.





} //end of loop

void goForward() {
  Serial.println("goForward() function called");
  digitalWrite(leftMotorForwardPin, HIGH);   
  digitalWrite(leftMotorBackwardPin, LOW);    
  digitalWrite(rightMotorForwardPin, HIGH);     
  digitalWrite(rightMotorBackwardPin, LOW);    
  direction = 1;
}

void goBackward() {
  Serial.println("goBackward() function called");
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
  direction = 2;
}

void goRight() {
  Serial.println("goRight() function called");
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
}

void goLeft() {
  Serial.println("goLeft() function called");
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
}

void stop() {
  Serial.println("stop() function called");
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
  direction = 0;
}

void continueForwardOrBackward() {
  if (direction == 1) {
    goForward();
  } else if (direction == 2) {
    goBackward();
  } else {
    stop();
  }
}



*/
/*
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

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



/*
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
*/

// Define the motor pins
int in1 = 2;
int in2 = 4;
int enA = 3;

int in3 = 5;
int in4 = 7;
int enB = 6;

void setup() {
  // Set motor pins as OUTPUT
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  // Move forward for 3 seconds
  moveForward();
  delay(3000);

  // Move backward for 3 seconds
  moveBackward();
  delay(3000);
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(enA, 255);  // Assuming enA is a PWM pin, setting it to maximum value for full speed
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enB, 255);  // Assuming enB is a PWM pin, setting it to maximum value for full speed
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(enA, 255);  // Assuming enA is a PWM pin, setting it to maximum value for full speed
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enB, 255);  // Assuming enB is a PWM pin, setting it to maximum value for full speed
}




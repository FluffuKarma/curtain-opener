/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */

// Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(stepsPerRevolution, D1, D3, D2, D4);

char rx_byte=0;
bool turning = false;
bool cclockwise = false;

void setup() {
  // Set the speed to 5 rpm:
  myStepper.setSpeed(15);
  
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
  
    // check if a number was received
    if (rx_byte=='1') {
      Serial.println("turning");
      turning = true;
      cclockwise=false;
    }
    else if (rx_byte=='0'){
      Serial.println("Stopping");
      turning=false;
    }
    else if (rx_byte=='2'){
      Serial.println("reversing");
      turning = true;
      cclockwise=true;
      }
  }
  if(turning==true){
    if(cclockwise==false){
    myStepper.step(1);}
    else{myStepper.step(-1);}
    }
}

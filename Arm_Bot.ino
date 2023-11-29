/*
  Arm Bot 
  Justin C Kirk

  Makerinchief 
  www.makerinchief.com
  info@makerinchief.com

  Please read README.md for details

*/

#include <Servo.h>

Servo base, wrist, gripper;
int base_pin = 10;
int wrist_pin = 11;
int gripper_pin = 12;

// Used to keep track of each servo.
int base_position = 0;
int wrist_position = 0;
int gripper_position = 0;

// Use a timer to update the positions of each servo.
unsigned long servo_current = 0;
unsigned long servo_previous = 0;
unsigned long servo_interval = 25;


// The Arm Bot uses 3 potentiometers to for controls but potentiometer
// is a big word and hard to spell, 
// so we can call them controls and set up our variables as follows:

// Each potentiometer is connected to an Analog Pin on the Arduino.
int control_a_pin = 0;
int control_b_pin = 1;
int control_c_pin = 2;

int control_a_val = 0;
int control_b_val = 0;
int control_c_val = 0;

// Print the values for each control to the Serial Monitor.
void print_control_values() {
    Serial.print(control_a_val);
    Serial.print(" ");
    Serial.print(control_b_val);
    Serial.print(" ");
    Serial.print(control_c_val);
    Serial.println();

}

// Create timer variables to update our servos motors without using delays.
unsigned long current = 0;
unsigned long previous = 0;
unsigned long interval = 100;

void setup() {

  // Start serial monitor
  Serial.begin(9600);

  // Initialize all 3 servos
  base.attach(base_pin);
  wrist.attach(wrist_pin);
  gripper.attach(gripper_pin);
  delay(1000);

  base_position = 100;
  wrist_position = 90;
  gripper_position = 90;

  base.write(base_position);
  wrist.write(wrist_position);
  gripper.write(gripper_position);

  delay(1000);
  Serial.println("Arm Bot Ready!");
}

void loop() {

  // Use a timer instead of delay since delays are blocking.
  current = millis();
  servo_current = millis();

  if (current - previous > interval) {

    control_a_val = analogRead(control_a_pin);
    control_b_val = analogRead(control_b_pin);
    control_c_val = analogRead(control_c_pin);
    
    print_control_values();

    base_position = map(control_a_val, 0, 1023, 0, 179);
    wrist_position = map(control_b_val, 0, 1023, 0, 179);
    gripper_position = map(control_c_val, 0, 1023, 0, 179);
    previous = current;
  }
  
  if (servo_current - servo_previous >= servo_interval) {

    base.write(base_position);
    wrist.write(wrist_position);
    gripper.write(gripper_position);

    servo_previous = servo_current;
  }
}

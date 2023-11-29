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

int base_position = 0;
int wrist_position = 0;
int gripper_position = 0;

// Used to keep track of each servo.
// 0 == Base
// 1 = Write
// 2 = Gripper
int current_positions[] = { 0, 0, 0 };
// Servo Control

unsigned long servo_current = 0;
unsigned long servo_previous = 0;
unsigned long servo_interval = 25;

// void servos_move_arm(int *positions) {
// }

// void servos_move_base(int base_position) {
//   base.write(base_position);
// }

// void servos_move_wrist(int wrist_position) {
//   wrist.write(wrist_position);
// }

// void servos_move_gripper(int gripper_position) {
//   gripper.write(gripper_position);
// }

// Potentiometer Control

// The Arm Bot uses 3 potentiometers to for controls but potentiometer
// is a big word and hard to spell, 
// so we can call them controls and set up our variables as follows:

// Number of controls/potentiometers.
int control_count = 3;

// Each potentiometer is connected to an Analog Pin on the Arduino.
int control_a_pin = 0;
int control_b_pin = 1;
int control_c_pin = 2;

int control_a_val = 0;
int control_b_val = 0;
int control_c_val = 0;

// Create an array of these pin numbers to make for easy referencing later.
// int control_pins[] = { control_1_pin, control_2_pin, control_3_pin };


// Store the value of each control in an array.
// Index 0 == Base Control
// Index 1 == Wrist Control
// Index 2 == Gripper Control
// int control_vals[] = { 0, 0, 0 };

// When we want to read the values of the potentiometers,
// use a timer so we do not block the current code being run.
// unsigned long control_current = 0;
// unsigned long control_previous = 0;
// unsigned long control_interval = 100;

// Update the control values once every number of milliseconds given by
// control_interval.
// void update_controls() {
  
//   control_current = millis();

//   if (control_current - control_previous >= control_interval) {
//     read_controls();
//     control_previous = control_current;
//   }
// }

// Get the values for each of the controls.
// void read_controls() {
//   for (int i = 0; i < control_count; i++) {
//     control_vals[i] = analogRead(control_pins[i]);
//   }
// }

// Use map() to scale the control values to a range the servos can use.
// void map_control_values(int low_value, int high_value) {  
//   for (int i = 0; i < 3; i++) {
//     control_vals[i] = map(control_vals[i], 0, 1023, low_value, high_value);
//   }
// }

// Print the values for each control to the Serial Monitor.
void print_control_values() {
  // for (int i = 0; i < control_count; i++) {
  //   Serial.print(control_vals[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();
    Serial.print(control_a_val);
    Serial.print(" ");
    Serial.print(control_b_val);
    Serial.print(" ");
    Serial.print(control_c_val);
    Serial.println();

}

// Get the current value of each control and save it to the a given array of 
// // equal size.
// void get_control_values(int *values) {
//   for (int i = 0; i < 3; i++) {
//     values[i] = map(control_vals[i], 0, 1023, 0, 179);
//   }
// }




// Create timer variables to update our servos motors without using delays.
unsigned long current = 0;
unsigned long previous = 0;
unsigned long interval = 100;

void setup() {

  // Start serial monitor
  Serial.begin(9600);

  // Initialize all 3 servos
  // servos_init();

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
  delay(20);
}

void loop() {

  // Use a timer instead of delay since delays are blocking.
  current = millis();
  servo_current = millis();

  if (current - previous > interval) {

    // After every interval,
    // 

    // servos_update();

    // update_controls();
    // for (int i = 0; i < control_count; i++) {
    //   control_vals[i] = analogRead(control_pins[i]);
    // }

    // controls_map_values(current_positions);
    // print_current_positions();
    // servos_move_arm(current_positions);

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

void print_current_positions() {

  for (int i = 0; i < 3; i++) {
    Serial.print(current_positions[i]);
    Serial.print(" ");
  }

  Serial.println();
}

// Servo Control

#include <Servo.h>
Servo base, wrist, gripper;

int servo_count = 3;

int base_pin = 10;
int wrist_pin = 11;
int gripper_pin = 12;
int servo_pins[] = { base_pin, wrist_pin, gripper_pin };

int base_position = 0;
int wrist_position = 0;
int gripper_position = 0;

// Store the value of each position in an array.
// Index 0 == Base Position
// Index 1 == Wrist Position
// Index 2 == Gripper Position
int servo_positions[] = { 0, 0, 0 };

unsigned long servo_current = 0;
unsigned long servo_previous = 0;
long servo_interval = 25;

void setup_servos() {

  base.attach(base_pin);
  wrist.attach(wrist_pin);
  gripper.attach(gripper_pin);
  delay(1000);

  base.write(100);
  wrist.write(90);
  gripper.write(90);
  delay(20);
}

void servos_run() {
  servo_current = millis();
}

void servos_move_arm(int *positions) {
  if (servo_current - servo_previous >= servo_interval) {

    base.write(positions[0]);
    wrist.write(positions[1]);
    gripper.write(positions[2]);

    servo_previous = servo_current;
  }
}

void servos_move_base(int base_position) {
  base.write(base_position);
}

void servos_move_wrist(int wrist_position) {
  wrist.write(wrist_position);
}

void servos_move_gripper(int gripper_position) {
  gripper.write(gripper_position);
}

/*
  Arm Bot 
  Justin C Kirk

  Makerinchief 
  www.makerinchief.com
  info@makerinchief.com

  Please read README.md for details

*/

// Create timer variables to update our servos motors without using delays.
unsigned long current = 0;
unsigned long previous = 0;
unsigned long interval = 100;

// Used to keep track of each servo.
// 0 == Base
// 1 = Write
// 2 = Gripper
int current_positions[] = { 0, 0, 0 };

void setup() {

  // Start monitor to read various info
  Serial.begin(9600);

  // Initialize all 3 servos
  setup_servos();
}

void loop() {

  // Use a timer instead of delay since delay functions are blocking.
  current = millis();

  if (current - previous > interval) {

    servos_run();
    update_controls();

    controls_map_values(current_positions);
    print_current_positions();
    servos_move_arm(current_positions);

    previous = current;
  }
}

void print_current_positions() {

  for (int i = 0; i < 3; i++) {
    Serial.print(current_positions[i]);
    Serial.print(" ");
  }

  Serial.println();
}

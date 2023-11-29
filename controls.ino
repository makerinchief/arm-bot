// // Potentiometer Control

// // The Arm Bot uses 3 potentiometers to for controls but potentiometer
// // is a big word and hard to spell, 
// // so we can call them controls and set up our variables as follows:

// // Number of controls/potentiometers.
// int control_count = 3;

// // Each potentiometer is connected to an Analog Pin on the Arduino.
// int control_1_pin = 0;
// int control_2_pin = 1;
// int control_3_pin = 2;

// // Create an array of these pin numbers to make for easy referencing later.
// int control_pins[] = { control_1_pin, control_2_pin, control_3_pin };


// // Store the value of each control in an array.
// // Index 0 == Base Control
// // Index 1 == Wrist Control
// // Index 2 == Gripper Control
// int control_vals[] = { 0, 0, 0 };

// // When we want to read the values of the potentiometers,
// // use a timer so we do not block the current code being run.
// unsigned long control_current = 0;
// unsigned long control_previous = 0;
// unsigned long control_interval = 100;

// // Update the control values once every number of milliseconds given by
// // control_interval.
// void update_controls() {
  
//   control_current = millis();

//   if (control_current - control_previous >= control_interval) {
//     read_controls();
//     control_previous = control_current;
//   }
// }

// // Get the values for each of the controls.
// void read_controls() {
//   for (int i = 0; i < control_count; i++) {
//     control_vals[i] = analogRead(control_pins[i]);
//   }
// }

// // Use map() to scale the control values to a range the servos can use.
// void map_control_values(int low_value, int high_value) {  
//   for (int i = 0; i < 3; i++) {
//     control_vals[i] = map(control_vals[i], 0, 1023, low_value, high_value);
//   }
// }

// // Print the values for each control to the Serial Monitor.
// void print_control_values() {
//   for (int i = 0; i < control_count; i++) {
//     Serial.print(control_vals[i]);
//     Serial.print(" ");
//   }
//   Serial.println();
// }

// // Get the current value of each control and save it to the a given array of 
// // equal size.
// void get_control_values(int *values) {
//   for (int i = 0; i < 3; i++) {
//     values[i] = map(control_vals[i], 0, 1023, 0, 179);
//   }
// }


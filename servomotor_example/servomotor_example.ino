/**
 * @file motor_example.ino
 * @brief Example to move a servomotor.
 * @author Raul Perula-Martinez
 * Inf. Industrial II. Depto. Ing. Sistemas y Automatica
 */

#include <Servo.h>

// global variables

// servo data
Servo left_wheel;
int left_wheel_pin = 9;  // modify if necessary

// counter
int value = 0;
boolean turn = false;

// initialization
void setup()
{
  Serial.begin(9600);  // open serial port to 9600 bps
  Serial.flush();      // empty serial port

  // attaches the servo on pin selected to the servo object 
  left_wheel.attach(left_wheel_pin);
}

// main loop
void loop()
{
  // check transition
  if (!turn) {
    // increment
    value += 15;

    if (value == 255) {
      turn = true;
    }
  }
  else {
    // decrement
    value -= 15;

    if (value == 0) {
      turn = false;
    }
  }

  // sets the servo position according to the value
  Serial.print("Value: ");
  Serial.println(value);
  left_wheel.write(value);

  // waits for the servo to get there
  delay(1000);
}


/**
 * @file template.ino
 * @brief Template for arduino programs.
 * @author Raul Perula-Martinez
 * Inf. Industrial II. Depto. Ing. Sistemas y Automatica
 */

// global variables
boolean first_time = false;

// initialization
void setup()
{
  Serial.begin(9600);  // open serial port to 9600 bps
  Serial.flush();      // empty serial port
}

// main loop
void loop()
{
  if (first_time) {
    // print string "Hello World." ten times
    for (int i = 0; i < 10; i++) {
      print_hello_world();
    }

    // print finish and stop
    Serial.println("Finish.");
    
    // change first_time state
    first_time = false;
  }
}


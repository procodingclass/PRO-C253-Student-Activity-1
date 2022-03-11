

#define BUTTON_PIN 22  // ESP32 pin GIOP22 connected to button's pin
#define RELAY_PIN  18  // ESP32 pin GIOP27 connected to relay's pin

// The below are variables, which can be changed
int relay_state = LOW;  // the current state of relay
int button_state;       // the current state of button
int last_button_state;  // the previous state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set ESP32 pin to input pull-up mode
  pinMode(RELAY_PIN, OUTPUT);        // set ESP32 pin to output mode

  button_state = digitalRead(BUTTON_PIN);
}

void loop() {
  last_button_state = button_state;      // save the last state
  button_state = digitalRead(BUTTON_PIN);   // read new state

  if (last_button_state == HIGH && button_state == LOW) {
    Serial.println("The button is pressed");

    // toggle state of relay
    relay_state = !relay_state;

    // control relay arccoding to the toggled state
    digitalWrite(RELAY_PIN, relay_state);
  }
}

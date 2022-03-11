

#define BUTTON_PIN 22  
#define RELAY_PIN  18  

int relay_state = LOW;  
int button_state;       
int last_button_state;  

void setup() {
  Serial.begin(9600);                
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  pinMode(RELAY_PIN, OUTPUT);        

  button_state = digitalRead(BUTTON_PIN);
}

void loop() {
  last_button_state = button_state;      
  button_state = digitalRead(BUTTON_PIN);   

  if (last_button_state == HIGH && button_state == LOW) {
    Serial.println("The button is pressed");

  
    relay_state = !relay_state;
    digitalWrite(RELAY_PIN, relay_state);
  }
}

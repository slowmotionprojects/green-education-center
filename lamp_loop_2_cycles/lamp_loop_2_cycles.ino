int pinArray[] = {2,3,4,5,6,7,8,9}; // define the pins that will connect to the relays

int cycle1LengthMs = 12000;  // how long each lamp stays on in the first cycle
int cycle2LengthMs = 1000;   // how long each lamp stays on in the second cycle

void setup() {
  for (int i = 0; i < (sizeof(pinArray)/sizeof(int)); i++){
    pinMode(pinArray[i],OUTPUT);
    digitalWrite(pinArray[i], HIGH);    // initialise all relays to HIGH (light off)
  }
  digitalWrite(pinArray[0], LOW);       // except the first one
}


void loop() {
  // first cycle
  for (int i = 0; i < (sizeof(pinArray)/sizeof(int))-1; i++){
    delay(cycle1LengthMs);
    digitalWrite(pinArray[i], HIGH);    // turn off this relay
    digitalWrite(pinArray[i+1], LOW);   // turn on the next one
  }
  // loop exits when the last relay is on, we need to wait and reset the loop
  delay(cycle1LengthMs);
  digitalWrite(pinArray[(sizeof(pinArray)/sizeof(int))-1], HIGH);
  digitalWrite(pinArray[0], LOW);

  // second cycle
  for (int i = 0; i < (sizeof(pinArray)/sizeof(int))-1; i++){
    delay(cycle2LengthMs);
    digitalWrite(pinArray[i], HIGH);    // turn off this relay
    digitalWrite(pinArray[i+1], LOW);   // turn on the next one
  }
  delay(cycle2LengthMs);
  digitalWrite(pinArray[(sizeof(pinArray)/sizeof(int))-1], HIGH);
  digitalWrite(pinArray[0], LOW);
}

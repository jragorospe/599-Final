int buttonPin = 2;
int transByte;

void setup() {
  // Set up pin output for button
  pinMode(buttonPin, OUTPUT);
  transByte = 1;
  // Begin serial port for transmitting data
  Serial.begin(9600);
}

void loop() {

  // Simply check if button is pressed and send to serial port
  int bState = digitalRead(buttonPin);
  if(bState == HIGH) {
    Serial.println(transByte);
  }
}

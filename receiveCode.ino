int incomingByte = 0;
int smartPin = 2;
int winePin = 7;

void setup() {
  // Set's up the pin output for both relays
  pinMode(smartPin, OUTPUT);
  pinMode(winePin, OUTPUT);
  // Begin serial for communication to python script and rf receiver
  Serial.begin(9600);
}

void loop() {
  // Receive output coming from rf transmitter through serial port
  incomingByte = Serial.read();
  Serial.println(incomingByte);

  // Check if port is available and the signal was received
  if((Serial.available() > 0) && (incomingByte == 1) {

    // Switch relay from NO and turn on. Enables smart outlet (light).
    digitalWrite(smartPin, HIGH);
    delay(1000);

    // Switch relay for pump on for 5 seconds
    digitalWrite(winePin, HIGH);
    delay(5000);
    digitalWrite(winePin, LOW);
    
  }
}

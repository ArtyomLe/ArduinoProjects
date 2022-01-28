void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    switch(c) {
      case 'n':
      digitalWrite(13, HIGH);
      break;
      case 'f':
      digitalWrite(13, LOW);
      break;
    }
  }
}

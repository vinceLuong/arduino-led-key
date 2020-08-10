const int bbPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(bbPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while( ! Serial); //wait until serial is ready
  Serial.println("Ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
    {
      Serial.println("Number!");
    }
    if (ch == 'o')
    {
      Serial.println("Turning On");
      digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage LOW
      
    }
    if (ch == 'x')
    {
      Serial.println("Turning Off");
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      
    }
    if (ch == 'H') {
      if (digitalRead(bbPin) == HIGH) {
        Serial.println("Turning off BB!");
        digitalWrite(bbPin, LOW);    // turn the LED off by making the voltage LOW  
      }
      else {
      Serial.println("Turning on BB!");
      digitalWrite(bbPin, HIGH);    // turn the LED off by making the voltage LOW
      }
    }
  }

}

const int buttonPin = 2; 
const int LEDPin = 13; 

int buttonState; 
int lastButtonState = LOW;           //for debounce
unsigned long lastDebounceTime = 0;  //for debounce
unsigned long debounceDelay = 50;    //for debounce

void setup() {
  pinMode(buttonPin, INPUT); 
  pinMode(LEDPin, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  int analogValue = analogRead(A0)/4; 
//  int reading = digitalRead(buttonPin);
  buttonState = digitalRead(buttonPin);
  Serial.write(analogValue);  

  if (analogValue != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

  if (analogValue != buttonState) { 
    buttonState = analogValue; 
  
    if (buttonState == HIGH) {
      Serial.write(1);
      digitalWrite(LEDPin, HIGH); 
    }
  
    else {
    Serial.write(0); 
    digitalWrite(LEDPin, LOW); 
    }
    delay(100);
  }
  }
}

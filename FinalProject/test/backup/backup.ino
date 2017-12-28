//button pins with debounce code in
const int buttonPin = 2;    
const int ledPin = 13;      

int ledState = HIGH;         
boolean buttonState;             //reading from input
int lastButtonState = LOW;   //previous reading for debounce
int pot = A0; 
int potValue = 0;   
int scene1 = 5; 
int sceneX = 10;         


// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(pot); //testing purposes
  int reading = digitalRead(buttonPin);

//  if (potValue < 204) { 
//    Serial.write("scene1");
//  }
//  if (potValue >= 204 && potValue < 408) { 
//    Serial.write("scene2");
//    digitalWrite(ledPin, LOW);
//  }
//  if (potValue >= 408 && potValue < 612) { 
//    Serial.write("scene3");
//    digitalWrite(ledPin, LOW);
//  }
//  if (potValue >= 612 && potValue < 816) { 
//    Serial.write("scene4");
//    digitalWrite(ledPin, LOW);
//  }
//  if (potValue >= 816 && potValue < 1024) { 
//    Serial.write("scene5");
//    digitalWrite(ledPin, LOW);
//  }
  
  if (reading != lastButtonState) {
    // reset debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState) {
          Serial.write(scene1);
          digitalWrite(ledPin, LOW);
      }
      else {
        Serial.write(sceneX); 
        digitalWrite(ledPin, HIGH);
      }
      }
    }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

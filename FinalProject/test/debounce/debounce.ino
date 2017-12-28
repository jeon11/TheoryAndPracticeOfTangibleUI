//button pins with debounce code in
const int buttonPin = 2;    
const int ledPin = 13;      

int ledState = HIGH;         
int buttonState;             //reading from input
int lastButtonState = LOW;   //previous reading for debounce
int pot = A0; 
int potValue = 0;
int scene1 = 11; 
int scene2 = 22;
int scene3 = 33; 
int scene4 = 44; 
int scene5 = 55; 
int empty = 66;


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
  int potValue = analogRead(pot); 
  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    // reset debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == LOW) {
        if (potValue < 204) {
          Serial.write(scene1);
          digitalWrite(ledPin, LOW);
        }
        if ((potValue >= 204) && (potValue < 409)) {
          Serial.write(scene2);
          digitalWrite(ledPin, LOW);
        }
        if ((potValue >= 409) && (potValue < 614)) {
          Serial.write(scene3);
          digitalWrite(ledPin, LOW);
        }
        if ((potValue >= 614) && (potValue < 819)) {
          Serial.write(scene4);
          digitalWrite(ledPin, LOW);
        }
        if ((potValue >= 819) && (potValue < 1024)) {
          Serial.write(scene5);
          digitalWrite(ledPin, LOW);
        }
       
      }
     if (buttonState == HIGH) {
//      else {
        Serial.write(empty); 
        digitalWrite(ledPin, HIGH);
      }
      }
    }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

// Jin Jeon 
//Info C262 Lab 7
 
int motorPin = 9;
int potPin = A0;
int sensorPin_P1 = A1;   // Analogue input for Pot 0 that controls blinking speed
int blink_rate = 0;  // variable to store the value coming from the sensor
int potVal = 0;
int motorCtrlVal = 0;
int ledPin_G = 3;
int ledPin_R = 5;
int ledPin_B = 6;

void setup() {
  pinMode(ledPin_R, OUTPUT);
  pinMode(ledPin_B, OUTPUT);
  pinMode(ledPin_G, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");Serial.println(potVal);
  motorCtrlVal = map(potVal, 0, 1024, 0, 255);
  Serial.print("motorCtrlVal: ");Serial.println(motorCtrlVal);
  analogWrite(motorPin, motorCtrlVal);

  blink_rate = analogRead(sensorPin_P1);
  analogWrite(ledPin_R, 255);
  analogWrite(ledPin_G, 255);
  analogWrite(ledPin_B, 255);
  delay(blink_rate);
  analogWrite(ledPin_R, 0); 
  analogWrite(ledPin_G, 0);
  analogWrite(ledPin_B, 0);
  delay(blink_rate);
}

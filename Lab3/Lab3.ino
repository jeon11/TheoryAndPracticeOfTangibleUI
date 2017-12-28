/*
  Lab 3: Sensing Potentiometers
  Jin Jeon 
  Info C262 
*/

int sensorPin_P0 = A0;   // Analogue input for Pot 0 that controls blinking speed
int sensorPin_P1 = A1;   // Analogue input for Pot 1 that controls brightness of LEDs
int ledPin_R = 11;       // LED pin for Red
int ledPin_B = 10;       // LED pin for Blue
int ledPin_G = 9;       // LED pin for Green
int blink_rate = 0;  // variable to store the value coming from the sensor
int brightness = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin_R, OUTPUT);
  pinMode(ledPin_B, OUTPUT);
  pinMode(ledPin_G, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  blink_rate = analogRead(sensorPin_P0); //assigning blink_rate to pot0 value
  brightness = analogRead(sensorPin_P1); //assigning brightness to pot1 value
  // turn the ledPin on
  analogWrite(ledPin_R, brightness/5);
  analogWrite(ledPin_B, brightness/5);
  analogWrite(ledPin_G, brightness/5);

  // stop the program for <blink_rate> milliseconds:
  delay(blink_rate);
  // turn the ledPin off:
  analogWrite(ledPin_R, 0); //set brightness to 0
  analogWrite(ledPin_B, 0); //set brightness to 0
  analogWrite(ledPin_G, 0); //set brightness to 0

  // stop the program for for <blink_rate> milliseconds:
  delay(blink_rate);
}

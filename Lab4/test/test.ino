int fsrPin = 0;     // the cell and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 

void setup() {
 Serial.begin(9600);
}
 
void loop() {
 int analogValue = analogRead(A0)/4; // read the sensor value
 Serial.write(analogValue);          // send the value serially
                                     // as a binary value
  fsrReading = analogRead(fsrPin);  
  
  // LED lights red when sensor is weak = meaning danger
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  fsrReading = 1023 - fsrReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);
}


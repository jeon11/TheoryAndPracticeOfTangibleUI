/* 
 * Serial RGB LED
 * ---------------
 * Serial commands control the brightness of R,G,B LEDs 
 *
 * Command structure is "<colorCode><colorVal>", where "colorCode" is
 * one of "r","g",or "b" and "colorVal" is a number 0 to 255.
 * E.g. "r0"   turns the red LED off.  
 *      "g127" turns the green LED to half brightness
 *      "b64"  turns the blue LED to 1/4 brightness
 *
 * Created 18 October 2006
 * copyleft 2006 Tod E. Kurt <tod@todbot.com
 * http://todbot.com/
 */

char serInString[100];  // array that will hold the different bytes of the string. 100=100characters;
                        // -> you must state how long the array will be else it won't work properly
char colorCode;
char color;
int colorVal;

int redPin   = 9;   // Red LED,   connected to digital pin 9
int greenPin = 10;  // Green LED, connected to digital pin 10
int bluePin  = 11;  // Blue LED,  connected to digital pin 11
int percentage = 0;

void setup() {
  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT);
  Serial.begin(9600);
  analogWrite(redPin,   127);   // set them all to mid brightness
  analogWrite(greenPin, 127);   // set them all to mid brightness
  analogWrite(bluePin,  127);   // set them all to mid brightness
//  Serial.println("enter color command (e.g. 'r43') :");  
  Serial.println("enter color command (e.g. 'rr, ggg, or bbbb'). Optional: 'o' for orange and 'y' for yellow and 'p' for purple:");  
}

void loop () {
  // clear the string
  memset(serInString, 0, 100);
  //read the serial port and create a string out of what you read
  readSerialString(serInString);
  percentage = strlen(serInString);
    
  colorCode = serInString[0];
  if( colorCode == 'r' || colorCode == 'g' || colorCode == 'b' ) {
    colorVal = int(10 * 2.55 * percentage);
    Serial.print("setting color ");
    Serial.print(colorCode);
    Serial.print(" to ");
    Serial.print(colorVal);
    Serial.println();
    serInString[0] = 0;                   // indicates we've used this string
    if(colorCode == 'r') 
      analogWrite(redPin, colorVal);
    else if(colorCode == 'g')
      analogWrite(greenPin, colorVal);
    else if(colorCode == 'b')
      analogWrite(bluePin, colorVal);
  }

  if(colorCode == 'o' ) {
      Serial.print("setting color to orange");
      Serial.println();
      analogWrite(redPin, 70);
      analogWrite(greenPin, 30);
      analogWrite(bluePin, 0);
  }
  if(colorCode == 'y' ) {
      Serial.print("setting color to yellow");
      Serial.println();
      analogWrite(redPin, 30);
      analogWrite(greenPin, 80);
      analogWrite(bluePin, 0);
  }
  if(colorCode == 'p' ) {
      Serial.print("setting color to purple");
      Serial.println();
      analogWrite(redPin, 100);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 100);
  }
  
  delay(100);  // wait a bit, for serial data
}

//read a string from the serial and store it in an array
//you must supply the array variable
void readSerialString (char *strArray) {
  int i = 0;
  if(!Serial.available()) {
    return;
  }
  while (Serial.available()) {
    strArray[i] = Serial.read();
    i++;
  }
}

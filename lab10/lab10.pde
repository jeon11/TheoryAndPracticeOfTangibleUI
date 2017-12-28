
//download minim sound library from processing
import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

//code for importing Arduino firmata
import processing.serial.*;
import cc.arduino.*;
import processing.sound.*;

//calling in Minim class
Minim minim;
Arduino arduino;

//audio file variable names
AudioPlayer kick;
AudioPlayer snare;
AudioPlayer hihat;
AudioPlayer zing;
 
int FSR1 = 0; // pin A0 FSR
int FSR2 = 1; // pin A1 FSR
int FSR3 = 2; // pin A2 FSR
int FSR4 = 3; // pin A3 FSR
int FSRval1 = 0;
int FSRval2 = 0;
int FSRval3 = 0;
int FSRval4 = 0;

int FSRval_flag1 = 0;
int FSRval_flag2 = 0;
int FSRval_flag3 = 0;
int FSRval_flag4 = 0;

void setup(){
  arduino = new Arduino(this, Arduino.list()[3], 57600);
  arduino.pinMode(FSR1, Arduino.INPUT);
  arduino.pinMode(FSR2, Arduino.INPUT);
  arduino.pinMode(FSR3, Arduino.INPUT);
  arduino.pinMode(FSR4, Arduino.INPUT);
  //println(Arduino.list());
  
  size(100, 100);
  minim = new Minim(this);
  
  //calling in audio files. Make sure to change directory to local directory
  kick = minim.loadFile("/Users/christian/CDTMCloud/4. Semester (abroad)/Tangible UI/lab11/1.wav");
  snare = minim.loadFile("/Users/christian/CDTMCloud/4. Semester (abroad)/Tangible UI/lab11/2.wav");
  hihat = minim.loadFile("/Users/christian/CDTMCloud/4. Semester (abroad)/Tangible UI/lab11/3.wav");
  zing = minim.loadFile("/Users/christian/CDTMCloud/4. Semester (abroad)/Tangible UI/lab11/4.wav");
}
 
void draw() {
  background(0);
  stroke(255);
  
  FSRval1 = arduino.analogRead(FSR1);
  FSRval2 = arduino.analogRead(FSR2);
  FSRval3 = arduino.analogRead(FSR3);
  FSRval4 = arduino.analogRead(FSR4);
  
  println("Val1 = " + FSRval1 + " flag: " + FSRval_flag1);
  println("Val2 = " + FSRval2 + " flag: " + FSRval_flag2);
  println("Val3 = " + FSRval3 + " flag: " + FSRval_flag3);
  println("Val4 = " + FSRval4 + " flag: " + FSRval_flag4);
 
  //need to change below number '300' 
  if (FSRval1 < 500 && FSRval_flag1 == 0) {
      kick.rewind();
      kick.play();
      FSRval_flag1 = 1;
  } else if (FSRval1 > 900 && FSRval_flag1 == 1) {
    FSRval_flag1 = 0;
  }
  
  if (FSRval2 < 600 && FSRval_flag2 == 0) {
      snare.rewind();
      snare.play();
      FSRval_flag2 = 1;
  } else if (FSRval2 > 900 && FSRval_flag2 == 1) {
    FSRval_flag2 = 0;
  }
  
  if (FSRval3 < 600 && FSRval_flag3 == 0) {
      hihat.rewind();
      hihat.play();
      FSRval_flag3 = 1;
  } else if (FSRval3 > 900 && FSRval_flag3 == 1) {
    FSRval_flag3 = 0;
  }
  
  if (FSRval4 < 600 && FSRval_flag4 == 0) {
      zing.rewind();
      //zing.play();
      FSRval_flag4 = 1;
  } else if (FSRval4 > 900 && FSRval_flag4 == 1) {
    FSRval_flag4 = 0;
  }
}
 

//uncomment below to make keyboard as input
void keyPressed() {
  if (key == '1') {
    kick.rewind();
    kick.play();
  }
  if (key == '2') {
    snare.rewind();
    snare.play();
  }
  if (key == '3') {
    hihat.rewind();
    hihat.play();
  }
  if (key == '4') {
    zing.rewind();
    zing.play();
  }
}
import processing.serial.*;

Serial myPort;
// at the top of the program:
float xPos = 0; // horizontal position of the graph
float yPos = 500; // vertical position of the graph
void setup () {
  size(700, 250);        // window size
 
// Lists all the available serial ports
println(Serial.list());

String portName = Serial.list()[1];
myPort = new Serial(this, portName, 9600);

background(#597D87);

strokeWeight(3);

}
void serialEvent (Serial myPort) {
  // get serial input
  int inByte = myPort.read();
  // print
  println(inByte);
  
  yPos = height - inByte;
}

void draw () {
   // drawing lines based on FSR input
 
  stroke(#F2E3D5);
  line(xPos, height, xPos, yPos);
  
  // Clearing the screen
  if (xPos >= width) {
    xPos = 0;
    // clear screen once width is filled;
    background(#597D87);
  } else {
    // increment x value for next reading;
    xPos++;
  }
}
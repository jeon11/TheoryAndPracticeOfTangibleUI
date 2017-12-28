import processing.serial.*;
import cc.arduino.*;
import processing.sound.*;
  
SoundFile file;

void setup() {
  size(640, 360);
  background(255);
    
  // Load a soundfile from the /data folder of the sketch and play it back
  file = new SoundFile(this, "sample.mp3");
  file.play();
}      

void draw() {
}

import ddf.minim.*;
AudioPlayer player;
Minim minim;

void setup (){
  size (700, 500);
  minim = new Minim(this);
  

}

void draw(){
  
     if (mouseButton == LEFT) 
    {
         player = minim.loadFile("chainsaw.wav",1);
         player.play();
         
    }
    else if (mouseButton == RIGHT)
    {
      player = minim.loadFile("beep.wav", 2048); 
      player.close();// to close first one and then play the other
       player.play();
    
     
     }

 
}
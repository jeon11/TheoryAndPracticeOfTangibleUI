//Retro-feel Countdown
//Original code from eAthis
int compteur;
PFont police;

void setup() {
  size(400, 400);
  frameRate(30); 
  police = loadFont("PlaneCrash-48.vlw");
  textFont(police,150);
  compteur = 0;
}

void draw() {
    background(random(245, 255));
   
    // draw line
    smooth();
    strokeWeight(1);
    stroke(random(20,80)); 
    line(0,200,400,200);
    line(200,0,200,400);
    
    // draw cross line
    strokeWeight(2);
    line(200,0,200,200);
    
    // draw circle
    strokeWeight(2);
    stroke(random(30,80));
    noFill();
    ellipse(200,200,300,300);
    ellipse(200,200,270,270);
    
    // pattern effects
    noStroke();
    fill(random(50,100));
    ellipse(random (0,400), random (0,400), random (20), random (20));
    for (float i = 0; i < 400; i = i+random(0,400)) {
      strokeWeight(1);
      stroke(random(50,255));
      line(i,0,i,height);
  }
   
   // countdown 
   if( compteur <= 30){ 
    fill(0);
    text("4",150,255); 
  }
  
  if( compteur >= 31){
    if (compteur <= 60){
      fill(0);
      text("3",155,255);
    }
  }
  if (compteur >= 61){
    if (compteur <= 90){
      fill(0);
      text("2",155,250);
    }
  }
  if (compteur >= 91){
    if (compteur <= 120){
      fill(0);
      text("1",150,255);
    }
  }
  
  // line rotation  
  translate(200, 200);
  rotate(compteur*((PI*2)/30));
  stroke(0);
  strokeWeight(2);
  smooth();
  line(0, 0, 0, -290);
  
  // flash
  if (compteur == 30) { 
    background(230);
  }
  if (compteur==60){
    background(230);
  }
  if (compteur == 90){
    background(230);
  }
  if(compteur == 120){
    background(230); 
    compteur = 0;
  }
  compteur = compteur+1;
}
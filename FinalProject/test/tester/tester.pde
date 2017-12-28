import processing.serial.*;

int compteur;
PFont police; 
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
 
void setup() 
{
    size(400, 400);
    frameRate(30); 
    police = loadFont("PlaneCrash-48.vlw"); 
    textFont(police,150); 
    compteur = 0; 
    
// Open whatever port is the one you're using.
String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
myPort = new Serial(this, portName, 9600); 
}
 
void draw() {
  if ( myPort.available() > 0) 
  {  // If data is available,
  val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
println(val); //print it out in the console
 
  //DRAW RECTANGLE (that changes on different switch states)
  background(127,0,0);
 
  if (val == "3High"){
    fill(255,200,200);
    ellipse(60,20,100,100);
  }
  if (val == "3Low"){
    fill(200);
    ellipse(250, 250, 100, 100);    
  }
  
//  // Animation for countdown
//  background(random(170,190));
     
//    // croix
//    smooth();
//    strokeWeight(1);// largeur de trait
//    stroke(random(20,80));// couleur aléatoire 
//    line(0,200,400,200);//croix
//    line(200,0,200,400);//
    
//    //trait supérieur de la croix plus large
//    strokeWeight(2);// largeur de trait
//    line(200,0,200,200);// surlignage de la position de départ
    
//    //cibles
//    strokeWeight(2);// largeur de trait
//    stroke(random(190,220));// couleur du trait aléatoire en niveau de gris
//    noFill();// pas de remplissage
//    ellipse(200,200,300,300);// cible 1
//    ellipse(200,200,270,270);// cible 2
    
//    //effet usé
//    noStroke();// pas de bordure
//    fill(random(50,100));// remplissage aléatoire en valeurs de gris
//    ellipse(random (0,400), random (0,400), random (20), random (20));// taches position aléatoire et diamètre de 20 maximum
//    for (float i = 0; i < 400; i = i+random(0,400)){////boucle variable "i" min=0 ;max=400;incrementation aléatoire maximum 400
//      strokeWeight(1);//largeur de trait
//      stroke(random(50,255));// couleur de trait aléatoire en nuances de gris
//      line(i,0,i,height);// tracer lignes: absisse des deux points de la ligne s'incrémente simultanément on a donc des lignes verticales
//  }
   
  
//   // gestion de la typographie en fonction du compteur
//   if( compteur <= 30){ // condition: tant que le compteur ne dépasse pas 30 (1seconde)
//    fill(0);// remplissage en noir
//    text("4",150,255);// print "4" 
//  }
//  if( compteur >= 31){// tant que le compteur est plus grand ou egal a 31
//    if (compteur <= 60){// et qu'il est plus petit ou egal a 60
//      fill(0);// remplissage en noir
//      text("3",155,255);// print "3"
//    }
//  }
//  if (compteur >= 61){// tant que le compteur est plus grand ou egal a 61
//    if (compteur <= 90){// et qu'il est plus petit ou egal a 90
//      fill(0);//remplissage en noir
//      text("2",155,250);// print "2"
//    }
//  }
//  if (compteur >= 91){// tant que le compteur est plus grand ou egal a 91
//    if (compteur <= 120){// et qu'il est plus petit ou egal a 120
//      fill(0);// remplissage en noir
//      text("1",150,255);// print "1"
//    }
//  }
  
//  //rotation de la ligne
//  translate(200, 200);//le point d'origine (coin supérieur gauche) est au centre
//  rotate(compteur*((PI*2)/30));//rotation en fonction du compteur de 360°par seconde
//  stroke(0);//ligne noire
//  strokeWeight(2);// épaisseur de la ligne
//  smooth();//lissage
//  line(0, 0, 0, -290);//ligne verticale position de départ
  
  
//  // flash
//  if (compteur == 30) {//condition : si le compteur dépasse 30 (1seconde) 
//    background(230);//et le le fond blanc qui fait le flash........3......
//  }
//  if (compteur==60){
//    background(230);//........2.......
//  }
//  if (compteur == 90){
//    background(230);//....1.....
//  }
//  if(compteur == 120){
//    background(230);//ouverture volet 
//    compteur = 0;
//  }
//  compteur = compteur+1;//incrémentation du compteur
}
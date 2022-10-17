#include <SharpIR.h>

#include <Servo.h>

// MAPPING DES PINS
  //AFFECTATION DES SERVOS POUR LES PIEDS ET HANCHE
  //DECLARATION DES VARIABLES POUR LES PINS DES SERVO
  /*L'orientation du robot est celle de l'homme c'est à dire que 
  le coté gauche du robot correspond au coté gauche de l'homme*/
  const byte pin_pg = 2, pin_pd = 3, pin_hg = 4, pin_hd = 5, pin_bg = 6, pin_bd = 7;
  const byte pin_cd = A1, pin_cg = A0;
// VARIABLES
  SharpIR capt_d(SharpIR::GP2Y0A41SK0F,pin_cd), capt_g(SharpIR::GP2Y0A41SK0F,pin_cg);
  Servo servo_pg, servo_pd, servo_hg, servo_hd, servo_bg, servo_bd;//Déclaration des variables servo
  int pg, pd, hg, hd, bg, bd;//Déclaration des variables contenants les angles des servomoteurs
  int varp, varh;//Se sont des variables dans lesquelles seront stocké les variable "pas, demipas, penche, demipenche" afin de pouvoir faire déplacer le robot
  int i, j, k;
  int delais;
  int vue_droit, vue_gauche, dist=0;
//CONSTANTES
  const int pente = 30, demipente = 15, pas = 60, demipas = 30;
  const int init_pg = 85, init_pd = 83, init_hg = 95, init_hd = 87, init_bg =  90, init_bd = 90;
  const int delais_1 = 12, delais_2 = 7;
#include "motion.h"//Bibliothèque contenant les fonction de déplacement vers l'avant, l'arrière, 
                   //tourner à gauche, tourner à droite et celle d'initialisation des servo moteurs

void setup() {
  // put your setup code here, to run once:
  Serial.setTimeout(500);
  Serial.begin(9600);
  delais = delais_1;
  init_robot();
  delay(1000);
}

void loop() {
  // MARCH

  /*voir();
  varp = demipente; varh = demipas; pasg_avant();
  varp = pente; varh = pas;
  pasd_avant(); pasg_avant();   //delais -=1;
  pasd_avant(); pasg_avant(); 
  pasd_avant(); pasg_avant(); */
  //if(delais<=delais_2) {delais=delais_2;}

  /*varp = demipente; varh = demipas; pasd_avant();

  voir();
  varp = demipente; varh = demipas; pasg_arriere();
  varp = pente; varh = pas;
  pasd_arriere(); pasg_arriere();   //delais -=1;
  pasd_arriere(); pasg_arriere(); 
  pasd_arriere(); pasg_arriere(); 
  //if(delais<=delais_2) {delais=delais_2;}

  varp = demipente; varh = demipas; pasd_arriere();*/

  for(int i=0; i<3; i++){
   turn_gauche();
   Serial.println("je tourne"); 
  }
  voir();
}

void init_robot(){
  servo_on();
  centre();
}
void servo_on(){
  servo_pg.attach(pin_pg,544,2400);
  servo_pd.attach(pin_pd,544,2400);
  servo_hg.attach(pin_hg,544,2400);
  servo_hd.attach(pin_hd,544,2400);
  servo_bg.attach(pin_bg,544,2400);
  servo_bd.attach(pin_bd,544,2400);
}

void servo_off(){
  servo_pg.detach();
  servo_pd.detach();
  servo_hg.detach();
  servo_hd.detach();
  servo_bg.detach();
  servo_bd.detach();
}

void avance(){//Faire les pas gauche et droite vers l'avant
  varp = demipente ; 
  varh = demipas ;   
  pasd_avant();
  varp = pente ; 
  varh = pas ;     
    pasg_avant() ; 
    pasd_avant();
  varp = demipente ;
  varh = demipas ;
  pasd_avant(); 
}
void voir (){
  vue_droit = capt_d.getDistance();
  Serial.print("Distance droit: "); Serial.print(vue_droit); Serial.println(" cm");
  vue_gauche = capt_g.getDistance();
  Serial.print("Distance gauche: "); Serial.print(vue_gauche); Serial.println(" cm");
  //distance=(droit+gauche)/2;
}

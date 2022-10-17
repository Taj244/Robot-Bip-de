#include <SharpIR.h>


int pin_cd = A1, pin_cg = A0;
int dist=0;
SharpIR capt_d(SharpIR::GP2Y0A41SK0F,pin_cd), capt_g(SharpIR::GP2Y0A41SK0F,pin_cg);

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  dist = capt_d.getDistance();
  Serial.println(dist);
  delay(2000);

}

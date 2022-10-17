void centre(){
  Serial.print("centrer");
  pg = (init_pg);
  pd = (init_pd);
  hg = (init_hg);
  hd = (init_hd);
  bd = (init_bd);
  bg = (init_bg);
  servo_pg.write(pg);
  servo_pd.write(pd);
  servo_hg.write(hg);
  servo_hd.write(hd);
  servo_bg.write(bg);
  servo_bd.write(bd);
}
void pasg_avant(){
  Serial.print("pas gauche");
  for(i=0; i<varp; i++){
    delay(delais*1.5);
    pd+=1; pg+=1;
    servo_pg.write(pg); servo_pd.write(pd);
    
  }
  for(i=0; i<varh; i++){
    delay(delais/1.5);
    hd+=1; hg+=1;
    servo_hg.write(hg); servo_hd.write(hd);
  }
}

void pasd_avant(){
  Serial.print("pas gauche");
  for(i=0; i<varp; i++){
    delay(delais*1.5);
    
    pd-=1; pg-=1;
    servo_pg.write(pg); servo_pd.write(pd);
  }
  for(i=0; i<varh; i++){
    delay(delais/1.5);
    hd-=1; hg-=1;
    servo_hg.write(hg);servo_hd.write(hd);
  }
}

void pasg_arriere(){
   for(i=0; i<varp; i++){
    delay(delais*2);
    pd+=1; pg+=1;
    servo_pg.write(pg); servo_pd.write(pd);
    
  }
  for(i=0; i<varh; i++){
    delay(delais/1.5);
    hd-=1; hg-=1;
    servo_hg.write(hg); servo_hd.write(hd);
  }
}

void pasd_arriere(){
  for(i=0; i<varp; i++){
    delay(delais*2);
    
    pd-=1; pg-=1;
    servo_pg.write(pg); servo_pd.write(pd);
  }
  for(i=0; i<varh; i++){
    delay(delais/1.5);
    hd+=1; hg+=1;
    servo_hg.write(hg);servo_hd.write(hd);
  }
}



void turn_droit(){
   varp = demipente ; varh = demipas ; 
   // penche à gauche
   for (i=0;i<=varp;i+=1)
  { delay(delais*2);
    pg-=1;    pd-=1;
     servo_pg.write(pg) ;     servo_pd.write(pd) ;
   }
  //  pas gauche
  for (i=0;i<=varh;i+=1)
  {delay(delais);
    hg+=1; hd-=0;    
    servo_hd.write(hd) ;servo_hg.write(hg) ;    
    }
  // penche à gauche
   for (i=0;i<=varp;i+=1)
  { delay(delais*2);
    pd+=2;  pg+=2;
     servo_pd.write(pd); servo_pg.write(pg) ;
   }
  //  pas gauche
  for (i=0;i<=varh;i+=1)
  { delay(delais);
    hg-=1;  hd+=0;
    servo_hg.write(hg) ;    servo_hd.write(hd) ;
    }
  // penche à gauche
  for (i=0;i<=varp;i+=1)
  { delay(delais*2);
    pg-=1;    pd-=1;
    servo_pg.write(pg) ;
   }
}

void turn_gauche(){
  varp = demipente ; varh = demipas ; 
   // penche à droite
   for (i=0;i<=varp;i+=1)
  { delay(delais*2);
    pg+=1;    pd+=1;
    servo_pg.write(pg) ;    servo_pd.write(pd) ;
   }
  //  pas droite
  for (i=0;i<=varh;i+=1)
  { delay(delais);
    hg+=0;    hd-=1;
   servo_hg.write(hg) ;   servo_hd.write(hd) ; 
    }
  // penche à gauche
   for (i=0;i<=varp;i+=1)
  { delay(delais*2);
    pg-=2;    pd-=2;
    servo_pg.write(pg) ;    servo_pd.write(pd) ;
   }
  //  pas gauche
  for (i=0;i<=varh;i+=1)
  { delay(delais);
    hg-=0;    hd+=1;
   servo_hg.write(hg) ;   servo_hd.write(hd) ;
    }
  // penche à gauche
   for (i=0;i<=varp;i+=1)
  { delay(delais*2);
    pg+=1;    pd+=1;
    servo_pg.write(pg) ;    servo_pd.write(pd) ;
   }
}

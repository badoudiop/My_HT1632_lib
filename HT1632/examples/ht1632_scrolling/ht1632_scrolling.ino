
#include <HT1632.h>
#include "the_fonts.h"

//*********************************
int Cs1=2,Cs2=3,Cs3=4,Wr=5,Data=6;
HT1632 ht(Cs1,Cs2,Cs3,Wr,Data);
int i=0,j3=22,qq=0,w,duree;
int longueur(unsigned char *x);
 
unsigned char I1[8],I2[8],I3[8],I4[8],I5[8],toto,tonton;

void clear(void);//on ecrit des 0 partout pour effacer

unsigned char J1[96];//car y a 96 colonnes pour 3 panneaux


//*****************************

void setup(void)
{
i=0;j3=22;qq=0;duree=500;;
ht.init();
ht.ht1632_init();

w=longueur(mes);
clear();
ht.ht1632_init();
_delay_ms(10);
ht.ht1632_init();
_delay_ms(10);
}

void loop()
{// on tourne 8 fois pour récupérer un tableau 8x8
//qq=0;
//**********************

tester(qq);

//*****************************

  ht.charger(tab[tolower(mes[qq%w])-97],tab[tolower(mes[(qq+1)%w])-97],tab[tolower(mes[(qq+2)%w])-97],tab[tolower(mes[(qq+3)%w])-97],tab[tolower(mes[(qq+4)%w])-97],I1,I2,I3,I4,I5);
  
int j=j3;
J1[0]=I1[0];ht.permute(J1);
ht.afficher1(J1);ht.afficher2(J1);ht.afficher3(J1);ht.pause(j); //123
for(int coco=0;coco<7;coco++)
{
  ht.tourner(I1,I2,I3,I4,I5);//2
  j=j3;
  J1[0]=I1[0];ht.permute(J1);
  ht.afficher1(J1);ht.afficher2(J1);ht.afficher3(J1);ht.pause(j); //123
}
qq++;if(qq>w) qq=0;
     }

void tester( int q)
{
for(int i=0;i<5;i++) 
{
if(mes[(q+i)%w]==32) mes[(q+i)%w]=123;//espace
if(mes[(q+i)%w]==44) mes[(q+i)%w]=124;// virgule
if(mes[(q+i)%w]==63) mes[(q+i)%w]=125;//interro
if(mes[(q+i)%w]==33) mes[(q+i)%w]=126;//excla
if(mes[(q+i)%w]==58) mes[(q+i)%w]=127;//2 pts
if(mes[(q+i)%w]==45) mes[(q+i)%w]=128;//triat union
}
}

int longueur(unsigned char *x)
{
  int l=0;
  while(*x){x++;l++;}
  return l;
}

void clear(void)//on ecrit des 0 partout pour effacer
{
 

for(unsigned int j=0;j<4;j++)
{
  ht.affiche_font1(vide,16*j);
  ht.affiche_font2(vide,16*j);
  ht.affiche_font3(vide,16*j);

}
//cs_high();
//_delay_ms(50);
}
//*****************

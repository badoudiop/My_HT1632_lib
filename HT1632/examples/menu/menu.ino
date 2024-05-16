#include <HT1632.h>
#include "the_fonts.h"

//*********************************


HT1632 ht(2,3,4,5,6);

int i=0,j3=22,qq=0,j=5,duree;


unsigned char I1[8],I2[8],I3[8],I4[8],I5[8],toto,tonton;
//unsigned int longueur(unsigned char *x);



unsigned char *mes1="lundi:mafeyp";
unsigned char *mes2="mardi:yassa ";
unsigned char *mes3="mer:thieb yp"; 
unsigned char *mes4="jeudi:cousmz"; 
unsigned char *mes5="vend:domoda "; 
unsigned char *mes6="sam:p-frites"; 
int lg_chaine;

void clear(void);//on ecrit des 0 partout pour effacer

//*****************************
void setup(void)
{

i=0;j3=22;qq=0;duree=500;

ht.init();
ht.ht1632_init();
clear();
ht.ht1632_init();
ht.pause(100);
ht.ht1632_init();
ht.pause(100);

//*****************************

}

void loop()
{
  ht.pause(duree);
  if(j==0) j=1;
 else if(j==1) j=2;
 else if(j==2)j=3;
 else if(j==3)j=4;
 else if(j==4)j=5;
 else if(j==5)j=0;

 
unsigned char *L[]={mes1,mes2,mes3,mes4,mes5,mes6};
unsigned char *mes=L[j] ;
lg_chaine=ht.longueur(mes);
 
for(i=0;i<lg_chaine;i++){
if(mes[i]==32) mes[i]=123;//espace
else if(mes[i]==44) mes[i]=124;// virgule
else if(mes[i]==63) mes[i]=125;//interro
else if(mes[i]==33) mes[i]=126;//excla
else if(mes[i]==58) mes[i]=127;//2 pts
else if(mes[i]==45) mes[i]=128;//triat union
//else J1[i]=tolower(mes[i]);
}
for(i=0;i<4;i++) {ht.affiche_font3(tab[tolower(mes[i])-97],i*16);
ht.pause(100);}
//for(i=4;i<8;i++){if(mes1[i]==32)J1[i]=123;}
for(i=4;i<8;i++){ ht.affiche_font2(tab[tolower(mes[i])-97],(i-4)*16);
ht.pause(100);}

for(i=8;i<12;i++) {ht.affiche_font1(tab[tolower(mes[i])-97],(i-8)*16);
ht.pause(100);}
ht.pause(3000);
clear();
ht.pause(1000);
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


//*************************************
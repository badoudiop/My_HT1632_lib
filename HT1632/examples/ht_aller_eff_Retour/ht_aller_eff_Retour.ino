#include <HT1632.h>
#include "the_fonts.h"


//*********************************


HT1632 ht(2,3,4,5,6);

int i=0,j3=22,qq=0,j=0,duree;

unsigned char *mes1="colette diop";
int lg_chaine;
unsigned char J1[96];
//*****************************



unsigned char I1[8],I2[8],I3[8],I4[8],I5[8],toto,tonton;
//unsigned int longueur(unsigned char *x);


void setup(void)
{
i=0,j3=22,qq=0;duree=500;
lg_chaine=ht.longueur(mes1);

ht.init();
ht.ht1632_init();
clear();


}

void loop()
{
  ht.pause(2*duree);

if(mes1[0]== 32 ) {mes1[0]=123;
   ht.affiche_font3(tab[26],0);}
   else ht.affiche_font3(tab[tolower(mes1[0])-97],0);
  ht.pause(duree);
 /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
if(mes1[1]== 32 ) {mes1[1]=123;
   ht.affiche_font3(tab[26],16);}
   else ht.affiche_font3(tab[tolower(mes1[1])-97],16);
  ht.pause(duree);
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
if(mes1[2]== 32 ) {mes1[2]=123;
   ht.affiche_font3(tab[26],32);}
   else ht.affiche_font3(tab[tolower(mes1[2])-97],32);
  ht.pause(duree);
 /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
if(mes1[3]== 32 ) {mes1[3]=123;
   ht.affiche_font3(tab[26],48);}
   else ht.affiche_font3(tab[tolower(mes1[3])-97],48);
  ht.pause(duree);
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
if(mes1[4]== 32 ) {mes1[4]=123;
   ht.affiche_font2(tab[26],0);}
   else ht.affiche_font2(tab[tolower(mes1[4])-97],0);
  ht.pause(duree);
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
  
 if(mes1[5]== 32 ) {mes1[5]=123;
   ht.affiche_font2(tab[26],16);}
   else ht.affiche_font2(tab[tolower(mes1[5])-97],16);
  ht.pause(duree);
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
  if(mes1[6]== 32 ) {mes1[6]=123;
   ht.affiche_font2(tab[26],32);}
   else ht.affiche_font2(tab[tolower(mes1[6])-97],32);
  ht.pause(duree);
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/

   if(mes1[7]== 32 ) {mes1[7]=123;
   ht.affiche_font2(tab[26],48);}
   else ht.affiche_font2(tab[tolower(mes1[7])-97],48);
  ht.pause(duree);

  
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
if(mes1[8]== 32 ) {mes1[8]=123;
   ht.affiche_font1(tab[26],0);}
   else ht.affiche_font1(tab[tolower(mes1[8])-97],0);
  ht.pause(duree);
  //ht.affiche_font1(vide,0);
// ht.pause(duree);
  
 if(mes1[9]== 32 ) {mes1[9]=123;
   ht.affiche_font1(tab[26],16);}
   else ht.affiche_font1(tab[tolower(mes1[9])-97],16);
  ht.pause(duree);
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/
  if(mes1[10]== 32 ) {mes1[10]=123;
   ht.affiche_font1(tab[26],32);}
   else ht.affiche_font1(tab[tolower(mes1[10])-97],32);
  ht.pause(duree);
  /*
  ht.affiche_font1(vide,16);
  ht.pause(duree);
*/

   if(mes1[11]== 32 ) {mes1[11]=123;
   ht.affiche_font1(tab[26],48);}
   else ht.affiche_font1(tab[tolower(mes1[11])-97],48);
  ht.pause(duree);

  _delay_ms(2000);
 // clear();
  _delay_ms(1000);

  //********************************
   ht.affiche_font1(vide,48);
   ht.pause(duree);
   ht.affiche_font1(vide,32);
   ht.pause(duree);
   ht.affiche_font1(vide,16);
   ht.pause(duree);
   ht.affiche_font1(vide,0);
   ht.pause(duree);
   //***********************
ht.affiche_font2(vide,48);
   ht.pause(duree);
   ht.affiche_font2(vide,32);
   ht.pause(duree);
   ht.affiche_font2(vide,16);
  ht.pause(duree);
   ht.affiche_font2(vide,0);
   ht.pause(duree);
   //***********************
   ht.affiche_font3(vide,48);
   ht.pause(duree);
   ht.affiche_font3(vide,32);
   ht.pause(duree);
   ht.affiche_font3(vide,16);
   ht.pause(duree);
   ht.affiche_font3(vide,0);
  ht.pause(duree);
   //***********************
   

}


//******************************************
void init(void)
{
ht.init();

ht.ht1632_init();

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


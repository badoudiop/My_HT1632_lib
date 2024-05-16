#include <Arduino.h>
#include "the_fonts.h"


//*********************************
int cs1=2;
int cs2=3;
int cs3=4;
int wr=5;
int data=6;


#define sys_en  0x02
#define led_on 0x06
#define master_rc 0b000101000
#define slave_rc 0b100000
#define commons 0b001010000// onprend ab=10 : voir data sheet
#define pwm_16 0b101011110

int i=0,j3=22,qq=0,j=0,duree;

unsigned char *mes1="colette diop";
int lg_chaine;
unsigned char J1[96];
//*****************************



unsigned char I1[8],I2[8],I3[8],I4[8],I5[8],toto,tonton;
//unsigned int longueur(unsigned char *x);
void nop(void);
void write_low(void);
void write_high(void);
void data_low(void);
void data_high(void);
void cs3_low(void);
void cs1_low(void);
void cs2_low(void);
void cs3_high(void);
void cs1_high(void);
void cs2_high(void);
void write_id(void);
void command_id(void);
void ht1632_write(unsigned char x);
void ht1632_adr(unsigned char x);
void ht1632_master_command(unsigned int x);
void ht1632_slave_command(unsigned int x);
void ht1632_init(void);
void init(void);
void clear(void);
int longueur(unsigned char *x);
void command(unsigned int x);



void pause( int s);

void affiche_font1(unsigned char x[],int i);
void affiche_font2(unsigned char x[],int i);
void affiche_font3(unsigned char x[],int i);
//*****************************
void afficher1(unsigned char x[]);
void afficher2(unsigned char x[]);
void afficher3(unsigned char x[]);
void tourner(unsigned char *x);
//**********************

void setup(void)
{
i=0,j3=22,qq=0;duree=500;
lg_chaine=longueur(mes1);

init();
clear();


}

void loop()
{
  pause(2*duree);

if(mes1[0]== 32 ) {mes1[0]=123;
   affiche_font3(tab[26],0);}
   else affiche_font3(tab[tolower(mes1[0])-97],0);
  pause(duree);
 /*
  affiche_font1(vide,16);
  pause(duree);
*/
if(mes1[1]== 32 ) {mes1[1]=123;
   affiche_font3(tab[26],16);}
   else affiche_font3(tab[tolower(mes1[1])-97],16);
  pause(duree);
  /*
  affiche_font1(vide,16);
  pause(duree);
*/
if(mes1[2]== 32 ) {mes1[2]=123;
   affiche_font3(tab[26],32);}
   else affiche_font3(tab[tolower(mes1[2])-97],32);
  pause(duree);
 /*
  affiche_font1(vide,16);
  pause(duree);
*/
if(mes1[3]== 32 ) {mes1[3]=123;
   affiche_font3(tab[26],48);}
   else affiche_font3(tab[tolower(mes1[3])-97],48);
  pause(duree);
  /*
  affiche_font1(vide,16);
  pause(duree);
*/
if(mes1[4]== 32 ) {mes1[4]=123;
   affiche_font2(tab[26],0);}
   else affiche_font2(tab[tolower(mes1[4])-97],0);
  pause(duree);
  /*
  affiche_font1(vide,16);
  pause(duree);
*/
  
 if(mes1[5]== 32 ) {mes1[5]=123;
   affiche_font2(tab[26],16);}
   else affiche_font2(tab[tolower(mes1[5])-97],16);
  pause(duree);
  /*
  affiche_font1(vide,16);
  pause(duree);
*/
  if(mes1[6]== 32 ) {mes1[6]=123;
   affiche_font2(tab[26],32);}
   else affiche_font2(tab[tolower(mes1[6])-97],32);
  pause(duree);
  /*
  affiche_font1(vide,16);
  pause(duree);
*/

   if(mes1[7]== 32 ) {mes1[7]=123;
   affiche_font2(tab[26],48);}
   else affiche_font2(tab[tolower(mes1[7])-97],48);
  pause(duree);

  
  /*
  affiche_font1(vide,16);
  pause(duree);
*/
if(mes1[8]== 32 ) {mes1[8]=123;
   affiche_font1(tab[26],0);}
   else affiche_font1(tab[tolower(mes1[8])-97],0);
  pause(duree);
  //affiche_font1(vide,0);
// pause(duree);
  
 if(mes1[9]== 32 ) {mes1[9]=123;
   affiche_font1(tab[26],16);}
   else affiche_font1(tab[tolower(mes1[9])-97],16);
  pause(duree);
  /*
  affiche_font1(vide,16);
  pause(duree);
*/
  if(mes1[10]== 32 ) {mes1[10]=123;
   affiche_font1(tab[26],32);}
   else affiche_font1(tab[tolower(mes1[10])-97],32);
  pause(duree);
  /*
  affiche_font1(vide,16);
  pause(duree);
*/

   if(mes1[11]== 32 ) {mes1[11]=123;
   affiche_font1(tab[26],48);}
   else affiche_font1(tab[tolower(mes1[11])-97],48);
  pause(duree);

  _delay_ms(2000);
 // clear();
  _delay_ms(1000);

  //********************************
   affiche_font1(vide,48);
   pause(duree);
   affiche_font1(vide,32);
   pause(duree);
   affiche_font1(vide,16);
   pause(duree);
   affiche_font1(vide,0);
   pause(duree);
   //***********************
affiche_font2(vide,48);
   pause(duree);
   affiche_font2(vide,32);
   pause(duree);
   affiche_font2(vide,16);
  pause(duree);
   affiche_font2(vide,0);
   pause(duree);
   //***********************
   affiche_font3(vide,48);
   pause(duree);
   affiche_font3(vide,32);
   pause(duree);
   affiche_font3(vide,16);
   pause(duree);
   affiche_font3(vide,0);
  pause(duree);
   //***********************
   
 /*
  affiche_font1(vide,16);
  pause(duree);
*/
/*
 for(i=0;i<64;i++)
  {
affiche_font1(A,i);
affiche_font2(A,i);
//affiche_font1(A,i);
affiche_font3(A,i);
_delay_ms(20);
  }

  for(i=64;i>0;i--)
  {
affiche_font1(tab[3],64-i);
affiche_font2(A,64-i);
affiche_font3(A,64-i);
_delay_ms(10);
}
  */
}
//*************************************
void nop(void)
{
_delay_us(1);
}

void write_low(void)
{
digitalWrite(wr,LOW);nop();
}
void write_high(void)
{
digitalWrite(wr,HIGH);nop();
}

void data_low(void)
{
digitalWrite(data,LOW);nop();
}
void data_high(void)
{
digitalWrite(data,HIGH);nop();
}

void cs1_low(void)
{
digitalWrite(cs1,LOW);nop();
}
void cs1_high(void)
{
digitalWrite(cs1,HIGH);nop();

}
void cs2_low(void)
{
digitalWrite(cs2,LOW);nop();
}
void cs2_high(void)
{
digitalWrite(cs2,HIGH);nop();

}

void cs3_low(void)
{
digitalWrite(cs3,LOW);nop();
}
void cs3_high(void)
{
digitalWrite(cs3,HIGH);nop();

}

void write_id(void)//code pour ecrire
{

write_high();
write_low();
data_high();//envoie 1
write_high();

write_low();
data_low();//envoie 0
write_high();

write_low();
data_high();//envoie 1
write_high();

}

void command_id(void)//code pour une commande
{

write_high();
write_low();
data_high();//envoie 1
write_high();

write_low();
data_low();//envoie 0
write_high();

write_low();
data_low();//envoie 0
write_high();

}
//*******************************

void ht1632_write(unsigned char x)
//ecrit un char; on mettra write_id avant ; commence par le lsb
//en write continuous mode pas besoin de couper le char D7D6D5D4D3D2D1D0 en 2 groupes ;
//ht1632 ecrit D3D2D1D0 sur le haut puis D7D6D5D4 dessous  dans chaque colonne: aide à créer les fontes .
{
write_low();
if(x&0x01){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x02){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x04){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x08){data_high();}
else {data_low();}
write_high();
//************************
write_low();
if(x&0x10){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x20){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x40){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x80){data_high();}
else {data_low();}
write_high();
}
//***********************************
void ht1632_adr(unsigned char x)
//ecrire une adresse; le code write_id est mis devant ;
//on en aura besoin que d'une fois pour l'adresse 0
{
write_id();
write_low();
if(x&0x40){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x20){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x10){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x08){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x04){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x02){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x01){data_high();}
else {data_low();}
write_high();

}
//************************
void command(unsigned int x)
{
command_id();
write_low();
if(x&0x100){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x80){data_high();}
else {data_low();}
write_high();
write_low();
if(x&0x40){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x20){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x10){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x08){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x04){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x02){data_high();}
else {data_low();}
write_high();

write_low();
if(x&0x01){data_high();}
else {data_low();}
write_high();
}

//*****************************************
void ht1632_master_command(unsigned int x)
//ecriturecomplète d'une commande pour le panneau1.
{
  cs2_high();cs3_high();
cs1_high();
cs1_low();
command(x);
cs1_high();
}
//*****************************************
void ht1632_slave_command(unsigned int x)//pour le panneau2
//ecriturecomplète d'une commande .
{cs1_high();
cs2_high();cs3_high();
cs2_low();cs3_low();
command(x);
cs2_high();cs3_high();
}
void ht1632_init(void)
{
//on initialise le ht1632
ht1632_master_command(sys_en);
ht1632_master_command(master_rc);
ht1632_master_command(commons);//dans le commons on prend ab=10 (voir le data sheet)
ht1632_master_command(led_on);
ht1632_master_command(pwm_16);
ht1632_slave_command(sys_en);
ht1632_slave_command(slave_rc);
ht1632_slave_command(commons);//dans le commons on prend ab=10 (voir le data sheet)
ht1632_slave_command(led_on);
ht1632_slave_command(pwm_16);

}


//******************************************
void init(void)
{
pinMode(cs1,OUTPUT);pinMode(cs2,OUTPUT);pinMode(cs3,OUTPUT);
pinMode(wr,OUTPUT);pinMode(data,OUTPUT);

ht1632_init();

}

void clear(void)//on ecrit des 0 partout pour effacer
{
 

for(unsigned int j=0;j<4;j++)
{
  affiche_font1(vide,16*j);
  affiche_font2(vide,16*j);
  affiche_font3(vide,16*j);

}
//cs_high();
//_delay_ms(50);
}






void affiche_font1(unsigned char x[],int i)
{
unsigned int tata=0;
 cs1_low();cs3_high();cs2_high();
 ht1632_adr(i);
while(tata<8)//
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs1_high();
}

void affiche_font2(unsigned char x[],int i)
{
unsigned int tata=0;
 cs2_low();cs3_high();cs1_high();
 ht1632_adr(i);
while(tata<8)//
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs2_high();
}

void affiche_font3(unsigned char x[],int i)
{
unsigned int tata=0;
 cs3_low();cs2_high();cs1_high();
 ht1632_adr(i);
while(tata<8)//
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs3_high();
}

void pause(unsigned int s)
{while(s--) _delay_ms(1);}

//********************************************

void afficher3(unsigned char x[])//afficher sur l'sclave d'abord puis sur le maitre
// sinon il y a enchevetrement

{//permute();//Si on active les permutes dans les 2 affiches , les lettres deviennent immenses
// avec défilement plus rapide ; reduire j3 dans main() pour ralentir .
unsigned int tata=0;
 cs3_low();cs2_high();cs1_high();
 ht1632_adr(0);
while(tata<32)// jusqu'à 32 pour couper J1 en trois parties égales ;
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs3_high();
}

void afficher2(unsigned char x[])//afficher sur l'sclave d'abord puis sur le maitre
// sinon il y a enchevetrement

{//permute();

unsigned int tata=32;
 cs2_low();cs1_high();cs3_high();
 ht1632_adr(0);
while(tata<64)// jusqu'à 64 pour couper J1 en trois parties égales ;
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs2_high();
}


void afficher1(unsigned char x[])// afficher sur le digit maitre

{//permute();
unsigned int tata=64;// de 32 à 64 l'autre moitié
 cs1_low();cs3_high();cs2_high();
 ht1632_adr(0);
while(tata<96)
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs1_high();
}

void tourner(unsigned char *x)
{
for(int i=0;i<95;i++) x[i]=x[i+1];
x[95]=x[0];
}

int longueur(unsigned char *x)
{
int t=0;
while(*x) {x++;t++;}
return t;
}

void pause(int j)
{
while(j--)_delay_ms(1);
}


//*************************************Main

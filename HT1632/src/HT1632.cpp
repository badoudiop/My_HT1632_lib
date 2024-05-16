
#include "HT1632.h"


//*********************************
int cs1,cs2,cs3,wr,data;

//*****************************
#define sys_en  0x02
#define led_on 0x06
#define master_rc 0b000101000
#define slave_rc 0b100000
#define commons 0b001010000// onprend ab=10 : voir data sheet
#define pwm_16 0b101011110

unsigned int longueur(unsigned char *x);
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
//void ht1632_init(void);
void ht1632_adr1(unsigned char x);
void ht1632_write1(unsigned char x);
void command(unsigned int x);
void pause(unsigned int s);

HT1632::HT1632(int cs11 ,int cs21 ,int cs31 , int wr1 , int data1)
{
  _cs1=cs1;_cs2=cs21;_cs3=cs31; _wr=wr1 ; _data=data1;
cs1=cs11 ;cs2=cs21;cs3=cs31; wr=wr1; data=data1;
}


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
void HT1632::ht1632_write(unsigned char x)
{
ht1632_write1(x);
}
//***********************************

void ht1632_write1(unsigned char x)
//ecrit un char; on mettra write_id avant ; commence par le lsb
//en write continuous mode pas besoin de couper le char D7D6D5D4D3D2D1D0 en 2 groupes ;
//ht1632 ecrit D3D2D1D0 sur le haut puis D7D6D5D4 dessous  dans chaque colonne: aide à créer les fontes .
{
//write_id();
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
void HT1632::ht1632_adr(unsigned char x)
{
ht1632_adr1(x);

}
//****************************************
void ht1632_adr1(unsigned char x)
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
void HT1632::ht1632_init(void)
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
void HT1632::init(void)
{
pinMode(cs1,OUTPUT);pinMode(cs2,OUTPUT);pinMode(cs3,OUTPUT);
pinMode(wr,OUTPUT);pinMode(data,OUTPUT);
//ht1632_init();

}

void HT1632::permute(unsigned char *x)// L'ESSENTIEL est là ;pour défiler !!!
{
unsigned char qq=0;
unsigned char a=x[0];
while(qq<95) {x[qq]=x[qq+1];qq++;}
x[95]=a;
//J1[63]=J1[0];
}
void HT1632::charger(unsigned char *x,unsigned char *y,unsigned char *z,unsigned char *u,unsigned char *s,unsigned char *x1,unsigned char *x2,unsigned char *x3,unsigned char *x4,unsigned char *x5)
{
int toto=0;
while(toto<8)//pour ne pas modofier les *x...*s on travaille sur les I .
{
x1[toto]=x[toto];x2[toto]=y[toto];x3[toto]=z[toto];x4[toto]=u[toto];x5[toto]=s[toto];toto++;
}
}

void HT1632::tourner(unsigned char *x1,unsigned char *x2,unsigned char *x3,unsigned char *x4,unsigned char *x5)
{
x1[0]=x1[1];x1[1]=x1[2];x1[2]=x1[3];x1[3]=x1[4];
x1[4]=x1[5];x1[5]=x1[6];x1[6]=x1[7];x1[7]=x2[0];
//*********
x2[0]=x2[1];x2[1]=x2[2];x2[2]=x2[3];x2[3]=x2[4];
x2[4]=x2[5];x2[5]=x2[6];x2[6]=x2[7];x2[7]=x3[0];
//**********
x3[0]=x3[1];x3[1]=x3[2];x3[2]=x3[3];x3[3]=x3[4];
x3[4]=x3[5];x3[5]=x3[6];x3[6]=x3[7];x3[7]=x4[0];
//***************
x4[0]=x4[1];x4[1]=x4[2];x4[2]=x4[3];x4[3]=x4[4];
x4[4]=x4[5];x4[5]=x4[6];x4[6]=x4[7];x4[7]=x5[0];
//********************
x5[0]=x5[1];x5[1]=x5[2];x5[2]=x5[3];x5[3]=x5[4];
x5[4]=x5[5];x5[5]=x5[6];x5[6]=x5[7];
}

void HT1632::afficher3(unsigned char x[])//afficher sur l'sclave d'abord puis sur le maitre
// sinon il y a enchevetrement

{//permute();//Si on active les permutes dans les 2 affiches , les lettres deviennent immenses
// avec défilement plus rapide ; reduire j3 dans main() pour ralentir .
unsigned int tata=0;
 cs3_low();cs1_high();cs2_high();
 ht1632_adr1(0);
while(tata<32)// jusqu'à 32 pour couper J1 en trois parties égales ;
{
ht1632_write1(x[tata]);
_delay_us(100);
tata++;
}
 cs3_high();
}



void HT1632::afficher2(unsigned char x[])// afficher sur le digit maitre

{//permute();
unsigned int tata=32;// de 32 à 64 l'autre moitié
 cs2_low();cs1_high();cs3_high();
 ht1632_adr1(0);
while(tata<64)
{
ht1632_write1(x[tata]);
_delay_us(100);
tata++;
}
 cs2_high();
}



void HT1632::afficher1(unsigned char x[])//afficher sur l'sclave d'abord puis sur le maitre
// sinon il y a enchevetrement

{//permute();

unsigned int tata=64;
 cs1_low();cs3_high();cs2_high();
 ht1632_adr1(0);
while(tata<96)// jusqu'à 64 pour couper J1 en trois parties égales ;
{
ht1632_write1(x[tata]);
_delay_us(100);
tata++;
}
 cs1_high();
}


unsigned int HT1632::longueur(unsigned char *x)
//Pour déterminer la fin de la lecture du tableau message: longueur de message  .
{
unsigned int count=0;
while(*x){count++;x++;}
return count;
}

void HT1632::pause(int s)
{while(s--) _delay_ms(1);}


//*****************************************
void HT1632::affiche_font1(unsigned char x[],int i)
{
unsigned int tata=0;
 cs1_low();cs3_high();cs2_high();
 ht1632_adr1(i);
while(tata<8)//
{
ht1632_write1(x[tata]);
_delay_us(100);
tata++;
}
 cs1_high();
}

void  HT1632::affiche_font2(unsigned char x[],int i)
{
unsigned int tata=0;
 cs2_low();cs3_high();cs1_high();
 ht1632_adr1(i);
while(tata<8)//
{
ht1632_write1(x[tata]);
_delay_us(100);
tata++;
}
 cs2_high();
}

void  HT1632::affiche_font3(unsigned char x[],int i)
{
unsigned int tata=0;
 cs3_low();cs2_high();cs1_high();
 ht1632_adr1(i);
while(tata<8)//
{
ht1632_write1(x[tata]);
_delay_us(100);
tata++;
}
 cs3_high();
}


//*************************************Main
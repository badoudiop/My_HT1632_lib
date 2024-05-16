
#ifndef HT1632_h
#define HT1632_h

#include <Arduino.h>


#if ARDUINO >= 100
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#endif

class HT1632
{
private :
int _cs1,_cs2,_cs3, _wr , _data ;

public:
HT1632(int a , int b , int c , int d , int e);

void init(void);
void clear(void);
//**************************************
void charger(unsigned char *x,unsigned char *y,unsigned char *z,unsigned char *u,unsigned char *s,unsigned char *x1,unsigned char *x2,unsigned char *x3,unsigned char *x4,unsigned char *x5);
void tourner(unsigned char *x1,unsigned char *x2,unsigned char *x3,unsigned char *x4,unsigned char *x5);
void afficher1(unsigned char x[]);
void afficher2(unsigned char x[]);
void afficher3(unsigned char x[]);
unsigned int longueur(unsigned char *x);

void ht1632_write(unsigned char x);
void ht1632_adr(unsigned char x);
void permute(unsigned char *x);
void pause(int s);
void  affiche_font1(unsigned char x[],int i);
void  affiche_font2(unsigned char x[],int i);
void  affiche_font3(unsigned char x[],int i);
void ht1632_init(void);
};
#endif



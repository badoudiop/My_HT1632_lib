unsigned char A[8]={0x00,0xfe,0xff,0x11,0x11,0x11,0xfe,0x00};//tableau de A
unsigned char B[8]={0x81,0xff,0xff,0x81,0x81,0x89,0x89,0x76};
unsigned char C[8]={0x00,0x7e,0xff,0x81,0x81,0x81,0x81,0x00};
unsigned char D[8]={0x81,0xff,0xff,0x81,0x81,0x81,0x7e,0x00};
unsigned char E[8]={0x00,0x7e,0xff,0x99,0x99,0x99,0x81,0x00};
unsigned char F[8]={0x00,0xff,0xff,0x19,0x19,0x19,0x01,0x00};
unsigned char G[8]={0x00,0x7e,0xff,0x81,0x81,0x91,0x91,0x00};
unsigned char H[8]={0x00,0xff,0x18,0x18,0x18,0x18,0xff,0x00};
unsigned char I[8]={0x00,0x00,0x81,0xff,0xff,0x81,0x00,0x00};
unsigned char J[8]={0x00,0xe1,0xc1,0xff,0xff,0x01,0x01,0x00};
unsigned char K[8]={0x00,0xff,0xff,0x18,0x24,0x42,0x81,0x00};
unsigned char L[8]={0x00,0xff,0xff,0x80,0x80,0x80,0xc0,0x00};
unsigned char M[8]={0x00,0xff,0x06,0x0c,0x0c,0x06,0xff,0x00};
unsigned char N[8]={0x00,0xff,0xfe,0x18,0x30,0x7f,0xff,0x00};
unsigned char O[8]={0x00,0x7e,0xc3,0xc3,0xc3,0xc3,0x7e,0x00};
unsigned char P[8]={0x00,0xff,0xff,0x11,0x11,0x11,0x1f,0x00};
unsigned char Q[8]={0x00,0x7e,0xc3,0xc3,0xd3,0xe3,0x7e,0x00};
unsigned char R[8]={0x00,0xff,0xff,0x11,0x31,0x51,0x9f,0x00};
unsigned char S[8]={0x00,0x8f,0x99,0x99,0x99,0x99,0xf0,0x00};
unsigned char T[8]={0x00,0x03,0x03,0xff,0xff,0x03,0x03,0x00};
unsigned char U[8]={0x00,0x7f,0xff,0xc0,0xc0,0xff,0x7f,0x00};
unsigned char V[8]={0x00,0x1f,0x7f,0x80,0x80,0x7f,0x1f,0x00};
unsigned char W[8]={0x00,0x3f,0x40,0xf0,0xf0,0x40,0x3f,0x00};
unsigned char X[8]={0x00,0xc7,0x2c,0x18,0x38,0x64,0xc3,0x00};
unsigned char Y[8]={0x00,0x06,0xcc,0xd8,0xd8,0xff,0xff,0x00};
unsigned char Z[8]={0x00,0xc3,0xe3,0xd3,0xcb,0xc7,0xc3,0x00};//tableau de Z

unsigned char vide[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char vir[8]={0,0,128,128,128,96,0,0};
unsigned char inter[8]={0,0,2,1,225,14,0,0,};
unsigned char exc[8]={0,0,0,191,0,0,0,0};
unsigned char dpts[8]={0,0,0,40,0,0,0,0};
unsigned char tir[8]={0,0,8,8,8,0,0};


unsigned char *tab[]={A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,vide,vir,inter,exc,dpts,tir};
//*tab permet un balayage facile : A=tab[0] etc....


unsigned char *mes="    mamadou va a l ecole avec bineta , apres un bon cafe au lait - pain beurre , confiture  ! ils aiment bien les etudes , les maths etc  yeeeees !    ";



//unsigned char *mes="    bonjour tout le monde ,comment allez vous ?  yeeees!!! lundi:mafe,mardi:domoda,mercredi:thiebe-yap,jeudi:yassa-poulet , yees !!        ";

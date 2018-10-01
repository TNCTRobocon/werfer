#ifndef CONTROLLER_H
#define CONTROLLER_H

enum{LSX,LSY,RSX,RSY,RT,LT,DX,DY,BUTTON,A=10,B,X,Y,LB,RB,BACK,START,MIDBUT,LS,RS};

#define lowest -8192 //border
#define highest 8192

void setupcon();
unsigned char getcon();

extern int errnum,reccon[9];
extern struct js_event ebuf;
extern struct js_event joysta;
extern int fd;//game pad file id;

#endif

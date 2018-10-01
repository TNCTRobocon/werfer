#ifndef MOTOR_H
#define MOTOR_H

#define uu1 16//0
#define uu2 17//1
#define uu3 18//2
#define uu4 19//3

#define tirerf 20 //タイヤ右前//4
#define tirelf 21 //タイヤ左前//5
#define tirerb 22 //タイヤ右後//6
#define tirelb 23 //タイヤ左後//7

#define pp1 24//8
#define pp2 25//9


#define mcmax 165 //mc
#define mcmid 100
#define mcmin 40
#define dtmax 0.7 //dt
#define dtmid 0.9 //age+
#define dtmin 0.2

void mcm(int,int);
void dtm(int,float);
void motor(int);
void Front(float);
void Back(float);
void Stop(float);
void motordrive(int,float);

extern int mcsp;
extern float dtsp;
extern int spflag; //dt:0 mc:1
extern int pmflag;

#endif

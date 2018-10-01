#ifndef MOTOR_H
#define MOTOR_H

#define uu1 21//0//////////16↓
#define uu2 22//1
#define uu3 23//2
#define uu4 24//3

#define tirerf 20 //タイヤ右前//4
#define tirelf 21 //タイヤ左前//5
#define tirerb 22 //タイヤ右後//6
#define tirelb 23 //タイヤ左後//7


#define pp1 24//8
#define pp2 25//9

#define mc_test 0.3
#define mcmax 165 //mc
#define mcmid 100
#define mcmin 40
#define dtmax 0.7 //dt
#define dtmid 0.9 //age+
#define dtmin 0.2

#define sel_set(x) x    //自由にselを変えれるやつ
#define dt_set(x) x //自由にdtを変えれるやつ


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

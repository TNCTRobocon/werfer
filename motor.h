#ifndef MOTOR_H
#define MOTOR_H

#define r_out 19//3//////////16↓
#define r_in 17//1
#define l_in 16//0
#define l_out 18//2

#define tirerf 20 //タイヤ右前//4
#define tirelf 21 //タイヤ左前//5
#define tirerb 22 //タイヤ右後//6
#define tirelb 23 //タイヤ左後//7

#define throwwww 27 //sel11

#define pen 26 //ふりこ

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
#define dt_set(x) x     //自由にdtを変えれるやつ

void lift(float);
void lift_stop();
void mcm(int,int);  //mc制御用の関数
void dtm(int,float);//dt制御用の関数
void motor(int);    //上下のやつ
void Front(float);  //前進
void Back(float);   //後退
void Stop(float);   //停止
void motordrive(int,float);

extern int mcsp;
extern float dtsp;
extern int spflag; //dt:0 mc:1
extern int st_status;

#endif

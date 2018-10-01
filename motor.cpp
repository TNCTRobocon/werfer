#include"headers.h"

int mcsp=mcmid;
float dtsp=dtmid;

int spflag=0; //dt:0 mc:1
int st_status=0;

void motor(int a){
	switch(a){
			case DX: //
			case DY: //
			case RT: //
			case LT: //
				break;

			case LB:
			break;

			case RB:

			break;


		    case RSX://
				break;
			case LSX://

				break;

			case LSY://

				break;



			case START://
				break;

			case BACK://リセット
				break;

			case A://押されてる間だけ動く
			if(reccon[BUTTON]&(1<<0)){
			motordrive(uu1,dtsp);//後日調整予定
			printf("1 up\n");
		}else{
			motordrive(uu1,0);
			printf("1 stop\n");
		}
		break;


			case Y://押されている間だけ動く
				if(reccon[BUTTON]&(1<<3)){
					motordrive(uu2,dtsp);//後日調整予定
					printf("2 up\n");
				}else{
					motordrive(uu2,0);
					printf("2 stop\n");
				}
				break;

				case X://押されている間だけ動く
					if(reccon[BUTTON]&(1<<2)){
						motordrive(uu3,dtsp);//後日調整予定
						printf("3 up\n");
					}else{
						motordrive(uu3,0);
						printf("3 stop\n");
					}
					break;

				case B://押されている間だけ動く
					if(reccon[BUTTON]&(1<<1)){
						motordrive(uu4,dtsp);//後日調整予定
						printf("4 up\n");
					}else{
						motordrive(uu4,0);
						printf("4 stop\n");
					}
					break;
				}
			}

void dtm(int id, float dt){ //dt
	serialPrintf(srid,"sel %d\r",id);
	serialPrintf(srid,"dt %.2f\r",dt);
	printf("\ndt %4.2f\r",dt);
	delay(1);
}
void mcm(int id, int mc){ //mc
	serialPrintf(srid,"sel %d\r",id);
	serialPrintf(srid,"rady %d\r",mc);
	if(id==tirelb) serialPrintf(srid,"go\r");
}

void Front(float value){
	printf("\nflont %.2lf\n",value);
	motordrive(tirerf,-value);
	motordrive(tirerb,-value);
	motordrive(tirelf,value);
	motordrive(tirelb,value);
}

void Back(float value){
	printf("\nback %.2lf\n",value);
	motordrive(tirerf,value);
	motordrive(tirerb,value);
	motordrive(tirelf,-value);
	motordrive(tirelb,-value);
}

void Stop(float value){
	value = 0;
	printf("\nstop %.2lf\n",value);
	motordrive(tirerf,value);
	motordrive(tirerb,value);
	motordrive(tirelf,value);
	motordrive(tirelb,value);
}

void motordrive(int id,float value){
	if(spflag==1){
		printf("mc no\n");
		//mcm(id,(int)(value*200));
	}else{
		dtm(id,value);
	}
}

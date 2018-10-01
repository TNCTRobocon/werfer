#include"headers.h"

int srid;
int modeflag;

void setupUART(){
	srid=serialOpen("/dev/ttyS0",115200);
	if(srid<0)
		printf("can not open serialport\n");
	else
	    printf("success open serialport\n");
	serialPrintf(srid,"sel 0\r");
	serialPrintf(srid,"dt 0\r");
	serialPrintf(srid,"mc 0\r");
}

int main(){
	int i = 0;
	errno=0;
	for(i=0;i<9;i++) reccon[i]=0;
	//memset(reccon,0,sizeof(reccon));

	if(wiringPiSetup()==-1){
		printf("error winringPi setup\n");
		return 1;
	}else{
		printf("success wiringPi setup\n");
	}


	setupUART();
	setupcon();
	read(fd,&joysta,sizeof(joysta));
	ebuf=joysta;

	while(1){

		if(modeflag == 0){
			switch(getcon()){
				case DX: //移動
				case DY: //移動
				case LT: //左旋回
				case RT: //右旋回
					if(reccon[RT] < lowest&&reccon[LT] < lowest){
						if(reccon[DY] < lowest){//LSY_前進
							Front(0.7);
							printf("flont\n");
						}else if(reccon[DY] > highest){//LSY_後進
							Back(0.7);
							printf("back\n");
						}else{//停止
							Stop(0);
							printf("stop\n");
						}
					}
					break;

				case RSX: //
					break;
				case RSY: //
					break;
				case LSX: //
					break;
				case LSY: //
					break;

				case LB:
					if(reccon[BUTTON]&(1<<4)){
						motordrive(pp1,-0.5);
						printf("left pooon start\n");
					}else{
						motordrive(pp1,0);
						printf("left pooon stop\n");
					}
					break;

				case RB:
					if(reccon[BUTTON]&(1<<5)){
						motordrive(pp2,-0.5);
						printf("right pooon start\n");
					}else{
						motordrive(pp2,0);
						printf("right pooon stop\n");
					}
					break;

				case Y: //射出スイッチ
				if(pmflag==1){
					dtsp = dtmid;
					printf("%4.2f  ",dtsp);
					if(reccon[BUTTON]&(1<<3)){
						motordrive(uu2,dtsp);//後日調整予定
						printf("2 up\n");
					}else{
						motordrive(uu2,0);
						printf("2 stop\n");
					}
				}else if(pmflag==0){
					dtsp = -dtmid;
					printf("%4.2f  ",dtsp);
					if(reccon[BUTTON]&(1<<3)){
						motordrive(uu2,dtsp);//後日調整予定
						printf("2 up\n");
					}else{
						motordrive(uu2,0);
						printf("2 stop\n");
					}
				}
					break;

				case X: //
				if(pmflag==1){
					dtsp = dtmid;
					printf("%4.2f  ",dtsp);
					if(reccon[BUTTON]&(1<<2)){
						motordrive(uu3,dtsp);//後日調整予定
						printf("3 up\n");
					}else{
						motordrive(uu3,0);
						printf("3 stop\n");
					}
				}else if(pmflag==0){
					dtsp = -dtmid;
					printf("%4.2f  ",dtsp);
					if(reccon[BUTTON]&(1<<2)){
						motordrive(uu3,dtsp);//後日調整予定
						printf("3 up\n");
					}else{
						motordrive(uu3,0);
						printf("3 stop\n");
					}
				}
					break;

				case A: //スロー
					if(pmflag==1){
						dtsp = dtmid;
						printf("%4.2f  ",dtsp);
						if(reccon[BUTTON]&(1<<0)){
							motordrive(uu1,dtsp);//後日調整予定
							printf("1 up\n");
						}else{
							motordrive(uu1,0);
							printf("1 stop\n");
						}
				}else if(pmflag==0){
					dtsp = -dtmid;
					printf("%4.2f  ",dtsp);
					if(reccon[BUTTON]&(1<<0)){
						motordrive(uu1,dtsp);//後日調整予定
						printf("1 up\n");
					}else{
						motordrive(uu1,0);
						printf("1 stop\n");
					}
				}
					break;


				case B: //ダッシュ
				if(pmflag==1){
					dtsp = dtmid;
					printf("%4.2f  ",dtsp);
					if(reccon[BUTTON]&(1<<1)){
						motordrive(uu4,dtsp);//後日調整予定
						printf("4 up\n");
					}else{
						motordrive(uu4,0);
						printf("4 stop\n");
					}
				}else if(pmflag==0){
					dtsp = -dtmid;
					printf("%4.2f  ",dtsp);
					if(reccon[BUTTON]&(1<<1)){
						motordrive(uu4,dtsp);//後日調整予定
						printf("4 up\n");
					}else{
						motordrive(uu4,0);
						printf("4 stop\n");
					}
				}
					break;

				case START: //
				if(reccon[BUTTON]&(1<<7)){
					if(modeflag==0){
						modeflag=1;
						printf("----------------------\n-----setting mode-----\n----------------------\n");
					}else if(modeflag==1){
						modeflag=0;
						printf("----------------------\n-------move mode------\n----------------------\n");
					}
				}else{}
				break;

				case MIDBUT:
					if(reccon[BUTTON]&(1<<8)){
						if(spflag==0){
							spflag=1;
							printf("mc\n");
						}else if(spflag==1){
							spflag=0;
							printf("dt\n");
						}else{}
					}else{}
					break;

				case BACK: //リセット
					if(reccon[BUTTON]&(1<<6)){
						serialPrintf(srid,"sel 0\r");
						serialPrintf(srid,"reboot\r");
						printf("all stop and reboot\n");
					}else{
						printf("completed\n");
					}

					break;
			}
		}else if(modeflag == 1){//setting
			switch(getcon()){
				case DX: //移動
				case DY: //移動
				case LT: //左旋回
				case RT: //右旋回
					if(reccon[RT] < lowest&&reccon[LT] < lowest){
						if(reccon[DY] < lowest){//LSY_前進
						}else if(reccon[DY] > highest){//LSY_後進
						}else{//停止
						}
					}
					break;

				case RSX: //
					break;
				case RSY: //
					break;
				case LSX: //
					break;
				case LSY: //
					break;

				case LB:
					if(reccon[BUTTON]&(1<<4)){
					}else{
					}
					break;

				case RB:
					if(reccon[BUTTON]&(1<<5)){
					}else{
					}
					break;

				case Y: //
				if(pmflag==1){

				}else if(pmflag==0){
				}
					break;

				case X: //
				if(pmflag==1){
				}else if(pmflag==0){
				}
					break;

				case A: //
				if(pmflag==1){
				}else if(pmflag==0){
				}
					break;


				case B: //ダッシュ
				if(pmflag==1){
				}else if(pmflag==0){
				}
					break;




				case START: //
				if(reccon[BUTTON]&(1<<7)){
					if(modeflag==0){
						modeflag=1;
						printf("----------------------\n-----setting mode-----\n----------------------\n");
					}else if(modeflag==1){
						modeflag=0;
						printf("----------------------\n-------move mode------\n----------------------\n");
					}
				}else{}
				break;


				case MIDBUT:
					if(reccon[BUTTON]&(1<<8)){
						if(spflag==0){
							spflag=1;
							printf("mc\n");
						}else if(spflag==1){
							spflag=0;
							printf("dt\n");
						}else{}
					}else{}
					break;

				case BACK: //リセット
					if(reccon[BUTTON]&(1<<6)){
						serialPrintf(srid,"sel 0\r");
						serialPrintf(srid,"reboot\r");
						printf("all stop and reboot\n");
					}else{
						printf("completed\n");
					}
					break;
			}
		}
	}
}

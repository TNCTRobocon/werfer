#include"headers.h"

int srid;

void setupUART(){
	srid=serialOpen("/dev/ttyS0",115200);
	if(srid<0)
		printf("can not open serialport\nq	");
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
		switch(getcon()){
			case DX: //移動
			case DY: //移動
			case LT: //左旋回
			case RT: //右旋回
				if(reccon[RT] < lowest&&reccon[LT] < lowest){
					if(reccon[DY] < lowest){//LSY_前進
						Front(0.7);			//dt 0.7で前進
						printf("flont\n");
					}else if(reccon[DY] > highest){//LSY_後進
						Back(0.7);			//dt 0.7で後退
						printf("back\n");
					}else{//停止
						Stop(0);			//停止
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

			case LB://左射出
				if(reccon[BUTTON]&(1<<4)){
					motordrive(pp1,-0.5);//dt 0.5で回転
					printf("left pooon start\n");
				}else{
					motordrive(pp1,0);	//停止
					printf("left pooon stop\n");
				}
				break;

			case RB://右射出
				if(reccon[BUTTON]&(1<<5)){
					motordrive(pp2,-0.5);//dt 0.5で回転
					printf("right pooon start\n");
				}else{
					motordrive(pp2,0);	//停止
					printf("right pooon stop\n");
				}
				break;
			case Y:
				if(st_status==1){	//個別
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);
				motor(Y);	//dt 0.9で回転
			}else if(st_status==0){//まとめて
				break;
			}
			break;
			case X:
				if(st_status==1){	//個別
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);
				motor(X);	//dt 0.9で回転
			}else if(st_status==0){//まとめて
				break;
			}
			break;
			case A: //スロー
			if(st_status==1){	//個別
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);//dt 0.9
				motor(A);
			}else if(st_status==0){//まとめて上昇
				dtsp = dtmid;
				printf("up");
				motor(A);
				motor(B);
				motor(X);
				motor(Y);
			}
			break;
			case B: //個別
			if(st_status==1){
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);
				motor(B);
			}else if(st_status==0){	//まとめて下降
				dtsp = -dtmid;
				printf("dowm");
				motor(A);
				motor(B);
				motor(X);
				motor(Y);
			}
			break;
			/*case Y:	//
			if(st_status==1){	//下降
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);
				motor(Y);	//dt 0.9で回転
			}else if(st_status==0){//上昇
				dtsp = -dtmid;
				printf("%4.2f  ",dtsp);
				motor(Y);	//dt -0.9で回転
			}
				break;

			case X: //
			if(st_status==1){
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);
				motor(X);	//dt 0.9で回転
			}else if(st_status==0){
				dtsp = -dtmid;
				printf("%4.2f  ",dtsp);
				motor(X);	//dt -0.9で回転
			}
				break;
			case A: //スロー
			if(st_status==1){
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);
				motor(A);
			}else if(st_status==0){
				dtsp = -dtmid;
				printf("%4.2f  ",dtsp);
				motor(A);
			}
				break;


			case B: //ダッシュ
			if(st_status==1){
				dtsp = dtmid;
				printf("%4.2f  ",dtsp);
				motor(B);
			}else if(st_status==0){
				dtsp = -dtmid;
				printf("%4.2f  ",dtsp);
				motor(B);
			}
				break;
*/



			case START: //
			if(reccon[BUTTON]&(1<<7)){
				if(st_status==0){
					st_status=1;
					printf("separate\n");
				}else if(st_status==1){
					st_status=0;
					printf("together\n");
				}else{}
			}else{}
			break;
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

			/*default:
				motor(50);
				break;*/

		}
	}
}

#include "headers.h"
#include "func.h"

int srid;

void setupUART()
{
	srid = serialOpen("/dev/ttyS0", 115200);
	if (srid < 0)
		printf("can not open serialport\nq	");
	else
		printf("success open serialport\n");
	serialPrintf(srid, "sel 0\r");
	serialPrintf(srid, "dt 0\r");
	serialPrintf(srid, "mc 0\r");
}

#define	TGE 0
#define	SEP 1


int main()
{
	int i = 0;
	errno = 0;
	int (*func[2])(int); //関数ポインタ（）
	func[0] = together;  //同時に上昇したりする関数
	func[1] = separate;  //個別に上下するやつ

	for (i = 0; i < 9; i++)
		reccon[i] = 0;
	//memset(reccon,0,sizeof(reccon));

	if (wiringPiSetup() == -1)
	{
		printf("error winringPi setup\n");
		return 1;
	}
	else
	{
		printf("success wiringPi setup\n");
	}

	setupUART();
	setupcon();
	read(fd, &joysta, sizeof(joysta));
	ebuf = joysta;

	while (1)
	{
		func[TGE](getcon()); //まとめて昇降するやつ
		//func[SEP](getcon());	//個別に昇降するやつ
		switch (getcon())
		{
		case DX: //移動
		case DY: //移動
		case LT: //左旋回
		case RT: //右旋回
			if (reccon[RT] < lowest && reccon[LT] < lowest)
			{
				if (reccon[DY] < lowest)
				{				//LSY_前進
					Front(0.7); //dt 0.7で前進
					printf("flont\n");
				}
				else if (reccon[DY] > highest)
				{			   //LSY_後進
					Back(0.7); //dt 0.7で後退
					printf("back\n");
				}
				else
				{			 //停止
					Stop(0); //停止
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

		case LB: //左射出
			if (reccon[BUTTON] & (1 << 4))
			{
				motordrive(pp1, -0.5); //dt 0.5で回転
				printf("left pooon start\n");
			}
			else
			{
				motordrive(pp1, 0); //停止
				printf("left pooon stop\n");
			}
			break;

		case RB: //右射出
			if (reccon[BUTTON] & (1 << 5))
			{
				motordrive(pp2, -0.5); //dt 0.5で回転
				printf("right pooon start\n");
			}
			else
			{
				motordrive(pp2, 0); //停止
				printf("right pooon stop\n");
			}
			break;
		case MIDBUT:
			if (reccon[BUTTON] & (1 << 8))
			{
				if (spflag == 0)
				{
					spflag = 1;
					printf("mc\n");
				}
				else if (spflag == 1)
				{
					spflag = 0;
					printf("dt\n");
				}
				else
				{
				}
			}
			else
			{
			}
			break;

		case BACK: //リセット
			if (reccon[BUTTON] & (1 << 6))
			{
				serialPrintf(srid, "sel 0\r");
				serialPrintf(srid, "reboot\r");
				printf("all stop and reboot\n");
			}
			else
			{
				printf("completed\n");
			}

			break;

		default:
			break;
		}
	}
}


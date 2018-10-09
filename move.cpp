#include "headers.h"

void move()
{
	switch (getcon())
	{
	case DX: //移動
	case DY: //移動
	case LT: //左旋回
	case RT: //右旋回
		if (reccon[RT] < lowest && reccon[LT] < lowest)
		{
			if (reccon[DY] < lowest)
			{ //LSY_前進
				Front(0.7);
				printf("flont\n");
			}
			else if (reccon[DY] > highest)
			{ //LSY_後進
				Back(0.7);
				printf("back\n");
			}
			else
			{ //停止
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
		if (reccon[BUTTON] & (1 << 4))
		{
			motordrive(pp1, -0.5);
			printf("left pooon start\n");
		}
		else
		{
			motordrive(pp1, 0);
			printf("left pooon stop\n");
		}
		break;

	case RB:
		if (reccon[BUTTON] & (1 << 5))
		{
			motordrive(pp2, 0.5);
			printf("right pooon start\n");
		}
		else
		{
			motordrive(pp2, 0);
			printf("right pooon stop\n");
		}
		break;

	case Y: //なだれ
		dtsp = -0.3;
		printf("%4.2f  ", dtsp);
		if (reccon[BUTTON] & (1 << 3))
		{
			motordrive(throwwww, dtsp);
			printf("penduram start\n");
		}
		else
		{
			motordrive(throwwww, 0);
			printf("penduram stop\n");
		}
		break;

	case X: //滑り台
		dtsp = -0.3;
		printf("%4.2f  ", dtsp);
		if (reccon[BUTTON] & (1 << 2))
		{
			motordrive(pen, dtsp);
			printf("throwwww\n");
		}
		else
		{
			motordrive(pen, 0);
			printf("throwww stop\n");
		}
		break;

	case A: //スロー
		dtsp = dtmid;
		//printf("%4.2f  ", dtsp);
		if (reccon[BUTTON] & (1 << 0))
		{
			lift(dtsp);
			printf("lift move up\n");
		}
		else
		{
			lift_stop();
			printf("lift stop\n");
		}
		break;

	case B: //ダッシュ
		dtsp = -dtmid;
		if (reccon[BUTTON] & (1 << 1))
		{
			lift(dtsp);
			printf("lift move down\n");
		}
		else
		{
			lift_stop();
			printf("lift stop\n");
		}
		break;

	case START: //
		if (reccon[BUTTON] & (1 << 7))
		{
			if (st_status == 0)
			{
				st_status = 1;
				printf("----------------------\n-----setting mode-----\n----------------------\n");
			}
			else if (st_status == 1)
			{
				st_status = 0;
				printf("----------------------\n-------move mode------\n----------------------\n");
			}
		}
		else
		{
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
	}
}

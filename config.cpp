#include "headers.h"
/*キャリブレーション時のプログラム*/
void lift_in_right()//右の内側
{
	if (reccon[RSY] > highest)//上昇
	{
		dtsp = dtmid;
			motordrive(r_in, dtsp);
		printf("right inside up\n");
	}
	else if (reccon[RSY] < lowest)//下降
	{
		dtsp = -dtmid;
			motordrive(r_in, dtsp);
		printf("right inside down\n");
	}
	else
	{
		motordrive(r_in, 0);
		printf("right inside stop\n");
	}
}
/*左内側の昇降*/
void lift_in_left()
{
	if (reccon[LSY] > highest)
	{
		dtsp = dtmid;
			motordrive(l_in, dtsp);
		printf("left inside up\n");
	}
	else if (reccon[LSY] < lowest)
	{
		dtsp = -dtmid;
			motordrive(l_in, dtsp);
			printf("left inside down\n");
	}
	else
	{
		motordrive(l_in, 0);
		printf("left inside stop\n");
	}
}

void config()
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
			{ //LSY_上昇
				dtsp = dtmid;
					motordrive(l_out, dtsp);
				printf("left outside up\n");
			}
			else if (reccon[DY] > highest)
			{ //LSY＿下降
				dtsp = -dtmid;
					motordrive(l_out, dtsp);
				printf("left outside down\n");
			}
			else
			{ //停止
					motordrive(l_out, 0);
				printf("left outside stop\n");
			}
		}
		break;

	case RSX: //
		break;
	case RSY: //
		lift_in_right();
		break;
	case LSX: //
		break;
	case LSY: //
		lift_in_left();
		break;

	case LB:
		if (reccon[BUTTON] & (1 << 4))
		{
			motordrive(pen, -0.3);
			printf("penduram start\n");
		}
		else
		{
			motordrive(pen, 0);
			printf("penduram stop\n");
		}
		break;
	case RB:
		if (reccon[BUTTON] & (1 << 5))
		{
			motordrive(pen, 0.3);
			printf("config penduram\n");
		}
		else
		{
			motordrive(pen, 0);
			printf("penduram stop\n");
		}
		break;
	case Y: //右外上昇
		dtsp = -dtmid;
		if (reccon[BUTTON] & (1 << 3))
		{
				motordrive(r_out, dtsp);
		}
		else
		{
			motordrive(r_out, 0);
			printf("right outside stop\n");
		}
		break;

	case X: //

	case A: //右外下降
		dtsp = dtmid;
		if (reccon[BUTTON] & (1 << 0))
		{

				motordrive(r_out, dtsp);
			printf("right outside down\n");
		}
		else
		{
			motordrive(r_out, 0);
			printf("right outside stop\n");
		}

	case B:		//ダッシュ
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

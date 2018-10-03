#include "headers.h"

void lift_in_right()
{
	if (reccon[RSY] > highest)
	{
		dtsp = dtmid;
		motordrive(r_in, dtdp);
		printf("right outside up\n");
	}
	else if (reccon[RSY] < lowest)
	{
		dtsp = -dtmid;
		motordrive(r_in, dtdp);
		printf("right outside down\n");
	}
	else
	{
		motordrive(r_in, 0);
		printf("right inside stop\n");
	}
}

void lift_in_right(){
	if (reccon[LSY] > highest)
	{
		dtsp = dtmid;
		motordrive(l_in, dtdp);
		printf("left outside up\n");
	}
	else if (reccon[LSY] < lowest)
	{
		dtsp = -dtmid;
		motordrive(l_in, dtdp);
		printf("left outside down\n");
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
			{ //LSY_前進
				dtsp = dtmid;
				motordrive(l_out, dtsp);
				printf("left outside up\n");
			}
			else if (reccon[DY] > highest)
			{ //LSY_後進
				dtsp = -dtmid;
				motordrive(l_out, dtsp);
				printf("left outside down\n");
			}
			else
			{ //停止
				motordrive(l_out, 0);
				printf("left out stop\n");
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
		}
		else
		{
		}
		break;

	case RB:
		if (reccon[BUTTON] & (1 << 5))
		{
		}
		else
		{
		}
		break;

	case Y: //射出スイ
		dtsp = dtmid;
		printf("%4.2f  ", dtsp);
		if (reccon[BUTTON] & (1 << 3))
		{
			motordrive(r_out, dtsp);
			printf("right outside up\n");
		}
		else
		{
			motordrive(r_out, 0);
			printf("right outside stop\n");
		}
	}
	break;

case X: //

case A: //スロー
	dtsp = -dtmid;
	printf("%4.2f  ", dtsp);
	if (reccon[BUTTON] & (1 << 3))
	{
		motordrive(r_out, dtsp);
		printf("right outside down\n");
	}
	else
	{
		motordrive(r_out, 0);
		printf("right outside stop\n");
	}
}

case B:		//ダッシュ
case START: //
if (reccon[BUTTON] & (1 << 7))
{
	if (modeflag == 0)
	{
		modeflag = 1;
		printf("----------------------\n-----setting mode-----\n----------------------\n");
	}
	else if (modeflag == 1)
	{
		modeflag = 0;
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
			motordrive(pp2, -0.5);
			printf("right pooon start\n");
		}
		else
		{
			motordrive(pp2, 0);
			printf("right pooon stop\n");
		}
		break;

	case Y: //射出スイッチ
		if (pmflag == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 3))
			{
				motordrive(uu2, dtsp); //後日調整予定
				printf("2 up\n");
			}
			else
			{
				motordrive(uu2, 0);
				printf("2 stop\n");
			}
		}
		else if (pmflag == 0)
		{
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 3))
			{
				motordrive(uu2, dtsp); //後日調整予定
				printf("2 up\n");
			}
			else
			{
				motordrive(uu2, 0);
				printf("2 stop\n");
			}
		}
		break;

	case X: //
		if (pmflag == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 2))
			{
				motordrive(uu3, dtsp); //後日調整予定
				printf("3 up\n");
			}
			else
			{
				motordrive(uu3, 0);
				printf("3 stop\n");
			}
		}
		else if (pmflag == 0)
		{
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 2))
			{
				motordrive(uu3, dtsp); //後日調整予定
				printf("3 up\n");
			}
			else
			{
				motordrive(uu3, 0);
				printf("3 stop\n");
			}
		}
		break;

	case A: //スロー
		if (pmflag == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 0))
			{
				motordrive(uu1, dtsp); //後日調整予定
				printf("1 up\n");
			}
			else
			{
				motordrive(uu1, 0);
				printf("1 stop\n");
			}
		}
		else if (pmflag == 0)
		{
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 0))
			{
				motordrive(uu1, dtsp); //後日調整予定
				printf("1 up\n");
			}
			else
			{
				motordrive(uu1, 0);
				printf("1 stop\n");
			}
		}
		break;

	case B: //ダッシュ
		if (pmflag == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 1))
			{
				motordrive(uu4, dtsp); //後日調整予定
				printf("4 up\n");
			}
			else
			{
				motordrive(uu4, 0);
				printf("4 stop\n");
			}
		}
		else if (pmflag == 0)
		{
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			if (reccon[BUTTON] & (1 << 1))
			{
				motordrive(uu4, dtsp); //後日調整予定
				printf("4 up\n");
			}
			else
			{
				motordrive(uu4, 0);
				printf("4 stop\n");
			}
		}
		break;

	case START: //
		if (reccon[BUTTON] & (1 << 7))
		{
			if (modeflag == 0)
			{
				modeflag = 1;
				printf("----------------------\n-----setting mode-----\n----------------------\n");
			}
			else if (modeflag == 1)
			{
				modeflag = 0;
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
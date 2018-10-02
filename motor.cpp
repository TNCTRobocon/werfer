#include "headers.h"

int mcsp = mcmid;
float dtsp = dtmid;

int spflag = 0; //dt:0 mc:1
int st_status = 1;

void motor(int a)
{
	switch (a)
	{
	case DX: //
	case DY: //
	case RT: //
	case LT: //
		break;

	case LB:
		break;

	case RB:

		break;

	case RSX: //
		break;
	case LSX: //

		break;

	case LSY: //

		break;

	case START: //
		break;

	case BACK: //リセット
		break;

	case A: //押されてる間だけ動く
		if (reccon[BUTTON] & (1 << 0))
		{
			motordrive(r_out, dtsp); //後日調整予定
			printf("right outside move\n");
		}
		else
		{
			motordrive(r_out, 0);
			//printf("right outside stop\n");
		}
		break;

	case Y: //押されている間だけ動く
		if (reccon[BUTTON] & (1 << 3))
		{
			motordrive(r_in, dtsp); //後日調整予定
			printf("right inside move\n");
		}
		else
		{
			motordrive(r_in, 0);
			//printf("right inside stop\n");
		}
		break;

	case X: //押されている間だけ動く
		if (reccon[BUTTON] & (1 << 2))
		{
			motordrive(l_in, dtsp); //後日調整予定
			printf("left outside move\n");
		}
		else
		{
			motordrive(l_in, 0);
			//printf("left inside stop\n");
		}
		break;

	case B: //押されている間だけ動く
		if (reccon[BUTTON] & (1 << 1))
		{
			motordrive(l_out, dtsp); //後日調整予定
			printf("left outside move\n");
		}
		else
		{
			motordrive(l_out, 0);
			printf("\n");
			//printf("left outside stop\n");
		}
		break;
	}
}

void dtm(int id, float dt)
{ //dt
	serialPrintf(srid, "sel %d\r", id);
	serialPrintf(srid, "dt %.2f\r", dt);
	printf("\ndt %4.2f\r", dt);
	delay(1);
}
void mcm(int id, int mc)
{ //mc
	serialPrintf(srid, "sel %d\r", id);
	serialPrintf(srid, "rady %d\r", mc);
	if (id == tirelb)
		serialPrintf(srid, "go\r");
}

void Front(float value)
{
	printf("\nflont %.2lf\n", value);
	motordrive(tirerf, -value);
	motordrive(tirerb, -value);
	motordrive(tirelf, value);
	motordrive(tirelb, value);
}

void Back(float value)
{
	printf("\nback %.2lf\n", value);
	motordrive(tirerf, value);
	motordrive(tirerb, value);
	motordrive(tirelf, -value);
	motordrive(tirelb, -value);
}

void Stop(float value)
{
	value = 0;
	printf("\nstop %.2lf\n", value);
	motordrive(tirerf, value);
	motordrive(tirerb, value);
	motordrive(tirelf, value);
	motordrive(tirelb, value);
}

void motordrive(int id, float value)
{
	if (spflag == 1)
	{
		printf("mc no\n");
	}
	else
	{
		dtm(id, value);
	}
}

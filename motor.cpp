#include "headers.h"

int mcsp = mcmid;
float dtsp = dtmid;

int spflag = 0; //dt:0 mc:1
int st_status = 1;

void lift(int value){
	motordrive(r_in,value);
	motordrive(r_out,value);
	motordrive(l_in,value);
	motordrive(l_out,value);
	printf("lifting\n");
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

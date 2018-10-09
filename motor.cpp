#include "headers.h"

int mcsp = mcmid;
float dtsp = dtmid;

int spflag = 0; //dt:0 mc:1
int st_status = 1;

void lift(float value){
	motordrive(r_in,value);
	motordrive(r_out,-value);
	motordrive(l_in,value);
	motordrive(l_out,value);
}
void lift_stop(){
	int value = 0;
	motordrive(r_in,value);
	motordrive(r_out,value);
	motordrive(l_in,value);
	motordrive(l_out,value);
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
	serialPrintf(srid, "mc %d\r", mc);
	printf("\nmc %4.2f\r", mc);
	delay(1);
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
		mcm(id,value);
	}
	else
	{
		dtm(id, value);
	}
}

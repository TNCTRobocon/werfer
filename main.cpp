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

int main()
{
	int i = 0;
	errno = 0;

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
		if (!st_status) //キャリブレーションの時は動かない
		{
			move();
		}
		else if (st_status)
		{
			config();
		}
	}
}

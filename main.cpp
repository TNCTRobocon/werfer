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

#define TGE 0
#define SEP 1

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
		//func[TGE](getcon()); //まとめて昇降するやつ
		func[SEP](getcon()); //個別に昇降するやつ
		if (!st_status)//キャリブレーションの時は動かない
		{
			config();
		}else(st_status){
			move();
		}
		}
	}

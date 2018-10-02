#include "headers.h"
void together(int con)
{
	switch (con)
	{
	case Y:
		if (st_status == 1)
		{ //個別
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			motor(Y); //dt 0.9で回転
		}
		else if (st_status == 0)
		{ //まとめて
			break;
		}
		break;
	case X:
		if (st_status == 1)
		{ //個別
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			motor(X); //dt 0.9で回転
		}
		else if (st_status == 0)
		{ //まとめて
			break;
		}
		break;
	case A: //スロー
		if (st_status == 1)
		{ //個別
			dtsp = dtmid;
			printf("%4.2f  ", dtsp); //dt 0.9
			motor(A);
		}
		else if (st_status == 0)
		{ //まとめて上昇
			dtsp = dtmid;
			printf("up");
			motor(A);
			motor(B);
			motor(X);
			motor(Y);
		}
		break;
	case B: //個別
		if (st_status == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			motor(B);
		}
		else if (st_status == 0)
		{ //まとめて下降
			dtsp = -dtmid;
			printf("dowm");
			motor(A);
			motor(B);
			motor(X);
			motor(Y);
		}
		break;
	case START: //
		if (reccon[BUTTON] & (1 << 7))
		{
			if (st_status == 0)
			{
				st_status = 1;
				printf("calibration\n");
			}
			else if (st_status == 1)
			{
				st_status = 0;
				printf("process now\n");
			}
			else
			{
			}
		}
		else
		{
		}
	}
}

void separate(int con)
{
	switch (con)
	{
	case Y: //
		if (st_status == 1)
		{ //下降
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			motor(Y); //dt 0.9で回転
		}
		else if (st_status == 0)
		{ //上昇
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			motor(Y); //dt -0.9で回転
		}
		break;

	case X: //
		if (st_status == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			motor(X); //dt 0.9で回転
		}
		else if (st_status == 0)
		{
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			motor(X); //dt -0.9で回転
		}
		break;
	case A: //スロー
		if (st_status == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			motor(A);
		}
		else if (st_status == 0)
		{
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			motor(A);
		}
		break;

	case B: //ダッシュ
		if (st_status == 1)
		{
			dtsp = dtmid;
			printf("%4.2f  ", dtsp);
			motor(B);
		}
		else if (st_status == 0)
		{
			dtsp = -dtmid;
			printf("%4.2f  ", dtsp);
			motor(B);
		}
		break;
	case START: //
		if (reccon[BUTTON] & (1 << 7))
		{
			if (st_status == 0)
			{
				st_status = 1;
				printf("dowm\n");
			}
			else if (st_status == 1)
			{
				st_status = 0;
				printf("up\n");
			}
			else
			{
			}
		}
		else
		{
		}
	}
}

#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <iomanip>
#include "TapXacDinh.h"
#include "Equation.h"
#include "MinMax.h"
#define epsilon 1e-5
extern FILE * input, * output;
using namespace std;

void MinMax(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:
	{
		MinMax_1();
		break;
	}
	case 2:
	{
		MinMax_2(a, b, c);
		break;
	}
	case 3:
	{
		MinMax_3(a, b, c, d);
		break;
	}
	case 4:
	{
		MinMax_4(a, b, c);
		break;
	}
	case 5:
	{
		MinMax_5();
		break;
	}
	case 6:
	{
		MinMax_6(a, b, c, d, e);
		break;
	}
	default:
		break;
	}
}

void MinMax_1()
{
	fprintf(output, "Ham so khong co cuc tieu hay cuc dai !!!\n");
}

void MinMax_2(float a, float  b, float  c)
{
	if (a < 0)
	{
		fprintf(output, "Ham so khong co cuc tieu!!!\n");
		float x1 = (-b) / (2 * a);
		float MAX = a * pow(x1, 2) + b * x1 + c;
		fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", x1, MAX);
	}
	else if (a > 0)
	{
		float x1 = (-b) / (2 * a);
		float MIN = a * pow(x1, 2) + b * x1 + c;
		fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", x1, MIN);
		fprintf(output, "Ham so khong co cuc dai!!!\n");
	}
}

void MinMax_3(float a, float b, float c, float d)
{
	float a1 = 3 * a, b1 = 2 * b, c1 = c;
	float x, y;
	short z;
	GiaiPT_Bac2(a1, b1, c1, x, y, z);
	if (z == -1 || z == 0)
	{
		fprintf(output, "Ham so khong cuc dai va cuc tieu!!!\n");
	}
	else
	{
		float X1, X2;
		if (a < 0)
		{
			float MAX, MIN;
			if (x < y)
			{
				MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X1 = x;
				MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X2 = y;
			}
			else
			{
				MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X2 = x;
				MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X1 = y;
			}
			fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", X1, MIN);
			fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", X2, MAX);
		}
		else
		{
			float MAX, MIN;
			if (x < y)
			{
				float MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X1 = x;
				float MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X2 = y;
			}
			else
			{
				float MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X2 = x;
				float MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X1 = y;
			}
			fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", X1, MIN);
			fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", X2, MAX);
		}
	}
}

void MinMax_4(float a, float b, float c)
{
	float a1 = 4 * a, b1 = 2 * a;
	if (a > 0 && b >= 0)
	{
		fprintf(output, "Ham so co cuc tieu la: (%d, %10f)\n", 0, c);
		fprintf(output, "Ham so khong co cuc dai!!!\n");
	}
	else if (a < 0 && b <= 0)
	{
		fprintf(output, "Ham so khong co cuc tieu!!!\n");
		fprintf(output, "Ham so co cuc dai la: (%d, %10f)\n", 0, c);
	}
	else if (a > 0 && b < 0)
	{
		float delta;
		delta = b * b - 4 * a * c;
		fprintf(output, "Ham so co 2 cuc tieu la: (%.2f , %.2f) va (%.2f , %.2f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
		fprintf(output, "Ham so co 1 cuc dai la: (%d , %.2f)", 0, c);
	}
	else if (a < 0 && b > 0)
	{
		float delta;
		delta = b * b - 4 * a * c;
		fprintf(output, "Ham so co 1 cuc tieu la: (%d , %.2f)", 0, c);
		fprintf(output, "Ham so co 2 cuc dai la: (%.2f , %.2f) va (%.2f , %.2f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
	}
}

void MinMax_5()
{
	fprintf(output, "Ham so khong co cuc tieu hay cuc dai !!!\n");
}

void MinMax_6(float a, float b, float c, float d, float e)
{
	float a1 = a * d;
	float b1 = 2 * a * e;
	float c1 = b * e - c * d;
	float x, y;
	short z;
	GiaiPT_Bac2(a1, b1, c1, x, y, z);
	if (z == -1 || z == 0)
		fprintf(output, "Ham so khong co cuc tieu hay cuc dai !!!\n");
	else
	{
		if (Equa_2(a1, b1, c1, x - epsilon) > 0 && Equa_2(a1, b1, c1, x + epsilon) < 0)
		{
			fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", x, Equa_6(a, b, c, d, e, x));
			fprintf(output, "Ham so co cuc dai la: (%10f, %10f)\n", y, Equa_6(a, b, c, d, e, y));
		}
		else
		{
			fprintf(output, "Ham so co cuc tieu la: (%10f, %10f)\n", y, Equa_6(a, b, c, d, e, y));
			fprintf(output, "Ham so co cuc dai la: (%10f, %10f)\n", x, Equa_6(a, b, c, d, e, x));
		}
	}
}

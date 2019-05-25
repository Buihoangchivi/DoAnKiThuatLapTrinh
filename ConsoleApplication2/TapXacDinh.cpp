#include "TapXacDinh.h"
#include "Equation.h"
#include <iostream>
#include <cmath>

#define _CRT_NONSTDC_NO_WARNINGS

extern FILE* input, * output;

using namespace std;

void TapXacDinh(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:
		TapXacDinh_1();
		break;
	case 2:
		TapXacDinh_2();
		break;
	case 3:
		TapXacDinh_3();
		break;
	case 4:
		TapXacDinh_4();
		break;
	case 5:
		TapXacDinh_5(a, b, c, d);
		break;
	case 6:
		TapXacDinh_6(a, b, c, d, e);
		break;
	default:
		break;
	}
}

void TapXacDinh_1()
{
	fprintf(output, "Tap xac dinh cua Ham so la R\n");
}

void TapXacDinh_2()
{
	fprintf(output, "Tap xac dinh cua Ham so la R\n");
}

void TapXacDinh_3()
{
	fprintf(output, "Tap xac dinh cua Ham so la R\n");
}

void TapXacDinh_4()
{
	fprintf(output, "Tap xac dinh cua Ham so la R\n");
}

void TapXacDinh_5(float a, float b, float c, float d)
{
	if (d != 0) fprintf(output, "Tap xac dinh cua Ham so la R \\ {%.2f}\n", -d / c);
	else fprintf(output, "Tap xac dinh cua Ham so la R \\ {0}\n");
}

void TapXacDinh_6(float a, float b, float c, float d, float e)
{
	if (e != 0) fprintf(output, "Tap xac dinh cua Ham so la R \\ {%.2f}\n", -e / d);
	else fprintf(output, "Tap xac dinh cua Ham so la R \\ {0}\n");
}

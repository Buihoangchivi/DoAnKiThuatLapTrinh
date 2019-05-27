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
	case 1:case 2:case 3:case 4:case 14:case 15:
		TapXacDinh_1();
		break;
	case 5:
		TapXacDinh_2(a, b, c, d);
		break;
	case 6:
		TapXacDinh_3(a, b, c, d, e);
		break;
	case 16:
		TapXacDinh_4();
		break;
	case 17:
		TapXacDinh_5();
	default:
		break;
	}
}

void TapXacDinh_1()
{
	fprintf(output, "Tap xac dinh cua Ham so la R\n");
}

void TapXacDinh_2(float a, float b, float c, float d)
{
	if (d != 0) fprintf(output, "Tap xac dinh cua Ham so la R \\ {%.2f}\n", -d / c);
	else fprintf(output, "Tap xac dinh cua Ham so la R \\ {0}\n");
}

void TapXacDinh_3(float a, float b, float c, float d, float e)
{
	if (e != 0) fprintf(output, "Tap xac dinh cua Ham so la R \\ {%.2f}\n", -e / d);
	else fprintf(output, "Tap xac dinh cua Ham so la R \\ {0}\n");
}

void TapXacDinh_4()
{
	if (output == stdout) fprintf(output, "Tap xac dinh cua Ham so la R \\ {%c / 2 + k%c} (k thuoc Z)}\n", 227, 227);
	fprintf(output, "Tap xac dinh cua Ham so la R \\ {Pi / 2 + k*Pi} (k thuoc Z)}\n");
}

void TapXacDinh_5()
{
	if (output == stdout) fprintf(output, "Tap xac dinh cua Ham so la R \\ {k%c} (k thuoc Z)}\n", 227);
	fprintf(output, "Tap xac dinh cua Ham so la R \\ {k * Pi} (k thuoc Z)}\n");
}
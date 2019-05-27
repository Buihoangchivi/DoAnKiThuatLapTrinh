#include <iostream>
#include <cmath>
#include "Input_Output.h"
#include "Equation.h"
#include "Daoham.h"
#define epsilon 1e-5

#define _CRT_NONSTDC_NO_WARNINGS

extern FILE * input, * output;

using namespace std;

void DaoHam_XetDau(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:
		DaoHam1(a, b);
		break;
	case 2:
		DaoHam2(a, b, c);
		break;
	case 3:
		DaoHam3(a, b, c, d);
		break;
	case 4:
		DaoHam4(a, b, c);
		break;
	case 5:
		DaoHam5(a, b, c, d);
		break;
	case 6:
		DaoHam6(a, b, c, d, e);
		break;
	case 14:
		DaoHam14();
		break;
	case 15:
		DaoHam15();
		break;
	case 16:
		DaoHam16();
		break;
	case 17:
		DaoHam17();
		break;
	case 18:
		DaoHam18(a, b);
		break;
	case 19:
		DaoHam19(a, b, c);
		break;
	case 20:
		DaoHam20(a, b, c, d);
		break;
	case 21:
		DaoHam21(a, b, c);
		break;
	case 22:
		DaoHam22(a, b, c, d);
		break;
	case 23:
		DaoHam23(a, b, c, d, e);
		break;
	default:
		break;
	}
}

void XetDau0(float a)
{
	if (a == 0) fprintf(output, "\tDao ham luon bang 0 voi moi x thuoc R\n");
	else if (a < 0) fprintf(output, "\tDao ham luon am voi moi x thuoc R\n");
	else fprintf(output, "\tDao ham luon duong voi moi x thuoc R\n");
}

void XetDau1(float a, float b)
{
	if (a > 0)
	{
		if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c, %.2f)\n", (char)236, -b / a);
		else fprintf(output, "\tDao ham luon am voi x thuoc (-oo, %.2f)\n", -b / a);
		fprintf(output, "\tDao ham bang 0 voi x = %.2f\n", -b / a);
		if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, +%c)\n", -b / a, (char)236);
		else fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, +oo)\n", -b / a);
	}
	else
	{
		if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, %.2f)\n", (char)236, -b / a);
		else fprintf(output, "\tDao ham luon duong voi x thuoc (-oo, %.2f)\n", -b / a);
		fprintf(output, "\tDao ham bang 0 voi x = %.2f\n", -b / a);
		if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, +%c)\n", -b / a, (char)236);
		else fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, +oo)\n", -b / a);
	}
}

void XetDau2(float a, float b, float c)
{
	float x, y;
	short t;
	GiaiPT_Bac2(a, b, c, x, y, t);
	if (t == -1)
	{
		if (a < 0) fprintf(output, "\tDao ham luon am voi moi x thuoc R\n");
		else fprintf(output, "\tDao ham luon duong voi moi x thuoc R\n");
	}
	else if (t == 0)
	{
		if (a < 0) fprintf(output, "\tDao ham luon am voi moi x thuoc R \\ {%.2f}\n", x);
		else fprintf(output, "\tDao ham luon duong voi moi x thuoc R \\ {%.2f}\n", x);
		fprintf(output, "Dao ham bang 0 tai x = %.2f\n", x);
	}
	else
	{
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c, %.2f) va x thuoc (%.2f, +%c)\n"
				, (char)236, x, y, (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (-oo, %.2f) va x thuoc (%.2f, +oo)\n", x, y);
			fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, %.2f)\n", x, y);
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, %.2f) va x thuoc (%.2f, +%c)\n"
				, (char)236, x, y, (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (-oo, %.2f) va x thuoc (%.2f, +oo)\n", x, y);
			fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, %.2f)\n", x, y);
		}
		fprintf(output, "\tDao ham bang 0 tai x = %.2f va x = %.2f\n", x, y);
	}
}

void XetDau3(float a, float b)
{
	if (a * b < 0)
	{
		float temp = sqrt(-b / a);
		if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c, %.2f) va x thuoc (%d, %.2f)\n"
				, (char)236, -temp, 0, temp);
			else fprintf(output, "\tDao ham luon am voi x thuoc (-oo, %.2f) va x thuoc (%d, %.2f)\n", -temp, 0, temp);
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, %d) va x thuoc (%.2f, +%c)\n"
				, -temp, 0, temp, (char)236);
			else  fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, %d) va x thuoc (%.2f, +oo)\n", -temp, 0, temp);
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, %.2f) va x thuoc (%d, %.2f)\n"
				, (char)236, -temp, 0, temp);
			else  fprintf(output, "\tDao ham luon duong voi x thuoc (-oo, %.2f) va x thuoc (%d, %.2f)\n", -temp, 0, temp);
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, %d) va x thuoc (%.2f, +%c)\n"
				, -temp, 0, temp, (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, %d) va x thuoc (%.2f, +oo)\n", -temp, 0, temp);
		}
		fprintf(output, "\tDao ham bang 0 tai x = 0,  x = %.2f va x = %.2f\n", -temp, temp);
	}
	else
	{
		if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c, 0)\n", (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (-oo, 0)\n");
			fprintf(output, "\tDao ham bang 0 voi x = 0\n");
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (0, +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (0, +oo)\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, 0)\n", (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (-oo, 0)\n");
			fprintf(output, "\tDao ham bang 0 voi x = 0\n");
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (0, +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (0, +oo)\n");
		}
	}
}

void XetDau4(float a, float c, float d)
{
	if (a < epsilon) fprintf(output, "\tDao ham luon bang 0 voi moi x thuoc R\n");
	else if (a > 0) fprintf(output, "\tDao ham luon duong voi moi x thuoc R \\ {%.2f}\n", -d / c);
	else fprintf(output, "\tDao ham luon am voi moi x thuoc R \\ {%.2f}\n", -d / c);
	if (output == stdout) fprintf(output, "\tDao ham tien toi %c khi x = %.2f\n", (char)236, -d / c);
}

void XetDau14()
{
	if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (%c/2 + k%c, 3%c/2 + k%c) voi k thuoc Z\n", 227, 227, 227, 227);
	else fprintf(output, "\tDao ham luon am voi x thuoc (Pi/2 + k* Pi, 3* Pi/2 + k* Pi) voi k thuoc Z\n");
	if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c/2 + k%c, %c/2 + k%c) voi k thuoc Z\n", 227, 227, 227, 227);
	else fprintf(output, "\tDao ham luon duong voi x thuoc (-Pi/2 + k* Pi, Pi/2 + k* Pi) voi k thuoc Z\n");
	if (output == stdout) fprintf(output, "\tDao ham bang 0 voi x = %c/2 + k%c voi k thuoc Z\n", 227, 227);
	else fprintf(output, "\tDao ham bang 0 voi x = Pi/2 + k* Pi voi k thuoc Z\n");
}

void XetDau15()
{
	if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (%c + k%c, 2%c + k%c) voi k thuoc Z\n", 227, 227, 227, 227);
	else fprintf(output, "\tDao ham luon duong voi x thuoc (Pi/2 + k* Pi, 3* Pi/2 + k* Pi) voi k thuoc Z\n");
	if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (k%c, %c + k%c) voi k thuoc Z\n", 227, 227, 227);
	else fprintf(output, "\tDao ham luon am voi x thuoc (k* Pi, Pi + k* Pi) voi k thuoc Z\n");
	if (output == stdout) fprintf(output, "\tDao ham bang 0 voi x = k%c voi k thuoc Z\n", 227);
	else fprintf(output, "\tDao ham bang 0 voi x = k* Pi voi k thuoc Z\n");
}

void XetDau16()
{
	fprintf(output, "\tDao ham luon duong voi moi x thuoc R\n");
}

void XetDau17()
{
	fprintf(output, "\tDao ham luon am voi moi x thuoc R\n");
}

void DaoHam1(float a, float b)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = %.2f\n", a);
	fprintf(output, "Xet dau dao ham y':\n");
	XetDau0(a);
}

void DaoHam2(float a, float b, float c)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = ");
	PT_1(2 * a, b);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau1(2 * a, b);
}

void DaoHam3(float a, float b, float c, float d)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = ");
	PT_2(3 * a, 2 * b, c);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau2(3 * a, 2 * b, c);
}

void DaoHam4(float a, float b, float c)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = ");
	PT_3(4 * a, 0, 2 * b, 0);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau3(4 * a, 2 * b);
}

void DH_4(float a, float b, float c, float d)
{
	if (fabs(a * d - b * c) < epsilon) fprintf(output, "0\n");
	else
	{
		fprintf(output, "%.2f / ", a * d - b * c);
		if (2 * c * d != 0 || d * d != 0) fprintf(output, "(");
		PT_2(c * c, 2 * c * d, d * d);
		if (2 * c * d != 0 || d * d != 0) fprintf(output, ")");
	}
}

void DaoHam5(float a, float b, float c, float d)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = ");
	DH_4(a, b, c, d);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau4(a * d - b * c, c, d);
}

void DH_5(float a, float b, float c, float d, float e)
{
	float a1 = a * d, b1 = 2 * a * e, c1 = b * e - c * d;
	if (b1 != 0 || c1 != 0) fprintf(output, "(");
	PT_2(a * d, 2 * a * e, b * e - c * d);
	if (b1 != 0 || c1 != 0) fprintf(output, ")");
	fprintf(output, " / ");
	if (2 * d * e != 0 || e * e != 0) fprintf(output, "(");
	PT_2(d * d, 2 * d * e, e * e);
	if (2 * d * e != 0 || e * e != 0) fprintf(output, ")");
}

void DaoHam6(float a, float b, float c, float d, float e)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = ");
	DH_5(a, b, c, d, e);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau2(a * d, 2 * a * e, b * e - c * d);
}

void DaoHam14()
{
	fprintf(output, "Dao ham cua ham so co dang: y' = Cos(x)\n");
	fprintf(output, "Xet dau dao ham y':\n");
	XetDau14();
}

void DaoHam15()
{
	fprintf(output, "Dao ham cua ham so co dang: y' = -Sin(x)\n");
	fprintf(output, "Xet dau dao ham y':\n");
	XetDau15();
}

void DaoHam16()
{
	fprintf(output, "Dao ham cua ham so co dang: y' = 1 + Tan(x)^2\n");
	fprintf(output, "Xet dau dao ham y':\n");
	XetDau16();
}

void DaoHam17()
{
	fprintf(output, "Dao ham cua ham so co dang: y' = -(1 + Cot(x)^2)\n");
	fprintf(output, "Xet dau dao ham y':\n");
	XetDau17();
}

void XetDau18(float a, float b)
{
	if (a == 0) fprintf(output, "\tDao ham luon bang 0 voi moi x thuoc R\n");
	else if (a < 0)	fprintf(output, "\tDao ham luon am voi moi x < %.2f", -b / a);
	else fprintf(output, "\tDao ham luon duong voi moi x > %.2f\n", -b / a);
}

void XetDau19(float a, float b, float c)
{

}

void XetDau20(float a, float b, float c, float d)
{

}

void XetDau21(float a, float b, float c)
{

}

void XetDau22(float a, float b, float c, float d)
{

}

void XetDau23(float a, float b, float c, float d, float e)
{

}

void DaoHam18(float a, float b)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = %.2f / Can(%.2fx + %.2f)", a / 2, a, b);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau18(a, b);
}
void DaoHam19(float a, float b, float c)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = ");
	fprintf(output, "(");
	PT_1(a, b / 2);
	fprintf(output, ") / Can(");
	PT_2(a, b, c);
	fprintf(output, ")");
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau19(a, b, c);
}
void DaoHam20(float a, float b, float c, float d)
{
	fprintf(output, "Dao ham cua ham so co dang y' = ");
	fprintf(output, "(");
	PT_2(1.5 * a, b, c / 2);
	fprintf(output, ") / Can(");
	PT_3(a, b, c, d);
	fprintf(output, ")");
	XetDau20(a, b, c, d);
}

void DaoHam21(float a, float b, float c)
{
	fprintf(output, "Dao ham cua ham so co dang y' = ");
	fprintf(output, "(");
	PT_3(2 * a, 0, b, 0);
	fprintf(output, ") / Can(");
	PT_4(a, b, c);
	fprintf(output, ")");
	XetDau21(a, b, c);
}

void DaoHam22(float a, float b, float c, float d)
{
	fprintf(output, "Dao ham cua ham so co dang y' = (");
	DH_4(a, b, c, d);
	fprintf(output, ") / (2 * Can(");
	PT_5(a, b, c, d);
	fprintf(output, "))");
	XetDau22(a, b, c, d);
}

void DaoHam23(float a, float b, float c, float d, float e)
{
	fprintf(output, "Dao ham cua ham so co dang y' = (");
	DH_5(a, b, c, d, e);
	fprintf(output, ") / (2 * Can(");
	PT_6(a, b, c, d, e);
	fprintf(output, "))");
	XetDau23(a, b, c, d, e);
}



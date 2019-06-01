#include <iostream>
#include <cmath>
#include <iomanip>
#include "TapXacDinh.h"
#include "Equation.h"
#include "MinMax.h"
#include "Intersection.h"
#define MIN 0.00001
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define epsilon 1e-5
extern FILE* input, * output;
using namespace std;

void Inter(int ii, int jj,int i,int j)
{
	switch (ii)
	{
	case 1:
	{
		switch (jj)
		{
		case 1:
			Inter_1_1(arr_a[i], arr_b[i], arr_a[j], arr_b[j]);
			break;
		case 2:
			Inter_1_2(arr_a[i], arr_b[i], arr_a[j], arr_b[j], arr_c[j]);
			break;
		case 3:
			Inter_1_3(arr_a[i], arr_b[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 4:
			Inter_1_4(arr_a[i], arr_b[i], arr_a[j], arr_b[j], arr_c[j]);
			break;
		case 5:
			Inter_1_5(arr_a[i], arr_b[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 6:
			Inter_1_6(arr_a[i], arr_b[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_e[j]);
			break;
		}
		break;
	}
	case 2:
	{
		switch (jj)
		{
		case 1:
			Inter_1_2(arr_a[j], arr_b[j], arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 2:
			Inter_2_2(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j]);
			break;
		case 3:
			Inter_2_3(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 4:
			Inter_2_4(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j]);
			break;
		case 5:
			Inter_2_5(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 6:
			Inter_2_6(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_e[j]);
			break;
		}
		break;
	}
	case 3:
	{
		switch (jj)
		{
		case 1:
			Inter_1_3(arr_a[j], arr_b[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 2:
			Inter_2_3(arr_a[j], arr_b[j], arr_c[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 3:
			Inter_3_3(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 4:
			Inter_3_4(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_a[j], arr_b[j], arr_c[j]);
			break;
		case 5:
			Inter_3_5(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 6:
			Inter_3_6(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_e[j]);
			break;
		}
		break;
	}
	case 4:
	{
		switch (jj)
		{
		case 1:
			Inter_1_4(arr_a[j], arr_b[j], arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 2:
			Inter_2_4(arr_a[j], arr_b[j], arr_c[j], arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 3:
			Inter_3_4(arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 4:
			Inter_4_4(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j]);
			break;
		case 5:
			Inter_4_5(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 6:
			Inter_4_6(arr_a[i], arr_b[i], arr_c[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_e[j]);
			break;
		}
		break;
	}
	case 5:
	{
		switch (jj)
		{
		case 1:
			Inter_1_5(arr_a[j], arr_b[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 2:
			Inter_2_5(arr_a[j], arr_b[j], arr_c[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 3:
			Inter_3_5(arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 4:
			Inter_4_5(arr_a[j], arr_b[j], arr_c[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 5:
			Inter_5_5(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
			break;
		case 6:
			Inter_5_6(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_e[j]);
			break;
		}
		break;
	}
	case 6:
	{
		switch (jj)
		{
		case 1:
			Inter_1_6(arr_a[j], arr_b[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		case 2:
			Inter_2_6(arr_a[j], arr_b[j], arr_c[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		case 3:
			Inter_3_6(arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		case 4:
			Inter_4_6(arr_a[j], arr_b[j], arr_c[j], arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		case 5:
			Inter_5_6(arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_a[i], arr_b[j], arr_c[j], arr_d[j], arr_e[i]);
			break;
		case 6:
			Inter_6_6(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i], arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_e[j]);
			break;
		}
		break;
	}
	}
}

void Inter_1_1(float a1, float b1, float a2, float b2)
{
	float INT_x = (b2 - b1) / (a1 - a2);
	float INT_y = a1 * INT_x + b1;
	fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", INT_x, INT_y);
}

void Inter_2_2(float a1, float b1, float c1, float a2, float b2, float c2)
{
	float A = a1 - a2, B = b1 - b2, C = c1 - c2;
	float x, y;
	short z;
	GiaiPT_Bac2(A, B, C, x, y, z);
	if (z == -1)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	}
	else if (z == 0)
	{
		float Y = a1 * pow(x, 2) + b1 * x + c1;
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Y);
	}
	else
	{
		float Y1 = a1 * pow(x, 2) + b1 * x + c1;
		float Y2 = a1 * pow(y, 2) + b1 * y + c1;
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f) va (%.10f , %.10f)\n", x, Y1, y, Y2);
	}
}

void Inter_3_3(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2)
{
	float A = a1 - a2, B = b1 - b2, C = c1 - c2, D = d1 - d2;
	float x, y, z;
	short k;
	GiaiPT_Bac3(A, B, C, D, x, y, z, k);
	if (k == -1)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_3(a1, b1, c1, d1, x));
	}
	else if (k == 0)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_3(a1, b1, c1, d1, x));
	}
	else
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_3(a1, b1, c1, d1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_3(a1, b1, c1, d1, y));
		if (z != y && z != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_3(a1, b1, c1, d1, z));
	}
}

void Inter_4_4(float a1, float b1, float c1, float a2, float b2, float c2)
{
	float A = a1 - a2, B = b1 - b2, C = c1 - c2;
	float x, y, z, t;
	short k;
	GiaiPT_Bac4(A, 0, B, 0, C, x, y, z, t, k);
	if (k == 0)
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	else if (k == 2)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
	}
	else if (k == 4)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
	}
}

void Inter_5_5(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2)
{
	float A = a1 * c2 - a2 * c1, B = a1 * d2 + b1 * c2 - a2 * d1 - b2 * c1, C = b1 * d2 - b2 * d1;
	float x, y;
	short k;
	GiaiPT_Bac2(A, B, C, x, y, k);
	if (Equa_1(c1, d1, x) == 0 && Equa_1(c1, d1, x) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (Equa_1(c2, d2, x) == 0 && Equa_1(c2, d2, x) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == -1)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	}
	else if (k == 0)
	{
		if (c1 * x + d1 != 0 && c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_5(a1, b1, c1, d1,x));
	}
	else if (k == 1)
	{
		if (c1 * x + d1 != 0 && c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_5(a1, b1, c1, d1, x));
		if (c1 * y + d1 != 0 && c2 * y + d2 != 0 && y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_5(a1, b1, c1, d1, y));
	}
}

void Inter_6_6(float a1, float b1, float c1, float d1, float e1, float a2, float b2, float c2, float d2, float e2)
{
	float A = a1 * d2 - a2 * d1;
	float B = a1 * e2 + b1 * d2 - (a2 * e1 + b2 * d1);
	float C = b1 * e2 + c1 * d2 - (b2 * e1 + c2 * d1);
	float D = c1 * e2 - c2 * e1;
	float x, y, z;
	short k;
	GiaiPT_Bac3(A, B, C, D, x, y, z, k);
	if (Equa_1(d1, e1, x) == 0 && Equa_1(d1, e1, y) == 0 && Equa_1(d1, e1, z) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (Equa_1(d2, e2, x) == 0 && Equa_1(d2, e2, y) == 0 && Equa_1(d2, e2, z) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 1)
	{
		if (Equa_1(d1, e1, x) != 0 && Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_6(a1, b1, c1, d1, e1, x));
	}
	if (k == 3)
	{
		if (Equa_1(d1, e1, x) != 0 && Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_6(a1, b1, c1, d1, e1, x));
		if (y != x && Equa_1(d1, e1, y) != 0 && Equa_1(d2, e2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_6(a1, b1, c1, d1, e1, y));
		if (z != x && z != y && Equa_1(d1, e1, z) != 0 && Equa_1(d2, e2, z) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_6(a1, b1, c1, d1, e1, z));
	}
}

void Inter_1_2(float a, float b, float a1, float b1, float c1)
{
	float A = a1, B = b1 - a, C = c1 - b;
	float x, y;
	short z;
	GiaiPT_Bac2(A, B, C, x, y, z);
	if (z == -1)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	}
	else if (z == 0)
	{
		float Y = a1 * pow(x, 2) + b1 * x + c1;
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Y);
	}
	else
	{
		float Y1 = a1 * pow(x, 2) + b1 * x + c1;
		float Y2 = a1 * pow(y, 2) + b1 * y + c1;
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f) va (%.10f , %.10f)\n", x, Y1, y, Y2);
	}
}

void Inter_1_3(float a, float b, float a1, float b1, float c1, float d1)
{
	float A = a1, B = b1, C = c1 - a, D = d1 - b;
	float x, y, z;
	short k;
	GiaiPT_Bac3(A, B, C, D, x, y, z, k);
	if (k == 1)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_1(a, b, x));
	}
	if (k == 3)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_1(a, b, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_1(a, b, y));
		if (z != x && z != y)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_1(a, b, z));
	}
}

void Inter_1_4(float a, float b, float a1, float b1, float c1)
{
	float A = a1, B = b1, C = -a, D = c1 - b;
	float x, y, z, t;
	short k;
	GiaiPT_Bac4(A, 0, B, C, D, x, y, z, t, k);
	if (k == 0)
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	else if (k == 2)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
	}
	else if (k == 4)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
	}
}

void Inter_1_5(float a, float b, float a1, float b1, float c1, float d1)
{
	float A = a * c1, B = a * d1 + b * c1 - a1, C = b * d1 - b1;
	float x, y;
	short z;
	GiaiPT_Bac2(A, B, C, x, y, z);
	if (Equa_1(c1, d1, x) == 0 && Equa_1(c1, d1, y) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (z == -1)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	}
	else if (z == 0)
	{
		if (Equa_1(c1, d1, x) != 0)
		{
			float Y = a1 * pow(x, 2) + b1 * x + c1;
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Y);
		}

	}
	else
	{
		if (Equa_1(c1, d1, x) != 0)
		{
			float Y1 = a1 * pow(x, 2) + b1 * x + c1;
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Y1);
		}
		if (Equa_1(c1, d1, y) != 0)
		{
			float Y2 = a1 * pow(y, 2) + b1 * y + c1;
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Y2);
		}

	}
}

void Inter_1_6(float a, float b, float a1, float b1, float c1, float d1, float e1)
{
	float A = a * d1 - a1, B = a * e1 + b * d1 - b1, C = b * e1 - c1;
	float x, y;
	short z;
	GiaiPT_Bac2(A, B, C, x, y, z);
	if (Equa_1(d1, e1, x) == 0 && Equa_1(d1, e1, y) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (z == -1)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	}
	else if (z == 0)
	{
		if (Equa_1(d1, e1, x) != 0)
		{
			float Y = a1 * pow(x, 2) + b1 * x + c1;
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Y);
		}
	}
	else
	{
		if (Equa_1(d1, e1, x) != 0)
		{
			float Y1 = a1 * pow(x, 2) + b1 * x + c1;
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Y1);
		}
		if (Equa_1(d1, e1, y) != 0)
		{
			float Y2 = a1 * pow(y, 2) + b1 * y + c1;
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Y2);
		}

	}
}

void Inter_2_3(float a1, float b1, float c1, float a2, float b2, float c2, float d2)
{
	float A = a2, B = b2 - a1, C = c2 - b1, D = d2 - c1;
	float x, y, z;
	short k;
	GiaiPT_Bac3(A, B, C, D, x, y, z, k);
	if (k == 1)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_2(a1, b1, c1, x));
	}
	if (k == 3)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_2(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_2(a1, b1, c1, y));
		if (z != x && z != y)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_2(a1, b1, c1, z));
	}
}

void Inter_2_4(float a1, float b1, float c1, float a2, float b2, float c2)
{
	float A = a2, B = 0, C = b2 - a1, D = -b1, E = c2 - c1;
	float x, y, z, t;
	short k;
	GiaiPT_Bac4(A, B, C, D, E, x, y, z, t, k);
	if (k == 0)
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	else if (k == 2)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
	}
	else if (k == 4)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
	}
}

void Inter_2_5(float a1, float b1, float c1, float a2, float b2, float c2, float d2)
{
	float A = a1 * c2, B = a1 * d2 + b1 * c2, C = b1 * d2 + c1 * c2 - c2, D = c1 * d2 - b2;
	float x, y, z;
	short k;
	GiaiPT_Bac3(A, B, C, D, x, y, z, k);
	if (Equa_1(c2, d2, x) == 0 && Equa_1(c2, d2, y) == 0 && Equa_1(c2, d2, z) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 1)
	{
		if (Equa_1(c2, d2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_2(a1, b1, c1, x));
	}
	if (k == 3)
	{
		if (Equa_1(c2, d2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_2(a1, b1, c1, x));
		if (y != x && Equa_1(c2, d2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_2(a1, b1, c1, x));
		if (z != x && z != y && Equa_1(c2, d2, z) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_2(a1, b1, c1, x));
	}
}

void Inter_2_6(float a1, float b1, float c1, float a2, float b2, float c2, float d2, float e2)
{
	float A = a1 * d2, B = a1 * e2 + b1 * d2 - a2, C = b1 * e2 + c1 * d2 - b2, D = c1 * e2 - c2;
	float x, y, z;
	short k;
	GiaiPT_Bac3(A, B, C, D, x, y, z, k);
	if (Equa_1(d2, e2, x) == 0 && Equa_1(d2, e2, y) == 0 && Equa_1(d2, e2, z) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 1)
	{
		if (Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_2(a1, b1, c1, x));
	}
	if (k == 3)
	{
		if (Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_2(a1, b1, c1, x));
		if (y != x && Equa_1(d2, e2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_2(a1, b1, c1, x));
		if (z != x && z != y && Equa_1(d2, e2, z) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_2(a1, b1, c1, x));
	}
}

void Inter_3_4(float a1, float b1, float c1, float d1, float a2, float b2, float c2)
{
	float A = a2, B = -a1, C = b2 - b1, D = -c1, E = c2 - d1;
	float x, y, z, t;
	short k;
	GiaiPT_Bac4(A, B, C, D, E, x, y, z, t, k);
	if (k == 0)
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	else if (k == 2)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
	}
	else if (k == 4)
	{
		fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
	}
}

void Inter_3_5(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2)
{
	float A = a1 * c2, B = a1 * d2 + b1 * c2, C = b1 * d2 + c1 * c2, D = c1 * d2 + d1 * c2 - a2, E = d1 * d2 - b2;
	float x, y, z, t;
	short k;
	GiaiPT_Bac4(A, B, C, D, E, x, y, z, t, k);
	if (Equa_1(c2, d2, x) == 0 && Equa_1(c2, d2, y) == 0 && Equa_1(c2, d2, z) == 0 && Equa_1(c2, d2, t) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 0)
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	else if (k == 2)
	{
		if (Equa_1(c2, d2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_3(a1, b1, c1, d1, x));
		if (y != x && Equa_1(c2, d2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_3(a1, b1, c1, d1, y));
	}
	else if (k == 4)
	{
		if (Equa_1(c2, d2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_3(a1, b1, c1, d1, x));
		if (y != x && Equa_1(c2, d2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_3(a1, b1, c1, d1, y));
		if (z != y && z != x && Equa_1(c2, d2, z) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_3(a1, b1, c1, d1, z));
		if (t != z && t != y && t != x && Equa_1(c2, d2, t) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_3(a1, b1, c1, d1, t));
	}
}

void Inter_3_6(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float e2)
{
	float A = a1 * d2, B = a1 * e2 + b1 * d2, C = b1 * e2 + c1 * d2 - a2, D = c1 * e2 + d1 * d2 - b2, E = d1 * d2 - c2;
	float x, y, z, t;
	short k;
	GiaiPT_Bac4(A, B, C, D, E, x, y, z, t, k);
	if (Equa_1(d2, e2, x) == 0 && Equa_1(d2, e2, y) == 0 && Equa_1(d2, e2, z) == 0 && Equa_1(d2, e2, t) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 0)
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
	else if (k == 2)
	{
		if (Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_3(a1, b1, c1, d1, x));
		if (y != x && Equa_1(d2, e2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_3(a1, b1, c1, d1, y));
	}
	else if (k == 4)
	{
		if (Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_3(a1, b1, c1, d1, x));
		if (y != x && Equa_1(d2, e2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_3(a1, b1, c1, d1, y));
		if (z != y && z != x && Equa_1(d2, e2, z) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_3(a1, b1, c1, d1, z));
		if (t != z && t != y && t != x && Equa_1(d2, e2, t) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_3(a1, b1, c1, d1, t));
	}
}

void Inter_4_5(float a1, float b1, float c1, float a2, float b2, float c2, float d2)
{
	float A = a1 * c2, B = a1 * d2, C = b1 * c2, D = b1 * d2, E = c1 * c2 - a2, F = c1 * d2 - b2;
	float x, y, z, t, c;
	short k;
	GiaiPT_Bac5(A, B, C, D, E, F, x, y, z, t, c, k);
	if (Equa_1(c2, d2, x) == 0 && Equa_1(c2, d2, y) == 0 && Equa_1(c2, d2, z) == 0 && Equa_1(c2, d2, t) == 0 && Equa_1(c2, d2, c) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 1)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		else
			fprintf(output, "Hai ham so khong co giao diem!!!\n");
	}
	else if (k == 2)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
	}
	else if (k == 3)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x && c2 * z + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
	}
	else if (k == 4)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x && c2 * z + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x && c2 * t + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
	}
	else if (k == 5)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x && c2 * z + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x && c2 * t + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
		if (c != t && c != z && c != y && z != x && c2 * c + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", c, Equa_4(a1, b1, c1, c));
	}

}

void Inter_4_6(float a1, float b1, float c1, float a2, float b2, float c2, float d2, float e2)
{
	float A = a1 * d2, B = a1 * e2, C = b1 * d2, D = b1 * e2 - a2, E = c1 * d2 - b2, F = c1 * e2 - c2;
	float x, y, z, t, c;
	short k;
	GiaiPT_Bac5(A, B, C, D, E, F, x, y, z, t, c, k);
	if (Equa_1(c2, d2, x) == 0 && Equa_1(c2, d2, y) == 0 && Equa_1(c2, d2, z) == 0 && Equa_1(c2, d2, t) == 0 && Equa_1(c2, d2, c) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 1)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		else
			fprintf(output, "Hai ham so khong co giao diem!!!\n");
	}
	else if (k == 2)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
	}
	else if (k == 3)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x && c2 * z + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
	}
	else if (k == 4)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x && c2 * z + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x && c2 * t + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
	}
	else if (k == 5)
	{
		if (c2 * x + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_4(a1, b1, c1, x));
		if (y != x && c2 * y + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_4(a1, b1, c1, y));
		if (z != y && z != x && c2 * z + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_4(a1, b1, c1, z));
		if (t != z && t != y && t != x && c2 * t + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", t, Equa_4(a1, b1, c1, t));
		if (c != t && c != z && c != y && z != x && c2 * c + d2 != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", c, Equa_4(a1, b1, c1, c));
	}
}

void Inter_5_6(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float e2)
{
	float A = a2 * c1, B = a2 * d1 + b2 * c1 - a1 * c2, C = b2 * d1 + c2 * c1 - a1 * d2 - b1 * c2, D = c2 * d1 - b1 * d2;
	float x, y, z;
	short k;
	GiaiPT_Bac3(A, B, C, D, x, y, z, k);
	if (Equa_1(d2, e2, x) == 0 && Equa_1(d2, e2, y) == 0 && Equa_1(d2, e2, z) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (Equa_1(c1, d1, x) == 0 && Equa_1(c1, d1, y) == 0 && Equa_1(c1, d1, z) == 0)
	{
		fprintf(output, "Hai ham so khong co giao diem!!!\n");
		return;
	}
	if (k == 1)
	{
		if (Equa_1(c1, d1, x) != 0 && Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_5(a1, b1, c1, d1, x));
	}
	if (k == 3)
	{
		if (Equa_1(c1, d1, x) != 0 && Equa_1(d2, e2, x) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", x, Equa_5(a1, b1, c1, d1, x));
		if (y != x && Equa_1(c1, d1, y) != 0 && Equa_1(d2, e2, y) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", y, Equa_5(a1, b1, c1, d1, y));
		if (z != x && z != y && Equa_1(c1, d1, z) != 0 && Equa_1(d2, e2, z) != 0)
			fprintf(output, "Giao diem cua hai ham so la: (%.10f , %.10f)\n", z, Equa_5(a1, b1, c1, d1, z));
	}
}
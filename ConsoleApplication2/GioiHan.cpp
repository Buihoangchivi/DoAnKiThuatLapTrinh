#define _CRT_SECURE_NO_WARNINGS
#include "GioiHan.h"
#include "Equation.h"
#include "Input_Output.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#define epsilon 1e-5
#define MAX 256

extern FILE * input, *output;

using namespace std;


void GioiHan(int k, float a, float b, float c, float d, float e, int select)
{
	switch (k)
	{
	case 1:
		GioiHan1(a, b, select);
		break;
	case 2:
		GioiHan2(a, b, c, select);
		break;
	case 3:
		GioiHan3(a, b, c, d, select);
		break;
	case 4:
		GioiHan4(a, b, c, select);
		break;
	case 5:
		GioiHan5(a, b, c, d, select);
		break;
	case 6:
		GioiHan6(a, b, c, d, e, select);
		break;
	case 14:
		GioiHan14(select);
		break;
	case 15:
		GioiHan15(select);
		break;
	case 16:
		GioiHan16(select);
		break;
	case 17:
		GioiHan17(select);
		break;
	case 18:
		GioiHan18(a, b, select);
		break;
	case 19:
		GioiHan19(a, b, c, select);
		break;
	case 20:
		GioiHan20(a, b, c, d, select);
		break;
	case 21:
		GioiHan21(a, b, c, select);
		break;
	case 22:
		GioiHan22(a, b, c, d, select);
		break;
	case 23:
		GioiHan23(a, b, c, d, e, select);
		break;
	default:
		break;
	}
}

void GioiHan1(float a, float b, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_1(a, b);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_1(a, b);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_1(a, b);
			fprintf(output, ") = %.2f\n", b);
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_1(a, b);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_1(a, b);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_1(a, b);
			fprintf(output, ") = %.2f\n", b);
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0); PT_1(a, b);
		fprintf(output, ") = %.2f\n", Equa_1(a, b, x0));
		break;
	default:
		break;
	}
}

void GioiHan2(float a, float b, float c, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_2(a, b, c);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_2(a, b, c);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_2(a, b, c);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_2(a, b, c);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0); PT_2(a, b, c);
		fprintf(output, ") = %.2f\n", Equa_2(a, b, c, x0));
		break;
	default:
		break;
	}
}

void GioiHan3(float a, float b, float c, float d, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_3(a, b, c, d);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_3(a, b, c, d);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_3(a, b, c, d);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_3(a, b, c, d);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0); PT_3(a, b, c, d);
		fprintf(output, ") = %.2f\n", Equa_3(a, b, c, d, x0));
		break;
	default:
		break;
	}
}

void GioiHan4(float a, float b, float c, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_4(a, b, c);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_4(a, b, c);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_4(a, b, c);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_4(a, b, c);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0); PT_4(a, b, c);
		fprintf(output, ") = %.2f\n", Equa_4(a, b, c, x0));
		break;
	default:
		break;
	}
}

void GioiHan5(float a, float b, float c, float d, int select)
{
	switch (select)
	{
	case 1:
		if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
		else fprintf(output, "\tKhi x -> +oo  lim("); PT_5(a, b, c, d);
		fprintf(output, ") = %.2f\n", a / c);
		break;
	case 2:
		if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
		else fprintf(output, "\tKhi x -> -oo  lim("); PT_5(a, b, c, d);
		fprintf(output, ") = %.2f\n", a / c);
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		if (x0 != -d / c)
		{
			fprintf(output, "\tKhi x -> %.2f  lim(", x0); PT_5(a, b, c, d);
			fprintf(output, ") = %.2f\n", Equa_5(a, b, c, d, x0));
		}
		else
		{
			fprintf(output, "\tKhi x -> %.2f  lim", x0); PT_5(a, b, c, d);
			if (output == stdout) fprintf(output, ") = %c\n", char(236));
			else fprintf(output, ") = oo\n");
		}
		break;
	default:
		break;
	}
}

void GioiHan6(float a, float b, float c, float d, float e, int select)
{
	switch (select)
	{
	case 1:
		if (a * d > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_6(a, b, c, d, e);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim("); PT_6(a, b, c, d, e);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		break;
	case 2:
		if (a * d < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim("); PT_6(a, b, c, d, e);
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			PT_6(a, b, c, d, e);
			if (output == stdout) fprintf(output, ") = -%c\n", char(236));
			else fprintf(output, ") = -oo\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		if (x0 != -e / d)
		{
			fprintf(output, "\tKhi x -> %.2f  lim(", x0); PT_6(a, b, c, d, e);
			fprintf(output, ") = %.2f\n", Equa_6(a, b, c, d, e, x0));
		}
		else
		{
			fprintf(output, "\tKhi x -> %.2f  lim(", x0); PT_6(a, b, c, d, e);
			if (output == stdout) fprintf(output, ") = oo\n");
		}
		break;
	default:
		break;
	}
}

void GioiHan14(int select)
{
	switch (select) {
	case 1:
		fprintf(output, "\tKhi x->+oo Lim(Sin(x)) khong xac dinh\n");
		break;
	case 2:
		fprintf(output, "\tKhi x->-oo Lim(Sin(x)) khong xac dinh\n");
		break;
	case 3:
		float x0;
		fprintf(output, "Nhap x0 (radian): ");
		fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x->%.2f Lim(Sin(x)) = %.2f\n", x0, sin(x0));
		break;
	default:
		break;
	}
}

void GioiHan15(int select)
{
	switch (select)
	{
	case 1:
		fprintf(output, "\tKhi x->+oo Lim(Cos(x)) khong xac dinh\n");
		break;
	case 2:
		fprintf(output, "\tKhi x->-oo Lim(Cos(x)) khong xac dinh\n");
		break;
	case 3:
		float x0;
		fprintf(output, "Nhap x0 (radian): ");
		fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x->%.2f Lim(Cos(x)) = %.2f\n", x0, cos(x0));
		break;
	default:
		break;
	}
}

void GioiHan16(int select)
{
	switch (select) {
	case 1:
		fprintf(output, "\tKhi x->+oo Lim(Tan(x)) khong xac dinh\n");
		break;
	case 2:
		fprintf(output, "\tKhi x->-oo Lim(Tan(x)) khong xac dinh\n");
		break;
	case 3:
		float x0;
		fprintf(output, "Nhap x0 (radian): ");
		fscanf(input, "%f", &x0);
		if (fabs(cos(x0)) < epsilon) fprintf(output, "\tKhi x->%.2f Tan(x) khong xac dinh => Lim(Tan(x)) = oo\n", x0);
		else fprintf(output, "\tKhi x->%.2f Lim(tan(x)) = %.2f\n", x0, tan(x0));
	}
}

void GioiHan17(int select)
{
	switch (select) {
	case 1:
		fprintf(output, "\tKhi x->+oo Lim(Cot(x)) khong xac dinh\n");
		break;
	case 2:
		fprintf(output, "\tKhi x->-oo Lim(Cot(x)) khong xac dinh\n");
		break;
	case 3:
		float x0;
		fprintf(output, "Nhap x0 (radian): ");
		fscanf(input, "%f", &x0);
		if (fabs(sin(x0)) < epsilon) fprintf(output, "\tKhi x->%.2f Cot(x) khong xac dinh => Lim(Cot(x)) = oo\n", x0);
		else fprintf(output, "\tKhi x->%.2f Lim(Cot(x))=%.2f\n", x0, 1 / tan(x0));
	}
}

void GioiHan18(float a, float b, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout)
				fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else
				fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_1(a, b);
			printf(")");
			if (output == stdout)
				fprintf(output, ") khong xac dinh\n");
			else
				fprintf(output, ") khong xac dinh\n");
		}
		else if (a > 0)
		{
			if (output == stdout)
				fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else
				fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_1(a, b);
			printf(")");
			if (output == stdout)
				fprintf(output, ") = +%c\n", char(236));
			else
				fprintf(output, ") = +oo\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_1(a, b);
			printf(")");
			fprintf(output, ") = can(%.2f)\n", b);
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_1(a, b);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_1(a, b);
			printf(")");
			if (output == stdout)
				fprintf(output, ") khong xac dinh\n");
			else
				fprintf(output, ") khong xac dinh\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_1(a, b);
			printf(")");
			fprintf(output, ") = can(%.2f)\n", b);
		}
		break;
	case 3:
		float x0;
		if (input == stdin)
			fprintf(stdout, "Nhap x0 = ");
		fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0);
		printf("Can(");
		PT_1(a, b);
		printf(")");
		fprintf(output, ") = can(%.2f)\n", Equa_1(a, b, x0));
		break;
	default:
		break;
	}
}

void GioiHan19(float a, float b, float c, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout)
				fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else
				fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_2(a, b, c);
			printf(")");
			if (output == stdout)
				fprintf(output, ") khong xac dinh\n");
			else
				fprintf(output, ") khong xac dinh\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_2(a, b, c);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_2(a, b, c);
			printf(")");
			if (output == stdout) fprintf(output, ") khong xac dinh\n");
			else fprintf(output, ") khong xac dinh\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_2(a, b, c);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0);
		printf("Can(");
		PT_2(a, b, c);
		printf(")");
		fprintf(output, ") = can(%.2f)\n", Equa_2(a, b, c, x0));
		break;
	default:
		break;
	}
}

void GioiHan20(float a, float b, float c, float d, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_3(a, b, c, d);
			printf(")");
			if (output == stdout) fprintf(output, ") khong xac dinh\n");
			else fprintf(output, ") khong xac dinh\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_3(a, b, c, d);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_3(a, b, c, d);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_3(a, b, c, d);
			printf(")");
			if (output == stdout) fprintf(output, ") khong xac dinh\n");
			else fprintf(output, ") khong xac dinh\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0);
		printf("Can(");
		PT_3(a, b, c, d);
		printf(")");
		fprintf(output, ") = can(%.2f)\n", Equa_3(a, b, c, d, x0));
		break;
	default:
		break;
	}
}

void GioiHan21(float a, float b, float c, int select)
{
	switch (select)
	{
	case 1:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_4(a, b, c);
			printf(")");
			if (output == stdout) fprintf(output, ") khong xac dinh\n");
			else fprintf(output, ") khong xac dinh\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_4(a, b, c);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 2:
		if (a < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_4(a, b, c);
			printf(")");
			if (output == stdout) fprintf(output, ") khong xac dinh\n");
			else fprintf(output, ") khong xac dinh\n");
		}
		else if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_4(a, b, c);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		fprintf(output, "\tKhi x -> %.2f  lim(", x0);
		printf("Can(");
		PT_4(a, b, c);
		printf(")");
		fprintf(output, ") = can(%.2f)\n", Equa_4(a, b, c, x0));
		break;
	default:
		break;
	}
}

void GioiHan22(float a, float b, float c, float d, int select)
{
	switch (select)
	{
	case 1:
		if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
		else fprintf(output, "\tKhi x -> +oo  lim(");
		printf("Can(");
		PT_5(a, b, c, d);
		printf(")");
		fprintf(output, ") = can(%.2f/%.2f)\n", a, c);
		break;
	case 2:
		if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
		else fprintf(output, "\tKhi x -> -oo  lim(");
		printf("Can(");
		PT_5(a, b, c, d);
		printf(")");
		fprintf(output, ") = can(%.2f/%.2f)\n", a, c);
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		if (x0 != -d / c)
		{
			fprintf(output, "\tKhi x -> %.2f  lim(", x0);
			printf("Can(");
			PT_5(a, b, c, d);
			printf(")");
			fprintf(output, ") = can(%.2f)\n", Equa_5(a, b, c, d, x0));
		}
		else
		{
			fprintf(output, "\tKhi x -> %.2f  lim", x0);
			printf("Can(");
			PT_5(a, b, c, d);
			printf(")");
			if (output == stdout) fprintf(output, ") = %c\n", char(236));
			else fprintf(output, ") = oo\n");
		}
		break;
	default:
		break;
	}
}

void GioiHan23(float a, float b, float c, float d, float e, int select)
{
	switch (select)
	{
	case 1:
		if (a * d > 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_6(a, b, c, d, e);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> +%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> +oo  lim(");
			printf("Can(");
			PT_6(a, b, c, d, e);
			printf(")");
			if (output == stdout) fprintf(output, ") khong xac dinh\n");
			else fprintf(output, ") khong xac dinh\n");
		}
		break;
	case 2:
		if (a * d < 0)
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_6(a, b, c, d, e);
			printf(")");
			if (output == stdout) fprintf(output, ") = +%c\n", char(236));
			else fprintf(output, ") = +oo\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tKhi x -> -%c  lim(", char(236));
			else fprintf(output, "\tKhi x -> -oo  lim(");
			printf("Can(");
			PT_6(a, b, c, d, e);
			printf(")");
			if (output == stdout) fprintf(output, ") khong xac dinh\n");
			else fprintf(output, ") = khong xac dinh\n");
		}
		break;
	case 3:
		float x0;
		if (input == stdin) fprintf(stdout, "Nhap x0 = "); fscanf(input, "%f", &x0);
		if (x0 != -e / d)
		{
			fprintf(output, "\tKhi x -> %.2f  lim(", x0);
			printf("Can(");
			PT_6(a, b, c, d, e);
			printf(")");
			fprintf(output, ") = can(%.2f)\n", Equa_6(a, b, c, d, e, x0));
		}
		else
		{
			fprintf(output, "\tKhi x -> %.2f  lim(", x0);
			printf("Can(");
			PT_6(a, b, c, d, e);
			printf(")");
			if (output == stdout) fprintf(output, ") = %c\n", char(236));
		}
		break;
	default:
		break;
	}
}

void Choice_And_Lim(int k, float a, float b, float c, float d, float e)
{
	if (input == stdin)
	{
		fprintf(stdout, "**Ban muon tim gioi han cua ham so \tKhi x -> \n");
		fprintf(stdout, "- Nhan 1 de tim gioi han \tKhi x -> +%c\n", (char)236);
		fprintf(stdout, "- Nhan 2 de tim gioi han \tKhi x -> -%c\n", (char)236);
		fprintf(stdout, "- Nhan 3 de tim gioi han \tKhi x -> x0\n");
	}
	int select;
	while (true)
	{
		if (input == stdin) fprintf(stdout, "Nhap lua chon cua ban: "); fscanf(input, "%d", &select);
		if (input != stdin && select == 0) return;
		while (select < 1 || select > 3)
		{
			if (input == stdin)
			{
				fprintf(stdout, "\aDu lieu khong hop le!!! Moi ban nhap lai: "); fscanf(input, "%d", &select);
			}
		}
		if ((1 <= select) && (select <= 3)) GioiHan(k, a, b, c, d, e, select);
		if (input == stdin)
		{
			fprintf(stdout, "\nBan co muon tiep tuc tim gioi han cua ham so khong?\n");
			fprintf(stdout, "\tNeu ban muon tim tiep: Nhap 1\n");
			fprintf(stdout, "\tNeu ban muon dung tim: Nhap cac gia tri khac 1\n");
			fprintf(stdout, "\nNhap lua chon cua ban: "); fscanf(input, "%d", &select);
			if (select != 1) return;
			fprintf(stdout, "\n");
		}
	}
}

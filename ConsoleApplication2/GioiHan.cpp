#define _CRT_NONSTDC_NO_WARNINGS
#include "GioiHan.h"
#include "Equation.h"
#include "Input_Output.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
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
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_1(a, b);
			fprintf(input, ") = -%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_1(a, b);
			fprintf(output, ") = +%c\n", char(236));
		}
		else
		{
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_1(a, b);
			fprintf(output, ") = %.2f\n", b);
		}
		break;
	case 2:
		if (a < 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_1(a, b);
			fprintf(output, ") = +%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_1(a, b); fprintf(output, ") = -%c\n", char(236));
		}
		else
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_1(a, b); fprintf(output, ") = %.2f\n", b);
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
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_2(a, b, c); fprintf(output, ") = -%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_2(a, b, c); fprintf(output, ") = +%c\n", char(236));
		}
		break;
	case 2:
		if (a < 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_2(a, b, c); fprintf(output, ") = -%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_2(a, b, c); fprintf(output, ") = +%c\n", char(236));
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
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_3(a, b, c, d); fprintf(output, ") = -%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_3(a, b, c, d); fprintf(output, ") = +%c\n", char(236));
		}
		break;
	case 2:
		if (a < 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_3(a, b, c, d); fprintf(output, ") = +%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_3(a, b, c, d); fprintf(output, ") = -%c\n", char(236));
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
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_4(a, b, c); fprintf(output, ") = -%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_4(a, b, c); fprintf(output, ") = +%c\n", char(236));
		}
		break;
	case 2:
		if (a < 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_4(a, b, c); fprintf(output, ") = -%c\n", char(236));
		}
		else if (a > 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_4(a, b, c); fprintf(output, ") = +%c\n", char(236));
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
		fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_5(a, b, c, d);
		fprintf(output, ") = 0\n");
		break;
	case 2:
		fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_5(a, b, c, d);
		fprintf(output, ") = 0\n");
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
			fprintf(output, "\tKhi x -> %.2f  lim", x0); PT_5(a, b, c, d); fprintf(output, ") = %c\n", char(236));
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
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_6(a, b, c, d, e); fprintf(output, ") = +%c\n", char(236));
		}
		else
		{
			fprintf(output, "\tKhi x -> +%c  lim(", char(236)); PT_6(a, b, c, d, e); fprintf(output, ") = -%c\n", char(236));
		}
		break;
	case 2:
		if (a * d < 0)
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_6(a, b, c, d, e); fprintf(output, ") = +%c\n", char(236));
		}
		else
		{
			fprintf(output, "\tKhi x -> -%c  lim(", char(236)); PT_6(a, b, c, d, e); fprintf(output, ") = -%c\n", char(236));
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
			fprintf(output, ") = %c\n", char(236));
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
			fprintf(stdout, "Neu ban muon tim tiep: Nhap 1\n");
			fprintf(stdout, "Neu ban muon dung tim: Nhap cac gia tri khac 1\n");
			fprintf(stdout, "Nhap lua chon cua ban: "); fscanf(input, "%d", &select);
			if (select != 1) return;
			fprintf(stdout, "\n");
		}
	}
}

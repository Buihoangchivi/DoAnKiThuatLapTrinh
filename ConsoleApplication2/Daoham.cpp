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
	case 11:
		DaoHam11(a);
		break;
	case 12:
		DaoHam12(a);
		break;
	case 13:
		DaoHam13();
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
		if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c; %.2f)\n", (char)236, -b / a);
		else fprintf(output, "\tDao ham luon am voi x thuoc (-oo; %.2f)\n", -b / a);
		fprintf(output, "\tDao ham bang 0 voi x = %.2f\n", -b / a);
		if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f; +%c)\n", -b / a, (char)236);
		else fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f; +oo)\n", -b / a);
	}
	else
	{
		if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c; %.2f)\n", (char)236, -b / a);
		else fprintf(output, "\tDao ham luon duong voi x thuoc (-oo; %.2f)\n", -b / a);
		fprintf(output, "\tDao ham bang 0 voi x = %.2f\n", -b / a);
		if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (%.2f; +%c)\n", -b / a, (char)236);
		else fprintf(output, "\tDao ham luon am voi x thuoc (%.2f; +oo)\n", -b / a);
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
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c; %.2f) va x thuoc (%.2f; +%c)\n"
				, (char)236, x, y, (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (-oo; %.2f) va x thuoc (%.2f; +oo)\n", x, y);
			fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f; %.2f)\n", x, y);
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c; %.2f) va x thuoc (%.2f; +%c)\n"
				, (char)236, x, y, (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (-oo; %.2f) va x thuoc (%.2f; +oo)\n", x, y);
			fprintf(output, "\tDao ham luon am voi x thuoc (%.2f; %.2f)\n", x, y);
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
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c; %.2f) va x thuoc (%d; %.2f)\n"
				, (char)236, -temp, 0, temp);
			else fprintf(output, "\tDao ham luon am voi x thuoc (-oo, %.2f) va x thuoc (%d, %.2f)\n", -temp, 0, temp);
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, %d) va x thuoc (%.2f, +%c)\n"
				, -temp, 0, temp, (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (-oo; %.2f) va x thuoc (%d; %.2f)\n", -temp, 0, temp);
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f; %d) va x thuoc (%.2f; +%c)\n"
				, -temp, 0, temp, (char)236);
			else  fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f; %d) va x thuoc (%.2f; +oo)\n", -temp, 0, temp);
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c; %.2f) va x thuoc (%d; %.2f)\n"
				, (char)236, -temp, 0, temp);
			else  fprintf(output, "\tDao ham luon duong voi x thuoc (-oo; %.2f) va x thuoc (%d; %.2f)\n", -temp, 0, temp);
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (%.2f; %d) va x thuoc (%.2f; +%c)\n"
				, -temp, 0, temp, (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (%.2f; %d) va x thuoc (%.2f; +oo)\n", -temp, 0, temp);
		}
		fprintf(output, "\tDao ham bang 0 tai x = 0,  x = %.2f va x = %.2f\n", -temp, temp);
	}
	else
	{
		if (a > 0)
		{
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (-%c; 0)\n", (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (-oo; 0)\n");
			fprintf(output, "\tDao ham bang 0 voi x = 0\n");
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (0; +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (0; +oo)\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (-%c; 0)\n", (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (-oo; 0)\n");
			fprintf(output, "\tDao ham bang 0 voi x = 0\n");
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (0; +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (0; +oo)\n");
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

void XetDau11(float b)
{
	if (b == 1)
		fprintf(output, "\tDao ham luon duong tren TXD cua ham so\n");
	else if (b > 1)
	{
		if ((int)b % 2 != 0)
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (0; 1) va x thuoc (1; +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (0; 1) va x thuoc (1; +oo)\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon duong voi x thuoc (1; +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon duong voi x thuoc (1; +oo)\n");
			fprintf(output, "\tDao ham luon am voi x thuoc (0; 1)\n");
		}
		fprintf(output, "\tDao ham bang 0 tai x = 1\n");
	}
	else if (b < 0)
	{
		if ((int)b % 2 != 0)
		{
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (0; 1) va x thuoc (1; +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (0; 1) va x thuoc (1; +oo)\n");
		}
		else
		{
			if (output == stdout) fprintf(output, "\tDao ham luon am voi x thuoc (1; +%c)\n", (char)236);
			else fprintf(output, "\tDao ham luon am voi x thuoc (1; +oo)\n");
			fprintf(output, "\tDao ham luon duong voi x thuoc (0; 1)");
		}
	}
}

void XetDau12(float a)
{
	if (a > 0) fprintf(output, "\tDao ham luon duong tren TXD cua ham so\n");
	else if (a > 0 && a < 1) fprintf(output, "\tDao ham luon am tren TXD cua ham so");
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

void XetDau18(float a, float b)
{
	if (a > 0)
		fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", -b / a);
	else
	{
		if (a != 0)
			fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f)\n", -b / a);
		else
		{
			if (b < 0)
				fprintf(output, "Ham so khong co dao ham\n");
			else
				fprintf(output, "Dao ham cua ham so luon bang 0\n");
		}
	}
}

void XetDau19(float a, float b, float c)
{
	if (a == 0)
		XetDau18(b, c);
	else {
		float x, y;
		short k;
		GiaiPT_Bac2(a, b, c, x, y, k);
		if (k == -1 || k == 0) {
			if (a > 0) {
				if (output == stdout)
					fprintf(output, "\tDao ham luon am voi x thuoc (-%c, %.2f)\n", (char)236, -b / (2 * a));
				else
					fprintf(output, "\tDao ham luon am voi x thuoc (-oo, %.2f)\n", -b / (2 * a));
				fprintf(output, "\tDao ham bang 0 voi x = %.2f\n", -b / (2 * a));
				if (output == stdout)
					fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, +%c)\n", -b / (2 * a), (char)236);
				else
					fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, +oo)\n", -b / (2 * a));
			}
			else
			{
				fprintf(output, "Ham so khong co dao ham\n");
			}
		}
		else
		{
			if (a > 0) {
				if (-b / (2 * a) < x) {
					fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f)\n", -b / (2 * a));
					fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) hoac (%.2f,+oo)\n", -b / (2 * a), x, y);
					fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", -b / (2 * a));
				}
				else {
					if (-b / (2 * a) > y) {
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f) hoac (%.2f,%.2f)\n", x, y, -b / (2 * a));
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", -b / (2 * a));
						fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", -b / (2 * a));
					}
					else {
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f)\n", x);
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", y);
					}
				}
			}
			else
				if (-b / (2 * a) > x && -b / (2 * a) < y) {
					fprintf(output, "Ham so luon duong voi x thuoc (%.2f,%.2f)\n", -b / (2 * a), y);
					fprintf(output, "Ham so luon am voi x thuoc (%.2f,%.2f)\n", x, -b / (2 * a));
					fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", -b / (2 * a));
				}
				else
					if (-b / 2 * a < x) {
						fprintf(output, "Ham so luon duong voi x thuoc (%.2f,%.2f)\n", x, y);
					}
					else
						fprintf(output, "Ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
		}
	}
}

void XetDau20(float a, float b, float c, float d)
{
	if (a == 0)
		XetDau19(b, c, d);
	else
	{
		float x1, x2, x3, x, y;
		short k, l;
		GiaiPT_Bac3(a, b, c, d, x1, x2, x3, k); 
		GiaiPT_Bac2(3 * a, 2 * b, c, x, y, l);
		if (l == -1) {
			switch (k)
			{
			case 1:
				if (a > 0)
				{
					fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x1);
				}
				else
					fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x1);
				break;
			case 3:
				if (a > 0)
				{
					fprintf(output, "Dao ham cua ham so luon duong voi x thuoc ");
					if (x1 == x2 && x2 == x3)
						fprintf(output, "(%.2f,+oo)\n", x1);
					else
					{
						if (x1 == x2)
							fprintf(output, "(%.2f,+oo)\n", x3);
						else
						{
							if (x2 == x3)
								fprintf(output, "(%.2f,+oo)\n", x1);
							else
								fprintf(output, "(%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3);
						}
					}
				}
				else
				{
					fprintf(output, "Dao ham cua ham so luon duong ");
					if (x1 == x2 && x2 == x3)
						fprintf(output, "(-oo,%.2f)\n", x1);
					else
					{
						if (x1 == x2)
							fprintf(output, "(-oo,%.2f)\n", x3);
						else
						{
							if (x2 == x3)
								fprintf(output, "(-oo,%.2f)v{%.2f}\n", x1, x2);
							else
								fprintf(output, "(-oo,%.2f) v (%.2f,%.2f)\n", x1, x2, x3);
						}
					}
				}
			}
		}
		else 
		{
			if (l == 0) {
				switch (k)
				{
				case 1:
					if (a > 0)
					{
						if (x > x1) {
							fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f\n", x1, x);
							fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
						}
						else
							fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) \n", x1);
					}
					else {
						if (x > x1)
							fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) sao cho x khac %.2f\n", x1, x);
						else {
							fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f\n", x1, x);
							fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
						}
					}
					break;
				case 3:
					if (a > 0)
					{
						if (x1 == x2 && x2 == x3) {
							if (x < x1)
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x1);
							else {
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f\n", x1, x);
								fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
							}
						}
						else
						{
							if (x1 == x2) {
								if (x < x3)
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x3);
								else {
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f\n", x3, x);
									fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
								}
							}
							else
							{
								if (x2 == x3) {
									if (x < x1)
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x1);
									else {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f\n", x1, x);
										fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
									}
								}
								else {
									if (x < x1) {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3);
									}
									else {
										if (x > x1 && x < x2) {
											fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", x);
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo) sao cho x khac %.2f\n", x1, x2, x3, x);
										}
										else {
											if (x > x2 && x < x3) {
												fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3);
											}
											else {
												fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", x);
												fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3);
											}

										}
									}
								}
							}
						}
					}
					else
					{
						if (x1 == x2 && x2 == x3) {
							if (x > x1)
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x1);
							else {
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) sao cho x khac %.2f\n", x1, x);
								fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
							}
						}
						else
						{
							if (x1 == x2)
							{
								if (x > x3)
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc(-oo,%.2f)\n", x3);
								else {
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) sao cho x khac %.2f\n", x3, x);
									fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
								}
							}
							else
							{
								if (x2 == x3)
								{
									if (x > x1)
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x1);
									else {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) sao cho x khac %.2f\n", x1, x);
										fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
									}
								}
								else
								{
									if (x > x3) {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x1, x2, x3);
									}
									else {
										if (x > x2 && x < x3) {
											fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", x);
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f) sao cho x khac %.2f\n", x1, x2, x3, x);
										}
										else {
											if (x > x1 && x < x2) {
												fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x1, x2, x3);
											}
											else {
												fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", x);
												fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x1, x2, x3);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				switch (k)
				{
				case 1:
					if (a > 0)
					{
						if (x > x1 && y > x1) {
							fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x, y);
							fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
							fprintf(output, "Dao ham cua ham so bang 0 voi x1 = %.2f va x2= %.2f\n", x, y);
						}
						else {
							if (x < x1 && y>x1) {
								fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x1, y);
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", y);
								fprintf(output, "Dao ham bang 0 voi x= %.2f\n", y);
							}
							else
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) \n", x1);
						}
					}
					else {
						if (x < x1 && y < x1) {
							fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f) v (%.2f,%.2f) \n", x, y, x1);
							fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f)\n", x, y);
							fprintf(output, "Dao ham cua ham so bang 0 voi x1 = %.2f   x2 = %.2f\n", x, y);
						}
						else {
							if (x<x1 && y>x1) {
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x);
								fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, x1);
								fprintf(output, "Dao ham cua ham so bang 0 voi x= %.2f\n", x);
							}
							else {
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) \n", x1);
							}
						}
					}
					break;
				case 3:
					if (a > 0)
					{
						if (x1 == x2 && x2 == x3) {
							if (x > x1 && y > x1) {
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x, y);
								fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
								fprintf(output, "Dao ham cua ham so bang 0 voi x1 = %.2f va x2= %.2f\n", x, y);
							}
							else {
								if (x < x1 && y>x1) {
									fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x1, y);
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", y);
									fprintf(output, "Dao ham bang 0 voi x= %.2f\n", y);
								}
								else
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) \n", x1);
							}
						}
						else
						{
							if (x1 == x2) {
								if (x < x1 && y < x1)
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x3);
								else {
									if (x<x3 && y>x3) {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f\n", x3, y);
										fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", y);
									}
									else {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f va %.2f\n", x3, x, y);
										fprintf(output, "Dao ham cua ham so bang 0 voi x1 = %.2f va x2= %.2f\n", x, y);
									}
								}
							}
							else
							{
								if (x2 == x3) {
									if (x < x1 && y < x1)
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x1);
									else {
										if (x<x1 && y>x1) {
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f\n", x1, y);
											fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", y);
										}
										else {
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo) sao cho x khac %.2f va %.2f\n", x1, x, y);
											fprintf(output, "Dao ham cua ham so bang 0 voi x1 = %.2f va x2= %.2f\n", x, y);
										}
									}
								}
								else {
									if (x < x1 && y < x1) {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3);
									}
									else {
										if (x<x1 && x >x1) {
											fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", y);
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3);
											fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x1, y);
										}
										else {
											if (x < x2 && y < x2) {
												fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,%.2f) v (%.2f,+oo)\n", x1, x, y, x2, x3);
												fprintf(output, "Dao ham cua ham so luon am voi x thuoc ((%.2f,%.2f)\n", x, y);
												fprintf(output, "Dao ham cua ham so bang 0 voi x1= %.2f   x2= %.2f\n", x, y);
											}
											else {
												if (x<x2 && y>x2) {
													fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x, x3);
													fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, x2);
													fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", x);
												}
												else {
													if (x < x3 && y < x3) {
														fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3);
													}
													else {
														if (x<x3 && y>x3) {
															fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, y);
															fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x3, y);
															fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", y);
														}
														else {
															fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,%.2f) v (%.2f,+oo)\n", x1, x2, x3, x, y);
															fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
															fprintf(output, "Dao ham cua ham so bang 0 voi x1= %.2f   x2= %.2f\n", x, y);
														}
													}
												}

											}

										}
									}
								}
							}
						}
					}
					else
					{
						if (x1 == x2 && x2 == x3) {
							if (x < x1 && y < x1) {
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x, y, x1);
								fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
								fprintf(output, "Dao ham cua ham so bang 0 voi x1= %.2f,x2= %.2f\n", x, y);
							}
							else {
								if (x<x1 && y>x1) {
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x);
									fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, x1);
									fprintf(output, "Dao ham cua ham so bang 0 voi x= %.2f\n", x);
								}
								else
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x1);
							}
						}
						else
						{
							if (x1 == x2)
							{
								if (x > x3 && y > x3)
									fprintf(output, "Dao ham cua ham so luon duong voi x thuoc(-oo,%.2f)\n", x3);
								else {
									if (x<x3 && y>x3) {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x);
										fprintf(output, "Dao ham cua ham so luong am voi x thuoc (%.2f,%.2f)\n", x, x3);
										fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
									}
									else {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f) \n", x, y, x3);
										fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
										fprintf(output, "Dao ham cua ham so bang 0 voi x1 = %.2f   x2=%.2f \n", x, y);
									}

								}
							}
							else
							{
								if (x2 == x3)
								{
									if (x > x1 && y > x1)
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc(-oo,%.2f)\n", x1);
									else {
										if (x<x3 && y>x3) {
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f)\n", x);
											fprintf(output, "Dao ham cua ham so luong am voi x thuoc (%.2f,%.2f)\n", x, x1);
											fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
										}
										else {
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f) \n", x, y, x1);
											fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
											fprintf(output, "Dao ham cua ham so bang 0 voix1 = %.2f  x2=%.2f \n", x, y);
										}
									}
								}
								else
								{
									if (x > x3 && y > x3) {
										fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x1, x2, x3);
									}
									else {
										if (x<x3 && y >x3) {
											fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", x);
											fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x1, x2, x);
											fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, x3);
										}
										else {
											if (x < x3 && y < x3) {
												fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f) v (%.2f,%.2f)\n", x1, x2, x, y, x3);
												fprintf(output, "Dao ham cua ham so luon am voi x thuoc ((%.2f,%.2f)\n", x, y);
												fprintf(output, "Dao ham cua ham so bang 0 voi x1= %.2f   x2= %.2f\n", x, y);
											}
											else {
												if (x<x2 && y>x2) {
													fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x1, y, x3);
													fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x2, y);
													fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f", y);
												}
												else {
													if (x < x2 && y < x2) {
														fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x1, x2, x3);
													}
													else {
														if (x<x1 && y>x1) {
															fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x, x2, x3);
															fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, x1);
															fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x);
														}
														else {
															fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f,%.2f) v (%.2f,%.2f)\n", x, y, x1, x2, x3);
															fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)\n", x, y);
															fprintf(output, "Dao ham cua ham so bang 0 voi x1= %.2f   x2= %.2f\n", x, y);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void XetDau21(float a, float b, float c)
{
	if (a == 0)
		XetDau19(b, 0, c);
	else
	{
		float x1, x2, x3, x4, x5, x6, x7;
		short k, l;
		GiaiPT_Bac4(a, 0, b, 0, c, x1, x2, x3, x4, k);
		GiaiPT_Bac3(4 * a, 0, 2 * b, 0, x5, x6, x7, l);
		switch (k) {
		case 0:
			if (l == 1)//tu co nghiem bang 0
			{
				if (a > 0)
				{
					fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f)\n", x5);
					fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x5);
					fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x5);
				}
				else
					fprintf(output, "Ham so khong co dao ham\n");
			}
			if (l == 3)
			{
				if (a > 0)
				{
					if (x5 == x6 && x6 == x7)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x5);
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f)\n", x5);
						fprintf(output, "Dao ham cua ham so bang 0 voi x = %.2f\n", x5);
					}
					else
					{
						if (x5 == x6)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x7);
							fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x5, x5, x7);
							fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
						}
						else
						{
							if (x6 == x7)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", x5);
								fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f)\n", x5);
								fprintf(output, "Dao ham cua ham so bang khong voi x = %.2f\n", x5);
							}
							else
							{
								fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x5, x6, x7);
								fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x5, x6, x7);
								fprintf(output, "Dao ham cua ham so bang khong voi x thuoc {%.2f,%.2f,%.2f}\n", x5, x6, x7);
							}
						}
					}
				}
				else
					fprintf(output, "Ham so khong co dao ham\n");
			}
			break;
		case 2:
			if (l == 1 || (l == 3 && x5 == x7))
			{
				if (a > 0)
				{
					if (x1 != x2)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,+oo)\n", x2);
						fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f)\n", x1);
					}
					if (x1 == x2)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (-oo,0)\n");
						fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (0,+oo)\n");
					}
				}
				else
				{
					if (x1 != x2)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%2f,0)\n", x1);
						fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (0,%.2f)\n", x2);
						fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
					}
					if (x1 == x2)
					{
						fprintf(output, "Ham so khong co dao ham\n");
					}
				}
			}
			if (l == 3 && x5 != x7)
			{
				if (a > 0)
				{
					if (x1 != x2)
					{
						if (x7 <= x2)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,+oo)\n", x2);
							fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f)\n", x1);
						}
						if (x7 > x2)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x5, x1, x7);
							fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x5, x2, x7);
							fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
						}
					}
					if (x1 == x2)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,+oo)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,%.2f}\n", x5, x7);
					}
				}
				if (a < 0)
				{
					if (x1 != x2)
					{
						if (x7 >= x2)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f)\n", x2);
							fprintf(output, "Dao ham cua ham so luon am voi  moi x thuoc (%.2f,0)\n", x1);
							fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
						}
						if (x7 < x2)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (0,%.2f)\n", x1, x5, x7);
							fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,0) v (%.2f,%.2f)\n", x5, x7, x2);
							fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,0,%.2f}\n", x5, x7);
						}
					}
					if (x1 == x2)
					{
						fprintf(output, "Ham so khong co dao ham\n");
					}
				}
			}
			break;
		case 4:
			if (l == 1 || (l == 3 && x5 == x7))
			{
				if (a > 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,+oo)\n");
						fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,0)\n");
					}
					else
					{
						if (x2 == x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,+oo)\n", x4);
							fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f)\n", x1);
						}
						if (x2 != x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f) v (%.2f,+oo)\n", x3, x4);
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (-oo,%.2f) v (%.2f,0)\n", x1, x2);
							fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
						}
					}
				}
				if (a < 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so khong co dao ham\n");
					}
					else
					{
						if (x2 == x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0)\n", x1);
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f)\n", x4);
						}
						if (x1 != x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x1, x2);
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x3, x4);
						}
					}
				}
			}
			if (l == 3 && x5 != x7)
			{
				if (a > 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,0) v (%.2f,+oo)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f) v (0,%.2f)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
					}
					else
					{
						if (x2 == x3)
						{
							if (x7 <= x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,+oo)\n", x4);
								fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f)\n", x1);
							}
							if (x7 > x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x5, x1, x7);
								fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x5, x4, x7);
								fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
							}
						}
						else
						{
							if (x3 != x4)
							{
								if (x7 < x3)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,%.2f) v (%.2f,+oo)\n", x5, x7, x3, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (%.2f,%.2f) v (0,%.2f)\n", x1, x2, x5, x7);
									fprintf(output, "Dao ham cua ham so bang 0 khi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
								if (x7 >= x3 && x7 <= x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,+oo)\n", x2, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f)\n", x1, x3);
									fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
								}
								if (x7 > x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,0) v (%.2f,+oo)\n", x5, x1, x2, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f) v (%.2f,%.2f)\n", x5, x3, x4, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
							}
							if (x3 == x4)
							{
								if (x7 < x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,%.2f) v (%.2f,+oo)\n", x5, x7, x4, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (%.2f,%.2f) v (0,%.2f)\n", x1, x1, x5, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
								if (x7 == x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,+oo)\n", x5, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f)\n", x5, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
								}
								if (x7 > x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,0) v (%.2f,+oo)\n", x5, x1, x1, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f) v (%.2f,%.2f)\n", x5, x4, x4, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
							}
						}
					}
				}
				if (a < 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so khong co dao ham\n");
					}
					else
					{
						if (x2 == x3)
						{
							if (x7 >= x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f)\n", x4);
								fprintf(output, "Dao ham cua ham so luon am voi  moi x thuoc (%.2f,0)\n", x1);
							}
							if (x7 < x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (0,%.2f)\n", x1, x5, x7);
								fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,0) v (%.2f,%.2f)\n", x5, x7, x4);
								fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
							}
						}
						else
						{
							if (x3 != x4)
							{
								fprintf(output, "Tap xac dinh cua Ham so la [%.2f,%.2f]v[%.2f,%.2f]\n", x1, x2, x3, x4);
								if (x7 <= x3)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x1, x2);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,%.2f)\n", x3, x4);
								}
								if (x7 > x3 && x7 < x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,%.2f)\n", x1, x5, x3, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,%.2f) v (%.2f,%.2f)\n", x5, x2, x7, x4);
									fprintf(output, "Dao ham cua ham so bang 0 khi x thuoc {%.2f,%.2f}\n", x5, x7);
								}
								if (x7 >= x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x3, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,%.2f)\n", x1, x2);
								}
							}
							if (x3 == x4)
								fprintf(output, "Ham so khong co dao ham\n");
						}
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void XetDau22(float a, float b, float c, float d)
{
	if (a == 0)
	{
		if (b == 0)
			fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc TXD\n");
		else
		{
			if (b < 0)
			{
				c = -c;
				d = -d;
			}
			if (c > 0) {
				if (-d - b * c < 0)
					fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,+oo)\n", -d / c);
				else
					fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,+oo)\n", -d / c);
			}
			else
			{
				if (c != 0) {
					if (-d - b * c < 0)
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f)\n", -d / c);
					else
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc ((-oo,%.2f)\n", -d / c);
				}
				else
				{
					if (d >= 0)
						fprintf(output, "Ham so luon duong voi moi x thuoc R\n");
					else
						fprintf(output, "Ham so khong co dao ham\n");
				}
			}
		}
	}
	else
	{
		if (c == 0)
		{
			if (d == 0)
				fprintf(output, "Ham so khong co dao ham\n");
			else
				XetDau18(a / d, b / d);
		}
		else
		{
			float x1 = -b / a;
			float x2 = -d / c;
			if (x1 > x2)
				swap(x1, x2);
			a = d * a;
			if (x1 == x2)
			{
				if (a > 0)
				{
					if (a * d - b * c < 0)
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc R\\{%.2f}\n", -d / c);
					else
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc R\\{%.2f}\n", -d / c);
				}
				else
					fprintf(output, "Ham so khong co dao ham\n");
			}
			else
			{
				if (a > 0)
				{
					if (a * d - b * c < 0)
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f) v (%.2f.+oo)\n", x1, x2);
					else
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (-oo,%.2f) v (%.2f.+oo)\n", x1, x2);
				}
				else
				{
					if (a * d - b * c < 0)
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (%.2f,%.2f)", x1, x2);
					else
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,%.2f)", x1, x2);
				}
			}
		}
	}
}

void XetDau23(float a, float b, float c, float d, float e)
{

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
		fprintf(output, "%.2f / ", (double)a * (double)d - (double)b * (double)c);
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

void DaoHam11(float b)
{
	if (b != 1 && b != 2)
		fprintf(output, "\tDao ham cua Ham so la: y' = (%d*Ln(x) ^ (%d)) / x\n", (int)b, (int)(b - 1));
	else if (b == 1)
		fprintf(output, "\tDao ham cua Ham so la: y' = 1 / x\n");
	else if (b == 2)
		fprintf(output, "\tDao ham cua Ham so la: y' = (2 * Ln(x)) / x\n");
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau11(b);
}

void DaoHam12(float a)
{
	fprintf(output, "\tDao ham cua Ham so la: y' = 1/(x*Ln(a))\n");
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau12(a);
}

void DaoHam13()
{
	fprintf(output, "Dao ham cua ham so co dang: y' = e ^ x\n");
	fprintf(output, "Xet dau dao ham y':\n");
	XetDau16();
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

void DaoHam18(float a, float b)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = %.2f / Can(%.2fx + %.2f)", a / 2, a, b);
	fprintf(output, "\n\nXet dau dao ham y':\n");
	XetDau18(a, b);
}
void DaoHam19(float a, float b, float c)
{
	fprintf(output, "Dao ham cua ham so co dang: y' = ");
	fprintf(output, "(");
	PT_1(a, b / 2);
	fprintf(output, ") / Can(");
	PT_2(a, b, c);
	fprintf(output, ")\nXet dau dao ham y':\n");
	XetDau19(a, b, c);
}
void DaoHam20(float a, float b, float c, float d)
{
	fprintf(output, "Dao ham cua ham so co dang y' = ");
	fprintf(output, "(");
	PT_2(1.5 * a, b, c / 2);
	fprintf(output, ") / Can(");
	PT_3(a, b, c, d);
	fprintf(output, ")\nXet dau dao ham y':\n");
	XetDau20(a, b, c, d);
}

void DaoHam21(float a, float b, float c)
{
	fprintf(output, "Dao ham cua ham so co dang y' = ");
	fprintf(output, "(");
	PT_3(2 * a, 0, b, 0);
	fprintf(output, ") / Can(");
	PT_4(a, b, c);
	fprintf(output, ")\nXet dau dao ham y':\n");
	XetDau21(a, b, c);
}

void DaoHam22(float a, float b, float c, float d)
{
	fprintf(output, "Dao ham cua ham so co dang y' = (");
	DH_4(a, b, c, d);
	fprintf(output, ") / (2 * Can(");
	PT_5(a, b, c, d);
	fprintf(output, "))\nXet dau dao ham y':\n");
	XetDau22(a, b, c, d);
}

void DaoHam23(float a, float b, float c, float d, float e)
{
	fprintf(output, "Dao ham cua ham so co dang y' = (");
	DH_5(a, b, c, d, e);
	fprintf(output, ") / (2 * Can(");
	PT_6(a, b, c, d, e);
	fprintf(output, "))\nXet dau dao ham y':\n");
	XetDau23(a, b, c, d, e);
}



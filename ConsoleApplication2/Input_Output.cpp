#include "Input_Output.h"
#include "TapXacDinh.h"
#include "Equation.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#define epsilon 1e-5
#define _CRT_NONSTDC_NO_WARNINGS

extern FILE * input, * output;

using namespace std;

void Input(char ch, int& k)
{
	if (input == stdin) fprintf(stdout, "%c = ", ch);
	fscanf(input, "%d", &k);
}

void Input(char ch, float& k)
{
	if (input == stdin) fprintf(stdout, "%c = ", ch);
	fscanf(input, "%f", &k);
}

void Input_Equation_Console(int& k)
{
	fprintf(stdout, "Chon Ham so ax + b                     : Nhap 1\n");
	fprintf(stdout, "Chon Ham so ax^2 + bx + c              : Nhap 2\n");
	fprintf(stdout, "Chon Ham so ax^3 + bx^2 + cx + d       : Nhap 3\n");
	fprintf(stdout, "Chon Ham so ax^4 + bx^2 + c            : Nhap 4\n");
	fprintf(stdout, "Chon Ham so (ax + b) / (cx + d)        : Nhap 5\n");
	fprintf(stdout, "Chon Ham so (ax^2 + bx + c) / (dx + e) : Nhap 6\n");
	fprintf(stdout, "Chon cac Ham so khac                   : Nhap 7\n");
	fprintf(stdout, "De dung chuong trinh                   : Nhap 0\n");
	fprintf(stdout, "Nhap vao 1 so N: ");
	while (true)
	{
		Input('N', k);
		if (k < 0 || k>17)
		{
			fprintf(stdout, "Du lieu ban nhap vao khong hop le!!!\a\n");
			fprintf(stdout, "Xin moi ban nhap lai 1 so N: ");
		}
		else break;
	}
}

void Input_Equation_File(int& k)
{
	Input('N', k);
}

void Output_Equation(int& k, float& a, float& b, float& c, float& d, float& e)
{
	switch (k)
	{
	case 1:
		Input('a', a);
		Input('b', b);
	Equation1:
		fprintf(output, "* Ham so co dang: y = ");
		PT_1(a, b);
		fprintf(output, "\n");
		break;
	case 2:
		Input('a', a);
		Input('b', b);
		Input('c', c);
	Equation2:
		if (a == 0)
		{
			k = 1;
			a = b;
			b = c;
			goto Equation1;
		}
		fprintf(output, "* Ham so co dang: y = ");
		PT_2(a, b, c);
		fprintf(output, "\n");
		break;
	case 3:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		if (a == 0)
		{
			k = 2;
			a = b;
			b = c;
			c = d;
			goto Equation2;
		}
		fprintf(output, "* Ham so co dang: y = ");
		PT_3(a, b, c, d);
		fprintf(output, "\n");
		break;
	case 4:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		if (a == 0)
		{
			k = 2;
			a = b;
			b = 0;
			goto Equation2;
		}
		fprintf(output, "* Ham so co dang: y = ");
		PT_4(a, b, c);
		fprintf(output, "\n");
		break;
	case 5:
	Equa5:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
	Equation5:
		if (c == 0 && d == 0)
		{
			fprintf(output, "Ham so khong hop le vi mau so bang 0!!!\n");
			fprintf(output, "Ban muon nhap lai phuong trinh loai nay : Nhap 1\n");
			fprintf(output, "Ban muon nhap cac loai phuong trinh khac: Nhap 2\n");
			int n;
			while (true)
			{
				Input('N', n);
				if (n != 1 && n != 2)
				{
					fprintf(output, "Du lieu ban nhap vao khong hop le!!!\a\n");
					fprintf(output, "Xin moi ban nhap lai 1 so N: ");
				}
				else break;
			}
			if (n == 1) goto Equa5;
			else
			{
				k = 0;
				return;
			}
		}
		if (c == 0)
		{
			k = 1;
			a /= d;
			b /= d;
			goto Equation1;
		}
		if (b == 0 && d == 0)
		{
			k = 1;
			b = a / c;
			a = 0;
			goto Equation1;
		}
		if (fabs(Equa_1(a, b, -d / c)) < epsilon)
		{
			k = 1;
			b = a / c;
			a = 0;
			goto Equation1;
		}
		fprintf(output, "* Ham so co dang: y = ");
		PT_5(a, b, c, d);
		fprintf(output, "\n");
		break;
	case 6:
	Equa6:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		Input('e', e);
		if (a == 0)
		{
			k = 5;
			a = b;
			b = c;
			c = d;
			d = e;
			goto Equation5;
		}
		if (d == 0 && e == 0)
		{
			fprintf(output, "Ham so khong hop le vi mau so bang 0!!!\n");
			fprintf(output, "Ban muon nhap lai phuong trinh loai nay : Nhap 1\n");
			fprintf(output, "Ban muon nhap cac loai phuong trinh khac: Nhap 2\n");
			int n;
			while (true)
			{
				Input('N', n);
				if (n != 1 && n != 2)
				{
					fprintf(output, "Du lieu ban nhap vao khong hop le!!!\a\n");
					fprintf(output, "Xin moi ban nhap lai 1 so N: ");
				}
				else break;
			}
			if (n == 1) goto Equa6;
			else
			{
				k = 0;
				return;
			}
		}
		if (d == 0)
		{
			k = 2;
			a /= e;
			b /= e;
			c /= e;
			goto Equation2;
		}
		if (a == 0 && b == 0 && c == 0)
		{
			k = 1;
			goto Equation1;
		}
		if (c == 0 && e == 0)
		{
			k = 2;
			a /= d;
			b /= d;
			goto Equation1;
		}
		float x, y;
		short n;
		GiaiPT_Bac2(a, b, c, x, y, n);
		if (n != -1)
		{
			if (n == 0) y = x;
			if (fabs(x + e / d) < epsilon)
			{
				k = 1;
				float temp = a;
				a /= d;
				b = -a * y / d;
				goto Equation1;
			}
			if (fabs(y + e / d) < epsilon)
			{
				k = 1;
				float temp = a;
				a /= d;
				b = -a * x / d;
				goto Equation1;
			}
		}
		fprintf(output, "* Ham so co dang: y = ");
		PT_6(a, b, c, d, e);
		fprintf(output, "\n");
		break;
	default:
		system("cls");
		CacHamSoKhac(k, a, b, c, d, e);
		break;
	}
}

void Output_Advanced_Equation(int& k, float& a, float& b, float& c, float& d, float& e)
{
	switch (k)
	{
	case 7:
		Input('a', a);
		Input('b', b);
		Input('R', c);
		if (c <= 0)
		{
			if (input == stdin)
				while (c < epsilon)
				{
					fprintf(stdout, "\aBan kinh duong tron ban nhap vao phai khac 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('R', c);
				}
			else
			{
				fprintf(output, "Khong the ve do thi duong tron voi R = 0!!!\n\n");
				if (output == stdout) system("pause");
				k = 0;
				return;
			}
		}
		fprintf(output, "* Phuong trinh co dang: ");
		PT_7(a, b, c);
		fprintf(output, "\n");
		break;
	case 8:
		Input('a', a);
		Input('b', b);
	PT8:
		if (a <= 0)
		{
			if (input == stdin)
				while (a < epsilon)
				{
					fprintf(stdout, "\aDu lieu ban nhap vao phai khac 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('a', a);
				}
			else
			{
				fprintf(output, "Khong the ve do thi Elips voi a = 0!!!\n\n");
				if (output == stdout) system("pause");
				k = 0;
				return;
			}
		}
		if (b <= 0)
		{
			if (input == stdin)
				while (b < epsilon)
				{
					fprintf(stdout, "Du lieu ban nhap vao phai khac 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('b', b);
				}
			else
			{
				fprintf(output, "Khong the ve do thi Elips voi b = 0!!!\n\n");
				if (output == stdout) system("pause");
				k = 0;
				return;
			}
		}
		fprintf(output, "* Phuong trinh co dang: ");
		PT_8(a, b);
		fprintf(output, "\n");
		break;
	case 9:
		Input('h', a);
		Input('k', b);
		Input('a', c);
		Input('b', d);
		if (c < epsilon)
		{
			if (input == stdin)
				while (c < epsilon)
				{
					fprintf(stdout, "\aDu lieu ban nhap vao phai lon hon 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('a', c);
				}
			else
			{
				fprintf(output, "Khong the ve do thi Hyperbol!!!\n\n");
				if (output == stdout) system("pause");
				k = 0;
				return;
			}
		}
		if (d < epsilon)
		{
			if (input == stdin)
				while (d < epsilon)
				{
					fprintf(stdout, "\aDu lieu ban nhap vao phai lon hon 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('b', d);
				}
			else
			{
				fprintf(output, "Khong the ve do thi Hyperbol!!!\n\n");
				if (output == stdout) system("pause");
				k = 0;
				return;
			}
		}
		fprintf(output, "* Phuong trinh co dang: ");
		PT_9(a, b, c, d);
		fprintf(output, "\n");
		break;
	case 10:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		Input('e', e);
		fprintf(output, "* Phuong trinh co dang: ");
		PT_10(a, b, c, d, e);
		fprintf(output, "\n");
		break;
	default:
		break;
	}
}

void CacHamSoKhac(int& k, float& a, float& b, float& c, float& d, float& e)
{
	if (input == stdin)
	{
		fprintf(stdout, "Chon Phuong trinh Duong tron (x - a)^2 + (y - b)^2 = R^2              : Nhap 1\n");
		fprintf(stdout, "Chon Phuong trinh Elips (x^2 / a^2) + (y^2 / b^2) = 1                 : Nhap 2\n");
		fprintf(stdout, "Chon Phuong trinh Hyperbol [(x - h)^2 / a^2] - [(y - k)^2 / b^2] = 1  : Nhap 3\n");
		fprintf(stdout, "Chon Phuong trinh Parabol (ax + by)^2 + cx + dy + e = 0               : Nhap 4\n");
		fprintf(stdout, "Chon Ham so y = [Ln(a)]^b                                             : Nhap 5\n");
		fprintf(stdout, "Chon Ham so y = Log(x)a                                               : Nhap 6\n");
		fprintf(stdout, "Chon Ham so y = e^x                                                   : Nhap 7\n");
		fprintf(stdout, "Chon Ham so y = Sin(x)                                                : Nhap 8\n");
		fprintf(stdout, "Chon Ham so y = Cos(x)                                                : Nhap 9\n");
		fprintf(stdout, "Chon Ham so y = Tan(x)                                                : Nhap 10\n");
		fprintf(stdout, "Chon Ham so y = Cotan(x)                                              : Nhap 11\n");
		fprintf(stdout, "Ban muon tinh ham can thuc cua cac ham so co ban                      : Nhap 12\n");
		fprintf(stdout, "Ban muon tinh ham tri tuyet doi cua cac ham so co ban                 : Nhap 13\n");
		fprintf(stdout, "De dung chuong trinh                                                  : Nhap 0\n");
		fprintf(stdout, "Nhap vao 1 so N: ");
		while (true)
		{
			Input('N', k);
			if (k < 0 || k>13)
			{
				fprintf(stdout, "Du lieu ban nhap vao khong hop le!!!\a\n");
				fprintf(stdout, "Xin moi ban nhap lai 1 so N: ");
			}
			else break;
		}
		if (k == 0) return;
		k += 6;
	}
	Output_Advanced_Equation(k, a, b, c, d, e);
}

void PT_1(float a, float b)
{
	if (a != 0)
	{
		if (a == 1) fprintf(output, "x");
		else if (a == -1) fprintf(output, "-x");
		else fprintf(output, "%.2fx", a);
	}
	if (a == 0) fprintf(output, "%.2f", b);
	else
	{
		if (b > 0) fprintf(output, " + %.2f", b);
		else if (b < 0) fprintf(output, " - %.2f", -b);
	}
}

void PT_2(float a, float b, float c)
{
	if (a == 0)
	{
		PT_1(b, c);
		return;
	}
	if (a == 1) fprintf(output, "x^2");
	else if (a == -1) fprintf(output, "-x^2");
	else fprintf(output, "%.2fx^2", a);
	if (b != 0)
	{
		if (b == 1) fprintf(output, " + x");
		else if (b == -1) fprintf(output, " - x");
		else if (b > 0) fprintf(output, " + %.2fx", b);
		else if (b < 0) fprintf(output, " - %.2fx", -b);
	}
	if (c != 0)
	{
		if (c > 0) fprintf(output, " + %.2f", c);
		else if (c < 0) fprintf(output, " - %.2f", -c);
	}
}

void PT_3(float a, float b, float c, float d)
{
	if (a == 0)
	{
		PT_2(b, c, d);
		return;
	}
	if (a == 1) fprintf(output, "x^3");
	else if (a == -1) fprintf(output, "-x^3");
	else fprintf(output, "%.2fx^3", a);
	if (b != 0)
		if (b == 1) fprintf(output, " + x^2");
		else if (b == -1) fprintf(output, " - x^2");
		else if (b > 0) fprintf(output, " + %.2fx^2", b);
		else if (b < 0) fprintf(output, " - %.2fx^2", -b);
	if (c != 0)
		if (c == 1) fprintf(output, " + x");
		else if (c == -1) fprintf(output, " - x");
		else if (c > 0) fprintf(output, " + %.2fx", c);
		else if (c < 0) fprintf(output, " - %.2fx", -c);
	if (d != 0)
	{
		if (d > 0) fprintf(output, " + %.2f", d);
		else if (d < 0) fprintf(output, " - %.2f", -d);
	}
}

void PT_4(float a, float b, float c)
{
	if (a == 0)
	{
		PT_2(b, 0, c);
		return;
	}
	if (a == 1) fprintf(output, "x^4");
	else if (a == -1) fprintf(output, "-x^4");
	else fprintf(output, "%.2fx^4", a);
	if (b != 0)
		if (b == 1) fprintf(output, " + x^2");
		else if (b == -1) fprintf(output, " - x^2");
		else if (b > 0) fprintf(output, " + %.2fx^2", b);
		else if (b < 0) fprintf(output, " - %.2fx^2", -b);
	if (c != 0)
	{
		if (c > 0) fprintf(output, " + %.2f", c);
		else if (c < 0) fprintf(output, " - %.2f", -c);
	}
}

void PT_5(float a, float b, float c, float d)
{
	if (a != 0 && b != 0) fprintf(output, "(");
	PT_1(a, b);
	if (a != 0 && b != 0) fprintf(output, ")");
	fprintf(output, " / ");
	if (c != 0 && d != 0) fprintf(output, "(");
	PT_1(c, d);
	if (c != 0 && d != 0) fprintf(output, ")");
}

void PT_6(float a, float b, float c, float d, float e)
{
	if (a == 0)
	{
		PT_5(b, c, d, e);
		return;
	}
	if (b != 0 || c != 0) fprintf(output, "(");
	PT_2(a, b, c);
	if (b != 0 || c != 0) fprintf(output, ")");
	fprintf(output, " / ");
	if (d != 0 && e != 0) fprintf(output, "(");
	PT_1(d, e);
	if (d != 0 && e != 0) fprintf(output, ")");
}

void PT_7(float a, float b, float c)
{
	if (fabs(a) < epsilon) fprintf(output, "x^2 + ");
	else if (a > 0) fprintf(output, "(x - %.2f)^2 + ", a);
	else fprintf(output, "(x + %.2f)^2 + ", -a);
	if (fabs(b) < epsilon) fprintf(output, "y^2 = %.2f", c * c);
	else if (b > 0) fprintf(output, "(y - %.2f)^2 = %.2f", b, c * c);
	else fprintf(output, "(y + %.2f)^2 = %.2f", -b, c * c);
}

void PT_8(float a, float b)
{
	fprintf(output, "x^2 / %.2f + y^2 / %.2f = 1", a * a, b * b);
}

void PT_9(float h, float k, float a, float b)
{
	if (fabs(h) < epsilon) fprintf(output, "x^2 / %.2f - ", a * a);
	else if (h > 0) fprintf(output, "(x - %.2f)^2 / %.2f - ", h, a * a);
	else fprintf(output, "(x + %.2f)^2 / %.2f - ", -h, a * a);
	if (fabs(k) < epsilon) fprintf(output, "y^2 / %.2f = 1", b * b);
	else if (k > 0) fprintf(output, "(y - %.2f)^2 / %.2f = 1", k, b * b);
	else fprintf(output, "(y + %.2f)^2 / %.2f = 1", -b, b * b);
}

void PT_10(float a, float b, float c, float d, float e)
{
	if (a != 0)
	{
		if (b > 0) fprintf(output, "(%.2fx + %.2fy)^2", a, b);
		else if (b < 0) fprintf(output, "(%.2fx - %.2fy)^2", a, -b);
		else fprintf(output, "%.2fx^2", a * a);
	}
	else if (b != 0) fprintf(output, "%.2fy^2", b * b);
	if (c > 0) fprintf(output, " + %.2fx", c);
	else if (c < 0) fprintf(output, " - %.2fx", -c);
	if (d > 0) fprintf(output, " + %.2fy", d);
	else if (d < 0) fprintf(output, " - %.2fy", -d);
	if (e > 0) fprintf(output, " + %.2f", e);
	else if (e < 0) fprintf(output, " - %.2f", -e);
	fprintf(output, " = 0");
}

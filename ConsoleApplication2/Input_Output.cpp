#include "Input_Output.h"
#include "TapXacDinh.h"
#include "Equation.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string>
#define epsilon 1e-5
#define _CRT_NONSTDC_NO_WARNINGS

extern FILE * input, * output;

using namespace std;

void Input(char ch, int& k)
{
	if (input == stdin && ch != ' ') fprintf(stdout, "%c = ", ch);
	fscanf(input, "%d", &k);
}

void Input(char ch, float& k)
{
	if (input == stdin && ch != ' ') fprintf(stdout, "%c = ", ch);
	char s[50];
	fflush(input);
	fscanf(input, "%s", &s);
	k = 0;
	int i,dem=0;
	for (i = 0; i < strlen(s); i++)
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' && s[i] != '-') break;
		else if (s[i] != '-') k = k * 10 + (int)(s[i] - '0'); else dem++;
	if (s[i] == '.')
	{
		float temp = 1;
		int j;
		for (j = i + 1; j < strlen(s); j++)
			if (s[j] == '\n') return; else
				if ((s[j] < '0' || s[j] > '9') && s[j] != ' ') break; else
				{
					temp *= 0.1;
					k += temp * (int)(s[j] - '0');
				}
		i = j;
	}
	if (dem % 2 != 0) k *= -1;
	if (s[i] == '/')
	{
		float temp = 0;
		int j,dem=0;
		for (j = i + 1; j < strlen(s); j++)
			if ((s[j] < '0' || s[j] > '9') && s[j] != ' ' && s[j] != '-') break;
			else if (s[j] != '-') temp = temp * 10 + (int)(s[j] - '0'); else dem++;
		if (s[j] == '.')
		{
			float temp1 = 1;
			for (int k = j + 1; k < strlen(s); k++)
				if (s[k] == '\n') break; else
					if ((s[k] < '0' || s[k] > '9') && s[k] != ' ') break; else
					{
						temp1 *= 0.1;
						temp += temp1 * (int)(s[k] - '0');
					}
		}
		if (dem % 2 != 0) temp *= -1;
		if (temp != 0) k /= temp;
	}

}

void Input_Equation_Console(int& k)
{
	fprintf(stdout, "Nhap 1: Chon Ham so ax + b\n");
	fprintf(stdout, "Nhap 2: Chon Ham so ax^2 + bx + c\n");
	fprintf(stdout, "Nhap 3: Chon Ham so ax^3 + bx^2 + cx + d\n");
	fprintf(stdout, "Nhap 4: Chon Ham so ax^4 + bx^2 + c\n");
	fprintf(stdout, "Nhap 5: Chon Ham so (ax + b) / (cx + d)\n");
	fprintf(stdout, "Nhap 6: Chon Ham so (ax^2 + bx + c) / (dx + e)\n");
	fprintf(stdout, "Nhap 7: Chon cac Ham so khac\n");
	fprintf(stdout, "Nhap 0: De dung chuong trinh\n");
	fprintf(stdout, "Nhap vao 1 so N: ");
	while (true)
	{
		Input('N', k);
		if (k < 0 || k>7)
		{
			fprintf(stdout, "Du lieu ban nhap vao khong hop le!!!\a\n");
			fprintf(stdout, "Xin moi ban nhap lai 1 so N: ");
		}
		else break;
	}
}

void Input_Equation_File(int& k)
{
	fscanf(input, "%d", &k);
}

void Output_Equation(int& k, float& a, float& b, float& c, float& d, float& e)
{
Call:
	switch (k)
	{
		if (k < 0 || k>29) return;
	case 1: case 18: case 24:
		Input('a', a);
		Input('b', b);
	Equation1:
		fprintf(output, "* Ham so co dang: y = ");
		if (k == 18) fprintf(output, "Can(");
		else if (k == 24) fprintf(output, "|");
		PT_1(a, b);
		if (k == 18) fprintf(output, ")");
		else if (k == 24) fprintf(output, "|");
		fprintf(output, "\n");
		break;
	case 2:case 19: case 25:
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
		if (k == 19) fprintf(output, "Can(");
		else if (k == 25) fprintf(output, "|");
		PT_2(a, b, c);
		if (k == 19) fprintf(output, ")");
		else if (k == 25) fprintf(output, "|");
		fprintf(output, "\n");
		break;
	case 3:case 20: case 26:
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
		if (k == 20) fprintf(output, "Can(");
		else if (k == 26) fprintf(output, "|");
		PT_3(a, b, c, d);
		if (k == 20) fprintf(output, ")");
		else if (k == 26) fprintf(output, "|");
		fprintf(output, "\n");
		break;
	case 4:case 21: case 27:
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
		if (k == 21) fprintf(output, "Can(");
		else if (k == 27) fprintf(output, "|");
		PT_4(a, b, c);
		if (k == 21) fprintf(output, ")");
		else if (k == 27) fprintf(output, "|");
		fprintf(output, "\n");
		break;
	case 5:case 22: case 28:
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
		if (k == 22) fprintf(output, "Can(");
		else if (k == 28) fprintf(output, "|");
		PT_5(a, b, c, d);
		if (k == 22) fprintf(output, ")");
		else if (k == 28) fprintf(output, "|");
		fprintf(output, "\n");
		break;
	case 6:case 23: case 29:
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
		if (k == 23) fprintf(output, "Can(");
		else if (k == 29) fprintf(output, "|");
		PT_6(a, b, c, d, e);
		if (k == 23) fprintf(output, ")");
		else if (k == 29) fprintf(output, "|");
		fprintf(output, "\n");
		break;
	default:
		system("cls");
		CacHamSoKhac(k, a, b, c, d, e);
		if (k > 17) goto Call;
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
					fprintf(stdout, "\aBan kinh duong tron ban nhap vao phai > 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('R', c);
				}
			else
			{
				fprintf(output, "Khong the ve do thi duong tron voi R <= 0!!!\n\n");
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
		if (a <= 0)
		{
			if (input == stdin)
				while (a < epsilon)
				{
					fprintf(stdout, "\aDu lieu ban nhap vao phai lon hon 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('a', a);
				}
			else
			{
				fprintf(output, "Khong the ve do thi Elips voi a <= 0!!!\n\n");
				return;
			}
		}
		if (b <= 0)
		{
			if (input == stdin)
				while (b < epsilon)
				{
					fprintf(stdout, "Du lieu ban nhap vao phai lon hon 0!!!\n");
					fprintf(stdout, "Moi ban nhap lai du lieu:\n");
					Input('b', b);
				}
			else
			{
				fprintf(output, "Khong the ve do thi Elips voi x <= 0!!!\n\n");
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
	case 14:
		fprintf(output, "\n* Ham so co dang: y = Sin(x)\n");
		break;
	case 15:
		fprintf(output, "\n* Ham so co dang: y = Cos(x)\n");
		break;
	case 16:
		fprintf(output, "\n* Ham so co dang: y = Tan(x)\n");
		break;
	case 17:
		fprintf(output, "\n* Ham so co dang: y = Cot(x)\n");
		break;
	case 18:
		system("cls");
		k--;
		Ham_Khac(k, 0);
		break;
	case 19:
		system("cls");
		Ham_Khac(k, 4);
		break;
	default:
		break;
	}
}

void Ham_Khac(int& k, int temp)
{
	if (input == stdin)
	{
		k += temp;
		int n;
		fprintf(stdout, "Nhap 1: Chon Ham so ax + b\n");
		fprintf(stdout, "Nhap 2: Chon Ham so ax^2 + bx + c\n");
		fprintf(stdout, "Nhap 3: Chon Ham so ax^3 + bx^2 + cx + d\n");
		fprintf(stdout, "Nhap 4: Chon Ham so ax^4 + bx^2 + c\n");
		fprintf(stdout, "Nhap 5: Chon Ham so (ax + b) / (cx + d)\n");
		fprintf(stdout, "Nhap 6: Chon Ham so (ax^2 + bx + c) / (dx + e)\n");
		fprintf(stdout, "Nhap 0: De dung chuong trinh\n");
		fprintf(stdout, "Nhap vao 1 so N: ");
		while (true)
		{
			Input('N', n);
			if (n < 0 || n>6)
			{
				fprintf(stdout, "Du lieu ban nhap vao khong hop le!!!\a\n");
				fprintf(stdout, "Xin moi ban nhap lai 1 so N: ");
			}
			else break;
		}
		if (n == 0) return;
		k += n;
	}
}

void CacHamSoKhac(int& k, float& a, float& b, float& c, float& d, float& e)
{
	if (input == stdin)
	{
		fprintf(stdout, "Nhap 1 : Chon Phuong trinh Duong tron (x - a)^2 + (y - b)^2 = R^2\n");
		fprintf(stdout, "Nhap 2 : Chon Phuong trinh Elips (x^2 / a^2) + (y^2 / b^2) = 1\n");
		fprintf(stdout, "Nhap 3 : Chon Phuong trinh Hyperbol [(x - h)^2 / a^2] - [(y - k)^2 / b^2] = 1\n");
		fprintf(stdout, "Nhap 4 : Chon Phuong trinh Parabol (ax + by)^2 + cx + dy + e = 0\n");
		fprintf(stdout, "Nhap 5 : Chon Ham so y = [Ln(a)]^b\n");
		fprintf(stdout, "Nhap 6 : Chon Ham so y = Log(x)a\n");
		fprintf(stdout, "Nhap 7 : Chon Ham so y = e^x\n");
		fprintf(stdout, "Nhap 8 : Ham so y = Sin(x)\n");
		fprintf(stdout, "Nhap 9 : Chon Ham so y = Cos(x)\n");
		fprintf(stdout, "Nhap 10: Chon Ham so y = Tan(x)\n");
		fprintf(stdout, "Nhap 11: Chon Ham so y = Cotan(x)\n");
		fprintf(stdout, "Nhap 12: Ban muon tinh ham can thuc cua cac ham so co ban\n");
		fprintf(stdout, "Nhap 13: Ban muon tinh ham tri tuyet doi cua cac ham so co ban\n");
		fprintf(stdout, "Nhap 0 : De dung chuong trinh\n");
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

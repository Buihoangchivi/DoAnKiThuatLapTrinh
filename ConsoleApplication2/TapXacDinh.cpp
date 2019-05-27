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
		break;
	case 18:
		TapXacDinh_18(a, b);
		break;
	case 19:
		TapXacDinh_19(a, b, c);
		break;
	case 20:
		TapXacDinh_20(a, b, c, d);
		break;
	case 21:
		TapXacDinh_21(a, b, c);
		break;
	case 22:
		TapXacDinh_22(a, b, c, d);
		break;
	case 23:
		TapXacDinh_23(a, b, c, d, e);
		break;
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

void TapXacDinh_18(float a, float b)
{
	if (a > 0)
		fprintf(output, "Tap xac dinh cua Ham so la [%.2f,+oo)\n", -b / a);
	else
	{
		if (a != 0)
			fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f]\n", -b / a);
		else
		{
			if (b >= 0)
				fprintf(output, "Tap xac dinh cua Ham so la R\n");
			else
				fprintf(output, "Ham so khong xac dinh voi moi x thuoc R\n");
		}
	}
}

void TapXacDinh_19(float a, float b, float c)
{
	if (a == 0)
		TapXacDinh_18(b, c);
	else {
		float x, y;
		short k;
		GiaiPT_Bac2(a, b, c, x, y, k);
		if (k == -1 || k == 0) {
			if (a > 0)
				fprintf(output, "Tap xac dinh cua Ham so la R\n");
			else
			{
				if (k == 0)
					fprintf(output, "Tap xac dinh cua ham so la {%.2f}", x);
				else
					fprintf(output, "Ham so khong xac dinh voi moi x thuoc R\n");
			}
		}
		else
		{
			if (a > 0)
				fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f]v[%.2f.+oo)\n", x, y);
			else
				fprintf(output, "Tap xac dinh cua Ham so la [%.2f,%.2f]", x, y);
		}
	}
}

void TapXacDinh_20(float a, float b, float c, float d)
{
	if (a == 0)
		TapXacDinh_19(b, c, d);
	else
	{
		float x1, x2, x3;
		short k;
		GiaiPT_Bac3(a, b, c, d, x1, x2, x3, k);
		switch (k)
		{
		case 1:
			if (a > 0)
				fprintf(output, "Tap xac dinh cua Ham so la [%.2f,+oo)\n", x1);
			else
				fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f]\n", x1);
			break;
		case 3:
			if (a > 0)
			{
				fprintf(output, "Tap xac dinh cua Ham so la ");
				if (x1 == x2 && x2 == x3)
					fprintf(output, "[%.2f,+oo)\n", x1);
				else
				{
					if (x1 == x2)
						fprintf(output, "{%.2f}v[%.2f,+oo)\n", x1, x3);
					else
					{
						if (x2 == x3)
							fprintf(output, "[%.2f,+oo)\n", x1);
						else
							fprintf(output, "[%.2f,%.2f]v[%.2f,+oo)\n", x1, x2, x3);
					}
				}
			}
			else
			{
				fprintf(output, "Tap xac dinh cua Ham so la ");
				if (x1 == x2 && x2 == x3)
					fprintf(output, "(-oo,%.2f]\n", x1);
				else
				{
					if (x1 == x2)
						fprintf(output, "(-oo,%.2f]\n", x3);
					else
					{
						if (x2 == x3)
							fprintf(output, "(-oo,%.2f]v{%.2f}\n", x1, x2);
						else
							fprintf(output, "(-oo,%.2f]v[%.2f,%.2f]\n", x1, x2, x3);
					}
				}
			}
		}
	}
}

void TapXacDinh_21(float a, float b, float c)
{
	if (a == 0)
		TapXacDinh_19(b, 0, c);
	else
	{
		float x1, x2, x3, x4;
		short k;
		GiaiPT_Bac4(a, 0, b, 0, c, x1, x2, x3, x4, k);
		switch (k) {
		case 0:
			if (a > 0)
				fprintf(output, "Tap xac dinh cua Ham so la R\n");
			else
				fprintf(output, "Ham so khong xac dinh voi moi x thuoc R\n");
			break;
		case 2:
			if (a > 0)
			{
				if (x1 != x2)
					fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f]v[%.2f,+oo)\n", x1, x2);
				else
					fprintf(output, "Tap xac dinh cua Ham so la R\n");
			}
			else
			{
				if (x1 != x2)
					fprintf(output, "Tap xac dinh cua Ham so la [%.2f,%.2f]\n", x1, x2);
				else
					fprintf(output, "Tap xac dinh cua Ham so la {0}\n");
			}
			break;
		case 4:
			if (a > 0)
			{
				if (x1 == x4)
					fprintf(output, "Tap xac dinh cua Ham so la R\n");
				else
				{
					if (x2 == x3)
						fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f]v{0}v[%.2f,+oo)\n", x1, x4);
					else
					{
						if (x3 != x4)
							fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f]v[%.2f,%.2f]v[%.2f,+oo)\n", x1, x2, x3, x4);
						if (x3 == x4)
							fprintf(output, "Tap xac dinh cua ham so la R\n");
					}
				}
			}
			else
			{
				if (x1 == x4)
					fprintf(output, "Tap xac dinh cua Ham so la {0}\n");
				else
				{
					if (x2 == x3)
						fprintf(output, "Tap xac dinh cua Ham so la [%.2f,%.2f]\n", x1, x4);
					else
					{
						if (x3 != x4)
							fprintf(output, "Tap xac dinh cua Ham so la [%.2f,%.2f]v[%.2f,%.2f]\n", x1, x2, x3, x4);
						if (x3 == x4)
							fprintf(output, "Tap xac dinh cua ham so la {%.2f,%.2f}\n", x2, x3);
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void TapXacDinh_22(float a, float b, float c, float d)
{
	if (a == 0)
	{
		if (b == 0)
			fprintf(output, "Tap xac dinh cua Ham so la R\\{%.2f}\n", -d / c);
		else
		{
			if (b < 0)
			{
				c = -c;
				d = -d;
			}
			if (c > 0)
				fprintf(output, "Tap xac dinh cua Ham so la (%.2f,+oo)\n", -d / c);
			else
			{
				if (c != 0)
					fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f)\n", -d / c);
				else
				{
					if (d >= 0)
						fprintf(output, "Tap xac dinh cua Ham so la R\n");
					else
						fprintf(output, "Ham so khong xac dinh voi moi x thuoc R\n");
				}
			}
		}
	}
	else
	{
		if (c == 0)
		{
			if (d == 0)
				fprintf(output, "Ham so khong xac dinh voi moi x %c R\n", 238);
			else
				TapXacDinh_18(a / d, b / d);
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
					fprintf(output, "Tap xac dinh cua Ham so la R\\{%.2f}\n", -d / c);
				else
					fprintf(output, "Ham so khong xac dinh voi moi x thuoc R\n");
			}
			else
			{
				if (a > 0)
				{
					if (x1 == -d / c)
						fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f)v[%.2f.+oo)\n", x1, x2);
					else
						fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f]v(%.2f.+oo)\n", x1, x2);
				}
				else
				{
					if (x1 == -d / c)
						fprintf(output, "Tap xac dinh cua Ham so la (%.2f,%.2f]", x1, x2);
					else
						fprintf(output, "Tap xac dinh cua Ham so la [%.2f,%.2f)", x1, x2);
				}
			}
		}
	}
}

void TapXacDinh_23(float a, float b, float c, float d, float e)
{
	if (a == 0)
		TapXacDinh_22(b, c, d, e);
	else
	{
		if (d == 0)
		{
			if (e == 0)
				fprintf(output, "Ham so khong xac dinh voi moi x thuoc R\n");
			else
				TapXacDinh_19(a / e, b / e, c / e);
		}
		else
		{
			float x3 = -e / d;
			float x1, x2;
			short k;
			GiaiPT_Bac2(a, b, c, x1, x2, k);
			if (k == -1 || k == 0)
			{
				d = d / a;
				e = e / a;
				if (d > 0)
				{
					if (k == 0 && x1 < -e / d)
						fprintf(output, "Tap xac dinh cua Ham so la {%.2f}v(%.2f,+oo)\n", -e / d, x1);
					else
						fprintf(output, "Tap xac dinh cua Ham so la (%.2f,+oo)\n", -e / d);
				}
				else
				{
					if (k == 0 && x1 > -e / d)
						fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f)v{%.2f}\n", -e / d, x1);
					else
						fprintf(output, "Tap xac dinh cua Ham so la (-oo,%.2f)\n", -e / d);
				}
			}
			else
			{
				if (x3 > x1 && x3 < x2)
					swap(x2, x3);
				if (x3 <= x1)
				{
					swap(x3, x2);
					swap(x3, x1);
				}
				a = a / d;
				if (a > 0)
				{
					fprintf(output, "Tap xac dinh cua Ham so la ");
					if (x1 == x2)
						fprintf(output, "[%.2f,+oo)\n", x3);
					else
					{
						if (x2 == x3)
							fprintf(output, "[%.2f,+oo)\\{%.2f}\n", x1, x2);
						else
						{
							if (x1 == -e / d)
								fprintf(output, "(%.2f,%.2f]v[%.2f,+oo)\n", x1, x2, x3);
							if (x2 == -e / d)
								fprintf(output, "[%.2f,%.2f)v[%.2f,+oo)\n", x1, x2, x3);
							if (x3 == -e / d)
								fprintf(output, "[%.2f,%.2f]v(%.2f,+oo)\n", x1, x2, x3);
						}
					}
				}
				else
				{
					fprintf(output, "Tap xac dinh cua Ham so la ");
					if (x1 == x2)
						fprintf(output, "(-oo,%.2f] \\ {%.2f}\n", x3, x1);
					else
					{
						if (x2 == x3)
							fprintf(output, "(-oo,%.2f]\n", x1);
						else
						{
							if (x1 == -e / d)
								fprintf(output, "(-oo,%.2f)v[%.2f,%.2f]\n", x1, x2, x3);
							if (x2 == -e / d)
								fprintf(output, "(-oo,%.2f]v(%.2f,%.2f]\n", x1, x2, x3);
							if (x3 == -e / d)
								fprintf(output, "(-oo,%.2f]v[%.2f,%.2f)\n", x1, x2, x3);
						}
					}
				}
			}
		}
	}
}
#include <iostream>
#include <cmath>
#include <iomanip>
#include "TapXacDinh.h"
#include "Equation.h"
#include "MinMax.h"
#define epsilon 1e-5
using namespace std;

void MinMax(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:
	{
		MinMax_1();
		break;
	}
	case 2:
	{
		MinMax_2(a, b, c);
		break;
	}
	case 3:
	{
		MinMax_3(a, b, c, d);
		break;
	}
	case 4:
	{
		MinMax_4(a, b, c);
		break;
	}
	case 5:
	{
		MinMax_5();
		break;
	}
	case 6:
	{
		MinMax_6(a, b, c, d, e);
		break;
	}
	default:
		break;
	}
}

void MinMax_1()
{
	cout << "Ham so khong co cuc tieu hay cuc dai !!!" << endl;
}

void MinMax_2(float a, float  b, float  c)
{
	if (a < 0)
	{
		cout << "Ham so khong co cuc tieu!!!" << endl;
		float x1 = (-b) / (2 * a);
		float MAX = a * pow(x1, 2) + b * x1 + c;
		cout << "Ham so co cuc dai la: (" << setprecision(10) << x1 << " , " << setprecision(10) << MAX << ")" << endl;
	}
	else if (a > 0)
	{
		float x1 = (-b) / (2 * a);
		float MIN = a * pow(x1, 2) + b * x1 + c;
		cout << "Ham so co cuc tieu la: (" << setprecision(10) << x1 << " , " << setprecision(10) << MIN << ")" << endl;
		cout << "Ham so khong co cuc dai!!!" << endl;
	}
	else
	{
		MinMax_1();
	}
}

//void MinMax_3(float a, float b, float c, float d)
//{
//	if (a == 0)
//	{
//		MinMax_2(b, c, d);
//	}
//	else 
//	{
//		float a1 = 3 * a, b1 = 2 * b, c1 = c;
//		float delta = b1 * b1 - 4 * a1*c1;
//		if (fabs(delta) < epsilon)
//			delta = 0;
//		if (delta <= 0)
//		{
//			cout << "Ham so khong cuc dai va cuc tieu!!!" << endl;
//		}
//		else
//		{
//			float x = (-b1 + sqrt(delta)) / (2 * a1);
//			float y = (-b1 - sqrt(delta)) / (2 * a1);
//			float X1, X2;
//			float MAX, MIN;
//			if (a < 0)
//			{
//				if (x < y)
//				{
//					MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//					X1 = x;
//					MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
//					X2 = y;
//				}
//				else
//				{
//					MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//					X2 = x;
//					MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
//					X1 = y;
//				}
//			}
//			else
//			{
//				if (x < y)
//				{
//					float MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//					X1 = x;
//					float MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
//					X2 = y;
//				}
//				else
//				{
//					float MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//					X2 = x;
//					float MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
//					X1 = y;
//				}
//			}
//			cout << "Ham so co cuc tieu la: (" << setprecision(10) << X1 << " , " << setprecision(10) << MIN << ")" << endl;
//			cout << "Ham so cuc dai la: (" << setprecision(10) << X2 << " , " << setprecision(10) << MAX << ")" << endl;
//		}
//	}
//}

void MinMax_3(float a, float b, float c, float d)
{
	if (a == 0)
	{
		MinMax_2(b, c, d);
	}
	else
	{
		float a1 = 3 * a, b1 = 2 * b, c1 = c;
		float x, y;
		short z;
		GiaiPT_Bac2(a1, b1, c1, x, y, z);
		if (z == -1 || z == 0)
		{
			cout << "Ham so khong cuc dai va cuc tieu!!!" << endl;
		}
		else
		{
			float X1, X2;
			float MAX, MIN;
			if (a < 0)
			{
				if (x < y)
				{
					MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
					X1 = x;
					MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
					X2 = y;
				}
				else
				{
					MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
					X2 = x;
					MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
					X1 = y;
				}
			}
			else
			{
				if (x < y)
				{
					float MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
					X1 = x;
					float MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
					X2 = y;
				}
				else
				{
					float MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
					X2 = x;
					float MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
					X1 = y;
				}
			}
			cout << "Ham so co cuc tieu la: (" << setprecision(10) << X1 << " , " << setprecision(10) << MIN << ")" << endl;
			cout << "Ham so cuc dai la: (" << setprecision(10) << X2 << " , " << setprecision(10) << MAX << ")" << endl;
		}
	}
}

void MinMax_4(float a, float b, float c)
{
	if (a == 0)
	{
		MinMax_2(b, 0, c);
	}
	else
	{
		float MIN, MAX;
		float a1 = 4 * a, b1 = 2 * a;
		if (a > 0 && b >= 0)
		{
			cout << "Ham so co cuc tieu la: (" << 0 << " , " << setprecision(10) << c << ")" << endl;
			cout << "Ham so khong co cuc dai!!!" << endl;
		}
		else if (a < 0 && b <= 0)
		{
			cout << "Ham so khong co cuc tieu!!!" << endl;
			cout << "Ham so co cuc dai la: (" << 0 << " , " << setprecision(10) << c << ")" << endl;
		}
		else if (a > 0 && b < 0)
		{
			float delta;
			delta = b * b - 4 * a*c;
			printf("Ham so co 2 cuc tieu la: (%f , %f) va (%f , %f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
			printf("Ham so co 1 cuc dai la: (%f , %f)", 0, c);
		}
		else if (a < 0 && b > 0)
		{
			float delta;
			delta = b * b - 4 * a*c;
			printf("Ham so co 1 cuc tieu la: (%f , %f)", 0, c);
			printf("Ham so co 2 cuc dai la: (%f , %f) va (%f , %f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
		}
	}
}

void MinMax_5()
{
	cout << "Ham so khong co cuc tieu hay cuc dai !!!" << endl;
}

void MinMax_6(float a, float b, float c, float d, float e)
{
	if (a == 0)
		MinMax_5();
	else if (d == 0)
		MinMax_2(a / e, b / e, c / e);
	else if (a*pow(-e / d, 2) + b * (-e / d) + c == 0)
	{
		MinMax_1();
	}
	else
	{
		float a1 = a * d;
		float b1 = 2 * a*e;
		float c1 = b * e - c * d;
		float x, y;
		short z;
		GiaiPT_Bac2(a1, b1, c1, x, y, z);
		if (z == -1 || z == 0)
			cout << "Ham so khong co cuc tieu hay cuc dai !!!" << endl;
		else
		{
			if (Equa_2(a1, b1, c1, x - epsilon) > 0 && Equa_2(a1, b1, c1, x + epsilon) < 0)
			{
				cout << "Ham so co cuc tieu la: (" << setprecision(10) << x << " , " << setprecision(10) << Equa_6(a, b, c, d, e, x) << ")" << endl;
				cout << "Ham so co cuc dai la: (" << setprecision(10) << y << " , " << setprecision(10) << Equa_6(a, b, c, d, e, y) << ")" << endl;
			}
			else
			{
				cout << "Ham so co cuc tieu la: (" << setprecision(10) << y << " , " << setprecision(10) << Equa_6(a, b, c, d, e, y) << ")" << endl;
				cout << "Ham so co cuc dai la: (" << setprecision(10) << x << " , " << setprecision(10) << Equa_6(a, b, c, d, e, x) << ")" << endl;
			}
		}
	}
}

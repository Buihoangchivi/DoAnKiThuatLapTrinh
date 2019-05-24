#include <iostream>
#include <cmath>
#include "Input_Output.h"
#include "Equation.h"
#include "Daoham.h"
#define epsilon 1e-5

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
	default:
		break;
	}
}

void XetDau0(float a)
{
	if (a == 0) cout << "\tDao ham luon bang 0 voi moi x thuoc R" << endl;
	else if (a < 0) cout << "\tDao ham luon am voi moi x thuoc R" << endl;
	else cout << "\tDao ham luon duong voi moi x thuoc R" << endl;
}

void XetDau1(float a, float b)
{
	if (a > 0)
	{
		cout << "\tDao ham luon am voi x thuoc (-" << (char)236 << ", " << -b / a << ")" << endl;
		cout << "\tDao ham bang 0 voi x = " << -b / a << endl;
		cout << "\tDao ham luon duong voi x thuoc (" << -b / a << ", +" << (char)236 << ")" << endl;
	}
	else
	{
		cout << "\tDao ham luon duong voi x thuoc (-" << (char)236 << ", " << -b / a << ")" << endl;
		cout << "\tDao ham bang 0 voi x = " << -b / a << endl;
		cout << "\tDao ham luon am voi x thuoc (" << -b / a << ", -" << (char)236 << ")" << endl;
	}
}

void XetDau2(float a, float b, float c)
{
	float x, y;
	short t;
	GiaiPT_Bac2(a, b, c, x, y, t);
	if (t == -1)
	{
		if (a < 0) cout << "\tDao ham luon am voi moi x thuoc R" << endl;
		else cout << "\tDao ham luon duong voi moi x thuoc R" << endl;
	}
	else if (t == 0)
	{
		if (a < 0) cout << "\tDao ham luon am voi moi x thuoc R \\ {" << x << "}" << endl;
		else cout << "\tDao ham luon duong voi moi x thuoc R \\ {" << x << "}" << endl;
		cout << "Dao ham bang 0 tai x = " << x << endl;
	}
	else
	{
		if (a < 0)
		{
			cout << "\tDao ham luon am voi x thuoc (-" << (char)236 << ", " << x << ")" << " va x thuoc ("
				<< y << ", +" << (char)236 << ")" << endl;
			cout << "\tDao ham luon duong voi x thuoc (" << x << ", " << y << ")" << endl;
		}
		else
		{
			cout << "\tDao ham luon duong voi x thuoc (-" << (char)236 << ", " << x
				<< ") va x thuoc (" << y << ", +" << (char)236 << ")" << endl;
			cout << "\tDao ham luon am voi x thuoc (" << x << ", " << y << ")" << endl;
		}
		cout << "\tDao ham bang 0 tai x = " << x << " va x = " << y << endl;
	}
}

void XetDau3(float a, float b)
{
	if (a * b < 0)
	{
		float temp = sqrt(-b / a);
		if (a > 0)
		{
			cout << "\tDao ham luon am voi x thuoc (-" << (char)236 << ", " << -temp
				<< ") va x thuoc (0, " << temp << endl;
			cout << "\tDao ham luon duong voi x thuoc (" << -temp
				<< ", 0) va x thuoc (" << temp << ", +" << (char)236 << ")" << endl;
		}
		else
		{
			cout << "\tDao ham luon duong voi x thuoc (-" << (char)236 << ", " << -temp
				<< ") va x thuoc (0, " << temp << ")" << endl;
			cout << "\tDao ham luon am voi x thuoc (" << -temp
				<< ", 0) va x thuoc (" << temp << ", +" << (char)236 << ")" << endl;
		}
		cout << "\tDao ham bang 0 tai x = 0,  x = " << -temp << " va x = " << temp << endl;
	}
	else
	{
		if (a > 0)
		{
			cout << "\tDao ham luon am voi x thuoc (-" << (char)236 << ", 0)" << endl;
			cout << "\tDao ham bang 0 voi x = 0" << endl;
			cout << "\tDao ham luon duong voi x thuoc (0, +" << (char)236 << ")" << endl;
		}
		else
		{
			cout << "\tDao ham luon duong voi x thuoc (-" << (char)236 << ", 0)" << endl;
			cout << "\tDao ham bang 0 voi x = 0" << endl;
			cout << "\tDao ham luon am voi x thuoc (0, +" << (char)236 << ")" << endl;
		}
	}
}

void XetDau4(float a, float c, float d)
{
	if (a < epsilon) cout << "\tDao ham luon bang 0 voi moi x thuoc R" << endl;
	else if (a > 0) cout << "\tDao ham luon duong voi moi x thuoc R \\ {" << -d / c << "}" << endl;
	else cout << "\tDao ham luon am voi moi x thuoc R \\ {" << -d / c << "}" << endl;
	cout << "\tDao ham tien toi " << (char)236 << " khi x = " << -d / c << endl;
}

void DaoHam1(float a, float b)
{
	cout << "Ham so dao ham co dang: y' = " << a << endl;
	cout << "Xet dau dao ham y':" << endl;
	XetDau0(a);
}

void DaoHam2(float a, float b, float c)
{
	cout << "Ham so dao ham co dang: y' = ";
	PT_1(2 * a, b);
	cout << endl;
	cout << "Xet dau dao ham y':" << endl;
	XetDau1(2 * a, b);
}

void DaoHam3(float a, float b, float c, float d)
{
	cout << "Ham so dao ham co dang: y' = ";
	PT_2(3 * a, 2 * b, c);
	cout << endl;
	cout << "Xet dau dao ham y':" << endl;
	XetDau2(3 * a, 2 * b, c);
}

void DaoHam4(float a, float b, float c)
{
	cout << "Ham so dao ham co dang: y' = ";
	PT_3(4 * a, 0, 2 * b, 0);
	cout << endl;
	cout << "Xet dau dao ham y':" << endl;
	XetDau3(4 * a, 2 * b);
}

void DH_4(float a, float b, float c, float d)
{
	if (fabs(a * d - b * c) < epsilon) cout << "0" << endl;
	else
	{
		cout << a * d - b * c << " / ";
		if (2 * c * d != 0 || d * d != 0) cout << "(";
		PT_2(c * c, 2 * c * d, d * d);
		if (2 * c * d != 0 || d * d != 0) cout << ")";
	}
}

void DaoHam5(float a, float b, float c, float d)
{
	cout << "Ham so dao ham co dang: y' = ";
	DH_4(a, b, c, d);
	cout << endl;
	cout << "Xet dau dao ham y':" << endl;
	XetDau4(a * d - b * c, c, d);
}

void DH_5(float a, float b, float c, float d, float e)
{
	float a1 = a * d, b1 = 2 * a * e, c1 = b * e - c * d;
	if (b1 != 0 || c1 != 0) cout << "(";
	PT_2(a * d, 2 * a * e, b * e - c * d);
	if (b1 != 0 || c1 != 0) cout << ")";
	cout << " / ";
	if (2 * d * e != 0 || e * e != 0) cout << "(";
	PT_2(d * d, 2 * d * e, e * e);
	if (2 * d * e != 0 || e * e != 0) cout << ")";
}

void DaoHam6(float a, float b, float c, float d, float e)
{
	cout << "Ham so dao ham co dang: y' = ";
	DH_5(a, b, c, d, e);
	cout << endl;
	cout << "Xet dau dao ham y':" << endl;
	XetDau2(a * d, 2 * a * e, b * e - c * d);
}


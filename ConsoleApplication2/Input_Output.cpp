#include "Input_Output.h"
#include "TapXacDinh.h"
#include <iostream>

using namespace std;

template<class T>
void Input(char ch, T &k)
{
	cout << ch << " = ";
	cin >> k;
}

void Input_Equation(int &k)
{
	cout << "Chon Ham so ax + b = 0                    : Nhap 1" << endl;
	cout << "Chon Ham so ax^2 + bx + c = 0             : Nhap 2" << endl;
	cout << "Chon Ham so ax^3 + bx^2 + cx + d = 0      : Nhap 3" << endl;
	cout << "Chon Ham so ax^4 + bx^2 + c = 0           : Nhap 4" << endl;
	cout << "Chon Ham so (ax + b) / (cx + d) = 0       : Nhap 5" << endl;
	cout << "Chon Ham so (ax^2 + bx + c) / (dx + e) = 0: Nhap 6" << endl;
	cout << "Nhap vao 1 so N: ";
	Input('N', k);
}

void Output_Equation(int k, float &a, float &b, float &c, float &d, float &e)
{
	switch (k)
	{
	case 1:
		Input('a', a);
		Input('b', b);
		cout << "Ham so co dang: y = ";
		PT_1(a, b);
		cout << endl;
		break;
	case 2:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		cout << "Ham so co dang: y = ";
		PT_2(a, b, c);
		cout << endl;
		break;
	case 3:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		cout << "Ham so co dang: y = ";
		PT_3(a, b, c, d);
		break;
	case 4:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		cout << "Ham so co dang: y = ";
		PT_4(a, b, c);
		break;
	case 5:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		if (c == 0 && d == 0)
		{
			cout << "Ham so khong hop le vi mau so bang 0!!!" << endl;
			exit(0);
		}
		if (a == 0 && b == 0)
		{
			cout << "0" << endl;
			return;
		}
		cout << "Ham so co dang: y = ";
		PT_5(a, b, c, d);
		break;
	case 6:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		Input('e', e);
		if (d == 0 && e == 0)
		{
			cout << "Ham so khong hop le vi mau so bang 0!!!" << endl;
			exit(0);
		}
		if (a == 0 && b == 0 && c == 0)
		{
			cout << "0" << endl;
			return;
		}
		cout << "Ham so co dang: y = ";
		PT_6(a, b, c, d, e);
		break;
	default:
		cout << "Du lieu ban nhap vao khong hop le!!!" << endl;
		break;
	}
}

void PT_1(float a, float b)
{
	if (a != 0)
	{
		if (a == 1) cout << "x";
		else if (a == -1) cout << "-x";
		else cout << a << "x";
	}
	if (a == 0) cout << b;
	else
	{
		if (b > 0) cout << " + " << b;
		else if (b < 0) cout << " - " << -b;
	}
}

void PT_2(float a, float b, float c)
{
	if (a == 0)
	{
		PT_1(b, c);
		return;
	}
	if (a == 1) cout << "x^2";
	else if (a == -1) cout << "-x^2";
	else cout << a << "x^2";
	if (b != 0)
	{
		if (b == 1) cout << " + x";
		else if (b == -1) cout << " - x";
		else if (b > 0) cout << " + " << b << "x";
		else if (b < 0) cout << " - " << -b << "x";
	}
	if (c != 0)
	{
		if (c > 0) cout << " + " << c;
		else if (c < 0) cout << " - " << -c;
	}
}

void PT_3(float a, float b, float c, float d)
{
	if (a == 0)
	{
		PT_2(b, c, d);
		return;
	}
	if (a == 1) cout << "x^3";
	else if (a == -1) cout << "-x^3";
	else cout << a << "x^3";
	if (b != 0)
	if (b == 1) cout << " + x^2";
	else if (b == -1) cout << " - x^2";
	else if (b > 0) cout << " + " << b << "x^2";
	else if (b < 0) cout << " - " << -b << "x^2";
	if (c != 0)
	if (c == 1) cout << " + x";
	else if (c == -1) cout << " - x";
	else if (c > 0) cout << " + " << c << "x";
	else if (c < 0) cout << " - " << -c << "x";
	if (d != 0)
	{
		if (d > 0) cout << " + " << d << endl;
		else if (d < 0) cout << " - " << -d << endl;
	}
	else cout << endl;
}

void PT_4(float a, float b, float c)
{
	if (a == 0)
	{
		PT_2(b, 0, c);
		return;
	}
	if (a == 1) cout << "x^4";
	else if (a == -1) cout << "-x^4";
	else cout << a << "x^4";
	if (b != 0)
	if (b == 1) cout << " + x^2";
	else if (b == -1) cout << " - x^2";
	else if (b > 0) cout << " + " << b << "x^2";
	else if (b < 0) cout << " - " << -b << "x^2";
	if (c != 0)
	{
		if (c > 0) cout << " + " << c << endl;
		else if (c < 0) cout << " - " << -c << endl;
	}
	else cout << endl;
}

void PT_5(float a, float b, float c, float d)
{
	if (a != 0 && b != 0) cout << "(";
	PT_1(a, b);
	if (a != 0 && b != 0) cout << ")";
	cout << " / ";
	if (c != 0 && d != 0) cout << "(";
	PT_1(c, d);
	if (c != 0 && d != 0) cout << ")";
	cout << endl;
}

void PT_6(float a, float b, float c, float d, float e)
{
	if (a == 0)
	{
		PT_5(b, c, d, e);
		return;
	}
	if (b != 0 || c != 0) cout << "(";
	PT_2(a, b, c);
	if (b != 0 || c != 0) cout << ")";
	cout << " / ";
	if (d != 0 && e != 0) cout << "(";
	PT_1(d, e);
	if (d != 0 && e != 0) cout << ")";
	cout << endl;
}


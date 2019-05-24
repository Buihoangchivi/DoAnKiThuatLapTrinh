#define _CRT_NONSTDC_NO_WARNINGS
#include "GioiHan.h"
#include "Equation.h"
#include "Input_Output.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define epsilon 1e-5

#define MAX 256

using namespace std;


void GioiHan(int k, float a, float b, float c, float d, float e)
{
	int select;
	Choice(select);
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
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_1(a, b); cout << ") = -" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_1(a, b); cout << ") = +" << char(236) << endl;
		}
		else
		{
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_1(a, b); cout << ") = " << b << endl;
		}
		break;
	case 2:
		if (a < 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_1(a, b); cout << ") = +" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_1(a, b); cout << ") = -" << char(236) << endl;
		}
		else
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_1(a, b); cout << ") = " << b << endl;
		}
		break;
	case 3:
		float x0;
		cout << "Nhap x0 = "; cin >> x0;
		cout << "\tKhi x -> " << x0 << "  lim("; PT_1(a, b); cout << ") = " << Equa_1(a, b, x0) << endl;
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
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_2(a, b, c); cout << ") = -" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_2(a, b, c); cout << ") = +" << char(236) << endl;
		}
		else
			GioiHan1(b, c, 1);
		break;
	case 2:
		if (a < 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_2(a, b, c); cout << ") = -" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_2(a, b, c); cout << ") = +" << char(236) << endl;
		}
		else
			GioiHan1(b, c, 2);
		break;
	case 3:
		float x0;
		cout << "Nhap x0 = "; cin >> x0;
		cout << "\tKhi x -> " << x0 << "  lim("; PT_2(a, b, c); cout << ") =  " << Equa_2(a, b, c, x0) << endl;
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
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_3(a, b, c, d); cout << ") = -" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_3(a, b, c, d); cout << ") = +" << char(236) << endl;
		}
		else GioiHan2(b, c, d, 1);
		break;
	case 2:
		if (a < 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_3(a, b, c, d); cout << ") = +" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_3(a, b, c, d); cout << ") = -" << char(236) << endl;
		}
		else GioiHan2(b, c, d, 2);
		break;
	case 3:
		float x0;
		cout << "Nhap x0 = "; cin >> x0;
		cout << "\tKhi x -> " << x0 << "  lim("; PT_3(a, b, c, d); cout << ") =  " << Equa_3(a, b, c, d, x0) << endl;
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
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_4(a, b, c); cout << ") = -" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_4(a, b, c); cout << ") = +" << char(236) << endl;
		}
		else GioiHan2(b, 0, c, 1);
		break;
	case 2:
		if (a < 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_4(a, b, c); cout << ") = -" << char(236) << endl;
		}
		else if (a > 0)
		{
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_4(a, b, c); cout << ") = +" << char(236) << endl;
		}
		else GioiHan2(b, 0, c, 2);
		break;
	case 3:
		float x0;
		cout << "Nhap x0 = "; cin >> x0;
		cout << "\tKhi x -> " << x0 << "  lim("; PT_4(a, b, c); cout << ") =  " << Equa_4(a, b, c, x0) << endl;
		break;
	default:
		break;
	}
}

void GioiHan5(float a, float b, float c, float d, int select)
{
	if (c == 0) GioiHan1(a / d, b / d, select);
	else if (a == 0)
	if (b == 0) cout << "Ham so la ham hang co gia tri 0, lim luon = 0!!!" << endl;
	else
		switch (select)
	{
		case 1:
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_5(a, b, c, d); cout << ") = 0 " << endl;
			break;
		case 2:
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_5(a, b, c, d); cout << ") = 0 " << endl;
			break;
		case 3:
			float x0;
			cout << "Nhap x0 = "; cin >> x0;
			if (x0 != -d / c)
			{
				cout << "\tKhi x -> " << x0 << "  lim("; PT_5(a, b, c, d); cout << ") = " << Equa_5(a, b, c, d, x0) << endl;
			}
			else
			{
				cout << "\tKhi x -> " << x0 << "  lim("; PT_5(a, b, c, d); cout << ") = " << char(236) << endl;
			}
			break;
		default:
			break;
	}
	else
		switch (select)
	{
		case 1:
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_5(a, b, c, d); cout << ") = " << a / c << endl;
			break;
		case 2:
			cout << "\tKhi x -> -" << char(236) << "  lim("; PT_5(a, b, c, d); cout << ") = " << a / c << endl;
			break;
		case 3:
			float x0;
			cout << "Nhap x0 = "; cin >> x0;
			if (x0 != -d / c)
			{
				cout << "\tKhi x -> " << x0 << "  lim("; PT_5(a, b, c, d); cout << ") = " << Equa_5(a, b, c, d, x0) << endl;
			}
			else 
			{
				cout << "\tKhi x -> " << x0 << "  lim("; PT_5(a, b, c, d); cout << ") = " << char(236) << endl;
			}
			else cout << "Ham so la ham hang co gia tri " << a / c << ", lim luon = " << a / c << "!!!" << endl;
			break;
		default:
			break;
	}
}

void GioiHan6(float a, float b, float c, float d, float e, int select)
{
	if (a == 0) GioiHan5(b, c, d, e, select);
	else if (d == 0) GioiHan2(a / e, b / e, c / e, select);
	else
	{
		float x, y;
		short k;
		GiaiPT_Bac2(a, b, c, x, y, k);
		if (k != -1)
		{
			if (k == 0) y = x;
			if (x + e / d < epsilon)
			{
				GioiHan1(a/d, -a*y/d, select);
				return;
			}
			if (y + e / d < epsilon)
			{
				GioiHan1(a/d, -a*x/d, select);
				return;
			}
		}
		switch (select)
		{
		case 1:
			if (a*d > 0)
			{
				cout << "\tKhi x -> +" << char(236) << "  lim("; PT_6(a, b, c, d, e); cout << ") = +" << char(236) << endl;
			}
			else
			{
				cout << "\tKhi x -> +" << char(236) << "  lim("; PT_6(a, b, c, d, e); cout << ") = -" << char(236) << endl;
			}
			break;
		case 2:
			if (a*d < 0)
			{
				cout << "\tKhi x -> -" << char(236) << "  lim("; PT_6(a, b, c, d, e); cout << ") = +" << char(236) << endl;
			}
			else
			{
				cout << "\tKhi x -> -" << char(236) << "  lim("; PT_6(a, b, c, d, e); cout << ") = -" << char(236) << endl;
			}
			break;
		case 3:
			float x0;
			cout << "Nhap x0 = "; cin >> x0;
			if (x0 != -e / d)
			{
				cout << "\tKhi x -> " << x0 << "  lim("; PT_6(a, b, c, d, e); cout << ") = " << Equa_6(a, b, c, d, e, x0) << endl;
			}
			else 
			{
				cout << "\tKhi x -> " << x0 << "  lim("; PT_6(a, b, c, d, e); cout << ") = " << char(236) << endl;
			}
			break;
		default:
			break;
		}
	}
}

void Choice(int& select)
{
	cout << "**Ban muon tim gioi han cua ham so \tKhi x -> " << endl;
	cout << "- Nhan 1 de tim gioi han \tKhi x -> +" << (char)236 << endl;
	cout << "- Nhan 2 de tim gioi han \tKhi x -> -" << (char)236 << endl;
	cout << "- Nhan 3 de tim gioi han \tKhi x -> x0" << endl;
	cout << "Nhap lua chon cua ban: "; cin >> select;
	while (select < 1 || select > 3)
	{
		cout << "Nhap lai lua chon cua ban: "; cin >> select;
	}
}

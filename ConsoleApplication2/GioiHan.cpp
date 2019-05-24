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
}

void GioiHan6(float a, float b, float c, float d, float e, int select)
{
	switch (select)
	{
	case 1:
		if (a * d > 0)
		{
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_6(a, b, c, d, e); cout << ") = +" << char(236) << endl;
		}
		else
		{
			cout << "\tKhi x -> +" << char(236) << "  lim("; PT_6(a, b, c, d, e); cout << ") = -" << char(236) << endl;
		}
		break;
	case 2:
		if (a * d < 0)
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

void Choice_And_Lim(int k, float a, float b, float c, float d, float e)
{
	cout << "**Ban muon tim gioi han cua ham so \tKhi x -> " << endl;
	cout << "- Nhan 1 de tim gioi han \tKhi x -> +" << (char)236 << endl;
	cout << "- Nhan 2 de tim gioi han \tKhi x -> -" << (char)236 << endl;
	cout << "- Nhan 3 de tim gioi han \tKhi x -> x0" << endl;
	int select;
	while (true)
	{
		cout << "Nhap lua chon cua ban: "; cin >> select;
		if (select == 0) return;
		while (select < 1 || select > 3)
		{
			cout << "\aDu lieu khong hop le!!! Moi ban nhap lai: "; cin >> select;
			if (select == 0) return;
		}
		GioiHan(k, a, b, c, d, e, select);
		cout << "\nBan co muon tiep tuc tim gioi han cua ham so khong?" << endl;
		cout << "Neu ban muon tim tiep: Nhap 1" << endl;
		cout << "Neu ban muon dung tim: Nhap cac gia tri khac 1" << endl;
		cout << "Nhap lua chon cua ban: "; cin >> select;
		if (select != 1) return;
		cout << endl;
	}
}

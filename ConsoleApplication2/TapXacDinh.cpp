#include "TapXacDinh.h"
#include "Equation.h"
#include <iostream>
#include <cmath>
#define esilon 1e-5

using namespace std;

void TapXacDinh(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:
		TapXacDinh_1();
		break;
	case 2:
		TapXacDinh_2();
		break;
	case 3:
		TapXacDinh_3();
		break;
	case 4:
		TapXacDinh_4();
		break;
	case 5:
		TapXacDinh_5(a, b, c, d);
		break;
	case 6:
		TapXacDinh_6(a, b, c, d, e);
		break;
	default:
		break;
	}
}

void TapXacDinh_1()
{
	cout << "Tap xac dinh cua phuong trinh la R" << endl;
}

void TapXacDinh_2()
{
	cout << "Tap xac dinh cua phuong trinh la R" << endl;
}

void TapXacDinh_3()
{
	cout << "Tap xac dinh cua phuong trinh la R" << endl;
}

void TapXacDinh_4()
{
	cout << "Tap xac dinh cua phuong trinh la R" << endl;
}

void TapXacDinh_5(float a, float b, float c, float d)
{
	if (fabs(c) <= esilon || fabs(Equa_1(a, b, -d / c)) <= esilon) cout << "Tap xac dinh cua phuong trinh la R" << endl;
	else if (d != 0) cout << "Tap xac dinh cua phuong trinh la R \\ {" << -d / c << "}" << endl;
	else cout << "Tap xac dinh cua phuong trinh la R \\ {0}" << endl;
}

void TapXacDinh_6(float a, float b, float c, float d, float e)
{
	if (fabs(d) <= esilon || fabs(Equa_2(a, b, c, -e / d)) <= esilon) cout << "Tap xac dinh cua phuong trinh la R" << endl;
	else if (e != 0) cout << "Tap xac dinh cua phuong trinh la R \\ {" << -e / d << "}" << endl;
	else cout << "Tap xac dinh cua phuong trinh la R \\ {0}" << endl;
}

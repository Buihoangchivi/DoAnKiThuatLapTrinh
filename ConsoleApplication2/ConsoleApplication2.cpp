// Text1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "Input_Output.h"
#include "TapXacDinh.h"
#include "Draw.h"
#include "Daoham.h"
#include "GioiHan.h"

using namespace std;

int _tmain(int argc, char* argv[])
{
	int k;
	float a, b, c, d, e;
	Input_Equation(k);
	Output_Equation(k, a, b, c, d, e);
	cout << endl;
	if (k<1 || k>6) return 0;
	TapXacDinh(k, a, b, c, d, e);
	cout << endl;
	DaoHam_XetDau(k, a, b, c, d, e);
	cout << endl;
	GioiHan(k, a, b, c, d, e);
	cout << endl;
	//Draw(argc, argv);
	return 0;
}


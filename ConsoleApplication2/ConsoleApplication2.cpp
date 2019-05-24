// Text1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
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
	while (true)
	{
		Input_Equation(k);
		if (k == 0) break;
		Output_Equation(k, a, b, c, d, e);
		if (k == 0) goto Next;
		cout << endl;
		TapXacDinh(k, a, b, c, d, e);
		cout << endl;
		DaoHam_XetDau(k, a, b, c, d, e);
		cout << endl;
		Choice_And_Lim(k, a, b, c, d, e);
		cout << endl;
		//Draw(argc, argv);
	Next:
		system("cls");
	}
	return 0;
}


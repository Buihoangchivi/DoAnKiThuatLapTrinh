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
#include "MinMax.h"
#define fi "Input.txt"
#define fo "Output.txt"
#define _CRT_NONSTDC_NO_WARNINGS

FILE* input, * output;

using namespace std;

void NhapCach_Input_Output()
{
	int a;
	cout << "Ban muon nhap du lieu tu dau?" << endl;
	cout << "\tNhap tu file:             Nhap 1" << endl;
	cout << "\tNhap tu man hinh console: Nhap 2" << endl;
	cout << "Ban hay nhap vao lua chon: ";
	cin >> a;
	while (a != 1 && a != 2)
	{
		cout << "\aLua chon ban nhap vao khong hop le!!!" << endl;
		cout << "Xin moi ban nhap lai lua chon: ";
		cin >> a;
	}
	if (a == 1)	input = fopen(fi, "rt");
	else input = stdin;
	system("cls");
	cout << "Ban muon xuat du lieu vao dau?" << endl;
	cout << "\tXuat ra file:             Nhap 1" << endl;
	cout << "\tXuat ra man hinh console: Nhap 2" << endl;
	cout << "Ban hay nhap vao lua chon: ";
	cin >> a;
	while (a != 1 && a != 2)
	{
		cout << "\n\aLua chon ban nhap vao khong hop le!!!" << endl;
		cout << "Xin moi ban nhap lai lua chon: ";
		cin >> a;
	}
	if (a == 1)	output = fopen(fo, "wt");
	else output = stdout;
	system("cls");
}

int _tmain(int argc, char* argv[])
{
	int k;
	float a, b, c, d, e;
	NhapCach_Input_Output();
	while (true)
	{
		if (input == stdin) Input_Equation_Console(k);
		else Input_Equation_File(k);
		if (k == 0) break;
		Output_Equation(k, a, b, c, d, e);
		if (k == 0) goto Next;
		fprintf(output, "\n");
		TapXacDinh(k, a, b, c, d, e);
		fprintf(output, "\n");
		DaoHam_XetDau(k, a, b, c, d, e);
		fprintf(output, "\n");
		Choice_And_Lim(k, a, b, c, d, e);
		fprintf(output, "\n");
		MinMax(k, a, b, c, d, e);
		if (output == stdout) system("pause");
		else fprintf(output, "\n\n");
		//Draw(argc, argv);
	Next:
		system("cls");
	}
	return 0;
}


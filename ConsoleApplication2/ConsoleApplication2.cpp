// Text1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "Input_Output.h"
#include "TapXacDinh.h"
#include "Draw.h"
#include "Daoham.h"
#include "GioiHan.h"
#include "MinMax.h"
#include "Bangbienthien.h"
#include "Intersection.h"
#define fi "Input.txt"
#define fo "Output.txt"
#define MAX 50

FILE * input, * output;

int arr_k[MAX];
float arr_a[MAX]; float arr_b[MAX]; float arr_c[MAX]; float arr_d[MAX]; float arr_e[MAX];
int NN;

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
	cout << "\tXuat ra file            : Nhap 1" << endl;
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
	NN = 0;
	float a, b, c, d, e;
	NhapCach_Input_Output();
	while (true)
	{
		if (input == stdin) Input_Equation_Console(k);
		else Input_Equation_File(k);	
		if (k == 0) break;
		Output_Equation(k, a, b, c, d, e);
		if (k == 0) goto Next;
		arr_k[NN] = k; arr_a[NN] = a; arr_b[NN] = b;
		arr_c[NN] = c; arr_d[NN] = d; arr_e[NN] = e;
		NN++;
		if (k <= 6 || k >= 11)
		{
			fprintf(output, "\n");
			TapXacDinh(k, a, b, c, d, e);
			fprintf(output, "\n");
			DaoHam_XetDau(k, a, b, c, d, e);
			fprintf(output, "\n");
			Choice_And_Lim(k, a, b, c, d, e);
			fprintf(output, "\n");
			MinMax(k, a, b, c, d, e);
			fprintf(output, "\n");
			BBT(k, a, b, c, d, e);
			fprintf(output, "\n");
		}
		if (output == stdout) system("pause");
		else fprintf(output, "\n\n");
	Next:
		system("cls");
	}
	if (NN >= 2)
	{
		fprintf(output, "* Tim giao diem cac ham so co ban:\n\n");
		for (int i = 0; i < NN - 1; i++)
			if (arr_k[i] < 7)
				for (int j = i + 1; j < NN; j++)
					if (arr_k[j] < 7)
					{
						fprintf(output, "\n- Hai ham so:\n\n\t");
						switch (arr_k[i])
						{
						case 1:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_1(arr_a[i], arr_b[i]);
							fprintf(output, "\n\n\t");
							break;
						case 2:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_2(arr_a[i], arr_b[i], arr_c[i]);
							fprintf(output, "\n\n\t");
							break;
						case 3:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_3(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
							fprintf(output, "\n\n\t");
							break;
						case 4:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_4(arr_a[i], arr_b[i], arr_c[i]);
							fprintf(output, "\n\n\t");
							break;
						case 5:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_5(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
							fprintf(output, "\n\n\t");
							break;
						case 6:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_6(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
							fprintf(output, "\n\n\t");
							break;
						}
						switch (arr_k[j])
						{
						case 1:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_1(arr_a[j], arr_b[j]);
							fprintf(output, "\n\n");
							break;
						case 2:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_2(arr_a[j], arr_b[j], arr_c[j]);
							fprintf(output, "\n\n");
							break;
						case 3:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_3(arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
							fprintf(output, "\n\n");
							break;
						case 4:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_4(arr_a[j], arr_b[j], arr_c[j]);
							fprintf(output, "\n\n");
							break;
						case 5:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_5(arr_a[j], arr_b[j], arr_c[j], arr_d[j]);
							fprintf(output, "\n\n");
							break;
						case 6:
							fprintf(output, "+ Ham so co dang: y = ");
							PT_6(arr_a[j], arr_b[j], arr_c[j], arr_d[j], arr_e[j]);
							fprintf(output, "\n\n");
							break;
						}
						Inter(arr_k[i], arr_k[j], i ,j);
					}
		if (output == stdout) system("pause");
	}
	Draw(argc, argv);
	return 0;
}


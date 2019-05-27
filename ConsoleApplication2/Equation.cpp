#include "Equation.h"
#include <iostream>
#include <cmath>
#define epsilon 1e-5
#define PI 3.14159265

using namespace std;

float Equa_1(float a, float b, float x)
{
	return a * x + b;
}

float Equa_2(float a, float b, float c, float x)
{
	return a * x * x + b * x + c;
}

float Equa_3(float a, float b, float c, float d, float x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

float Equa_4(float a, float b, float c, float x)
{
	return a * x * x * x * x + b * x * x + c;
}

float Equa_5(float a, float b, float c, float d, float x)
{
	return (a * x + b) / (c * x + d);
}

float Equa_6(float a, float b, float c, float d, float e, float x)
{
	return (a * x * x + b * x + c) / (d * x + e);
}

void Equa_7(float a, float b, float r, float x, float& y1, float& y2)
{
	y1 = -sqrt(r * r - (x - a) * (x - a));
	y2 = -y1;
}

void Equa_8(float a, float b, float x, float& y1, float& y2)
{
	y1 = -sqrt(b * b * (1 - x * x / (a * a)));
	y2 = -y1;
}

void Equa_9(float h, float k, float a, float b, float x, float &y1, float &y2)
{
	y1 = -sqrt(b * b * ((x - h) * (x - h) / (a * a) - 1)) + k;
	y2 = sqrt(b * b * ((x - h) * (x - h) / (a * a) - 1)) + k;
}

void Equa_10(float a, float b, float c, float d, float e, float x, float &y1, float &y2, short& k)
{
	GiaiPT_Bac2(b * b, 2 * a * b * x + d, a * a * x * x + c * x + e, y1, y2, k);
}

void GiaiPT_Bac2(float a, float b, float c, float& x, float& y, short& k)
{
	float delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		k = -1;
		return;
	}
	else if (fabs(delta) < epsilon)
	{
		k = 0;
		x = -b / (2 * a);
	}
	else
	{
		k = 1;
		x = (-b + sqrt(delta)) / (2 * a);
		y = (-b - sqrt(delta)) / (2 * a);
		if (x > y) swap(x, y);
	}
}

void GiaiPT_Bac3(float A, float B, float C, float D, float& X1, float& X2, float& X3, short& K)
{
	X1 = FLT_MIN, X2 = FLT_MIN, X3 = FLT_MIN;
	float delta = B * B - 3 * A * C;
	float Can2delta = pow(fabs(delta), 1.0 / 2);
	if (fabs(delta) < epsilon)
	{
		if (B * B * B - 27 * A * A * D == 0)
			X1 = (-B) / 3 * A;
		else
		{
			float temp = B * B * B - 27 * A * A * D;
			X1 = (-B + pow(temp, 1.0 / 3)) / (3 * A);
		}
		K = 1;
	}
	else if (delta < 0)
	{
		float k = (9 * A * B * C - 2 * pow(B, 3) - 27 * A * A * D) / (2 * pow(Can2delta, 3));
		float TEMP1 = pow(k * k + 1, 1.0 / 2);
		float TEMP2 = pow(k + pow(k * k + 1, 1.0 / 2), 1.0 / 3);
		float TEMP3;
		if (k - pow(k * k + 1, 1.0 / 2) < 0)
		{
			TEMP3 = pow(-(k - pow(k * k + 1, 1.0 / 2)), 1.0 / 3);
		}
		else
			TEMP3 = pow(k - pow(k * k + 1, 1.0 / 2), 1.0 / 3);
		X1 = Can2delta * (TEMP2 + TEMP3) / (3 * A) - B / (3 * A);
		K = 1;
	}
	else
	{
		float k = (9 * A * B * C - 2 * pow(B, 3) - 27 * A * A * D) / (2 * pow(Can2delta, 3));
		if (fabs(k) > 1)
		{
			float TEMP2 = pow(fabs(k) + pow(k * k - 1, 1.0 / 2), 1.0 / 3);
			float TEMP3 = pow(fabs(k) - pow(k * k - 1, 1.0 / 2), 1.0 / 3);
			X1 = Can2delta * fabs(k) * (TEMP2 + TEMP3) / (3 * A * k) - B / (3 * A);
			K = 1;
		}
		else
		{
			float arc = acos(k);
			X1 = (2 * Can2delta * cos(arc / 3) - B) / (3 * A);
			X2 = (2 * Can2delta * cos(arc / 3 - 2 * PI / 3) - B) / (3 * A);
			X3 = (2 * Can2delta * cos(arc / 3 + 2 * PI / 3) - B) / (3 * A);
			K = 3;
		}
	}
	if (K != 0)
		while (X1 == FLT_MIN)
		{
			if (K == 1)
				for (int i = 0; i < 3; i++)
				{
					swap(X1, X2);
					swap(X2, X3);
				}
			for (int i = 0; i < K; i++)
			{
				X1 = X2;
				X2 = X3;
				X3 = FLT_MIN;
			}
		}

	for (int i = 0; i < K; i++)
	{
		if (X1 > X2 && X2 != FLT_MIN)
			swap(X1, X2);
		if (X2 > X3 && X3 != FLT_MIN)
			swap(X2, X3);
	}
}

void GiaiPT_Bac4(float A, float B, float C, float D, float E, float& X1, float& X2, float& X3, float& X4, short& K)
{
	X1 = FLT_MIN, X2 = FLT_MIN, X3 = FLT_MIN, X4 = FLT_MIN;
	float A1 = A, B1 = B, C1 = C, D1 = D, E1 = E;
	if (A != 1)
	{
		A = 1;
		B = B / A;
		C = C / A;
		D = D / A;
		E = E / A;
	}
	C = (6 * B1 * B1 / 16 - 3 * B1 * B1 / 4 + C1);
	D = (-pow(B1, 3) * 4 / 64 + 3 * B1 * B1 * B1 / 16 - B1 * C1 / 2 + D1);
	E = pow(B1, 4) / 256 - pow(B1, 4) / 64 + B1 * B1 * C1 / 16 - B1 * D1 / 4 + E1;
	float M1, M2, M3;
	short K1;
	int count = 0;
	GiaiPT_Bac3(8, -4 * C, -8 * E, 4 * C * E - D * D, M1, M2, M3, K1);
	M1 = M3;
	if (2 * M1 - C > 0 && -(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C == 0)
	{
		X1 = (pow(2 * M1 - C, 1.0 / 2) + pow(-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
		X1 = X1 - B1 / 4;
		count++;
		X2 = (-pow(2 * M1 - C, 1.0 / 2) + pow((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
		X2 = X2 - B1 / 4;
		count++;
		K = count;
	}
	else
	{
		if (2 * M1 - C > 0 && -(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C > 0)
		{
			X1 = (pow(2 * M1 - C, 1.0 / 2) + pow(-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
			X1 = X1 - B1 / 4;
			count++;
		}
		if (2 * M1 - C > 0 && -(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C > 0)
		{
			X2 = (pow(2 * M1 - C, 1.0 / 2) - pow(-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
			X2 = X2 - B1 / 4;
			count++;
		}
		if (2 * M1 - C > 0 && (2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C > 0)
		{
			X3 = (-pow(2 * M1 - C, 1.0 / 2) + pow((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
			X3 = X3 - B1 / 4;
			count++;
		}
		if (2 * M1 - C > 0 && (2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C > 0)
		{
			X4 = (-pow(2 * M1 - C, 1.0 / 2) - pow((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
			X4 = X4 - B1 / 4;
			count++;
		}
		K = count;
	}
	if (K != 0)
		while (X1 == FLT_MIN)
		{
			if (K == 1)
			{
				for (int i = 0; i < 3; i++)
				{
					swap(X1, X2);
					swap(X2, X3);
				}
			}
			for (int i = 0; i < K; i++)
			{
				X1 = X2;
				X2 = X3;
				X3 = X4;
				X4 = FLT_MIN;
			}
		}

	for (int i = 0; i < count; i++)
	{
		if (X1 > X2 && X2 != FLT_MIN)
			swap(X1, X2);
		if (X2 > X3 && X3 != FLT_MIN)
			swap(X2, X3);
		if (X3 > X4 && X4 != FLT_MIN)
			swap(X3, X4);
	}
}

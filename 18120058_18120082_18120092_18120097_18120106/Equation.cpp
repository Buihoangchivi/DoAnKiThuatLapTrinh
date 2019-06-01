#include "Equation.h"
#include <iostream>
#include <cmath>
#define epsilon 1e-5
#define PI 3.14159265

using namespace std;

int count1 = 0;
int count2 = 0;

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
	y1 = -sqrt(r * r - (x - a) * (x - a)) + b;
	y2 = sqrt(r * r - (x - a) * (x - a)) + b;
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
			if (temp < 0)
			{
				X1 = (-B - pow(-temp, 1.0 / 3)) / (3 * A);
			}
			else
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
			TEMP3 = -TEMP3;
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
	/*if (A < 0)
	{
		A = -A;
		B = -B;
		C = -C;
		D = -D;
		E = -E;
	}*/
	K = 0;
	X1 = FLT_MIN, X2 = FLT_MIN, X3 = FLT_MIN, X4 = FLT_MIN;
	float A1 = A, B1 = B, C1 = C, D1 = D, E1 = E;
	int count = 0;
	if (E == 0)
	{
		float N1, N2, N3;
		short KK;
		X1 = 0;
		count++;
		GiaiPT_Bac3(A, B, C, D, X2, X3, X4, KK);
		if (X2 != FLT_MIN)
			count++;
		if (X3 != FLT_MIN)
			count++;
		if (X4 != FLT_MIN)
			count++;
		K = count;
	}
	else if (B == 0 && D == 0)
	{
		float x, y;
		short k;
		GiaiPT_Bac2(A, C, E, x, y, k);
		if (k == 0)
		{
			if (x > 0)
			{
				count = 2;
				X1 = -pow(x, 1.0 / 2);
				X2 = pow(x, 1.0 / 2);
			}
			K = count;
		}
		else if (k == 1)
		{
			if (x > 0)
			{
				count += 2;
				X1 = -pow(x, 1.0 / 2);
				X2 = pow(x, 1.0 / 2);
			}
			if (y > 0)
			{
				count += 2;
				X3 = pow(y, 1.0 / 2);
				X4 = -pow(y, 1.0 / 2);
			}
			K = count;
		}
	}
	else
	{
		if (A != 1)
		{
			B = B / A;
			C = C / A;
			D = D / A;
			E = E / A;
			A = 1;
		}
		float A2 = A, B2 = B, C2 = C, D2 = D, E2 = E;
		C = (6 * B2 * B2 / 16 - 3 * B2 * B2 / 4 + C2);
		D = (-pow(B2, 3) * 4 / 64 + 3 * B2 * B2 * B2 / 16 - B2 * C2 / 2 + D2);
		E = pow(B2, 4) / 256 - pow(B2, 4) / 64 + B2 * B2 * C2 / 16 - B2 * D2 / 4 + E2;
		float M1, M2, M3;
		short K1;
		GiaiPT_Bac3(8, -4 * C, -8 * E, 4 * C * E - D * D, M1, M2, M3, K1);
		if (K1 == 3)
			M1 = M3;
		else if (K1 == 2)
			M1 = M2;
		if (2 * M1 - C > 0 && (-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C) == 0)
		{
			X1 = (pow(2 * M1 - C, 1.0 / 2) + pow(-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
			X1 = X1 - B2 / 4;
			count++;
			X2 = (-pow(2 * M1 - C, 1.0 / 2) + pow((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
			X2 = X2 - B2 / 4;
			count++;
			K = count;
		}
		if (2 * M1 - C == 0)
		{
			X1 = pow(-M1, 1.0 / 2);
			X2 = -pow(-M1, 1.0 / 2);
			K = 2;
			count = 2;
		}
		else
		{
			if (2 * M1 - C > 0 && (-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C) > 0)
			{
				X1 = (pow(2 * M1 - C, 1.0 / 2) + pow(-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
				X1 = X1 - B2 / 4;
				count++;
			}
			if (2 * M1 - C > 0 && (-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C) > 0)
			{
				X2 = (pow(2 * M1 - C, 1.0 / 2) - pow(-(2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
				X2 = X2 - B2 / 4;
				count++;
			}
			if (2 * M1 - C > 0 && ((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C) > 0)
			{
				X3 = (-pow(2 * M1 - C, 1.0 / 2) + pow((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
				X3 = X3 - B2 / 4;
				count++;
			}
			if (2 * M1 - C > 0 && ((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C) > 0)
			{
				X4 = (-pow(2 * M1 - C, 1.0 / 2) - pow((2 * D) / pow(2 * M1 - C, 1.0 / 2) - 2 * M1 - C, 1.0 / 2)) / 2;
				X4 = X4 - B2 / 4;
				count++;
			}
			K = count;
		}
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

// Tính giá trị biểu thức bậc 4 đủ
float Equa_4s(float a, float b, float c, float d, float e, float x)
{
	return a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e;
}
// Tính giá trị biểu thức bậc 5 đủ
float Equa_5s(float a, float b, float c, float d, float e, float f, float x)
{
	return a * pow(x, 5) + b * pow(x, 4) + c * pow(x, 3) + d * pow(x, 2) + e * x + f;
}

// Hàm tìm nghiệm bậc 5 của pt đồng biến
float FindSolution5_1(float a, float b, float c, float d, float e, float f, float start, float end)
{
	if (start <= end)
	{
		float mid = start + (end - start) / 2;
		if (fabs(Equa_5s(a, b, c, d, e, f, mid)) < 1e-2)
			return mid;
		if (count1 == 500)
		{
			return FLT_MIN;
		}
		if (Equa_5s(a, b, c, d, e, f, mid) > 0)
		{
			count1++;
			return FindSolution5_1(a, b, c, d, e, f, start, mid);
		}
		count1++;
		return FindSolution5_1(a, b, c, d, e, f, mid, end);
	}
	return FLT_MIN;
}

// Hàm tìm nghiệm bậc 5 của pt nghịch biến
float FindSolution5_2(float a, float b, float c, float d, float e, float f, float start, float end)
{
	if (start <= end)
	{
		float mid = start + (end - start) / 2;
		if (fabs(Equa_5s(a, b, c, d, e, f, mid)) < 1e-2)
			return mid;
		if (count2 == 500)
		{
			return FLT_MIN;
		}
		if (Equa_5s(a, b, c, d, e, f, mid) < 0)
		{
			count2++;
			return FindSolution5_2(a, b, c, d, e, f, start, mid);
		}
		count2++;
		return FindSolution5_2(a, b, c, d, e, f, mid, end);
	}
	return FLT_MIN;
}

void GiaiPT_Bac5(float a, float b, float c, float d, float e, float f, float& x1, float& x2, float& x3, float& x4, float& x5, short& k)
{
	k = 0;
	float start = -100, end = 100;
	int count = 0;
	float A = 5 * a, B = 4 * b, C = 3 * c, D = 2 * d, E = e;
	float X, Y, Z, T;
	short K;
	x1 = FLT_MIN, x2 = FLT_MIN, x3 = FLT_MIN, x4 = FLT_MIN, x5 = FLT_MIN;
	float Fx1 = FLT_MIN, Fx2 = FLT_MIN, Fx3 = FLT_MIN, Fx4 = FLT_MIN;
	GiaiPT_Bac4(A, B, C, D, E, X, Y, Z, T, K);
	if (K == 0)
	{
		if (Equa_4s(A, B, C, D, E, 0) > 0)
			FindSolution5_1(a, b, c, d, e, f, start, end);
		else
			FindSolution5_2(a, b, c, d, e, f, start, end);
		count1 = 0;
		count2 = 0;
	}
	else if (K > 0)
	{
		Fx1 = Equa_5s(a, b, c, d, e, f, X);
		count++;
		if (Equa_4s(A, B, C, D, E, X + epsilon) * Equa_4s(A, B, C, D, E, X - epsilon) < 0)
		{
			if (Equa_4s(A, B, C, D, E, X - epsilon) > 0)
			{
				if (FindSolution5_1(a, b, c, d, e, f, start, X) != FLT_MIN)
				{
					x1 = FindSolution5_1(a, b, c, d, e, f, start, X);
					k++;
				}
			}
			else if (Equa_4s(A, B, C, D, E, X - epsilon) < 0)
			{
				if (FindSolution5_2(a, b, c, d, e, f, start, X) != FLT_MIN)
				{
					x1 = FindSolution5_2(a, b, c, d, e, f, start, X);
					k++;
				}

			}
		}
		count1 = 0;
		count2 = 0;
	}

	if (K > 1)
	{
		Fx2 = Equa_5s(a, b, c, d, e, f, Y);
		count++;
		if (Equa_4s(A, B, C, D, E, Y + epsilon) * Equa_4s(A, B, C, D, E, Y - epsilon) < 0)
		{
			if (Equa_4s(A, B, C, D, E, Y - epsilon) > 0)
			{
				if (FindSolution5_1(a, b, c, d, e, f, X, Y) != FLT_MIN)
				{
					x2 = FindSolution5_1(a, b, c, d, e, f, X, Y);
					k++;
				}
			}
			else if (Equa_4s(A, B, C, D, E, Y - epsilon) < 0)
			{
				if (FindSolution5_2(a, b, c, d, e, f, X, Y) != FLT_MIN)
				{
					x2 = FindSolution5_2(a, b, c, d, e, f, X, Y);
					k++;
				}

			}
		}
		count1 = 0;
		count2 = 0;
		if (k == 2)
		{
			count++;
			if (Equa_4s(A, B, C, D, E, Y + epsilon) > 0)
			{
				x3 = FindSolution5_1(a, b, c, d, e, f, Y, end);
				k++;
			}
			else if (Equa_4s(A, B, C, D, E, Y + epsilon) < 0)
			{
				x3 = FindSolution5_2(a, b, c, d, e, f, Y, end);
				k++;
			}
			count1 = 0;
			count2 = 0;
			return;
		}
	}
	if (K > 2)
	{

		Fx3 = Equa_5s(a, b, c, d, e, f, Z);
		count++;
		if (Equa_4s(A, B, C, D, E, Z + epsilon) * Equa_4s(A, B, C, D, E, Z - epsilon) < 0)
		{
			if (Equa_4s(A, B, C, D, E, Z - epsilon) > 0)
			{
				if (FindSolution5_1(a, b, c, d, e, f, Y, Z) != FLT_MIN)
				{
					x3 = FindSolution5_1(a, b, c, d, e, f, Y, Z);
					k++;
				}
			}
			else if (Equa_4s(A, B, C, D, E, Z - epsilon) < 0)
			{
				if (FindSolution5_2(a, b, c, d, e, f, Y, Z) != FLT_MIN)
				{
					x3 = FindSolution5_2(a, b, c, d, e, f, Y, Z);
					k++;
				}
			}
		}
		count1 = 0;
		count2 = 0;
		if (K == 3)
		{
			count++;
			if (Equa_4s(A, B, C, D, E, Z + epsilon) > 0)
			{
				x4 = FindSolution5_1(a, b, c, d, e, f, Z, end);
				k++;
			}
			else if (Equa_4s(A, B, C, D, E, Z + epsilon) < 0)
			{
				x4 = FindSolution5_2(a, b, c, d, e, f, Z, end);
				k++;
			}
			count1 = 0;
			count2 = 0;
			return;
		}
	}
	if (K > 3)
	{
		Fx4 = Equa_5s(a, b, c, d, e, f, T);
		count++;
		if (Equa_4s(A, B, C, D, E, T + epsilon) * Equa_4s(A, B, C, D, E, T - epsilon) < 0)
		{
			if (Equa_4s(A, B, C, D, E, T - epsilon) > 0)
			{
				if (FindSolution5_1(a, b, c, d, e, f, Z, T) != FLT_MIN)
				{
					x4 = FindSolution5_1(a, b, c, d, e, f, Z, T);
					k++;
				}
			}
			else if (Equa_4s(A, B, C, D, E, T - epsilon) < 0)
			{
				//if (FindSolution5_2(a, b, c, d, e, f, Z, T) != FLT_MIN)
				if (FindSolution5_2(a, b, c, d, e, f, Z, T) != FLT_MIN)
				{
					x4 = FindSolution5_2(a, b, c, d, e, f, Z, T);
					k++;
				}

			}
		}
		count1 = 0;
		count2 = 0;
	}
	if (Equa_4s(A, B, C, D, E, T + epsilon) > 0)
	{
		x5 = FindSolution5_1(a, b, c, d, e, f, T, end);
		k++;
	}
	else if (Equa_4s(A, B, C, D, E, T + epsilon) < 0)
	{
		x5 = FindSolution5_2(a, b, c, d, e, f, T, end);
		k++;
	}
	count1 = 0;
	count2 = 0;
	if (k != 0)
		while (x1 == FLT_MIN)
		{
			if (k == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					swap(x1, x2);
					swap(x2, x3);
					swap(x3, x4);
				}
			}
			for (int i = 0; i < K; i++)
			{
				x1 = x2;
				x2 = x3;
				x3 = x4;
				x4 = x5;
				x5 = FLT_MIN;
			}
		}
	for (int i = 0; i < k; i++)
		for (int j = i + 1; j < k; j++)
		{
			if (x1 == FLT_MIN && x2 != FLT_MIN)
				swap(x1, x2);
			if (x2 == FLT_MIN && x3 != FLT_MIN)
				swap(x2, x3);
			if (x3 == FLT_MIN && x4 != FLT_MIN)
				swap(x3, x4);
			if (x4 == FLT_MIN && x5 != FLT_MIN)
				swap(x4, x5);
		}
}

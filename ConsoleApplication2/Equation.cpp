#include "Equation.h"
#include <iostream>
#include <cmath>
#define epsilon 1e-5

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

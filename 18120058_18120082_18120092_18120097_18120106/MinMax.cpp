#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <iomanip>
#include "TapXacDinh.h"
#include "Equation.h"
#include "MinMax.h"
#define epsilon 1e-5
extern FILE * input, * output;
using namespace std;

void MinMax(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:case 5:case 11:case 12:case 13:case 14:case 15:case 18:
	{
		MinMax_1();
		break;
	}
	case 2:
	{
		MinMax_2(a, b, c);
		break;
	}
	case 3:
	{
		MinMax_3(a, b, c, d);
		break;
	}
	case 4:
	{
		MinMax_4(a, b, c);
		break;
	}
	case 6:
	{
		MinMax_6(a, b, c, d, e);
		break;
	}
	case 16:
	{
		MinMax_16();
		break;
	}
	case 17:
	{
		MinMax_17();
		break;
	}
	case 19:
	{
		MinMax_19(a, b, c);
		break;
	}
	case 20:
	{
		MinMax_20(a, b, c, d);
		break;
	}
	case 21:
	{
		MinMax_21(a, b, c);
		break;
	}
	case 22:
	{
		MinMax_22(a,b,c,d);
		break;
	}
	case 23:
	{
		break;
	}
	default:
		break;
	}
}

void MinMax_1()
{
	fprintf(output, "\nHam so khong co cuc tieu hay cuc dai !!!\n\n");
}

void MinMax_2(float a, float  b, float  c)
{
	if (a < 0)
	{
		fprintf(output, "\nHam so khong co cuc tieu!!!\n\n");
		float x1 = (-b) / (2 * a);
		float MAX = a * pow(x1, 2) + b * x1 + c;
		fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", x1, MAX);
	}
	else if (a > 0)
	{
		float x1 = (-b) / (2 * a);
		float MIN = a * pow(x1, 2) + b * x1 + c;
		fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", x1, MIN);
		fprintf(output, "\nHam so khong co cuc dai!!!\n\n");
	}
}

void MinMax_3(float a, float b, float c, float d)
{
	float a1 = 3 * a, b1 = 2 * b, c1 = c;
	float x, y;
	short z;
	GiaiPT_Bac2(a1, b1, c1, x, y, z);
	if (z == -1 || z == 0)
	{
		fprintf(output, "\nHam so khong cuc dai va cuc tieu!!!\n\n");
	}
	else
	{
		if (a < 0)
		{
			float X1, X2;
			if (x < y)
			{
				float MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X1 = x;
				float MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X2 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
			else
			{
				float X1, X2;
				float MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X2 = x;
				float MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X1 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
		}
		else
		{
			if (x < y)
			{
				float X1, X2;
				float MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X1 = x;
				float MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X2 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
			else
			{
				float X1, X2;
				float MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X2 = x;
				float MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X1 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
		}
	}
}

void MinMax_4(float a, float b, float c)
{
	float a1 = 4 * a, b1 = 2 * a;
	if (a > 0 && b >= 0)
	{
		fprintf(output, "\nHam so co cuc tieu la: (%d, %10f)\n\n", 0, c);
		fprintf(output, "\nHam so khong co cuc dai!!!\n\n");
	}
	else if (a < 0 && b <= 0)
	{
		fprintf(output, "\nHam so khong co cuc tieu!!!\n\n");
		fprintf(output, "\nHam so co cuc dai la: (%d, %10f)\n\n", 0, c);
	}
	else if (a > 0 && b < 0)
	{
		float delta;
		delta = b * b - 4 * a * c;
		fprintf(output, "\nHam so co 2 cuc tieu la: (%.2f , %.2f) va (%.2f , %.2f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
		fprintf(output, "\nHam so co 1 cuc dai la: (%d , %.2f)", 0, c);
	}
	else if (a < 0 && b > 0)
	{
		float delta;
		delta = b * b - 4 * a * c;
		fprintf(output, "\nHam so co 1 cuc tieu la: (%d , %.2f)", 0, c);
		fprintf(output, "\nHam so co 2 cuc dai la: (%.2f , %.2f) va (%.2f , %.2f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
	}
}

void MinMax_6(float a, float b, float c, float d, float e)
{
	float a1 = a * d;
	float b1 = 2 * a * e;
	float c1 = b * e - c * d;
	float x, y;
	short z;
	GiaiPT_Bac2(a1, b1, c1, x, y, z);
	if (z == -1 || z == 0)
		fprintf(output, "\nHam so khong co cuc tieu hay cuc dai !!!\n\n");
	else
	{
		if (Equa_2(a1, b1, c1, x - epsilon) > 0 && Equa_2(a1, b1, c1, x + epsilon) < 0)
		{
			fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", x, Equa_6(a, b, c, d, e, x));
			fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", y, Equa_6(a, b, c, d, e, y));
		}
		else
		{
			fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", y, Equa_6(a, b, c, d, e, y));
			fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", x, Equa_6(a, b, c, d, e, x));
		}
	}
}

void MinMax_16()
{
	if (output == stdout) fprintf(output, "Ham so co cuc tieu tai cac diem (-%c/2 + k* 2%c,-1), k thuoc Z\n\n", (char)227, (char)227);
	else fprintf(output, "Ham so co cuc tieu tai cac diem (-Pi/2 + k* 2Pi,-1), k thuoc Z\n\n");
	if (output == stdout) fprintf(output, "Ham so co cuc dai tai cac diem (%c/2 + k* 2%c,1), k thuoc Z\n\n", (char)227, (char)227);
	else fprintf(output, "Ham so co cuc dai tai cac diem (Pi/2 + k* 2Pi,1), k thuoc Z\n\n");
}

void MinMax_17()
{
	if (output == stdout) fprintf(output, "Ham so co cuc tieu tai cac diem (%c + k* 2%c,-1), k thuoc Z\n\n", (char)227, (char)227);
	else fprintf(output, "Ham so co cuc tieu tai cac diem (Pi + k* 2Pi,-1), k thuoc Z\n\n");
	if (output == stdout) fprintf(output, "Ham so co cuc dai tai cac diem (k* 2%c,1), k thuoc Z\n\n", (char)227);
	else fprintf(output, "Ham so co cuc dai tai cac diem (k* 2Pi,1), k thuoc Z\n\n");
}

void MinMax_19(float a, float b, float c) {
	if (a == 0) {
		MinMax_1();
	}
	else {
		float x, y;
		short k;
		GiaiPT_Bac2(a, b, c, x, y, k);
		if (k == -1 || k == 0) {
			if (a > 0) {
				fprintf(output, "Ham so co cuc tieu tai x= %.2f  y=0\n", -b / 2 * a);
			}
			else
			{
				fprintf(output, "Ham so khong co cuc tri\n");
			}
		}
		else
		{
			if (a > 0) {
				if (-b / 2 * a < x) {
					fprintf(output, "Ham so co cuc tieu tai x= %.2f  y=0 \n", -b / 2 * a);
				}
				else {
					if (-b / 2 * a > y) {
						fprintf(output, "Ham so co cuc tieu tai x= %.2f y=%.2f \n", -b / 2 * a, sqrt(Equa_2(a, b, c, -b / 2 * a)));
					}
					else {
						fprintf(output, "Ham so khong co cuc tri\n");
					}
				}
			}
			else
				if (-b / 2 * a > x && -b / 2 * a < y) {
					fprintf(output, "Ham so co cuc tieu tai x= %.2f y=0\n", -b / 2 * a);
				}
				else
					if (-b / 2 * a < x) {
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else {
						fprintf(output, "Ham so khong co cuc tri\n");
					}
		}
	}
}

void MinMax_20(float a, float b, float c, float d)
{
	if (a == 0)
		MinMax_19(b, c, d);
	else
	{
		float x1, x2, x3, x, y;
		short k, l;
		GiaiPT_Bac3(a, b, c, d, x1, x2, x3, k);
		GiaiPT_Bac2(3 * a, 2 * b, c, x, y, l);
		if (l == -1) {
			switch (k)
			{
			case 1:
				if (a > 0)
				{

				}
				else {
					fprintf(output, "Ham so khong co cuc tri\n");
				}
				break;
			case 3:
				if (a > 0)
				{
					if (x1 == x2 && x2 == x3) {
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else
					{
						if (x1 == x2) {
							fprintf(output, "Ham so khong co cuc tri\n");
						}
						else
						{
							if (x2 == x3) {
								fprintf(output, "Ham so khong co cuc tri\n");
							}
							else
							{
								fprintf(output, "Ham so khong co cuc tri\n");
							}
						}
					}
				}
				else
				{
					if (x1 == x2 && x2 == x3)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else
					{
						if (x1 == x2)
						{
							fprintf(output, "Ham so khong co cuc tri\n");
						}
						else
						{
							if (x2 == x3)
							{
								fprintf(output, "Ham so khong co cuc tri\n");
							}
							else
							{
								fprintf(output, "Ham so khong co cuc tri\n");
							}
						}
					}
				}
			}
		}
		else
		{
			if (l == 0) {
				switch (k)
				{
				case 1:
					if (a > 0)
					{
						if (x > x1) {
							fprintf(output, "Ham so khong co cuc tri\n");
						}
						else
						{
							fprintf(output, "Ham so khong co cuc tri\n");
						}
					}
					else {
						if (x > x1)
						{
							fprintf(output, "Ham so khong co cuc tri\n");
						}
						else {
							fprintf(output, "Ham so khong co cuc tri\n");
						}
					}
					break;
				case 3:
					if (a > 0)
					{
						if (x1 == x2 && x2 == x3) {
							if (x < x1)
							{
								fprintf(output, "Ham so khong co cuc tri\n");
							}
							else {
								fprintf(output, "Ham so khong co cuc tri\n");
							}
						}
						else
						{
							if (x1 == x2) {
								if (x < x3)
								{
									fprintf(output, "Ham so khong co cuc tri\n");
								}
								else {
									fprintf(output, "Ham so khong co cuc tri\n");
								}
							}
							else
							{
								if (x2 == x3) {
									if (x < x1)
									{
										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
								}
								else {
									if (x < x1) {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										if (x > x1 && x < x2) {
											fprintf(output, "Ham so khong co cuc tri\n");
										}
										else {
											if (x > x2 && x < x3) {
												fprintf(output, "Ham so khong co cuc tri\n");
											}
											else {
												fprintf(output, "Ham so khong co cuc tri\n");
											}

										}
									}
								}
							}
						}
					}
					else
					{
						if (x1 == x2 && x2 == x3) {
							if (x > x1)
							{
								fprintf(output, "Ham so khong co cuc tri\n");
							}
							else {
								fprintf(output, "Ham so khong co cuc tri\n");
							}
						}
						else
						{
							if (x1 == x2)
							{
								if (x > x3)
								{
									fprintf(output, "Ham so khong co cuc tri\n");
								}
								else {

									fprintf(output, "Ham so khong co cuc tri\n");
								}
							}
							else
							{
								if (x2 == x3)
								{
									if (x > x1)
									{

										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
								}
								else
								{
									fprintf(output, "Ham so khong co cuc tri\n");
									if (x > x3) {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										if (x > x2 && x < x3) {
											fprintf(output, "Ham so khong co cuc tri\n");
										}
										else {
											if (x > x1 && x < x2) {
												fprintf(output, "Ham so khong co cuc tri\n");
											}
											else {
												fprintf(output, "Ham so khong co cuc tri\n");
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				switch (k)
				{
				case 1:
					if (a > 0)
					{
						if (x > x1 && y > x1) {
							fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
						}
						else {
							if (x < x1 && y>x1) {
								fprintf(output, "Ham so co 1 cuc tieu tai x=%.2f y=%.2f\n", y, sqrt(Equa_3(a, b, c, d, y)));
							}
							else
							{
								fprintf(output, "Ham so khong co cuc tri\n");
							}
						}
					}
					else {
						if (x < x1 && y < x1) {
							fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", y, sqrt(Equa_3(a, b, c, d, y)), x, sqrt(Equa_3(a, b, c, d, x)));
						}
						else {
							if (x<x1 && y>x1) {
								fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)));
							}
							else {
								fprintf(output, "Ham so khong co cuc tri\n");
							}
						}
					}
					break;
				case 3:
					if (a > 0)
					{
						if (x1 == x2 && x2 == x3) {
							if (x > x1 && y > x1) {
								fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
							}
							else {
								if (x < x1 && y>x1) {
									fprintf(output, "Ham so co 1 cuc tieu tai x=%.2f y=%.2f\n", y, sqrt(Equa_3(a, b, c, d, y)));
								}
								else
								{
									fprintf(output, "Ham so khong co cuc tri\n");
								}
							}
						}
						else
						{
							if (x1 == x2) {
								if (x < x3 && y < x3)
								{
									fprintf(output, "Ham so khong co cuc tri\n");
								}
								else {
									if (x<x3 && y>x3) {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
								}
							}
							else
							{
								if (x2 == x3) {
									if (x < x1 && y < x1)
									{
										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										if (x<x1 && y>x1) {
											fprintf(output, "Ham so khong co cuc tri\n");
										}
										else {
											fprintf(output, "Ham so khong co cuc tri\n");
										}
									}
								}
								else {
									if (x < x1 && y < x1) {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										if (x<x1 && x >x1) {
											fprintf(output, "Ham so co 1 cuc tieu tai x=%.2f y=%.2f\n", y, sqrt(Equa_3(a, b, c, d, y)));
										}
										else {
											if (x < x2 && y < x2) {
												fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
											}
											else {
												if (x<x2 && y>x2) {
													fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)));
												}
												else {
													if (x < x3 && y < x3) {
														fprintf(output, "Ham so khong co cuc tri\n");
													}
													else {
														if (x<x3 && y>x3) {
															fprintf(output, "Ham so co 1 cuc tieu tai x=%.2f y=%.2f\n", y, sqrt(Equa_3(a, b, c, d, y)));
														}
														else {
															fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
														}
													}
												}

											}

										}
									}
								}
							}
						}
					}
					else
					{
						if (x1 == x2 && x2 == x3) {
							if (x < x1 && y < x1) {
								fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
							}
							else {
								if (x<x1 && y>x1) {
									fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)));
								}
								else
								{
									fprintf(output, "Ham so khong co cuc tri\n");
								}
							}
						}
						else
						{
							if (x1 == x2)
							{
								if (x > x3 && y > x3)
								{
									fprintf(output, "Ham so khong co cuc tri\n");
								}
								else {
									if (x<x3 && y>x3) {
										fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)));
									}
									else {
										fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
									}

								}
							}
							else
							{
								if (x2 == x3)
								{
									if (x > x1 && y > x1)
									{
										fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
									}
									else {
										if (x<x3 && y>x3) {
											fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)));
										}
										else {
											fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
										}
									}
								}
								else
								{
									if (x > x3 && y > x3) {
										fprintf(output, "Ham so khong co cuc tri\n");
									}
									else {
										if (x<x3 && y >x3) {
											fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)));
										}
										else {
											if (x < x3 && y < x3) {
												fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
											}
											else {
												if (x<x2 && y>x2) {
													fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
												}
												else {
													if (x<x2 && y<x2)
														fprintf(output, "Ham so khong co cuc tri\n");
													else {
														if (x<x1 && y>x1) {
															fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)));
														}
														else {
															fprintf(output, "Ham so co 1 cuc dai tai x=%.2f y=%.2f va 1 cuc tieu tai x=%.2f y=%.2f\n", x, sqrt(Equa_3(a, b, c, d, x)), y, sqrt(Equa_3(a, b, c, d, y)));
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void MinMax_21(float a, float b, float c)
{
	if (a == 0)
		MinMax_19(b, 0, c);
	else
	{
		float x1, x2, x3, x4, x5, x6, x7;
		short k, l;
		GiaiPT_Bac4(a, 0, b, 0, c, x1, x2, x3, x4, k);
		GiaiPT_Bac3(4 * a, 0, 2 * b, 0, x5, x6, x7, l);
		switch (k) {
		case 0:
			if (l == 1)//tu co nghiem bang 0
			{
				if (a > 0)
				{
					fprintf(output, "Ham so co 1 cuc tieu tai x = %.2f\n", x5);
				}
				else
					fprintf(output, "Ham so khong xac dinh\n");
			}
			if (l == 3)
			{
				if (a > 0)
				{
					if (x5 == x6 && x6 == x7)
					{
						fprintf(output, "Ham so co 1 cuc tieu tai x = %.2f\n", x5);
					}
					else
					{
						if (x5 == x6)
						{
							fprintf(output, "Ham so co 1 cuc tieu tai x = %.2f\n", x7);
						}
						else
						{
							if (x6 == x7)
							{
								fprintf(output, "Ham so co 1 cuc tieu tai x = %.2f\n", x5);
							}
							else
							{
								fprintf(output, "Ham so co 2 cuc tieu tai x = %.2f va x = %.2f\n", x5, x7);
								fprintf(output, "Ham so co 1 cuc dai tai x = %.2f\n", x6);
							}
						}
					}
				}
				else
					fprintf(output, "Ham so khong xac dinh\n");
			}
			break;
		case 2:
			if (l == 1 || (l == 3 && x5 == x7))
			{
				if (a > 0)
				{
					if (x1 != x2)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					if (x1 == x2)
					{
						fprintf(output, "Ham so co 1 cuc tieu tai x = 0\n");
					}
				}
				else
				{
					if (x1 != x2)
					{
						fprintf(output, "Ham so co 1 cuc dai tai x = 0\n");
					}
					if (x1 == x2)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
				}
			}
			if (l == 3 && x5 != x7)
			{
				if (a > 0)
				{
					if (x1 != x2)
					{
						if (x7 <= x2)
						{
							fprintf(output, "Ham so khong co cuc tri\n");
						}
						if (x7 > x2)
						{
							fprintf(output, "Ham so co 2 cuc tieu tai x = %.2f va x = %.2f\n", x5, x7);
						}
					}
					if (x1 == x2)//Truong hop nay thuc ra khong ton tai
					{

					}
				}
				if (a < 0)
				{
					if (x1 != x2)
					{
						if (x7 >= x2)//Truong hop nay thuc ra khong ton tai
						{

						}
						if (x7 < x2)
						{
							fprintf(output, "Ham so co 1 cuc tieu tai x = %.2f\n", x6);
							fprintf(output, "Ham so co 2 cuc dai tai x = %.2f va x = %.2f\n", x5, x7);
						}
					}
					if (x1 == x2)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
				}
			}
			break;
		case 4:
			if (l == 1 || (l == 3 && x5 == x7))//Truong hop l==1 khong ton tai => chi co truong hop f(x)=ax^4 => chi co truong hop x1=x2=x3=x4=0
			{
				if (a > 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so co 1 cuc tieu tai x = 0\n");
					}
					else
					{
						if (x2 == x3)
						{
							fprintf(output, "Ham so khong co cuc tri\n");
						}
						if (x2 != x3)//Truong hop nay khong ton tai
						{
						}
					}
				}
				if (a < 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else//Truong hop nay khong ton tai 
					{
					}
				}
			}
			if (l == 3 && x5 != x7)
			{
				if (a > 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so co 2 cuc tieu tai x = %.2f va x = %.2f\n", x5, x7);
						fprintf(output, "Ham so co 1 cuc dai tai x = %.2f\n", x6);
					}
					else
					{
						if (x2 == x3)
						{
							if (x7 <= x4)
							{
								fprintf(output, "Ham so khong co cuc tri\n");
							}
							if (x7 > x4)//Truong hop nay khong ton tai
							{
							}
						}
						else
						{
							if (x3 != x4)
							{
								if (x7 < x3)//Truong hop nay khong ton tai
								{
								}
								if (x7 >= x3 && x7 <= x4)
								{
									fprintf(output, "Ham so co 1 cuc dai tai x = %.2f\n", x6);
								}
								if (x7 > x4)//Truong hop nay khong ton tai
								{
								}
							}
							if (x3 == x4)
							{
								if (x7 < x4)//Truong hop nay khong ton tai
								{
								}
								if (x7 == x4)
								{
									fprintf(output, "Ham so co 2 cuc tieu tai x = %.2f va x = %.2f\n", x5, x7);
									fprintf(output, "Ham so co 1 cuc dai tai x = %.2f\n", x6);
								}
								if (x7 > x4)//Truong hop nay khong ton tai
								{
								}
							}
						}
					}
				}
				if (a < 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else
					{
						if (x2 == x3)
						{
							if (x7 >= x4)//Truong hop nay khong ton tai
							{
							}
							if (x7 < x4)
							{
								fprintf(output, "Ham so co 1 cuc tieu tai x = %.2f\n", x6);
								fprintf(output, "Ham so co 2 cuc dai tai x = %.2f va x = %.2f\n", x5, x7);
							}
						}
						else
						{
							if (x3 != x4)
							{
								if (x7 <= x3)//Truong hop nay khong ton tai
								{
								}
								if (x7 > x3 && x7 < x4)
								{
									fprintf(output, "Ham so co 2 cuc dai tai x = %.2f va x = %.2f\n", x5, x7);
								}
								if (x7 >= x4)//Truong hop nay khong ton tai
								{
								}
							}
							if (x3 == x4)
								fprintf(output, "Ham so khong co cuc tri\n");
						}
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void MinMax_22(float a, float b, float c, float d)
{
	if (a == 0)
	{
		if (b == 0)
			fprintf(output, "Ham so khong co cuc tri\n");
		else
		{
			if (b < 0)
			{
				c = -c;
				d = -d;
			}
			if (c > 0) {
				if (-d - b * c < 0)
				{
					fprintf(output, "Ham so khong co cuc tri\n");
				}
				else
				{
					fprintf(output, "Ham so khong co cuc tri\n");
				}
			}
			else
			{
				if (c != 0) {
					if (-d - b * c < 0)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
				}
				else
				{
					if (d >= 0)
						fprintf(output, "Ham so khong co cuc tri\n");
					else
						fprintf(output, "Ham so khong xac dinh\n");
				}
			}
		}
	}
	else
	{
		if (c == 0)
		{
			if (d == 0)
				fprintf(output, "Ham so khong xac dinh\n");
			else
				MinMax_1();
		}
		else
		{
			float x1 = -b / a;
			float x2 = -d / c;
			if (x1 > x2)
				swap(x1, x2);
			a = a / c;
			b = b / c;
			c = c / c;
			d = d / c;
			if (x1 == x2)
			{
				if (a * c > 0)
					fprintf(output, "Ham so khong co cuc tri\n");
				if (a * c < 0)
					fprintf(output, "Ham so khong xac dinh\n");
			}
			else
			{
				if (a > 0)
				{
					if (a * d - b * c < 0)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
				}
				else
				{
					if (a * d - b * c < 0)
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
					else
					{
						fprintf(output, "Ham so khong co cuc tri\n");
					}
				}
			}
		}
	}
}

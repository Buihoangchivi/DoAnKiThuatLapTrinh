#include <cmath>
#include "Equation.h"
#include <stdio.h>
#include <cmath>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Draw.h"
#include <iomanip>
using namespace std;
#define xMin -14
#define xMax 14
#define yMin -14
#define yMax 14
#define cl 0.02
#define epsilon 1e-5

void Sin()
{
	glColor3f(0.1, 0.8, 0.5);
	glBegin(GL_POINTS);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, sin(i));
	}
	glEnd();
}

void Cos()
{
	glColor3f(0, 0.5, 1);
	glBegin(GL_POINTS);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, cos(i));
	}
	glEnd();
}

void Tan()
{
	glColor3f(1, 0.2, 0.6);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		if (tan(i) * tan(i + cl) < 0) continue;
		glVertex2f(i, tan(i));
		glVertex2f(i + cl, tan(i + cl));
	}
	glEnd();
}

void CoTan()
{
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		if (1 / (tan(i) * tan(i + cl)) < 0) continue;
		glVertex2f(i, 1 / tan(i));
		glVertex2f(i + cl, 1 / tan(i + cl));
	}
	glEnd();
}

void PT1(float a, float b)
{
	glColor3f(0, 1, 1);
	glBegin(GL_POINTS);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, Equa_1(a, b, i));
	}
	glEnd();
}

void PT2(float a, float b, float c)
{
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	for (float i = xMin; i < xMax; i += cl)
	{
		glVertex2f(i, Equa_2(a, b, c, i));
		glVertex2f(i + cl, Equa_2(a, b, c, i + cl));
	}
	glEnd();
}

void PT3(float a, float b, float c, float d)
{
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, Equa_3(a, b, c, d, i));
		glVertex2f(i + cl, Equa_3(a, b, c, d, i + cl));
	}
	glEnd();
}

void PT4(float a, float b, float c)
{
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	for (float i = xMin; i < xMax; i += cl)
	{
		glVertex2f(i, Equa_4(a, b, c, i));
		glVertex2f(i + cl, Equa_4(a, b, c, i + cl));
	}
	glEnd();
}

void PT5(float a, float b, float c, float d)
{
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		if (Equa_5(a, b, c, d, i) * Equa_5(a, b, c, d, i + cl) < 0) continue;
		glVertex2f(i, Equa_5(a, b, c, d, i));
		glVertex2f(i + cl, Equa_5(a, b, c, d, i + cl));
	}
	glEnd();
}

void PT6(float a, float b, float c, float d, float e)
{
	glColor3f(1, 0, 1);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		if (Equa_6(a, b, c, d, e, i) * Equa_6(a, b, c, d, e, i + cl) < 0) continue;
		glVertex2f(i, Equa_6(a, b, c, d, e, i));
		glVertex2f(i + cl, Equa_6(a, b, c, d, e, i + cl));
	}
	glEnd();
}

void PT7(float a, float b, float c)
{
	glColor3f(0.4, 0.3, 0.6);
	glBegin(GL_POINTS);
	float y1, y2;
	for (float i = a - c; i <= a + c; i += cl)
	{
		Equa_7(a, b, c, i, y1, y2);
		glVertex2f(i, y1);
		glVertex2f(i, y2);
	}
	glEnd();
}

void PT8(float a, float b)
{
	glColor3f(0.4, 0.1, 0.5);
	glBegin(GL_POINTS);
	float y1, y2;
	for (float i = -a; i <= a; i += cl)
	{
		Equa_8(a, b, i, y1, y2);
		glVertex2f(i, y1);
		glVertex2f(i, y2);
	}
	glEnd();
}

void PT9(float a, float b, float c, float d)
{
	glColor3f(0.7, 0.8, 0.4);
	glBegin(GL_POINTS);
	float y1, y2;
	for (float i = xMin; i <= a - c; i += cl)
	{
		Equa_9(a, b, c, d, i, y1, y2);
		glVertex2f(i, y1);
		glVertex2f(i, y2);
	}
	for (float i = a + c; i <= xMax; i += cl)
	{
		Equa_9(a, b, c, d, i, y1, y2);
		glVertex2f(i, y1);
		glVertex2f(i, y2);
	}
	glEnd();
}

void PT10(float a, float b, float c, float d, float e)
{
	glColor3f(0.1, 1, 0.3);
	glBegin(GL_POINTS);
	float y1, y2, temp;
	short k;
	for (float i = xMin; i <= xMax; i += cl)
	{
		Equa_10(a, b, c, d, e, i, y1, y2, k);
		if (k == -1) continue;
		glVertex2f(i, y1);
		if (k == 0) continue;
		glVertex2f(i, y2);
	}
	glEnd();
}

void PT11(float a)
{
	glColor3f(0.1, 1, 0.3);
	glBegin(GL_LINES);
	for (float i = 0; i <= xMax; i += cl)
	{
		if (pow(log(i), a) * pow(log(i + cl), a) < 0) continue;
		glVertex2f(i, pow(log(i), a));
		glVertex2f(i + cl, pow(log(i + cl), a));
	}
	glEnd();
}

void PT12(float a)
{
	glColor3f(0.1, 1, 0.3);
	glBegin(GL_LINES);
	for (float i = 0; i <= xMax; i += cl)
	{
		if ((log(i) / log(a)) * (log(i + cl) / log(a)) < 0) continue;
		glVertex2f(i, log(i) / log(a));
		glVertex2f(i + cl, log(i + cl) / log(a));
	}
	glEnd();
}

void PT13()
{
	glColor3f(0.1, 1, 0.3);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, exp(i));
		glVertex2f(i + cl, exp(i + cl));
	}
	glEnd();
}

void PT18(float a, float b)
{
	glColor3f(0.4, 0.2, 0.5);
	glBegin(GL_LINES);
	if (a > 0)
	{
		for (float i = -b / a; i < xMax; i += cl)
		{
			glVertex2f(i, sqrt(Equa_1(a, b, i)));
			glVertex2f(i + cl, sqrt(Equa_1(a, b, i + cl)));
		}
	}
	else
	{
		if (a != 0)
		{
			for (float i = xMin; i <= -b / a; i += cl)
				if (fabs(Equa_1(a, b, i)) <= epsilon)
					if (fabs(Equa_1(a, b, i + cl)) <= epsilon)
					{
						glVertex2f(i, sqrt(Equa_1(a, b, i)));
						glVertex2f(i + cl, sqrt(Equa_1(a, b, i + cl)));
					}
					else
					{
						glVertex2f(i, sqrt(Equa_1(a, b, i)));
						glVertex2f(-b / a, 0);
					}
		}
		else
			for (float i = xMin; i <= xMax; i += cl)
			{
				glVertex2f(i, sqrt(b));
				glVertex2f(i + cl, sqrt(b));
			}
	}
	glEnd();
}

void PT19(float a, float b, float c)
{
	glColor3f(0.2, 1, 0.4);
	glBegin(GL_LINES);
	float x, y;
	short k;
	GiaiPT_Bac2(a, b, c, x, y, k);
	if (k != 1)
	{
		for (float i = xMin; i < xMax; i += cl)
			if (Equa_2(a, b, c, i) >= 0 || fabs(Equa_2(a, b, c, i)) <= epsilon)
			{
				glVertex2f(i, sqrt(fabs(Equa_2(a, b, c, i))));
				glVertex2f(i + cl, sqrt(fabs(Equa_2(a, b, c, i + cl))));
			}
	}
	else
	{
		if (a > 0)
		{
			for (float i = x; i >= xMin; i -= cl)
			{
				glVertex2f(i, sqrt(Equa_2(a, b, c, i)));
				glVertex2f(i - cl, sqrt(Equa_2(a, b, c, i - cl)));
			}
			for (float i = y; i <= xMax; i += cl)
			{
				glVertex2f(i, sqrt(Equa_2(a, b, c, i)));
				glVertex2f(i + cl, sqrt(Equa_2(a, b, c, i + cl)));
			}
		}
		else
		{
			for (float i = x; i <= y; i += cl)
				if (Equa_2(a, b, c, i) >= 0 || fabs(Equa_2(a, b, c, i)) <= epsilon)
					if (Equa_2(a, b, c, i + cl) >= 0 || fabs(Equa_2(a, b, c, i + cl)) <= epsilon)
					{
						glVertex2f(i, sqrt(fabs(Equa_2(a, b, c, i))));
						glVertex2f(i + cl, sqrt(fabs(Equa_2(a, b, c, i + cl))));
					}
					else
					{
						glVertex2f(i, sqrt(fabs(Equa_2(a, b, c, i))));
						glVertex2f(y, 0);
					}
		}
	}
	glEnd();
}

void PT20(float a, float b, float c, float d)
{
	glColor3f(0.8, 0.7, 0.2);
	glBegin(GL_LINES);
	float x1, x2, x3;
	short k;
	GiaiPT_Bac3(a, b, c, d, x1, x2, x3, k);
	switch (k)
	{
	case 1:
		if (a > 0)
		{
			for (float i = x1; i <= xMax; i += cl)
			{
				glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
				glVertex2f(i + cl, sqrt(fabs(Equa_3(a, b, c, d, i + cl))));
			}
		}
		else
		{
			for (float i = x1; i >= xMin; i -= cl)
			{
				glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
				glVertex2f(i - cl, sqrt(fabs(Equa_3(a, b, c, d, i - cl))));
			}
		}
		break;
	case 3:
		if (a > 0)
		{
			if (x1 == x2 && x2 == x3)
			{
				for (float i = x1; i <= xMax; i += cl)
				{
					glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
					glVertex2f(i + cl, sqrt(fabs(Equa_3(a, b, c, d, i + cl))));
				}
			}
			else
			{
				if (x1 == x2)
				{
					for (float i = x3; i <= xMax; i += cl)
					{
						glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
						glVertex2f(i + cl, sqrt(fabs(Equa_3(a, b, c, d, i + cl))));
					}
					glVertex2f(x1, sqrt(fabs(Equa_3(a, b, c, d, x1))));
					glVertex2f(x1, sqrt(fabs(Equa_3(a, b, c, d, x1))));
				}
				else
				{
					if (x2 == x3)
					{
						for (float i = x1; i <= xMax; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_3(a, b, c, d, i + cl))));
						}
					}
					else
					{
						for (float i = x1; i <= x2; i += cl)
							if (Equa_3(a, b, c, d, i) >= 0 || fabs(Equa_3(a, b, c, d, i)) <= epsilon)
								if (Equa_3(a, b, c, d, i + cl) >= 0 || fabs(Equa_3(a, b, c, d, i + cl)) <= epsilon)
								{
									glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_3(a, b, c, d, i + cl))));
								}
								else
								{
									glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
									glVertex2f(x2, sqrt(fabs(Equa_3(a, b, c, d, x2))));
								}
						for (float i = x3; i <= xMax; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_3(a, b, c, d, i + cl))));
						}
					}
				}
			}
		}
		else
		{
			if (x1 == x2 && x2 == x3)
			{
				for (float i = x1; i >= xMin; i -= cl)
				{
					glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
					glVertex2f(i - cl, sqrt(fabs(Equa_3(a, b, c, d, i - cl))));
				}
			}
			else
			{
				if (x1 == x2)
				{
					for (float i = x3; i >= xMin; i -= cl)
					{
						glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
						glVertex2f(i - cl, sqrt(fabs(Equa_3(a, b, c, d, i - cl))));
					}
				}
				else
				{
					if (x2 == x3)
					{
						for (float i = x1; i >= xMin; i -= cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
							glVertex2f(i - cl, sqrt(fabs(Equa_3(a, b, c, d, i - cl))));
						}
						glVertex2f(x2, sqrt(fabs(Equa_3(a, b, c, d, x2))));
						glVertex2f(x2, sqrt(fabs(Equa_3(a, b, c, d, x2))));
					}
					else
					{
						for (float i = x1; i >= xMin; i -= cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
							glVertex2f(i - cl, sqrt(fabs(Equa_3(a, b, c, d, i - cl))));
						}
						for (float i = x2; i <= x3; i += cl)
							if (Equa_3(a, b, c, d, i) >= 0 || fabs(Equa_3(a, b, c, d, i)) <= epsilon)
								if (Equa_3(a, b, c, d, i + cl) >= 0 || fabs(Equa_3(a, b, c, d, i + cl)) <= epsilon)
								{
									glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_3(a, b, c, d, i + cl))));
								}
								else
								{
									glVertex2f(i, sqrt(fabs(Equa_3(a, b, c, d, i))));
									glVertex2f(x3, sqrt(fabs(Equa_3(a, b, c, d, x3))));
								}
					}
				}
			}
		}
	}
	glEnd();
}

void PT21(float a, float b, float c)
{
	if (a == 0)
		PT19(b, 0, c);
	else
	{
		glColor3f(0.1, 0.4, 0.6);
		glBegin(GL_LINES);
		float x1, x2, x3, x4;
		short k;
		GiaiPT_Bac4(a, 0, b, 0, c, x1, x2, x3, x4, k);
		switch (k) {
		case 0:
			if (a > 0)
			{
				for (float i = xMin; i <= xMax; i += cl)
				{
					glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
					glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
				}
			}
			else break;
		case 2:
			if (a > 0)
			{
				if (x1 != x2)
				{
					for (float i = x1; i >= xMin; i -= cl)
					{
						glVertex2f(i, sqrt(Equa_2(a, b, c, i)));
						glVertex2f(i - cl, sqrt(Equa_2(a, b, c, i - cl)));
					}
					for (float i = x2; i <= xMax; i += cl)
					{
						glVertex2f(i, sqrt(fabs(Equa_2(a, b, c, i))));
						glVertex2f(i + cl, sqrt(fabs(Equa_2(a, b, c, i + cl))));
					}
				}
				else
				{
					for (float i = xMin; i <= xMax; i += cl)
					{
						glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
						glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
					}
				}
			}
			else
			{
				if (x1 != x2)
				{
					for (float i = x1; i <= x2; i += cl)
						if (Equa_4(a, b, c, i) >= 0 || fabs(Equa_4(a, b, c, i)) <= epsilon)
							if (Equa_4(a, b, c, i + cl) >= 0 || fabs(Equa_4(a, b, c, i + cl)) <= epsilon)
							{
								glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
								glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
							}
							else
							{
								glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
								glVertex2f(x2, sqrt(fabs(Equa_4(a, b, c, x2))));
							}
				}
				else
				{
					glVertex2f(0, sqrt(fabs(Equa_4(a, b, c, 0))));
					glVertex2f(0, sqrt(fabs(Equa_4(a, b, c, 0))));
				}
			}
			break;
		case 4:
			if (a > 0)
			{
				if (x1 == x4)
				{
					for (float i = xMin; i <= xMax; i += cl)
					{
						glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
						glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
					}
				}
				else
				{
					if (x2 == x3)
					{
						for (float i = x1; i >= xMin; i -= cl)
						{
							glVertex2f(i, sqrt(Equa_2(a, b, c, i)));
							glVertex2f(i - cl, sqrt(Equa_2(a, b, c, i - cl)));
						}
						for (float i = x4; i <= xMax; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_2(a, b, c, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_2(a, b, c, i + cl))));
						}
						glVertex2f(0, sqrt(fabs(Equa_4(a, b, c, 0))));
						glVertex2f(0, sqrt(fabs(Equa_4(a, b, c, 0))));
					}
					else
					{
						if (x3 != x4)
						{
							for (float i = x1; i >= xMin; i -= cl)
							{
								glVertex2f(i, sqrt(Equa_2(a, b, c, i)));
								glVertex2f(i - cl, sqrt(Equa_2(a, b, c, i - cl)));
							}
							for (float i = x4; i <= xMax; i += cl)
							{
								glVertex2f(i, sqrt(fabs(Equa_2(a, b, c, i))));
								glVertex2f(i + cl, sqrt(fabs(Equa_2(a, b, c, i + cl))));
							}
							for (float i = x2; i <= x3; i += cl)
								if (Equa_4(a, b, c, i) >= 0 || fabs(Equa_4(a, b, c, i)) <= epsilon)
									if (Equa_4(a, b, c, i + cl) >= 0 || fabs(Equa_4(a, b, c, i + cl)) <= epsilon)
									{
										glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
										glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
									}
									else
									{
										glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
										glVertex2f(x3, sqrt(fabs(Equa_4(a, b, c, x3))));
									}
						}
						if (x3 == x4)
						{
							for (float i = xMin; i <= xMax; i += cl)
							{
								glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
								glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
							}
						}
					}
				}
			}
			else
			{
				if (x1 == x4)
				{
					glVertex2f(0, sqrt(fabs(Equa_4(a, b, c, 0))));
					glVertex2f(0, sqrt(fabs(Equa_4(a, b, c, 0))));
				}
				else
				{
					if (x2 == x3)
					{
						for (float i = x1; i <= x4; i += cl)
							if (Equa_4(a, b, c, i) >= 0 || fabs(Equa_4(a, b, c, i)) <= epsilon)
								if (Equa_4(a, b, c, i + cl) >= 0 || fabs(Equa_4(a, b, c, i + cl)) <= epsilon)
								{
									glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
								}
								else
								{
									glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
									glVertex2f(x4, sqrt(fabs(Equa_4(a, b, c, x4))));
								}
					}
					else
					{
						if (x3 != x4)
						{
							for (float i = x1; i <= x2; i += cl)
								if (Equa_4(a, b, c, i) >= 0 || fabs(Equa_4(a, b, c, i)) <= epsilon)
									if (Equa_4(a, b, c, i + cl) >= 0 || fabs(Equa_4(a, b, c, i + cl)) <= epsilon)
									{
										glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
										glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
									}
									else
									{
										glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
										glVertex2f(x2, sqrt(fabs(Equa_4(a, b, c, x2))));
									}
							for (float i = x3; i <= x4; i += cl)
								if (Equa_4(a, b, c, i) >= 0 || fabs(Equa_4(a, b, c, i)) <= epsilon)
									if (Equa_4(a, b, c, i + cl) >= 0 || fabs(Equa_4(a, b, c, i + cl)) <= epsilon)
									{
										glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
										glVertex2f(i + cl, sqrt(fabs(Equa_4(a, b, c, i + cl))));
									}
									else
									{
										glVertex2f(i, sqrt(fabs(Equa_4(a, b, c, i))));
										glVertex2f(x4, sqrt(fabs(Equa_4(a, b, c, x4))));
									}
						}
						if (x3 == x4)
						{
							glVertex2f(x2, sqrt(fabs(Equa_4(a, b, c, x2))));
							glVertex2f(x2, sqrt(fabs(Equa_4(a, b, c, x2))));
							glVertex2f(x3, sqrt(fabs(Equa_4(a, b, c, x3))));
							glVertex2f(x3, sqrt(fabs(Equa_4(a, b, c, x3))));
						}
					}
				}
			}
		}
		glEnd();
	}
}

void PT22(float a, float b, float c, float d)
{
	glColor3f(1, 0.1, 0.6);
	glBegin(GL_LINES);
	if (a == 0)
	{
		if (b == 0)
		{
			for (float i = xMin; i <= xMax; i += cl)
				if (i != -d / c)
				{
					glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
					glVertex2f(i + cl, sqrt(fabs(Equa_5(a, b, c, d, i + cl))));
				}
		}
		else
		{
			if (b < 0)
			{
				c = -c;
				d = -d;
			}
			if (c > 0)
			{
				for (float i = -d / c + cl; i <= xMax; i += cl)
				{
					glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
					glVertex2f(i + cl, sqrt(fabs(Equa_5(a, b, c, d, i + cl))));
				}
			}
			else
			{
				if (c != 0)
				{
					for (float i = xMin; i < -d / c; i += cl)
					{
						glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
						glVertex2f(i + cl, sqrt(fabs(Equa_5(a, b, c, d, i + cl))));
					}
				}
				else
				{
					if (d >= 0)
					{
						for (float i = xMin; i <= xMax; i += cl)
							if (i != -d / c)
							{
								glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
								glVertex2f(i + cl, sqrt(fabs(Equa_5(a, b, c, d, i + cl))));
							}
					}
				}
			}
		}
	}
	else
	{
		if (c == 0)
		{
			if (d != 0)	PT18(a / d, b / d);
		}
		else
		{
			float x1 = -b / a;
			float x2 = -d / c;
			if (x1 > x2)
				swap(x1, x2);
			if (x1 == x2)
			{
				if (a * c > 0)
				{
					for (float i = xMin; i <= xMax; i += cl)
						if (i != -d / c)
						{
							glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_5(a, b, c, d, i + cl))));
						}
				}
			}
			else
			{
				if (a * c > 0)
				{
					if (x1 == -d / c)
					{
						for (float i = xMin; i < x1; i += cl)
							if (Equa_5(a, b, c, d, i) >= 0 || fabs(Equa_5(a, b, c, d, i)) <= epsilon)
								if (Equa_5(a, b, c, d, i + cl) >= 0 || fabs(Equa_5(a, b, c, d, i + cl)) <= epsilon)
								{
									glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_5(a, b, c, d, i + cl))));
								}
								else
								{
									glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
									glVertex2f(x1, yMax);
								}
						for (float i = x2; i <= xMax; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
							glVertex2f(i - cl, sqrt(fabs(Equa_5(a, b, c, d, i - cl))));
						}
					}
					else
					{
						for (float i = x1; i >= xMin; i -= cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
							glVertex2f(i - cl, sqrt(fabs(Equa_5(a, b, c, d, i - cl))));
						}
						for (float i = xMax; i > x2; i -= cl)
							if (Equa_5(a, b, c, d, i) >= 0 || fabs(Equa_5(a, b, c, d, i)) <= epsilon)
								if (Equa_5(a, b, c, d, i - cl) >= 0 || fabs(Equa_5(a, b, c, d, i - cl)) <= epsilon)
								{
									glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
									glVertex2f(i - cl, sqrt(fabs(Equa_5(a, b, c, d, i - cl))));
								}
								else
								{
									glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
									glVertex2f(x2, yMax);
								}
					}
				}
				else
				{
					if (x1 == -d / c)
					{
						for (float i = x2; i > x1; i -= cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
							glVertex2f(i - cl, sqrt(fabs(Equa_5(a, b, c, d, i - cl))));
						}
					}
					else
					{
						for (float i = x1; i < x2; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_5(a, b, c, d, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_5(a, b, c, d, i + cl))));
						}
					}
				}
			}
		}
	}
	glEnd();
}

void PT23(float a, float b, float c, float d, float e)
{
	if (a == 0)
		PT22(b, c, d, e);
	else
	{
		glColor3f(0, 0.4, 0.6);
		glBegin(GL_LINES);
		if (d == 0)
		{
			if (e != 0) PT19(a / e, b / e, c / e);
		}
		else
		{
			float x3 = -e / d;
			float x1, x2;
			short k;
			GiaiPT_Bac2(a, b, c, x1, x2, k);
			if (k == -1 || k == 0)
			{
				d = d / a;
				e = e / a;
				if (d > 0)
				{
					if (k == 0 && x1 < -e / d)
					{
						for (float i = x1 + cl; i <= xMax; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
						}
						glVertex2f(-e / d, sqrt(fabs(Equa_6(a, b, c, d, e, -e / d))));
						glVertex2f(-e / d, sqrt(fabs(Equa_6(a, b, c, d, e, -e / d))));
					}
					else
					{
						for (float i = -e / d + cl; i <= xMax; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
						}
					}
				}
				else
				{
					if (k == 0 && x1 > -e / d)
					{
						for (float i = xMin; i < -e / d; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
						}
						glVertex2f(x1, sqrt(fabs(Equa_6(a, b, c, d, e, x1))));
						glVertex2f(x1, sqrt(fabs(Equa_6(a, b, c, d, e, x1))));
					}
					else
					{
						for (float i = xMin; i < -e / d; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
						}
					}
				}
			}
			else
			{
				if (x3 > x1 && x3 < x2)
					swap(x2, x3);
				if (x3 <= x1)
				{
					swap(x3, x2);
					swap(x2, x1);
				}
				if (a * d > 0)
				{
					if (x1 == x2)
					{
						for (float i = x3; i <= xMax; i += cl)
						{
							glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
							glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
						}
					}
					else
					{
						if (x2 == x3)
						{
							for (float i = x1; i <= xMax; i += cl)
								if (i != x2)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
								}
						}
						else
						{
							if (x1 == -e / d)
							{
								for (float i = x2; i > x1; i -= cl)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i - cl, sqrt(fabs(Equa_6(a, b, c, d, e, i - cl))));
								}
								for (float i = x3; i <= xMax; i += cl)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
								}
							}
							if (x2 == -e / d)
							{
								for (float i = x1; i < x2; i += cl)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
								}
								for (float i = x3; i <= xMax; i += cl)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
								}
							}
							if (x3 == -e / d)
							{
								for (float i = x1; i <= x2; i += cl)
									if (Equa_6(a, b, c, d, e, i) >= 0 || fabs(Equa_6(a, b, c, d, e, i)) <= epsilon)
										if (Equa_6(a, b, c, d, e, i + cl) >= 0 || fabs(Equa_6(a, b, c, d, e, i + cl)) <= epsilon)
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
										}
										else
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(x2, sqrt(fabs(Equa_6(a, b, c, d, e, x2))));
										}
							}
							for (float i = x3 + cl; i <= xMax; i += cl)
							{
								glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
								glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
							}
						}
					}
				}
				else
				{
					if (x1 == x2)
					{
						for (float i = x3; i >= xMin; i -= cl)
							if (i != x1)
							{
								glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
								glVertex2f(i - cl, sqrt(fabs(Equa_6(a, b, c, d, e, i - cl))));
							}
					}
					else
					{
						if (x2 == x3)
						{
							for (float i = x1; i >= xMin; i -= cl)
							{
								glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
								glVertex2f(i - cl, sqrt(fabs(Equa_6(a, b, c, d, e, i - cl))));
							}
						}
						else
						{
							if (x1 == -e / d)
							{
								for (float i = x1 - cl; i >= xMin; i -= cl)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i - cl, sqrt(fabs(Equa_6(a, b, c, d, e, i - cl))));
								}
								for (float i = x2; i <= x3; i += cl)
									if (Equa_6(a, b, c, d, e, i) >= 0 || fabs(Equa_6(a, b, c, d, e, i)) <= epsilon)
										if (Equa_6(a, b, c, d, e, i + cl) >= 0 || fabs(Equa_6(a, b, c, d, e, i + cl)) <= epsilon)
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
										}
										else
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(x3, sqrt(fabs(Equa_6(a, b, c, d, e, x3))));
										}
							}
							if (x2 == -e / d)
							{
								for (float i = x1; i >= xMin; i -= cl)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i - cl, sqrt(fabs(Equa_6(a, b, c, d, e, i - cl))));
								}
								for (float i = x3; i >= x2; i -= cl)
									if (Equa_6(a, b, c, d, e, i) >= 0 || fabs(Equa_6(a, b, c, d, e, i)) <= epsilon)
										if (Equa_6(a, b, c, d, e, i - cl) >= 0 || fabs(Equa_6(a, b, c, d, e, i - cl)) <= epsilon)
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(i - cl, sqrt(fabs(Equa_6(a, b, c, d, e, i - cl))));
										}
										else
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(x2, yMax);
										}
							}
							if (x3 == -e / d)
							{
								for (float i = x1; i >= xMin; i -= cl)
								{
									glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
									glVertex2f(i - cl, sqrt(fabs(Equa_6(a, b, c, d, e, i - cl))));
								}
								for (float i = x2; i < x3; i += cl)
									if (Equa_6(a, b, c, d, e, i) >= 0 || fabs(Equa_6(a, b, c, d, e, i)) <= epsilon)
										if (Equa_6(a, b, c, d, e, i + cl) >= 0 || fabs(Equa_6(a, b, c, d, e, i + cl)) <= epsilon)
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(i + cl, sqrt(fabs(Equa_6(a, b, c, d, e, i + cl))));
										}
										else
										{
											glVertex2f(i, sqrt(fabs(Equa_6(a, b, c, d, e, i))));
											glVertex2f(x3, sqrt(fabs(Equa_6(a, b, c, d, e, x3))));
										}
							}
						}
					}
				}
			}
		}
	}
	glEnd();
}

float min(float a, float b)
{
	if (a < b) return a;
	return b;
}

void PT24(float a, float b)
{
	glColor3f(0, 1, 1);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, fabs(Equa_1(a, b, i)));
		glVertex2f(i + cl, min(yMax, fabs(Equa_1(a, b, i + cl))));
	}
	glEnd();
}

void PT25(float a, float b, float c)
{
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	for (float i = xMin; i < xMax; i += cl)
	{
		glVertex2f(i, fabs(Equa_2(a, b, c, i)));
		glVertex2f(i + cl, min(yMax, fabs(Equa_2(a, b, c, i + cl))));
	}
	glEnd();
}

void PT26(float a, float b, float c, float d)
{
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, fabs(Equa_3(a, b, c, d, i)));
		glVertex2f(i + cl, min(yMax, fabs(Equa_3(a, b, c, d, i + cl))));
	}
	glEnd();
}

void PT27(float a, float b, float c)
{
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	for (float i = xMin; i < xMax; i += cl)
	{
		glVertex2f(i, fabs(Equa_4(a, b, c, i)));
		glVertex2f(i + cl, min(yMax, fabs(Equa_4(a, b, c, i + cl))));
	}
	glEnd();
}

void PT28(float a, float b, float c, float d)
{
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, fabs(Equa_5(a, b, c, d, i)));
		glVertex2f(i + cl, min(yMax, fabs(Equa_5(a, b, c, d, i + cl))));
	}
	glEnd();
}

void PT29(float a, float b, float c, float d, float e)
{
	glColor3f(1, 0, 1);
	glBegin(GL_LINES);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, fabs(Equa_6(a, b, c, d, e, i)));
		glVertex2f(i + cl, min(yMax, fabs(Equa_6(a, b, c, d, e, i + cl))));
	}
	glEnd();
}

void Display(void)
{
	/* draw unit square polygon */
	glBegin(GL_LINES);
	glColor3f(0.1, 0.1, 0.1);
	for (float i = xMin; i <= xMax; i += cl * 10)
		if (i != 0)
		{
			glVertex2f(i, yMin);
			glVertex2f(i, yMax);
		}
	for (float i = yMin; i <= yMax; i += cl * 10)
		if (i != 0)
		{
			glVertex2f(xMin, i);
			glVertex2f(xMax, i);
		}
	glLineWidth(2);
	glColor3f(1, 1, 1);
	glVertex2f(0, yMin);
	glVertex2f(0, yMax);
	glVertex2f(xMin, 0);
	glVertex2f(xMax, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(-cl * 10, yMax - 10 * cl);
	glVertex2f(0, yMax);
	glVertex2f(cl * 10, yMax - 10 * cl);
	glVertex2f(xMax - 10 * cl, -cl * 5);
	glVertex2f(xMax, 0);
	glVertex2f(xMax - 10 * cl, cl * 5);
	glEnd();
	for (int i = 0; i < NN; i++)
	{
		switch (arr_k[i])
		{
		case 1:
			PT1(arr_a[i], arr_b[i]);
			break;
		case 2:
			PT2(arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 3:
			PT3(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 4:
			PT4(arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 5:
			PT5(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 6:
			PT6(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		case 7:
			PT7(arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 8:
			PT8(arr_a[i], arr_b[i]);
			break;
		case 9:
			PT9(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 10:
			PT10(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		case 11:
			PT11(arr_a[i]);
			break;
		case 12:
			PT12(arr_a[i]);
			break;
		case 13:
			PT13();
			break;
		case 14:
			Sin();
			break;
		case 15:
			Cos();
			break;
		case 16:
			Tan();
			break;
		case 17:
			CoTan();
			break;
		case 18:
			PT18(arr_a[i], arr_b[i]);
			break;
		case 19:
			PT19(arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 20:
			PT20(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 21:
			PT21(arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 22:
			PT22(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 23:
			PT23(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		case 24:
			PT24(arr_a[i], arr_b[i]);
			break;
		case 25:
			PT25(arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 26:
			PT26(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 27:
			PT27(arr_a[i], arr_b[i], arr_c[i]);
			break;
		case 28:
			PT28(arr_a[i], arr_b[i], arr_c[i], arr_d[i]);
			break;
		case 29:
			PT29(arr_a[i], arr_b[i], arr_c[i], arr_d[i], arr_e[i]);
			break;
		default:
			break;
		}
	}
	glFlush();
}

void Init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* void glOrtho(float left, float right, float bottom, float top,
	float nearVal, float farVal); */
	glOrtho(xMin, xMax, yMin, yMax, -cl, cl);
}

void Draw(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700); // size of GL window
	glutInitWindowPosition(300, 0); // position of GL window on the screen
	glutCreateWindow("Ve Do Thi"); // create a GL window with the name passed as an argument
	Init(); // initialization function
	glutDisplayFunc(Display); // call display function
	glutMainLoop(); // loop until you close the application
}
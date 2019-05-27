#include <cmath>
#include "Equation.h"
#include <stdio.h>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Draw.h"
#define xMin -14
#define xMax 14
#define yMin -14
#define yMax 14
#define cl 0.02

void Sin()
{
	glColor3f(0.5, 1, 0);
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
	glColor3f(0, 1, 0.5);
	glBegin(GL_POINTS);
	for (float i = xMin; i <= xMax; i += cl)
	{
		glVertex2f(i, Equa_1(a, b, i));
	}
	glEnd();
}

void PT2(float a, float b, float c)
{
	glColor3f(0, 1, 0);
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
	glColor3f(1, 0.5, 0);
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
	glColor3f(1, 0, 0.5);
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
	glColor3f(0.7, 0.2, 0.4);
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
	/* void glOrtho(double left, double right, double bottom, double top,
	double nearVal, double farVal); */
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
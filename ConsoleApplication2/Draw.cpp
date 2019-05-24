//#include <glut.h> 
//#include <cmath>
//#define xMin -10
//#define xMax 10
//#define yMin -6
//#define yMax 6
//#define cl 0.02
//
//void Sin()
//{
//	glColor3f(0, 1, 0);
//	glBegin(GL_POINTS);
//	for (float i = xMin; i <= xMax; i += cl)
//	{
//		glVertex2f(i, sin(i));
//	}
//	glEnd();
//}
//
//void Cos()
//{
//	glColor3f(0, 0, 1);
//	glBegin(GL_POINTS);
//	for (float i = xMin; i <= xMax; i += cl)
//	{
//		glVertex2f(i, cos(i));
//	}
//	glEnd();
//}
//
//void Tan()
//{
//	glColor3f(1, 0, 0);
//	glBegin(GL_POINTS);
//	for (float i = xMin; i <= xMax; i += cl)
//	{
//		glVertex2f(i, tan(i));
//	}
//	glEnd();
//}
//
//void Display()
//{
//	/* draw unit square polygon */
//	glBegin(GL_LINES);
//	glColor3f(0.1, 0.1, 0.1);
//	for (float i = xMin; i <= xMax; i += cl * 10)
//	if (i != 0)
//	{
//		glVertex2f(i, yMin);
//		glVertex2f(i, yMax);
//	}
//	for (float i = yMin; i <= yMax; i += cl * 10)
//	if (i != 0)
//	{
//		glVertex2f(xMin, i);
//		glVertex2f(xMax, i);
//	}
//	glLineWidth(2);
//	glColor3f(1, 1, 1);
//	glVertex2f(0, yMin);
//	glVertex2f(0, yMax);
//	glVertex2f(xMin, 0);
//	glVertex2f(xMax, 0);
//	glEnd();
//	glBegin(GL_TRIANGLES);
//	glVertex2f(-cl * 10, yMax - 10 * cl);
//	glVertex2f(0, yMax);
//	glVertex2f(cl * 10, yMax - 10 * cl);
//	glVertex2f(xMax - 10 * cl, -cl * 5);
//	glVertex2f(xMax, 0);
//	glVertex2f(xMax - 10 * cl, cl * 5);
//	glEnd();
//	Sin();
//	Cos();
//	Tan();
//	glFlush();
//}
//
//void Init()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glColor3f(1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	/* void glOrtho(double left, double right, double bottom, double top,
//	double nearVal, double farVal); */
//	glOrtho(xMin, xMax, yMin, yMax, -cl, cl);
//}
//
//void Draw(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(800, 500); // size of GL window
//	glutInitWindowPosition(100, 100); // position of GL window on the screen
//	glutCreateWindow("Ve Do Thi"); // create a GL window with the name passed as an argument
//	Init(); // initialization function
//	glutDisplayFunc(Display); // call display function
//	glutMainLoop(); // loop until you close the application
//}
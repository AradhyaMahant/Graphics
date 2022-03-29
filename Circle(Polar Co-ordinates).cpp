#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int xc, yc, r;
void putpixel(int x, int y){
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}
void display(){
	float x, y;
	x = 0;
	y = r;
	float theta = 0;
	float inc = (float)1 / r;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(-20, 0);
	glVertex2i(20, 0);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0, -20);
	glVertex2i(0, 20);
	glEnd();
	float end = 3.14 / 4;
	float C = cos(inc);
	float S = sin(inc);
	while (theta <= end)
	{
		float temp = x;
		x = x * C - y * S;
		y = y * C + temp * S;			
		putpixel(x, y);
		theta = theta + inc;
	}
	glFlush();
}

void init(){
		glClearColor(0.7, 0.7, 0.7, 0.7);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-20, 20, -20, 20);
	}
	
int main(int argc, char* argv[]) {
		printf("Enter x coordinate of circle's centre:");
		scanf_s("%d", &xc);
		printf("Enter y coordinate of circle's centre:");
		scanf_s("%d", &yc);
		printf("Enter Radius of the circle:");
		scanf_s("%d", &r);
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(200, 100);
		glutCreateWindow("Circle using Polar Equation");
		init();
		glutDisplayFunc(display);
		glutMainLoop();
}

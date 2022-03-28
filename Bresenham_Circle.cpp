#include <GL/glut.h>
#include <stdio.h>
#include <math.h>


void init(void)
{
	glClearColor(1.4, 1.0, 1.8, 0.5);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 160.0, 0.0, 160.0);
}
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void Circle() {
	int x_mid = 80, y_mid = 80, r = 40;
	int x = 0, y = r;
	int d = 3 - (2*r);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.1, 0.1);
	while (x <= y) {
		setPixel(x_mid + x, y_mid + y);
		setPixel(x_mid + y, y_mid + x);
		setPixel(x_mid - x, y_mid + y);
		setPixel(x_mid + y, y_mid - x);
		setPixel(x_mid - x, y_mid - y);
		setPixel(x_mid - y, y_mid - x);
		setPixel(x_mid + x, y_mid - y);
		setPixel(x_mid - y, y_mid + x);
	if (d < 0)
		d += (2 * x) + 3;
	else {
		d += (2 * (x - y)) + 5;
		y -= 1;
	}
	x++;
}
	glFlush();
}
int main(int argc, char** argv) {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowPosition(0, 0);
		glutInitWindowSize(500, 500);
		glutCreateWindow("Circle using Bresenham Algorithm");
		init();
		glutDisplayFunc(Circle);
		glutMainLoop();
		return 0;
}

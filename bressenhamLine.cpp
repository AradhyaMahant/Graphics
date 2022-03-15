#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>

float x1, y1, x2, y2, m;
float dy, dx;

void Input(){
        printf("Enter the value of x1: ");
        scanf("%f", &x1);
        printf("Enter the value of y1: ");
        scanf("%f", &y1);
        printf("Enter the value of x2: ");
        scanf("%f", &x2);
        printf("Enter the value of y2: ");
        scanf("%f", &y2);
        dx=x2-x1;
        dy=y2-y1;
        m=dy/dx;
}

void MyInit(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}
void Draw(){
	glBegin(GL_POINTS);
	if(m>0 && m<=1){
        while(x1<=x2 && y1<=y2){
            x1=x1+1;
            y1=y1+m;
            glVertex2i(x1, y1);
            printf("%f %f", x1, y1);
        }
	}
    else if(m>1){
        while(x1<=x2 && y1<=y2){
            x1=x1+(1/m);
            y1=y1+1;
            glVertex2i(x1, y1);
            printf("%f %f", x1, y1);
        }
    }
    else if(m>=-1 && m<0){
        while(x1<=x2 && y1<=y2){
            x1=x1-1;
            y1=y1-m;
            glVertex2i(x1, y1);
            printf("%f %f", x1, y1);
        }
    }
    else if(m<-1){
        x1=x1-(1/m);
        y1=y1-1;
        glVertex2i(x1, y1);
        printf("%f %f", x1, y1);
    }
    glEnd();
    glFlush();
}

int main(int argC, char *argV[]){
	Input();

	glutInit(&argC, argV);
	glutInitWindowPosition(200, 250);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutCreateWindow("Line");

	MyInit();
	glutDisplayFunc(Draw);
	glutMainLoop();

	return 0;

}

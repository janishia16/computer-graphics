#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
float v[4][3]={{0,1,1},{1,0,0},{0,2,0},{-1,0,0}};
int m;
float x;
void display();
void triangle(float a[3],float b[3],float c[3]);
void div_tetr(float a[3],float b[3],float c[3],int m);
void tetra(int m);
void timer(int e)
{
	x+=2;
	glutPostRedisplay();
	glutTimerFunc(100,timer,0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
  	glOrtho(-3.0,3.0,-3.0,3.0,-10.0,10.0);
  	glPushMatrix();
  	glRotatef(x,1.0,0.0,0.0);
	tetra(m);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void triangle(float a[3],float b[3],float c[3])
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
	glFlush();
}
void div_tetr(float a[3],float b[3],float c[3],int m)
{
	float v1[3],v2[3],v3[3];
	int j;
	if(m>0)
	{
		for(j=0;j<3;j++)
		{
			v1[j]=(a[j]+b[j])/2;
			v2[j]=(a[j]+c[j])/2;
			v3[j]=(b[j]+c[j])/2;
		}
		div_tetr(a,v1,v2,m-1);
		div_tetr(v1,b,v3,m-1);
		div_tetr(v2,v3,c,m-1);
	}
	else
		triangle(a,b,c);
}
void tetra(int m)
{
	glColor3f(1.0,0.0,0.0);
	div_tetr(v[0],v[1],v[3],m);	
	
	glColor3f(0.0,1.0,0.0);
	div_tetr(v[0],v[2],v[3],m);
	
	glColor3f(0.0,0.0,1.0);
	div_tetr(v[0],v[1],v[2],m);
	
	glColor3f(0.0,0.0,1.0);
	div_tetr(v[1],v[2],v[3],m);
}


int main(int argc,char**argv)
{
	printf("enter the number of divisions:");
	scanf("%d",&m);
	glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(0,0);
   glutCreateWindow("4MT19CS060-LAB6");
   glClearColor(1.0,1.0,1.0,0);
   glutDisplayFunc(display);
   glEnable(GL_DEPTH_TEST);
   timer(0);
   glutMainLoop();
   return 0;
}


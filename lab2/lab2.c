#include<stdio.h>
#include<GL/glut.h>

int x=0,choice,theta,h=0,k=0;

void timer(int e)
{
	x++;
	glutPostRedisplay();
	glutTimerFunc(100,timer,0);
}

void draw_triangle()
{
	glColor3f(0.0,0.0,1.0);
	glLineWidth(5.0);
	
	glBegin(GL_LINE_LOOP);
	glVertex2i(120,120);
	glVertex2i(160,160);
	glVertex2i(200,120);
	glEnd();

}

void display_fixedpoint(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glPushMatrix();
	glTranslatef(h,k,0);
	glRotatef(x,0,0,1);
	glTranslatef(-h,-k,0);
	draw_triangle();
	glPopMatrix();
	glFlush();

}

void display_orgin(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glPushMatrix();
	
	//glRotatef(x,0,0,1);
	glRotatef(theta,0,0,1);
	
	draw_triangle();
	glPopMatrix();
	glFlush();
}
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-200.0,500.0,-100.0,500.0,-500.0,500.0);
	
		
}
int main(int argc,char ** argv)
{
	printf("enter the choice: \n 1.fixedpoint \n 2.orgin \n");
	scanf("%d",&choice);
	printf("Angle of rotation:");
	scanf("%d",&theta);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(10,50);
	
	
	switch(choice)
	{
		case 1:	printf("enter the fixed point:");
					scanf("%d %d",&h,&k);
					
					glutCreateWindow("fixedpoint");
					glutDisplayFunc(display_fixedpoint);
					init();
					timer(0);
					glutMainLoop();
					
		case 2: 	glutCreateWindow("orgin");
					glutDisplayFunc(display_orgin);
					init();
					//timer(0);
					glutMainLoop();
					
		default: printf("invalid");
					init();
					glutMainLoop();
	}
	
}


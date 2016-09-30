#include <GL/glut.h>
// hering illisuon ( two lines with many coming out of the center. )
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0,0.0,0.0,0.0);	
	glBegin(GL_POINTS);		
	
	glVertex2i(5,5);
	
			
	glEnd();
	glFlush();
	
}
int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(400,400);                 
glutInitWindowPosition(500,200);			 
glutCreateWindow("sample");
glClearColor(1.0,1.0,1.0,0.0); 
gluOrtho2D(0.0,400.0,0.0,400.0);
glutDisplayFunc(display);
glutMainLoop(); 
return 0;
}
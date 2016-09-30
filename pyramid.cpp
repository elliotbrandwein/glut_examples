#include <GL/glut.h>
// pyramid illusion 
void draw_rectange (int deltaX, int deltaY, double deltaColor)
{
	glColor4f(0.0,0.0+deltaColor,0.0+deltaColor,0.0);	
	int stopX = 401-(deltaX*2);
	int stopY = 400-(deltaY*2);
	for( int y = 0; y< stopY ;y++)
	{
		for ( int x = 0; x<stopX; x++)
		{
			glVertex2i(x+deltaX,y+deltaY);
		}
	}
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0,0.0,0.0,0.0);	
	glBegin(GL_POINTS);		
	int deltaX = 0;
	int deltaY = 0;
	double deltaColor = 0.0;
	for (int i = 0; i< 20; i++)
	{
		draw_rectange(deltaX, deltaY, deltaColor);
		deltaX += 10;
		deltaY += 10;
		deltaColor += 0.03 ;
	}
	glEnd();
	glFlush();
	
}
int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(400,400);                 
glutInitWindowPosition(900,200);			 
glutCreateWindow("sample");
glClearColor(1.0,1.0,1.0,0.0); 
gluOrtho2D(0.0,400.0,0.0,400.0);
glutDisplayFunc(display);
glutMainLoop(); 
return 0;
}
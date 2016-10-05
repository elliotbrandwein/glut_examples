#include <GL/glut.h>
// hering illisuon ( two lines with many coming out of the center. )


void draw_line(int y)
{
	glBegin(GL_LINE_STRIP);	
	glVertex2i(0+y,0);
	glVertex2i(800-y,400);
	glEnd();

}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	

	// draws the two big parallel lines
	
	
	

	// draws the lines going through the two big parallel lines

	
	glColor4f(0.0,0.0,1.0,0.0); // blue

	for( int y = 0; y <800 ; y+=50)
	{
		draw_line(y);
		draw_line(y+600);
		draw_line(y-600);
	}
		glColor4f(1.0,0.0,0.0,0.0);	// red
		
	int Y_DIFF = 100;
		for (int y = 0; y<6; y++ )
	{
		glBegin(GL_LINE_LOOP);	
		glVertex2i(0,y+150);
		glVertex2i(800,y+150);
		glEnd();
	}
	for (int y = 0; y<6; y++ )
	{
		glBegin(GL_LINE_LOOP);	
		glVertex2i(0,y+150+Y_DIFF);
		glVertex2i(800,y+150+Y_DIFF);
		glEnd();
	}	
	
	glFlush();
	
}
int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(800,400);                 
glutInitWindowPosition(500,200);			 
glutCreateWindow("sample");
glClearColor(1.0,1.0,1.0,0.0); 
gluOrtho2D(0.0,800.0,0.0,400.0);
glutDisplayFunc(display);
glutMainLoop(); 
return 0;
}

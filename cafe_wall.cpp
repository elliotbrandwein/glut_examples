#include <GL/glut.h>
// cage wall illusion.  
void draw_square(int deltaX, int deltaY)
{
	for ( int x = 10+ deltaX; x< 40+deltaX;x++)
	{
		for( int y = 5+deltaY; y<45+deltaY; y++)
		{	
			glVertex2i(x,y);
		}
	}		
}
void draw_line(int deltaY)
{
	glColor4f(0.6,0.6,0.6,0.0);
	for(int x = 0; x<400; x++)
		{
			glVertex2i(x,45+deltaY);
		}
	glColor4f(0.0,0.0,0.0,0.0);	
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0,0.0,0.0,0.0);	
	glBegin(GL_POINTS);		
	bool keep = true;
	int move_x = 0;
	int move_y = 40;
	int wobble = 0;
	int line = 0;
	draw_line(0);
	while(keep)
	{
		wobble++;
		line++;
		draw_square(move_x, move_y);
		if ( line%6 ==0) draw_line(move_y);
		move_x += 60;
		if ( move_x >=350)
		{
			move_x = 0;
			move_y+= 41;
		}

		if (move_x>= 400 || move_y >=400 ){
			keep = false;
		}
		if( wobble % 6 == 0)move_x+=10;
		if( wobble % 12 == 0) move_x+=10; 
	}	
			
	glEnd();
	glFlush();
	
}
int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(400,420);                 
glutInitWindowPosition(500,200);			 
glutCreateWindow("sample");
glClearColor(1.0,1.0,1.0,0.0); 
gluOrtho2D(0.0,400.0,0.0,420.0);
glutDisplayFunc(display);
glutMainLoop(); 
return 0;
}
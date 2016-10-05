#include <GL/glut.h>
// cage wall illusion.  

// this draws exactly one square per call. 
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
// this draws the one-pixel depth line all the way down image. its not a line loop
void draw_line(int deltaY)
{
	glColor4f(0.6,0.6,0.6,0.0);
	for(int x = 0; x<401; x++)
		{
			glVertex2i(x,45+deltaY);
		}
	glColor4f(0.0,0.0,0.0,0.0);	
}
// the man display function
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0,0.0,0.0,0.0);	
	glBegin(GL_POINTS);		
	// set-up
	bool keep = true;
	int move_x = 0;
	int move_y = 40;
	int wobble = 0;
	int line = 0;
	draw_line(0);
	// main drawing-loop
	while(keep)
	{
		wobble++;
		line++;
		// draws the sqaures
		draw_square(move_x, move_y);
		// if there are 5 squares already, draw the line over the squares. 
		if ( line%6 ==0) draw_line(move_y);
		// always move the drawing of each square over by the length of a square
		move_x += 60;
		// if I have moved passed where I want to stop, reset the x and move up a row
		if ( move_x >=350)
		{
			move_x = 0;
			move_y+= 41;
		}
		// if I have moved too far off the image, I know I am done and I will stop . 
		if (move_x>= 401 || move_y >=400 ){
			keep = false;
		}
		// these two ifs deal with "wobbling" the image so the squares start and stop at different spots.
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
// Elliot Brandwein
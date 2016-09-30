#include <GL/glut.h>
// herman illusion, 5x5 grid. 
void draw_square(int deltaX, int deltaY)
{
	for ( int x = 10+ deltaX; x< 60+deltaX;x++)
	{
		for( int y = 10+deltaY; y<60+deltaY; y++)
		{	
			glVertex2i(x,y);
		}
	}		
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0,0.0,0.0,0.0);	
	glBegin(GL_POINTS);		
	bool keep = true;
	int move_x = 30;
	int move_y = 30;
	while(keep)
	{
		draw_square(move_x, move_y);
		move_x += 60;
		if ( move_x >=300)
		{
			move_x = 30;
			move_y+= 60;
		}

		if (move_x>= 300 || move_y >=300 ){
			keep = false;
		} 
	}	
			
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
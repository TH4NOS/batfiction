#include"headerfiles.h"

static int prev=115;
int NUM_OF_TESTS = 100000;
struct object batman,joker,level1,missile,batwing;

static int bx1,by1,rx1,ry1,rx2,ry2,rx3,ry3,page=0;
int minx=16;
int miny=16;
int mval=30;
int size=30;
int maxx=273,maxy=163;
int dx1=1,dy1=1,dx2=1,dy2=1,dx3=1,dy3=1;

void collisioncheck()
{
	//collision
	
	int a=bx1-size;
	int b=bx1+size;
	int c=by1-size;
	int d=by1+size;
	
	if((rx1>=a&&rx1<=b&&ry1>=c&&ry1<=d)||(rx2>=a&&rx2<=b&&ry2>=c&&ry2<=d)||(rx3>=a&&rx3<=b&&ry3>=c&&ry3<=d))
	exit(0);
}

void passive(int x,int y)
{
	
	
		if(y<(maxy)&&y>(0+miny)&&x<(maxx)&&x>(0+minx))
		
		{
			by1=y;
			bx1=x;
			batwingmove(x,y);
			collisioncheck();
			glutPostRedisplay();
		}
	
}

void display(void)
{
// glClearColor(0.0,0.0,1.0,1.0);
 //glClear(GL_COLOR_BUFFER_BIT);
 batlvl2();
 checkmissile();
 batwingmove(0,0);
 checkmissile();
 missilemove();
 checkmissile();
 batwingmove(0,0);
 checkmissile();
  switch(rand() % 35) 
     {
      case 0: launchbatwingmissile(); break;
     }
 glFlush();
}
void keyboard(unsigned char key,int x,int y)
{  

  switch(rand() % 35) 
     {
      case 0: launchbatwingmissile(); break;
     }
  batlvl2();
 checkmissile();
  missilemove();
  checkmissile();
  if(key==27) exit(0);
  else if (key==119 && batwing.y<163) {batwingmove(0,1);}
  else if (key==101 && batwing.x<279 && batwing.y<163) {batwingmove(1,1);}
  else if (key==113 && batwing.x>16 && batwing.y<163) {batwingmove(-1,1);}
  /*else if (key==32)  
    {
     if (prev==97) {batjumpside(-1);}
     else if (prev==100) {batjumpside(1);}
     else {batjump();}
    }*/
  else if (key==97 && batwing.x>16)  {batwingmove(-1,0);}
  else if (key==100 && batwing.x<279) {batwingmove(1,0);} 
  else if (key==115 && batwing.y>16) {batwingmove(0,-1);}
  else {cout<<"key entered "<<key<<endl;}
  checkmissile();
  glFlush();
  fflush(stdin);
  prev=key;
 // glutPostRedisplay();
 // batlvl2();
  //cout<<batman.x<<" "<<batman.y<<endl;
}

int main(int argc, char** argv)
{
 initstruct();
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutCreateWindow("test");
 glutFullScreen();
 gluOrtho2D(0,1366,0,768);
 glutDisplayFunc(display);
 glutIdleFunc(display);
 glutKeyboardFunc(keyboard);
 glutPassiveMotionFunc(passive);
 glutMainLoop();
 return 0;
}































/*
static int bx1,by1,rx1,ry1,rx2,ry2,rx3,ry3,page=0;
int minx=16;
int miny=16;
int mval=30;
int size=30;
int maxx=273,maxy=163;
int dx1=1,dy1=1,dx2=1,dy2=1,dx3=1,dy3=1;

void collisioncheck()
{
	//collision
	
	int a=bx1-size;
	int b=bx1+size;
	int c=by1-size;
	int d=by1+size;
	
	if((rx1>=a&&rx1<=b&&ry1>=c&&ry1<=d)||(rx2>=a&&rx2<=b&&ry2>=c&&ry2<=d)||(rx3>=a&&rx3<=b&&ry3>=c&&ry3<=d))
	exit(0);
}

void passive(int x,int y)
{
	
	
		if(y<(maxy-miny)&&y>(0+miny)&&x<(maxx-minx)&&x>(0+minx))
		
		{
			by1=y;
			bx1=x;
			batwingmove(x,y);
			collisioncheck();
			glutPostRedisplay();
		}
	
}
*/



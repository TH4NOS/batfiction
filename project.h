int SCREENx=1366;
int SCREENy=768;

struct object
{ 
 float left,top,right,bottom; 
 int sizeofbox;    // size of box to display object
 int rows,cols;   // no of rows and cols to display object
 int x,y;   //each objects x and y position
};

extern object batman,joker,level1,missile,batwing;

void initstruct()
{
//size of box to display object
batman.sizeofbox=4;
joker.sizeofbox=4;
level1.sizeofbox=32;
missile.sizeofbox=0.5;
batwing.sizeofbox=4;

//rows and cols for each object
batman.rows=31;batman.cols=18;
joker.rows=26;joker.cols=20;
level1.rows=24;level1.cols=43;
missile.rows=5;missile.cols=10;
batwing.rows=12;batwing.cols=49;

//x and y coordinate for each object
batman.x=10;batman.y=30;
joker.x=50;joker.y=30;
level1.x=0;level1.y=0;
missile.x=300;missile.y=int(batman.y+int(batman.rows/2));
batwing.x=20;batwing.y=30;
}

void DrawRectangle(double x1, double y1, double x2, double y2)
{
	glBegin(GL_QUADS);
	glVertex2d(x1,y1);
	glVertex2d(x2,y1);
	glVertex2d(x2,y2);
	glVertex2d(x1,y2);
	glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glEnd();
}

void resolutionfix()
{
 // Let's start by clearing the whole screen with black
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
// Both these values must be your real window size, so of course these values can't be static
int screen_width = 1366;  
int screen_height = 768; 
 
// This is your target virtual resolution for the game, the size you built your game to
int virtual_width=1366;
int virtual_height=768;
 
float targetAspectRatio = virtual_width/virtual_height;
 
// figure out the largest area that fits in this resolution at the desired aspect ratio
int width = screen_width ;
int height = (int)(width / targetAspectRatio + 0.5f);
 
if (height > screen_height )
{
   //It doesn't fit our height, we must switch to pillarbox then
    height = screen_height ;
    width = (int)(height * targetAspectRatio + 0.5f);
}
 
// set up the new viewport centered in the backbuffer
int vp_x = (screen_width  / 2) - (width / 2);
int vp_y = (screen_height / 2) - (height/ 2);
 
glViewport(vp_x,vp_y,width,height);
// This pops those matrices for the scale transformations.

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPopMatrix();
glMatrixMode(GL_PROJECTION);
glPopMatrix();   
glMatrixMode(GL_MODELVIEW);
glPopMatrix();
}

void output(int x, int y, float r, float g, float b, void* font, char st[])
{
 /*
  choose one of these fonts
GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18  
 */
/*
 string c="Hello world";
 const int d=c.length();
 char ch[d];
 for(int i=0;i<d;i++)
  {ch[i]=c[i];}
 //glColor3f(1,0,0);
 output(100,100,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,ch);
*/
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len = strlen(st);
  for (int i = 0; i < len; i++) 
  {
    glutBitmapCharacter(font, int(st[i]));
  }
}


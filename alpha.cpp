#include<iostream>
#include<cstring>
#include<GL/glut.h>
using namespace std;

void output(int x, int y, float r, float g, float b, void* font, char st[])
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len = strlen(st);
  for (int i = 0; i < len; i++) 
  {
    glutBitmapCharacter(font, int(st[i]));
  }
}

void display(void)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 //resolutionfix();
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
 string c="Hello world";
 const int d=c.length();
 char ch[d];
 for(int i=0;i<d;i++)
  {ch[i]=c[i];}
 //glColor3f(1,0,0);
 output(100,100,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,ch);
 glFlush();
}


void keyboard(unsigned char key, int x, int y)
{
 if(key==27) exit(0);
 else cout<<"You pressed "<<key<<endl;
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutCreateWindow("test");
 glutFullScreen();
 gluOrtho2D(0,1366,0,768);
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}

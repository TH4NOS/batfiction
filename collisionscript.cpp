#include<iostream>
#include<fstream>
#include<ostream>
#include<GL/glut.h>
#include<vector>
#include<cstdio>
#include<unistd.h>
using namespace std;

static int d=10,e=10;

void resolutionfix();

void drawsquare(int x, int y, char color, int size_of_box)
{
 int size_of_box=4;
 x*=size_of_box;y*=size_of_box;
 if (color=='G')   glColor3f(0.5,0.5,0.5);
 else if (color=='B')   glColor3f(0.0,0.0,0.0);
 else if (color=='Y')   glColor3f(1.0,1.0,0.0);
 else if (color=='W')   glColor3f(1.0,1.0,1.0);
 else if (color=='F')   glColor3f(0.96,0.80,0.69);
 else if (color=='M')   glColor3f(0.5,0.35,0.05);
 else glColor3f(0.0,0.0,1.0);
 glBegin(GL_POLYGON);
        glVertex2f(x, y);	
        glVertex2f(x, y+size_of_box);
        glVertex2f(x+size_of_box, y+size_of_box);
        glVertex2f(x+size_of_box, y);
 glEnd();
}




void display(void)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_stand(0,0); 
// batmanbk_stand()
// batman_walk();*/
 glFlush();
}

void move(int x,int y)
{
float d=50000;
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
static int k=0;
if(k%2==0)   
  {
     batman_stand(x,y);
     for(float d=0;d<5000000;d++);
     glFlush();
  }
else   
   {
     batman_walk(x,y);
     for(float d=0;d<5000000;d++);
     glFlush();
   }
k++;
fflush(stdin);
}

void jump()
{
 float d=10000;
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_stand(0,1);
 glFlush();
 usleep(d);
 glutTimerFunc(1,Timer,1);
for(int i=0;i<20;i++)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_jump(0,1);
 glFlush();
 usleep(d);
}
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_stand(0,0);
 glFlush();
 usleep(d);
for(int i=0;i<20;i++)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_jump(0,-1);
 glFlush();
 usleep(d);
}
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_stand(0,-1);
 glFlush();
 fflush(stdin);
}

void jumpside(int k)
{
 float d=10000;
for(int i=0;i<20;i++)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_jump(0,1);
 glFlush();
 usleep(d);
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_walk(k,0);
 glFlush();
 usleep(d);
 
}
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_stand(0,0);
 glFlush();
 usleep(d);
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_walk(k,0);
 glFlush();
 usleep(d);
 
for(int i=0;i<20;i++)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_jump(0,-1);
 glFlush();
 usleep(d);
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_walk(k,0);
 glFlush();
 usleep(d);
 }
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_stand(0,-1);
 glFlush();
 fflush(stdin);

}


static int prev=115;
void keyboard(unsigned char key,int x,int y)
{
  if(key==27) exit(0);
 // else if (key==119) {move(0,1);}
 // else if (key==101) {move(1,1);}
 // else if (key==113) {move(-1,1);}
  else if (key==32)  
    {
     if (prev==97) {jumpside(-1);}
     else if (prev==100) {jumpside(1);}
     else {jump();}
    }
  else if (key==97)  {move(-1,0);}
  else if (key==100) {move(1,0);}
  //else if (key==115) {move(0,-1);}
  else {cout<<"key entered "<<key<<endl;}
  fflush(stdin);prev=key;
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
 batst.erase(batst.begin(),batst.end());
 batstbk.erase(batstbk.begin(),batstbk.end());
 batwlk.erase(batwlk.begin(),batwlk.end());
 batwlk1.erase(batwlk1.begin(),batwlk1.end());
 batwlk2.erase(batwlk2.begin(),batwlk2.end());
 return 0;
}

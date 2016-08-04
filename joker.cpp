#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<cstdio>
using namespace std;

vector<string> jokerst;
vector<string> jokerwlk;

void resolutionfix();

void drawsquare(int x, int y, char color)
{x*=10;y*=10;
 int size_of_box=10;
 if (color=='G')        glColor3f(0.0,0.9,0.0);
 else if (color=='B')   glColor3f(0.0,0.0,0.0);
 else if (color=='E')   glColor3f(0.0,0.0,0.7);
 else if (color=='W')   glColor3f(1.0,1.0,1.0);
 else if (color=='D')   glColor3f(0.0,0.5,0.0);
 else if (color=='P')   glColor3f(0.7,0.0,0.7);
 else if (color=='R')   glColor3f(1.0,0.0,0.0);

 else glColor3f(0.0,1.0,1.0);
 glBegin(GL_POLYGON);
        glVertex2f(x, y);	
        glVertex2f(x, y+size_of_box);
        glVertex2f(x+size_of_box, y+size_of_box);
        glVertex2f(x+size_of_box, y);
 glEnd();
}
// B-BLACK
// W-WHITE
// E-BLUE
// D-DARKGREEN
// G-LIGHTGREEN
// P-PURPLE
// R-RED
void jokerinit()
{
jokerst.push_back("BBBBBBBBB   BBBBBBBBB");
jokerst.push_back("BBWWBBBBB   BBBBBWWBB");
jokerst.push_back(" BBBEEEEB   BEEEEBBB ");
jokerst.push_back("   BBEEEEB BEEEEBB   ");
jokerst.push_back("    BEEEEEBEEEEEB    ");
jokerst.push_back(" BBB BEEEGEGEEEB BBB ");
jokerst.push_back(" BBBB BEGGGGGEB BBBB ");
jokerst.push_back(" BB B BGGGGGGGB B BB ");
jokerst.push_back(" BBB  BGGGGGGGB  BBB ");
jokerst.push_back(" BPPB BGGGWGGGB BPPB ");
jokerst.push_back(" BPPPBBGGPWPGGBBPPPB ");
jokerst.push_back("  BPPPPGGPBBBBGPPPB  ");
jokerst.push_back("   BPPPGGBWWWWBPPB   ");
jokerst.push_back("    BPGGBWRRRRRBB    ");
jokerst.push_back("     BBBWRRRRRRRB    ");
jokerst.push_back("      BWBWWWWWWWB    ");
jokerst.push_back("    BBDWWWBBBWBBB    ");
jokerst.push_back("   BDDWWBBWWBWBWB    ");
jokerst.push_back("    BDWDWBBBWWWBB    ");
jokerst.push_back("    BDDDWWBWWWWWB    ");
jokerst.push_back("     BDDDWWWWWWWDB   ");
jokerst.push_back("    BDDDDDWWDWWWDB   ");
jokerst.push_back("     BBDDWWDDDWDB    ");
jokerst.push_back("       BDDDDDDDB     ");
jokerst.push_back("      BDDBDDDDB      ");
jokerst.push_back("       BB BBBB       ");
}

void jokermoveinit()
{
jokerwlk.push_back("");
}


void joker_stand(void)
{
jokerinit();
 for(int i=0; i<26;i++)
 {
  for(int j=0;j<20;j++)
   {
    drawsquare(j+10,i+10,jokerst[i][j]);
   }
 }
}

void joker_walk(void)
{
jokermoveinit();
 for(int i=0; i<26;i++)
 {
  for(int j=0;j<20;j++)
   {
    drawsquare(j+80,i+10,jokerwlk[i][j]);
   }
 }
}


void display(void)
{
 glClearColor(0.0,1.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 //resolutionfix();
 joker_stand(); 
 //joker_walk();
 glFlush();
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
 jokerst.erase(jokerst.begin(),jokerst.end());
 jokerwlk.erase(jokerwlk.begin(),jokerwlk.end());
 return 0;
}

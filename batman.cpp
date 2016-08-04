#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<cstdio>
using namespace std;

vector<string> batst;
vector<string> batstbk;
vector<string> batwlk;

void resolutionfix();

void drawsquare(int x, int y, char color)
{x*=10;y*=10;
 int size_of_box=10;
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

void batmaninit()
{
batst.push_back("    GBBGGBBG    ");
batst.push_back("    BGGBBGGB    ");
batst.push_back("    BBGBBGBB    ");
batst.push_back("    GBGBBGBG    ");
batst.push_back("    WGBGGBGW    ");
batst.push_back("    GWGWWGWG    ");
batst.push_back("    WGWWWWGW    ");
batst.push_back("    WWWWWWWW    ");
batst.push_back("    WWWWWWWW    ");
batst.push_back("    WWWBBWWW    ");
batst.push_back("    WBGGGGBW    ");
batst.push_back("BBGBGGGGGGGGBGBB");
batst.push_back("BGGBYYBYYBYYBBGB");
batst.push_back("BBBWYYBYYBYYWBBB");
batst.push_back("BBWWYYGYYGYYWWBB");
batst.push_back("BWWWGWWWWWWGWWWB");
batst.push_back("WWWWGWWWWWWGWWWW");
batst.push_back("WGGWGWWBBWWGWGGW");
batst.push_back("GWWGWBBBBBBWGWWG");
batst.push_back("WWWWBBBWWBBBWWWW");
batst.push_back("BWWWWWWWWWWWWWWB");
batst.push_back("BBBWBBWWWWBBWBBB");
batst.push_back("BBBBBBBBBBBBBBBB");
batst.push_back("    BFFMMFFB    ");
batst.push_back("    BFFFFFFB    ");
batst.push_back("    BBBFFBBB    ");
batst.push_back("    BBBBBBBB    ");
batst.push_back("    BWWBBWWB    ");
batst.push_back("    BBBBBBBB    ");
batst.push_back("    BBBBBBBB    ");
batst.push_back("    B      B    ");
}


void batmanbackinit()
{
batstbk.push_back("    BBBGGBBB    ");
batstbk.push_back("    GBGBBGBG    ");
batstbk.push_back("    BBGBBGBB    ");
batstbk.push_back("    GBGBBGBG    ");
batstbk.push_back("    BBWGGWBB    ");
batstbk.push_back("    WWWWWWWW    ");
batstbk.push_back("    WWWWWWWW    ");
batstbk.push_back("    WWWBBWWW    ");
batstbk.push_back("    WWWBBWWW    ");
batstbk.push_back("    WBBBBBBW    ");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("BBGBBBBBBBBBBGBB");
batstbk.push_back("BGGBBBBBBBBBBBGB");
batstbk.push_back("BBBWBGBBBBGBWBBB");
batstbk.push_back("BBWWBGBBBBGBWWBB");
batstbk.push_back("BWWWBGBBBBGBWWWB");
batstbk.push_back("WWWWBGBBBBGBWWWW");
batstbk.push_back("WGGWBGBBBBGBWGGW");
batstbk.push_back("GWWGBGBBBBGBGWWG");
batstbk.push_back("WWWWBGBBBBGBWWWW");
batstbk.push_back("BWWWBGBBBBGBWWWB");
batstbk.push_back("BBBBBBBBBBBBBBBB");
batstbk.push_back("BBBBBBBBBBBBBBBB");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("    BBBBBBBB    ");
batstbk.push_back("    B      B    ");
}

void batmanmoveinit()
{
batwlk.push_back("GBBG        GBBG");
batwlk.push_back("BGGB        BGGB");
batwlk.push_back(" BBGB      BGBB ");
batwlk.push_back(" GBGB      BGBG ");
batwlk.push_back("  WGBG    GBGW  ");
batwlk.push_back("  GWGW    WGWG  ");
batwlk.push_back("   WGWW  WWGW   ");
batwlk.push_back("   WWWW  WWWW   ");
batwlk.push_back("   WWWW  WWWW   ");
batwlk.push_back("    WWWBBWWW    ");
batwlk.push_back("    WBGGGGBW    ");
batwlk.push_back("BBGBGGGGGGGGBGBB");
batwlk.push_back("BGGBYYBYYBYYBBGB");
batwlk.push_back("BBBWYYBYYBYYWBBB");
batwlk.push_back("BBWWYYGYYGYYWWBB");
batwlk.push_back("BWWWGWWWWWWGWWWB");
batwlk.push_back("WWWWGWWWWWWGWWWW");
batwlk.push_back("WGGWGWWBBWWGWGGW");
batwlk.push_back("GWWGWBBBBBBWGWWG");
batwlk.push_back("WWWWBBBWWBBBWWWW");
batwlk.push_back("BWWWWWWWWWWWWWWB");
batwlk.push_back("BBBWBBWWWWBBWBBB");
batwlk.push_back("BBBBBBBBBBBBBBBB");
batwlk.push_back("    BFFMMFFB    ");
batwlk.push_back("    BFFFFFFB    ");
batwlk.push_back("    BBBFFBBB    ");
batwlk.push_back("    BBBBBBBB    ");
batwlk.push_back("    BWWBBWWB    ");
batwlk.push_back("    BBBBBBBB    ");
batwlk.push_back("    BBBBBBBB    ");
batwlk.push_back("    B      B    ");
}


void batman_stand(void)
{
batmaninit();
 for(int i=0; i<31;i++)
 {
  for(int j=0;j<16;j++)
   {
    drawsquare(j+10,i+10,batst[i][j]);
    cout<<batst[i][j];
   }
  cout<<endl;
 }
}


void batmanbk_stand(void)
{
batmanbackinit();
 for(int i=0; i<31;i++)
 {
  for(int j=0;j<16;j++)
   {
    drawsquare(j+40,i+10,batstbk[i][j]);
    cout<<batst[i][j];
   }
  cout<<endl;
 }
}

void batman_walk(void)
{
batmanmoveinit();
 for(int i=0; i<31;i++)
 {
  for(int j=0;j<16;j++)
   {
    drawsquare(j+80,i+10,batwlk[i][j]);
    cout<<batst[i][j];
   }
  cout<<endl;
 }
}


void display(void)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 //resolutionfix();
 batman_stand(); 
 batmanbk_stand();
 batman_walk();
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
 batst.erase(batst.begin(),batst.end());
 batstbk.erase(batstbk.begin(),batstbk.end());
 batwlk.erase(batwlk.begin(),batwlk.end());
 return 0;
}

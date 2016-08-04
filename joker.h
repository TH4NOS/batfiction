vector<string> jokerst;
void jokerdrawsquare(int x, int y, char color)
{

// B-BLACK
// W-WHITE
// E-BLUE
// D-DARKGREEN
// G-LIGHTGREEN
// P-PURPLE
// R-RED
 int size_of_box=joker.sizeofbox;
 x*=size_of_box;y*=size_of_box;
 if (color=='G')        glColor3f(0.0,0.9,0.0);
 else if (color=='B')   glColor3f(0.0,0.0,0.0);
 else if (color=='E')   glColor3f(0.0,0.0,0.7);
 else if (color=='W')   glColor3f(1.0,1.0,1.0);
 else if (color=='D')   glColor3f(0.0,0.5,0.0);
 else if (color=='P')   glColor3f(0.7,0.0,0.7);
 else if (color=='R')   glColor3f(1.0,0.0,0.0);
 else glColor3f(0.0,0.0,1.0);
 glBegin(GL_POLYGON);
        glVertex2f(x, y);	
        glVertex2f(x, y+size_of_box);
        glVertex2f(x+size_of_box, y+size_of_box);
        glVertex2f(x+size_of_box, y);
 glEnd();
}


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

void joker_stand(int x,int y)
{
jokerinit();
joker.x+=x;
joker.y+=y;
 for(int i=0; i<joker.rows;i++)
 {
  for(int j=0;j<joker.cols;j++)
   {
    jokerdrawsquare(j+joker.x,i+joker.y,jokerst[i][j]);
   }
 }
}

void jokermove(int x,int y)
{
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl2();
 joker_stand(x,y);
 for(float d=0;d<5000000;d++);
// glFlush();
 fflush(stdout);
}

void joker_erase()
{
 jokerst.erase(jokerst.begin(),jokerst.end());
}

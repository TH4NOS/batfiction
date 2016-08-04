vector<string> lvl1;

static int d=10,e=10;

void resolutionfix();

void drawlvlsquare(int x, int y, char color)
{
 int size_of_box=32;
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

void batlvl1init()
{
  lvl1.push_back("GGGBBGGGGGBBBBWWWWBBGGGGGWWGGGWWWGGGGGGGGGG");
  lvl1.push_back("GGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBGGG");
  lvl1.push_back("GGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBGGG");
  lvl1.push_back("BBBBGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBGGG");
  lvl1.push_back("BBBBBBBGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBBGGGGGGGGBBBBBBBBGGGGGGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBGGGGGGBBBBBBGGGGGGGGGGGGGG");
  lvl1.push_back("GGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGGGGGG");
  lvl1.push_back("GGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGG");
  lvl1.push_back("GGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGG");
  lvl1.push_back("GGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBGGGGGG");
  lvl1.push_back("BBBBBBBBGGGGGGGGGGGGGGGBBBBBBBBBBBBBBGGGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBBBGGGGGGGGGBBBBBBBBBBGGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBGGGGBBBBBBBBGGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGBBBBBBBBGGGG");
  lvl1.push_back("BBBBGGGGGGBBBGGGGGGGGGBBBBBBBBBGGGGGBBBGGGG");
  lvl1.push_back("GGGGGGGGGGBBBBBBBBBGGGGBBBBBBBBBBBBBBBBGGGG");
  lvl1.push_back("GGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGG");
  lvl1.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGGGG");
  lvl1.push_back("BBBBBBBBBBBGGGGGGGGBBBBBBBBBBBBBBBGGGGGGGGG");
  lvl1.push_back("BBBBBBGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");
  lvl1.push_back("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");  
}

void batlvl1()
{
batlvl1init();
 for(int i=0; i<24;i++)
 {
  for(int j=0;j<43;j++)
   {
    drawlvlsquare(j,i,lvl1[i][j]);
   }
 }
}


void display(void)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batlvl1(); 
 glFlush();
}

void keyboard(unsigned char key,int x,int y)
{
  if(key==27) exit(0);
  else {cout<<"key entered "<<key<<endl;fflush(stdin);}
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
 lvl1.erase(lvl1.begin(),lvl1.end());
 return 0;
}

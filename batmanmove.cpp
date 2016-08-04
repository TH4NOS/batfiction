void display(void)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batman_stand(0,0); 
// batmanbk_stand()
// batman_walk();*/
 glFlush();
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
 return 0;
}

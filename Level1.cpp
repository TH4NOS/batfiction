#include"headerfiles.h"

static int prev=115;

struct object batman,joker,level1,missile,batwing;


void display(void)
{
// glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman.x=400;
 batman.y=11;
 batman.sizeofbox=3;
 batman_stand(0,0);
// batmanbk_stand()
// batman_walk();*/
 glFlush();
}

void keyboard(unsigned char key,int x,int y)
{  batlvl1();	
  if(key==27) exit(0);
  else if (key==119) /*{if(!batmanlvlconstraintstop()                                 ) */batmove(0,1) ; /*else batmove(0,0);}*/
//  else if (key==101) /*{if(!batmanlvlconstraintsright() && !batmanlvlconstraintstop() ) */batmove(1,1) ; /*else batmove(0,0);}*/
//  else if (key==113) /*{if(!batmanlvlconstraintsleft()  && !batmanlvlconstraintstop() ) */batmove(-1,1); /*else batmove(0,0);}*/
  else if (key==97)  /*{if(!batmanlvlconstraintsleft()                                ) */batmove(-1,0); /*else batmove(0,0);}*/
  else if (key==100) /*{if(!batmanlvlconstraintsright()                               ) */batmove(1,0) ; /*else batmove(0,0);} */
  else if (key==115) /*{if(!batmanlvlconstraintsbottom()                              ) */batmove(0,-1); /*else batmove(0,0);}*/
  else if (key==32)  
    {
     if (prev==97) {batjumpside(-1);}
     else if (prev==100) {batjumpside(1);}
     else {batjump();}
    }
  else {cout<<"key entered "<<key<<endl;}
  glFlush();
  fflush(stdin);
  prev=key;
  cout<<batman.x<<" "<<batman.y<<endl;
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
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}

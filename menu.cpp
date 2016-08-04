#include"headerfiles.h"
struct object batman,joker,level1,missile,batwing;
static int prevkey=100;

void controls()
{
	 glClearColor(0.0,0.0,1.0,1.0);
         glClear(GL_COLOR_BUFFER_BIT);
         char a[50]="Use Keyboard keys to play";
         output(50,140,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,a);
	 char b[50]="W - to move upwards";
         output(50,120,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,b);
	 char c[50]="A - to move left";
         output(50,100,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,c);
	 char d[50]="S - to move down";
         output(50,80,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,d);
	 char e[50]="D - to move right";
         output(50,60,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,e);
	 char f[50]="E - to move top right";
         output(50,40,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,f);
	 char g[50]="Q - to move top left";
         output(50,20,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,g);
         glFlush();
}

void credits()
{
	 glClearColor(0.0,0.0,1.0,1.0);
         glClear(GL_COLOR_BUFFER_BIT);
         char a[50]="This is our Graphics Project";
         output(50,140,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,a);
	 char b[50]="BAT FICTION";
         output(50,120,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,b);
	 char c[50]="Developers are : ";
         output(50,100,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,c);
	 char d[50]="ADITHYA C    BL.EN.U4CSE12004";
         output(50,80,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,d);
	 char e[50]="GANESH B R   BL.EN.U4CSE12031";
         output(50,60,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,e);
	 char f[50]="HARISH R     BL.EN.U4CSE12042";
         output(50,40,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,f);
	 char g[50]="THANK YOU FOR PLAYING";
         output(50,20,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,g);
         glFlush();

}


void basicmenu()
{
glClearColor(0.0,0.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
         char a[50]="Use Keyboard to select menu";
         output(80,500,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,a);
	 char b[50]="W - to play the level";
         output(80,380,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,b);
	 char c[50]="A - to view controls";
         output(80,260,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,c);
	 char f[50]="D - to view basic menu";
         output(80,200,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,f);	
	 char d[50]="S - to credits";
         output(80,140,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,d);
 	 char e[50]="Esc to exit the code";
         output(80,80,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,e);
 	
 glFlush();
}

void display()
{
 if (prevkey==119)     {system("g++ missile.cpp -lGL -lglut -lGLU && ./a.out");}
 else if (prevkey==97) {controls();}
 else if (prevkey==115){credits();}
 else if (prevkey==100){basicmenu();}
 glFlush();
 batwingcollision();
}


void keyboard(unsigned char key, int w, int h)
{
 prevkey=key;
 if(key==27) exit(0);
 else if (key==119)     {system("g++ missile.cpp -lGL -lglut -lGLU && ./a.out");}
 else if (key==97)      {controls();}
 else if (key==115)     {credits();}
 else {cout<<"this "<<key<<" was pressed"<<endl;}
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
 glutIdleFunc(display);
 glutKeyboardFunc(keyboard);
 //dglutPassiveMotionFunc(passive);
 glutMainLoop();
 return 0;
}

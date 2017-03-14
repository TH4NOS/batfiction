#include "linkedlist.h"
vector<string> mis;


static int score=0;

void missiledrawsquare(int x, int y, char color)
{
// R-RED
 int size_of_box=joker.sizeofbox;
 x*=size_of_box;y*=size_of_box;
 if (color=='R')   glColor3f(1.0,0.0,0.0);
 else glColor3f(0.0,1.0,1.0);
 glBegin(GL_POLYGON);
        glVertex2f(x, y);	
        glVertex2f(x, y+size_of_box);
        glVertex2f(x+size_of_box, y+size_of_box);
        glVertex2f(x+size_of_box, y);
 glEnd();
}

single_llist mi;

void missileinit()
{
mis.push_back("    RRRRRR");
mis.push_back("  RRRRRRRR");
mis.push_back("RRRRRRRRRR");
mis.push_back("  RRRRRRRR");
mis.push_back("    RRRRRR");

}

static int k=0;

void missiledraw(int x,int y)
{
missileinit();
 for(int i=0; i<missile.rows;i++)
 {
  for(int j=0;j<missile.cols;j++)
   {
    missiledrawsquare(j+x,i+y,mis[i][j]);
   }
 }
k++;
}

void allmissile()
{
    struct node *temp;
    if (start == NULL)
    {
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->x<<" "<<temp->y<<" "<<endl;
        missiledraw(temp->x,temp->y);
        temp = temp->next;
    }
}

void batcollision()
{
    cout<<"Batman's position : "<<batman.x<<" "<<batman.y<<" "<<endl;
    cout<<"Batman's values : "<<batman.left<<" "<<batman.right<<" "<<batman.bottom<<" "<<batman.top<<endl;
    if(mi.searchwithrange(batman.left,batman.top,batman.right,batman.bottom))
      {
       cout<<"You are Dead"<<endl;exit(0);
      }
}

void batwingcollision()
{
    cout<<"Batwing's position : "<<batwing.x<<" "<<batwing.y<<" "<<endl;
    cout<<"Batwing's values : "<<batwing.left<<" "<<batwing.right<<" "<<batwing.bottom<<" "<<batwing.top<<endl;
    if(mi.searchwithrange(batwing.left,batwing.top,batwing.right,batwing.bottom))
      {
         char ch;
         cout<<"You are dead"<<endl;
         cout<<"Score : "<<score<<endl;
    	 exit(0);
         system("g++ menu.cpp -lGL -lglut -lGLU && ./a.out");
      }
}



void checkmissile()
{
 if(!mi.isempty())
  {
    if(mi.search(0)) 
     {
       int temp=score;
       char a[100];
       if (temp==0) {a[0]==char(temp+48);}
       else
         { int k=0;
          do
            {
             a[k]=char((temp%10)+48);
	     temp/=10;k++;
            }while(temp!=0);
         }
       char b[10]="Score : ";
       output(10,10,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,b);
       output(10,10,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24,a);score+=10;
     }
    batwingcollision();
  }
}


void missilemove()
{
 if(!mi.isempty())
 {
 // glClearColor(0.0,0.0,1.0,1.0);
 // glClear(GL_COLOR_BUFFER_BIT);
  batlvl2();
  batwingmove(0,0);
  allmissile();
  for(float d=0;d<5000000;d++);
 // glFlush();
  fflush(stdout);
  mi.update();
 }
}

void launchbatmissile()
{
 mi.insert_last(missile.x,int(batman.y+int(batman.rows/2)));
}

void launchbatwingmissile()
{
 mi.insert_last(missile.x,int(batwing.y+int(batwing.rows/2)));
}


void missile_erase()
{
 mis.erase(mis.begin(),mis.end());
}

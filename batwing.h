vector<string> batwingst;

void collidebatwing()
{
//left top right bottom
batwing.left=batwing.x;
batwing.right=batwing.x+batwing.cols;
batwing.top=batwing.y+batwing.rows;
batwing.bottom=batwing.y;
}

void allmissile();

void batwingdrawsquare(int x, int y, char color)
{
 // G - grey
 // B - black
 int size_of_box=batwing.sizeofbox;
 x*=size_of_box;y*=size_of_box;
 if (color=='G')   glColor3f(0.5,0.5,0.5);
 else if (color=='B')   glColor3f(0.0,0.0,0.0);
 else glColor3f(0.0,0.0,1.0);
 glBegin(GL_POLYGON);
        glVertex2f(x, y);	
        glVertex2f(x, y+size_of_box);
        glVertex2f(x+size_of_box, y+size_of_box);
        glVertex2f(x+size_of_box, y);
 glEnd();
}

void batwinginit()
{
batwingst.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB ");
batwingst.push_back("BBBBBBBGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    ");
batwingst.push_back("BBBBBBBGBBBBBBBGGGGGGGGGGGGGGGGGGGGGGGGGG        ");
batwingst.push_back("BBBBBBBGBBBBBBBGBBBBBBBBBBBBBBBBBBBBB            ");
batwingst.push_back(" BBBBBBGBBBBBBBGGGGGGGGGGGGG                     ");
batwingst.push_back("  BBBBBBB       BBBBBBBBBB                       ");
batwingst.push_back("   BBBBB          BBBBBBB                        ");
batwingst.push_back("   BBBB                                          ");
batwingst.push_back("   BBB                                           ");
batwingst.push_back("  BBB                                            ");
batwingst.push_back("  BB                                             ");
batwingst.push_back("  B                                              ");
}

void batwing_stand(int x,int y)
{
batwinginit();
 batwing.x+=x;
 batwing.y+=y;
 collidebatwing();
cout<<batwing.x<<" "<<batwing.y<<endl;
 for(int i=0; i<batwing.rows;i++)
 {
  for(int j=0;j<batwing.cols;j++)
   {
    batwingdrawsquare(j+batwing.x,i+batwing.y,batwingst[i][j]);
   }
 }
}

bool batwingboundary()
{
if(batwing.top<=190 && batwing.left>=10 && batwing.right<=300 && batwing.bottom>=10) return true;
else return false;
}

void batwingmove(int x,int y)
{
//float d=slwlk;
 //glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
  batlvl2();
  allmissile();
     batwing_stand(x,y);
     //for(float d=0;d<5000000;d++);
//     glFlush();
fflush(stdout);
}

void batwing_erase()
{
 batwingst.erase(batwingst.begin(),batwingst.end());
} 

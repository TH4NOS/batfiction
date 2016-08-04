vector<string> batst;
vector<string> batstbk;
vector<string> batwlk;
vector<string> batwlk1;
vector<string> batwlk2;

const float slwlk=50000;
const float slj=10000;
const float sljs=10000;

void jokermove(int,int);

int trunc(float a)
{
  return int(a);
}

void collidebatman()
{
//left top right bottom
batman.left=batman.x;
batman.right=batman.x+batman.cols;
batman.top=batman.y+batman.rows;
batman.bottom=batman.y;
}

void batdrawsquare(int x, int y, char color)
{
 // G - grey
 // B - black
 // Y - gold
 // W - white
 // F - Flesh
 // M - Mouth
 int size_of_box=batman.sizeofbox;
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

void batmaninit()
{
batst.push_back("     GBBGGBBG     ");
batst.push_back("     BGGBBGGB     ");
batst.push_back("     BBGBBGBB     ");
batst.push_back("     GBGBBGBG     ");
batst.push_back("     WGBGGBGW     ");
batst.push_back("     GWGWWGWG     ");
batst.push_back("     WGWWWWGW     ");
batst.push_back("     WWWWWWWW     ");
batst.push_back("     WWWWWWWW     ");
batst.push_back("     WWWBBWWW     ");
batst.push_back("     WBGGGGBW     ");
batst.push_back(" BBGBGGGGGGGGBGBB ");
batst.push_back(" BGGBYYBYYBYYBGGB ");
batst.push_back(" BBBWYYBYYBYYWBBB ");
batst.push_back(" BBWWYYGYYGYYWWBB ");
batst.push_back(" BWWWGWWWWWWGWWWB ");
batst.push_back(" WWWWGWWWWWWGWWWW ");
batst.push_back(" WGGWGWWBBWWGWGGW ");
batst.push_back(" GWWGWBBBBBBWGWWG ");
batst.push_back(" WWWWBBBWWBBBWWWW ");
batst.push_back(" BWWWWWWWWWWWWWWB ");
batst.push_back(" BBBWBBWWWWBBWBBB ");
batst.push_back(" BBBBBBBBBBBBBBBB ");
batst.push_back("     BFFMMFFB     ");
batst.push_back("     BFFFFFFB     ");
batst.push_back("     BBBFFBBB     ");
batst.push_back("     BBBBBBBB     ");
batst.push_back("     BWWBBWWB     ");
batst.push_back("     BBBBBBBB     ");
batst.push_back("     BBBBBBBB     ");
batst.push_back("     B      B     ");
}


void batmanbackinit()
{
batstbk.push_back("     BBBGGBBB     ");
batstbk.push_back("     GBGBBGBG     ");
batstbk.push_back("     BBGBBGBB     ");
batstbk.push_back("     GBGBBGBG     ");
batstbk.push_back("     BBWGGWBB     ");
batstbk.push_back("     WWWWWWWW     ");
batstbk.push_back("     WWWWWWWW     ");
batstbk.push_back("     WWWBBWWW     ");
batstbk.push_back("     WWWBBWWW     ");
batstbk.push_back("     WBBBBBBW     ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back(" BBGBBBBBBBBBBGBB ");
batstbk.push_back(" BGGBBBBBBBBBBGGB ");
batstbk.push_back(" BBBWBGBBBBGBWBBB ");
batstbk.push_back(" BBWWBGBBBBGBWWBB ");
batstbk.push_back(" BWWWBGBBBBGBWWWB ");
batstbk.push_back(" WWWWBGBBBBGBWWWW ");
batstbk.push_back(" WGGWBGBBBBGBWGGW ");
batstbk.push_back(" GWWGBGBBBBGBGWWG ");
batstbk.push_back(" WWWWBGBBBBGBWWWW ");
batstbk.push_back(" BWWWBGBBBBGBWWWB ");
batstbk.push_back(" BBBBBBBBBBBBBBBB ");
batstbk.push_back(" BBBBBBBBBBBBBBBB ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back("     BBBBBBBB     ");
batstbk.push_back("     B      B     ");
}

void batmanmoveinit()
{				
batwlk.push_back(" GBBG        GBBG ");
batwlk.push_back(" BGGB        BGGB ");
batwlk.push_back("  BBGB      BGBB  ");
batwlk.push_back("  GBGB      BGBG  ");
batwlk.push_back("   WGBG    GBGW   ");
batwlk.push_back("   GWGW    WGWG   ");
batwlk.push_back("    WGWW  WWGW    ");
batwlk.push_back("    WWWW  WWWW    ");
batwlk.push_back("    WWWW  WWWW    ");
batwlk.push_back("     WWWBBWWW     ");
batwlk.push_back("     WBGGGGBW     ");
batwlk.push_back(" BBGBGGGGGGGGBGBB ");
batwlk.push_back(" BGGBYYBYYBYYBBGB ");
batwlk.push_back(" BBBWYYBYYBYYWBBB ");
batwlk.push_back(" BBWWYYGYYGYYWWBB ");
batwlk.push_back(" BWWWGWWWWWWGWWWB ");
batwlk.push_back(" WWWWGWWWWWWGWWWW ");
batwlk.push_back(" WGGWGWWBBWWGWGGW ");
batwlk.push_back(" GWWGWBBBBBBWGWWG ");
batwlk.push_back(" WWWWBBBWWBBBWWWW ");
batwlk.push_back(" BWWWWWWWWWWWWWWB ");
batwlk.push_back(" BBBWBBWWWWBBWBBB ");
batwlk.push_back(" BBBBBBBBBBBBBBBB ");
batwlk.push_back("     BFFMMFFB     ");
batwlk.push_back("     BFFFFFFB     ");
batwlk.push_back("     BBBFFBBB     ");
batwlk.push_back("     BBBBBBBB     ");
batwlk.push_back("     BWWBBWWB     ");
batwlk.push_back("     BBBBBBBB     ");
batwlk.push_back("     BBBBBBBB     ");
batwlk.push_back("     B      B     ");
}

void batmanmove1init()
{
batwlk1.push_back(" GBBG        GBBG ");
batwlk1.push_back(" BGGB        BGGB ");
batwlk1.push_back("  BBGB      BGBB  ");
batwlk1.push_back("  GBGB      BGBG  ");
batwlk1.push_back("   WGBG    GBGW   ");
batwlk1.push_back("   GWGW    WGWG   ");
batwlk1.push_back("    WGWW  WWGW    ");
batwlk1.push_back("    WWWW  WWWW    ");
batwlk1.push_back("    WWWW  WWWW    ");
batwlk1.push_back("     WWWBBWWW     ");
batwlk1.push_back("     WBGGGGBW     ");
batwlk1.push_back("BBGB GGGGGGGG     ");
batwlk1.push_back("BGGB YYBYYBYY     ");
batwlk1.push_back("BBBW YYBYYBYY     ");
batwlk1.push_back("BBWW YYGYYGYY     ");
batwlk1.push_back("BWWW GWWWWWWG     ");
batwlk1.push_back("WWWW GWWWWWWG     ");
batwlk1.push_back("WGGW GWWBBWWG     ");
batwlk1.push_back("GWWG WBBBBBBW     ");
batwlk1.push_back("WWWW BBBWWBBB     ");
batwlk1.push_back("BWWW WWWWWWWW     ");
batwlk1.push_back(" BBBWBBWWWWBBBBBB ");
batwlk1.push_back(" BBBBBBBBBBBBWBBB ");
batwlk1.push_back("     BFFMMFFB GWWG");
batwlk1.push_back("     BFFFFFFB WGGW");
batwlk1.push_back("     BBBFFBBB WWWW");
batwlk1.push_back("     BBBBBBBB WWWB");
batwlk1.push_back("     BWWBBWWB WWBB");
batwlk1.push_back("     BBBBBBBB WBBB");
batwlk1.push_back("     BBBBBBBB BGGB");
batwlk1.push_back("     B      B BGBB");
}

void batmanmove2init()
{
batwlk2.push_back(" GBBG        GBBG ");
batwlk2.push_back(" BGGB        BGGB ");
batwlk2.push_back("  BBGB      BGBB  ");
batwlk2.push_back("  GBGB      BGBG  ");
batwlk2.push_back("   WGBG    GBGW   ");
batwlk2.push_back("   GWGW    WGWG   ");
batwlk2.push_back("    WGWW  WWGW    ");
batwlk2.push_back("    WWWW  WWWW    ");
batwlk2.push_back("    WWWW  WWWW    ");
batwlk2.push_back("     WWWBBWWW     ");
batwlk2.push_back("     WBGGGGBW     ");
batwlk2.push_back("     GGGGGGGG BGBB");
batwlk2.push_back("     YYBYYBYY BGGB");
batwlk2.push_back("     YYBYYBYY WBBB");
batwlk2.push_back("     YYGYYGYY WWBB");
batwlk2.push_back("     GWWWWWWG WWWB");
batwlk2.push_back("     GWWWWWWG WWWW");
batwlk2.push_back("     GWWBBWWG WGGW");
batwlk2.push_back("     WBBBBBBW GWWG");
batwlk2.push_back("     BBBWWBBB WWWW");
batwlk2.push_back(" BBBBWWWWWWWW WWWB");
batwlk2.push_back(" BBBWBBWWWWBBWBBB ");
batwlk2.push_back(" BWWWBBBBBBBBBBBB ");
batwlk2.push_back("GWWG BFFMMFFB     ");
batwlk2.push_back("WGGW BFFFFFFB     ");
batwlk2.push_back("WWWW BBBFFBBB     ");
batwlk2.push_back("BWWW BBBBBBBB     ");
batwlk2.push_back("BBWW BWWBBWWB     ");
batwlk2.push_back("BBBW BBBBBBBB     ");
batwlk2.push_back("BGGB BBBBBBBB     ");
batwlk2.push_back("BBGB B      B     ");
}

void batman_stand(int x,int y)
{
batmaninit();
batman.x+=x;
batman.y+=y;
collidebatman();
 for(int i=0; i<batman.rows;i++)
 {
  for(int j=0;j<batman.cols;j++)
   {
    batdrawsquare(j+batman.x,i+batman.y,batst[i][j]);
   }
 }
}


void batmanbk_stand(int x,int y)
{
batmanbackinit();
batman.x+=x;
batman.y+=y;
collidebatman();
 for(int i=0; i<batman.rows;i++)
 {
  for(int j=0;j<batman.cols;j++)
   {
    batdrawsquare(j+batman.x,i+batman.y,batstbk[i][j]);
   }
 }
}

void batman_walk(int x,int y)
{
static int k=0;
if(k%2==0) batmanmove1init();
else batmanmove2init();
batman.x+=x;
batman.y+=y;
collidebatman();
 for(int i=0; i<batman.rows;i++)
 {
  for(int j=0;j<batman.cols;j++)
   {
    if(k%2==0) batdrawsquare(j+batman.x,i+batman.y,batwlk1[i][j]);
    else batdrawsquare(j+batman.x,i+batman.y,batwlk2[i][j]);
   }
 }
k++;
}

bool batmanlvlconstraintsleft()
{
   cout<<batman.top-batman.bottom<<endl;
 for(int i=batman.bottom;i<31;i++)
  {
    float pixelf[3];
    glReadPixels(batman.left, i, 1, 1, GL_RGB, GL_FLOAT, pixelf);
    cout<<"i:"<<i<<"batmanleft"<<batman.left<<endl;
    cout<<"Readpixels"<<pixelf[0]<<" "<<pixelf[1]<<" "<<pixelf[2]<<endl;
    if(int(trunc(pixelf[0]*10)) == 5 && int(trunc(pixelf[1]*10)) == 5 && int(trunc(pixelf[2]*10)) == 5)
        return true;
  }
 return false;
}
bool batmanlvlconstraintsright()
{
   cout<<batman.top-batman.bottom<<endl;
 for(int i=batman.bottom;i<batman.top-1;i++)
  {
    float pixelf[3];
    glReadPixels(batman.right-1, i, 1, 1, GL_RGB, GL_FLOAT, pixelf);
    cout<<"i:"<<i<<"batmanright"<<batman.right<<endl;
    cout<<"Readpixels"<<pixelf[0]<<" "<<pixelf[1]<<" "<<pixelf[2]<<endl;
    if(int(trunc(pixelf[0]*10)) == 5 && int(trunc(pixelf[1]*10)) == 5 && int(trunc(pixelf[2]*10)) == 5)
        return true;
  }
 return false;
}
bool batmanlvlconstraintstop()
{
   cout<<batman.right-batman.left<<endl;
 for(int i=batman.left;i<31;i++)
  {
    float pixelf[3];
    glReadPixels(i,batman.top-1, 1, 1, GL_RGB, GL_FLOAT, pixelf);
    cout<<"i:"<<i<<"batmantop"<<batman.top+1<<endl;
    cout<<"Readpixels"<<pixelf[0]<<" "<<pixelf[1]<<" "<<pixelf[2]<<endl;
    if(int(trunc(pixelf[0]*10)) == 5 && int(trunc(pixelf[1]*10)) == 5 && int(trunc(pixelf[2]*10)) == 5)
        return true;
  }
 return false;
}
bool batmanlvlconstraintsbottom()
{
   cout<<batman.right-batman.left<<endl;
 for(int i=batman.left;i<batman.right-1;i++)
  {
    float pixelf[3];
    glReadPixels(i,batman.bottom+1, 1, 1, GL_RGB, GL_FLOAT, pixelf);
    cout<<"i:"<<i<<"batmanbottom"<<batman.bottom-1<<endl;
    cout<<"Readpixels"<<pixelf[0]<<" "<<pixelf[1]<<" "<<pixelf[2]<<endl;
    if(int(trunc(pixelf[0]*10)) == 5 && int(trunc(pixelf[1]*10)) == 5 && int(trunc(pixelf[2]*10)) == 5)
	        return true;
  }
 return false;
}

void batman_jump(int x,int y)
{
batmanmoveinit();
batman.x+=x;
batman.y+=y;
collidebatman();
 for(int i=0; i<batman.rows;i++)
 {
  for(int j=0;j<batman.cols;j++)
   {
    batdrawsquare(j+batman.x,i+batman.y,batwlk[i][j]);
   }
 }
}

void batmove(int x,int y)
{
//float d=slwlk;
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
static int k=0;
if(k%2==0)   
  {
     batman_stand(x,y);
     for(float d=0;d<5000000;d++);
//     glFlush();
  }
else   
   {
     batman_walk(x,y);
     for(float d=0;d<5000000;d++);
//   glFlush();
   }
k++;
fflush(stdout);
}

void batjump()
{
 float d=slj;
 //glClearColor(0.0,0.0,1.0,1.0);
 //glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_stand(0,1);
 glFlush();
 usleep(d);
 //glutTimerFunc(1,Timer,1);
for(int i=0;i<20;i++)
{
 //glClearColor(0.0,0.0,1.0,1.0);
 //glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_jump(0,1);
 glFlush();
 usleep(d);
}
 //glClearColor(0.0,0.0,1.0,1.0);
 //glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_stand(0,0);
 glFlush();
 usleep(d);
for(int i=0;i<20;i++)
{
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_jump(0,-1);
 glFlush();
 usleep(d);
}
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_stand(0,-1);
 glFlush();
 fflush(stdin);
}

void batjumpside(int k)
{
 float d=sljs;
for(int i=0;i<20;i++)
{
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_jump(0,1);
 glFlush();
 usleep(d);
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_walk(k,0);
 glFlush();
 usleep(d); 
}
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_stand(0,0);
 glFlush();
 usleep(d);
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_walk(k,0);
 glFlush();
 usleep(d);
 
for(int i=0;i<20;i++)
{
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_jump(0,-1);
 glFlush();
 usleep(d);
// glClearColor(0.0,0.0,1.0,1.0);
// glClear(GL_COLOR_BUFFER_BIT);
 batlvl1();
 batman_walk(k,0);
 glFlush();
 usleep(d);
 }
 glFlush();
 fflush(stdin);
}

void batman_erase()
{
 batst.erase(batst.begin(),batst.end());
 batstbk.erase(batstbk.begin(),batstbk.end());
 batwlk.erase(batwlk.begin(),batwlk.end());
 batwlk1.erase(batwlk1.begin(),batwlk1.end());
 batwlk2.erase(batwlk2.begin(),batwlk2.end());
}

#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <ostream>
#include <vector>
#include <cstdio>
#include <unistd.h>
using namespace std;
#include "project.h"


struct object batman,joker,level1,missile;

int main()
{

//size of box to display object
batman.sizeofbox=4;
joker.sizeofbox=10;
level1.sizeofbox=32;
missile.sizeofbox=1;

//rows and cols for each object
batman.rows=31;batman.cols=18;
joker.rows=26;joker.cols=20;
level1.rows=24;level1.cols=43;
//missile.rows=;missile.cols=;

//x and y coordinate for each object
batman.x=1330;batman.y=30;
joker.x=100;joker.y=100;
level1.x=0;level1.y=0;
//missile.x=;missile.y=;

 cout<<batman.x<<endl;
}


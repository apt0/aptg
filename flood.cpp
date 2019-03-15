#include<iostream>
#include<graphics.h>
using namespace std;


void flood(int x, int y,int oldcolor, int newcolor)
{
	int current = getpixel(x,y);
	
	if(current == oldcolor)
	{
		putpixel(x,y,newcolor);
		flood(x,y+1,oldcolor,newcolor);
		flood(x,y-1,oldcolor,newcolor);
		flood(x+1,y,oldcolor,newcolor);
		flood(x-1,y,oldcolor,newcolor);
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	circle(250,200,100);
	flood(250,200,0,4);
	getch();
	closegraph();
	return 0;
}

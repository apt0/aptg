#include<iostream>
#include<graphics.h>
using namespace std;


void boundary(int x, int y,int f_color, int b_color)
{
	int current = getpixel(x,y);
	
	if(current != f_color && current != b_color)
	{
		putpixel(x,y,f_color);
		boundary(x,y+1,f_color,b_color);
		boundary(x,y-1,f_color,b_color);
		boundary(x+1,y,f_color,b_color);
		boundary(x-1,y,f_color,b_color);
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	circle(250,200,100);
	boundary(250,200,4,15);
	getch();
	closegraph();
	return 0;
}

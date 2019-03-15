#include<iostream>
#include<graphics.h>
using namespace std;

void drawcircle(int xc,int yc, int x, int y)
{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc-x,yc+y,RED);
	putpixel(xc+x,yc-y,BLUE);
	putpixel(xc-x,yc-y,GREEN);
	putpixel(xc+y,yc+x,YELLOW);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
}
int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	int xc=200,yc=240,r=100;
	int x,y,d;

	x =0,y=r;
	d = r-1;

	drawcircle(xc,yc,x,y);
	while(x<y)
	{
		x++;
		if(d<0)
			d = d + 2*(x) + 3;
		else{
			d = d +2*(x-y) + 5;
			y--;
		}
	drawcircle(xc,yc,x,y);
	}
	getch();
	closegraph();
	return 0;
}

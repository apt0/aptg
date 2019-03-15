#include<iostream>
#include<graphics.h>
using namespace std;

void drawline(int xs, int ys, int xe, int ye)
{
	int x,y,dx,dy,c1,c2,d;
	
	dx=xe-xs;
	dy=ye-ys;

	c1 = 2*(dy-dx);
	c2 = 2*(dy);

	d = 2*dy - dx;

	x = xs;
	y = ys;

	putpixel(x, y, WHITE);

	while(x<=xe)
	{
		x = x + 1;
		if(d<0)
			d = d + c2;

		else{
			d = d + c1;
			y = y + 1;
		}
	putpixel(x,y,WHITE);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd, &gm, NULL);
	//drawline(200,100,300,180);
	drawline(100,180,200,100);

	getch();
	closegraph();
	return 0;

}

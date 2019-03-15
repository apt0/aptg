#include<iostream>
#include<graphics.h>
using namespace std;


void drawline(int x1, int y1, int x2, int y2)
{
	int dx,dy,m,s;	//1
	float xi,yi,x,y;

	dx = x2-x1;	//2
	dy = y2-y1;

	if(abs(dx)>=abs(dy))	//3
		s=abs(dx);
	else
		s=abs(dy);

	xi=dx/(float)s;		//4
	yi=dy/(float)s;

	x = x1;		//5
	y = y1;

	putpixel(x,y,WHITE);	//6

	for(m=0;m<s;m++)	//7
	{
		x = x + xi;
		y = y + yi;
		putpixel(x,y,WHITE);
	}


}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd, &gm, NULL);
	drawline(140,110,240,110);
	getch();
	return 0;
}

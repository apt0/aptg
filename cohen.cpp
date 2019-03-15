#include<iostream>
#include<graphics.h>
using namespace std;

int a[4],b[4];
float m, xnew, ynew;
float xl = 100, yl = 100, xh = 300, yh = 300,xa=10,ya=200,xb=250,yb=150;

void sutherland();
void bytecode();

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setcolor(5);
	line(xa,ya,xb,yb);
	setcolor(12);
	rectangle(xl,yl,xh,yh);
	m = (yb-ya)/(xb-xa);
	bytecode();
	sutherland();
	getch();
	return 0;
}

void bytecode()
{
	if(xa<xl)
	a[3]=1;
	else a[3]=0;

	if(xa>xh)
	a[2]=1;
	else a[2]=0;

	if(ya<yl)
	a[1]=1;
	else a[1]=0;

	if(ya>yh)
	a[0]=1;
	else a[0]=0;

	
	if(xb<xl)
	b[3]=1;
	else b[3]=0;

	if(xb>xh)
	b[2]=1;
	else b[2]=0;

	if(yb<yl)
	b[1]=1;
	else b[1]=0;

	if(yb>yh)
	b[0]=1;
	else b[0]=0;
}

void sutherland()
{
	cout<<"\nPress Ctrl+c to continue";
	getch();

	if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && b[0]==0 && b[1]==0 && b[2]==0 && b[3]==0)
	{
		cout<<"\nNO clipping Needed";
		line(xa,ya,xb,yb);
	}

	else if(a[0] && b[0] || a[1] && b[1] || a[2] && b[2] || a[3] && b[3])
	{
		//clrscr();
		cout<<"\nLine discared";
		rectangle(xl,yl,xh,yh);
	}

	else {
		if(a[3] == 1 && b[3]==0)
		{
			ynew = (m *(xl-xa)) + ya;
			setcolor(12);
			rectangle(xl,yl,xh,yh);
			setcolor(0);
			line(xa,ya,xb,yb);
			setcolor(15);
			line(xl,ynew,xb,yb);
		}

		else if(a[2] == 1 && b[2] == 0)
		{
			ynew = (m *(xh-xa)) + ya;
			setcolor(12);
			rectangle(xl,yl,xh,yh);
			setcolor(0);
			line(xa,ya,xb,yb);
			setcolor(15);
			line(xl,ynew,xb,yb);
		}

		
		else if(a[1] == 1 && b[1]==0)
		{
			xnew = (yl-ya)/m + xa;
			setcolor(12);
			rectangle(xl,yl,xh,yh);
			setcolor(0);
			line(xa,ya,xb,yb);
			setcolor(15);
			line(xnew,yh,xb,yb);
		}

		
		else if(a[0] == 1 && b[0]==0)
		{
			xnew = (yh-ya)/m + xa;
			setcolor(12);
			rectangle(xl,yl,xh,yh);
			setcolor(0);
			line(xa,ya,xb,yb);
			setcolor(15);
			line(xnew,yh,xb,yb);
		}
	}
}

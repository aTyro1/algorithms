#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
void bresenhemOne(int x1,int y1,int x2,int y2,int tx,int ty)
{
	float p,dx,dy;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	p=2*dy-dx;
	do{
		delay(10);
		putpixel(x1,y1,7);
		if(p<0)
		{
			p=2*dy+p;
			x1=x1+tx;
		}
		else
		{
			p=2*dy-2*dx+p;
			x1=x1+tx;
			y1=y1+ty;
		}
	}
	while(x1!=x2);
}
void bresenhemTwo(int x1,int y1,int x2,int y2,int tx,int ty)
{
	float p,dx,dy;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	p=2*dx-dy;
	do{
		delay(10);
		putpixel(x1,y1,7);
		if(p<0)
		{
			p=2*dx+p;
			y1=y1+ty;
		}
		else
		{
			p=2*dx-2*dy+p;
			y1=y1+ty;
			x1=x1+tx;
		}
	}
	while(y1!=y2);
}
void draw_line(int x1,int y1,int x2,int y2)
{
	float m,dx,dy;
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	if(m>0 && m<1)
	{
	       if(dy<0 && dx<0)
		bresenhemOne(x1,y1,x2,y2,-1,-1);
	       else
	       bresenhemOne(x1,y1,x2,y2,1,1);
	}
	else
	if(m>=1)
	{
		if(dy<0 && dx<0)
		bresenhemTwo(x1,y1,x2,y2,-1,-1);
		else
		bresenhemTwo(x1,y1,x2,y2,1,1);
	}
	else
	if(m<0 && m>-1)
	{
		if(dx<0)
		{
			bresenhemOne(x1,y1,x2,y2,-1,1);
		}
		else
		if(dy<0)
		{
			bresenhemOne(x1,y1,x2,y2,1,-1);
		}
	}
	else
	{
		if(dx<0)
		{
			bresenhemTwo(x1,y1,x2,y2,-1,1);
		}
		else
		if(dy<0)
		{
			bresenhemTwo(x1,y1,x2,y2,1,-1);
		}
	}
}
int main()
{
	int gd=DETECT,gm,x1,y1,x2,y2;
	clrscr();
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	setcolor(10);
	printf("enter first coordinates: ");
	scanf("%d%d",&x1,&y1);
	printf("enter second coordinates: ");
	scanf("%d%d",&x2,&y2);
	line(x1,y1,x2,y2);
	draw_line(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;
}
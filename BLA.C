#include<conio.h>
#include<graphics.h>
void m_less_than_one(int x1,int y1,int x2,int y2,int xp,int yp)
{
	int dx,d2y,d2x,p,i,temp;
	dx=abs(x2-x1);
	d2y=2*abs(y2-y1);
	d2x=2*dx;
	p=d2y-dx;
	i=0;
	do
	{
		x1=x1+xp;
		if(p<1)
		{
			y1=y1;
			p=d2y+p;
		}
		else
		{
			y1=y1+yp;
			p=d2y-d2x+p;
		}
		putpixel(x1,y1,8);
		i++;
	}
	while(i<dx);
}
void m_greater_than_one(int x1,int y1,int x2,int y2,int xp,int yp)
{
	int dy,d2y,d2x,p,i;
	dy=abs(y2-y1);
	d2y=2*abs(y2-y1);
	d2x=2*abs(x2-x1);
	p=d2x-dy;
	i=0;
	do{
		y1=y1+yp;
		if(p<1)
		{
			x1=x1;
			p=d2x+p;
		}
		else
		{
			x1=x1+xp;
			p=d2x-d2y+p;
		}
		putpixel(x1,y1,8);
		i++;
	}
	while(i<dy);
}
void drawline(int x1,int y1,int x2,int y2)
{
	int dx,dy,r;
	float m;
	dx=(x2-x1);
	dy=(y2-y1);
	if(dx==0 || dy==0)
	{
		line(x1,y1,x2,y2);
		return;
	}
	else
	{
		m=(float)dy/(float)dx;
		if(m<1 && m>0)
		{
			m_less_than_one(x1,y1,x2,y2,1,1);
		}
		else if(m>1)
		{
			if(dx<0 && dy<0)
			m_greater_than_one(x1,y1,x2,y2,1,1);
		}
		else
		{
			if(m>-1)
			{
				if(dx<0 && dy<0)
				m_less_than_one(x1,y1,x2,y2,-1,-1);
				else
				if(dx<0)
				m_less_than_one(x1,y1,x2,y2,-1,1);
				else
				m_less_than_one(x1,y1,x2,y2,1,-1);
			}
			else
			{
				if(dy<0 && dx<0)
				m_greater_than_one(x1,y1,x2,y2,-1,-1);
				else
				if(dy<0)
				m_greater_than_one(x1,y1,x2,y2,1,-1);
				else
				m_greater_than_one(x1,y1,x2,y1,-1,1);

			}
		}
	}
}
int main()
{
       int gd=DETECT,gm,x1,x2,y1,y2,m;
	clrscr();
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	setcolor(8);
	drawline(150,100,150,350);
	drawline(150,350,400,350);
	drawline(400,350,400,100);
	drawline(175,225,240,225);
	drawline(240,225,240,165);
	drawline(240,165,175,165);
	drawline(175,165,175,225);
	drawline(270,130,375,130);
	drawline(375,130,375,330);
	drawline(375,330,270,330);
	drawline(270,330,270,130);
	drawline(125,100,425,100);
	drawline(125,100,275,50);
	drawline(275,50,425,100);
	setfillstyle(SOLID_FILL,8);
	floodfill(200,80,8);
	floodfill(275,275,8);
	floodfill(200,200,8);
	getch();
	closegraph();
	return 0;
}
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void flood_fill4(int x,int y,int new_color,int old_color)
{
	int curr_color=getpixel(x,y);
	if(curr_color==old_color)
	{
		putpixel(x,y,new_color);  delay(5);
		flood_fill4(x-1,y,new_color,old_color);
		flood_fill4(x,y-1,new_color,old_color);
		flood_fill4(x+1,y,new_color,old_color);
		flood_fill4(x,y+1,new_color,old_color);
	}
}
void flood_fill8(int x,int y,int new_color,int old_color)
{
	int curr_color=getpixel(x,y);
	if(curr_color==old_color)
	{
		putpixel(x,y,new_color);  delay(5);
		flood_fill8(x-1,y,new_color,old_color);
		flood_fill8(x,y-1,new_color,old_color);
		flood_fill8(x+1,y,new_color,old_color);
		flood_fill8(x,y+1,new_color,old_color);
		flood_fill8(x+1,y+1,new_color,old_color);
		flood_fill8(x-1,y-1,new_color,old_color);
		flood_fill8(x-1,y+1,new_color,old_color);
		flood_fill8(x+1,y-1,new_color,old_color);
	}
}
void boundary_fill4(int x,int y,int new_color,int boundary_color)
{
	int curr_color=getpixel(x,y);
	if(curr_color!=new_color && curr_color!=boundary_color)
	{
		putpixel(x,y,new_color); delay(5);
		boundary_fill4(x-1,y,new_color,boundary_color);
		boundary_fill4(x,y-1,new_color,boundary_color);
		boundary_fill4(x+1,y,new_color,boundary_color);
		boundary_fill4(x,y+1,new_color,boundary_color);
	}
}
void boundary_fill8(int x,int y,int new_color,int boundary_color)
{
	int curr_color=getpixel(x,y);
	if(curr_color !=new_color && curr_color!=boundary_color)
	{
		putpixel(x,y,new_color); delay(5);
		boundary_fill8(x-1,y,new_color,boundary_color);
		boundary_fill8(x,y-1,new_color,boundary_color);
		boundary_fill8(x+1,y,new_color,boundary_color);
		boundary_fill8(x,y+1,new_color,boundary_color);
		boundary_fill8(x+1,y+1,new_color,boundary_color);
		boundary_fill8(x+1,y-1,new_color,boundary_color);
		boundary_fill8(x-1,y-1,new_color,boundary_color);
		boundary_fill8(x-1,y+1,new_color,boundary_color);
	}
}
int main()
{
	int gd=DETECT,gm;
	int current_color;
	int points[38]={100,100,80,150,30,175,80,200,100,250,120,200,170,175,120,150,100,100,100,175,170,175,120,200,100,250,100,175,100,175,30,175,80,150,100,100,100,175};
	int points1[14]={120,150,80,200,100,250,120,200,80,150,100,100,120,150};

	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setcolor(14);
	drawpoly(19,points);
	drawpoly(7,points1);
	boundary_fill8(110,140,12,14);
       //	line(100,100,80,150);
       //	line(80,150,30,175);
       //	line(30,175,80,200);
       //	line(80,200,100,250);
       //	line(100,250,120,200);
       //	line(120,200,170,175);
       //	line(170,175,120,150);
	//line(120,150,100,100);
       //	boundary_fill8(210,210,8,9);
	getch();
	closegraph();
	return 0;
}
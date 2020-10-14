#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void display(int x,int y,int xc,int yc);
void main()
{
   int xc,x,yc,y,r;
   int i,gd=DETECT,gm;
   float dp;
   initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
   printf("Enter the radius of the circle:");
   scanf("%d",&r);
   printf("Enter the values of xc,yc:");
   scanf("%d %d",&xc,&yc);
   line(0,240,640,240);
   line(320,0,320,480);
   x=0;
   y=r;
   dp=1.25-r;
 //void display(int x,int y,int xc,int yc);
   do{
	if(dp<0)
	{
		x=x+1;
		y=y;
		dp=dp+2*x+1;
	}
	else
	{
		x=x+1;
		y=y-1;
		dp=dp+2*x+1-2*y;
	}
	 display(x,y,xc,yc);
    }  while(x<y);
    getch();
    closegraph();
   }
void display(int x,int y,int xc, int yc)
{
	putpixel(320+xc+x,240-yc+y,15);
	putpixel(320+xc+x,240-yc-y,15);
	putpixel(320+xc-x,240-yc+y,15);
	putpixel(320+xc-x,240-yc-y,15);
	putpixel(320+xc+y,240-yc+x,15);
	putpixel(320+xc+y,240-yc-x,15);
	putpixel(320+xc-y,240-yc+x,15);
	putpixel(320+xc-y,240-yc-x,15);
}
/*NAME:Isha Mehta
ROLL-NO:1902099
C-22

Aim:Bresenham line drawing algorithm */


#include<conio.h>
#include<graphics.h>
void main()
{
   int x1,x2,y1,y2,dx,dy,s1,s2,swap=0,dp,x,y;
   int i,gd=DETECT,gm;
   initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
   printf("Enter the values of x1,y1:");
   scanf("%d %d",&x1,&y1);
   printf("Enter the values of x2,y2:");
   scanf("%d %d",&x2,&y2);
   dx=abs(x2-x1);
   dy=abs(y2-y1);

   if((x2-x1)<0)
   {
	s1=-1;
   }
   else if((x2-x1)>0)
   {
	s1=1;
   }
   else{
	s1=0;
   }
   if((y2-y1)<0)
   {
	s2=-1;
   }
   else if((y2-y1)>0){
	s2=1;
   }
   else{
	s2=0;
   }

   dp=2*dy-dx ;
   if(dy>dx)
    {
       int temp;
       temp=dy;
       dy=dx;
       dx=temp;
       swap=1;
    }
    x=x1;
    y=y1;
    for(i=1;i<=dx;i++)
    {
	if(dp<0)
	{
		putpixel(x,y,WHITE);
		if(swap==1)
		{

			y=y+s2;

		}
		else
		{
			x=x+s1;
		}
		dp=dp+2*dy;
	}
	else
	{
		putpixel(x,y,WHITE);
		x=x+s1;
		y=y+s2;
		dp=dp+2*dy-2*dx;
	}
    }
    getch();
    closegraph();

}







 


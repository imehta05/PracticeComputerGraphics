#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void main(){
	int gd=DETECT,gm;
	int x1,y1,x2,y2,x3,y3,tx,ty,i,j,k,object[3][3],t[3][3],op[3][3];
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	printf("Enter the coordinates of polygon: ");
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	printf("Enter sx and sy:");
	scanf("%d %d",&sx,&sy);
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
		    if(i==j){
			t[i][j]=1;
			}
		    else
		    {
			t[i][j]=0;
		    }
		}
	}
	t[0][0]=sx;    t[1][1]=sy;
	object[0][0]=x1;  object[0][1]=y1; object[0][2]=1;
	object[1][0]=x2;  object[1][1]=y2; object[1][2]=1;
	object[2][0]=x3;  object[2][1]=y3; object[2][2]=1;
	printf("Object matrix\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
		  printf(" %d\t",object[i][j]);
		}
		printf("\n");
	}
	printf("translation matrix:\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
		  printf(" %d",t[i][j]);
		}
		printf("\n");
	}
	line(x1,y1,x2,y2);
       line(x2,y2,x3,y3);
       line(x3,y3,x1,y1);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			op[i][j]=0;
			for(k=0;k<3;k++)
			{
			  op[i][j]=op[i][j]+object[i][k]*t[k][j];
			}
		}

	}
		printf("The output matrix :);
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
		  printf(" %d",op[i][j]);
		}
		printf("\n");
	}
	line(op[0][0],op[0][1],op[1][0],op[1][1]);
	line(op[1][0],op[1][1],op[2][0],op[2][1]);
	line(op[2][0],op[2][1],op[0][0],op[0][1]);
	getch();
}
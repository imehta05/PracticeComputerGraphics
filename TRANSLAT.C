#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
void main(){
	int gd=DETECT,gm;
       int  ch,i,j,k;
	float x1,y1,x2,y2,x3,y3,object[3][3],op[3][3],t[3][3],x,rad=3.14/180,tx,ty,sx,sy,shx,shy;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter the coordinates of polygon: ");
	scanf("%f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
	line(0,240,640,240);
	line(320,0,320,480);
	object[0][0]=x1;  object[0][1]=y1; object[0][2]=1.0;
	object[1][0]=x2;  object[1][1]=y2; object[1][2]=1.0;
	object[2][0]=x3;  object[2][1]=y3; object[2][2]=1.0;
	printf("Object matrix\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
		  printf(" %0.2f\t",object[i][j]);
		}
		printf("\n");
	}

	line(320+x1,240-y1,320+x2,240-y2);
       line(320+x2,240-y2,320+x3,240-y3);
       line(320+x3,240-y3,320+x1,240-y1);


	printf("1.translation\t 2. Scaling \t3.Rotation \t 4.Reflection\t 5. Shear");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:  //translation
			printf("Enter the translation distance tx and ty:");
			scanf("%f %f",&tx,&ty);
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
			t[2][0]=tx;    t[2][1]=ty;
			printf("translation matrix:\n");
			for(i=0;i<3;i++)
			{	for(j=0;j<3;j++)
				{
				     printf(" %0.2f",t[i][j]);
				}
				printf("\n");
			}
		break;
		case 2:   //Scale
			printf("Enter  sx and sy:");
			scanf("%f %f",&sx,&sy);
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
			printf("translation matrix:\n");
			for(i=0;i<3;i++)
			{	for(j=0;j<3;j++)
				{
				 printf(" %0.2f",t[i][j]);
				}
				printf("\n");
			}
		break;
		case 3:   //Rotation
		printf("Enter the angle of rotation:");
		scanf("%f",&x);
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
		t[0][0]=t[1][1]=cos(rad*x);
		t[0][1]=sin(rad*x);t[1][0]=-sin(rad*x);
			printf("translation matrix:\n");
		for(i=0;i<3;i++)
		{	for(j=0;j<3;j++)
			{
			  printf(" %0.2f",t[i][j]);
			}
			printf("\n");
		}
		break;
		case 4:   //Reflection

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
			t[1][1]=-1;
			printf("translation matrix:\n");
			for(i=0;i<3;i++)
			{	for(j=0;j<3;j++)
				{
				  printf(" %0.2f",t[i][j]);
				}
				printf("\n");
			}

		break;
		case 5:     //Shear
			printf("Enter  shx and shy:");
			scanf("%f %f",&shx,&shy);
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
			t[0][1]=shy;    t[1][0]=shx;
			printf("translation matrix:\n");
			for(i=0;i<3;i++)
			{	for(j=0;j<3;j++)
				{
				  printf(" %0.2f",t[i][j]);
				}
				printf("\n");
			}

		break;

		default:
			printf("invalid choice");
		break;

	}
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

	printf("The output matrix :");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
		  printf(" %0.2f",op[i][j]);
		}
		printf("\n");
	}
	line(320+op[0][0],240-op[0][1],320+op[1][0],240-op[1][1]);
	line(320+op[1][0],240-op[1][1],320+op[2][0],240-op[2][1]);
	line(320+op[2][0],240-op[2][1],320+op[0][0],240-op[0][1]);
	getch();
	closegraph();
}
}

//2D transformation
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class transform
{
	public:
		int m,a[20][20],c[20][20];
		int i,j,k;
		public:
			
		void object();
		void accept();
		void operator *(float b[20][20])
		{
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<m;j++)
				{
					c[i][j]=0;
					for(int k=0;k<m;k++)
					{
						c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
					}
				}
			}
		}
};
void transform::object()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL); 
   line(300,0,300,600);
   line(0,300,600,300);
    for( i=0;i<m-1;i++)
    {
    	line(300+a[i][0],300-a[i][1],300+a[i+1][0],300-a[i+1][1]);
	}
	line(300+a[0][0],300-a[0][1],300+a[i][0],300-a[i][1]);
	for( i=0;i<m-1;i++)
	{
		
		line(300+c[i][0],300-c[i][1],300+c[i+1][0],300-c[i+1][1]);
	}
	line(300+c[0][0],300-c[0][1],300+c[i][0],300-c[i][1]);
	int temp;
	cout << "Press 1 to continue";
	cin >> temp;
	closegraph();
}
void transform::accept()
{
cout<<"\n";
 cout<<"Enter the Number Of Edges:";
    cin>>m;
    cout<<"\nEnter The Coordinates :";
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		if(j>=2)
    		a[i][j]=1;
    		else
    		cin>>a[i][j];
		}
	}
}
int main()
{
	int ch,tx,ty,sx,sy;
	float deg,theta,b[20][20];
	transform t;
	t.accept();
	
	    cout<<"\n\t\bMenu";
	    cout<<"\n1.Translation\n2.Scaling\n3.Rotation\nEnter your choice :";
			  cin>>ch;
		switch(ch)
		{
		case 1: cout<<"\nTRANSLATION OPERATION\n";
		        cout<<"Enter value for tx and ty:";
		        cin>>tx>>ty;
		        b[0][0]=b[2][2]=b[1][1]=1;
				b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
				b[2][0]=tx;
				b[2][1]=ty;
				t * b;
				
				
				t.object();
				break;			
	    case 2: cout<<"\nSCALING OPERATION\n";
		        cout<<"Enter value for sx,sy:";
		        cin>>sx>>sy;
		        b[0][0]=sx;
		        b[1][1]=sy;
		        b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
		        b[2][0]=b[2][1]=0;
				b[2][2] = 1;
				t * b;
				t.object();
				break;
		case 3: cout<<"\nROTATION OPERATION\n";
		        cout<<"Enter value for angle:";
		        cin>>deg;
				theta=deg*(3.14/100);
				b[0][0]=b[1][1]=cos(theta);
				b[0][1]=sin(theta);
				b[1][0]=sin(-theta);
				b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
				b[2][2]=1;
				t * b;
				t.object();
				break;
		default:
		    cout<<"\nInvalid choice";
			
		}
		
   getch();
   
   return 0;    
}


/*Another Program


NAME:-
ROLL_NO:-
DIV:-
Program No:-04A
AIM:-Write C++/Java program to draw 2-D object and perform following basic transformations,
a) Scaling
b) Translation
c) Rotation
Use operator overloading.

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int pi[10];			//total points i.e x & y
double b[3][3]={1,0,0,0,1,0,0,0,1};
int c[1][1];
float a[1][1];

void matmul(float[]);

int main()
{
	int i,x,y,tx,ty,sx,sy,angle=10,xmax,ymax,xmid,ymid,op;
	int gm,gd=DETECT;
	float p1[10]={50,50,
	100,50,
	100,100,
	50,100,
	50,50};

	cout<<"\nSelect transformation:";
	cout<<"\n1.Translation";
	cout<<"\n2.Rotation:";
	cout<<"\n3.Scaling:";
	cout<<"\nEnter the option:";
	cin>>op;

	switch(op)
	{
		case 1:
			cout<<"\nEnter x translation:";
			cin>>tx;
			cout<<"\nEnter y translation:";
			cin>>ty;

			b[0][0]=1;
			b[0][1]=0;
			b[0][2]=0;

			b[1][0]=0;
			b[1][1]=1;
			b[1][2]=0;

			b[2][0]=tx;
			b[2][1]=ty;
			b[2][2]=1;

			break;

		case 2:
			cout<<"\nEnter rotation angle:";
			cin>>angle;

			b[0][0]=cos(angle*3.14/180);
			b[0][1]=sin(angle*3.14/180);
			b[0][2]=0;
		
			b[1][0]=-sin(angle*3.14/180);
			b[1][1]=cos(angle*3.14/180);
			b[1][2]=0;

			b[2][0]=0;
			b[2][1]=0;
			b[2][2]=1;

			break;

		case 3:
			cout<<"\nEnter x scaling:";
			cin>>sx;
			cout<<"\nEnter y scaling:";
			cin>>sy;

			b[0][0]=sx;
			b[0][1]=0;
			b[0][2]=0;

			b[1][0]=0;
			b[1][1]=sy;
			b[1][2]=0;

			b[2][0]=0;
			b[2][1]=0;
			b[2][2]=1;

			break;
	}

initgraph(&gd,&gm,NULL);

xmax=getmaxx();
ymax=getmaxy();
xmid=xmax/2;
ymid=ymax/2;

setcolor(1);
line(xmid,0,xmid,ymax);
line(0,ymid,xmax,ymid);
setcolor(4);

for(i=0;i<8;i=i+2)
{
	line(p1[i]+xmid,ymid-p1[i+1],xmid+p1[i+2],ymid-p1[i+3]);
}

matmul(p1);
setcolor(15);

for(i=0;i<8;i=i+2)
{
	line(xmid+pi[i],ymid-pi[i+1],xmid+pi[i+2],ymid-pi[i+3]);
}

getch();
closegraph();
return 0;
}

void matmul(float p[10])
{
	int i;
	for(i=0;i<9;i=i+2)
	{
		a[0][0]=p[i];
		a[0][1]=p[i+1];
		c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+b[2][0];
		c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+b[2][1];
 		pi[i]=c[0][0];
       	 	pi[i+1]=c[0][1];
    
	}
}


------------------------OUTPUT---------------------
Select transformation:
1.Translation
2.Rotation:
3.Scaling:
Enter the option:1

Enter x translation:10

Enter y translation:10

root1@root1-ThinkCentre-M60e:~$ ./a.out

Select transformation:
1.Translation
2.Rotation:
3.Scaling:
Enter the option:2

Enter rotation angle:45

root1@root1-ThinkCentre-M60e:~$ ./a.out

Select transformation:
1.Translation
2.Rotation:
3.Scaling:
Enter the option:3

Enter x scaling:2

Enter y scaling:2

*/



*/
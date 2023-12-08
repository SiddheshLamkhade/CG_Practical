//bouncing ball
#include<iostream>
#include<graphics.h>
#include<math.h>

int main()
{

    int gd=DETECT,gm;
    int x,y,i;
    
    initgraph(&gd,&gm,NULL);
    
    x=getmaxx()/2;
    y=getmaxx()/2;
    
    for(i=0;i<1000;i++)
    {
        cleardevice();
        
        x=x+1;
        y=200+50*tan(i*3.142/180);
        
        setcolor(RED);
        circle(x,y,50);
        floodfill(x,y,RED);
        
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}
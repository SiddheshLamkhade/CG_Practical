//BasicShapes
#include<stdio.h>
#include<graphics.h>

void main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    line(100,100,300,400);     //line(x1,y1,x2,y2) Line from one point to another point.
    circle(300,500,400);      //circle(x,y,radius)  where (x,y) is centre point and 400 is its radius.
    rectangle(100,100,200,300); /*rectangle(x1,y1,x2,y2) where (x1,y1) is top left point of rectangle and
                                    (x2,y2) is bottom right point of rectangle*/
    rectangle(100,150,200,250)    //It draws Square . when difference dx and dy is same..

    drawpoly(4,m);             /* drawpoly(n,array) where n no of vertices.  Actually it draws triangle eventhough
                                we have given 4 vertices. it is because first and last vertices are same...*/
    int m[8]={300,100,100,300,500,300,300,100};

    closegraph();
    getch();
}

//boundary fill algorithm
#include <stdio.h>
#include <graphics.h>


boundary(x,y,newclr,bgclr){                               //Function declared to colour the given polygon.
    if(getpixel(x,y)!=newclr && getpixel(x,y)!=bgclr){    //getpixel fun gives pixel colour..
        putpixel(x,y,newclr);                             //putpixel fills colour..
        boundary(x+1,y,newclr,bgclr);
        boundary(x-1,y,newclr,bgclr);
        boundary(x,y+1,newclr,bgclr);                     // Four connected method.
        boundary(x,y-1,newclr,bgclr);
    }
}

void main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    rectangle(50,50,100,100);

    boundary(55,55,15,4);                     /*Function calling as we have taken seed point (55,55) it is pixel 
                                      coordinate from where colouring will be start. 
                                      here 15 is white colour and it is new clr .. 4 is bgclr and it is black*/
}

//graphics_window
#include<stdio.h>                     //standard input output header file.
#include<graphics.h>                   /*As we're using functions from graphics lib. so we are including this 
                                       file compulsory header file.*/

void main(){


    int gd=DETECT,gm;               /*There are 2 integer variables gd and gm where gm will store the value of 
                                      graphics driver and gm store graphics mode. they are in "int" data type*/
    initgraph(&gd,&gm,NULL);/*initialization of graph.It is used to create graph.init graph fun takes  
                                       3 arg We are giving address of graphics driver and graphics mode And path*/
    
    
    rectangle(200,200,500,400);         //Body of program.


    closegraph();                 /*As we have initialized graphics window so we have to close that window
                                       by closegraph fun*/
    getch();                       //For Ending of program...

}

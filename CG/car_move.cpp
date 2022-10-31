#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

void main()
{
    clrscr();
    int d=0,m;
    initgraph(&d,&m,"C:\\TC\\BGI");
    for(int x=0;x<500;x++){
        //ROAD
        line(0,400,639,400);

        // CAR BODY
        line(50+x,370,90+x,370);
        arc(110+x,370,0,180+x,20);
        line(130+x,370,220+x,370);
        arc(240+x,370,0,180+x,20);
        line(260+x,370,300+x,370);
        line(300+x,370,300+x,350);
        line(300+x,350,240+x,330);
        line(240+x,330,200+x,300);
        line(200+x,300,110+x,300);
        line(110+x,300,80+x,330);
        line(80+x,330,50+x,340);
        line(50+x,340,50+x,370);

        //CAR WINDOWS
        line(165+x,305,165+x,330);
        line(165+x,330,230+x,330);
        line(230+x,330,195+x,305);
        line(195+x,305,165+x,305);

        line(160+x,305,165+x,330);
        line(160+x,330,95+x,330);
        line(95+x,330,120+x,305);
        line(120+x,305,160+x,305);

        //WHEELS
        circle(110+x,370,17);
        circle(240+x,370,17);

        delay(10);
        cleardevice();
    }
    //CLOSE FOR LOOP
    getch();
}
/*
ALGORITHM
1.	Start.
2.	Declare variables x,y,x1,y1,x2,y2,k,dx,dy,s,xi,yi and also declare gdriver=DETECT, mode.
3.	Initialize the graphic mode with the path location in TurboC3 folder.
4.	Input the two line end-points and store the left end-points in (x1,y1).
5.	Load (x1, y1) into the frame buffer; that is, plot the first point. put x=x1,y=y1.
6.	Calculate dx=x2-x1 and dy=y2-y1
7.	If abs (dx) > abs (dy), do s=abs(dx).
8.	Otherwise s= abs(dy).
9.	Then xi=dx/s and yi=dy/s.
10.	Start from k=0 and continuing till k<s,the points will be
        i.	x=x+xi.
        ii.	Y=y+yi.
11. Plot pixels using putpixel at points (x,y) in specified colour.
12. Close Graph and stop.
*/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2, i, step, xn, yn, dx, dy;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    printf("Enter the starting coordinates: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the end coordinates: ");
    scanf("%d%d", &x2, &y2);
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }
    xn = dx / step;
    yn = dy / step;
    for (i = 1; i <= step; i++)
    { 
        putpixel(x1, y1, WHITE);
        x1 = x1 + xn;
        y1 = y1 + yn;
    }
    getch();
    closegraph();
    return 0;
}
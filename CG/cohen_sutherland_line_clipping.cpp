/*
ALGORITHM
Step1:Calculate positions of both endpoints of the line

Step2:Perform OR operation on both of these end-points

Step3:If the OR operation gives 0000
       Then
                line is considered to be visible
       else
          Perform AND operation on both endpoints
      If And ≠ 0000
          then the line is invisible
        else
      And=0000
    Line is considered the clipped case.

Step4:If a line is clipped case, find an intersection with boundaries of the window
                m=(y2-y1 )(x2-x1)

(a) If bit 1 is "1" line intersects with left boundary of rectangle window
                y3=y1+m(x-X1)
                where X = Xwmin
                where Xwminis the minimum value of X co-ordinate of window

(b) If bit 2 is "1" line intersect with right boundary
                y3=y1+m(X-X1)
                where X = Xwmax
                where X more is maximum value of X co-ordinate of the window

(c) If bit 3 is "1" line intersects with bottom boundary
                X3=X1+(y-y1)/m
                      where y = ywmin
                ywmin is the minimum value of Y co-ordinate of the window

(d) If bit 4 is "1" line intersects with the top boundary
                X3=X1+(y-y1)/m
                      where y = ywmax
                ywmax is the maximum value of Y co-ordinate of the window
*/
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int a[4], b[4];
    float m, xnew, ynew;
    float xl = 100, yl = 100, xh = 300, yh = 300, xa = 10, ya = 200, xb = 250, yb = 150;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(5);
    line(xa, ya, xb, yb);
    setcolor(12);
    rectangle(xl, yl, xh, yh);
    m = (yb - ya) / (xb - xa);

    if (xa < xl)
        a[3] = 1;
    else
        a[3] = 0;

    if (xa > xh)
        a[2] = 1;
    else
        a[2] = 0;

    if (ya < yl)
        a[1] = 1;
    else
        a[1] = 0;

    if (ya > yh)
        a[0] = 1;
    else
        a[0] = 0;

    if (xb < xl)
        b[3] = 1;
    else
        b[3] = 0;

    if (xb > xh)
        b[2] = 1;
    else
        b[2] = 0;

    if (yb < yl)
        b[1] = 1;
    else
        b[1] = 0;

    if (yb > yh)
        b[0] = 1;
    else
        b[0] = 0;

    printf("press a key to continue");
    getch();
    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0)
    {

        printf("no clipping");
        line(xa, ya, xb, yb);
    }
    else if (a[0] && b[0] || a[1] && b[1] || a[2] && b[2] || a[3] && b[3])
    {
        clrscr();
        printf("line discarded");
        rectangle(xl, yl, xh, yh);
    }
    else
    {
        if (a[3] == 1 && b[3] == 0)
        {
            ynew = (m * (xl - xa)) + ya;
            setcolor(12);
            rectangle(xl, yl, xh, yh);
            setcolor(0);
            line(xa, ya, xb, yb);
            setcolor(15);
            line(xl, ynew, xb, yb);
        }
        else if (a[2] == 1 && b[2] == 0)
        {
            ynew = (m * (xh - xa)) + ya;
            setcolor(12);
            rectangle(xl, yl, xh, yh);
            setcolor(0);
            line(xa, ya, xb, yb);
            setcolor(15);
            line(xl, ynew, xb, yb);
        }
        else if (a[1] == 1 && b[1] == 0)
        {
            xnew = xa + (yl - ya) / m;
            setcolor(0);
            line(xa, ya, xb, yb);
            setcolor(15);
            line(xnew, yh, xb, yb);
        }

        else if (a[0] == 1 && b[0] == 0)
        {
            xnew = xa + (yh - ya) / m;
            setcolor(0);
            line(xa, ya, xb, yb);
            setcolor(15);
            line(xnew, yh, xb, yb);
        }
    }
    getch();
    closegraph();
}
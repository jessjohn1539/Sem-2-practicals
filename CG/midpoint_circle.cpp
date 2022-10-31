/*
ALGORITHM
1.    Start 
2.    Input the radius r and the center (xc,yc) and obtain the first point on the circumference of a circle centered on the origin as          (x0,y0) = (0,r)
3.    Calculate the initial value of the decision parameter as      P0 = 5/4 – r
4.    At each xk position, starting at k = 0, perform the following test
         If Pk < 0, the next point along the circle centered on (0,0) is (xk+1,yk) and Pk+1 = Pk +2xk+1+1
         Otherwise, the next point along the circle is (xk+1,yk-1) and Pk+1 = Pk +2xk+1+1- 2yk+1 where 2x k+1 = 2x k + 2 and 2yk+1 = 2y k - 2
5.    Determine symmetry points in the remaining seven octants
6.    Move each calculated pixel position (x,y) onto the circular path centered on (xc,yc) and plot the coordinate value x = x+xc , y = y+ yc
7.    Repeat steps 3 to 5 until x >= y
8.    Stop

*/
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main()
{

    int gd = DETECT, gm;
    int xc, yc, x, y, r, d;
    //clrscr();
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Mid point Circle drawing algorithm\n");

    printf("Enter coordinates of center: ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the radius: ");
    scanf("%d", &r);
    d = 1 - r;
    x = 0;
    y = r;
    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc + x, WHITE);

        if (d <= 0)
        {
            d = d + 2 * x + 1;
        }
        else
        {
            d = d + 2 * (x - y) + 5;
            y = y - 1;
        }
        x = x + 1;
    }
    getch();
    closegraph();
}
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
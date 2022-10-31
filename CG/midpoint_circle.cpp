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
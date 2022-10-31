/*
ALGORITHM
1.	Input the two line end-points, storing the left end-point in (x0, y0)
2.	Plot the point (x0, y0)
3.	Calculate the constants Δx, Δy, 2Δy, and (2Δy - 2Δx) and get the first value for the decision parameter as:
                P0 = 2Δy - Δx 
4.	At each xk along the line, starting at k = 0, perform the following test. If pk < 0, the next point to plot is (xk+1, yk ) and:
                Pk+1 = Pk + 2Δy
Otherwise, the next point to plot is (xk+1, yk+1) and:
                Pk+1 = Pk + 2Δy - 2Δx
5.	Repeat step 4 (Δx – 1) times

*/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;

    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    p = 2 * dy - dx; //decision parameter

    while (x < x1)
    {
        if (p >= 0)
        {
            putpixel(x, y, 7);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, 7);
            p = p + 2 * dy;
        }
	x = x + 1;
    }
    getch();
}

int main()
{
    int gdriver = DETECT, gmode, error, x0, y0, x1, y1;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    printf("Bresenham's line drawing algorithm\n");
    printf("Enter co-ordinates of first point: ");
    scanf("%d%d", &x0, &y0);

    printf("Enter co-ordinates of second point: ");
    scanf("%d%d", &x1, &y1);
    drawline(x0, y0, x1, y1);

    return 0;
}
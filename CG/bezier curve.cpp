/*
ALGORITHM
1.  Get Four control points say A(x A , yA ), B(x B , yB), C(xC , yC),D(xD , yD )
2.	Divide the curves represented by point A,B,C and D in two sections
3.	Repeat the step 2 for section A AB, ABC, and ABCD and section ABCD , BCD, CD and D
4.	Repeat step 3 until we have sections so short that they can be replaced by straight lines
5.	Replace small sections by straight lines
6.	Stop

*/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
void main()
{
    int x[4], y[4], i;
    double puty, putx, t;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    for (i = 0; i < 4; i++)
    {
        printf("Enter x and y coordinated of point %d: ", i + 1);
        scanf("%d%d", &x[i], &y[i]);
        putpixel(x[i], y[i], 3);
    }
    for (t = 0.0; t <= 1.0; t = t + 0.001)
    {
        putx = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * t * t * pow(1 - t, 1) * x[2] + pow(t, 3) * x[3];
        puty = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * t * t * pow(1 - t, 1) * y[2] + pow(t, 3) * y[3];
        putpixel(putx, puty, WHITE);
    }
    getch();
    closegraph();
}
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

#define round(a) ((int)(a + 0.5))

void putcircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void circlemid(int xc, int yc, float r) {
    float x = 0, y = r;
    int p = 1 - r;

    while (x < y) {
        x++;

        if (p < 0) {
            p = p + (2 * x) + 1;
        } else {
            y--;
            p = p + (2 * (x - y) + 1);
        }

        putcircle(xc, yc, round(x), round(y));
        delay(10);
    }
}

void main() {
    int gd = DETECT, gm;
    
    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");  

    int xc, yc, r;
    
    clrscr();
    cout << "Enter center coordinates: ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    circlemid(xc, yc, r);
    
    setcolor(10);
    circle(xc, yc, r);

    getch();
    closegraph();
}

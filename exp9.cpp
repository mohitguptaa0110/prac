#include <graphics.h>
#include <conio.h>
#include <dos.h>

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float wxmin = 10, wxmax = 150, wymin = 10, wymax = 250;
    float vxmin = 200, vxmax = 600, vymin = 10, vymax = 250;

    int wx1 = 30, wy1 = 50, wx2 = 100, wy2 = 180;

    // Drawing window and viewport rectangles
    rectangle(wxmin, wymin, wxmax, wymax);
    rectangle(vxmin, vymin, vxmax, vymax);

    // Scaling factors
    float sx = (vxmax - vxmin) / (wxmax - wxmin);
    float sy = (vymax - vymin) / (wymax - wymin);

    // Drawing line in window
    line(wx1, wy1, wx2, wy2);

    // Transforming and drawing line in viewport
    float vx1 = sx * (wx1 - wxmin) + vxmin;
    float vy1 = sy * (wy1 - wymin) + vymin;
    float vx2 = sx * (wx2 - wxmin) + vxmin;
    float vy2 = sy * (wy2 - wymin) + vymin;

    line((int)vx1, (int)vy1, (int)vx2, (int)vy2);

    // Display labels
    outtextxy(60, 260, "Window");
    outtextxy(360, 260, "Viewport");

    getch();
    closegraph();
}

#include<conio.h>

#include<graphics.h>

void main()

{

clrscr();

int gd=DETECT,gm;

initgraph(&gd,&gm,"c:\\turboc3\\bgi");

setbkcolor(2);

circle(100,100,50);

outtextxy(75,98,"CIRCLE");

rectangle(210,60,400,140);

outtextxy(270,100,"RECTANGLE");

line(455,85,555,85);

outtextxy(490,95,"LINE");

arc(80,350,10,80,100);

outtextxy(100,340,"ARC");

ellipse(380,300,0,360,40,80);

outtextxy(355,300,"ELLIPSE");

getch();

}
/******************************ANALOG CLOCK***************************************************************
*******************************DESIGNED BY BHASKAR*******************************************************/

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
#include<math.h>
#include<dos.h>
#include<time.h>

int main(void)
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\tc\\bgi");

     setbkcolor(15);          // change background colour
    int x=getmaxx()/2,y=getmaxy()/2;
    int m=0,z=0,a,b=0,p;

while(1)


{ cleardevice();
  moveto(x-65,80);
  setcolor(3);
  settextstyle(4,0,5);          //set text style
  outtext("Bhaskar");
  settextstyle(0,0,0);
  moveto(x-40,50);
  setcolor(4);
  settextstyle(0,0,1);
  outtext("^^$@T@N^^");
  settextstyle(0,0,0);

/*<<<-----------get system time by dos.h --------------->>>*/
  struct time d;
  gettime(&d);
  int dm,ds,dh;
  dh=d.ti_hour;
  dm=d.ti_min;
  ds=d.ti_sec;
/*<<<<<<<<<<<<<<<--------dos.h ends---------->>>>>>>>>>>*/


   /*<------------------------printing the dial----------------------->*/
 //  circle(x,y,54);
  // circle(x,y,40);

   moveto((x+(48*cos(0*3.14/180))),(y+(48*sin(0*3.14/180))));
   setcolor(4);
   outtext(".");
  moveto((x+(56*cos(0*3.14/180))),(y+(56*sin(0*3.14/180))));
   setcolor(1);
   outtext("3");

     moveto((x+(48*cos(30*3.14/180))),(y+(48*sin(30*3.14/180))));
   setcolor(4);
   outtext(".");
     moveto((x+(56*cos(30*3.14/180))),(y+(56*sin(30*3.14/180))));
   setcolor(1);
   outtext("4");

    moveto((x+(48*cos(60*3.14/180))),(y+(48*sin(60*3.14/180))));
     setcolor(4);
     outtext(".");
    moveto(((x+3)+(56*cos(60*3.14/180))),(y+(56*sin(60*3.14/180))));
  setcolor(1);
  outtext("5");

     moveto((x+(48*cos(90*3.14/180))),(y+(48*sin(90*3.14/180))));
      setcolor(4);
     outtext(".");
    moveto(((x)+(56*cos(90*3.14/180))),((y+2)+(56*sin(90*3.14/180))));
  setcolor(1);
  outtext("6");

     moveto((x+(48*cos(120*3.14/180))),(y+(48*sin(120*3.14/180))));
      setcolor(4);
     outtext(".");
    moveto(((x-2)+(56*cos(120*3.14/180))),((y+1)+(56*sin(120*3.14/180))));
  setcolor(1);
  outtext("7");

     moveto((x+(48*cos(150*3.14/180))),(y+(48*sin(150*3.14/180))));
      setcolor(4);
     outtext(".");
     moveto((x+56*cos((150*3.14/180))),(y+(56*sin(150*3.14/180))));
   setcolor(1);
   outtext("8");

      moveto((x+(48*cos(180*3.14/180))),(y+(48*sin(180*3.14/180))));
      setcolor(4);
     outtext(".");
     moveto((x+(56*cos(180*3.14/180))),(y+(56*sin(180*3.14/180))));
   setcolor(1);
   outtext("9");

     moveto((x+(48*cos(210*3.14/180))),(y+(48*sin(210*3.14/180))));
      setcolor(4);
     outtext(".");
     moveto(((x-7)+(56*cos(210*3.14/180))),((y+1)+(56*sin(210*3.14/180))));
   setcolor(1);
   outtext("10");

     moveto((x+(48*cos(240*3.14/180))),(y+(48*sin(240*3.14/180))));
      setcolor(4);
     outtext(".");
     moveto((x+(56*cos(240*3.14/180))),(y+(56*sin(240*3.14/180))));
   setcolor(1);
   outtext("11");

    moveto((x+(48*cos(270*3.14/180))),(y+(48*sin(270*3.14/180))));
      setcolor(4);
     outtext(".");
     moveto((x+(56*cos(270*3.14/180))),(y+(56*sin(270*3.14/180))));
   setcolor(1);
   outtext("12");

    moveto((x+(48*cos(300*3.14/180))),(y+(48*sin(300*3.14/180))));
      setcolor(4);
     outtext(".");
     moveto((x+(56*cos(300*3.14/180))),(y+(56*sin(300*3.14/180))));
   setcolor(1);
   outtext("1");

    moveto((x+(48*cos(330*3.14/180))),(y+(48*sin(330*3.14/180))));
      setcolor(4);
     outtext(".");
     moveto((x+(56*cos(330*3.14/180))),(y+(56*sin(330*3.14/180))));
   setcolor(1);
   outtext("2");

  moveto(x-50,y-90);

 setcolor(13);
 outtext("ANALOG CLOCK");
/*<--------------------dial ends----------------------------------------*/





/*<<--------print hands of clock-------->>>>>>>>>>>>>>>*/
 setcolor(4);
 line(x,y,(x+40*cos((270+(6*ds))*3.14/180)),(y+40*sin((270+(6*ds))*3.14/180)));  //second hand
 sound(7);
 setcolor(1);
 line(x,y,(x+37*cos((270+(6*dm))*3.14/180)),(y+37*sin((270+(6*dm))*3.14/180))); //minute hand
 setcolor(2);
 line(x,y,(x+25*cos((270+(30*dh))*3.14/180)),(y+25*sin((270+(30*dh))*3.14/180)));//hour hand
/*<<<<<--------hands------->>>>>>>>>*/




/*<<<<<<--------printing digital clock by time.h------------>>>>>>>>>>*/
  time_t u;
    u = time(NULL);
    moveto(x-50,370);
    setcolor(13);
    outtext("DIGITAL CLOCK");
    gotoxy(30,25);
    cout<<ctime(&u);
/*<-------------------digital clock ends---------------------->>>>>>>>*/

   delay(1000); //delay of 1 second


 }                    //while loop ends
 getch();
  closegraph();
       }


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <windows.h>

#define cls printf("\033[2J")
#define nl printf("\n");
#define setmode(x) printf("\033[=%dh", (x))
#define resetmode(x) printf("\033[=%d1", (x))
#define setattr(a,v,b) printf("\033[%d;%d;%dm", (a), (v), (b))
#define delattr printf("\033[m")
#define movecursor(x,y) printf("\033[%d;%dH", x,y);

void intro(int high, int wide, int wait)
{
 int i,k;
 const int gr = 178;

 for (i = 0; i < wide; i++)
 {
    delay(wait);
    printf ("%c", gr);
 }

 for (i=0; i < high; i++)
 {
    delay(wait);
    printf ("%c", gr);
    for (k=0; k < wide-2; k++)
    printf(" ");
    printf ("%c", gr);
 }

 for (i = 0; i < wide; i++)
 {
    delay(wait);
    printf ("%c", gr);
 }
}

void clear_field(int high, int wide)
{
  int i,k,z=2;

  movecursor(z,2);

  for (i = 0; i < high-1; i++)
 {
     for (k = 0; k < wide-2; k++)
     printf (" ");
     z++;
     movecursor(z,2);
 }

}

void outro(int t)
{
 delay(t);
 cls;
 delattr;
 resetmode(18);
 _setcursortype(_NORMALCURSOR);
 exit(0);
}

void colormode()
{
 int rn_c = 31 + (rand() % (35+1-1));
 setattr(1,rn_c,40);
}

void snake(int wait)
{
  int i,input,x = 11,y = 40,score = 0,rn_x = 5,rn_y = 5,tail = 1;
  int field [22][80] = {0},fx,fy;
  bool up = false, down = false, left = false, right = false;
  const int gr1 = 1, gr2 = 48, sc = 248;

  enum key {UP = 72, DOWN = 80, LEFT = 75,
            RIGHT = 77, ENTER = 13};

  movecursor(rn_x,rn_y);
  printf ("%c", sc);
  movecursor(x,y);

  printf ("%c", gr1);
  movecursor(25,9);
  printf ("%d", score);
  movecursor(25,77);
  printf ("%d", tail);
  movecursor(x,y);

  do
   {

     input = getch();                            // Zeichen einlesen

     if (input == 0)                   // Pfeil oder Funktionstaste
      {
        input = getch();             // Scancode des Zeichens holen

        switch(input)
        {

        Up:
        case UP:

         while(! kbhit())
        {
          up = true; down = false; left = false; right = false;

          delay(wait);
          x--;
          printf(" ");
          movecursor(x,y);
          printf ("%c", gr1);
          movecursor(x,y);

          if (x < 2)
            outro(2000);

            if ((x == rn_y) && (y == rn_x))
           {
            colormode();
            score += 12;
            tail  += 1;
            movecursor(25,9);
            printf ("%d", score);
            movecursor(25,77);
            printf ("%d", tail);
            srand((unsigned) time(NULL));
            rn_x = 2 + (rand() % (78+1-1));
            rn_y = 2 + (rand() % (20+1-1));
            movecursor(rn_y,rn_x);
            printf ("%c", sc);
            movecursor(x,y);            //back to smiley!!
           }
        }

        input = kbhit();
        break;                // (!)

        Down:
        case DOWN:

        while(! kbhit())
        {
        up = false; down = true; left = false; right = false;

        x++;
        delay(wait);
        printf(" ");
        movecursor(x,y);     // new position
        printf ("%c", gr1);
        movecursor(x,y);     // back to smiley!

        if (x > 23)
           outro(2000);

        if ((x == rn_y) && (y == rn_x))
           {
            colormode();
            score += 12;
            tail  += 1;
            movecursor(25,9);
            printf ("%d", score);
            movecursor(25,77);
            printf ("%d", tail);
            srand((unsigned) time(NULL));
            rn_x = 2 + (rand() % (78+1-1));
            rn_y = 2 + (rand() % (20+1-1));
            movecursor(rn_y,rn_x);
            printf ("%c", sc);
            movecursor(x,y);
           }


      }

        input = kbhit();
        break;

        Left:
        case LEFT:

        while(! kbhit())
        {
        up = false; down = false; left = true; right = false;

        y--;
        delay(wait);
        printf(" ");
        movecursor(x,y);     // new position
        printf ("%c", gr1);
        movecursor(x,y);     // back to smiley!

        if (y < 2)
           outro(2000);

           if ((x == rn_y) && (y == rn_x))
           {
            colormode();
            score += 12;
            tail  += 1;
            movecursor(25,9);
            printf ("%d", score);
            movecursor(25,77);
            printf ("%d", tail);
            srand((unsigned) time(NULL));
            rn_x = 2 + (rand() % (78-1+1));
            rn_y = 2 + (rand() % (20-1+1));
            movecursor(rn_y,rn_x);
            printf ("%c", sc);
            movecursor(x,y);
           }


      }

        input = kbhit();
        break;

        Right:
        case RIGHT:

        while(! kbhit())
        {
        up = false; down = false; left = false; right = true;

        y++;
        delay(wait);
        printf(" ");
        movecursor(x,y);     // new position
        printf ("%c", gr1);
        movecursor(x,y);     // back to smiley!

        if (y > 79)
           outro(2000);

        if ((x == rn_y) && (y == rn_x))
           {
            colormode();
            score += 12;
            tail  += 1;
            movecursor(25,9);
            printf ("%d", score);
            movecursor(25,77);
            printf ("%d", tail);
            srand((unsigned) time(NULL));
            rn_x = 2 + (rand() % (78-1+1));
            rn_y = 2 + (rand() % (20-1+1));
            movecursor(rn_y,rn_x);
            printf ("%c", sc);
            movecursor(x,y);
           }
      }

        input = kbhit();
        break;
    }


    }  else if (up) goto Up;
            else if (down) goto Down;
                 else if (left) goto Left;
                      else if (right) goto Right;


} while (input != ENTER);
  outro(2000);

}

void main()
{
 _setcursortype(_NOCURSOR);
 movecursor(0,0);
 //setmode(18);    //optional
 setattr(1,36,40);    //optional
 intro(22,80,50);
 movecursor(11,35);
 delay(500);setattr(1,35,40);printf("S");delay(500);setattr(1,34,40);printf("N");delay(500);setattr(1,33,40);printf("A");
 delay(500);setattr(1,32,40);printf("K");delay(500);setattr(1,31,40);printf("E  ");
 delay(500);setattr(1,31,40);printf("2");delay(500);setattr(1,32,40);printf("0");
 delay(500);setattr(1,33,40);printf("0");delay(500);setattr(1,34,40);printf("3");delay(500);setattr(1,35,40);
 movecursor(14,27);
 printf("<press any key to continue>");
 getch();
 clear_field(22,80);
 movecursor(25,2);
 printf("SCORE: ");
 movecursor(25,70);
 printf("TAILS: ");
 movecursor(11,40);
 snake(100);
}

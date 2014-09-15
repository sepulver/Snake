#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define KEY_MOVE_UP 119
#define KEY_MOVE_LEFT 97
#define KEY_MOVE_DOWN 115
#define KEY_MOVE_RIGHT 100

char spielfeld[20][20];
int schlange_x;
int schlange_y;

void init_spielfeld();

void definieren_rand();

void erzeugen_futterpunkt(int &x, int &y);

void zeichnen_schlange();

void bewegen_schlange();

void init_schlange(int x, int y);

void zeichnen_spielfeld();

void bildschirmloeschen();

int main()
{
   int fx, fy, x, y, z;

    init_schlange(10, 10);

    for(z = 0; z < 10; z++)
    {
        erzeugen_futterpunkt(fx, fy);

        bool reset = false;

        bildschirmloeschen();

        init_spielfeld();
        definieren_rand();
        erzeugen_futterpunkt();

        while(!reset)
        {
            zeichnen_schlange();
            zeichnen_spielfeld();
            bewegen_schlange();
            bildschirmloeschen();

            printf("%d %d", fx, fy);

            if(schlange_x == fx && schlange_y == fy)
            {
                reset = true;
            }
        }
    }
    return 0;
}

void init_spielfeld()
{
    int x, y;

    for(x = 0; x < 20; x++)
    {
        for(y = 0; y < 20; y++)
        {
            spielfeld[x][y] = ' ';
        }
    }
}

void definieren_rand()
{
    int x, y;

    for(x = 0; x < 20; x++)
    {
        spielfeld[x][0] = 'x';
        spielfeld[x][19] = 'x';
    }

    for(y = 0; y < 20; y++)
    {
        spielfeld[0][y] = 'x';
        spielfeld[19][y] = 'x';
    }
}

void erzeugen_futterpunkt(int &x, int &y)
{
    srand(time(NULL));

    x = rand() % 17 + 1;

    y = rand() % 17 + 1;

    spielfeld[x][y] = 'F';

    return;
}

void init_schlange(int x, int y)
{
    schlange_x = x;
    schlange_y = y;
}

void zeichnen_schlange()
{
    spielfeld[schlange_x][schlange_y] = 'S';
    printf("X: %d    Y: %d\n", schlange_x, schlange_y);
}

void bewegen_schlange()
{
    char dummy = getch();

    switch(dummy)

        {
            case KEY_MOVE_UP:
                schlange_y--;
                break;

            case KEY_MOVE_LEFT:
                schlange_x--;
                break;

            case KEY_MOVE_DOWN:
                schlange_y++;
                break;

            case KEY_MOVE_RIGHT:
                schlange_x++;
                break;
        }
}

void zeichnen_spielfeld()
{
    int x, y;

    for(y = 0; y < 20; y++)
    {
        for(x = 0; x < 20; x++)
        {
            printf("%c", spielfeld[x][y]);
        }
        printf("\n");
    }
}

void bildschirmloeschen()
{
    system("cls");
}

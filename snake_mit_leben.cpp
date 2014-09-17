#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<dos.h>

#define KEY_MOVE_UP 119
#define KEY_MOVE_LEFT 97
#define KEY_MOVE_DOWN 115
#define KEY_MOVE_RIGHT 100

char spielfeld[20][20];
int schlange_x;
int schlange_y;
int score = 0;
int highscore = 0;
int runde = 0;
int leben = 3;
bool reset;

void init_spielfeld();

void definieren_rand();

void erzeugen_futterpunkt(int &x, int &y);

void zeichnen_schlange();

void bewegen_schlange();

void loesche_schlange(int x, int y);

void randberuehrung();

void init_schlange(int x, int y);

void zeichnen_spielfeld();

void set_highscore();

void bildschirmloeschen();

int main()
{
    int fx, fy, eingabe;

    init_schlange(10, 10);

    for(runde; runde < 3; runde)
    {
        set_highscore();

        reset = false;

        bildschirmloeschen();

        init_spielfeld();
        definieren_rand();
        erzeugen_futterpunkt(fx, fy);

        while(!reset)
        {
            zeichnen_schlange();
            zeichnen_spielfeld();
            bewegen_schlange();
            bildschirmloeschen();

            randberuehrung();

            if(schlange_x == fx && schlange_y == fy)
            {
                reset = true;

                score++;
            }
        }
    }

    set_highscore();

    printf("\nHighscore: %d\n", highscore);

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
    printf("X: %d    Y: %d\nScore: %d   Leben: %d\nHighscore: %d\n", schlange_x, schlange_y, score, leben, highscore);
}

void bewegen_schlange()
{
    char dummy = getch();

    loesche_schlange(schlange_x, schlange_y);

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

void loesche_schlange(int x, int y)
{
    spielfeld[x][y] = ' ';
}

void randberuehrung()
{
    if(schlange_y == 0)
        {
            init_schlange(10, 10);
            init_spielfeld();
            definieren_rand();

            reset = true;

            score = 0;
            leben--;
            runde++;
        }

    if(schlange_x== 0)
        {
            init_schlange(10, 10);
            init_spielfeld();
            definieren_rand();

            reset = true;

            score = 0;
            leben--;
            runde++;
        }

    if(schlange_y == 19)
        {
            init_schlange(10, 10);
            init_spielfeld();
            definieren_rand();

            reset = true;

            score = 0;
            leben--;
            runde++;
        }

    if(schlange_x == 19)
        {
            init_schlange(10, 10);
            init_spielfeld();
            definieren_rand();

            reset = true;

            score = 0;
            leben--;
            runde++;
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

void set_highscore()
{
    if(highscore <= score)
        {
            highscore = score;
        }
}


void bildschirmloeschen()
{
    system("cls");
}



/*int input = getch();

    bool up = false, down = false, left = false, right = false;

    enum key {UP = 72, DOWN = 80, LEFT = 75, RIGHT = 13};

    do
    {

        if(input == 0)
        {
            input = getch();

            switch(input)
            {

                case UP:

                    while(!kbhit())
                    {
                        up = true, down = false, left = false, right = false;

                        schlange_y--;

                        if(schlange_y < 1)
                        {
                            randberuehrung();
                        }
                    }
                    input = kbhit();
                    break;


                case DOWN:

                    while(!kbhit())
                    {
                        up = false, down = true, left = false, right = false;

                        schlange_y++;

                        if(schlange_y > 18)
                        {
                            randberuehrung();
                        }
                    }
                    input = kbhit();
                    break;


                case LEFT:

                    while(!kbhit())
                    {
                        up = false, down = false, left = true, right = false;

                        schlange_x--;

                        if(schlange_y < 1)
                        {
                            randberuehrung();
                        }
                    }
                    input = kbhit();
                    break;


                case RIGHT:

                    while(!kbhit())
                    {
                        up = false, down = false, left = false, right = true;

                        schlange_x++;

                        if(schlange_y > 18)
                        {
                            randberuehrung();
                        }
                    }
                    input = kbhit();
                    break;
            }
        }
         else if (up) goto Up;
                else if (down) goto Down;
                    else if (left) goto Left;
                      else if (right) goto Right;
    }
    while(input != ENTER)
    {
        randberuehrung();
    }
    */

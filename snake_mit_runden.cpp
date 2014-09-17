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
int score = 0;
int highscore = 0;
int runde = 0;
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

void bildschirmloeschen();

int main()
{
    int fx, fy, z, eingabe;

    printf("Wie viele Runden?\n\n");
    scanf("%d", &eingabe);

    init_schlange(10, 10);

    for(z = 0; z < eingabe; z++)
    {
        reset = false;

        bildschirmloeschen();

        init_spielfeld();
        definieren_rand();
        erzeugen_futterpunkt(fx, fy);

        if(highscore <= score)
        {
            highscore = score;
        }

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
                runde++;
            }
        }
    }
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
    printf("X: %d    Y: %d\nScore: %d   Runde: %d\nHighscore: %d\n", schlange_x, schlange_y, score, runde, highscore);
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
            runde++;
        }

    if(schlange_x== 0)
        {
            init_schlange(10, 10);
            init_spielfeld();
            definieren_rand();

            reset = true;

            score = 0;
            runde++;
        }

    if(schlange_y == 19)
        {
            init_schlange(10, 10);
            init_spielfeld();
            definieren_rand();

            reset = true;

            score = 0;
            runde++;
        }

    if(schlange_x == 19)
        {
            init_schlange(10, 10);
            init_spielfeld();
            definieren_rand();

            reset = true;

            score = 0;
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

void bildschirmloeschen()
{
    system("cls");
}


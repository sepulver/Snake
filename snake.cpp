#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<dos.h>
#include<windows.h>
#include<fstream>
#include<string.h>
#include<iostream>

char spielfeld[20][20];

char input;

int schlange_x;
int schlange_y;
int score = 0;
int highscore = 0;
int leben = 3;

bool reset;
bool up = false, down = false, left = false, right = false;

enum key { UP = 119, DOWN = 115, LEFT = 97, RIGHT = 100 };

void init_spielfeld();

void definieren_rand();

void erzeugen_futterpunkt(int &x, int &y);

void zeichnen_schlange();

void tastendruck();

void bewegen_schlange();

void loesche_schlange(int x, int y);

void randberuehrung();

void init_schlange(int x, int y);

void zeichnen_spielfeld();

void set_highscore();

void write_highscore();

void bildschirmloeschen();

int main()
{
	int fx, fy, eingabe;

	init_schlange(10, 10);

	for (leben; leben >= 1 ; leben)
	{
		reset = false;

		bildschirmloeschen();

		init_spielfeld();
		definieren_rand();
		erzeugen_futterpunkt(fx, fy);

		while (!reset)
		{
			zeichnen_schlange();
			zeichnen_spielfeld();
			tastendruck();
			bewegen_schlange();
			Sleep(200);

			bildschirmloeschen();

			randberuehrung();

			if (schlange_x == fx && schlange_y == fy)
			{
				reset = true;

				score++;
			}
        set_highscore();

        write_highscore();
		}
	}

	printf("\n! Game Over !\n\nHighscore: %d\n", highscore);

	return 0;
}

void init_spielfeld()
{
	int x, y;

	for (x = 0; x < 20; x++)
	{
		for (y = 0; y < 20; y++)
		{
			spielfeld[x][y] = ' ';
		}
	}
}

void definieren_rand()
{
	int x, y;

	for (x = 0; x < 20; x++)
	{
		spielfeld[x][0] = 'x';
		spielfeld[x][19] = 'x';
	}

	for (y = 0; y < 20; y++)
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

void tastendruck()
{
	if (kbhit())
	{
		input = getch();

		switch (input)
		{
		case UP:

			if (down == false)
			{
				up = true, down = false, left = false, right = false;
			}

			break;

		case DOWN:

			if (up == false)
			{
				up = false, down = true, left = false, right = false;
			}

			break;

		case LEFT:

			if (right == false)
			{
				up = false, down = false, left = true, right = false;
			}

			break;

		case RIGHT:

			if (left == false)
			{
				up = false, down = false, left = false, right = true;
			}

			break;
		}
	}
}

void bewegen_schlange()
{
	if (up == true)
	{
		schlange_y--;
	}

	if (down == true)
	{
		schlange_y++;
	}

	if (left == true)
	{
		schlange_x--;
	}

	if (right == true)
	{
		schlange_x++;
	}
}

void loesche_schlange(int x, int y)
{
	spielfeld[x][y] = ' ';
}

void randberuehrung()
{
	if (schlange_y == 0)
	{
		init_schlange(10, 10);
		init_spielfeld();
		definieren_rand();

		reset = true;

		up = false, down = false, left = false, right = false;

		score = 0;
		leben--;
	}

	if (schlange_x == 0)
	{
		init_schlange(10, 10);
		init_spielfeld();
		definieren_rand();

		reset = true;

		up = false, down = false, left = false, right = false;

		score = 0;
		leben--;
	}

	if (schlange_y == 19)
	{
		init_schlange(10, 10);
		init_spielfeld();
		definieren_rand();

		reset = true;

		up = false, down = false, left = false, right = false;

		score = 0;
		leben--;
	}

	if (schlange_x == 19)
	{
		init_schlange(10, 10);
		init_spielfeld();
		definieren_rand();

		reset = true;

		up = false, down = false, left = false, right = false;

		score = 0;
		leben--;
	}
}

void zeichnen_spielfeld()
{
	int x, y;

	for (y = 0; y < 20; y++)
	{
		for (x = 0; x < 20; x++)
		{
			printf("%c", spielfeld[x][y]);
		}
		printf("\n");
	}
}

void set_highscore()
{
	if (highscore <= score)
	{
		highscore = score;
	}
}

void write_highscore()
{
    using namespace std;

    fstream f;
    f.open("highscore.txt", ios::out);
    f << ("Highscore: %d", highscore) << endl;
    f.close();
}

void bildschirmloeschen()
{
	system("cls");
}


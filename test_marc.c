
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<dos.h>
#include<windows.h>

/*#define KEY_MOVE_UP 119
#define KEY_MOVE_LEFT 97
#define KEY_MOVE_DOWN 115
#define KEY_MOVE_RIGHT 100*/

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

	for (runde; runde < 3; runde)
	{
		set_highscore();

		reset = false;

		bildschirmloeschen();

		init_spielfeld();
		definieren_rand();
		erzeugen_futterpunkt(fx, fy);

		while (!reset)
		{

			zeichnen_spielfeld();
			bewegen_schlange();
			bildschirmloeschen();

			randberuehrung();

			if (schlange_x == fx && schlange_y == fy)
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

void bewegen_schlange()
{
	char input = 0;

	bool up = false, down = false, left = false, right = false;

	enum key { UP = 119, DOWN = 115, LEFT = 97, RIGHT = 100, ENTER = 13 };

	do
	{
	    zeichnen_schlange();

		if (_kbhit())
		{
			input = _getch();

			switch (input)
			{

			case UP:
					up = true, down = false, left = false, right = false;
					schlange_y--;

				break;


			case DOWN:
					up = false, down = true, left = false, right = false;
					schlange_y++;

				break;

			case LEFT:
					up = false, down = false, left = true, right = false;

					schlange_x--;

				break;


			case RIGHT:
					up = false, down = false, left = false, right = true;

					schlange_x++;

				break;
			}

		}
	} while (input != ENTER);

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

		score = 0;
		leben--;
		runde++;
	}

	if (schlange_x == 0)
	{
		init_schlange(10, 10);
		init_spielfeld();
		definieren_rand();

		reset = true;

		score = 0;
		leben--;
		runde++;
	}

	if (schlange_y == 19)
	{
		init_schlange(10, 10);
		init_spielfeld();
		definieren_rand();

		reset = true;

		score = 0;
		leben--;
		runde++;
	}

	if (schlange_x == 19)
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


void bildschirmloeschen()
{
	system("cls");
}

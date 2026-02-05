#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // for kbhit() and getch() on Windows
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clearScreen()
{
    system("cls");
}

int main()
{
    int candyX = 40, candyY = 1;
    int boxX = 40, boxY = 14;
    int score = 0, lifeline = 5;
    int d;
    char ch;

    srand(time(NULL));

    while (1)
    {
        clearScreen();

        gotoxy(60, 5);
        printf("Score = %d", score);

        gotoxy(60, 6);
        printf("Lifeline = %d", lifeline);

        // Candy
        gotoxy(candyX, candyY);
        printf("O");

        // Box
        gotoxy(boxX, boxY);
        printf("#");

        gotoxy(boxX + 7, boxY);
        printf("#");

        gotoxy(boxX, boxY + 1);
        printf("########");

        // Keyboard input
        if (kbhit())
        {
            ch = getch();
            switch (ch)
            {
            case 'a':
            case 'A':
                if (boxX > 1)
                    boxX--;
                break;

            case 'd':
            case 'D':
                if (boxX < 70)
                    boxX++;
                break;

            case 'x':
            case 'X':
                exit(0);
            }
        }

        candyY++;

        if (candyY == boxY)
        {
            d = candyX - boxX;

            if (d >= 1 && d <= 6)
            {
                score++;
                Beep(800, 150);
            }
            else
            {
                lifeline--;

                if (lifeline == 0)
                {
                    clearScreen();
                    gotoxy(35, 12);
                    printf("GAME OVER!");
                    getch();
                    exit(0);
                }
            }

            candyX = rand() % 70 + 1;
            candyY = 1;
        }

        Sleep(150);
    }

    return 0;
}

/**
 * screen.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 */

#include "screen.h"

void screenDrawBorders()
{
    char hbc = BOX_HLINE;
    char vbc = BOX_VLINE;

    screenClear();
    screenBoxEnable();

    screenGotoxy(MINX, MINY);
    printf("%c", BOX_UPLEFT);

    for (int i = MINX + 1; i < MAXX; i++)
    {
        screenGotoxy(i, MINY);
        printf("%c", hbc);
    }
    screenGotoxy(MAXX, MINY);
    printf("%c", BOX_UPRIGHT);

    for (int i = MINY + 1; i < MAXY; i++)
    {
        screenGotoxy(MINX, i);
        printf("%c", vbc);
        screenGotoxy(MAXX, i);
        printf("%c", vbc);
    }

    screenGotoxy(MINX, MAXY);
    printf("%c", BOX_DWNLEFT);
    for (int i = MINX + 1; i < MAXX; i++)
    {
        screenGotoxy(i, MAXY);
        printf("%c", hbc);
    }
    screenGotoxy(MAXX, MAXY);
    printf("%c", BOX_DWNRIGHT);

    screenBoxDisable();
}

void screenInit(int drawBorders)
{
    screenClear();
    if (drawBorders)
        screenDrawBorders();
    screenHomeCursor();
    screenHideCursor();

    // Clear Hanged Man drawing
    screenGotoxy(5, 15);
    printf("                ");
}

void screenDestroy()
{
    printf("%s[0;39;49m", ESC); // Reset colors
    screenSetNormal();
    screenClear();
    screenHomeCursor();
    screenShowCursor();
}

void screenGotoxy(int x, int y)
{
    x = (x < 0 ? 0 : x >= MAXX ? MAXX - 1
                               : x);
    y = (y < 0 ? 0 : y > MAXY ? MAXY
                              : y);

    printf("%s[f%s[%dB%s[%dC", ESC, ESC, y, ESC, x);
}

void screenSetColor(screenColor fg, screenColor bg)
{
    char atr[] = "[0;";

    if (fg > LIGHTGRAY)
    {
        atr[1] = '1';
        fg -= 8;
    }

    printf("%s%s%d;%dm", ESC, atr, fg + 30, bg + 40);
}

void displayTimeRemaining(int remaining_time)
{
    char time_string[12]; // Increased size from 10 to 12
    screenSetColor(CYAN, WHITE);
    screenGotoxy(30, 5);
    sprintf(time_string, "%02d:%02d", remaining_time / 60000, (remaining_time % 60000) / 1000);
    printf("Time Remaining: %s", time_string);
    screenUpdate();
}

void drawHangedMan(int currentPart)
{
    switch (currentPart)
    {
    case 6:
        screenGotoxy(5, SCRSTARTY + 1);
        printf(HANGMAN_HEAD);
        break;
    case 5:
        screenGotoxy(5, SCRSTARTY + 2);
        printf(HANGMAN_BODY);
        break;
    case 4:
        screenGotoxy(5, SCRSTARTY + 3);
        printf(HANGMAN_LEFT_ARM);
        break;
    case 3:
        screenGotoxy(5, SCRSTARTY + 4);
        printf(HANGMAN_RIGHT_ARM);
        break;
    case 2:
        screenGotoxy(5, SCRSTARTY + 5);
        printf(HANGMAN_LEFT_LEG);
        break;
    case 1:
        screenGotoxy(5, SCRSTARTY + 6);
        printf(HANGMAN_RIGHT_LEG);
        break;
    }
}

void displayInitialGameSetup()
{
    screenInit(1); // Draw borders
    screenGotoxy(SCRSTARTX + 2, SCRSTARTY+ 2);
    printf("=====ENFORCADOS=====\n");
    screenGotoxy(SCRSTARTX + 4, SCRSTARTY + 4);
    printf("A Forca Suprema\n");
    screenGotoxy(SCRSTARTX + 8, SCRSTARTY + 8);
    printf("Aperte qualquer tecla...");
}

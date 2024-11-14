#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "game.h"
#include "screen.h"
#include "keyboard.h"

void initializeGame(Game *game, const char *word, int attempts, int time_limit, int level)
{
    game->word = malloc(strlen(word) + 1);
    if (game->word == NULL)
    {
        fprintf(stderr, "Memory allocation failed for word\n");
        exit(EXIT_FAILURE);
    }
    game->display = malloc(strlen(word) + 1);
    if (game->display == NULL)
    {
        fprintf(stderr, "Memory allocation failed for display\n");
        exit(EXIT_FAILURE);
    }

    strcpy(game->word, word);

    // Initialize display with underscores
    for (int i = 0; i < strlen(word); i++)
    {
        game->display[i] = '_';
    }
    game->display[strlen(word)] = '\0';

    game->attempts = attempts;
    game->score = 0;
    game->time_limit = time_limit;
    game->level = level;
}

bool isLevelCompleted(Game *game)
{
    return strcmp(game->word, game->display) == 0;
}

bool updateTimeRemaining(Game *game)
{
    static int start_time = 0;
    if (start_time == 0)
    {
        start_time = time(NULL);
    }
    int elapsed_time = difftime(time(NULL), start_time) * 1000; // Convert to milliseconds
    int remaining_time = game->time_limit - elapsed_time;
    if (remaining_time <= 0)
    {
        return false;
    }
    game->time_limit = remaining_time;
    return true;
}

void playGame(Game *game)
{
    char guess;
    bool correctGuess;

    // Draw the hangman once at the start
    drawHangedMan(game->attempts);

    while (game->attempts > 0 && !isLevelCompleted(game))
    {
        screenSetColor(BLACK, WHITE);
        screenGotoxy(3, 8);
        printf("Palavra: %s\n", game->display);
        screenGotoxy(3, 9);
        printf("Tentativas: %d\n", game->attempts);
        screenGotoxy(3, 10);
        printf("Score: %d\n", game->score);

        int remaining_time = updateTimeRemaining(game);
        if (remaining_time) {
            displayTimeRemaining(remaining_time);
        }

        screenGotoxy(3, 11);
        printf("Enter a guess: ");
        guess = readch();
        correctGuess = isGuessCorrect(game, guess);
        if (correctGuess)
        {
            game->score++;
            updateDisplay(game, guess);
        }
        else
        {
            game->attempts--;
            drawHangedMan(game->attempts);
        }
    }
}

bool isGuessCorrect(Game *game, char guess)
{
    guess = tolower(guess); // Converta a adivinhação para minúscula
    for (int i = 0; i < strlen(game->word); i++)
    {
        if (game->word[i] == guess)
        {
            return true;
        }
    }
    return false;
}

void updateDisplay(Game *game, char guess)
{
    for (int i = 0; i < strlen(game->word); i++)
    {
        if (game->word[i] == guess)
        {
            game->display[i] = guess;
        }
    }
}

bool isWordGuessed(Game *game)
{
    return strcmp(game->word, game->display) == 0;
}

void cleanUpGame(Game *game)
{
    // Free allocated memory for word and display
    free(game->word);
    free(game->display);
    game->time_limit = 0;
    game->level = 1;
}

void resetGame(Game *game)
{
    game->time_limit = 30000; // 30 seconds for each level
    game->level++;
}

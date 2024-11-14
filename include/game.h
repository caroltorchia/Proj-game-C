#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

typedef struct {
    char *word;       // The word to guess
    char *display;    // Displayed word with underscores for unguessed letters
    int attempts;     // Number of allowed incorrect guesses
    int score;        // Player's score (number of correct guesses)
    int time_limit;    // Time limit for the current level in milliseconds
    int level;        // Current difficulty level
} Game;

void initializeGame(Game *game, const char *word, int attempts, int time_limit, int level);
bool isLevelCompleted(Game *game);
bool updateTimeRemaining(Game *game);
void resetGame(Game *game);
void cleanUpGame(Game *game);
void playGame(Game *game);
bool isGuessCorrect(Game *game, char guess);
void updateDisplay(Game *game, char guess);
bool isWordGuessed(Game *game);

#endif

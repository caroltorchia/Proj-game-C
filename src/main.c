#include <stdio.h>
#include <unistd.h>

#include "game.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

int main()
{
    Game game;

    char *words[] = {"rua", "gato", "macaco"};
    int total_words = sizeof(words) / sizeof(words[0]);
    int current_word = 0;
    int current_attempts = 6;
    int time_limit = 30000; // 30 seconds for each level

    // Initialize the screen and keyboard
    screenInit(1);
    keyboardInit();

    // Main game loop
    while (true)
    {
        displayInitialGameSetup();
        sleep(3);
        screenClear();
        screenUpdate();
        initializeGame(&game, words[current_word], current_attempts, time_limit, current_word / 3 + 1);

        while (updateTimeRemaining(&game))
        {
            playGame(&game);

            if (isLevelCompleted(&game))
            {
                current_word++;
                if (current_word >= total_words)
                {
                    screenGotoxy(15, 15);
                    printf("Você venceu! Score: %d\n", game.score);
                    break;
                }
                current_attempts = 6 + (game.level - 1) * 2;
                time_limit = 30000 + (game.level - 1) * 5000; // Increase time limit by 5 seconds per level
            }
            else
            {
                resetGame(&game);
            }
        }

        if (!isLevelCompleted(&game))
        {
            screenGotoxy(15, 15);
            printf("Game Over! Score: %d\n", game.score);
            sleep(3);
            break;
        }
    }

    // Clean up game resources
    cleanUpGame(&game);

    // Clean up resources and exit
    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}

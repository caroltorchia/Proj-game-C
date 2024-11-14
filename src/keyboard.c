#include <termios.h>
#include <unistd.h>
#include <ctype.h>

static struct termios initialSettings, newSettings;
static int peekCharacter = -1;

void keyboardInit()
{
    tcgetattr(STDIN_FILENO, &initialSettings);
    newSettings = initialSettings;
    newSettings.c_lflag &= ~ICANON;
    newSettings.c_lflag &= ~ECHO;
    newSettings.c_lflag &= ~ISIG;
    newSettings.c_cc[VMIN] = 1;
    newSettings.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

void keyboardDestroy()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &initialSettings);
}

int keyhit()
{
    unsigned char ch;
    int nread;

    if (peekCharacter != -1)
        return 1;

    newSettings.c_cc[VMIN] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
    nread = read(STDIN_FILENO, &ch, 1);
    newSettings.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    if (nread == 1)
    {
        peekCharacter = ch;
        return 1;
    }

    return 0;
}

int readch()
{
    char ch;

    if (peekCharacter != -1)
    {
        ch = peekCharacter;
        peekCharacter = -1;
        return ch;
    }
    read(STDIN_FILENO, &ch, 1);
    return ch;
}

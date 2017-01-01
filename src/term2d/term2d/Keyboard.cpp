#include <term2d/Keyboard.hpp>

#ifdef _WIN32

char CurKey()
{
    if (_kbhit()) {
        return (char)_getch();
    }
    return '\0';
}

void DisableKeyPrint() { }
void EnableKeyPrint() { }

#else

void DisableKeyPrint() {
  int temp = system("stty -echo");
}
void EnableKeyPrint() {
  int temp = system("stty echo");
}

int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}


char CurKey()
{
    if (_kbhit()) {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    } else {
        return '\0';

    }
}

#endif

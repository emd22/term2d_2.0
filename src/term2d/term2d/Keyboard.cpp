#include <term2d/Keyboard.hpp>

#ifdef _WIN32

char Getch() {
    if (_kbhit()) {
        return (char)_getch();
    }
    return '\0';
}

#else

static struct termios old, _new;

/* Initialize new terminal i/o settings */
void InitTermios(int echo) {
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    _new = old; /* make new settings same as old settings */
    _new.c_lflag &= ~ICANON; /* disable buffered i/o */
    _new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &_new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void ResetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
    char ch;
    InitTermios(echo);
    ch = getchar();
    ResetTermios();
    return ch;
}

/* Read 1 character without echo */
char Getch() {
    return getch_(0);
}

/* Read 1 character with echo */
char Getche() {
    return getch_(1);
}

#endif

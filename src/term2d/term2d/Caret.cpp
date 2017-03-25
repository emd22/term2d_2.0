#include <term2d/Caret.hpp>

//Set caret position and remove caret
#ifdef _WIN32
void CaretPos(int x, int y) {
    COORD cur;
    cur.X = x;
    cur.Y = y;vec
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void HideTermCaret()
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO structCursorInfo;
    structCursorInfo.dwSize = 1;
    structCursorInfo.bVisible = FALSE;

    SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
}
void ShowTermCaret()
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO structCursorInfo;
    structCursorInfo.dwSize = 1;
    structCursorInfo.bVisible = TRUE;

    SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
}

#else
//LINUX/UNIX
#include <cstdio>

void CaretPos(int x, int y) {
    std::printf("\033[%d;%dH", y, x);
}

void HideTermCaret() {
    std::fputs("\e[?25l", stdout);
}
void ShowTermCaret() {
    std::fputs("\e[?25h", stdout);
}
#endif

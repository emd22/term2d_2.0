#include <term2d/Caret.hpp>

/*
term2dterm2d                                                2dterm2dter   term2dterm2d
term2dterm2d    2dterm2dter     rm2dter   dterm   term2          m2dterm  term      2dte
    2dte       m2dt     term   erm2     2dt    m2d    2dt          dterm2 term      2dte
    2dte      rm2d       erm2 term      2dt    m2d    2dt           term2 term      2dte
    2dte      rm2dterm2dterm2 term      2dt    m2d    2dt         2dterm2 term      2dte
    2dte      rm2d            term      2dt           2dt      erm2dter   term      2dte
    2dte       m2dt     term2 term      2dt           2dt    dterm        term      2dte
    2dte        2dterm2dter   term      2dt           2dt   2dterm2term2d term2dterm2d
*/

//Set caret position and remove caret
#ifdef _WIN32
void SetTermCursorPos(int x, int y)
{
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

void SetTermCursorPos(int x, int y)
{
    std::printf("\033[%d;%dH", y, x);
}

void HideTermCaret()
{
    std::fputs("\e[?25l", stdout);
}
void ShowTermCaret()
{
    std::fputs("\e[?25h", stdout);
}
#endif
//A quick way to clear screen using newlines
void ClearScreen() {
  for (int i = 0; i < TermHeight(); i++) {
    std::cout << "\n";
  }
}

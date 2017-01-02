#include <term2d/ColorText.hpp>

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

#ifdef _WIN32
#define DEFAULT_COLOR 15
#define ANSI false

#include <windows.h>   // WinApi header

void ColoredText(char message, int color)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
    std::putchar(message);

    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
}
void ResetTerm() { }

#else

#define DEFAULT_COLOR 0
#define ANSI true

void ResetTerm() {
  std::cout << "\0033\0143";
}

void ColoredText(char message, int color)
{
  std::cout << "\033[" << color << "m" << message << "\033[15m";
  std::cout << "\033[" << DEFAULT_COLOR << "m" << "\033[15m";

    //ucout << utf8_string;
}

#endif

#include <ColorText.hpp>

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

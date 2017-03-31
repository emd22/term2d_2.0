#include <term2d/ColorText.hpp>

#ifdef _WIN32
#define DEFAULT_COLOR 15

#include <windows.h>   // WinApi header

void ColoredText(char message, int color) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
    std::putchar(message);

    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
}

#else

#define DEFAULT_COLOR 0

void ColoredText(char message, int color) {
  std::cout << "\033[" << color << "m" << message << "\033[15m";
  std::cout << "\033[" << DEFAULT_COLOR << "m" << "\033[15m";
}

#endif

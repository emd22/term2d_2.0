#include <Size.hpp>

#ifdef _WIN32
int TermHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
int TermWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

#else

int TermHeight() {
  struct winsize size;
  ioctl(1/*STDOUT_FILENO*/, TIOCGWINSZ, &size);
  return size.ws_row;
}
int TermWidth() {
  struct winsize size;
  ioctl(1/*STDOUT_FILENO*/, TIOCGWINSZ, &size);
  return size.ws_col;
}
#endif

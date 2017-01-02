#include <term2d/Size.hpp>

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

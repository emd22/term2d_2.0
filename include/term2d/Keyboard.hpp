#pragma once

enum KEYS {
    BACKSPACE = 127,
    TAB = 9,
    SPACE = ' ',
    RETURN = '\n',
    RETURN_OTHER = '\r',
};

#ifdef _WIN32
#include <conio.h>

char Getch();

#else
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>       
#include <sys/select.h>
#include <sys/ioctl.h>
#include <stropts.h>

int Getch();
int Getche();

#endif

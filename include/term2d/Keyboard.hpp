#pragma once

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

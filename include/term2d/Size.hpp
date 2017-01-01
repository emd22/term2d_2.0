#pragma once

#ifdef _WIN32
#include <windows.h>

#else

#include <sys/ioctl.h>

#endif

int TermHeight();
int TermWidth();

#pragma once

#include <cstdio>
#include <iostream>
#include <string>

#ifdef _WIN32
#define DEFAULT_COLOR 15
#define ANSI false

#include <windows.h>

#else

#define DEFAULT_COLOR 0
#define ANSI true

#endif

void ColoredText(char message, int color);
void ResetTerm();

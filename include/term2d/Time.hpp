#pragma once

#ifdef _WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>
#else
#include <unistd.h>
#endif

#include <string>

void TimeDelay(std::string option, int milliseconds);

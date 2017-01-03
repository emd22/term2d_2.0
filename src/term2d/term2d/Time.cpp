#include <term2d/Time.hpp>

#ifdef _WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

#include <string>

void TimeDelay(std::string option, int milliseconds) // cross-platform sleep function
{
  if (option == "ns") {
    milliseconds /= 1000;
  }
  else if (option == "ms") {
  }
  else if (option == "s") {
    milliseconds *= 1000;
  }
  else {
    milliseconds = 0;
  }

#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}

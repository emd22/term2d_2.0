#pragma once

#include <vector>
#include <map>
#include <array>

#ifdef _WIN32
#include <WinBase.h>
void beep(int freq = 440, int len = 200){
    Beep(freq, len);
}
#else
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <sys/ioctl.h>
#include <thread>
#include <iostream>

int beeper;

void open_beeper()
{
    beeper = open("/dev/console", O_WRONLY);
}

void close_beeper()
{
  ioctl(beeper, KIOCSOUND, 0);
  close(beeper);
}

void beep(int freq = 440, int len = 200){
    if (freq > 0 && freq < 2000){
      ioctl(beeper, KIOCSOUND, (int)(1193180/freq));
      std::this_thread::sleep_for(std::chrono::milliseconds(len));
      ioctl(beeper, KIOCSOUND, 0);
    }

}

#endif

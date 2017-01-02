#pragma once

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

#include <vector>
#include <map>
#include <array>

bool can_beep = true;

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

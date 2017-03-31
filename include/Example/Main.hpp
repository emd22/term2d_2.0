#pragma once

#include <term2d.hpp>

class Examples {
public:
    Examples(GUI *g, ScreenSpace *s);
    void Keypress();
private:
    int keyindex = 0;
    int maxindex = 0;
    GUI *gui;
    ScreenSpace *ss;
};
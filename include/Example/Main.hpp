#pragma once

#include <term2d.hpp>

void MainWidgets(GUI *gui, ScreenSpace *ss);
void SecWidgets(GUI *gui, ScreenSpace *ss);

class Examples {
public:
    Examples(GUI *g, ScreenSpace *s);
    void Keypress();
    void SecWidgets();
private:
    int keyindex = 0;
    int maxindex = 0;
    GUI *gui;
    ScreenSpace *ss;
};
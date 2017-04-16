#pragma once

#include <term2d.hpp>
#include <array>

#define CB_PARAM GUI *gui, ScreenSpace *ss

struct Movement {  
    int x;
    int y;
    std::string name;
};

struct BasicWidget {
    int x;
    int y;
    int type;
    std::string message;
    std::vector<Title> titles = {};
};

enum W_TYPES {
    BUTTON,
    TITLEBAR,
};

std::vector<BasicWidget> widgets;

Movement WidgetMovement(bool ax, bool ay);

void MainWidgets(CB_PARAM);
void TestingWidgets(CB_PARAM);

void Button(CB_PARAM);
void Titlebar(CB_PARAM);
void WidgetsAdd(BasicWidget widget);

void Button(CB_PARAM);
void Titlebar(CB_PARAM);

class Program {
public:
    Program(GUI *g, ScreenSpace *s);
    void Keypress();
private:
    int keyindex = 0;
    int maxindex = 0;
    GUI *gui;
    ScreenSpace *ss;
};
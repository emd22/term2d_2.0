#pragma once
#include <term2d/Size.hpp>
#include <term2d/Space.hpp>
#include <string>
#include <vector>

struct SButton {
    int x;
    int y;
    int color;
    std::string title;
};

class GUI {
public:
    void Init(ScreenSpace *s);
    void Titlebar(std::vector<std::string> titles);
    void Button(int x, int y, std::string name, int color);
    int SelectButton(int id, int highlight);
    void DeselectButton(int id);
private:
    std::vector<SButton> buttons;
    ScreenSpace *ss;
    bool did_init = false;
};
#pragma once

#include <vector>
#include <string>
#include <term2d/ColorText.hpp>
#include <term2d/Caret.hpp>
#include <cassert>

class ScreenSpace {
public:
    void Create(int w, int h);
    void Edit(int x, int y, char style, int color);
    void Label(int x, int y, std::string message, int color);
    void Erase(int x, int y, int len, int h);
    void Quit();
private:
    std::vector<std::string> space;
    int _width = 0;
    int _height = 0;
    int lastx = 1;
    int lasty = 1;
    char _style = '?';
};

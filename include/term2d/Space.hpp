#pragma once

#include <vector>
#include <string>
#include <term2d/ColorText.hpp>
#include <term2d/Caret.hpp>
#include <term2d/Size.hpp>
#include <cassert>

class ScreenSpace {
public:
    void Create();
    void SetPage(int index);
    void Edit(int x, int y, char style, int color);
    void Label(int x, int y, std::string message, int color);
    void Erase(int x, int y, int len, int h);
    void Quit();
};

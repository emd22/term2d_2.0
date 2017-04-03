#pragma once

#include <vector>
#include <string>
#include <term2d/ColorText.hpp>
#include <term2d/Caret.hpp>
#include <term2d/Size.hpp>
#include <cassert>

struct Page {
    std::vector<std::string> data;
    std::vector<int> colors;
};

class ScreenSpace {
public:
    void Create();
    void SetPage(int index);
    void Edit(int x, int y, char style, int color);
    void Label(int x, int y, std::string message, int color);
    void Erase(int x, int y, int len, int h);
    void Quit();
private:
    std::vector<std::string> space;
    std::vector<Page> pages;
    int c_page = 0;
};

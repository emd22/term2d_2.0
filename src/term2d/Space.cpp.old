#include <term2d/Space.hpp>
#include <term2d/Keyboard.hpp>
#include <string>
#include <iostream>

void ScreenSpace::Create() {
    int w = TermWidth();
    int h = TermHeight();

    Page page;
    std::string line;
    std::vector<int> colors;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            line += ' ';
            std::cout << ' ';
            colors.push_back(DEFAULT_COLOR);
        }
        page.data.push_back(line);
        line = "";
        std::cout << '\n';
    }
    page.colors = colors;
    pages.push_back(page);
}

void ScreenSpace::SetPage(int index) {
    if (index > 0 && index < pages.size()) {
        c_page = index;
        for (int y = 0; y < pages[index].data.size(); y++) {
            for (int x = 0; x < pages[index].data[y].length(); x++) {
                Edit(x, y, pages[index].data[y][x], pages[index].colors[x+y]);
            }
        }
    }
}

void ScreenSpace::Edit(int x, int y, char style, int color) {
    int w = TermWidth();
    int h = TermHeight();

    if (x < w && y < h && x > 0 && y > 0) {
        pages[c_page].data[y][x] = style;
        pages[c_page].colors[x+y] = color;
        CaretPos(x, y);
        ColoredText(style, color);
    }
}

void ScreenSpace::Label(int x, int y, std::string message, int color) {
    for (int i = 0; i < message.length(); i++) {
        Edit(x+i, y, message[i], color);
    }
}
void ScreenSpace::Erase(int x, int y, int w, int h) {
    std::string line = "";
    for (int i = 0; i < w; i++) {
        line += ' ';
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            pages[c_page].data[y+i][x+j] = ' ';
            pages[c_page].colors[x+j+y+i] = DEFAULT_COLOR;
            CaretPos(x+j, y+i);
            std::cout << line;
        }
    }
}

void ScreenSpace::Quit() {
    Getche();
    exit(0);
}
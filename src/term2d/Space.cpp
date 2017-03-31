#include <term2d/Space.hpp>
#include <term2d/Keyboard.hpp>
#include <string>
#include <iostream>

void ScreenSpace::Create(int w, int h) {
    _width = w;
    _height = h;

    for (int y = 0; y < h; y++) {
        std::string line;
        for (int x = 0; x < w; x++) {
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void ScreenSpace::Edit(int x, int y, char style, int color) {
    if (x < _width && y < _height && x > 0 && y > 0) {
        CaretPos(x, y);
        ColoredText(style, color);
    }
}

void ScreenSpace::Label(int x, int y, std::string message, int color) {
    for (int i = 0; i < message.length(); i++) {
        Edit(x+i, y, message[i], color);
    }
}
void ScreenSpace::Erase(int x, int y, int len, int h) {
    std::string line = "";
    for (int i = 0; i < h; i++) {
        line += ' ';
    }
    for (int i = 0; i < len; i++) {
        CaretPos(x+i, y);
        std::cout << line;
    }
}

void ScreenSpace::Quit() {
    Getche();
    exit(0);
}
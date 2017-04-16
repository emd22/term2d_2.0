#include <term2d/Space.hpp>
#include <term2d/Keyboard.hpp>
#include <string>
#include <iostream>

void ScreenSpace::Create() {
    int w = TermWidth();
    int h = TermHeight();

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void ScreenSpace::Edit(int x, int y, char style, int color) {
    int w = TermWidth();
    int h = TermHeight();

    if (x < w && y < h+1 && x > 0 && y > 0) {
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
            CaretPos(x+j, y+i);
            std::cout << line;
        }
    }
}

void ScreenSpace::Quit() {
    exit(0);
}
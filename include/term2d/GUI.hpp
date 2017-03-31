#pragma once
#include <term2d/Size.hpp>
#include <term2d/Space.hpp>
#include <string>
#include <vector>
#include <functional>
#include <cctype>

class GUI;

struct Title {
    std::string t;
    std::function<void(GUI *)> callback;
};

struct SButton {
    int x;
    int y;
    int color;
    std::string title;
};

class GUI {
public:
    void Init(ScreenSpace *s);
    void Titlebar(std::vector<Title> titles);
    void Button(int x, int y, std::string name, int color);
    void Rect(int x, int y, int w, int h, char style, int color);
    int SelectButton(int id, int highlight);
    void DeselectButton(int id);
    void RemButton(int index);
    void TitlebarKeys(char k);
    void Menu(std::vector<std::string> titles, int color, int titlebar_index);
    void RemMenu(int titlebar_index);
    bool OpenCloseMenu();
    void ClearScreen();
private:
    std::vector<SButton> buttons;
    std::vector<char> titlebar_keys;
    std::vector<Title> _titles;
    std::vector<std::string> menu_titles;
    ScreenSpace *ss;
    int proper_index = 0;
    int maxlen = 0;
    bool did_init = false;
    bool menu_open = false;
};
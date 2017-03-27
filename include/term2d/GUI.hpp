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
    int SelectButton(int id, int highlight);
    void DeselectButton(int id);
    void RemButton(int index);
    void TitlebarKeys(char k);
    int Menu(std::vector<std::string> titles, int color);
    void RemMenu();
    bool OpenCloseMenu();
private:
    std::vector<SButton> buttons;
    std::vector<char> Titlebar_keys;
    std::vector<Title> _titles;
    std::vector<std::string> menu_titles;
    ScreenSpace *ss;
    int si = 0;
    bool did_init = false;
    bool menu_open = false;
};
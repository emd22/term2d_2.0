#pragma once
#include <term2d/Size.hpp>
#include <term2d/Space.hpp>
#include <term2d/Keyboard.hpp>
#include <term2d/Time.hpp>
#include <string>
#include <vector>
#include <functional>
#include <cctype>

class GUI;
class Program;

struct Title {
    std::string t;
    std::function<void(GUI *gui, ScreenSpace *ss)> callback;
    char key = ' ';
};

struct SButton {
    int x;
    int y;
    int color;
    std::string title;
    std::function<void(GUI *gui, ScreenSpace *ss)> callback;
};

struct Option {
    std::string t;
    std::function<void(GUI *gui, ScreenSpace *ss)> callback;
};

enum POSITION {
    LEFT,
    CENTER,
    RIGHT,
};

class GUI {
public:
    void Init(ScreenSpace *s);
    void Titlebar(const std::vector<Title> &titles, int y, bool tbk = true);
    void Modal(int w, int h, const std::string &message, const bool &input);
    void Button(int x, int y, std::string name, int color, std::function<void(GUI *, ScreenSpace *)> callback);
    void Rect(int x, int y, int w, int h, char style, int color);
    void Messagebar(std::string text, int position);
    void ClearMessage(int position = 4);
    int SelectButton(int id, int highlight);
    void DeselectButton(int id);
    void CheckButton(int id);
    void ClearWidgets();
    void ClearTitlebar();
    void PopButton();
    void RemButton(int index);
    void TitlebarKeys(char k);
    void Menu(std::vector<Option> options, int color, int titlebar_index);
    void RemMenu(int titlebar_index);
    bool OpenCloseMenu();
    void ClearScreen();
private:
    std::vector<SButton> buttons;
    std::vector<char> titlebar_keys;
    std::vector<Title> _titles;
    std::vector<Option> _options;
    
    ScreenSpace *ss;
    
    int proper_index = 0;
    int maxlen = 0;
    bool did_init = false;
    bool menu_open = false;
};
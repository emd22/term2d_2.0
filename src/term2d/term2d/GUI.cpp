#include <term2d/GUI.hpp>

void GUI::Init(ScreenSpace *s) {
    ss = s;
    did_init = true;
}

void GUI::TitlebarKeys(char k) {
    for (int i = 0; i < titlebar_keys.size(); i++) {
        if (k == titlebar_keys[i]) {
            _titles[i].callback(this);
        }
    }
}

void GUI::Titlebar(std::vector<Title> titles) {
    if(!did_init) { return; }

    _titles = titles;

    for (int i = 2; i < TermWidth(); i++) {
        for (int j = 0; j < titles.size(); j++) {
            ss->Label(i, 1, titles[j].t, 43);
            i += titles[j].t.length()+1;
            titlebar_keys.push_back(std::tolower(titles[j].t[0]));
        }
        return;
    }
}

void GUI::ClearScreen() {
    std::cout << "\e[1;1H\e[2J"; // clear screen
}

void GUI::Button(int x, int y, std::string name, int color) {
    if(!did_init) { return; }
    
    SButton button;
    button.title = name;
    button.x = x;
    button.y = y;
    button.color = color;

    ss->Label(x, y, name, color);

    buttons.push_back(button);
}

int GUI::SelectButton(int id, int highlight) {
    if(!did_init) { return 0; }

    if (id < buttons.size()) {
        ss->Label(buttons[id].x, buttons[id].y, buttons[id].title, highlight);
    }
    return buttons.size();
}

void GUI::DeselectButton(int id) {
    if(!did_init) { return; }

    if (id < buttons.size()) {
        ss->Label(buttons[id].x, buttons[id].y, buttons[id].title, buttons[id].color);
    }
}

void GUI::Menu(std::vector<std::string> titles, int color, int titlebar_index) {
    menu_titles = titles;
    proper_index = 0;
    
    for (int i = 0; i < titlebar_index; i++) {
        proper_index += _titles[i].t.length()+1;
    }

    for (int i = 0; i < titles.size(); i++) {
        Button(2+proper_index, 2+i, titles[i], color);
    }
}

void GUI::RemMenu(int titlebar_index) {
    for (int i = 0; i < menu_titles.size(); i++) {
        for (int j = 0; j < menu_titles[i].length(); j++) {
            ss->Erase(2+j+proper_index, 2+i, menu_titles.size());
        }
        buttons.pop_back();
    }
}

bool GUI::OpenCloseMenu() {
    if (menu_open) {
        menu_open = false;
    }
    else {
        menu_open = true;
    }
    return menu_open;
}
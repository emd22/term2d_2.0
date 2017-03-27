#include <term2d/GUI.hpp>

void GUI::Init(ScreenSpace *s) {
    ss = s;
    did_init = true;
}

void GUI::TitlebarKeys(char k) {
    for (int i = 0; i < Titlebar_keys.size(); i++) {
        if (k == Titlebar_keys[i]) {
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
            Titlebar_keys.push_back(std::tolower(titles[j].t[0]));
        }
        return;
    }
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

void GUI::RemButton(int index) {
    buttons.erase(buttons.begin()+index);
}

int GUI::Menu(std::vector<std::string> titles, int color) {
    int startindex = SelectButton(0, DEFAULT_COLOR);
    menu_titles = titles;
    
    for (int i = 0; i < titles.size(); i++) {
        Button(2, i+2, titles[i], color);
    }
    si = startindex;
    return startindex;
}
void GUI::RemMenu() {
    for (int i = menu_titles.size()-si; i < menu_titles.size(); i++) {
        RemButton(si+i);
    }
    for (int i = 0; i < menu_titles.size(); i++) {
        for (int j = 0; j < menu_titles[i].length(); j++) {
            ss->Erase(1+j, 2+i, menu_titles.size());
        }
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
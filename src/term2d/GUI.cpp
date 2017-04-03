#include <term2d/GUI.hpp>

void GUI::Init(ScreenSpace *s) {
    ss = s;
    did_init = true;
}

void GUI::TitlebarKeys(char k) {
    for (int i = 0; i < titlebar_keys.size(); i++) {
        if (k == titlebar_keys[i]) {
            _titles[i].callback(this, ss);
        }
    }
}

void GUI::Rect(int x, int y, int w, int h, char style, int color) {
    std::string line = "";

    for (int i = 0; i < w; i++) {
        line += style;
    }
    for (int i = 0; i < h; i++) {
        ss->Label(x, y+i, line, color);
    }
}

void GUI::Titlebar(std::vector<Title> titles) {
    if(!did_init) { return; }

    _titles = titles;

    for (int i = 2; i < TermWidth(); i++) {
        for (int j = 0; j < titles.size(); j++) {
            ss->Label(i, 1, titles[j].t, 43);
            i += titles[j].t.length()+1;
            if (titles[j].key == ' '){
                titlebar_keys.push_back(std::tolower(titles[j].t[0]));
            }
            else {
                titlebar_keys.push_back(titles[j].key);
            }
        }
        return;
    }
}

void GUI::ClearScreen() {
    std::cout << "\e[1;1H\e[2J"; // clear screen
}

void GUI::Button(int x, int y, std::string name, int color, std::function<void(GUI *, ScreenSpace *)> callback) {
    if(!did_init) { return; }
    
    SButton button;
    button.title = name;
    button.x = x;
    button.y = y;
    button.color = color;
    button.callback = callback;

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

void GUI::CheckButton(int id) {
    if (id < buttons.size()) {
        buttons[id].callback(this, ss);
    }
}

void GUI::DeselectButton(int id) {
    if(!did_init) { return; }

    if (id < buttons.size()) {
        ss->Label(buttons[id].x, buttons[id].y, buttons[id].title, buttons[id].color);
    }
}

void GUI::Menu(std::vector<Option> options, int color, int titlebar_index) {
    _options = options;
    proper_index = 0;
    maxlen = 0;

    for (int i = 0; i < options.size(); i++) {
        if (options[i].t.length() > maxlen) {
            maxlen = options[i].t.length();
        }
    }
    for (int i = 0; i < titlebar_index; i++) {
        proper_index += _titles[i].t.length()+1; // This is used for menu positioning(under corrisponding title)
    }
    Rect(2+proper_index, 2, maxlen, options.size(), ' ', color);
    for (int i = 0; i < options.size(); i++) {
        Button(2+proper_index, 2+i, options[i].t, color, options[i].callback);
    }
}

void GUI::RemMenu(int titlebar_index) {
    if(!did_init) { return; }

    for (int i = 0; i < _options.size(); i++) {
        for (int j = 0; j < _options[i].t.length(); j++) {
            ss->Erase(2+j+proper_index, 2+i, maxlen, _options[i].t.length());
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
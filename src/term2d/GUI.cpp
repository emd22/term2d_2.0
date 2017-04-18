// GUI.CPP

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

void GUI::Modal(int w, int h, const std::vector<std::string> &message, const bool &input) {
    int x = TermWidth()/2-(w/2);
    int y = TermHeight()/2-(h/2)-1;
    h++;
    Rect(x, y, w, h, '=', DEFAULT_COLOR);

    for (int i = 0; i < message.size(); i++) {
        ss->Label(x+1, y+i+1, message[i], 0);
    }

    if (input) {
        std::string text = "";

        while (true) {
            char k = Getch();
            if (k == 127) {
                ss->Edit(x+text.length(), y+3, '=', DEFAULT_COLOR);
                text.pop_back();
            }
            else if (k == '\n') {
                return;
            }
            else {
                text += k;
            }

            ss->Label(x+1, y+3, text, 0);

            TimeDelay(25);
        }
    }
    else {
        while (Getch() != '\n');
    }
}

void GUI::Titlebar(const std::vector<Title> &titles, int y, bool tbk) {
    if(!did_init) { return; }

    _titles = titles;

    for (int i = 2; i < TermWidth(); i++) {
        for (int j = 0; j < titles.size(); j++) {
            ss->Label(i, y+1, titles[j].t, 43);
            i += titles[j].t.length()+1;
            if (tbk) {
                if (titles[j].key == ' ') {
                    titlebar_keys.push_back(std::tolower(titles[j].t[0]));
                }
                else {
                    titlebar_keys.push_back(titles[j].key);
                }
            }
        }
        return;
    }
}

void GUI::Messagebar(std::string text, int position) {
    int pos = 0;
    if (position == POSITION::CENTER) {
        pos = TermWidth()/2-text.length()/2;
    }
    else if (position == POSITION::LEFT) {
        pos = 1;
    }
    else if (position == POSITION::RIGHT) {
        pos = TermWidth()-text.length();
    }

    ss->Label(pos, TermHeight(), text, 0);
}

void GUI::ClearMessage(int position) {
    int pos = 0;
    int maxpos = TermWidth()/3;
    int len = maxpos;
    
    if (position == POSITION::CENTER) {
        pos = maxpos;
    }
    else if (position == POSITION::LEFT) {
        pos = maxpos*2;
    }
    else if (position == POSITION::RIGHT) {
        pos = 0;
    }
    ss->Erase(pos, TermHeight()-1, len, 1);
}

void GUI::ClearWidgets() {
    Rect(0, 0, TermWidth(), TermHeight(), ' ', DEFAULT_COLOR);

    buttons.clear();
    titlebar_keys.clear();
    _titles.clear();
    menu_open = false;
}

void GUI::PopButton() {
    buttons.pop_back();
}

void GUI::ClearTitlebar() {
    titlebar_keys.clear();
    _titles.clear();
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

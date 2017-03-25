#include <term2d/GUI.hpp>

void GUI::Init(ScreenSpace *s) {
    ss = s;
    did_init = true;
}

void GUI::Titlebar(std::vector<std::string> titles) {
    if(!did_init) { return; }

    for (int i = 2; i < TermWidth(); i++) {
        for (int j = 0; j < titles.size(); j++) {
            ss->Label(i, 1, titles[j], 43);
            i += titles[j].length()+1;
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

    ss->Label(x, y, name, DEFAULT_COLOR);

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
        ss->Label(buttons[id].x, buttons[id].y, buttons[id].title, DEFAULT_COLOR);
    }
}
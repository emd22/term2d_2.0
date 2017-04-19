// MAIN.CPP

#include <T2D_ProjBuild/Main.hpp>

std::vector<Title> operator + (const std::vector<Title> &vec, const Title &t) {
    auto vec1 = vec;
    vec1.push_back(t);
    return vec1;
}

std::string operator & (const std::string &a, const std::string &b) {
    return a+b; 
}

void Toolbox(CB_PARAM) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({Option {"Titlebar", &Titlebar},
                   Option {"Button", &Button}}, 42, 1);
    } 
    else {
        gui->RemMenu(1);
    }
}

void Quit(CB_PARAM) {
    exit(0);
}

void OptionsMenu(CB_PARAM) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({Option {"Test Program", &TestingWidgets},
                   Option {"Quit", &Quit}}, 42, 0);
    }
    else {
        gui->RemMenu(0);
    }
}

void ReloadWidgets(CB_PARAM) {
    for (int i = 0; i < widgets.size(); i++) {
        BasicWidget cwid = widgets[i];
        int x = cwid.x;
        int y = cwid.y;
        int type = cwid.type;
        std::string message = cwid.message;
        std::vector<Title> titles = cwid.titles;

        if (type == W_TYPES::BUTTON) {
            ss->Label(x, y, message, 47);
        }
        else if (type == W_TYPES::TITLEBAR) {
            gui->Rect(1, y+1, TermWidth(), 1, '=', 42);
            ss->Label(2, y+1, "TITLEBAR", 42);
        }
    }
}

void noop(CB_PARAM) {}
void Titlebar(CB_PARAM) {
    int y = 1;
    
    while (true) {
        char k = Getch();

        if (k == ']' && y < TermHeight()-2) {
            ss->Erase(1, y, TermWidth(), 1);
            ReloadWidgets(gui, ss);
            y++;
        }
        if (k == '[' && y > 1) {
            ss->Erase(1, y, TermWidth(), 1);
            ReloadWidgets(gui, ss);
            y--;
        }

        if (k == '\n') {
            std::vector<Title> titles;
            std::string message = "";

            while (true) {
                char k = Getch();
                if (k == 127) {
                    message.pop_back();
                }
                else if (k == ',') {
                    titles.push_back(Title {message, &noop});
                    message = "";
                }
                else if (k == '\n') {
                    WidgetsAdd(BasicWidget {1, y, W_TYPES::TITLEBAR, "", titles});
                    MainWidgets(gui, ss);
                    return;
                }
                else {
                    message += k;
                }

                gui->Titlebar(titles+Title {message, &noop}, y, false);

                ss->Erase(1, y, message.length(), 1);
                
                TimeDelay(25);
            }
        }

        gui->Titlebar({Title {"title1", &noop}}, y, false);
        TimeDelay(25);
    }
    WidgetsAdd(BasicWidget {1, y, W_TYPES::TITLEBAR, "", {Title {"title1", &noop}}});
    MainWidgets(gui, ss);
}

void Button(CB_PARAM) {
    int x = 0;
    int y = 0;

    std::string message = "Button1";
    gui->Button(x, y, message, 42, &noop);

    while (true) {
        gui->PopButton();
        char k = Getch();
        
        if (k == ']' && y < TermHeight()-2) {
            ss->Erase(x, y, message.length(), 1);
            ReloadWidgets(gui, ss);
            y++;
        }
        if (k == '[' && y > 1) {
            ss->Erase(x, y, message.length(), 1);
            ReloadWidgets(gui, ss);
            y--;
        }
        if (k == '=' && x < TermWidth()-2) {
            ss->Erase(x, y, message.length(), 1);
            x++;
        }
        if (k == '-' && x > 1) {
            ss->Erase(x, y, message.length(), 1);
            x--;
        }
        if (k == '\n') {
            message = "";
            while (true) {
                gui->PopButton();
                char k = Getch();
                if (k == 127) {
                    message.pop_back();
                }
                else if (k == '\n') {
                    WidgetsAdd(BasicWidget {x, y, W_TYPES::BUTTON, message});
                    MainWidgets(gui, ss);
                    return;
                }
                else {
                    message += k;
                }

                ss->Erase(x, y, message.length(), 1);
                gui->Button(x, y, message, 42, &noop);
                
                TimeDelay(25);
            }
        }

        gui->Button(x, y, message, 42, &noop);
        TimeDelay(25);
    }
    WidgetsAdd(BasicWidget {x, y, W_TYPES::BUTTON, message});
    MainWidgets(gui, ss);
}

void WidgetsAdd(BasicWidget widget) {
    widgets.push_back(widget);
}

void Program::Keypress() {
    char k = Getch(); //A homemade Getch that works on linux aswell 

    //loop through keys
    if (k == 'q') { ss->Quit(); }
    if (k == '\t') { 
        gui->DeselectButton(keyindex);
        keyindex++; 
    }
    if (k == '\n' || k == '\r') {
        gui->CheckButton(keyindex);
    }

    gui->TitlebarKeys(k);

    if (keyindex >= maxindex || keyindex < 0) {
        keyindex = 0;
    }
    maxindex = gui->SelectButton(keyindex, 44);
}

void MainWidgets(CB_PARAM) {
    gui->ClearWidgets();
    ReloadWidgets(gui, ss);
    gui->Titlebar({Title {"Options", &OptionsMenu},
                   Title {"Toolbox", &Toolbox}}, 0);
}

void TestingM(CB_PARAM) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({Option {"Edit Page", &MainWidgets}}, 42, 0);
    }
    else {
        gui->RemMenu(0);
    }
}

void TestingWidgets(CB_PARAM) {
    Program pro(gui, ss);
    gui->ClearWidgets();
    
    for (int i = 0; i < widgets.size(); i++) {
        BasicWidget &cwid = widgets[i];
        int x = cwid.x;
        int y = cwid.y;
        int type = cwid.type;
        std::string message = cwid.message;
        std::vector<Title> titles = cwid.titles;

        if (type == W_TYPES::BUTTON) {
            gui->Button(x, y, message, 47, &noop);
        }
        else if (type == W_TYPES::TITLEBAR) {
            gui->Titlebar(titles, y, false);
        }
    }

    gui->Titlebar({Title {"Page", &TestingM}}, 0);
}

Program::Program(GUI *g, ScreenSpace *s) {
    gui = g;
    ss = s;
}

int main() {
    GUI gui;
    ScreenSpace ss;
    Program Program(&gui, &ss);
    
    gui.Init(&ss);
    ss.Create();

    Color color;
    color.back_color = 45;
    color.text_color = 44;
    color.textbox_color = 47;
    color.textbox_back_color = 44;

    gui.Modal(50, 10, {"Dingus",
                       "mingus",
                       "swibbity swoop", 
                       "you better watch out you little poop"}, 
                       true, color);
    MainWidgets(&gui, &ss);

    while (true) {
        Program.Keypress();
        TimeDelay(25); //sleep 25 ms to avoid high cpu usage
    }

    return 0;
}

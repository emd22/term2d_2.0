#include <Example/Main.hpp>

void Button1(GUI *gui) {
    gui->Rect(20, 15, 5, 5, '$', DEFAULT_COLOR);
}

void FMenu(GUI *gui) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({Option {"New", Button1},
                   Option {"Open", Button1}}, 42, 0);
    }
    else {
        gui->RemMenu(0);
    }
}

void Examples::Keypress() {
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

Examples::Examples(GUI *g, ScreenSpace *s) {
    gui = g;
    ss = s;
}

int main() {
    GUI gui;
    ScreenSpace ss;
    Examples examples(&gui, &ss);

    gui.ClearScreen();
    ss.Create(50, 50);

    gui.Init(&ss);
    gui.Titlebar({Title {"File", &FMenu}});

    gui.Button(10, 10, "Button1", 47, &Button1);
    gui.Button(20, 10, "Button2", 47, &Button1);

    while (true) {
        examples.Keypress();
        TimeDelay(25); //sleep 25 ms to avoid high cpu usage
    }

    return 0;
}
#include <Example/Main.hpp>

void noop(GUI *gui, ScreenSpace *ss) {}

void NewPage(GUI *gui, ScreenSpace *ss) {
    ss->Create();
    SecWidgets(gui, ss);
}

void FMenu(GUI *gui, ScreenSpace *ss) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({Option {"New", &NewPage}}, 42, 0);
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

void MainWidgets(GUI *gui, ScreenSpace *ss) {
    gui->Titlebar({Title {"Page", &FMenu}});
}

void SecWidgets(GUI *gui, ScreenSpace *ss) {
    gui->Button(10, 10, "Goto previous page", 47, &MainWidgets);
}

Examples::Examples(GUI *g, ScreenSpace *s) {
    gui = g;
    ss = s;
}

int main() {
    GUI gui;
    ScreenSpace ss;
    Examples examples(&gui, &ss);
    
    gui.Init(&ss);
    ss.Create();

    MainWidgets(&gui, &ss);

    while (true) {
        examples.Keypress();
        TimeDelay(25); //sleep 25 ms to avoid high cpu usage
    }

    return 0;
}
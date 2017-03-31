#include <term2d.hpp>

void FMenu(GUI *gui) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({"Thi", "Test2", "More Tests", "Fourth Test"}, 42, 0);
    }
    else {
        gui->RemMenu(0);
    }
}

void EMenu(GUI *gui) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({"More Tests1", "More Tests Again"}, 42, 1);
    }
    else {
        gui->RemMenu(1);
    }
}

void VMenu(GUI *gui) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({"Other More Tests", "Other_More_Tests2"}, 42, 2);
    }
    else {
        gui->RemMenu(2);
    }
}

int main() {
    int buttonindex = 0;
    int maxindex = 0;
    ScreenSpace ss;
    GUI gui;
    
    gui.ClearScreen();
    ss.Create(50, 50);

    gui.Init(&ss);
    gui.Titlebar({Title {"File", &FMenu},
                  Title {"Edit", &EMenu},
                  Title {"View", &VMenu}});
    

    gui.Button(10, 10, "Test1", 47);
    gui.Button(20, 10, "Test2", 47);

    while (true) {
        char k = Getch();        
        if (k == 'q') { ss.Quit(); }
        if (k == '\t') { 
            gui.DeselectButton(buttonindex);
            buttonindex++; 
        }

        gui.TitlebarKeys(k);

        if (buttonindex >= maxindex || buttonindex < 0) {
            buttonindex = 0;
        }
        maxindex = gui.SelectButton(buttonindex, 44);
        TimeDelay(25); //sleep 25 ms to avoid high cpu usage
    }

    return 0;
}
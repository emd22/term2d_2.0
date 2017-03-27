#include <term2d.hpp>

void FMenu(GUI *gui) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({"Test1", "Test2", "Test3", "Test4"}, 42);
    }
    else {
        gui->RemMenu();
    }
}

void EMenu(GUI *gui) {
    if (gui->OpenCloseMenu()) {
        gui->Menu({"More1", "More2"}, 42);
    }
    else {
        gui->RemMenu();
    }
}

int main() {
    std::cout << "\e[1;1H\e[2J"; // clear screen
    int buttonindex = 0;
    int maxindex = 0;
    ScreenSpace ss;
    GUI gui;
    
    ss.Create(50, 50);

    gui.Init(&ss);
    gui.Titlebar({Title {"File", &FMenu},
                  Title {"Edit", &EMenu}});

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
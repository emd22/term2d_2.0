#include <term2d.hpp>

int main() {
    std::cout << "\e[1;1H\e[2J"; // clear screen
    int buttonindex = 0;
    int maxindex = 0;
    ScreenSpace ss;
    GUI gui;
    
    ss.Create(50, 50);

    gui.Init(&ss);
    gui.Titlebar({"File", "Edit", "Settings", "View"});
    gui.Button(10, 10, "ARNOLD", 43);
    gui.Button(20, 10, "Mutant", 43);

    while (true) {
        char k = Getch();        
        if (k == 'q') { ss.Quit(); }
        if (k == '\t') { 
            gui.DeselectButton(buttonindex);
            buttonindex++; 
        }

        if (buttonindex >= maxindex || buttonindex < 0) {
            buttonindex = 0;
        }
        maxindex = gui.SelectButton(buttonindex, 43);
    }

    return 0;
}
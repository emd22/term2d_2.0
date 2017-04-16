// #include <TextEditor/Main.hpp>

// void noop(CB_PARAM) {}

// std::string TextInput(int &x, int &y, GUI *gui, ScreenSpace *ss, std::vector<std::string> *lines, const int &padding, const int &ypadding, std::string &line) {
//     std::string input = "";
//     std::string input_sec = "";

//     int inputlen = 0;

//     while (true) {
//         ss->Label(1+padding, y+ypadding, input, DEFAULT_COLOR);
//         int k = Getch();

//         if (k == 127) { //Backspace key
//             if ((input.length()+y) > 1) {
//                 if (input.length() == 0) {
//                     ss->Erase(1, y+ypadding, input.length()+padding, 1);
//                     lines->erase(lines->begin()+y);
//                     y--;
//                     input = lines[0][y-1];
//                 }
//                 else {
//                     x--; 
//                     ss->Erase(1+padding, y+ypadding, input.length(), 1);
//                     input.pop_back();
//                     ss->Label(1+padding, y+ypadding, input+input_sec, DEFAULT_COLOR);
//                     CaretPos(padding+1, y+ypadding);
//                 }    
//             }
//         }

//         else if (k == 568) {   //Left arrow
//             if (input.length() != 1) {
//                 gui->ClearMessage(POSITION::RIGHT);
//                 gui->Messagebar("KEY:Left Arrow", POSITION::RIGHT);
//                 x--;
//                 input_sec = input[x]+input_sec;
//                 input.pop_back();
//             }
//             else {
//                 CaretPos(padding+1, y+ypadding);
//             }
//         }

//         else if (k == 567) {   //Right arrow
//             if (x >= inputlen) {
//                 x = inputlen;
//             }
//             else {
//                 x++;
//                 gui->ClearMessage(POSITION::RIGHT);
//                 gui->Messagebar("KEY:Right Arrow", POSITION::RIGHT);
            
//                 input.push_back(input_sec[0]);
//                 input_sec.erase(0, 1);
//             }
//         }

//         else if (k == 565) {
//             if (y > lines[0].size()) {
//                 line = input+input_sec;
//             }
//             if (y > 1) {
//                 input += input_sec;
//                 input_sec = "";
//                 y--;
//                 input = lines[0][y-1];
//             }
            
//         }

//         else if (k == 566) {
//             if (y < lines[0].size()+1) {
//                 if (y < lines[0].size()) {
//                     input += input_sec;
//                     input_sec = "";
//                     y++;
//                     input = lines[0][y-1];
//                 }
//                 else {
//                     input_sec = "";
//                     y++;
//                     input = line;
//                 }
//             }
//         }

//         else if (k != '\n') {
//             input += k;
//             x++;
//             ss->Label(1+padding, y+ypadding, input+input_sec, DEFAULT_COLOR);

//             std::string message = "LEN:"+std::to_string(input.length()+input_sec.length())+','+std::to_string(lines[0].size()+1);

//             gui->ClearMessage();
//             gui->Messagebar(message, POSITION::CENTER);
//             gui->Messagebar(std::to_string(x), POSITION::LEFT);
//             gui->Messagebar("KEY:"+std::to_string(k), POSITION::RIGHT);

//             inputlen = x;
//         }

//         else {
//             x = 0;
//             break;
//         }

//         if (k == '`') {
//             ss->Quit();
//         }
//     }
//     return input+input_sec;
// }

// void Keypress(CB_PARAM, int &x, int &y) {
//     std::vector<std::string> lines;
//     std::string line = "";

//     const int padding = 4;
//     const int ypadding = 1;

//     while (true) {
//         ss->Label(1, y+1, std::to_string(lines.size()), 42);
//         CaretPos(padding+1, y+ypadding);
//         line = TextInput(x, y, gui, ss, &lines, padding, ypadding, line);
//         y++;
//         lines.push_back(line);
//         line = "";
//     }
// }

// int main() {
//     GUI gui;
//     ScreenSpace ss;

//     int y = 1;
//     int x = 0;

//     gui.Init(&ss);
//     ss.Create();
//     Keypress(&gui, &ss, x, y);
// }
#include <term2d/RunAnimation.hpp>

void RunAnimation::Init(Animation *ani, std::string file_source) {
    ani->LoadFile("../include/animations/"+file_source); // load animation file
    ani->Parse(); // parse animation file
    frames = ani->GetFrames();
    amt_frames = frames.size();
}

int RunAnimation::Run(ScreenSpace *ss, int x, int y) {
  for (int frame = 0; frame < amt_frames; frame++) { // go through all frames and display to screen.
    for (int line = 0; line < frames[frame].data_lines.size(); line++) { // read through frame and display each line to screen
      ss->Label(x, y+line, frames[frame].data_lines[line], 37); // display line(color 37; foreground white)
    }
    ss->Print(); // print screenspace to terminal emulator
    TimeDelay("ms", frames[frame].speed); // wait for speed in frame (milliseconds)
    ss->ClearObjs();
  }
}

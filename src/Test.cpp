#include <term2d/term2d.hpp>

/*
term2dterm2d                                                2dterm2dter   term2dterm2d
term2dterm2d    2dterm2dter     rm2dter   dterm   term2          m2dterm  term      2dte
    2dte       m2dt     term   erm2     2dt    m2d    2dt          dterm2 term      2dte
    2dte      rm2d       erm2 term      2dt    m2d    2dt           term2 term      2dte
    2dte      rm2dterm2dterm2 term      2dt    m2d    2dt         2dterm2 term      2dte
    2dte      rm2d            term      2dt           2dt      erm2dter   term      2dte
    2dte       m2dt     term2 term      2dt           2dt    dterm        term      2dte
    2dte        2dterm2dter   term      2dt           2dt   2dterm2term2d term2dterm2d
*/

int main() {
  Animation ani;
  ScreenSpace ss;
  ss.Create(TermWidth(), TermHeight(), '.'); //create screenspace
  ani.LoadFile("../include/animations/tank.ani.asc"); //load animation file
  ani.Parse(); //parse animation file

  std::vector<Frame> frames = ani.GetFrames();
  int amt_frames = frames.size();
  DisableKeyPrint();

  char key;

  for (;;) {
    for (int frame = 0; frame < amt_frames; frame++) { //go through all frames and display to screen.
      key = CurKey(); //get current keyboard press
      if (key == 'q') { // if 'q' pressed then quit.
        EnableKeyPrint();
        return 0;
      }

      for (int line = 0; line < frames[frame].data_lines.size(); line++) { //read through frame and display each line to screen
        ss.Label(0, line, frames[frame].data_lines[line], 37); //display line(color 37; foreground white)
      }
      ss.Print(); // print screenspace to terminal
      TimeDelay("ms", 350); // wait for 350 milliseconds
      ss.Reset('.'); // reset screenspace to the period ascii character
      ss.ClearObjs(); //clear all created objects(labels, edits, etc.)
    }
  }
}

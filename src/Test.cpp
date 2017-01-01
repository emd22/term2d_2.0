#include <term2d/term2d.hpp>

int main() {
  Animation ani;
  ScreenSpace ss;
  ss.Create(20, 18, '.');
  ani.LoadFile("../include/animations/tank.ani.asc");
  ani.Parse();
  std::vector<Frame> frames = ani.GetFrames();
  int frame_amt = frames.size();

  for (;;) {


    TimeDelay("ms", 750)

  }
}

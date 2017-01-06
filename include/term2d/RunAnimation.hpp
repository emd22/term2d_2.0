#pragma once

#include <term2d/term2d.hpp>

class RunAnimation {
public:
  void Init(Animation *ani, std::string file_source);
  int Run(ScreenSpace *ss, int x, int y, bool time_stamp);
private:
  std::vector<Frame> frames = {}; // get all the frames
  int amt_frames = 0; // get amount of frames
};

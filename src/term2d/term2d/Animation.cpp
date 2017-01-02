#include <term2d/Animation.hpp>

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

int Animation::LoadFile(std::string filename) {
  file = std::ifstream(filename);
  if (!file.is_open()) {
    std::cout << "could not open file!\n";
    return 1;
  }
  while (std::getline(file, line)) {
    file_data.push_back(line);
  }
}

void Animation::Parse() {
  std::string frame_name = "";

  for (int i = 0; file_data[i] != "kill"; i++) {
    at_frame++;
    if (file_data[i][0] == '(') {
      for (int t = 0; file_data[i][t] != ')'; t++) {
        frame_name += file_data[i][t];
      }
      frame_name.erase(frame_name.begin(), frame_name.begin()+1);

      if (frame_name.length() > 0) {
        if (file_data[i][frame_name.length()+2] == '#' && file_data[i][frame_name.length()+3] == '!') {
          i++;
          for (int j = 0; file_data[i][0] != '!' && file_data[i][1] != '#'; j++) {
            if (j > file_data[i].length()) {
              i++;
              j = 0;
              data_lines.push_back(line);
              line = "";
            }
            line += file_data[i][j];
          }
          if (at_frame > 1) {
            data_lines[0].erase(data_lines[0].begin(), data_lines[0].begin()+1);
          }
          Frame frame;
          frame.name = frame_name;
          frame.data_lines = data_lines;
          frame_name = "";
          data_lines.clear();
          frames.push_back(frame);
        }
      }
    }
  }
}

std::vector<Frame> Animation::GetFrames() {
  return frames;
}

#include <term2d/LoadAnimation.hpp>

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
    if (file_data[i][0] == '(') {
      for (int t = 0; file_data[i][t] != ')'; t++) {
        if (i > file_data[i].length()) {
          i++;
        }
        frame_name += file_data[i][t];
      }
      frame_name.erase(frame_name.begin(), frame_name.begin()+1);
      std::cout << "framename-" << frame_name << '\n';

      if (frame_name.length() > 0) {
        if (file_data[i][frame_name.length()+2] == '/' && file_data[i][frame_name.length()+3] == '-') {
          std::cout << "opened frame '" << frame_name << "'\n";
          i++;
          for (int j = 0; file_data[i][0] != '-' && file_data[i][1] != '\\'; j++) {
            if (j > file_data[i].length()) {
              i++;
              j = 0;
              std::cout << frame_name << ", -1 = " << i-2 << '\n';
              data_lines.push_back(line);
              line = "";
            }
            line += file_data[i][j];
          }
          if (file_data[i][0] != '-' && file_data[i][1] != '\\') {
            std::cout << "closed frame '" << frame_name << "'\n";
          }
          std::cout << "pushed\n";
          Frame frame;
          frame.name = frame_name;
          frame.data_lines = line;
          frame_name = "";
          frame_data.clear();
          frames.push_back(frame);
        }
      }
    }
  }
}

std::vector<Frame> Animation::GetFrames() {
  return frames;
}

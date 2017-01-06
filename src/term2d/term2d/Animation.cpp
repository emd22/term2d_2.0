#include <term2d/Animation.hpp>

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

int Animation::Parse() {
  std::string frame_name = "";

  for (int i = 0; file_data[i] != "kill"; i++) {
    if (i >= file_data.size()) {
      //if at end of file and no 'kill' statement
      break;
    }
    at_frame++; //increasing frame number

    if (file_data[i][0] == '(') {
      //getting frame name
      for (int t = 0; file_data[i][t] != ')'; t++) {
        frame_name += file_data[i][t];
      }
      frame_name.erase(frame_name.begin(), frame_name.begin()+1); //erase first character of frame

      if (frame_name.length() > 0) {
        //getting frame data
        if (file_data[i][frame_name.length()+2] == '#' && file_data[i][frame_name.length()+3] == '!') {
          i++;
          for (int j = 0; file_data[i][0] != '!' && file_data[i][1] != '#'; j++) {
            if (j > file_data[i].length()) { //go to next line
              i++;
              j = 0;
              data_lines.push_back(line);
              line = "";
            }
            line += file_data[i][j];
          }
          //cutting off extra bit that somehow connects with the frame data after first frame
          if (at_frame > 1) {
            data_lines[0].erase(data_lines[0].begin(), data_lines[0].begin()+1);
          }
          //pushing different data from the frame to a vector of struct 'Frame'
          Frame frame;
          frame.name = frame_name;
          frame.data_lines = data_lines;
          frame.id = at_frame;
          frame.speed = speed;
          frame_name = "";
          data_lines.clear();
          frames.push_back(frame);
        }
      }
    }
    else if (file_data[i][0] == '\n' || file_data[i] [0] == '\0' || file_data[i][0] == '\r') {
      at_frame--;
      std::cout << "hit space, skipping...(frame:" << at_frame << ",line:" << i << ")\n";
    }
    else if (file_data[i][0] == '#' && file_data[i][1] == 's') {
      std::string value = "";
      if (file_data[i][2] == '(') {
        for (int j = 2; file_data[i][j] != ')'; j++) {
          value += file_data[i][j];
        }
        value.erase(value.begin(), value.begin()+1);
        speed = (int)::atof(value.c_str());
        std::cout << value << '\n';
      }
      at_frame--;
    }
    else {
      std::cout << "hit unknown character '" << file_data[i][0] << "'\n";
      i++;
      at_frame--;
    }
  }
}

std::vector<Frame> Animation::GetFrames() {
  return frames;
}

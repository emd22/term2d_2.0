#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define START_FRAME file_data[i][frame_name.length()+2] == '>' && file_data[i][frame_name.length()+3] == ':' && file_data[i][frame_name.length()+4] == '>'
#define END_FRAME file_data[i][j] == '<' && file_data[i][j+1] == ':' && file_data[i][j+2] == '<'

struct Frame {
  std::string name;
  std::vector<std::string> data_lines;
};

class Animation {
public:
  int LoadFile(std::string filename);
  void Parse();
  std::vector<Frame> GetFrames();
private:
  std::ifstream file;
  std::string line;
  std::vector<std::string> file_data;
  std::vector<std::string> data_lines;
  std::vector<Frame> frames;
};

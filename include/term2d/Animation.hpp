#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Frame {
  std::string name;
  std::vector<std::string> data_lines;
  int id;
  int speed;
};

class Animation {
public:
  int LoadFile(std::string filename);
  int Parse();
  std::vector<Frame> GetFrames();
private:
  std::ifstream file;
  std::string line;
  std::vector<std::string> file_data;
  std::vector<std::string> data_lines;
  int at_frame = 0;
  int speed = 0;
  std::vector<Frame> frames;
};

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

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
  int at_frame = 0;
  std::vector<Frame> frames;
};

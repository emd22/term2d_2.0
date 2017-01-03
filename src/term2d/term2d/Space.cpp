#include <term2d/Space.hpp>

void ScreenSpace::Create(int width, int height, char style) {
  // set member variables
  _width = width;
  _height = height-1;

  _style = style;

  for (int h = 0; h < _height; h++) {
    for (int w = 0; w < _width; w++) {
      line.push_back(style);
    }
    space.push_back(line);
    line.clear();
  }
}

void ScreenSpace::Edit(int x, int y, char style, int color) {
  if (x <= _width && y < _height && y >= 0 && x >= 0) {
    Object obj;
    obj.message = style;
    obj.color = color;
    obj.x = x;
    obj.y = y;
    objs.push_back(obj);
  }
}

void ScreenSpace::RawEdit(int x, int y, char style) {
  if (x <= _width && y < _height && y >= 0 && x >= 0) {
    space[y][x] = style;
  }
}

void ScreenSpace::Label(int x, int y, std::string message, int color = DEFAULT_COLOR) {
  for (int _x = 0; _x < message.length(); _x++) {
    Edit(_x+x, y, message[_x], color);
  }
}

void ScreenSpace::RawLabel(int x, int y, std::string message) {
  for (int _x = 0; _x < message.length(); _x++) {
    RawEdit(_x+x, y, message[_x]);
  }
}

int ScreenSpace::FindObjAtCoords(int x, int y) {
  for (int i = 0; i < objs.size(); i++) {
    if (objs[i].x == x && objs[i].y == y) {
      return i;  //Entity exists
    }
  }
  return -1; //Entity does not exist
}

void ScreenSpace::Print() {
  int pos;
  assert(_height == space.size());
  for (int y = 0; y < _height; y++) {
    for (int x = 0; x < space[y].size(); x++) {
      pos = FindObjAtCoords(x, y);
      if (pos > -1) {
        ColoredText(objs[pos].message, objs[pos].color);
      } else {
        std::cout << space[y][x];
      }
    }
    std::cout << "\n";
  }
  std::cout << "\r";
  SetTermCursorPos(0, 0);
}

void ScreenSpace::UpdateSize(int width, int height) {
  _width = width;
  _height = height;
}

void ScreenSpace::Reset(char style) {
  _style = style;

  line.clear();
  space.clear();

  for (int h = 0; h < _height; h++) {
    for (int w = 0; w < _width; w++) {
      line.push_back(style);
    }
    space.push_back(line);
    line.clear();
  }
}

void ScreenSpace::ClearObjs() {
  objs.clear();
}

#include <Space.hpp>

void ScreenSpace::Create(int width, int height, char style) {
  _width = width;
  _height = height;

  _style = style;

  for (int h = 0; h < _height; h++) {
    for (int w = 0; w < _width; w++) {
      line.push_back(style);
    }
    space.push_back(line);
    line.clear();
  }
}

void ScreenSpace::Edit(int x, int y, char style, int color, int precedence = 50) {
  if (x <= _width && y <= _height-1 && y >= 0 && x >= 0) {
    Object obj;
    obj.message = style;
    obj.color = color;
    obj.x = x;
    obj.y = y;
    obj.precedence = precedence;
    objs.push_back(obj);
  }
}

void ScreenSpace::Label(int x, int y, std::string message, int color = DEFAULT_COLOR, int precedence = 50) {
  for (int _x = 0; _x < message.length(); _x++) {
    Edit(_x+x, y, message[_x], color, precedence);
  }
}

int ScreenSpace::FindObjAtCoords(int x, int y) {
  for (int i = 0; i < objs.size(); i++) {
    if (objs[i].x == x && objs[i].y == y) {
      return i;  //Text exists
    }
  }
  return -1; //Text does not exist
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

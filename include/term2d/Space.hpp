#pragma once

#include <vector>
#include <string>
#include <term2d/ColorText.hpp>
#include <term2d/Caret.hpp>
#include <cassert>

struct Obj {
  int x;
  int y;
  char style;
  int color;
};

class ScreenSpace {
public:
  void Create(int w, int h);
  void Edit(int x, int y, char style, int color);
  void RawEdit(int x, int y, char style);
  void Label(int x, int y, std::string message, int color);
  void UpdateSize(int width, int height);
  void Reset();
  void Quit();
private:
  std::vector<std::string> space;
  std::vector<Obj> objs;

  int _width = 0;
  int _height = 0;

  int lastx = 1;
  int lasty = 1;

  char _style = '?';
};

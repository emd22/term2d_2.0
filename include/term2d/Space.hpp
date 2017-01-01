#pragma once

#include <vector>
#include <string>
#include <term2d/ColorText.hpp>
#include <term2d/Caret.hpp>
#include <cassert>

struct Object {
  char message = '?';
  int color = DEFAULT_COLOR;
  int x;
  int y;
  int precedence;
};

class ScreenSpace {
public:
  void Create(int width, int height, char style);
  void Edit(int x, int y, char style, int color, int precedence);
  void RawEdit(int x, int y, char style);
  void Label(int x, int y, std::string message, int color, int precedence);
  void RawLabel(int x, int y, std::string message);
  int FindObjAtCoords(int x, int y);
  void Print();
  void UpdateSize(int width, int height);
  void ClearObjs();
  void Reset(char style);
private:
  std::vector<char> line;
  std::vector<std::vector<char>> space;
  std::vector<Object> objs;

  int _width = 0;
  int _height = 0;

  char _style = '?';
};

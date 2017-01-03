#pragma once
#include <string>
#include <algorithm>

std::string StringLower(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}
std::string StringUpper(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  return str;
}

#pragma once
#include <string>

struct PatternMatchingMachine {
  const std::string & x;
  PatternMatchingMachine(const std::string & x) : x(x) {};
};
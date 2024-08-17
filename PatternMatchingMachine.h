#pragma once
#include "State.h"
#include <string>
#include <vector>

struct PatternMatchingMachine {
  const std::string & x;
  const std::vector<std::string> & K;
  PatternMatchingMachine(const std::string & x, const std::vector<std::string> & K) : x(x), K(K) {};
  std::vector<State> states;

  State* g(const State * state, const char & ch);
  State* f(const State * state);
  std::vector<std::string> output(const State * state);

  void match();
};
#pragma once
#include "State.h"
#include <string>
#include <vector>

struct PatternMatchingMachine {
  const std::string & x;
  const std::vector<std::string> & K;

  std::vector<State> states;
  void enter(const std::string & a);

  State* g(const State * state, const char & ch);
  void construct_g();

  State* f(const State * state);
  void construct_f();

  std::vector<std::string> output(const State * state);

  void match();

  PatternMatchingMachine(const std::string & x, const std::vector<std::string> & K) : x(x), K(K) {
    construct_g();
    construct_f();
  };
};
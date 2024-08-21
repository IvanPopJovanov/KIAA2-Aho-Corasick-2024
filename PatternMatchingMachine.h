#pragma once
#include "State.h"
#include <string>
#include <vector>

#define MAX_STATES 1024

struct PatternMatchingMachine {
  const std::string & x;
  const std::vector<std::string> & K;

  std::vector<State> states = std::vector<State>(MAX_STATES);
  void enter(const std::string & a, state_id &newstate);

  state_id g(const state_id state, const char & ch);
  void construct_g();

  state_id f(const state_id state);
  void construct_f();

  std::vector<std::string> output(state_id state);

  void match();

  PatternMatchingMachine(const std::string & x, const std::vector<std::string> & K) : x(x), K(K) {
    for(int i = 0; i < MAX_STATES; ++i) {
      for (char a = 0; a < 127; ++a) {
        states[i].g.insert(std::make_pair(a, FAIL));
        states[i].f = FAIL;
      }
    }
    construct_g();
    construct_f();
  };
};
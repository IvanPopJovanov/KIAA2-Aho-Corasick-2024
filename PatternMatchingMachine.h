#pragma once
#include "State.h"
#include <string>
#include <vector>
#include <fstream>

#define MAX_STATES 1024
#define ALPHABET_SIZE 127

class PatternMatchingMachine {
  const std::string & x;
  const std::vector<std::string> & K;

  std::vector<State> states = std::vector<State>(MAX_STATES);
  void enter(const std::string & a, state_id &newstate);

  state_id g(const state_id state, const char & ch);
  void construct_g();

  state_id f(const state_id state);
  void construct_f();

  std::vector<std::string> output(state_id state);

  std::ofstream out_file;

public:

  void match();

  PatternMatchingMachine(const std::string & x, const std::vector<std::string> & K, std::string out_name) : x(x), K(K) {
    out_file.open(out_name);

    for(int i = 0; i < MAX_STATES; ++i) {
      for (char a = 0; a < ALPHABET_SIZE; ++a) {
        states[i].g.insert(std::make_pair(a, FAIL));
        states[i].f = FAIL;
      }
    }
    construct_g();
    construct_f();
  };
};
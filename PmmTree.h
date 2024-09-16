#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>

#define MAX_STATES 1024
#define ALPHABET_SIZE 127 
#define FAIL -1

class PmmTree {
  const std::string & x;
  const std::vector<std::string> & K;

  std::map<char, int> g[MAX_STATES];
  int f[MAX_STATES];
  bool output[MAX_STATES];
  std::list<std::string> outputs[MAX_STATES];

  int state = 0;
  int n;
  int k;
  
  void enter(const std::string & a, int &newstate);

  void construct_g();

  void construct_f();

public:

  PmmTree(const std::string & x, const std::vector<std::string> & K) : x(x), K(K) { 
    n = x.size();
    k = K.size();

    for(int i = 0; i < MAX_STATES; ++i) {
      for(int j = 0; j < ALPHABET_SIZE; ++j) {
        g[i][j] = FAIL;
      }
      f[i] = FAIL;
      output[i] = false;
    }

    construct_g();
    construct_f();
  };

  void match();
};
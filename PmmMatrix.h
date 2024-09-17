#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <fstream>

#define MAX_STATES 1024
#define ALPHABET_SIZE 127 
#define FAIL -1

class PmmMatrix {
  const std::string & x;
  const std::vector<std::string> & K;

  int g[MAX_STATES][ALPHABET_SIZE];
  int f[MAX_STATES];
  bool output[MAX_STATES];
  std::list<std::string> outputs[MAX_STATES];

  int state = 0;
  int n;
  int k;
  
  void enter(const std::string & a, int &newstate);

  void construct_g();

  void construct_f();
  
  std::ofstream out_file;

public:

  PmmMatrix(const std::string & x, const std::vector<std::string> & K, std::string out_name) : x(x), K(K) { 
    out_file.open(out_name);
    
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
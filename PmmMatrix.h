#pragma once
#include <string>
#include <vector>
#include <list>
#include <queue>

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
  
  void enter(const std::string & a, int &newstate) {
    int m = a.size();
    state = 0;
    int j = 0;
    while(g[state][a[j]] != FAIL) {
      state = g[state][a[j]];
      ++j;
    }
    for(int p = j; p < m; ++p) {
      ++newstate;
      g[state][a[p]] = newstate;
      state = newstate;
    }
    output[state] = true;
    outputs[state].push_back(a);
  }

  void construct_g() {
    int newstate = 0;
    for(int i = 0; i < k; ++i) {
      enter(K[i], newstate);
    }
    for(int a = 0; a < ALPHABET_SIZE; ++a) {
      if(g[0][a] == FAIL)
        g[0][a] = 0;
    }
  }

  void construct_f() {
    std::queue<int> queue;

    for(int a = 0; a < ALPHABET_SIZE; ++a) {
      int s = g[0][a];
      if(s != 0) {
        queue.push(s);
        f[s] = 0;
      }
    }
    
    while(!queue.empty()) {
      int r = queue.front();
      queue.pop(); 

      for(int a = 0; a < ALPHABET_SIZE; ++a) {
        int s = g[r][a];
        if(s != FAIL) {
          queue.push(s);
          state = f[r];
          while (g[state][a] == FAIL)
            state = f[state];
          f[s] = g[state][a];
          output[s] = true;
          for(auto o : outputs[f[s]])
            outputs[s].push_back(o);
        }
      }
    }

  }

public:

  PmmMatrix(const std::string & x, const std::vector<std::string> & K) : x(x), K(K) { 
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

  void match() {
    state = 0;

    for(int i = 0; i < n; ++i) {
      while(g[state][x[i]] == FAIL)
        state = f[state];
      state = g[state][x[i]];
      if(output[state]) {
        printf("%d: ", i);
        for(auto o : outputs[state]) {
          printf("%s ", o);
        }
      }
    }
  }
};
#include "PmmTree.h"

void PmmTree::enter(const std::string &a, int &newstate)
{
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

void PmmTree::construct_g()
{
  int newstate = 0;
  for(int i = 0; i < k; ++i) {
    enter(K[i], newstate);
  }
  for(int a = 0; a < ALPHABET_SIZE; ++a) {
    if(g[0][a] == FAIL)
      g[0][a] = 0;
  }
}

void PmmTree::construct_f()
{
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
        for(auto o : outputs[f[s]]) {
          output[s] = true;
          outputs[s].push_back(o);
        }
      }
    }
  }

}

void PmmTree::match()
{
  state = 0;

  for(int i = 0; i < n; ++i) {
    while(g[state][x[i]] == FAIL)
      state = f[state];
    state = g[state][x[i]];
    if(output[state]) {
      std::cout << i << ": ";
      for(auto o : outputs[state]) {
        std::cout << o << " ";
      }
      std::cout << std::endl;
    }
  }
}

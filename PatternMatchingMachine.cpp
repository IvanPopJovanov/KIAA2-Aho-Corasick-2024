#include "PatternMatchingMachine.h"
#include <iostream>

void PatternMatchingMachine::enter(const std::string &a)
{
    int m = a.size();
    State *state = &(states[0]);
    int j = 1;
    while (g(state, a[j]) != FAIL) {
        state = g(state, a[j]);
        j++;
    }
    for (int p = j; p < m; ++p) {
        State * newstate = nullptr; // newstate = newstate + 1
        state->g[a[p]] = newstate;
        state = newstate;
    }
    state->output.push_back(a);
}

void PatternMatchingMachine::init_g()
{
    State * newstate = &(states[0]);
    int k = K.size();
    for (int i = 1; i < k; ++i) {
        enter(K[i]);
        for (char a = 0; a < 127; ++a) {
            if (g(newstate, a) == FAIL)
                newstate->g[a] = newstate;
        }
    } 
}

void PatternMatchingMachine::match()
{
    State *state = &(states[0]);
    int n = K.size();
    for(int i=0; i<n; ++i) {
        while(g(state, x[i]) == FAIL)
            state = f(state);
        state = g(state, x[i]);
        if(output(state).size() > 0) {
            std::cout << i << ": ";
            for (auto x : output(state)) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }
}

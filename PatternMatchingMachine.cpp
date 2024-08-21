#include "PatternMatchingMachine.h"
#include <iostream>
#include <queue>
#include <algorithm>

void PatternMatchingMachine::enter(const std::string & a, state_id &newstate)
{
    int m = a.size();
    state_id state = 0;
    int j = 0;
    while (g(state, a[j]) != FAIL) {
        state = g(state, a[j]);
        j++;
    }
    for (int p = j; p < m; ++p) {
        newstate = newstate + 1;
        states[state].g[a[p]] = newstate;
        state = newstate;
    }
    states[state].output.push_back(a);
}

state_id PatternMatchingMachine::g(const state_id state, const char & ch)
{
    return states[state].g.at(ch);
}

void PatternMatchingMachine::construct_g()
{
    state_id newstate = 0;
    int k = K.size();
    for (int i = 0; i < k; ++i) {
        enter(K[i], newstate);
    } 
    for (char a = 0; a < 127; ++a) {
        if (g(0, a) == FAIL)
            states[newstate].g[a] = 0;
    }
}

state_id PatternMatchingMachine::f(const state_id state)
{
    return states[state].f;
}

void PatternMatchingMachine::construct_f()
{
    std::queue<state_id> queue;
    for (char a = 0; a < 127; ++a) {
        state_id s = g(0, a);
        if(s != 0) {
            queue.push(s);
            states[s].f = 0;
        }
    }
    while(!queue.empty()) {
        state_id r = queue.front();
        queue.pop();

        for (char a = 0; a < 127; ++a) {
            state_id s = g(r, a);
            if(s != FAIL) {
                queue.push(s);
                state_id state = states[r].f;
                while (g(state,a) == FAIL) {
                    state = states[state].f;
                }
                states[s].f = g(state, a);
                for (auto x : states[states[s].f].output) {
                    if(std::find(states[s].output.begin(), states[s].output.end(), x) != states[s].output.end())
                    states[s].output.push_back(x); 
                }
                
            }
        }
    }

}

std::vector<std::string> PatternMatchingMachine::output(state_id state)
{
    return states[state].output;
}

void PatternMatchingMachine::match()
{
    state_id state = 0;
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

#include "PatternMatchingMachine.h"
#include <iostream>
#include <queue>

void PatternMatchingMachine::enter(const std::string &a, uint &newstate)
{
    int m = a.size();
    State *state = &(states[0]);
    int j = 1;
    while (g(state, a[j]) != FAIL) {
        state = g(state, a[j]);
        j++;
    }
    for (int p = j; p < m; ++p) {
        newstate = newstate + 1;
        state->g[a[p]] = &(states[newstate]);
        state = &(states[newstate]);
    }
    state->output.push_back(a);
}

State *PatternMatchingMachine::g(const State *state, const char &ch)
{
    return state->g.at(ch);
}

void PatternMatchingMachine::construct_g()
{
    uint newstate = 0;
    int k = K.size();
    for (int i = 1; i < k; ++i) {
        enter(K[i], newstate);
        for (char a = 0; a < 127; ++a) {
            if (g(&(states[newstate]), a) == FAIL)
                states[newstate].g[a] = &(states[newstate]);
        }
    } 
}

State *PatternMatchingMachine::f(const State *state)
{
    return state->f;
}

void PatternMatchingMachine::construct_f()
{
    std::queue<State*> queue;
    for (char a = 0; a < 127; ++a) {
        State* s = g(&(states[0]), a);
        if(s != &(states[0])) {
            queue.push(s);
            s->f = &(states[0]);
        }
    }
    while(!queue.empty()) {
        State* r = queue.front();
        queue.pop();

        for (char a = 0; a < 127; ++a) {
            State* s = g(r, a);
            if(s != FAIL) {
                queue.push(s);
                State* state = r->f;
                while (g(state,a) == FAIL) {
                    state = state->f;
                }
                s->f = g(state, a);
                for (auto x : s->f->output) {
                    s->output.push_back(x); // ovde treba unija
                }
                
            }
        }
    }

}

std::vector<std::string> PatternMatchingMachine::output(const State *state)
{
    return state->output;
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

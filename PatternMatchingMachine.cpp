#include "PatternMatchingMachine.h"
#include <iostream>

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

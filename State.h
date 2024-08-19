#pragma once
#include <string>
#include <map>
#include <vector>

struct State {
    std::map<char, State*> g;
    std::vector<std::string> output;
    State* f;
} ;

extern struct State *FAIL;
#pragma once
#include <map>
#include <vector>

struct State {
    std::map<char, State*> g;
    std::vector<std::string> output;
} *FAIL;
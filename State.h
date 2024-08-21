#pragma once
#include <string>
#include <map>
#include <vector>

typedef int state_id;

class State {
public:
    std::map<char, state_id> g;
    std::vector<std::string> output;
    state_id f;
} ;

extern state_id FAIL;
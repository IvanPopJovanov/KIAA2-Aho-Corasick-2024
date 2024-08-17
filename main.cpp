#include <iostream>
#include "PatternMatchingMachine.h"

int main() {

  PatternMatchingMachine M("ushers", {"he", "she", "his", "hers"});

  M.match();

  return 0;
}
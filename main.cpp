#include <iostream>
#include "PatternMatchingMachine.h"
#include "PmmMatrix.h"

int main() {
  //TODO: What is the most correct way to calculate execution time?

  std::string x = "ushers";
  std::vector<std::string> K({"he", "she", "his", "hers"});

  std::cout << "Apstraktna implementacija: " << std::endl;
  PatternMatchingMachine M1(x, K);
  M1.match();
  
  std::cout << "Matricna implementacija: " <<std::endl;
  PmmMatrix M2(x, K);
  M2.match();

  return 0;
}
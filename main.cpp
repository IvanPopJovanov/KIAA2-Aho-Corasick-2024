#include <iostream>
#include "PatternMatchingMachine.h"
#include "PmmMatrix.h"
#include "PmmTree.h"

int main() {
  //TODO: What is the most correct way to calculate execution time?
  //TODO: What is the most correct way to calculate memory size of a custom class object?

  std::string x = "ushers";
  std::vector<std::string> K({"he", "she", "his", "hers"});

  std::cout << "Apstraktna implementacija: " << std::endl;
  PatternMatchingMachine M1(x, K);
  M1.match();
  std::cout << sizeof(M1) << std::endl;
  
  std::cout << "Matricna implementacija: " <<std::endl;
  PmmMatrix M2(x, K);
  M2.match();
  std::cout << sizeof(M2) << std::endl;

  std::cout << "Stablo pretrage implementacija: " <<std::endl;
  PmmTree M3(x, K);
  M3.match();
  std::cout << sizeof(M3) << std::endl;


  return 0;
}
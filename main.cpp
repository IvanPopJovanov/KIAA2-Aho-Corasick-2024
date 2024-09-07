#include <iostream>
#include "PatternMatchingMachine.h"
#include "PmmMatrix.h"

int main() {
  //TODO: What is the most correct way to calculate execution time?

  printf("Apstraktna implementacija: \n");
  PatternMatchingMachine M1("ushers", {"he", "she", "his", "hers"});
  M1.match();
  
  printf("Matricna implementacija: \n");
  PmmMatrix M2("ushers", {"he", "she", "his", "hers"});
  M2.match();

  return 0;
}
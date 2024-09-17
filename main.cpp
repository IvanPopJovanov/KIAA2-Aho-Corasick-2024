#include <iostream>
#include "PatternMatchingMachine.h"
#include "PmmMatrix.h"
#include "PmmTree.h"

int main() {
  //TODO: What is the most correct way to calculate memory size of a custom class object?

  std::string x = "ushers";
  std::vector<std::string> K({"he", "she", "his", "hers"});

  clock_t start, end;

  std::cout << "Apstraktna implementacija: " << std::endl;
  start = clock(); 
  PatternMatchingMachine M1(x, K);
  M1.match();
  end = clock();
  std::cout << double(end-start)/ CLOCKS_PER_SEC*1000 << std::endl;
  std::cout << sizeof(M1) << std::endl;
  
  std::cout << "Matricna implementacija: " <<std::endl;
  start = clock(); 
  PmmMatrix M2(x, K);
  M2.match();
  end = clock();
  std::cout << double(end-start)/ CLOCKS_PER_SEC*1000 << std::endl;
  std::cout << sizeof(M2) << std::endl;

  std::cout << "Stablo pretrage implementacija: " <<std::endl;
  start = clock(); 
  PmmTree M3(x, K);
  M3.match();
  end = clock();
  std::cout << double(end-start)/ CLOCKS_PER_SEC*1000 << std::endl;
  std::cout << sizeof(M3) << std::endl;


  return 0;
}
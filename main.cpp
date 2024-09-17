#include <iostream>
#include "PatternMatchingMachine.h"
#include "PmmMatrix.h"
#include "PmmTree.h"

#define MAX_LEN_X 1e5
#define LEN_X_INCREMENT 1e3

void test(std::string x, std::vector<std::string> K, std::ofstream & out_csv) {
  clock_t start, end;

  // std::cout << "Apstraktna implementacija: " << std::endl;
  start = clock(); 
  PatternMatchingMachine M1(x, K, "output1.txt");
  M1.match();
  end = clock();
  // std::cout << double(end-start)/ CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  // std::cout << sizeof(M1) << " bytes" << std::endl;
  out_csv << "," << double(end-start)/ CLOCKS_PER_SEC*1000 << "," << sizeof(M1);
  //TODO: Change sizeof to custom allocator?
  
  // std::cout << "Matricna implementacija: " <<std::endl;
  start = clock(); 
  PmmMatrix M2(x, K, "output2.txt");
  M2.match();
  end = clock();
  // std::cout << double(end-start)/ CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  // std::cout << sizeof(M2) << " bytes" << std::endl;
  out_csv << "," << double(end-start)/ CLOCKS_PER_SEC*1000 << "," << sizeof(M2);

  // std::cout << "Stablo pretrage implementacija: " <<std::endl;
  start = clock(); 
  PmmTree M3(x, K, "output3.txt");
  M3.match();
  end = clock();
  // std::cout << double(end-start)/ CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  // std::cout << sizeof(M3) << " bytes" << std::endl;
  out_csv << "," << double(end-start)/ CLOCKS_PER_SEC*1000 << "," << sizeof(M3);

  // std::cout << "KMP: " <<std::endl;
  start = clock(); 
  for(auto k : K) {
    PmmMatrix M4(x, {k}, "output4.txt");
    M4.match();
  }
  end = clock();
  // std::cout << double(end-start)/ CLOCKS_PER_SEC*1000 << " ms" << std::endl;
  // std::cout << sizeof(PmmMatrix(x, {K[0]}, "output4.txt")) << " bytes" << std::endl;
  out_csv << "," << double(end-start)/ CLOCKS_PER_SEC*1000 << "," << sizeof(PmmMatrix(x, {K[0]}, "output4.txt"));

}

std::string random_string(const int len) {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

void random_dict(const int n, const int min_len, const int max_len, std::vector<std::string> & K) {
  for (int i=0; i < n; i++) {
    K.push_back(random_string((rand() % (max_len-min_len)) + min_len));
  }
}

int main() {
  srand(42);

  std::ofstream out_csv("stats.csv");
  std::cout << "0/" << MAX_LEN_X/LEN_X_INCREMENT << std::flush;
  for(int i = 1; i <= MAX_LEN_X/LEN_X_INCREMENT; i++) {
    std::string x = random_string(i*LEN_X_INCREMENT);
    std::vector<std::string> K;
    random_dict(100, 3, 10, K);

    out_csv << i;
    test(x, K, out_csv);
    out_csv << std::endl;
    std::cout << "\r" << i << "/" << MAX_LEN_X/LEN_X_INCREMENT << std::flush;
  }

  // std::cout << x << std::endl;
  // for (auto y : K)
  //   std::cout << y << std::endl;

  return 0;
}
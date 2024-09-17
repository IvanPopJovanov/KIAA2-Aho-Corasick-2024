#include <iostream>
#include "PatternMatchingMachine.h"
#include "PmmMatrix.h"
#include "PmmTree.h"

#define MAX_LEN_X 1e6
#define LEN_X_INCREMENT 1e3

#define MAX_LEN_K 100
#define LEN_K_INCREMENT 1

#define NUM_KEYWORDS 1e2
#define MAX_KEYWORD_LEN 15
#define MIN_KEYWORD_LEN 5

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

  // MENJANJE DUZINE TEKSTA
  std::cout << "Test 1 : MENJANJE DUZINE TEKSTA" << std::endl;

  std::ofstream out_csv1("stats1.csv");

  out_csv1 << "text length,abstract/ms,abstract/bytes,matrix/ms,matrix/bytes,tree/ms,tree/bytes,kmp/ms,kmp/bytes" << std::endl;

  std::cout << "0/" << MAX_LEN_X/LEN_X_INCREMENT << std::flush;
  for(int i = 1; i <= MAX_LEN_X/LEN_X_INCREMENT; i++) {
    std::string x = random_string(i*LEN_X_INCREMENT);
    std::vector<std::string> K;
    random_dict(NUM_KEYWORDS, MIN_KEYWORD_LEN, MAX_KEYWORD_LEN, K);

    out_csv1 << i*LEN_X_INCREMENT;
    test(x, K, out_csv1);
    out_csv1 << std::endl;
    std::cout << "\r" << i << "/" << MAX_LEN_X/LEN_X_INCREMENT << std::flush;
  }

  std::cout << std::endl;

  // MENJANJE BROJA KLJUCNIH RECI
  std::cout << "Test 2 : MENJANJE BROJA KLJUCNIH RECI" << std::endl;

  std::ofstream out_csv2("stats2.csv");

  out_csv2 << "keywords,abstract/ms,abstract/bytes,matrix/ms,matrix/bytes,tree/ms,tree/bytes,kmp/ms,kmp/bytes" << std::endl;

  std::cout << "0/" << MAX_LEN_K/LEN_K_INCREMENT << std::flush;
  for(int i = 1; i <= MAX_LEN_K/LEN_K_INCREMENT; i++) {
    std::string x = random_string(MAX_LEN_X);
    std::vector<std::string> K;
    random_dict(i*LEN_K_INCREMENT, MIN_KEYWORD_LEN, MAX_KEYWORD_LEN, K);

    out_csv2 << i*LEN_K_INCREMENT;
    test(x, K, out_csv2);
    out_csv2 << std::endl;
    std::cout << "\r" << i << "/" << MAX_LEN_K/LEN_K_INCREMENT << std::flush;
  }

  std::cout << std::endl;

  return 0;
}
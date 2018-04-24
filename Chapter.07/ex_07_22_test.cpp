#include "ex_07_22.h"
int main(int argc, char const *argv[]) {
  Persion p1;
  Persion p2("Bob");
  Persion p3("John", "ZhongNanHai");
  print(std::cout, p1);
  print(std::cout, p2);
  print(std::cout, p3);
  return 0;
}

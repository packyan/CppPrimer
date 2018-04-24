#include "ex_07_06.h"
int main(int argc, char const *argv[]) {
  Sales_data item1;
  Sales_data item2("book2");
  Sales_data item3("book3", 1, 100.0);
  Sales_data item4(std::cin);
  print(std::cout, item1);
  print(std::cout, item2);
  print(std::cout, item3);
  print(std::cout, item4);
  return 0;
}
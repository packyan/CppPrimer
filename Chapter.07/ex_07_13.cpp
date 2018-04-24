///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
///
///
#include "ex_07_12.h"
int main() {
  Sales_data total(std::cin);
  if (!std::cin.eof()) {
    while (!std::cin.eof()) {
      Sales_data trans(std::cin);
      if (total.isbn() == trans.isbn())
        total.combine(trans);
      else {
        print(std::cout, total);
        total = trans;
      }
    }
    print(std::cout, total);
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
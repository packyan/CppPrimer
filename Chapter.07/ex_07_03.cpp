///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
///
///
#include "ex_07_02.h"

int main() {
  Sales_data total;
  if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
      if (total.isbn() == trans.isbn())
        total.combine(trans);
      else {
        total.Print();
        total = trans;
      }
    }
    total.Print();
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
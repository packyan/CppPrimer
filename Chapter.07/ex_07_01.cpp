///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
///
///
#include "../include/Sales_data.h"

int main() {
  Sales_data total;
  if (std::cin >> total.bookNo >> total.units_sold >> total.price) {
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.price) {
      if (total.bookNo == trans.bookNo)
        total.AddDATA(trans);
      else {
        total.Print();
        total.SetDATA(trans);
      }
    }
    total.Print();
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
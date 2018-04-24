///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
///
///
#include <iostream>
#include <string>
// *.h files should not contain using declaration.
#ifndef SALES_DATA_H
#define SALES_DATA_H

struct Sales_data {
  std::string isbn() const { return bookNo; }
  double avg_price() const;
  Sales_data &combine(const Sales_data &);
  void Print() const {
    std::cout << isbn() << ' ' << units_sold << ' ' << revenue << ' '
              << avg_price() << std::endl;
  }
  std::string bookNo;
  unsigned int units_sold = 0;
  double revenue = 0.0;
};

// it's a member fuction so use struct name + ::
double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  this->units_sold += rhs.units_sold;
  this->revenue += rhs.revenue;
  return *this;
}

#endif
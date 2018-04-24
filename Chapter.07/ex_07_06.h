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
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, const int u, const double p)
      : bookNo(s), units_sold(u), revenue(p * u) {}
  Sales_data(std::istream &is);
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

// member functions
// it's a member fuction so use struct name + ::
double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  this->units_sold += rhs.units_sold;
  this->revenue += rhs.revenue;
  return *this;
}

// nonmember fuctions
std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0.0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &rhs) {
  std::cout << rhs.isbn() << ' ' << rhs.units_sold << ' ' << rhs.revenue
            << std::endl;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(lhs);
  return sum;
}

// constructor
Sales_data::Sales_data(std::istream &is) { read(is, *this); }

#endif
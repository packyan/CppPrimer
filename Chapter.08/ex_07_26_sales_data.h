///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
///
///
// *.h files should not contain using declaration.
#ifndef ex_07_26_sales_data
#define ex_07_26_sales_data

#include <iostream>
#include <string>

class Sales_data {
  friend std::istream &read(std::istream &is, Sales_data &item);
  friend std::ostream &print(std::ostream &os, const Sales_data &rhs);
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, const int u, const double p)
      : bookNo(s), units_sold(u), revenue(p * u) {}
  Sales_data(std::istream &is) {
    double price;
    is >> bookNo >> units_sold >> price;
    revenue = units_sold * price;
  }
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);
  inline double avg_price() const;
private:
  std::string bookNo;
  unsigned int units_sold = 0;
  double revenue = 0.0;
};

inline
double Sales_data::avg_price() const {
return units_sold ? revenue / units_sold : 0;}
// declarations for nonmember parts of the Sales_data interface.
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &rhs);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif
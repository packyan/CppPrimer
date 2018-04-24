#include "ex_07_26_sales_data.h"
// member functions
// it's a member fuction so use struct name + ::

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  this->units_sold += rhs.units_sold;
  this->revenue += rhs.revenue;
  return *this;
}// nonmember fuctions
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
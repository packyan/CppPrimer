///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
///
///
#include <iostream>
#include <string>
// *.h files should not contain using declaration.
#ifndef PERSION_H
#define PERSION_H

struct Persion {
  const std::string &getName const() { return name; };
  const std::string &getAddress const { return address; }
  std::string name;
  std::string address;
};
std::istream &read(std::istream &is, Persion &man) {
  is >> man.name >> man.address;
  return is;
}
std::ostream &print(std::ostream &os, const Persion &man) {
  os << man.getName() << ' ' << man.getAddress() << std::endl;
  return os;
}
#endif
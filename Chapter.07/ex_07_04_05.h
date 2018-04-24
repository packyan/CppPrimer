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
// should these function be const?
// Yes, A const followingn the parameters list indicates that this is a pointer
// to const These function only can read members of the objects on which it's
// called.
#endif
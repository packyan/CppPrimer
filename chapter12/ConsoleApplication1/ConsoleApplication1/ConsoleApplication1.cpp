/*
// 3 pointer
// shared_ptr unique_ptr  weak_ptr
// smart pointer is a kind of template

*/
#include "pch.h""
#include <memory>
#include <iostream>
#include <string>
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	shared_ptr<string> p_str1 = make_shared<string>("hello world");
	cout << *p_str1 << endl;

}


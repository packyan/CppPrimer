/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       21  May 2019
 *  @remark
 ***************************************************************************/
//  Compilers don’t always give easy-to-understand error messages if we attempt
//  to
//  copy or assign a unique_ptr. Write a program that contains these errors to
//  see
//  how your compiler diagnoses them.

#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

int main()
{
	unique_ptr<string> p_1(new string("packy"));
	unique_ptr<string> p_2(new string("yiyi"));
	//错误	C2280	“std::unique_ptr<std::string, std::default_delete<_Ty>>::unique_ptr(const std::unique_ptr<_Ty, std::default_delete<_Ty>> &)”: 尝试引用已删除的函数	ptr	c : \users\jarvis\desktop\cpp_premer\chapter12\ptr\ptr\ptr.cpp	24
	//unique_ptr<string> p_3(p_1); // copy
	//                      ^
	// Error: Call to implicitly-deleted copy constructor of
	// 'unique_ptr<string>'
	//
	 //unique_ptr<string> p_4 = p_1; // assign
	//                      ^
	// Error: Call to implicitly-deleted copy constructor of
	// 'unique_ptr<string>'
	std::cout << *p_1 << std::endl;
	std::cout << *p_2 << std::endl;
	p_1.reset(p_2.release());
	std::cout << *p_1 << std::endl;
	p_1.reset(nullptr);
}
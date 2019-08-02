/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       22  May 2019
 *  @remark
 ***************************************************************************/
 //
 //  Write a program to concatenate two string literals, putting the result in a
 //  dynamically allocated array of char.
 //  Write a program to concatenate two library strings that have the same value
 //  as the literals used in the first program.

#include <iostream>

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[]) {
	const char *c_string_1 = "Hello", *c_string_2 = "NJUST";
	//cout << sizeof(c_string_1) << ' ' << sizeof(*c_string_1) << endl;
	size_t clen = strlen(c_string_1) + strlen(c_string_2) + 1;
	char *cat_cstring = new char[clen]();
	strcat_s(cat_cstring, clen, c_string_1);
	strcat_s(cat_cstring, clen, c_string_2);
	cout << cat_cstring << endl;

	string str_1 = "hello", str_2 = "NJUST";
	char *cat_str = new char[clen]();
	strcpy_s(cat_str, clen, (str_1 + str_2).c_str());
	cout << cat_str << endl;
	delete[] cat_cstring;
	delete[] cat_str;
	
	return 0;
 }
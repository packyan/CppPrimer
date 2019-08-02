/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       22  May 2019
 *  @remark
 ***************************************************************************/

//  Write a program that reads a string from the standard input into a
//  dynamically allocated character array.
//  Describe how your program handles varying size inputs.
//  Test your program by giving it a string of data that is longer than the
//  array size you've allocated.
#include <iostream>

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[]) {
	string input_str{};
	size_t max_size = 3;
	char *c_arr = new char[max_size]();
	while(cin >> input_str){
		if (input_str.length() > max_size) {
			max_size = input_str.length() + 1;
			delete[] c_arr;
			c_arr = new char[max_size]();

		}
		strcpy_s(c_arr, max_size, input_str.c_str());
		cout << c_arr << endl;
	}
	delete[] c_arr;
	return 0;
 }
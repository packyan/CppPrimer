//! @file   Exercise 9.18
//! @author packy
//! @date   2018-09-15
//! @Brief  Write a program to input string from std io, save them to a  deque, than using iterator to print it.

#include <iostream>
#include <vector>
#include <string>
#include <deque>
using std::deque;
using std::string;
using std::cout;
using std::endl;
int main()
{
	std::string str;
	std::deque<std::string> deq;
	while(std::cin >> str){
		deq.push_back(str);
	}
	for(deque<string>::iterator it_b = deq.begin(), it_e = deq.end();
		it_b != it_e; ++it_b){
		cout << *it_b << '\t';
	}
	cout << endl;
    return 0;
}

//! @file   Exercise 9.19
//! @author packy
//! @date   2018-09-15
//! @Brief  reWrite9.18, replace deque by list

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
using std::list;
using std::deque;
using std::string;
using std::cout;
using std::endl;
int main()
{
	std::string str;
	std::list<std::string> list;
	while(std::cin >> str){
		list.push_back(str);
	}
	for(std::list<std::string>::iterator it_b = list.begin(), it_e = list.end();
		it_b != it_e; ++it_b){
		cout << *it_b << '\t';
	}
	cout << endl;
    return 0;
}

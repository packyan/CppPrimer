//! @file   Exercise 9.20
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
	list<int> list1{1,2,3,4,5};
	deque<int> deq1, deq2;
	for(auto it = list1.begin(); it != list1.end(); ++it){
		if(*it % 2 ) deq1.push_back(*it);
		else deq2.push_back(*it);
	}
	for(const auto num:deq1)
		cout << num << '\t';
	cout << endl;
	for(const auto num:deq2)
		cout << num << '\t';
	cout << endl;
    return 0;
}

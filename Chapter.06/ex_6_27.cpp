///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief use initializer_list<int> to sum all elements in this list
/// 
///
#include <iostream>
#include <initializer_list>
using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;
int sum_list(initializer_list<int> il){
	int sum = 0;
	for(initializer_list<int>::iterator it = il.begin(), end = il.end();
		it != end; ++it){
		sum += *it;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	//argv[0] : contain prog name
	//argument should be start at argv[1]
	cout << "sum: " << sum_list({1,2,3,4,5,6})<<endl;
	cout << "sum: " << sum_list({1,2,3})<<endl;
	return 0;
}
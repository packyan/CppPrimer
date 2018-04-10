///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>
#include <iterator> // seems not necessary...

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	int i_array[10];
	for(int *ptr_begin = std::begin(i_array), *ptr_end = std::end(i_array); ptr_begin != ptr_end; ++ptr_begin)
		*ptr_begin = 0;
	for(auto x : i_array)
		cout << x << ' ';
	cout <<endl;
	return 0;
}
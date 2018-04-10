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

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	constexpr size_t array_size = 10;
	int i_array[array_size];
	for (int i = 0; i < array_size; ++i)	i_array[i] = i;
	for(auto x : i_array)	cout << x << ' ';
	cout <<endl;
	return 0;
}
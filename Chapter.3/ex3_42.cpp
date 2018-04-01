///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;

int main(int argc, char const *argv[])
{
	int arr[5], arr2[5];
	std::vector<int> ivec{1, 5, 6, 8, 5};
	for(auto &x : arr){
		static int i = 0;
		x = ivec[i];
		++i;
	}
	for(auto x : arr)	cout << x << ' ';
	cout << endl;
	for (int  *it = begin(arr2); it != end(arr2); ++it)
	{
		*it = ivec[it - begin(arr2)];
	}
	for(auto x : arr2)	cout << x << ' ';
	cout << endl;
	return 0;
}
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
	int arr[5] = {1,2,3,4,5};
	std::vector<int> ivec(begin(arr), end(arr));
	for(auto x : ivec)
		cout << x << ' ';
	cout << endl;
	return 0;
}
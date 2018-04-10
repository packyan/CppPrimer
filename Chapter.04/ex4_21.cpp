///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief find odd numbers and double them
/// 
///
#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
	std::vector<int> ivec{1,2,3,4,5,6,7};
	for(int &x : ivec)
		x = (x % 2) ? x * 2 : x;
	for(int x :ivec)
		std::cout << x << ' ';
	std::cout << std::endl;
	return 0;
}
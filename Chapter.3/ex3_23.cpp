///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// define a vector give it ten elements 
/// then using iterator to double the elements.
///

#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <cctype>
#include<ctime>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
	srand(time(0));
	std::vector<int> ivec(10);
	for(auto &x : ivec) 
		{
			x = rand()%100;
		}
	for(auto x :ivec) cout << x << ' ';
		cout << endl;
	for (std::vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		(*it) = (*it) * 2;
	}
	for(auto x :ivec)
		cout << x << ' ';
}
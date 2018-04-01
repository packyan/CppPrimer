
// @Author  Pakcyan
// @Date    April. 2018
// @Brief
// read a sequence of strings from cin and
// store those values in a vector.

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	string temp;
	while(cin >> temp)
		v.push_back(temp);
	for(auto x : v)
		cout << x << ' ';
	cout << endl;
	return 0;
}
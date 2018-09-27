#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>


using std::string;
using std::list;
using std::vector;
using std::count;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	std::vector<int> v{1,3,4,6};
	for(auto i : v){
		cout << i << ' ';
	}
	cout << endl;
	fill_n(v.begin(), v.size(),0);
	for(auto i : v){
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}


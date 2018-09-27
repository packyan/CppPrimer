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
	char c1[10] = "hello";
	char c2[10] = "hello";
	list<char*> roster1{c1};
	vector<char*> roster2{c2};
	cout << equal(roster1.cbegin(),roster1.cend(), roster2.cbegin()) << endl;

	return 0;
}

// clang 3.5.0
// out
// 0
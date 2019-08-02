// associative-container.cpp
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::list;
int main()
{
	string name;
	size_t age;
	std::pair<string, size_t> info;
	vector<std::pair<string, size_t> > v_info;
	while (cin >> name >> age) {
		v_info.push_back(std::pair<string, size_t>( name, age));
	}

	for (const auto &p : v_info) {
		cout << p.first << ' ' << p.second << endl;
	}
}

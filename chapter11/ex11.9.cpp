// associative-container.cpp
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::list;
int main()
{
	map<string, list<size_t>> word_lookUp;
	string line,words;
	size_t line_num = 0;
	while (std::getline(cin, line)) {
		++line_num;
		std::stringstream sstream(line);
		while(sstream >> words)
		word_lookUp[words].push_back(line_num);
		
	}
	for (auto const &p : word_lookUp)
	{
		cout << p.first << " : ";
		for (auto num : p.second) {
			cout << num << ' ';
		}
		cout << endl;
	}

}

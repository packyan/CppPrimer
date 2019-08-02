// associative-container.cpp
//

#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	map<string, size_t> words_counter;
	string word;
	while (cin >> word) {
		++words_counter[word];
	}
	
	for (const auto &w : words_counter) {
		cout << w.first << " occurs " << w.second
			<< ((w.second == 1)? "time" : "times") << endl;
	}
}

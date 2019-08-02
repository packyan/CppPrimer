// associative-container.cpp
//

#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
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
		for (auto &c : word) c = tolower(c);
		//! According to the erase-remove idiom.
		//! For more information about the erase-remove idiom, please refer to
		//! http://en.wikipedia.org/wiki/Erase-remove_idiom
		word.erase(std::remove_if(word.begin(), word.end(), ispunct),
			word.end());
		++words_counter[word];
	}
	
	for (const auto &w : words_counter) {
		cout << w.first << " occurs " << w.second
			<< ((w.second == 1)? "time" : "times") << endl;
	}
}

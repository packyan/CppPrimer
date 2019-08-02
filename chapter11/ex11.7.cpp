// associative-container.cpp
//

#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <string>

#include <vector>
using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
	map<string, vector<string> > famls;
	string lastName, children_name;
	cout << "Add family enter 1 or add members for a family enter2 and enter @q to quit" << endl;
	while (1) {
		
		cin >> lastName;
		if(lastName =="1")
		{
			
			cout << "please enter a new family name: " << endl;
			cin >> lastName;
			cout << "please enter children's name: " << endl;
			cin >> children_name;
			famls[lastName].push_back(children_name);
		}
		else if (lastName == "2") {
			cout << "please enter family name: " << endl;
			cin >> lastName;
			cout << "please enter children's name: " << endl;
			cin >> children_name;
			famls[lastName].push_back(children_name);
		}
		else if (lastName == "@q") {
			break;
		}
		cout << "Add family enter 1 or add members for a family enter2 and enter @q to quit" << endl;
	}
	for (const auto f : famls) {
		cout << f.first << endl;
		for (const auto c : f.second) {
			cout << c << ' ';
		}
		cout << endl;
	}
	

}

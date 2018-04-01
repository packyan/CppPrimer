///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// toupper all charecters in first phase
///

#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
	std::vector<string> str_ivec;
	string str;
	while(getline(cin, str))
		str_ivec.push_back(str);
	for (std::vector<string>::iterator it = str_ivec.begin(); it != str_ivec.end() && !it->empty(); ++it)
	{
		for (string::iterator charecter = (*it).begin(); charecter != (*it).end(); ++charecter)
		{
			*charecter = toupper(*charecter);
		}
	}

	for (auto str : str_ivec)
	{
		cout << str << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	string str2(str);
	//using for
	for (decltype(str.size()) index = 0;
		index != str.size() && str[index] != ' ';
		++index)
	{
		str[index] = 'X';
	}
	cout << str <<endl;

	//using while
	decltype(str2.size()) index = 0;
	while(index < str2.size() && str2[index] != ' '){
		str2[index] = 'X';
		++index;
	}
	cout << str2 << endl;
	return 0;
}
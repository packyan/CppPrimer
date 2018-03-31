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
	for (char &c : str)
	{
		c = 'X';
	}
	cout << str <<endl;
	return 0;
}
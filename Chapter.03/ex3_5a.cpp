#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string str_input, long_str;
	while(cin >> str_input)
		long_str += str_input;
	cout << "Connected string : " << long_str << endl;
	return 0;
}
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string str1, str2;
	cin >> str1 >> str2;
	if(str1 == str2) cout << "str1 equal str2" << endl;
	else if(str1 > str2) cout << "the bigger one is " << str1 << endl;
	else cout << "the bigger one is " << str2 << endl;
	return 0;
}
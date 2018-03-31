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
	string::size_type str1_len = str1.size(), str2_len = str2.size();
	if(str1_len == str2_len) cout << "str1 and str2 have the same length" << endl;
	else if(str1_len > str2_len) cout << "the longer one is " << str1 << endl;
	else cout << "the longer one is " << str2 << endl;
	return 0;
}
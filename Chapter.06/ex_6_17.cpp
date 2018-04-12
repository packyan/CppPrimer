///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief // Determine if a string has uppercase letters
/// 
///
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

bool hasUpper(const string &str){
	for(const char c : str)
	{
		if(isupper(c)) {
			return 1;
		}
	}
	return 0;
}

string str2lower(string &str){
	for(char &c : str)
	{
		if(isupper(c)) {
			c = tolower(c);
		}
	}
	return str;
}

int main(int argc, char const *argv[])
{
	
	for (string str; cout << "Please enter a string\n",
		cin >> str ; )
	{
		cout << "it's has upper: " << hasUpper(str) << endl;
		cout << "string to lower: " << str2lower(str) <<endl;

	}
	return 0;
}
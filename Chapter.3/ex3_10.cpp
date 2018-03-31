#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string str, str2;
	cin >> str;
	if(str.empty()){
		cout << "empty string" << endl;
		return -1;
	}
	for (char &c : str)
	{
		if(!ispunct(c)) str2 += c;
	}
	cout << str2 <<endl;
	return 0;
}
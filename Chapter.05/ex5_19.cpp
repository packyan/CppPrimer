///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief do repeatly prompt user enter two strings and output the shotter one on the screen
/// 
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main(int argc, char const *argv[])
{
	string str1, str2;
	do{
		cout << "Please enter two strings" << endl;
		cin >> str1 >> str2;
		cout << "shotter one is ";
		if(str1.size() < str2.size())  cout<< str1 << endl;
		else cout << str2 <<endl;
	} while (1);
	return 0;
}
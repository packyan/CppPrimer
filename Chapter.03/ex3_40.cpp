///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief cat two c_strings
/// 
///

#include <iostream>
#include <vector>
#include <string>
#include <cstring>


using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
int main(int argc, char const *argv[])
{
	const char c_str1[] = "bilibili", c_str2[] = "ganbei";
	char cat_str[100] = {};
	strcpy(cat_str, c_str1);
	strcat(cat_str, " ");
	strcat(cat_str, c_str2);
	for(auto c : cat_str)
		cout << c;
	cout <<endl;
	return 0;
}
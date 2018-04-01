///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief compare two string or c_string
/// 
///

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>
#include <cstring>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;

bool c_str_compare(const char *p1, const char *p2);

int main(int argc, char const *argv[])
{
	string str1("bilibili ganbei"), str2("bilibili ganbe");
	const char c_str1[] = "bilibili", c_str2[] = "bilibili";
	if(str1 == str2) cout<< "two strings is the same"<<endl;
	else cout << "two string not the same" << endl;
	if(c_str_compare(c_str1,c_str2))
		cout << "two c_string is the same"<< endl;
	else cout << "two c_string not the same"<< endl;
	return 0;
}

bool c_str_compare(const char *p1, const char *p2){
	if(strlen(p1) != strlen(p2)) {
		cout << "--warning: two string length is not the same" <<endl;
		return false;
	}
	else if(!(strcmp(p1,p2))) return true;
	else return false;
	
}
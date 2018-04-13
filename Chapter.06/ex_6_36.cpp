///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
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
using strArr  = string[10];
string str[10] = {"1", "2", "3", "4", "211", "985", "nice", "8", "9", "finish"};
string addstr = "6";
string (&fun(string (&str)[10]))[10]{
	for (size_t i = 0; i < 10 ;++i)
	{
		str[i] = str[i] + addstr;

	}
	return str;

}
auto fun2(string (&str)[10]) -> string(&)[10]
{
	for (size_t i = 0; i < 10 ;++i)
	{
		str[i] = str[i] + addstr;

	}
	return str;

}

decltype(str) &fun3(string (&str)[10]){
	for (size_t i = 0; i < 10 ;++i)
	{
		str[i] = str[i] + addstr;

	}
	return str;

}

strArr &fun1(strArr &str){
	for (size_t i = 0; i < 10 ;++i)
	{
		str[i] = str[i] + addstr;

	}
	return str;	
}
int main(int argc, char const *argv[])
{

	for(auto s : fun(str)) cout << s << ' ';
	cout << endl;
	for(auto s : fun1(str)) cout << s << ' ';
	cout << endl;	
	for(auto s : fun2(str)) cout << s << ' ';
	cout << endl;
	for(auto s : fun3(str)) cout << s << ' ';
	cout << endl;
	return 0;
}

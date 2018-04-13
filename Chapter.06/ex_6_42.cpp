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
using std::vector;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending  = "s"){
	return  (ctr > 1) ? word + ending : word;
}
int main(int argc, char const *argv[])
{
	cout << make_plural(1, "success", "es") << ' '
	<< make_plural(1, "failure")<< '\n';
	cout << make_plural(2, "success", "es") << ' '
	<< make_plural(2, "failure")<<endl;
	return 0;
}
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::prev;

string Rename(const string &name, const string &first, const string &last)
{
	auto full_name = name;
	full_name.insert(full_name.begin(),first.begin(),first.end());
	full_name.append(last);
 	return full_name;
}

int main()
{
	string name = Rename("JING","Mr "," JR.");
	cout << name << endl;
}
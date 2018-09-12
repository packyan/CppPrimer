#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

istream& istream_test(istream& in){
	std::string buf;	
	while(in >> buf)
		cout << buf << '\n' << endl;
	in.clear();
	return in;
} 
int main(int argc, char const *argv[])
{
	string temp_str;
	cin >> temp_str;
	istringstream istr_Stream(temp_str);
	istream_test(istr_Stream);
	return 0;
}
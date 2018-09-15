#include <iostream>
#include <string>
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
	istream_test(cin);
	return 0;
}
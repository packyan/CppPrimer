#include <iostream>
#include <fstream>
#include <sstream> // istringstream
#include <string>
#include <vector>
using namespace std;

istream& istream_test(istream& in) {
	std::string buf;
	while (in >> buf)
		cout << buf << '\n' << endl;
	in.clear();
	return in;
}
int main(int argc, char const *argv[])
{
	ifstream infile(argv[1]);
	string buf;
	vector<string> lines;
	while (getline(infile,buf))
	{
		lines.push_back(buf);
	}
	for (auto line : lines) {
		istringstream words(line);
		string word;
		while (words >> word)
			cout << word << endl;
	}
	return 0;
}
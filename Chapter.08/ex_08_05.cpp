#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void ReadFile(const string& filename, std::vector<string> &v_str){
	string buf;
	ifstream infile(filename);
	if(infile)
	while(infile>>buf){

		v_str.push_back(buf);
	}

}
int main(int argc, char const *argv[])
{
	/* code */
	string filename = "test.txt";
	std::vector<string> vec;
	ReadFile(filename,vec);
	for (std::vector<string>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;
	}
	//for (const auto& str : vec) cout << str << endl;
	return 0;
}
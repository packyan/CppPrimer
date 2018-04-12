///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief main function print all arguments
/// 
///
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(int argc, char const *argv[])
{
	//argv[0] : contain prog name
	//argument should be start at argv[1]
	for (int i = 0; i <= argc; ++i)
	{
		std::string temp = argv[i];
		cout << "argv[" << i << ']' << temp << endl; 
	}
	return 0;
}
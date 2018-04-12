///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief main function to connect two strings
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
	std::string str = argv[1];
	str += argv[2];
	cout << "connect : "<< str << endl;
	return 0;
}
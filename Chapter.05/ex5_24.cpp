///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main(int argc, char const *argv[])
{
	int i,j;
	while(cin >> i >> j){
		if(!j) throw std::runtime_error("ERROR devide zero\n");
		cout << " i / j = " << i/j << endl;		
	}
	return 0;
}

/*terminate called after throwing an instance of 'std::runtime_error'
  what():  ERROR devide zero


This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.*/
///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int fun(int p, int q);
typedef decltype(fun) *fp;

int intAdd(int p, int q){
	return p + q;
}

int intSub(int p, int q){
	return p - q;
}

int intMulti(int p, int q){
	return p * q;
}

int intDiv(int p, int q){
	return p / q;
}
std::vector<fp> v{intAdd, intSub, intMulti, intDiv};

int main(int argc, char const *argv[])
{
	for (std::vector<fp>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)(6,6)<<' ';
	}

	return 0;
}
///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int intCompare(const int i, const int* const p){
	return (i >= *p) ? i : *p;
}

int main(int argc, char const *argv[])
{
	
	for (int i  = 0, j = 0; cout << "Please enter two number to campare\n",
		cin >> i >> j ; )
	{

		cout << "i = " << i << " j = " << j << endl;
		cout << "bigger one is: "<< intCompare(i, &j) << endl;
	}
	return 0;
}
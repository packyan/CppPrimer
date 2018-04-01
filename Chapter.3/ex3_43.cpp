///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;

int main(int argc, char const *argv[])
{
	int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	cout << "****range for*****" << endl;
	// range for
	for(const int (&row)[4] : ia){
		for (const int col : row)
			cout << col << ' ';
		cout << endl;		
	}
	cout << "****index*****" << endl;
	// ordinary for loop using subscripts
	for (size_t rows = 0; rows < 3; ++rows)
	{
		for (size_t cols = 0; cols < 4; ++cols)
		{
			cout << ia[rows][cols] << ' ';
		}
		cout <<endl;
	}
	// using pointer
	cout << "****pointer*****" << endl;
	for (int (*p)[4] = ia; p != ia + 3; ++p)
	{
		for (int *q = *p ; q != *p + 4; ++q)
		{
			cout << *q << ' ';
		}
		cout << endl;
	}
	return 0;
}
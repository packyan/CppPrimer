///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;



int main(int argc, char const *argv[])
{
	// use type alias
	using int_array = int[4];
	int_array ia[3] = {0,1,2,3,4,5,6,7,8,9,10,11};
	// range for
	for(const int_array &rows : ia){
		for (const int col : rows)	cout << col << ' ';
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
	//using pointer
	cout << "****pointer*****" << endl;
	for (int_array *p = ia; p != ia + 3; ++p)
	{
		for (int *q = *p ; q != *p + 4; ++q)
		{
			cout << *q << ' ';
		}
		cout << endl;
	}
	return 0;
}
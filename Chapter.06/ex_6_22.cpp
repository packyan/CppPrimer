///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief swap two int pointers
/// 
///
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void swapIntPointer( int* &lhs,  int* &rhs)
{
    auto temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main(int argc, char const *argv[])
{
	
	for (int i  = 0, j = 0; cout << "Please enter two number to swap\n",
		cin >> i >> j ; )
	{

		cout << "i = " << i << " j = " << j << endl;
		cout << "swapIntPointer: "<< endl;
		int *lhs = &i, *rhs = &j;
		swapIntPointer(lhs, rhs);
		cout << "i = " << *lhs << " j = " << *rhs << endl;
	}
	return 0;
}
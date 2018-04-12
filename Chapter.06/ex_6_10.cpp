///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief // Using pointers, write a function to swap the values of two ints.
// Test the function by calling it and printing the swapped values.
/// 
///
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void mySwap(int* const p, int* const q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

int main(int argc, char const *argv[])
{
	
	for (int i  = 0, j = 0; cout << "Please enter two number to swap\n",
		cin >> i >> j ; )
	{

		cout << "i = " << i << " j = " << j << endl;
		mySwap(&i, &j);
		cout << "Swaping"<<endl;
		cout << "i = " << i << " j = " << j << endl;
	}
	return 0;
}
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
/*
 *programing a program 
 *prompt the user to enter two integers and print all integers in this ranges
*/
int main(int argc, char** argv)
{
	int i = 0, j = 0;
	while(i >= j)
	{
		cout << "please enter two integers" << endl;
		cin >> i >> j;
	}
	while(i < j - 1)
	{
		cout << ++i << " ";
	}
	cout << endl;
	return 0;
}

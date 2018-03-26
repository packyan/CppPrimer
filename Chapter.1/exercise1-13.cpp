#include<iostream>
using std::cout;
using std::cin;
using std::endl;
/*
 *Rewrite the previous program
*/
int main(int argc, char** argv)
{
	int  sum = 0;
	for(int i = 50; i <=100; i++) sum += i;
	cout << "the sum of 50 to 100 integers is " << sum << endl;
	for(int i = 10; i >= 0; i-- ) cout << i << " ";
	cout<<endl;
	int i = 0, j = 0;
	while(i >= j)
	{
		cout << "please enter two integers" << endl;
		cin >> i >> j;
	}
	for(; i < j; i++) cout << i << " ";
	cout<<endl;
	return 0;
}

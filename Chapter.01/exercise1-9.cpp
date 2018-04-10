#include<iostream>
using std::cout;
using std::cin;
using std::endl;
/*
 *using while to add of 50 to 100 integers
*/
int main(int argc, char** argv)
{
	int i = 50, sum = 0;
	while(i <= 100)
	{
		sum += i;
		i++;
	}
	cout << "the sum of 50 to 100 integers is " << sum << endl;
	return 0;
}

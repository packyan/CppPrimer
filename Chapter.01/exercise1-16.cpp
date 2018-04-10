#include<iostream>
using std::cout;
using std::cin;
using std::endl;
/*
 *sum
*/
int main(int argc, char** argv)
{
	int  temp = 0, sum = 0;
	while(cin >> temp)
	{	
		cout << temp << " ";
		sum += temp;
	}
	cout << endl;
	cout << "the sum is " << sum <<endl;
	return 0;
}

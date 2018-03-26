#include<iostream>
using std::cout;
using std::cin;
using std::endl;
/*
 *print integers between 10 and 0 in reverse order
*/
int main(int argc, char** argv)
{
	int i = 10;
	while(i >= 0)
	{
		cout << i << " ";
		i--;
	}
	cout << endl;
	return 0;
}

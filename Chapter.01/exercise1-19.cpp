#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
int i = 0, j = 0;

	cout << "please enter two integers" << endl;
	cin >> i >> j;
	if(i > j){
	int temp = i;
	i = j;
	j = temp;
	}
	while(i < j - 1)
	{
		cout << ++i << " ";
	}
	cout << endl;

}

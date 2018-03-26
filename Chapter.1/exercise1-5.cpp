#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char** argv)
{
	cout << "Please enter two numbers"<<endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "the product of ";
	cout << v1;
	cout << " and ";
	cout << v2;
	cout << " is ";
	cout << v1 * v2<<endl;
	return 0;
}

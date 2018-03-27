#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char const *argv[])
{
	unsigned u = 10, u2 = 42;
	cout << u2 -u << endl;
	cout << u - u2 << endl;

	int i = 10, i2 = 42;
	cout << i2 - i << endl;
	cout << i - i2 << endl;
	cout << i - u << endl;
	cout << u - i << endl;
	return 0;
}
/*output:
32
4294967264
32
-32
0
0
*/
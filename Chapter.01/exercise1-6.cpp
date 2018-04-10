#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char** argv)
{
	
	cout << "Please enter two numbers"<<endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "the sum of " << v1 //;
	<< " and " << v2 //;
	<< " is " << v1 + v2 << endl;
	return 0;
}
//the program fragment is illegal
// fixed: Remove the spare semicolon
//compiler error
/*
exercise1-6.cpp: In function ‘int main(int, char**)’:
exercise1-6.cpp:11:2: error: expected primary-expression before ‘<<’ token
  << " and " << v2;
  ^
exercise1-6.cpp:12:2: error: expected primary-expression before ‘<<’ token
  << " is " << v1 + v2 << endl;

*/

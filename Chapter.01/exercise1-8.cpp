#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char** argv)
{
	
	cout << "/*";
	cout << "*/";
	cout << /*"/*"*/ " "; 
	cout << /* "*/" /* "/*" */;
	return 0;
}
///* 
// * this line is incorrect
// *exercise1-8.cpp: In function ‘int main(int, char**)’:
// *exercise1-8.cpp:10:18: error: expected primary-expression before ‘;’ token
// * cout << /*"/*"*/ ;

//*/

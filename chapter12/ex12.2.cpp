
#include <memory>
#include <iostream>
#include <string>
#include "StrBlob.h"
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	StrBlob b1{"packy","yy","aa"};
	const StrBlob b2{ "22","33","44" };
	cout << b1.back() << ' ' << b1.front() << endl;
	cout << b2.back() << ' ' << b2.front() << endl;
	b1.back() = "bb";
	b1.front() = "cc";
	cout << b1.back() << ' ' << b1.front() << endl;
	return 0; 
	
}



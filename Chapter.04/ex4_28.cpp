///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// size of built-in types
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char const *argv[])
{
    cout << "bool\t\tis " << sizeof(bool) << "byte." << endl;
    cout << "char\t\tis " << sizeof(char) << "byte." << endl;
    cout << "wchar_t\t\tis " << sizeof(wchar_t) << "bytes." << endl;
    cout << "char16_t\tis " << sizeof(char16_t) << "bytes." << endl;
    cout << "char32_t\tis " << sizeof(char32_t) << "bytes." << endl;
    cout << "short\t\tis " << sizeof(short) << "bytes." << endl;
    cout << "int\t\tis " << sizeof(int) << "bytes." << endl;
    cout << "long\t\tis " << sizeof(long) << "bytes." << endl;
    cout << "long long\tis " << sizeof(long long) << "bytes." << endl;
    cout << "float\t\tis " << sizeof(float) << "bytes." << endl;
    cout << "double\t\tis " << sizeof(double) << "bytes." << endl;
    cout << "long double\tis " << sizeof(long double) << "bytes." << endl;
    cout << endl;
	return 0;
}
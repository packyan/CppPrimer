///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief use recursion function to output a vector.
/// 
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
template <typename T>
void printVec(std::vector<T> &ivec){
	for (typename std::vector<T>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << ' ';
	}
}

template <class iterator>
void printVec_RECURSION(iterator itBegin, iterator itEnd){
	if(itBegin == itEnd) return;
	cout << *itBegin << ' ';
	return(printVec_RECURSION(itBegin+1,itEnd));
}


int main(int argc, char const *argv[])
{
	std::vector<string> v{"211", "985", "is", "good"};
	std::vector<int> int_v{111,222,666,888};
	printVec(v);
	cout << endl;
	printVec_RECURSION(v.begin(),v.end());
	cout << endl;
	
	printVec(int_v);
	cout << endl;
	printVec_RECURSION(int_v.begin(),int_v.end());
	return 0;
}
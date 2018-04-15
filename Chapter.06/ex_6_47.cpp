///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief // Revise the program you wrote in the exercises in 6.3.2 (p.
// 228) that used recursion to print the contents of a vector to conditionally
// print information about its execution. For example, you might print the size
// of the vector on each call. Compile and run the program with debugging turned
// on and again with it turned off.
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

//#define NDEBUG

template <typename T>
void printVec(std::vector<T> &ivec){
	// for (typename std::vector<T>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	// {
	// 	cout << *it << ' ';
	// }
	#ifndef NDEBUG
	cout << "vector size :" << ivec.size()<<endl;
	#endif
	if(! ivec.empty()){
		cout << ivec.back() << ' ';
		ivec.pop_back();
		printVec(ivec);
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
	printVec(v);
	cout << endl;
	return 0;
}
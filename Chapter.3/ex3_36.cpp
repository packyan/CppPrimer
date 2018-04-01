///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief compare two array is equal or not.
/// 
///

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>
#include <iterator> // seems not necessary...

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

bool arr_compare(int const *pb1, int const *pe1, int const *pb2, int const *pe2);

int main(int argc, char const *argv[])
{
	int i_array[5] = {1,2,3,4,5}, i_array2[5] = {1,2,3,4,5};
	int *ptr_begin = std::begin(i_array), *ptr_end = std::end(i_array),\
		*ptr_begin2 = std::begin(i_array2), *ptr_end2 = std::end(i_array2);
	if(arr_compare(ptr_begin, ptr_end, ptr_begin2, ptr_end2))
		cout << "two array is equal" <<endl;
	else cout << "two array is not equal" <<endl;
	return 0;
}

bool arr_compare(int const *pb1, int const *pe1, int const *pb2, int const *pe2){
	if((pe1 - pb1) != (pe2 - pb2)){
		cout << "array size is not the same"<< endl;
		return false;
	} 
	else {
		for( ; pb1 != pe1 ; ++pb1, ++pb2)
				if(*pb1 != *pb2) return false;
		return true;
	}
}
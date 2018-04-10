///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
/// 
///

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	//use array
	constexpr size_t array_size = 10;
	int i_array[array_size], i_array_copy[array_size];
	for (int i = 0; i < array_size; ++i)	i_array[i] = i;
	for (int i = 0; i < array_size; ++i)	i_array_copy[i] = i_array[i];
	cout << "i_array :"<<endl;
	for(auto x : i_array)	cout << x << ' ';
	cout <<endl;
	cout << "i_array_copy :"<<endl;
	for(auto x : i_array_copy)	cout << x << ' ';
	cout <<endl;

	//use vector
	std::vector<int> ivec(array_size), ivec_copy(array_size);
	for(auto &x : ivec){
		static int i = 0;
		x = i;
		++i;
	}
	cout << "ivec :"<< endl;
	for(auto x : ivec)	cout << x << ' ';
	cout <<	endl;

	ivec_copy = ivec; //vector copy '='
	cout << "ivec_copy :"<< endl;
	for(auto x : ivec_copy)	cout << x << ' ';
	cout <<	endl;
	return 0;
}
///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// 
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main(int argc, char const *argv[])
{
	std::vector<int> ivec_2{0, 1, 1 ,2}, ivec_1{0, 1, 1 ,2, 3,5,8};
	std::vector<int>::size_type ivec1_size = ivec_1.size(), ivec2_size = ivec_2.size();
	if ( ivec1_size >= ivec2_size)
	{
		bool isornot = 1;
		for (std::vector<int>::size_type i = 0; i < ivec2_size; ++i)
		{
			if(ivec_1[i] != ivec_2[i]){
				cout << "false" << endl;
				isornot = 0;
				break;
			}

		}
		if(isornot) cout << "true" <<endl;
	}
	else{
		bool isornot = 1;
		for (std::vector<int>::size_type i = 0; i < ivec1_size; ++i)
		{
			if(ivec_1[i] != ivec_2[i]){
				cout << "false" << endl;
				isornot = 0;
				break;
			}

		}
		if(isornot) cout << "true" <<endl;

	}
	return 0;
}
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char* const argv[]){
	std::vector<string> v_str_num{"1","3.5","5","111"};
	float v_sum = 0;
	for(auto num : v_str_num){
		v_sum += stoi(num);
	}
	cout << "the vector sum is : " << v_sum << endl;
	v_sum = 0;
	for(auto num : v_str_num){
		v_sum += stof(num); // stod
	}
	cout << "the vector sum is : " << v_sum << endl;

	return 0;
}


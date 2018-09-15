#include <iostream>
#include <vector>
using std::cout;
using std::endl;
int main(int argc, char const *argv[])
{
	std::vector<int> v1;
	std::vector<int> v2{1,2,3,6,7};
	cout << "at: " << v1.at(0) << endl; 
	/*
	at: terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
  */
	cout << "index " << v1[0] << endl; // Segmentation fault: 11
	cout << "front " << v1.front() << endl; // Segmentation fault: 11
	cout << "back" << v1.back() <<endl;// Segmentation fault: 11
	return 0;
}
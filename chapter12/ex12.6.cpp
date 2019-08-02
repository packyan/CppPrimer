
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "StrBlob.h"
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::cin;
using std::cout;
using std::endl;
void push_vector_ptr(vector<int> *ptr_vec) {
	int temp;
	while (cin >> temp) {
		ptr_vec->push_back(temp);
	}
}
void print_vector_ptr(const vector<int> *ptr_vec) {
	for (const auto i : *ptr_vec) {
		cout << i << ' ';
	}
	cout << endl;
}
int main()
{
	//auto p_i = new int();
	vector<int> *p_v = new vector<int>{1,3,4,5,6,4};
	push_vector_ptr(p_v);
	print_vector_ptr(p_v);
	delete p_v;
	return 0; 
}



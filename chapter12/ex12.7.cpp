
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
void push_vector_ptr(shared_ptr<vector<int>> ptr_vec) {
	int temp;
	while (cin >> temp) {
		ptr_vec->push_back(temp);
	}
}
void print_vector_ptr(const shared_ptr<vector<int>> ptr_vec) {
	for (const auto i : *ptr_vec) {
		cout << i << ' ';
	}
	cout << endl;
}
int main()
{
	shared_ptr<vector<int>> ptr_v = std::make_shared<vector<int>>();
	push_vector_ptr(ptr_v);
	print_vector_ptr(ptr_v);
	return 0; 
}



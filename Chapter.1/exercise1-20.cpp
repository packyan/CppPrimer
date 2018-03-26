#include<iostream>
#include"../include/Sales_item.h"
using std::cout;
using std::cin;
using std::endl;
int main(){
	Sales_item item;
	while(cin >> item)
	cout << item << endl;
	return 0;
}

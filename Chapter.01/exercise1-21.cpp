#include<iostream>
#include"../include/Sales_item.h"
using std::cout;
using std::cin;
using std::endl;
int main(){
	Sales_item item1 ,item2;
	cin >> item1 >> item2;
	if(item1.isbn() == item2.isbn()) {
		Sales_item item = item1 + item2;
		cout << item << endl;
	}
	else cout << "the ISBN is not the same" << endl; 
	return 0;
}

#include<iostream>
#include"../include/Sales_item.h"
using std::cout;
using std::cin;
using std::endl;
int main(){
	Sales_item item,item2;
	if(cin >> item)
	{
	Sales_item item_total = item;
	while(cin >> item2)
	if(item.isbn() == item2.isbn()) {
		item_total += item2;	
	}
	else cout << item2.isbn() <<"the ISBN is not the same" << endl; 
	cout << item_total << endl;
	}
	return 0;
}

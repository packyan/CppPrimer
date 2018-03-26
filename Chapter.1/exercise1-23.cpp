#include<iostream>
#include<string>
#include"../include/Sales_item.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	Sales_item currItem, item;
	if(cin >> currItem){
		int cnt = 1;
		while(cin >> item){
			if(currItem.isbn() == item.isbn()) 
			++cnt;
			else{
				cout << currItem.isbn() << " occurs " << cnt;
				cout << (string)((cnt == 1) ? " time" : " times")<< endl;
				currItem = item;
				cnt = 1;
			}
	
		}
	cout << currItem.isbn() << " occurs " << cnt;
	cout << (string)((cnt == 1) ? " time" : " times")<< endl;
	}
	return 0;	
}

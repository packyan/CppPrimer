#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Sales_data.h"
int main(int argc, char const *argv[])
{
	Sales_data item1, currItem, temp;
	if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
		temp.SetDATA(item1);
		//cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
		while(cin >> currItem.bookNo >> currItem.units_sold >> currItem.price){
			if(temp.bookNo == currItem.bookNo){
				temp.AddDATA(currItem);
				//cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
			}
	else{
	temp.Print();
	temp.SetDATA(currItem);
		}
		}
	}
	temp.Print();
	return 0;
}
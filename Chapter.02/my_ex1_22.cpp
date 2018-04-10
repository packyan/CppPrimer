#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Sale_data{
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
    double average = 0.0;
};
int main(int argc, char const *argv[])
{
	Sale_data item1, item2, temp;
	if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
		temp.bookNo = item1.bookNo;
		temp.units_sold = item1.units_sold;
		temp.revenue = 1.0 * item1.units_sold * item1.price;
		cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
		while(cin >> item2.bookNo >> item2.units_sold >> item2.price){
			if(temp.bookNo == item2.bookNo){
				temp.units_sold += item2.units_sold;
				temp.revenue += 1.0 * item2.price * item2.units_sold;
				temp.average = 1.0 * temp.revenue/temp.units_sold;
				cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
			}
	else{
		cout << "the bookNo is not the same, please enter again." << endl;
		exit(0);
		}
		}
	}
	cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
	return 0;
}
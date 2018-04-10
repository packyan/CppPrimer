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
};
int main(int argc, char const *argv[])
{
	Sale_data item1;
	while(cin >> item1.bookNo >> item1.units_sold >> item1.price)
		cout << item1.bookNo << ' ' << item1.units_sold << ' '<< item1.price <<endl;
	return 0;
}
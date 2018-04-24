#include "ex_07_26_sales_data.h"
int main(int argc, char const *argv[])
{
	Sales_data item("isbn666",20,25.5);
	std::cout << item.avg_price();
	return 0;
}
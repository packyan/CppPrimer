#include <iostream>
#include <string>
// *.h files should not contain using declaration.
// using std::cout;
// using std::cin;
// using std::endl;
// using std::string;

#ifndef SALES_DATA_H
#define SALES_DATA_H

struct Sales_data{
    std::string bookNo;
    //std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
    double average = 0.0;
    void AddDATA(Sales_data add_item);
    void Print(void);
    void SetDATA(Sales_data set_item);
    // void CalcRevenue(void);
    // void CalcAverage(void);
};

void Sales_data::AddDATA(Sales_data add_item){
	if(bookNo != add_item.bookNo){
		std::cout << "can not add a book with different bookNo" << std::endl;
		return;
	}
	units_sold += add_item.units_sold;
	revenue += add_item.price * add_item.units_sold;
	average = 1.0 * revenue / units_sold;
}

void Sales_data::SetDATA(Sales_data set_item){
	units_sold = set_item.units_sold;
	bookNo = set_item.bookNo;
	price = set_item.price;
	revenue = set_item.price * set_item.units_sold;
	average = revenue / units_sold;
}

void Sales_data::Print(){
	std::cout << bookNo << ' ' << units_sold  << ' ' << revenue << ' ' << average << std::endl;
}


#endif
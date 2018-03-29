#include <iostream>
#include "Sales_data.h"
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    Sales_data item1, item2, temp;
    if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
        temp.SetDATA(item1);
        while(cin >> item2.bookNo >> item2.units_sold >> item2.price){
            if(temp.bookNo == item2.bookNo){
                temp.AddDATA(item2);
            }
    else{
        cout << "the bookNo is not the same, please enter again." << endl;
        exit(0);
        }
        }
    }
    temp.Print();
    return 0;
}
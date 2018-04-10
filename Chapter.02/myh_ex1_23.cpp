#include <iostream>
#include <string>
#include "../include/Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    Sales_data item1, currItem, temp;
    unsigned int bookcnt = 0;
    if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
        temp.SetDATA()
        bookcnt = 1;
        // temp.units_sold = item1.units_sold;
        // temp.revenue = 1.0 * item1.units_sold * item1.price;
        // temp.average = 1.0 * item1.price;
        //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
        while(cin >> currItem.bookNo >> currItem.units_sold >> currItem.price){
            if(temp.bookNo == currItem.bookNo){
                bookcnt++;
                // temp.units_sold += currItem.units_sold;
                // temp.revenue += 1.0 * currItem.price * currItem.units_sold;
                // temp.average = 1.0 * temp.revenue/temp.units_sold;
                //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
            }
    else{
        cout << temp.bookNo << " occurs " << bookcnt << string ((bookcnt == 1)? " time" : " times")<< endl;
        bookcnt = 1;
        temp.bookNo = currItem.bookNo;
    // cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    // temp.bookNo = currItem.bookNo;
    // temp.units_sold = currItem.units_sold;
    // temp.revenue = 1.0 * currItem.units_sold * currItem.price;
    // temp.average = 1.0 * currItem.price;
        }
        }
        cout << temp.bookNo << " occurs " << bookcnt << string ((bookcnt == 1)? " time" : " times")<< endl;
    }
    //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    return 0;
}
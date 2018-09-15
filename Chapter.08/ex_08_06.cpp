#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "ex_08_06.h"

int main(int argc, char** argv)
{
    std::ifstream input(argv[1]); // useage "*.exe test.txt"
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
    }
}
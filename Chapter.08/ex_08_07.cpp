#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "ex_08_06.h"

int main(int argc, char** argv)
{
    std::ifstream input(argv[1]); // useage "*.exe test.txt"
	std::ofstream output(argv[2]);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
    }
}
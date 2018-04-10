///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief ex3_20
///


#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    std::vector<int> ivec;
    int temp;
    while(cin >> temp)
    	ivec.push_back(temp);
    std::vector<int>::size_type ivec_size = ivec.size();
    if (ivec.empty()) {
        cout << "Input at least one integer." << endl;
        return -1;
    }
    else if (ivec_size == 1) {
        cout << ivec[0] << " don't have any adjacent elements.";
        return -1;
    }
    else {
        for (int i = 0; i != ivec_size - 1; ++i)
    	   cout << ivec[i] + ivec[i + 1] << endl;
    }   
    return 0;
}
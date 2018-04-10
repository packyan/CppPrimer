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
    for (int i = 0; i != ivec_size / 2; ++i)
    {
    	cout << "ivec[" << i+1 << "] + ivec[" << ivec_size - i << "] = " << ivec[i]+ivec[ivec_size - i - 1] << endl;
    }
    if(ivec_size % 2) cout << "ivec["<< ivec_size/2 + 1 << "] = " << ivec[ivec_size/2] << endl; 
    return 0;
}
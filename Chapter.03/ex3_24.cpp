///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief ex3_20b with iterator
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
        cout << *ivec.begin() << " don't have any adjacent elements.";
        return -1;
    }
    for (std::vector<int>::iterator it = ivec.begin(); it != ivec.end() - 1; ++it)
    {
        cout << *it + *(it+1) << ' ';
    }
    cout << endl;
    
    for (std::vector<int>::iterator it = ivec.begin(); it != (ivec.begin() + ivec_size/2); ++it)
    {
        static int i = 0;
        //auto temp = (ivec_size - 2*i - 1); // p.101
        cout << "ivec[" << i + 1 << "] + ivec[" << ivec_size - i << "] = " << *it + *(it + ivec_size - 2*i - 1)<< endl;
        //cout << *it <<' ' << *(it + ivec_size - 2*i - 1)<<endl;
        i++;
    }
    if(ivec_size % 2) cout << "ivec[" << ivec_size/2 + 1 << "] = " <<  *(ivec.begin()+ivec_size/2 )<< endl;

    // begin and end both used
    for (std::vector<int>::iterator it = ivec.begin(), it_end = ivec.end() - 1; it != it_end; ++it,--it_end)
    {
        cout << *it + *it_end << ' ';
    }
    if(ivec_size % 2) cout <<  *(ivec.begin() + ivec_size/2 )<< endl;

    cout <<endl;
    return 0;
}
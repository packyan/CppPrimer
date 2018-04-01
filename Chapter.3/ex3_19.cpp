///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// List 3 ways to define a vector which has 10 elements
/// each with the value 42.
/// which one is better, and tell way.
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
    std::vector<int> v1(10,42);
    std::vector<int> v2(10);
    for(auto & x : v2) 
        x = 42;
    std::vector<int> v3{42,42,42,42,42,42,42,42,42,42};
    std::vector<std::vector<int> > vec_ivec{v1, v2, v3};
    for(auto vec : vec_ivec){
     	for(auto x : vec)
    		cout << x << ' ';
    	cout << endl;   	
    }
    cout << "The first approach is better" << endl;
    return 0;
}
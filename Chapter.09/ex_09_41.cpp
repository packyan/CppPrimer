
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main()
{
    vector<char> vi{'s','d','f','g','\0'};
    string str(vi.begin(),vi.end());
    cout << str << endl;

    return 0;
}
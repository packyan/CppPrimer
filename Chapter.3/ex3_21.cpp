///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// Redo the first exercise from § 3.3.3 (p. 94) using iterators.
///

#include <vector>
#include <iterator>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void check(const vector<int>& vec)
{
    if (vec.empty())
        cout << "size: 0; no values." << endl;
    else {
        cout << "size: " << vec.size() << "; values:";
        for (auto it = vec.cbegin(); it != vec.cend(); ++it) cout << *it << ",";
        cout << "\b." << endl;
    }
}

void check(const vector<string>& vec)
{
    if (vec.empty())
        cout << "size: 0; no values." << endl;
    else {
        cout << "size: " << vec.size() << "; values:";
        for (auto it = vec.cbegin(); it != vec.cend(); ++it)
            if (it->empty())
                cout << "(null)"
                     << ",";
            else
                cout << *it << ",";
        cout << "\b." << endl;
    }
}

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    std::vector<std::vector<int>> int_ivec{v1, v2, v3, v4, v5};
    std::vector<std::vector<string>> string_ivec{v6, v7};

    for (std::vector<std::vector<int>>::const_iterator i = int_ivec.cbegin(); i != int_ivec.cend(); ++i)
    {
        check(*i);
    }

    for (std::vector<std::vector<string>>::const_iterator i = string_ivec.cbegin(); i != string_ivec.cend(); ++i)
    {
        check(*i);
    }

    return 0;
}
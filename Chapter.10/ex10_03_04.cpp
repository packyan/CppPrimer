#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>

using std::string;
using std::list;
using std::vector;
using std::count;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	std::vector<int> v{1,3,4,5,6,87,9,1};
	std::vector<double> v2{1.1, 0.5, 3.3};
	int sum = accumulate(v.begin(), v.end(),0);
	cout << "sum is " << sum << endl;

	double sum2 = accumulate(v2.begin(), v2.end(),0);
	cout << "sum2 is " << sum2 << endl;
	    //! @attention
    //!
    //! The ouput is 4 rather than 4.9 as expected.
    //! The reason is std::accumulate is a template function. The third
    //! parameter is _Tp __init
    //! When "0" , an integer, had been specified here, the compiler deduced _Tp
    //! as
    //! interger.As a result ,when the following statments were being excuted :
    //  for (; __first != __last; ++__first)
    //	__init = __init + *__first;
    //  return __init;
    //! all calculation would be converted to integer.
	return 0;
}
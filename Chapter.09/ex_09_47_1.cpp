#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::prev;

int main()
{
	string numbers{"0123456789"};
	string alphabet{"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"};
	string str_to_find{"ab2c3d7R4E6"};
	for(string::size_type pos = 0;
		(pos = str_to_find.find_first_not_of(alphabet,pos))!= string::npos;++pos)
	{cout << str_to_find[pos] << " ";

	}
	cout << '\n';
	for(string::size_type pos = 0;
		(pos = str_to_find.find_first_not_of(numbers,pos))!= string::npos;++pos)
	{cout << str_to_find[pos] << " ";

	}
return 0;
}
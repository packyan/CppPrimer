///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief count the numbers of ff fl and fi.
/// 
///
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main(int argc, char const *argv[])
{
	char ch,prechar;
	string::size_type ffCnt = 0, flCnt = 0, fiCnt = 0;
	while(cin >> ch){
		if(prechar == 'f')
		switch(ch){
			case 'i':
				++fiCnt;
		        break;	
	        case 'l':
		        ++flCnt;
		        break;
	        case 'f':
		        ++ffCnt;
		        break;				
		}
		prechar = ch;
	}
	cout << "Number of ff: \t" << ffCnt << '\n' << "Number of fi: \t"
         << fiCnt << '\n' << "Number of fl: \t" << flCnt << endl;

	return 0;
}
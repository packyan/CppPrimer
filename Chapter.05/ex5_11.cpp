///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief cin >> std::noskipws >> count the numbers of vowel aplha, space, tab and newline.
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
	char ch;
	string::size_type aCnt = 0 ,eCnt = 0, iCnt  = 0, oCnt = 0, uCnt = 0,\
	spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
	while(cin >> std::noskipws >> ch){
		switch(ch){
			case 'a':
			case 'A':
				++aCnt;
				break;
			case 'e':
			case 'E':
				++eCnt;
				break;
	        case 'i':
	        case 'I':
	            ++iCnt;
	            break;
	        case 'o':
	        case 'O':
	            ++oCnt;
	            break;
	        case 'u':
	        case 'U':
	            ++uCnt;
	            break;
	        case ' ':
	        	++spaceCnt;
	        	break;
	        case '\t':
	        	++tabCnt;
	        	break;
	        case '\n':
	        	++newlineCnt;
	        	break;

		}
	}
	cout << "Number of vowel a: \t" << aCnt << '\n' 
		 << "Number of vowel e: \t" << eCnt << '\n' 
		 << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n' 
         << "Number of vowel u: \t" << uCnt << '\n' 
         << "Number of space :\t" << spaceCnt << '\n'
         << "Number of Tab: \t" << tabCnt << '\n'
         << "Number of newline: \t" << newlineCnt << endl;

	return 0;
}
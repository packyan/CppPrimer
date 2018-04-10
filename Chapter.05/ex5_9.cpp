///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief count the numbers of vowel aplha.
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
	string::size_type aCnt = 0;
	string::size_type eCnt = 0;
	string::size_type iCnt = 0;
	string::size_type oCnt = 0;
	string::size_type uCnt = 0;
	while(cin >> ch){
		if(ch == 'a') ++aCnt;
		else if(ch == 'e') ++eCnt;
		else if(ch == 'i') ++iCnt;
		else if(ch == 'o') ++oCnt;
		else if(ch == 'u') ++uCnt;
	}
	cout << "Number of vowel a: \t" << aCnt << '\n' << "Number of vowel e: \t"
         << eCnt << '\n' << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n' << "Number of vowel u: \t"
         << uCnt << endl;

	return 0;
}
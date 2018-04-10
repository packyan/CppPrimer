///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief 
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
	string curr_string, pre_string, max_string;
	string::size_type Cnt = 1, max_Cnt = 1;
	if(cin >> pre_string)
		while(cin >> curr_string){
			if(curr_string == pre_string) ++Cnt;
			else {
				if(Cnt > max_Cnt){
					max_Cnt = Cnt;
					max_string = pre_string;
				}
				pre_string = curr_string;
				Cnt = 1;
			}
		}
	if(max_Cnt == 1) cout << "no word was repeated" <<endl;
	else cout << "max_string :\t" << max_string << "\n"
		<< "max_Cnt: \t" << max_Cnt << endl; 
	return 0;
}
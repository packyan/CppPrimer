#include <iostream>
#include <forward_list>
#include <string>
using std::string;
using std::forward_list;
using std::cout;
using std::endl;
void insert_string_to_forwardlist(forward_list<string> &flst, const string &str1, const string &str2){
	int finded = 0;
	auto prev = flst.before_begin();
	for (auto curr = flst.begin();
         curr != flst.end();prev = curr++){
		 if (*curr == str1)
            {
            	//curr = flst.erase_after(prev);
            	finded = 1;
            	flst.insert_after(curr,str2);
            }
	}
	if(!finded) flst.insert_after(prev,str2);
}

int main()
{
    forward_list<string> flst = {"oh","hello","cpp","yeah"};
   	string replace_str = "fuck";
   	insert_string_to_forwardlist(flst,"hello",replace_str);
    for (auto i : flst) cout << i << " ";
    	cout << endl;
    	   	insert_string_to_forwardlist(flst,"dasd",replace_str);
    
    for (auto i : flst) cout << i << " ";
    cout << endl;
}
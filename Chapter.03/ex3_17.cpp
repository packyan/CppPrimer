///
///@Author  Pakcyan
///@Date    April. 2018
///@Brief
/// Read a sequence of words from cin and store the values a vector.
/// After you've read all the words, process the vector and change each word to
/// uppercase.
/// Print the transformed elements, eight words to a line.
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
    std::vector<string> word_sequence;
    string word;
    while(cin >> word)
    {
        word_sequence.push_back(word);
    }
    for (std::vector<string>::iterator i = word_sequence.begin(); i != word_sequence.end(); ++i)
    {
        for(auto &charecter : *i)
            if(!ispunct(charecter)) charecter = toupper(charecter);
    }
    for(auto words : word_sequence)
        cout << words << endl;

    return 0;
}
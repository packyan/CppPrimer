#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>


using std::string;
using std::list;
using std::vector;
using std::count;
using std::cin;
using std::cout;
using std::endl;

//! print a container like vector,deque, list,etc.
template <typename Sequence> inline std::ostream& println(Sequence const& seq)
{
    for (auto const& elem : seq) std::cout << elem << " ";
    std::cout << std::endl;

    return std::cout;
}

inline bool is_shorter(std::string const& lhs, std::string const& rhs)
{
    return lhs.size() < rhs.size();
}

void elimdups(std::vector<std::string>& vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}



int main(int argc, char const *argv[])
{
	std::vector<string> vec{"hello","world","fuck","cpp"};
	elimdups(vec);
	std::stable_sort(vec.begin(),vec.end(),is_shorter);
	println(vec);
	return 0;
}


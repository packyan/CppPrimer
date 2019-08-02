#include "StrBlob.h"
#include <iostream>
//StrBlob::StrBlob: data(std::make_shared<std::vector<std::string>>){}
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):
	data(std::make_shared<std::vector<std::string>> (il)){}
int  out_of_range(const std::string &msg)
{
	std::cout << msg << std::endl;
	return 1;
}
void StrBlob::print()
{
	check(0, "print empty StrBlob");
	for (auto str : *data) {
		std::cout << str << ' ';
	}
	std::cout << std::endl;
}

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}




std::string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
 std::string&  StrBlob::front()const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

std::string& StrBlob::back()const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}
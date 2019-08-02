#include "StrBlobPtr.h"


std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto p = wptr.lock();
	//检查vector是否还存在
	if (!p)
		throw std::runtime_error("unbound BtrBloPtr\n");
	// 检查解引是否越界
	if (i >= p->size())
		throw std::out_of_range(msg);
	return p;
}

std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}


StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() {
	auto p = StrBlobPtr(*this, data->size());
	return p;
}
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
const std::string&  StrBlob::front()const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::back()const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}
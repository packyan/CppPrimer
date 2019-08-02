#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class StrBlobPtr;
class StrBlob {
	
public:
	friend class StrBlobPtr;

	typedef std::vector<std::string>::size_type size_type;

	StrBlobPtr begin();
//	StrBlobPtr end() { return StrBlobPtr(*this, data->size()); }

	StrBlobPtr end();
	StrBlob(); //constructer
	StrBlob(std::initializer_list<std::string> il);//constructer
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	//push and pop
	void push_back(const std::string &str) { data->push_back(str); }
	void pop_back();

	//access elements
	std::string &front();
	const std::string &front() const;
	std::string &back();
	const std::string &back() const;

	//disp data
	void print();

private:
	std::shared_ptr<std::vector<std::string> > data;
	void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {

public:
	friend class StrBlob;

	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string> > wptr;
	std::size_t curr;


};
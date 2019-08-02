#pragma once
#include <vector>
#include <string>
#include <memory>
class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob(); //constructer
	StrBlob(std::initializer_list<std::string> il);//constructer
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	//push and pop
	void push_back(const std::string &str) { data->push_back(str); }
	void pop_back();

	//access elements
	std::string &front();
	std::string &front() const;
	std::string &back();
	std::string &back() const;

	//disp data
	void print();

private:
	std::shared_ptr<std::vector<std::string> > data;
	void check(size_type i, const std::string &msg) const;
};
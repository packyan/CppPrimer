/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Packy.A
 *  @date       20  May 2019
 *  @remark
 ***************************************************************************/
 //  ex12.14
//Write your own version of a function that uses a shared_ptr to manage a
 //  connection.
//!

#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

struct connection {
	string ip;
	size_t port;
	connection(string ip_, size_t port_): ip(ip_), port(port_){}
};
struct destination {
	string ip;
	size_t port;
	destination(string ip_, size_t port_) : ip(ip_), port(port_) {}
};

connection connect(destination *p_Dest) {
	std::shared_ptr<connection> p_Conn(new connection(p_Dest->ip, p_Dest->port));
	cout << "connecting : " << p_Conn.use_count() << endl;
	return *p_Conn;
}

void disconnect(connection *p_Conn) {
	cout << "disconnecting " << p_Conn->ip << ':' << p_Conn->port << endl;
};

void end_connection(connection *p_Conn) {
	disconnect(p_Conn);
}

void f(destination &d) {
	connection c = connect(&d);
	//shared_ptr<connection> p(&c, end_connection);
	shared_ptr<connection> p(&c, [](connection *p) {disconnect(p); });
	std::cout << "connecting :(" << p.use_count() << ")" << std::endl;
}
int main()
{

	destination dest("192.168.1.111", 8000);
	f(dest);
	return 0;
}
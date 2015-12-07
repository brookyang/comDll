#ifndef SOCK_ACCEPT_H_
#define SOCK_ACCEPT_H_
#include <string>
#include "Inet_Addr.h"
#include "sock_stream.h"

#define SCOK_ACCEPT_EXPORT_ __declspec(dllexport)
using namespace std;

class SCOK_ACCEPT_EXPORT_ sock_accept
{
public:
	sock_accept(Inet_Addr addr);
	~sock_accept(void);
	void setSockStream(sock_stream* sstream);
	void accept();
private:
	SOCKET handle_;
	sock_stream* stream;
};

#endif /** SOCK_ACCEPT_H_ **/